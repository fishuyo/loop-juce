#include <string.h>
#include <assert.h>
#include <math.h>

#include "LoopBuffer.h"

LoopBuffer::LoopBuffer() : maxSize(0), curSize(0), wPos(0), rPos(0), rMin(0), rMax(0), samples(0) {}
LoopBuffer::LoopBuffer( unsigned int size) : maxSize(size), curSize(0), wPos(0), rPos(0), rMin(0), rMax(0) {
  samples = size > 0 ? new float[size] : 0;
}

LoopBuffer::~LoopBuffer(){
  if( maxSize > 0 ) delete[] samples;
}

//resize sample buffer, default doubles current buffer size
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
  if(rPos >= rMax) rPos = rMin;
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
  if( rPos < rMin || rPos >= rMax) rPos = rMin;
  int overlap = rPos + numSamples - rMax;
  
  if( overlap >= (int)(rMax-rMin) ) return;
  if(overlap > 0){
    int i;
    for( i = 0; i < numSamples - overlap; i++){
      out[i] += samples[rPos+i] * gain;
    }
    for( int j = 0; j < overlap; j++){
      out[i++] += samples[rMin+j] * gain;
    }
    rPos = overlap;
    
  }else{
    for( int i = 0; i < numSamples; i++){
      out[i] += samples[rPos+i] * gain;
    }
    rPos += numSamples;
  }
}

void LoopBuffer::readR( float *out, unsigned int numSamples, float gain=1.f){
  
  if( rPos < rMin || rPos >= rMax) rPos = rMax;
  int underlap = rPos - numSamples - rMin;
  
  if( underlap <= -(int)(rMax-rMin) ) return;
  float *tmp = &samples[rPos];
  
  if(underlap < 0){
    for( int i = 0; i < rPos; i++){
      out[i] += *(--tmp) * gain;
    }
    tmp = &samples[rMax];
    for( int i = rPos; i < numSamples; i++){
      out[i] += *(--tmp) * gain;
    }
    
    rPos = rMax + underlap;
    
  }else{
    for( int i = 0; i < numSamples; i++){
      out[i] += *(--tmp) * gain;
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
  recording = playing = stacking = undoing = reversing = false;
  gain = 1.0f;
  decay = .5f;
  rms = 0.f;
}

Loop::Loop(float num_seconds, unsigned int rate=44100){
  numSamples = num_seconds * rate;
  allocate( numSamples );
  seconds = num_seconds;
  sampleRate = rate;
  recording = playing = stacking = undoing = reversing = false;
  gain = 1.0f;
  decay = .5f;
  rms = 0.f;
}

void Loop::allocate( unsigned int n ){
  b[0].resize(n);
  b[1].resize(n);
  numSamples=n;
  seconds = n * 1.0f / (1.0f * sampleRate);
}

void Loop::play(){ playing = true; }
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
  
  if(recording){ //fresh loop

    b[0].append( in[0], count );
		
	}else if(playing){ //playback and stack
		
    lPos = b[0].rPos;
		
		if(reversing){
      
      b[0].readR( out[0], count, gain );
      //memcpy( out[1], out[0], count * sizeof(float) );
      
      //rms = b[0].getRMS( count, b[0].rPos );
			if(stacking){	
				b[0].applyGain( decay, count, b[0].rPos );
        b[0].addFromR( in[0], count, lPos );
			}
			
		}else {
      
      b[0].read( out[0], count, gain );
      //memcpy( out[1], out[0], count * sizeof(float) );
      
      //rms = b[0].getRMS(count, lPos);
			if(stacking){
        b[0].applyGain( decay, count, lPos);
        b[0].addFrom( in[0], count, lPos );
			}			
      
			
		}
  }
}  
