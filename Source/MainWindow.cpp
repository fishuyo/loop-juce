/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic outline for a simple desktop window.

  ==============================================================================
*/

#include "MainWindow.h"
#include "RangLoopComponent.h"


//==============================================================================
MainAppWindow::MainAppWindow()
    : DocumentWindow (JUCEApplication::getInstance()->getApplicationName(),
                      Colours::lightgrey,
                      DocumentWindow::allButtons)
{
	RangLoopComponent* const contentComponent = new RangLoopComponent();
	
	setContentOwned (contentComponent, true);
	
	centreWithSize (getWidth(), getHeight());
	
	setVisible (true);
    //centreWithSize (500, 400);
    //setVisible (true);
}

MainAppWindow::~MainAppWindow()
{
}

void MainAppWindow::closeButtonPressed()
{
    JUCEApplication::getInstance()->systemRequestedQuit();
}
