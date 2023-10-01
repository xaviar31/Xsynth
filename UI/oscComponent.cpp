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

    setSliderWithLabel(fmFreqSlider, fmFreqLabel, apvts, fmFreqID, fmFreqAttachment);
    setSliderWithLabel(fmDepthSlider, fmDepthLabel, apvts, fmDepthID, fmDepthAttachment);
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
    fmFreqLabel.setBounds(fmFreqSlider.getX(), fmFreqSlider.getY() - 10, fmFreqSlider.getWidth(), 20);

    fmDepthSlider.setBounds(fmFreqSlider.getX(), 150, 90, 90);
    fmDepthLabel.setBounds(fmDepthSlider.getX(), fmDepthSlider.getY() - 10, fmDepthSlider.getWidth(), 20);
}

void oscComponent::setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramID,
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);

    fmFreqAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramID, slider);

    fmFreqLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    fmFreqLabel.setFont(15.0f);
    fmFreqLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(fmFreqLabel);

    fmDepthLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    fmDepthLabel.setFont(15.0f);
    fmDepthLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(fmDepthLabel);
}
