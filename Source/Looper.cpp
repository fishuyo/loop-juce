
#include "Looper.h"

#define BOUND(x) if((x)<0||(x)>=loops.size()) return
#define abs(x) ((x)<0?(-(x)):(x))
Looper::Looper(){}

Looper::~Looper(){
    for(int i=0; i < loops.size(); i++)
        delete loops[i];
}

Loop* Looper::newLoop(){
    Loop *loop = new Loop();
    loops.push_back( loop );
    loudness.push_back( 0.f );
    return loop;
}

Loop* Looper::operator()(int loop){
    if(loop < 0 || loop >= loops.size() ) return NULL;
    return loops[loop];
}

void Looper::updateRMS(){
    for( int i=0; i < loops.size(); i++){
        Loop* l = loops[i];
        float loud = loudness[i];
        l->rms = l->b[0].getRMSR( 2048 );
        if( l->rms > .5f ){
            loud += l->rms;
            if(loud > 100.f) loud = 100.f;
        }else{
            loud -= .6f - l->rms;
            if( loud < 0.f) loud = 0.f;
        }
        if( loud > 3.f && l->gain > .05f ){
            l->gain -= .05f;
            if(l->gain <= 0.f) l->gain = 0.f;
            //loud -= 1.f;
        }else if( loud < .1f && l->gain < 1.f ){
            l->gain += .001f;
        }
        loudness[i] = loud;
    }
}
void Looper::play(int i){ BOUND(i); loops[i]->play(); }
void Looper::playOnce(int i){ 
    BOUND(i);
    Loop *l = loops[i];
    l->times = 1;
    l->rewind();
    l->play();
}
void Looper::stop(int i){ BOUND(i); loops[i]->stop(); }
void Looper::stack(int i){ BOUND(i); loops[i]->stack(); }
void Looper::reverse(int i){ BOUND(i); loops[i]->reverse(); }
void Looper::clear(int i){ BOUND(i); loops[i]->clear(); }
void Looper::setGain(int i, float g){ BOUND(i); if(g < 0.f) g = 0.f; loops[i]->gain = g; }
void Looper::setDecay(int i, float g){ BOUND(i); if(g < 0.f) g = 0.f; loops[i]->decay = g; }
void Looper::record(int i){ 
    BOUND(i);
    Loop *l = loops[i];
    l->clear();
    l->stop();
    l->record(); 
}

void Looper::toggleRecord(int i){
    BOUND(i);
    Loop *l = loops[i];
    if(!l->recording){
		int sampleRate = 44100; //audioDeviceManager.getCurrentAudioDevice()->getCurrentSampleRate();
		if( l->numSamples == 0 ){
            l->allocate( sampleRate * 5.f );
        }else l->clear();
        l->stop();
        l->record();
	}else{
        l->stop();
		l->rewind();
        l->play();
	}
}

void Looper::audioIO( float** in, float** out, unsigned int count ){
    
	for(int i=0; i < loops.size(); i++ ){
        Loop *l = loops[i];
        if( !l->recording || !l->recOut ) loops[i]->audioIO( in, out, count );
        
    }
    for(int i=0; i < loops.size(); i++ ){
        Loop *l = loops[i];
        if( l->recording && l->recOut ) loops[i]->audioIO( out, 0, count );
    }
    
}  
