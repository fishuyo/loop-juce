#include <string.h>
#include <assert.h>
#include <math.h>

#include "sndfile.h"

#include "LoopBuffer.h"

#define RW_SIZE 4096

LoopBuffer::LoopBuffer() : maxSize(0), curSize(0), wPos(0), rPos(0), rMin(0), rMax(0), samples(0), times(0) {}
LoopBuffer::LoopBuffer( unsigned int size) : maxSize(size), curSize(0), wPos(0), rPos(0), rMin(0), rMax(0), times(0) {
  samples = size > 0 ? new float[size] : 0;
}

LoopBuffer::~LoopBuffer(){
  if( maxSize > 0 ) delete[] samples;
}

//resize sample buffer
void LoopBuffer::resize( unsigned int size){
  if( (!size && !maxSize) || (size < maxSize) ) return;
  
  float *b = new float[size];
  if(maxSize && samples){
    memcpy( b, samples, maxSize * sizeof(float) );
    delete[] samples;
  }
  maxSize = size; 
  samples = b;
}

//append sample
void LoopBuffer::operator()( float s ){
  if(curSize+1 > maxSize) resize(2*maxSize);
  samples[curSize++] = s;
  rMax++;
}
//read sample
float LoopBuffer::operator()(){
    if(rPos >= rMax){ 
        rPos = rMin;
        times++;
    }
  return samples[rPos++];
}
  
//write sample data, appended to buffer
void LoopBuffer::append( float *in, unsigned int numSamples ){
  if( !maxSize ) return;
  else if( curSize + numSamples >= maxSize ) resize(2*maxSize);
  for( int i=0; i<numSamples; i++)
    samples[curSize+i] = in[i];
  if( rMax == curSize ) rMax += numSamples;
  curSize += numSamples;
}

//read sample data at r_head, between r_min and r_max
void LoopBuffer::read( float *out, unsigned int numSamples, float gain=1.f){
    if( rPos < rMin || rPos >= rMax){ rPos = rMin; times++; }
  int overlap = rPos + numSamples - rMax;
  
  if( overlap >= (int)(rMax-rMin) ) return;
  if(overlap > 0){
    int i;
    for( i = 0; i < numSamples - overlap; i++){
      out[i] = samples[rPos+i] * gain;
    }
    for( int j = 0; j < overlap; j++){
      out[i++] = samples[rMin+j] * gain;
    }
    rPos = overlap;
      times++;
    
  }else{
    for( int i = 0; i < numSamples; i++){
      out[i] = samples[rPos+i] * gain;
    }
    rPos += numSamples;
  }
}

void LoopBuffer::readR( float *out, unsigned int numSamples, float gain=1.f){
  
    if( rPos < rMin || rPos >= rMax){ rPos = rMax; times++; }
  int underlap = rPos - numSamples - rMin;
  
  if( underlap <= -(int)(rMax-rMin) ) return;
  float *tmp = &samples[rPos];
  
  if(underlap < 0){
    for( int i = 0; i < rPos; i++){
      out[i] = *(--tmp) * gain;
    }
    tmp = &samples[rMax];
    for( int i = rPos; i < numSamples; i++){
      out[i] = *(--tmp) * gain;
    }
    
    rPos = rMax + underlap;
      times++;
    
  }else{
    for( int i = 0; i < numSamples; i++){
      out[i] = *(--tmp) * gain;
    }
    rPos -= numSamples;
  }
  
}

void LoopBuffer::addFrom( float *from, unsigned int numSamples, unsigned int offset=0 ){
  if( offset < rMin || offset >= rMax) offset = rMin;
  int overlap = offset + numSamples - rMax;
  
  assert( overlap < (int)(rMax-rMin) );
  if(overlap > 0){
    int i;
    for( i = 0; i < numSamples - overlap; i++){
      samples[offset+i] += from[i];
    }
    for( int j = 0; j < overlap; j++){
      samples[rMin+j] += from[i++];
    }
    
  }else{
    for( int i = 0; i < numSamples; i++){
      samples[offset+i] += from[i];
    }
  }
}

void LoopBuffer::addFromR( float *from, unsigned int numSamples, unsigned int offset=0 ){
  if( offset < rMin || offset >= rMax) offset = rMax;
  int underlap = offset - numSamples - rMin;
  
  assert( underlap > -(int)(rMax-rMin) );
  float *tmp = &samples[offset];
  
  if(underlap < 0){
    for( int i = 0; i < rPos; i++){
      *(--tmp) += from[i];
    }
    tmp = &samples[rMax];
    for( int i = rPos; i < numSamples; i++){
      *(--tmp) += from[i];
    }
  }else{
    for( int i = 0; i < numSamples; i++){
      *(--tmp) += from[i];
    }
  }
}

void LoopBuffer::applyGain( float gain, unsigned int numSamples, unsigned int offset=0){
  if( offset < rMin ) offset = rMin;
  while( numSamples-- ){
    if(offset >= rMax) offset = rMin;
    samples[offset++] *= gain;    
  }
}

