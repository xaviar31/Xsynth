/*
  ==============================================================================

    oscComponent.cpp
    Created: 30 Sep 2023 8:15:11pm
    Author:  Xavi

  ==============================================================================
*/

#include <JuceHeader.h>
#include "oscComponent.h"

//==============================================================================
oscComponent::oscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectionID)
{
    juce::StringArray choices{ "Sine", "Saw", "Square" };
    oscWaveSelection.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelection);

    oscWaveSelectionAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectionID, oscWaveSelection);
}

oscComponent::~oscComponent()
{
}

void oscComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void oscComponent::resized()
{
    oscWaveSelection.setBounds(0, 0, 90, 20);
}
