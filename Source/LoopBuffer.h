
#pragma once

struct LoopBuffer {
  
  float *samples, *scratch;
  float gain;
  bool undo;
 
  size_t max_size, cur_size; //allocated size, samples recorded
  size_t w_head, r_head; // write head, read head
  size_t r_min, r_max; // read limiters

  LoopBuffer( size_t size=0) : gain(1.0f), max_size(size), cur_size(0), w_head(0), r_head(0), r_min(0), r_max(0), undo(true) {
    samples = size > 0 ? new float[size] : NULL;
    scratch = size > 0 ? new float[size] : NULL;
  }

  //resize sample buffer, default doubles current buffer size
  void resize( size_t size=0){
    if( !size && !max_size ) return;
    size_t new_size = size > 0 ? size : 2*max_size;
    float *b = new float[new_size];
    float *b2 = new float[new_size];
    memcpy( b, samples, max_size * sizeof(float) );
    memcpy( b2, scratch, max_size * sizeof(float) );
    max_size = new_size; 
  }

  void operator()( float s ){ append( &s, 1 ); }
  float operator()(){ float s; read( &s, 1 ); return s; }
  
  //write sample data, appended to buffer
  void append( float *in, size_t numSamples ){
    if( cur_size + numSamples > max_size ) resize();
    memcpy( samples + cur_size * sizeof(float), in, numSamples * sizeof(float) );
    cur_size += numSamples;
    r_max = cur_size;
  }

  //read sample data at r_head, between r_min and r_max
  void read( float *out, size_t numSamples ){
    if( r_head < r_min || r_head > r_max) r_head = r_min;

    size_t off = r_head - r_min;

    for( int i = 0; i < numSamples; i++ ){
      out[i] = samples[ off++ % r_max + r_min ] * gain;
    }
  }


  void set_read_bounds( size_t b1, size_t b2=0){
    r_min = b1 < b2 ? b1 : b2;
    r_max = b1 < b2 ? b2 : b1;
    if( r_max > cur_size ) r_max = cur_size;
  }

};


struct Loop : LoopBuffer {
  
  size_t sample_rate;
  float seconds;

  float gain;
  bool reverse;
  

  Loop(float num_seconds=10.f, size_t rate=44100) : LoopBuffer( sec * rate ) {
    seconds = 0.f;
    sample_rate = rate;

  }


}
