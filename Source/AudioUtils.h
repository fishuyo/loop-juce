/*
 *  AudioUtils.h
 *  rangatang
 *
 *  Created by Tim Wood on 1/22/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "../JuceLibraryCode/JuceHeader.h"

/*
*Component to Display Stream of Audio Input 
*/
class LiveAudioDisplayComp  : public Component,
public AudioIODeviceCallback,
public Timer
{
public:
    //==============================================================================
    LiveAudioDisplayComp();
    ~LiveAudioDisplayComp();
	
    void paint (Graphics& g);
    void timerCallback();
	void setDisplayOutput(bool output);
	
    void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
    void audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                float** outputChannelData, int numOutputChannels, int numSamples);
private:
    float samples [1024];
    int nextSample, subSample;
    float accumulator;
	bool displayOutput;
	
    LiveAudioDisplayComp (const LiveAudioDisplayComp&);
    LiveAudioDisplayComp& operator= (const LiveAudioDisplayComp&);
};

/*
*Audio Recorder Utility class, record input stream to file
*/
class AudioRecorder  : public AudioIODeviceCallback
{
public:
    AudioRecorder();
	
    ~AudioRecorder();
	
    //==============================================================================
    void startRecording (const File& file);
	
    void stop();
	
    bool isRecording() const;
	
    //==============================================================================
    void audioDeviceAboutToStart (AudioIODevice* device);
	
    void audioDeviceStopped();
	
    void audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                float** outputChannelData, int numOutputChannels,
                                int numSamples);
	
private:
    TimeSliceThread backgroundThread; // the thread that will write our audio data to disk
    ScopedPointer<AudioFormatWriter::ThreadedWriter> threadedWriter; // the FIFO used to buffer the incoming data
    double sampleRate;
	
    CriticalSection writerLock;
    AudioFormatWriter::ThreadedWriter* volatile activeWriter;
};

/*
 *AudioPlayer utility class, play an audio file
 */
class AudioPlayer : public AudioIODeviceCallback
{
public:
	AudioPlayer();
	~AudioPlayer();
	
	void loadFile(const File& audioFile);
	void play();
	void stop();	
	bool isPlaying() const;
	
	void audioDeviceAboutToStart (AudioIODevice* device);	
    void audioDeviceStopped();	
    void audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                float** outputChannelData, int numOutputChannels,
                                int numSamples);
	
private:
	
    AudioSourcePlayer audioSourcePlayer;
    AudioTransportSource transportSource;
    ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;
	
};
