/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  12 Mar 2012 1:10:26pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_RANGLOOPCOMPONENT_RANGLOOPCOMPONENTTEMP_95560D42__
#define __JUCER_HEADER_RANGLOOPCOMPONENT_RANGLOOPCOMPONENTTEMP_95560D42__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
//[/Headers]

#include "LoopComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RangLoopComponent  : public Component,
                           public ButtonListener,
                           public SliderListener
{
public:
    //==============================================================================
    RangLoopComponent ();
    ~RangLoopComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void mouseWheelMove (const MouseEvent& e, float wheelIncrementX, float wheelIncrementY);
    bool keyPressed (const KeyPress& key);

    // Binary resources:
    static const char* ftttmlogorings_gif;
    static const int ftttmlogorings_gifSize;


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent2;
    GroupComponent* groupComponent3;
    TextButton* recordButton;
    TextButton* switchButton;
    TextButton* reverseButton;
    TextButton* stackButton;
    Slider* slider;
    Label* durationLabel;
    Label* playtimeLabel;
    Slider* volumeKnob;
    Label* label3;
    Slider* decayKnob;
    Label* label2;
    Slider* speedKnob;
    Label* label4;
    TextButton* deviceButton;
    LoopComponent* loopComp1;
    LiveAudioDisplayComp* audioInDispComp;
    LiveAudioDisplayComp* audioOutDispComp;
    LoopComponent* loopComp2;
    LoopComponent* loopComp3;
    LoopComponent* loopComp4;
    LoopComponent* loopComp5;
    LoopComponent* loopComp6;
    LoopComponent* loopComp7;
    LoopComponent* loopComp8;
    LoopComponent* loopComp9;
    LoopComponent* loopComp10;
    LoopComponent* loopComp11;
    LoopComponent* loopComp12;
    LoopComponent* loopComp13;
    LoopComponent* loopComp14;
    LoopComponent* loopComp15;
    LoopComponent* loopComp16;
    GroupComponent* groupComponent;
    Slider* masterKnob;
    Label* label5;
    Image cachedImage_ftttmlogorings_gif;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    RangLoopComponent (const RangLoopComponent&);
    const RangLoopComponent& operator= (const RangLoopComponent&);
};


#endif   // __JUCER_HEADER_RANGLOOPCOMPONENT_RANGLOOPCOMPONENTTEMP_95560D42__
