/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  30 Jan 2011 1:30:18am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "RangLoopComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...


//[/MiscUserDefs]

//==============================================================================
RangLoopComponent::RangLoopComponent ()
    : recordButton (0),
      switchButton (0),
      reverseButton (0),
      stackButton (0),
      slider (0),
      durationLabel (0),
      playtimeLabel (0),
      volumeKnob (0),
      label3 (0),
      decayKnob (0),
      label2 (0),
      speedKnob (0),
      label4 (0),
      deviceButton (0),
      speedButton (0),
      cachedImage_ftttmlogorings_gif (0)
{
    addAndMakeVisible (recordButton = new TextButton ("record"));
    recordButton->addListener (this);
    recordButton->setColour (TextButton::buttonColourId, Colour (0xff6be171));
    recordButton->setColour (TextButton::buttonOnColourId, Colours::green);

    addAndMakeVisible (switchButton = new TextButton ("switch"));
    switchButton->setButtonText ("A / B");
    switchButton->addListener (this);
    switchButton->setColour (TextButton::buttonColourId, Colour (0xff6be171));
    switchButton->setColour (TextButton::buttonOnColourId, Colours::green);

    addAndMakeVisible (reverseButton = new TextButton ("reverse"));
    reverseButton->addListener (this);
    reverseButton->setColour (TextButton::buttonColourId, Colour (0xff6be171));
    reverseButton->setColour (TextButton::buttonOnColourId, Colours::green);

    addAndMakeVisible (stackButton = new TextButton ("stack"));
    stackButton->addListener (this);
    stackButton->setColour (TextButton::buttonColourId, Colour (0xff6be171));
    stackButton->setColour (TextButton::buttonOnColourId, Colours::green);

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::LinearHorizontal);
    slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider->setColour (Slider::thumbColourId, Colour (0xff6be171));
    slider->setColour (Slider::rotarySliderFillColourId, Colour (0xff6be171));
    slider->addListener (this);

    addAndMakeVisible (durationLabel = new Label ("durationLabel",
                                                  "0:00"));
    durationLabel->setFont (Font (10.0000f, Font::bold));
    durationLabel->setJustificationType (Justification::centred);
    durationLabel->setEditable (false, false, false);
    durationLabel->setColour (Label::textColourId, Colour (0xff6be171));
    durationLabel->setColour (TextEditor::textColourId, Colours::black);
    durationLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (playtimeLabel = new Label ("playtime",
                                                  "0:00"));
    playtimeLabel->setFont (Font (10.0000f, Font::plain));
    playtimeLabel->setJustificationType (Justification::centred);
    playtimeLabel->setEditable (false, false, false);
    playtimeLabel->setColour (Label::textColourId, Colour (0xff6be171));
    playtimeLabel->setColour (TextEditor::textColourId, Colours::black);
    playtimeLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (volumeKnob = new Slider ("volumeKnob"));
    volumeKnob->setRange (0, 10, 0);
    volumeKnob->setSliderStyle (Slider::Rotary);
    volumeKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volumeKnob->setColour (Slider::rotarySliderFillColourId, Colour (0xff6be171));
    volumeKnob->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           "volume"));
    label3->setFont (Font (11.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colour (0xff6be171));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (decayKnob = new Slider ("decayKnob"));
    decayKnob->setRange (0, 10, 0);
    decayKnob->setSliderStyle (Slider::Rotary);
    decayKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    decayKnob->setColour (Slider::rotarySliderFillColourId, Colour (0xff6be171));
    decayKnob->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           "decay"));
    label2->setFont (Font (11.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colour (0xff6be171));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (speedKnob = new Slider ("speedKnob"));
    speedKnob->setRange (0, 10, 0);
    speedKnob->setSliderStyle (Slider::Rotary);
    speedKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    speedKnob->setColour (Slider::rotarySliderFillColourId, Colour (0xff6be171));
    speedKnob->addListener (this);

    addAndMakeVisible (label4 = new Label ("new label",
                                           "speed"));
    label4->setFont (Font (11.0000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colour (0xff6be171));
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (deviceButton = new TextButton ("devices"));
    deviceButton->setButtonText ("Audio device...");
    deviceButton->addListener (this);
    deviceButton->setColour (TextButton::buttonColourId, Colour (0xff6be171));

    addAndMakeVisible (speedButton = new TextButton ("speed"));
    speedButton->addListener (this);
    speedButton->setColour (TextButton::buttonColourId, Colour (0xff6be171));
    speedButton->setColour (TextButton::buttonOnColourId, Colours::green);

    cachedImage_ftttmlogorings_gif = ImageCache::getFromMemory (ftttmlogorings_gif, ftttmlogorings_gifSize);

    //[UserPreSize]
	this->setWantsKeyboardFocus(true);
	
	recordButton->setClickingTogglesState(true);
	switchButton->setClickingTogglesState(true);
	stackButton->setClickingTogglesState(true);
	reverseButton->setClickingTogglesState(true);
	speedButton->setClickingTogglesState(true);
	
	volumeKnob->setValue(8.0, false, false);
	decayKnob->setValue(3.0, false, false);
	speedKnob->setValue(5.0, false, false);
	
	//deviceSelector = new AudioDeviceSelectorComponent (audioDeviceManager, 0, 2, 0, 2, true, true, true, false);
	addAndMakeVisible (liveAudioInDisplayComp = new LiveAudioDisplayComp());
	addAndMakeVisible (liveAudioOutDisplayComp = new LiveAudioDisplayComp());
	liveAudioOutDisplayComp->setDisplayOutput(true);
    //[/UserPreSize]

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
	// and initialise the device manager with no settings so that it picks a default device to use.
	recorder = new AudioRecorder();
	
	nowPlaying = false;
	nowRecording = false;
	nowStacking = false;
	nowSpeeding = false;
	nowReversing = false;
	playbackPosition = 0;
	samplesRecorded = 0;
	playbackPositionB = 0;
	samplesRecordedB = 0;
	loopB = false;
	currentBuffer = NULL;
	sampleBuffer = NULL;
	sampleBufferB = NULL;

    const String error (audioDeviceManager.initialise (1, /* number of input channels */
                                                       2, /* number of output channels */
                                                       0, /* no XML settings.. */
                                                       true  /* select default device on failure */));

    if (error.isNotEmpty())
    {
        AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                     "Sound PLy3R",
                                     "Couldn't open an output device!\n\n" + error);
    }
    else
    {
        //audioSourcePlayer.setSource (&transportSource);

        // start the IO device pulling its data from our callback..
		audioDeviceManager.addAudioCallback (liveAudioInDisplayComp);
		audioDeviceManager.addAudioCallback (this);
		//audioDeviceManager.addAudioCallback (recorder);
		audioDeviceManager.addAudioCallback (liveAudioOutDisplayComp);
	}
  
  this->toFront(true);
    //[/Constructor]
}