float LoopBuffer::getRMS(unsigned int numSamples, unsigned int offset){
  if( curSize == 0 ) return 0.f;
  double sum = 0.0;
  if( offset < rMin ) offset = rMin;
  unsigned int i = numSamples;
  while( i-- ){
    if(offset >= rMax) offset = rMin;
    float s = samples[offset++];
    sum += s*s;    
  }
  //return sum / numSamples;
  return (float) sqrt (sum / numSamples); 
}

float LoopBuffer::getRMSR(unsigned int numSamples){
  unsigned int offset = rPos - numSamples;
  while( offset < 0 ) offset += rMax;
  
  return getRMS(numSamples, offset); 
}

void LoopBuffer::setBounds( unsigned int b1, unsigned int b2=0){
  rMin = b1 < b2 ? b1 : b2;
  rMax = b1 < b2 ? b2 : b1;
  if( rMax > curSize ) rMax = curSize;
}



/*
 * Loop
*
*/
Loop::Loop(){
  numSamples = 0;
  seconds = 0.f;
  sampleRate = 44100;
  recording = playing = stacking = undoing = reversing = recOut = false;
  gain = 1.0f;
  pan = .5f;
  decay = .5f;
  rms = 0.f;
  iobuffer = 0;
    times = 0;
}

Loop::Loop(float num_seconds, unsigned int rate=44100){
  numSamples = num_seconds * rate;
  allocate( numSamples );
  seconds = num_seconds;
  sampleRate = rate;
  recording = playing = stacking = undoing = reversing = recOut = false;
  gain = 1.0f;
  pan = .5f;
  decay = .5f;
  rms = 0.f;
  iobuffer = 0;
    times = 0;
}

Loop::~Loop(){
  if(iobuffer) delete[] iobuffer;
}

void Loop::allocate( unsigned int n ){
  b[0].resize(n);
  b[1].resize(n);
  numSamples=n;
  seconds = n * 1.0f / (1.0f * sampleRate);
  iobuffer = new float[1024]; //TODO should adjust if change in blocksize
}

void Loop::play(){ playing = true; recording=false; }
void Loop::play(int times_){ times = times_; playing = true; recording=false; }
void Loop::stop(){ playing = false; recording = false; }
void Loop::rewind(){ b[0].rPos = b[0].rMin; }

void Loop::record(){ recording = true; playing = false;}

void Loop::stack(){ stacking=!stacking; }
void Loop::reverse(){ reversing = !reversing; }
void Loop::undo(){
  
}
void Loop::clear(){
  b[0].rMin = b[0].rMax = b[0].rPos = b[0].curSize = 0;
}

void Loop::audioIO( float** in, float** out, unsigned int count ){
  
  unsigned int lPos=0;
  float l = (1.f - pan );
  float r = pan;
  
  if(recording){ //fresh loop

    b[0].append( in[0], count );
		
  }else if(playing && numSamples > 0){ //playback and stack
		
    lPos = b[0].rPos;
		
    if(reversing){
      
      b[0].readR( iobuffer, count, gain );
      
      if(stacking){	
	    b[0].applyGain( decay, count, b[0].rPos );
        b[0].addFromR( in[0], count, lPos );
      }
			
    }else {
      
      b[0].read( iobuffer, count, gain );
      
	  if(stacking){
        b[0].applyGain( decay, count, lPos);
        b[0].addFrom( in[0], count, lPos );
	  }			
	}
    
    //up mix to 2 channels
    for( int i=0; i < count; i++){
      out[0][i] += iobuffer[i] * l;
      out[1][i] += iobuffer[i] * r;
    }
      
    if( times > 0 && b[0].times >= times ){
        b[0].times = 0; times = 0;
        stop();
    }
    
  }//end else if(playing)

} 
/*
int Loop::load( const char* filename ){

  SNDFILE *file;
  SF_INFO sfinfo;
  float buffer[RW_SIZE];
  sf_count_t read;

  if( !(file = sf_open(filename, SFM_READ, &sfinfo))){
    //std::cout << "Error loading file " << filename << std::endl;
    return -1;
  }

  sampleRate = sfinfo.samplerate;
  allocate(sfinfo.frames);

  while( (read = sf_readf_float( file, buffer, RW_SIZE/sfinfo.channels )) > 0 ){
    switch( sfinfo.channels ){
      case 1: 
        b[0].append( buffer, read ); break;
      case 2:
        //mix to single channel
        for( int i=0; i < read/2; i++) buffer[i] = (buffer[2*i]+buffer[2*i+1]) / 2.f;
        b[0].append( buffer, read/2 ); break;
      default: return -2; break;
    }
  }
  sf_close(file);
  return 0;
}

int Loop::save( const char* filename ){
 
  SNDFILE *file;
  SF_INFO sfinfo;
  sf_count_t writ;

  sfinfo.samplerate = sampleRate;
  sfinfo.frames = numSamples;
  sfinfo.channels = 1;
  sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

  if( !(file = sf_open(filename, SFM_WRITE, &sfinfo))){
    //std::cout << "Error opening file " << filename << std::endl;
    return -1;
  }

  writ = sf_writef_float( file, b[0].samples, numSamples );
  sf_close( file );
  return 0;
}*/
