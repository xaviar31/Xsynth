/*
  ==============================================================================

    adsrComponent.h
    Created: 29 Sep 2023 2:19:04pm
    Author:  Xavi

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class adsrComponent  : public juce::Component
{
public:
    adsrComponent();
    ~adsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (adsrComponent)
};
