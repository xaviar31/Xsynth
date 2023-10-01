/*
  ==============================================================================

    adsrComponent.cpp
    Created: 29 Sep 2023 2:19:04pm
    Author:  Xavi

  ==============================================================================
*/

#include <JuceHeader.h>
#include "adsrComponent.h"

//==============================================================================
adsrComponent::adsrComponent(juce::AudioProcessorValueTreeState& apvts)
{
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    attackAttachment = std::make_unique<SliderAttachment>(apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<SliderAttachment>(apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<SliderAttachment>(apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<SliderAttachment>(apvts, "RELEASE", releaseSlider);

    setSliderParams(attackSlider);
    setSliderParams(decaySlider);
    setSliderParams(sustainSlider);
    setSliderParams(releaseSlider);

}

adsrComponent::~adsrComponent()
{
}

void adsrComponent::paint (juce::Graphics& g)
{
    juce::Image image(juce::Image::ARGB, getWidth(), getHeight(), true);
    juce::Graphics tg(image);

    juce::Colour blue(87, 202, 255);
    juce::ColourGradient cg = juce::ColourGradient::horizontal(blue.darker(1.0), 0.0, blue.darker(20.0), getWidth());
    tg.setGradientFill(cg);
    tg.fillAll();

    g.drawImage(image, getLocalBounds().toFloat());
}

void adsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(0);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight();
    const auto sliderX = 0;
    const auto sliderY = 0;

    attackSlider.setBounds(sliderX, sliderY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderY, sliderWidth, sliderHeight);
}

void adsrComponent::setSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::seagreen);
    slider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);
    slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 50, 25);
    addAndMakeVisible(slider);
}