RangLoopComponent::~RangLoopComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	audioDeviceManager.removeAudioCallback (recorder);
    audioDeviceManager.removeAudioCallback (liveAudioInDisplayComp);
	audioDeviceManager.removeAudioCallback (liveAudioOutDisplayComp);
    recorder = 0;

	deleteAndZero(liveAudioInDisplayComp);
	deleteAndZero(liveAudioOutDisplayComp);
	//deleteAndZero(deviceSelector);
    //[/Destructor_pre]

    deleteAndZero (recordButton);
    deleteAndZero (switchButton);
    deleteAndZero (reverseButton);
    deleteAndZero (stackButton);
    deleteAndZero (slider);
    deleteAndZero (durationLabel);
    deleteAndZero (playtimeLabel);
    deleteAndZero (volumeKnob);
    deleteAndZero (label3);
    deleteAndZero (decayKnob);
    deleteAndZero (label2);
    deleteAndZero (speedKnob);
    deleteAndZero (label4);
    deleteAndZero (deviceButton);
    deleteAndZero (speedButton);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RangLoopComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	//slider->setValue( audioDeviceManager.getCurrentInputLevel() );
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    g.setColour (Colours::black);
    g.drawImage (cachedImage_ftttmlogorings_gif,
                 332, 68, 128, 128,
                 0, 0, cachedImage_ftttmlogorings_gif.getWidth(), cachedImage_ftttmlogorings_gif.getHeight());

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RangLoopComponent::resized()
{
    recordButton->setBounds (8, 168, 72, 24);
    switchButton->setBounds (88, 168, 72, 24);
    reverseButton->setBounds (168, 168, 72, 24);
    stackButton->setBounds (248, 168, 72, 24);
    slider->setBounds (16, 136, 264, 8);
    durationLabel->setBounds (275, 128, 48, 24);
    playtimeLabel->setBounds (0, 144, 48, 24);
    volumeKnob->setBounds (272, 79, 40, 24);
    label3->setBounds (272, 103, 39, 24);
    decayKnob->setBounds (236, 79, 40, 24);
    label2->setBounds (236, 103, 39, 24);
    speedKnob->setBounds (197, 79, 40, 24);
    label4->setBounds (197, 103, 39, 24);
    deviceButton->setBounds (8, 88, 104, 24);
    speedButton->setBounds (120, 88, 72, 24);
    //[UserResized] Add your own custom resize handling here..
	liveAudioInDisplayComp->setBounds (8, 4, getWidth() - 16, 64);
	liveAudioOutDisplayComp->setBounds (8, 208, getWidth() - 16, 64);
	//deviceSelector->setBounds (350, 8, getWidth() / 3 - 16, getHeight() - 16);
    //[/UserResized]
}

void RangLoopComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == recordButton)
    {
        //[UserButtonCode_recordButton] -- add your button handler code here..
		toggleRecord();
        //[/UserButtonCode_recordButton]
    }
    else if (buttonThatWasClicked == switchButton)
    {
        //[UserButtonCode_switchButton] -- add your button handler code here..
		switchLoop();
        //[/UserButtonCode_switchButton]
    }
    else if (buttonThatWasClicked == reverseButton)
    {
        //[UserButtonCode_reverseButton] -- add your button handler code here..
		toggleReverse();
        //[/UserButtonCode_reverseButton]
    }
    else if (buttonThatWasClicked == stackButton)
    {
        //[UserButtonCode_stackButton] -- add your button handler code here..
		toggleStack();
        //[/UserButtonCode_stackButton]
    }
    else if (buttonThatWasClicked == deviceButton)
    {
        //[UserButtonCode_deviceButton] -- add your button handler code here..
		AudioDemoSetupPage *ds = new AudioDemoSetupPage(audioDeviceManager);
		
		DialogWindow::showModalDialog(	"Configure Audio Device",
									   ds,
									   this,
									  Colours::black,
										  true);
		deleteAndZero(ds);
        //[/UserButtonCode_deviceButton]
    }
    else if (buttonThatWasClicked == speedButton)
    {
        //[UserButtonCode_speedButton] -- add your button handler code here..
        //[/UserButtonCode_speedButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void RangLoopComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == volumeKnob)
    {
        //[UserSliderCode_volumeKnob] -- add your slider handling code here..
        //[/UserSliderCode_volumeKnob]
    }
    else if (sliderThatWasMoved == decayKnob)
    {
        //[UserSliderCode_decayKnob] -- add your slider handling code here..
        //[/UserSliderCode_decayKnob]
    }
    else if (sliderThatWasMoved == speedKnob)
    {
        //[UserSliderCode_speedKnob] -- add your slider handling code here..
        //[/UserSliderCode_speedKnob]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

bool RangLoopComponent::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
	int code = key.getKeyCode();
	ModifierKeys mods = key.getModifiers();
	
	float val = 0.1f;
	
	/*if ( mods == ModifierKeys::altModifier ){
	//	switchLoop();
		
	}
	if (mods == ModifierKeys::ctrlModifier) {
		if( nowPlaying )stop();
		else play();
	}*/
	if (mods == ModifierKeys::commandModifier) {
		toggleReverse();
	}
	

				
	if( mods == ModifierKeys::ctrlModifier ){
		val = 1.0f;
	}

		
	if ( code == KeyPress::deleteKey || code == KeyPress::escapeKey ){
		if( nowPlaying )stop();
		else play();
		return true;
		
	}else if( code == 196640 ){
		toggleReverse();
		return true;
	
	}else if( code == KeyPress::pageDownKey){
		switchLoop();
		return true;
			
	}else if( code == KeyPress::pageUpKey){
		switchLoop();
		if( !nowRecording ) toggleRecord();
		return true;
		
	}else if( code == KeyPress::spaceKey ){
			if(!nowPlaying) toggleRecord();
			else toggleStack();
			return true;
	}
	
	if ( key.isCurrentlyDown() ){	
		if (code == KeyPress::downKey ){
				volumeKnob->setValue( volumeKnob->getValue() - val, true, false);
				return true;
		}else if( code == KeyPress::upKey ){
				volumeKnob->setValue( volumeKnob->getValue() + val, true, false);
				return true;
		}else if( code == KeyPress::leftKey ){
				decayKnob->setValue( decayKnob->getValue() - val, true, false);
				return true;
		}else if( code == KeyPress::rightKey ){
				decayKnob->setValue( decayKnob->getValue() + val, true, false);
				return true;
			
		}
	}
	
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void RangLoopComponent::play(){
	
	if( curLoop > loops.size()) return;
	
  loops[curLoop].rewind();
  loops[curLoop].play(); 
  
	//loopB ? playbackPositionB = 0 : playbackPosition = 0;
	nowPlaying = true;
}
void RangLoopComponent::stop(){
  if( curLoop > loops.size() ) return;
	loops[curLoop].stop();	
}

void RangLoopComponent::toggleRecord(){
	
	if(!nowRecording){
		int sampleRate = audioDeviceManager.getCurrentAudioDevice()->getCurrentSampleRate();
		if( loops.size() <= curLoop ){
      curLoop = loops.size();
      loops.push_back( Loop( 10.0f, sampleRate ));
    } //else loops[curLoop] = Loop( 10.f, sampleRate );
                      
		//currentBuffer = new AudioSampleBuffer(1, 60 * sampleRate );
		recordButton->setToggleState(true,false);
		
		/*if( loopB ){
			samplesRecordedB = 0;
			sampleBufferB = currentBuffer;
		}else {
			samplesRecorded = 0;
			sampleBuffer = currentBuffer;
		}*/
    loops[curLoop].stop();
    loops[curLoop].record();
		nowPlaying = false;
		nowRecording = true;
	}else{
    
		nowRecording = false;
    loops[curLoop].stop();
		recordButton->setToggleState(false,false);
		play();
	}
	
}
void RangLoopComponent::toggleStack(){
	if(!nowStacking && curLoop < loops.size() ){
		nowStacking = true;
    loops[curLoop].stack();
		stackButton->setToggleState(true,false);
		
	}else{
		nowStacking = false;
    loops[curLoop].stack();
		stackButton->setToggleState(false,false);
	}	
}
void RangLoopComponent::toggleReverse(){	

  loops[curLoop].reverse();
	nowReversing = !nowReversing;
	reverseButton->setToggleState(nowReversing,false);
		
}
void RangLoopComponent::switchLoop(){
	
	if( nowRecording ) toggleRecord();

	/*AudioSampleBuffer* buff;
	loopB = !loopB;
	switchButton->setToggleState(loopB, false);
	
	buff = loopB ? sampleBufferB : sampleBuffer;*/
  
  curLoop = !curLoop;
	
	if( loops.size() <= curLoop ){
		
		nowRecording = false;
		nowPlaying = false;
		//currentBuffer = NULL;
		toggleRecord();
		//int sampleRate = audioDeviceManager.getCurrentAudioDevice()->getCurrentSampleRate();
		//buff = new AudioSampleBuffer(1, 60 * sampleRate );
	}else {
		//currentBuffer = buff;
		play();
	}
}

void RangLoopComponent::audioDeviceIOCallback (const float** inputChannelData,
												 int totalNumInputChannels,
												 float** outputChannelData,
												 int totalNumOutputChannels,
												 int numSamples)
{
  for (int i = 0; i < totalNumOutputChannels; ++i)
    if (outputChannelData[i] != 0)
      zeromem (outputChannelData[i], sizeof (float) * numSamples);
  
	if( nowRecording || nowPlaying )
    loops[curLoop].audioIO( (float**)inputChannelData, (float**)outputChannelData, numSamples );


	/*double gain = volumeKnob->getValue() / volumeKnob->getMaximum();
	unsigned long samplesRec = loopB ? samplesRecordedB : samplesRecorded;
	unsigned long playbackPos = loopB ? playbackPositionB : playbackPosition;

	if(nowRecording){ //fresh loop
		//resize buffer if needed
		if(samplesRec + numSamples >= currentBuffer->getNumSamples()){
			currentBuffer->setSize(1, 2 * currentBuffer->getNumSamples(), true, false, true);
		}

		currentBuffer->copyFrom(0, samplesRec, inputChannelData[0], numSamples);
		samplesRec += numSamples;
		
	}else if(nowPlaying){ //playback and stack
		
		
		if(nowReversing){

			if(playbackPos == 0) playbackPos = samplesRec;
			int prevPos = playbackPos;
			int underlap = playbackPos - numSamples;
			float *tmp = currentBuffer->getSampleData(0, playbackPos);
			
			if(underlap < 0){
				for( int i = 0; i < playbackPos; i++){
					outputChannelData[0][i] = *(--tmp) * gain;
					outputChannelData[1][i] = *tmp * gain;
				}
				tmp = currentBuffer->getSampleData(0, samplesRec);
				for( int i = playbackPos; i < numSamples; i++){
					outputChannelData[0][i] = *(--tmp) * gain;
					outputChannelData[1][i] = *tmp * gain;
				}
				
				playbackPos = samplesRec + underlap;
				
			}else{
				for( int i = 0; i < numSamples; i++){
					outputChannelData[0][i] = *(--tmp) * gain;
					outputChannelData[1][i] = *tmp * gain;
				}
				playbackPos -= numSamples;
			}
			
			if(nowStacking){ //used to be outside elseif !nowRecording && currentBuffer ?	
				currentBuffer->applyGain(playbackPos, numSamples, 1.0f - (decayKnob->getValue() / decayKnob->getMaximum()) );
				float *tmp = currentBuffer->getSampleData(0, prevPos);
				for(int i = 0; i < numSamples; i++){
					*(--tmp) += inputChannelData[0][i];
					
				}
			}			
			
		}else{//
			
			if(playbackPos == samplesRec) playbackPos = 0;
			int prevPos = playbackPos;

			float *tmp = currentBuffer->getSampleData(0, playbackPos);
			int overlap = playbackPos + numSamples - samplesRec;
			if(overlap > 0){
				
				for( int i = 0; i < numSamples - overlap; i++){
					outputChannelData[0][i] = tmp[i] * gain;
					outputChannelData[1][i] = tmp[i] * gain;
				}
				tmp = currentBuffer->getSampleData(0, 0);
				for( int i = numSamples - overlap; i < numSamples; i++){
					outputChannelData[0][i] = tmp[i] * gain;
					outputChannelData[1][i] = tmp[i] * gain;
				}
				//memcpy(outputChannelData[0], tmp, numSamples - overlap * sizeof(float) );
				//memcpy(outputChannelData[0]+(numSamples-overlap), currentBuffer->getSampleData(0), overlap  * sizeof(float) );
				//memcpy(outputChannelData[1], tmp, numSamples - overlap);
				//memcpy(outputChannelData[1]+(numSamples-overlap), currentBuffer->getSampleData(0), overlap  * sizeof(float) );
				playbackPos = overlap;

			}else{
				for( int i = 0; i < numSamples; i++){
					outputChannelData[0][i] = tmp[i] * gain;
					outputChannelData[1][i] = tmp[i] * gain;
				}
				//memcpy(outputChannelData[0], tmp, numSamples  * sizeof(float) );
				//memcpy(outputChannelData[1], tmp, numSamples  * sizeof(float) );
				playbackPos += numSamples;
			}
		
			if(nowStacking){ //used to be outside elseif !nowRecording && currentBuffer ?	
				currentBuffer->applyGain(prevPos, numSamples, 1.0f - (decayKnob->getValue() / decayKnob->getMaximum()) );
				currentBuffer->addFrom(0, prevPos, inputChannelData[0], numSamples);
			}			
			
		}
		
	}else{
		// We need to clear the output buffers, in case they're full of junk..
		for (int i = 0; i < totalNumOutputChannels; ++i)
			if (outputChannelData[i] != 0)
				zeromem (outputChannelData[i], sizeof (float) * numSamples);
	}

	if( loopB ){
		samplesRecordedB = samplesRec;
		playbackPositionB = playbackPos;
	}else{
		samplesRecorded = samplesRec;
		playbackPosition = playbackPos;
	}*/

	//for( int i = 0; i < numSamples; i++)
	//	outputChannelData[0][i] = inputChannelData[0][i];

    // pass the audio callback on to our player source
	// audioSourcePlayer.audioDeviceIOCallback (inputChannelData, totalNumInputChannels, outputChannelData, totalNumOutputChannels, numSamples);

	/*AudioSourceChannelInfo fileBufInfo =  AudioSourceChannelInfo();

	AudioSampleBuffer fileBuffer = AudioSampleBuffer( outputChannelData, totalNumOutputChannels, numSamples);

	fileBufInfo.buffer = &fileBuffer;
	fileBufInfo.startSample = 0;
	fileBufInfo.numSamples = numSamples;

	transportSource.getNextAudioBlock( fileBufInfo);


	if( recordFileStream && !stackButton->getToggleState()){

		AudioSampleBuffer inputBuffer = AudioSampleBuffer( (float **)inputChannelData, totalNumInputChannels, numSamples);

		inputBuffer.writeToAudioWriter( recordWriter, 0, numSamples);

		//	fileBuffer.copyFrom( 0,0, inputBuffer, 0, 0, numSamples);

		samplesRecorded += numSamples;
	}


	if( recordFileStream && stackButton->getToggleState()){

		AudioSampleBuffer inputBuffer = AudioSampleBuffer( (float **)inputChannelData, totalNumInputChannels, numSamples);

		inputBuffer.addFromWithRamp(0, 0, fileBuffer.getSampleData(0), numSamples, .9, .9);

		recordFileStream->setPosition(44 + (samplesRecorded % currentAudioFileSource->getTotalLength()));
		inputBuffer.writeToAudioWriter( recordWriter, 0, numSamples);

		samplesRecorded += numSamples;

	}*/
}

void RangLoopComponent::audioDeviceAboutToStart (AudioIODevice* device)
{
    //audioSourcePlayer.audioDeviceAboutToStart (device);
}

void RangLoopComponent::audioDeviceStopped()
{
    //audioSourcePlayer.audioDeviceStopped();
}


void RangLoopComponent::changeListenerCallback (ChangeBroadcaster *source)
{
    // callback from the transport source to tell us that play has
    // started or stopped, so update our buttons..
    repaint();
}

void RangLoopComponent::updatePlaytimeLabel(){

	/*int seconds = transportSource.getNextReadPosition() / currentSampleRate;
	int minutes = seconds / 60;
	seconds = seconds % 60;
	playtimeLabel->setText( String(minutes) + ":" + (seconds > 9 ? (String(seconds)):("0"+String(seconds))) , false );
	playtimeLabel->setTopLeftPosition( slider->getPositionOfValue(slider->getValue()) - playtimeLabel->getWidth()/2 + slider->getX(), playtimeLabel->getY());*/
}

void RangLoopComponent::timerCallback(){

	/*if( recordFileStream && !stackButton->getToggleState() ) {
		int seconds = (double)samplesRecorded / recordWriter->getSampleRate();
		int minutes = seconds / 60;
		seconds = seconds % 60;
		durationLabel->setText( String(minutes) + ":" + (seconds > 9 ? (String(seconds)):("0"+String(seconds))) , false);

	}else if( transportSource.isPlaying()){
		slider->setValue( (float)transportSource.getNextReadPosition() / (float)transportSource.getTotalLength() * 10);
		updatePlaytimeLabel();
	}*/
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RangLoopComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff000000">
    <IMAGE pos="332 68 128 128" resource="ftttmlogorings_gif" opacity="1"
           mode="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="record" id="2e705ec45ad2983d" memberName="recordButton"
              virtualName="" explicitFocusOrder="0" pos="8 168 72 24" bgColOff="ff6be171"
              bgColOn="ff008000" buttonText="record" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="switch" id="eed935707ea8ad65" memberName="switchButton"
              virtualName="" explicitFocusOrder="0" pos="88 168 72 24" bgColOff="ff6be171"
              bgColOn="ff008000" buttonText="A / B" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="reverse" id="9581e586633172eb" memberName="reverseButton"
              virtualName="" explicitFocusOrder="0" pos="168 168 72 24" bgColOff="ff6be171"
              bgColOn="ff008000" buttonText="reverse" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="stack" id="c95a37574ee788a9" memberName="stackButton" virtualName=""
              explicitFocusOrder="0" pos="248 168 72 24" bgColOff="ff6be171"
              bgColOn="ff008000" buttonText="stack" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="new slider" id="600d5c02ae538547" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="16 136 264 8" thumbcol="ff6be171"
          rotarysliderfill="ff6be171" min="0" max="10" int="0" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="durationLabel" id="edd486ab06e40cbf" memberName="durationLabel"
         virtualName="" explicitFocusOrder="0" pos="275 128 48 24" textCol="ff6be171"
         edTextCol="ff000000" edBkgCol="0" labelText="0:00" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="1" italic="0" justification="36"/>
  <LABEL name="playtime" id="b3c3484d92fa9ac1" memberName="playtimeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 144 48 24" textCol="ff6be171"
         edTextCol="ff000000" edBkgCol="0" labelText="0:00" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="0" italic="0" justification="36"/>
  <SLIDER name="volumeKnob" id="15bbd88fe33cb947" memberName="volumeKnob"
          virtualName="" explicitFocusOrder="0" pos="272 79 40 24" rotarysliderfill="ff6be171"
          min="0" max="10" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="efd284515b19c3ca" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="272 103 39 24" textCol="ff6be171"
         edTextCol="ff000000" edBkgCol="0" labelText="volume" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="33"/>
  <SLIDER name="decayKnob" id="230bee0727aedcef" memberName="decayKnob"
          virtualName="" explicitFocusOrder="0" pos="236 79 40 24" rotarysliderfill="ff6be171"
          min="0" max="10" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="3ff5a890e2ada81d" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="236 103 39 24" textCol="ff6be171"
         edTextCol="ff000000" edBkgCol="0" labelText="decay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="33"/>
  <SLIDER name="speedKnob" id="f80b540670d69f9b" memberName="speedKnob"
          virtualName="" explicitFocusOrder="0" pos="197 79 40 24" rotarysliderfill="ff6be171"
          min="0" max="10" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="bce4a94ac3892128" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="197 103 39 24" textCol="ff6be171"
         edTextCol="ff000000" edBkgCol="0" labelText="speed" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="11" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="devices" id="7aa3c0dfe732b1e6" memberName="deviceButton"
              virtualName="" explicitFocusOrder="0" pos="8 88 104 24" bgColOff="ff6be171"
              buttonText="Audio device..." connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="speed" id="a63a7877645b3efb" memberName="speedButton" virtualName=""
              explicitFocusOrder="0" pos="120 88 72 24" bgColOff="ff6be171"
              bgColOn="ff008000" buttonText="speed" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: ftttmlogorings_gif, 7463, "../../../../../Desktop/ftttmlogorings.gif"
static const unsigned char resource_RangLoopComponent_ftttmlogorings_gif[] = { 71,73,70,56,57,97,128,0,128,0,247,0,0,0,0,0,112,111,112,16,25,33,199,213,213,64,60,60,2,16,7,173,173,173,25,0,0,148,148,148,
204,42,42,34,25,33,25,16,8,87,86,87,193,198,198,0,3,5,213,221,221,212,114,114,8,33,16,36,42,38,230,230,230,10,16,23,18,30,41,51,0,0,129,128,127,165,165,165,40,16,10,8,0,0,9,14,18,188,182,182,209,117,117,
42,24,33,54,49,49,41,0,0,7,4,6,77,80,80,107,107,107,25,35,48,247,247,247,213,147,147,26,17,23,9,17,8,205,195,195,40,26,17,206,88,88,16,16,16,33,0,0,1,8,3,41,29,39,34,28,38,7,10,14,42,48,44,181,181,181,
25,33,17,93,95,95,18,18,25,70,72,72,140,140,140,153,153,153,209,82,82,194,176,176,123,123,123,24,30,35,16,0,0,16,33,17,6,23,11,49,4,6,201,140,140,47,23,18,8,27,14,2,9,5,222,222,222,38,4,6,17,28,39,215,
197,197,34,3,5,212,131,131,41,18,24,26,3,5,56,28,32,24,14,18,14,21,27,215,153,153,239,239,239,255,255,255,41,35,47,9,38,18,201,185,185,54,25,25,48,13,9,221,231,231,206,58,58,25,25,25,34,35,48,15,4,6,49,
26,34,42,26,26,35,15,8,26,25,34,215,208,208,218,215,215,33,32,18,16,16,8,47,31,41,26,28,14,8,5,2,207,121,121,47,10,14,50,29,24,193,208,208,32,6,3,33,33,33,58,58,58,215,229,229,208,101,101,51,51,51,17,
24,12,16,26,13,17,6,3,214,214,214,33,39,46,40,5,2,27,6,3,34,8,8,23,11,14,215,178,178,17,38,19,25,39,51,23,28,38,24,32,42,49,17,22,17,10,14,48,17,15,25,22,11,218,174,174,43,14,14,56,30,32,42,11,14,50,7,
7,42,30,23,208,70,70,45,41,41,189,189,189,24,30,26,79,78,79,32,22,11,207,149,149,47,35,35,51,26,24,212,83,83,214,175,175,33,26,14,34,10,14,34,17,23,214,164,164,43,32,32,24,8,8,213,125,125,215,140,140,
199,192,192,66,66,66,8,8,8,48,51,55,58,63,59,33,14,18,58,33,25,208,104,104,204,51,51,219,209,209,183,187,187,2,27,11,39,38,37,115,115,115,204,204,204,197,197,197,90,90,90,41,45,48,205,131,131,58,58,49,
216,240,240,213,192,192,48,4,3,32,21,28,132,132,132,102,102,102,74,74,74,50,58,52,41,41,41,82,82,82,115,115,123,66,68,71,41,32,43,33,33,43,41,7,10,41,33,16,15,6,8,214,90,90,197,204,204,41,41,49,41,58,
49,214,99,99,206,139,139,202,181,181,202,186,186,59,62,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,33,249,4,0,7,0,255,0,44,0,0,0,
0,128,0,128,0,0,8,255,0,1,8,28,72,176,160,193,131,8,19,42,92,200,176,161,195,135,16,35,74,156,72,177,162,197,139,24,51,106,220,200,177,163,199,143,32,67,138,28,73,178,164,201,147,40,83,170,92,89,208,129,
203,151,48,29,176,156,89,49,38,40,80,49,114,234,220,25,227,230,205,151,52,131,30,124,121,51,198,134,163,27,40,40,93,202,84,41,210,13,59,129,10,85,249,82,103,82,165,80,178,66,17,192,181,171,87,174,90,179,
58,133,154,211,229,212,146,46,115,30,197,218,21,137,91,183,128,226,202,141,91,161,238,219,174,90,157,234,52,123,182,163,75,156,71,181,114,125,75,184,110,5,18,136,19,43,86,44,215,45,88,40,71,203,202,236,
139,209,193,205,192,91,5,192,157,251,170,23,3,87,143,150,133,186,99,184,116,221,197,140,1,185,21,75,33,103,136,16,148,41,90,54,186,33,171,102,36,128,22,87,120,195,3,3,42,84,56,108,93,184,117,227,21,160,
30,200,145,219,184,141,59,247,226,184,72,184,234,141,49,57,118,195,217,73,51,159,78,141,196,205,173,28,24,90,177,255,50,48,3,3,14,30,35,110,213,88,95,227,145,156,45,182,7,195,125,238,24,10,5,168,175,173,
43,76,155,253,246,115,213,209,81,32,199,42,224,181,210,74,120,6,228,128,192,130,10,158,183,138,43,111,108,177,22,5,153,221,230,92,98,117,9,0,217,6,63,233,103,208,107,129,105,118,33,98,25,106,120,159,27,
12,216,130,0,6,172,24,129,10,43,141,204,80,30,121,8,224,128,67,0,35,236,34,7,11,69,208,118,85,102,132,33,65,98,5,2,40,37,153,135,0,96,183,21,110,169,61,70,150,27,184,240,144,3,42,6,96,96,7,42,70,24,209,
138,130,228,53,210,74,35,8,164,247,136,12,33,16,117,89,118,61,184,161,138,42,61,96,88,65,86,28,130,82,29,101,150,101,231,22,99,171,217,7,21,11,110,200,177,203,42,182,216,18,222,4,172,176,50,1,6,60,24,
96,232,4,140,142,97,64,141,183,224,162,10,65,48,109,241,138,28,152,190,161,138,144,24,106,72,214,156,83,133,96,212,86,219,145,0,32,156,80,57,176,197,13,174,140,192,67,141,44,78,255,80,66,9,172,204,128,
67,35,70,204,58,171,20,19,52,130,40,15,145,234,2,10,65,54,200,113,3,46,200,246,210,203,142,135,37,166,26,156,29,10,101,25,40,20,50,233,38,156,101,1,0,202,46,60,216,152,67,130,158,200,58,197,20,138,78,
81,130,17,227,166,107,4,2,168,4,16,128,45,183,236,242,73,166,55,48,160,94,13,12,32,139,203,142,80,88,75,162,167,49,228,71,83,157,75,94,168,90,145,173,81,39,208,22,12,224,128,1,6,228,85,217,136,20,51,180,
98,196,5,168,76,33,133,20,83,24,97,135,20,90,138,97,4,43,182,4,23,192,45,40,7,176,10,15,23,172,114,11,3,12,60,226,94,136,165,2,98,98,182,44,57,48,170,0,205,254,11,217,145,91,184,34,40,121,51,52,242,91,
130,172,128,87,168,1,226,78,49,193,151,51,236,122,104,14,13,218,24,220,130,174,142,0,218,190,151,85,203,41,98,1,226,156,146,168,181,9,96,48,18,208,202,57,217,46,6,24,88,158,121,84,231,208,72,14,45,54,
50,1,14,6,152,91,194,4,118,176,255,194,113,9,27,143,193,131,140,57,220,40,28,122,174,182,247,201,39,186,188,70,54,169,61,19,121,159,156,99,199,80,237,133,68,254,172,240,64,111,32,8,49,15,171,184,90,50,
221,99,76,96,196,187,19,72,33,181,29,186,2,78,114,131,50,82,169,224,5,57,46,131,169,35,3,213,73,129,136,157,66,70,185,73,162,94,222,233,228,191,11,20,195,173,15,219,2,44,15,204,95,240,234,139,165,227,
144,3,224,27,239,218,122,175,118,52,162,125,43,85,90,189,74,13,243,170,226,72,12,148,234,76,161,217,189,115,8,42,72,193,247,123,33,218,9,175,191,197,130,6,60,138,99,13,34,136,208,234,171,6,52,98,7,14,
8,96,84,245,90,167,186,86,160,98,2,99,152,1,213,46,144,188,245,220,64,14,142,16,196,250,146,180,179,158,217,204,119,19,228,136,249,220,135,152,103,197,239,32,91,112,88,14,108,17,128,26,16,64,19,76,248,
194,7,88,21,0,233,205,128,7,1,24,67,233,84,71,64,41,140,208,0,35,8,206,5,20,164,188,26,236,107,11,176,73,136,238,255,120,230,44,79,21,207,35,58,171,141,181,158,149,170,12,130,226,22,56,248,222,35,36,113,
128,3,128,224,138,107,88,198,35,110,177,10,27,213,0,3,70,72,93,235,102,197,138,0,32,160,101,193,65,143,122,118,209,11,25,236,65,3,26,88,72,90,118,103,193,34,137,77,131,160,80,162,115,152,24,45,132,48,
162,6,174,248,196,23,90,0,2,11,24,210,144,10,144,195,39,118,113,11,21,5,32,7,173,16,227,174,16,112,139,242,156,81,107,34,184,193,39,108,167,10,61,84,241,0,112,92,200,77,232,56,188,59,106,36,143,28,52,
21,218,226,164,16,56,54,225,3,31,96,66,33,13,121,197,43,230,225,4,170,144,3,46,106,16,40,70,228,192,8,170,51,130,1,110,33,135,222,160,199,21,55,120,3,10,13,193,76,90,208,226,138,45,168,98,40,19,18,60,
34,254,171,53,124,57,37,40,182,242,62,223,13,11,33,112,172,98,11,8,121,72,104,126,210,7,232,100,129,12,112,1,69,6,204,192,14,19,176,149,244,48,128,0,151,61,66,83,155,16,39,57,203,9,255,130,104,162,51,
142,8,169,102,207,86,185,185,140,152,207,154,36,88,229,77,18,130,206,3,236,147,150,253,140,230,1,124,0,199,80,130,66,14,12,184,0,3,20,165,52,95,13,7,66,91,16,68,69,27,234,208,43,30,210,2,227,252,39,53,
45,103,54,231,40,52,131,17,33,88,228,126,6,83,0,56,180,5,39,189,226,57,41,122,16,55,60,226,123,24,48,218,120,206,211,30,55,28,4,142,13,37,100,45,205,137,206,132,220,132,155,29,212,144,41,39,130,74,107,
73,174,160,4,169,168,6,14,144,83,16,84,81,165,9,97,1,46,30,100,139,24,25,128,132,129,220,194,66,52,144,212,42,30,50,165,60,61,72,85,157,115,213,154,54,164,154,123,180,35,86,7,130,206,190,206,178,159,19,
141,171,66,108,48,86,8,173,232,60,174,32,128,90,27,194,86,116,62,20,176,130,165,84,85,19,243,210,154,228,17,161,149,45,72,56,199,201,217,113,74,19,160,7,113,129,104,69,235,211,85,124,162,6,10,226,1,248,
220,80,132,214,186,182,181,9,105,236,56,249,57,81,208,255,82,138,165,61,147,234,94,31,18,2,61,146,8,131,6,97,107,73,151,10,202,105,26,100,180,5,72,110,114,117,241,25,92,96,32,7,23,8,192,152,136,0,132,
234,42,55,185,163,69,72,67,151,170,211,200,14,4,175,215,220,237,117,88,58,23,59,174,79,184,220,141,166,113,9,130,220,2,84,23,8,68,136,175,12,144,57,130,17,2,235,19,142,136,175,126,223,11,4,229,138,246,
168,142,229,174,52,229,170,68,202,2,55,34,147,5,27,100,4,54,16,244,150,83,189,182,21,136,104,149,251,222,8,88,216,194,24,253,132,45,236,123,139,92,68,160,10,32,6,113,4,244,75,221,254,22,32,187,5,9,112,
57,7,220,18,220,70,21,155,49,37,239,191,212,167,89,31,88,241,193,96,29,200,132,221,91,93,11,135,88,196,50,96,192,159,10,135,30,99,164,226,194,72,70,114,124,77,252,223,26,223,152,150,44,38,136,168,82,153,
89,135,36,152,4,230,53,136,141,103,105,1,175,130,178,32,59,238,241,135,67,140,100,32,72,224,17,235,1,15,9,69,193,99,253,94,248,255,199,22,182,238,137,93,224,100,46,123,213,187,218,170,77,179,108,6,99,
135,28,148,174,7,230,171,67,87,252,101,246,186,128,199,73,190,112,137,251,235,136,27,140,224,19,143,40,89,0,24,192,2,10,243,55,209,113,102,50,157,27,188,229,183,214,182,197,187,115,105,160,69,89,96,83,
101,57,171,195,213,105,161,37,124,232,2,196,55,209,75,190,174,11,80,240,134,120,121,7,186,183,192,157,107,45,45,102,50,71,192,186,77,22,8,122,137,187,222,60,247,235,197,226,53,200,159,127,75,99,78,43,
85,213,182,157,112,143,127,188,100,19,207,249,191,186,168,129,214,234,135,128,0,24,53,38,187,70,116,146,169,139,221,172,110,185,150,45,104,234,109,67,173,224,13,4,113,33,189,61,54,98,164,58,39,182,62,
187,159,234,22,72,107,197,172,228,234,190,54,38,14,112,132,43,86,33,131,11,40,112,21,70,125,13,192,29,208,90,20,240,251,194,254,134,173,176,125,112,239,116,71,24,149,123,62,181,66,140,98,77,34,53,91,32,
231,134,102,190,1,176,111,32,140,59,226,175,255,109,173,79,64,193,48,30,200,225,13,130,186,128,28,68,213,19,199,129,187,8,21,46,51,16,92,235,108,226,70,86,103,80,77,40,20,2,38,71,25,11,221,221,168,222,
39,132,225,200,112,113,67,188,191,41,47,130,79,88,64,117,62,185,130,7,125,90,209,5,112,81,245,170,251,228,230,15,31,113,127,131,189,85,165,175,90,32,212,234,248,168,13,146,96,62,23,212,222,62,159,102,
17,220,123,114,236,142,214,5,55,169,250,22,246,190,5,25,168,199,13,8,104,196,89,137,233,136,194,59,194,235,63,129,201,220,31,78,238,96,135,28,223,182,141,55,167,220,94,211,180,139,154,67,4,121,188,197,
1,186,248,36,163,220,181,121,103,193,222,221,224,6,93,152,254,19,171,208,165,129,48,64,194,27,200,64,6,170,32,253,222,169,254,245,151,148,188,223,115,158,248,189,63,45,144,101,31,253,221,202,54,58,189,
123,94,203,226,106,160,233,38,47,179,221,69,27,250,209,155,62,83,203,96,128,105,3,63,84,30,236,98,25,111,192,20,35,98,63,123,22,212,222,37,201,141,175,255,136,169,43,113,0,148,253,173,35,199,56,179,191,
121,16,201,35,187,58,143,175,237,241,29,64,119,229,167,60,239,206,199,212,50,62,129,139,71,236,98,4,171,176,5,182,32,6,181,18,28,62,132,44,159,144,125,219,231,6,179,247,125,77,39,126,32,70,4,40,80,126,
241,39,88,238,103,106,125,198,118,122,214,110,236,7,119,34,231,3,18,230,116,191,118,109,120,7,10,84,183,5,165,247,114,252,183,11,12,80,3,40,99,90,140,128,0,91,98,43,170,101,47,53,176,11,184,208,11,10,
40,62,135,231,125,106,227,18,115,7,129,35,102,119,230,71,113,232,38,88,190,55,124,7,97,116,171,196,23,21,8,71,162,245,112,99,55,90,161,231,8,110,192,8,138,132,11,187,224,130,0,232,60,187,224,8,137,98,
0,189,97,11,66,86,3,209,53,2,248,242,8,189,96,59,186,192,128,180,247,131,15,104,127,69,0,114,86,84,124,182,149,118,205,178,74,192,151,59,49,0,85,148,167,123,71,200,116,65,168,124,119,135,127,106,242,114,
55,176,11,174,112,11,1,192,50,0,255,68,73,104,198,60,141,132,56,42,34,28,161,3,72,184,48,47,140,192,128,33,149,120,64,40,133,185,231,129,94,117,135,165,246,38,152,247,33,165,198,103,191,179,85,113,7,126,
201,151,105,41,23,3,162,151,130,252,103,47,162,3,64,224,1,49,15,131,0,84,243,48,245,179,139,53,210,50,104,184,11,201,36,7,226,99,3,62,8,19,225,87,102,18,23,114,22,151,59,169,168,113,3,145,96,10,197,87,
102,7,133,46,80,93,33,70,4,203,103,136,88,8,105,251,51,58,190,40,35,69,163,61,94,242,37,49,50,3,191,216,32,209,245,50,184,144,125,170,176,5,111,168,140,175,56,130,176,85,118,197,23,87,203,246,135,5,225,
98,191,39,108,131,214,101,181,21,135,16,119,127,179,200,8,111,176,72,218,214,45,188,8,49,229,120,142,6,34,30,17,25,145,84,82,37,133,211,50,238,200,73,242,232,131,3,209,121,16,55,103,225,68,108,0,37,124,
144,177,62,36,185,57,241,7,133,245,23,103,36,104,130,124,162,11,138,196,72,239,210,144,93,242,37,226,81,40,56,255,153,147,133,130,142,130,183,139,231,161,53,184,176,12,50,224,134,222,167,120,252,198,141,
5,224,18,231,39,144,32,136,118,164,244,143,253,200,110,252,104,132,34,7,71,131,24,129,201,101,38,44,224,8,185,164,144,1,112,1,52,137,10,18,89,40,98,96,7,102,121,150,104,153,147,80,83,30,246,5,148,111,
48,148,242,232,137,244,87,143,83,40,138,207,104,108,156,82,141,5,81,54,185,241,135,75,121,103,0,112,104,116,153,148,68,33,122,185,164,69,53,176,10,96,233,144,94,130,147,104,249,152,144,217,55,133,226,
9,49,66,79,63,201,0,201,212,134,54,32,8,11,165,111,174,54,102,72,41,19,41,25,71,23,104,138,236,55,16,165,104,71,0,41,146,87,89,5,220,248,90,38,184,119,186,240,6,187,244,149,14,227,27,141,201,10,144,153,
37,30,19,153,102,137,147,6,98,145,81,20,47,225,19,151,112,200,99,34,86,151,1,57,138,113,228,0,169,73,1,167,41,16,207,249,77,157,134,82,20,21,133,132,56,90,178,200,149,198,194,0,174,34,61,228,97,32,172,
255,32,6,99,128,150,188,41,67,232,57,6,70,144,158,50,36,6,4,104,64,85,130,0,182,240,61,239,168,153,28,233,153,68,160,104,5,48,135,246,6,101,77,233,156,91,241,126,123,41,111,166,9,114,74,119,157,43,249,
154,115,168,45,179,24,147,92,180,97,24,80,52,55,41,67,186,105,150,189,233,155,22,122,161,125,3,53,244,52,28,12,176,44,186,208,131,239,134,157,5,89,4,112,103,72,207,8,116,2,32,160,4,81,138,190,99,126,203,
57,81,104,128,115,64,144,156,39,38,16,162,178,149,179,137,11,173,178,152,18,58,158,236,25,164,66,42,67,26,250,155,95,242,92,231,65,156,114,224,134,106,131,159,31,41,90,206,88,92,42,10,8,126,192,143,168,
73,160,47,250,151,160,36,152,204,184,160,177,217,39,139,116,11,221,2,49,185,25,153,89,50,164,67,90,150,146,89,153,35,84,66,245,121,120,157,25,152,9,154,92,48,42,146,127,86,165,210,8,0,46,138,121,172,104,
135,30,57,130,155,198,160,91,0,147,60,250,46,223,50,3,13,80,161,143,137,158,15,255,208,168,141,234,49,104,42,67,141,186,166,221,3,44,215,55,148,155,201,96,52,26,129,59,103,162,49,202,116,228,133,167,25,
40,157,88,138,121,206,232,3,51,138,2,249,201,146,48,17,3,54,224,6,50,176,12,140,52,166,51,192,1,201,144,4,184,58,164,73,112,10,184,154,37,118,112,158,65,138,171,118,240,0,98,160,12,59,160,142,109,138,
76,198,24,151,213,49,136,44,233,2,162,56,81,20,20,106,162,186,87,123,10,10,14,102,157,104,16,126,156,42,113,95,170,72,12,48,147,190,177,3,43,176,2,29,160,3,167,96,4,98,208,9,102,153,5,124,160,3,240,170,
3,73,224,49,200,64,158,99,0,7,153,80,9,112,48,172,133,144,0,156,32,11,38,144,0,66,32,120,68,214,30,111,192,8,112,202,126,92,10,98,213,5,173,70,200,148,20,196,77,213,10,42,215,154,173,233,182,173,38,135,
149,11,42,168,132,154,152,27,102,0,168,192,6,200,128,12,81,208,1,73,128,175,166,96,2,89,128,175,81,96,2,153,208,9,73,240,0,73,96,10,16,96,161,240,255,42,6,142,10,175,15,16,7,58,64,153,241,137,30,151,234,
6,54,64,116,3,129,156,174,153,92,39,234,101,199,215,135,102,51,177,3,202,41,146,131,173,15,107,1,85,132,177,31,6,168,211,200,39,8,185,69,180,218,8,3,16,9,139,176,2,101,41,179,29,112,150,228,217,9,153,
144,161,38,107,150,112,176,4,153,224,168,118,208,1,165,96,2,16,144,6,86,208,0,84,34,159,1,224,10,203,18,143,222,71,16,155,234,154,59,135,6,213,105,113,42,202,162,87,10,181,69,34,181,228,228,101,160,240,
153,85,128,181,0,32,42,175,42,3,139,52,2,59,20,161,173,48,0,36,91,9,101,105,4,73,144,6,38,80,8,112,96,4,89,224,182,112,160,158,70,208,1,81,16,5,112,144,5,157,16,5,157,240,0,102,9,1,153,96,10,145,208,1,
179,64,12,4,27,69,62,164,41,204,218,145,144,59,130,132,251,100,134,251,156,228,51,160,43,138,129,49,64,184,141,91,69,55,65,4,54,186,105,33,32,8,40,8,174,134,26,161,13,144,2,113,16,7,179,144,5,234,255,
57,6,16,112,12,243,10,186,148,208,1,140,106,2,58,80,9,89,144,5,149,64,9,38,240,0,89,144,9,58,96,2,195,16,9,58,0,11,188,91,169,183,112,79,33,90,148,194,155,177,196,91,184,20,85,154,139,107,16,50,230,118,
33,240,176,94,85,7,160,160,141,130,43,113,213,187,5,185,196,42,93,244,45,141,121,150,235,73,164,191,154,37,56,43,164,15,64,164,56,219,168,56,251,171,191,201,10,158,96,73,195,17,26,67,9,192,33,40,192,253,
85,188,179,100,113,9,86,160,81,137,62,88,54,116,11,252,188,14,12,193,228,151,181,20,108,44,137,233,48,253,211,10,246,26,169,170,203,155,74,236,171,230,201,155,103,201,10,173,160,194,181,211,194,44,48,
162,116,199,176,5,32,195,40,74,81,234,7,149,4,193,132,11,198,192,7,80,7,40,160,170,88,89,0,64,156,75,187,212,45,24,220,10,102,201,158,103,138,196,114,156,158,80,108,73,182,48,197,66,75,180,114,154,177,
85,80,93,160,64,192,26,128,135,237,182,135,198,150,135,190,83,184,100,236,195,116,255,138,118,162,183,163,53,64,171,55,217,196,27,28,169,147,140,158,113,156,158,238,89,199,207,117,199,12,48,47,121,108,
197,124,204,141,127,188,79,85,4,94,57,188,91,53,124,200,198,155,200,53,122,180,104,204,200,20,76,155,67,76,166,226,209,196,26,124,201,27,124,201,72,236,158,98,16,197,9,66,59,242,130,169,122,188,176,71,
59,202,133,116,103,83,134,62,86,250,93,209,216,26,93,176,202,14,215,202,72,153,198,178,220,69,180,204,10,66,234,196,233,217,155,186,188,203,48,34,120,151,20,180,67,11,202,160,89,0,198,204,148,53,188,184,
235,147,132,67,247,204,232,86,7,117,160,200,175,44,168,21,60,112,224,233,37,34,35,201,183,220,193,221,188,205,231,153,150,6,212,161,120,76,117,228,204,176,64,0,10,49,234,3,93,172,151,108,199,110,71,39,
12,1,217,2,77,80,6,62,188,115,223,101,189,93,233,10,45,212,198,238,105,7,233,105,158,115,108,201,76,156,150,61,137,0,192,114,79,155,232,194,123,60,102,213,85,7,17,125,0,93,0,198,72,71,96,4,255,42,0,27,
32,12,77,128,83,93,214,4,194,96,198,17,188,160,162,114,189,159,224,157,42,18,158,138,186,155,111,28,210,232,121,196,99,64,128,61,73,84,245,25,188,47,124,181,45,93,135,58,21,211,126,152,167,208,40,111,
124,38,8,117,192,195,62,45,185,148,11,171,178,42,166,43,210,54,142,249,152,75,156,196,192,26,190,145,218,203,4,59,159,202,234,183,167,121,149,191,134,2,46,61,195,10,61,157,25,228,123,104,195,2,95,61,195,
100,156,159,145,59,118,89,235,8,142,204,198,69,92,40,30,77,164,217,108,166,72,92,40,108,202,201,158,28,82,192,103,215,64,128,215,60,108,121,131,172,16,93,44,57,56,61,195,155,64,209,84,125,163,176,92,193,
30,251,45,98,169,155,150,140,161,141,141,166,78,252,196,95,194,191,215,183,137,227,12,184,62,76,4,101,144,211,80,134,213,56,172,213,82,230,91,54,179,153,188,221,101,121,64,218,26,123,209,40,104,185,222,
249,42,17,218,8,105,221,196,74,157,196,0,45,59,243,249,187,186,96,156,4,97,180,18,152,215,197,255,39,12,124,189,31,96,204,2,155,240,108,109,80,6,101,32,189,63,141,163,219,137,144,187,4,40,109,92,203,146,
188,214,110,237,214,69,250,196,41,76,79,148,189,164,82,189,210,113,166,217,239,44,8,14,173,135,12,209,118,2,96,3,123,160,4,181,164,4,163,189,170,35,88,29,177,153,209,152,123,214,171,93,158,26,44,210,74,
124,225,104,250,158,200,234,187,40,237,6,4,13,184,159,249,223,129,125,69,60,221,204,201,182,110,56,252,215,155,128,7,180,116,220,14,110,216,236,253,170,91,155,218,154,27,221,187,233,207,234,58,164,59,
89,210,180,243,161,203,122,159,250,150,219,101,144,7,75,213,4,2,142,195,166,105,87,198,179,1,214,52,220,9,94,75,231,77,151,229,23,225,224,250,157,241,173,168,35,45,199,25,222,227,200,74,66,6,107,219,1,
67,206,22,214,221,74,183,9,130,144,74,82,69,200,1,213,135,214,130,4,54,240,4,122,176,84,13,62,189,211,8,10,52,254,6,104,38,174,139,125,212,174,157,212,234,249,196,146,221,225,192,210,201,65,30,167,36,
255,55,226,191,86,228,58,13,2,72,206,2,74,110,211,41,142,192,79,9,229,71,224,76,180,112,222,14,174,160,56,26,2,134,25,147,54,62,3,171,93,40,211,221,158,153,140,194,234,104,30,199,244,142,182,205,153,213,
65,162,22,134,2,101,208,6,116,206,2,242,230,197,119,229,91,36,240,7,113,62,231,181,180,0,115,144,157,204,103,130,136,13,174,98,58,79,32,235,9,145,236,155,35,253,152,80,108,86,29,90,66,44,204,164,117,173,
232,186,93,222,180,164,4,123,176,28,116,5,220,158,237,228,25,135,224,151,238,76,154,94,206,85,126,144,180,185,63,0,4,49,168,160,236,57,249,231,188,252,158,190,28,237,74,234,183,42,29,133,173,220,199,179,
94,235,183,142,54,122,204,91,76,235,28,127,240,7,114,238,226,22,128,7,192,46,236,204,55,139,50,144,238,162,115,214,229,168,147,190,169,150,6,196,150,193,225,50,134,30,162,155,137,232,173,121,237,6,111,
1,218,206,237,51,54,233,78,181,129,136,241,7,39,112,2,192,128,233,122,176,0,116,80,206,132,249,23,86,255,190,12,60,42,166,42,242,45,93,178,61,58,73,241,6,130,10,169,30,140,37,196,70,111,208,134,198,249,
234,43,25,1,115,176,239,87,116,4,123,176,7,8,101,71,108,62,94,14,109,51,39,112,9,43,79,11,8,63,7,63,240,3,133,77,130,37,248,233,52,111,47,138,41,61,185,40,35,230,120,246,104,95,145,207,37,159,232,113,
131,243,66,244,201,136,219,175,72,7,69,110,240,120,160,7,79,96,3,3,207,129,76,94,242,169,52,240,163,112,245,180,208,242,116,192,245,235,221,233,84,199,149,13,143,11,45,216,136,163,147,139,68,67,142,50,
82,63,148,191,246,56,128,145,160,241,246,68,121,68,127,138,244,11,208,6,152,126,4,121,31,233,163,42,17,73,132,80,127,176,5,129,31,4,65,128,7,96,64,8,116,176,141,229,134,248,134,217,240,224,200,136,60,
80,50,12,242,48,188,223,251,15,83,56,105,132,134,249,194,134,155,127,154,92,122,97,116,240,249,6,127,4,151,112,2,45,53,111,67,71,242,12,129,87,206,17,6,181,176,250,173,15,6,90,207,245,191,255,214,169,
223,85,189,214,155,130,203,144,136,46,168,50,23,80,50,184,24,55,11,82,35,151,207,60,194,255,8,9,8,123,133,55,143,58,150,141,245,88,247,46,30,4,205,127,2,127,96,96,31,103,17,0,1,106,3,20,36,128,72,144,
0,20,6,19,162,68,13,245,44,152,243,227,71,149,8,64,10,184,192,152,17,20,40,22,91,220,168,146,241,230,19,174,93,174,106,140,8,176,106,213,5,150,45,47,240,224,177,42,192,173,26,12,30,245,122,35,135,145,
155,45,91,88,108,4,229,0,192,80,140,64,128,68,64,26,97,206,130,35,180,156,2,27,181,229,207,65,18,21,4,80,136,33,116,232,86,174,93,189,118,117,32,144,32,213,132,11,27,38,2,67,136,142,68,138,22,51,106,228,
216,209,141,46,57,34,111,144,52,89,227,214,8,190,125,111,209,116,245,8,215,167,156,140,84,241,100,241,115,35,87,140,5,136,36,85,186,64,143,83,90,80,165,78,69,120,53,70,214,175,157,61,111,117,16,131,130,
128,10,100,21,50,108,152,86,162,68,34,110,223,186,0,218,209,35,255,200,186,159,110,220,120,180,75,55,3,6,186,119,225,26,188,172,240,225,158,137,55,106,37,234,194,49,145,42,205,233,72,198,243,116,212,137,
63,6,51,67,217,16,244,243,246,206,33,68,147,38,91,139,137,154,179,170,87,183,46,80,164,8,215,16,222,99,200,254,200,72,78,221,55,34,63,221,255,180,76,248,124,70,59,121,250,84,76,187,173,26,35,130,57,231,
8,209,35,186,202,70,169,37,12,235,72,64,2,59,1,185,163,144,189,239,74,59,8,16,5,198,35,15,45,66,86,251,161,162,2,46,234,170,189,205,100,155,77,21,93,100,96,113,62,57,88,212,69,23,55,254,3,16,40,228,146,
51,10,50,58,8,1,3,143,32,130,80,131,65,7,169,138,48,59,80,42,68,146,171,141,160,16,224,65,24,54,84,163,67,243,36,170,8,8,245,214,99,175,61,65,18,235,169,167,25,191,4,179,203,196,2,116,224,70,0,212,203,
49,169,29,123,108,72,13,38,26,124,176,72,206,146,164,51,172,129,154,164,234,23,40,163,84,35,173,15,169,68,239,34,23,74,4,42,174,196,255,108,64,52,209,49,141,179,209,171,198,210,140,224,135,51,120,4,166,
205,55,171,35,18,10,172,218,163,179,83,59,153,124,80,79,38,2,225,51,3,72,206,0,177,192,17,49,242,170,189,16,10,221,44,214,66,93,229,180,171,198,150,131,236,12,72,192,56,203,205,90,96,136,83,211,24,106,
237,180,78,177,192,59,232,23,24,60,8,132,84,44,76,69,117,181,8,90,179,242,74,207,104,165,181,76,51,7,84,174,0,72,145,34,132,144,12,176,32,23,11,38,20,128,129,42,8,133,37,182,88,99,65,25,173,2,12,149,101,
182,89,114,33,129,132,6,26,164,165,118,213,65,221,77,174,219,111,37,61,3,12,48,202,13,228,220,95,200,146,179,93,128,147,12,11,94,1,10,202,211,3,102,7,193,120,16,75,44,161,161,15,143,145,234,215,223,127,
43,204,104,68,111,143,74,74,34,93,199,45,151,9,15,96,88,56,67,1,176,27,54,132,135,31,6,69,52,130,66,125,161,222,140,85,176,228,140,142,63,158,54,208,244,212,123,237,181,43,77,54,106,96,130,51,96,25,139,
102,255,209,141,185,170,153,141,220,246,102,58,189,187,19,67,18,126,249,197,226,102,155,29,98,8,142,245,37,122,218,166,77,102,187,237,17,155,254,214,99,125,55,206,32,227,102,95,174,26,194,171,140,212,
186,239,79,119,182,238,151,23,94,240,98,236,64,84,64,92,95,180,251,128,140,90,184,31,7,162,192,199,146,242,184,143,185,55,198,120,108,139,193,166,74,94,97,231,236,91,235,136,41,96,210,107,46,124,241,197,
139,43,86,191,162,108,196,201,80,188,242,180,33,163,157,114,185,47,183,164,108,195,189,240,194,151,188,145,184,186,230,208,135,7,128,107,40,0,63,232,244,212,85,103,189,117,21,200,128,94,241,161,101,167,
254,118,233,45,65,188,236,33,88,231,29,117,46,184,56,200,170,207,203,36,158,248,209,153,44,200,58,229,121,103,158,117,69,222,135,62,126,233,231,143,63,126,196,85,152,100,146,230,189,24,252,251,239,1,1,
132,0,246,182,153,172,149,79,107,238,33,221,196,0,152,60,212,45,143,119,172,91,67,4,223,55,65,10,86,112,130,250,107,222,21,120,215,63,255,255,1,16,120,52,203,74,1,13,40,186,141,108,32,129,233,75,158,242,
204,192,62,39,180,208,133,78,136,96,12,101,152,193,23,110,240,5,84,192,33,21,16,18,192,153,97,69,120,35,4,226,80,194,18,3,19,50,137,52,0,244,31,23,112,104,6,38,178,240,133,135,128,226,11,157,192,62,222,
49,209,12,84,72,162,7,35,164,169,13,16,48,136,95,4,77,9,7,98,196,10,32,241,123,57,92,162,21,213,184,70,53,230,48,139,0,20,224,241,54,128,53,48,214,17,52,161,33,34,233,140,248,135,234,0,34,137,104,4,100,
32,147,200,5,0,2,2,9,31,228,226,102,28,102,199,58,150,41,103,121,76,160,0,249,216,71,51,14,242,141,133,60,100,28,185,216,197,16,50,210,147,94,41,83,172,230,168,71,35,10,80,0,147,68,229,36,77,57,179,227,
105,138,2,115,36,160,8,63,249,73,71,230,108,142,38,164,0,41,91,185,203,86,230,242,149,183,140,21,249,102,57,204,237,104,107,136,162,188,101,50,147,25,43,69,106,139,152,207,132,152,182,176,53,77,99,66,
4,147,66,1,1,0,59,0,0};

const char* RangLoopComponent::ftttmlogorings_gif = (const char*) resource_RangLoopComponent_ftttmlogorings_gif;
const int RangLoopComponent::ftttmlogorings_gifSize = 7463;
