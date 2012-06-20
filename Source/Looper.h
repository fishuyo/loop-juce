
#ifndef _LOOPER_H_
#define _LOOPER_H_

#include <iostream>
#include <vector>

#include "LoopBuffer.h"

#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"


struct Looper {
  
    std::vector<Loop*> loops;
    std::vector<float> loudness;

  unsigned int sampleRate;

  Looper();
  ~Looper();
    
    Loop* newLoop();
    Loop* operator()(int loop);
    
    void updateRMS();
    
    void play(int i);
    void playOnce(int i);    
    void stop(int i);
    void record(int i);
    void toggleRecord(int i);
    void stack(int i);
    void reverse(int i);
    void clear(int i);
    void setGain(int i, float g);
    void setDecay(int i, float g);    
    
  
  void audioIO( float** in, float** out, unsigned int count ); 
  

};

struct LooperOSC : public osc::OscPacketListener {
    Looper *looper;
    LooperOSC(Looper* looper_){
        looper = looper_;  
    };
    
    virtual void ProcessMessage( const osc::ReceivedMessage& m, 
                                const IpEndpointName& remoteEndpoint ){
        try{
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            osc::int32 id;
            args >> id;
            
            if( strcmp( m.AddressPattern(), "/play" ) == 0 ) looper->play(id);
            if( strcmp( m.AddressPattern(), "/playOnce" ) == 0 ) looper->playOnce(id);
            else if( strcmp( m.AddressPattern(), "/stop" ) == 0 ) looper->stop(id);
            else if( strcmp( m.AddressPattern(), "/record" ) == 0 ) looper->record(id);
            else if( strcmp( m.AddressPattern(), "/toggleRecord" ) == 0 ) looper->toggleRecord(id);
            else if( strcmp( m.AddressPattern(), "/stack" ) == 0 ) looper->stack(id);
            else if( strcmp( m.AddressPattern(), "/reverse" ) == 0 ) looper->reverse(id);
            else if( strcmp( m.AddressPattern(), "/clear" ) == 0 ) looper->clear(id);
            else if( strcmp( m.AddressPattern(), "/gain" ) == 0 ){
                float gain;
                args >> gain;
                looper->setGain(id, gain);
            } else if( strcmp( m.AddressPattern(), "/decay" ) == 0 ){
                float decay;
                args >> decay;
                looper->setDecay(id, decay);
            }
        }catch( osc::Exception& e ){
            std::cout << "error while parsing message: "
            << m.AddressPattern() << ": " << e.what() << "\n";
        }
    };    
};

#endif
