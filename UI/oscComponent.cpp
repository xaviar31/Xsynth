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
oscComponent::oscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectionID, juce::String fmFreqID, juce::String fmDepthID)
{
    juce::StringArray choices{ "Sine", "Saw", "Square" };
    oscWaveSelection.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelection);

    oscWaveSelectionAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectionID, oscWaveSelection);

    fmFreqSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    fmFreqSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(fmFreqSlider);

    fmFreqAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, fmFreqID, fmFreqSlider);

    fmFreqLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    fmFreqLabel.setFont(15.0f);
    fmFreqLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(fmFreqLabel);
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
    fmFreqSlider.setBounds(0, 40, 90, 90);
    fmFreqLabel.setBounds(fmFreqSlider.getX(), fmFreqSlider.getY() - 20, fmFreqSlider.getWidth(), 20);
}
