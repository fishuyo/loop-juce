/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  12 Mar 2012 11:56:22am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_LOOPCOMPONENT_LOOPCOMPONENT_C8D31A38__
#define __JUCER_HEADER_LOOPCOMPONENT_LOOPCOMPONENT_C8D31A38__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "LoopBuffer.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class LoopComponent  : public Component,
                        public AudioIODeviceCallback
{
public:
    //==============================================================================
    LoopComponent ();
    ~LoopComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    LoopComponent(char* c);
    void audioDeviceIOCallback (const float** inputChannelData,
                                int totalNumInputChannels,
                                float** outputChannelData,
                                int totalNumOutputChannels,
                                int numSamples);
    void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
  
    Loop loop;
    char* ident;
    bool selected;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void filesDropped (const StringArray& filenames, int mouseX, int mouseY);
    void mouseDown (const MouseEvent& e);
    void mouseDrag (const MouseEvent& e);
    void mouseWheelMove (const MouseEvent& e, float wheelIncrementX, float wheelIncrementY);
    void focusGained (FocusChangeType cause);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
  
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    LoopComponent (const LoopComponent&);
    const LoopComponent& operator= (const LoopComponent&);
};


#endif   // __JUCER_HEADER_LOOPCOMPONENT_LOOPCOMPONENT_C8D31A38__
