/*
 *  AudioUtils.cpp
 *  rangatang
 *
 *  Created by Tim Wood on 1/22/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "AudioUtils.h"

/*
 *LiveAudioDisplayComp Implementation
 */

LiveAudioDisplayComp::LiveAudioDisplayComp()
{
    nextSample = subSample = 0;
    accumulator = 0;
    zeromem (samples, sizeof (samples));
    setOpaque (true);
	displayOutput = false;
	
    startTimer (1000 / 50); // use a timer to keep repainting this component
}

LiveAudioDisplayComp::~LiveAudioDisplayComp()
{
}

void LiveAudioDisplayComp::setDisplayOutput(bool output){
	displayOutput = output;
}

void LiveAudioDisplayComp::paint (Graphics& g)
{
    g.fillAll (Colours::black);
	
    g.setColour (Colours::green);
    const float midY = getHeight() * 0.5f;
    int sampleNum = (nextSample + numElementsInArray (samples) - 1);
	
    for (int x = jmin (getWidth(), numElementsInArray (samples)); --x >= 0;)
    {
        const float sampleSize = midY * samples [sampleNum-- % numElementsInArray (samples)];
        g.drawVerticalLine (x, midY - sampleSize, midY + sampleSize);
    }
}

void LiveAudioDisplayComp::timerCallback()
{
    repaint();
}

void LiveAudioDisplayComp::audioDeviceAboutToStart (AudioIODevice*)
{
    zeromem (samples, sizeof (samples));
}

void LiveAudioDisplayComp::audioDeviceStopped()
{
    zeromem (samples, sizeof (samples));
}
void LiveAudioDisplayComp::audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                                       float** outputChannelData, int numOutputChannels, int numSamples)
{
		
	if(!displayOutput)
	{
		for (int i = 0; i < numSamples; ++i)
		{
			for (int chan = 0; chan < numInputChannels; ++chan)
			{
				if (inputChannelData[chan] != 0)
					accumulator += fabsf (inputChannelData[chan][i]);
			}
			
			const int numSubSamples = 100; // how many input samples go onto one pixel.
			const float boost = 10.0f;     // how much to boost the levels to make it more visible.
			
			if (subSample == 0)
			{
				samples[nextSample] = accumulator * boost / numSubSamples;
				nextSample = (nextSample + 1) % numElementsInArray (samples);
				subSample = numSubSamples;
				accumulator = 0;
			}
			else
			{
				--subSample;
			}
		}
		// We need to clear the output buffers, in case they're full of junk..
		for (int i = 0; i < numOutputChannels; ++i)
			if (outputChannelData[i] != 0)
				zeromem (outputChannelData[i], sizeof (float) * numSamples);
	}
	else
	{
		for (int i = 0; i < numSamples; ++i)
		{
			for (int chan = 0; chan < numOutputChannels; ++chan)
			{
				if (outputChannelData[chan] != 0)
					accumulator += fabsf (outputChannelData[chan][i]);
			}
			
			const int numSubSamples = 100; // how many input samples go onto one pixel.
			const float boost = 10.0f;     // how much to boost the levels to make it more visible.
			
			if (subSample == 0)
			{
				samples[nextSample] = accumulator * boost / numSubSamples;
				nextSample = (nextSample + 1) % numElementsInArray (samples);
				subSample = numSubSamples;
				accumulator = 0;
			}
			else
			{
				--subSample;
			}
		}
    }
	
}


/*
 * AudioRecorder Class Implementation
 */


AudioRecorder::AudioRecorder() : backgroundThread ("Audio Recorder Thread"),
	sampleRate (0), activeWriter (0)
{
        backgroundThread.startThread();
}
	
AudioRecorder::~AudioRecorder()
{
        stop();
}
	
