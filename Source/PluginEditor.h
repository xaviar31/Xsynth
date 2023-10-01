/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "../UI/adsrComponent.h"
#include "../UI/oscComponent.h"

//==============================================================================
/**
*/
class XsynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    XsynthAudioProcessorEditor (XsynthAudioProcessor&);
    ~XsynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    XsynthAudioProcessor& audioProcessor;
    adsrComponent adsr;
    oscComponent osc;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XsynthAudioProcessorEditor)
};
