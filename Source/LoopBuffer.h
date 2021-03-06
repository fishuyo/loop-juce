
#ifndef _LOOPBUFFER_H_
#define _LOOPBUFFER_H_

struct LoopBuffer {
  
  float *samples;
 
  unsigned int maxSize, curSize; //allocated size, samples recorded
  unsigned int rPos, wPos; //read head, write head at last read
  unsigned int rMin, rMax; //read limiters
    int times;

  LoopBuffer();
  LoopBuffer( unsigned int size);
  ~LoopBuffer();

  //resize sample buffer, default doubles current buffer size
  void resize( unsigned int size);

  //append sample
  void operator()( float s );
  //read one sample
  float operator()();
  
  //write sample data, appended to buffer
  void append( float *in, unsigned int numSamples );

  //read sample data at r_head, between r_min and r_max
  void read( float *out, unsigned int numSamples, float gain );
  void readR( float *out, unsigned int numSamples, float gain );
  
  void addFrom( float *from, unsigned int numSamples, unsigned int offset );
  void addFromR( float *from, unsigned int numSamples, unsigned int offset );
  
  void applyGain( float gain, unsigned int numSamples, unsigned int offset );
  
  //get root mean square of numSamples starting at offset
  float getRMS( unsigned int numSamples, unsigned int offset);
  //get root mean square of numSamples ago
  float getRMSR( unsigned int numSamples);

  //read between b1 and b2, uses smaller value as min (in samples)
  void setBounds( unsigned int b1, unsigned int b2);

};


struct Loop {
  
  LoopBuffer b[2];
  unsigned int sampleRate;
  unsigned int numSamples;
  float seconds;
    int times;

  float gain, pan, decay, rms;
  bool recording,playing,stacking,reversing,undoing;
    bool recOut;
  float *iobuffer;

  Loop();
  Loop(float num_seconds, unsigned int rate);
  ~Loop();
  
  void allocate( unsigned int n );
  
  void play();
    void play(int times);
  void stop();
  void rewind();
  void record();
  void stack();
  void reverse();
  void undo();
  void clear();
  
  void audioIO( float** in, float** out, unsigned int count ); 
  //int load( const char* filename );
  //int save( const char* filename );

};

#endif