void AudioRecorder::startRecording (const File& file)
{
        stop();
		
        if (sampleRate > 0)
        {
            // Create an OutputStream to write to our destination file...
            file.deleteFile();
            ScopedPointer<FileOutputStream> fileStream (file.createOutputStream());
			
            if (fileStream != 0)
            {
                // Now create a WAV writer object that writes to our output stream...
                WavAudioFormat wavFormat;
                AudioFormatWriter* writer = wavFormat.createWriterFor (fileStream, sampleRate, 1, 16, StringPairArray(), 0);
				
                if (writer != 0)
                {
                    fileStream.release(); // (passes responsibility for deleting the stream to the writer object that is now using it)
					
                    // Now we'll create one of these helper objects which will act as a FIFO buffer, and will
                    // write the data to disk on our background thread.
                    threadedWriter = new AudioFormatWriter::ThreadedWriter (writer, backgroundThread, 32768);
					
                    // And now, swap over our active writer pointer so that the audio callback will start using it..
                    const ScopedLock sl (writerLock);
                    activeWriter = threadedWriter;
                }
            }
        }
}
	
void AudioRecorder::stop()
{
        // First, clear this pointer to stop the audio callback from using our writer object..
        {
            const ScopedLock sl (writerLock);
            activeWriter = 0;
        }
		
        // Now we can delete the writer object. It's done in this order because the deletion could
        // take a little time while remaining data gets flushed to disk, so it's best to avoid blocking
        // the audio callback while this happens.
        threadedWriter = 0;
}
	
bool AudioRecorder::isRecording() const
{
       return activeWriter != 0;
}
	
    //==============================================================================
void AudioRecorder::audioDeviceAboutToStart (AudioIODevice* device)
{
        sampleRate = device->getCurrentSampleRate();
}

void AudioRecorder::audioDeviceStopped()
{
        sampleRate = 0;
}
	
void AudioRecorder::audioDeviceIOCallback (const float** inputChannelData, int /*numInputChannels*/,
                                float** outputChannelData, int numOutputChannels,
                                int numSamples)
{
        const ScopedLock sl (writerLock);
		
        if (activeWriter != 0)
            activeWriter->write (inputChannelData, numSamples);
		
        // We need to clear the output buffers, in case they're full of junk..
        for (int i = 0; i < numOutputChannels; ++i)
            if (outputChannelData[i] != 0)
                zeromem (outputChannelData[i], sizeof (float) * numSamples);
}
	

/*
 *AudioPlayer Class Implementation
 */

AudioPlayer::AudioPlayer(){
	audioSourcePlayer.setSource (&transportSource);
}
AudioPlayer::~AudioPlayer(){
	transportSource.setSource (0);
	audioSourcePlayer.setSource(0);
}

void AudioPlayer::loadFile(const File& audioFile)
{
    // unload the previous file source and delete it..
    transportSource.stop();
    transportSource.setSource (0);
    currentAudioFileSource = 0;
	
    // get a format manager and set it up with the basic types (wav and aiff).
    AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
	
    AudioFormatReader* reader = formatManager.createReaderFor (audioFile);
	
    if (reader != 0)
    {
        currentAudioFileSource = new AudioFormatReaderSource (reader, true);
		
        // ..and plug it into our transport source
        transportSource.setSource (currentAudioFileSource,
                                   32768, // tells it to buffer this many samples ahead
                                   reader->sampleRate);
    }
}

void AudioPlayer::play(){
	transportSource.start();
}
void AudioPlayer::stop(){
	transportSource.stop();
}
bool AudioPlayer::isPlaying() const{
	return transportSource.isPlaying();
}

void AudioPlayer::audioDeviceAboutToStart (AudioIODevice* device){
	audioSourcePlayer.audioDeviceAboutToStart(device);
}
void AudioPlayer::audioDeviceStopped(){
	audioSourcePlayer.audioDeviceStopped();
}
void AudioPlayer::audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
							float** outputChannelData, int numOutputChannels,
							int numSamples){
	audioSourcePlayer.audioDeviceIOCallback(inputChannelData, numInputChannels, outputChannelData, numOutputChannels, numSamples);
}


