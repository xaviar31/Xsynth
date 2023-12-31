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

    setLabelParams(attackLabel);
    setLabelParams(decayLabel);
    setLabelParams(sustainLabel);
    setLabelParams(releaseLabel);

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
    const auto bounds = getLocalBounds();
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() / 4 - padding;
    const auto sliderX = 0;
    const auto sliderY = 300;

    attackSlider.setBounds(sliderX, sliderY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderY, sliderWidth, sliderHeight);

    attackLabel.setBounds(attackSlider.getX(), attackSlider.getY() - 10, attackSlider.getWidth(), 20);
    decayLabel.setBounds(decaySlider.getX(), decaySlider.getY() - 10, decaySlider.getWidth(), 20);
    sustainLabel.setBounds(sustainSlider.getX(), sustainSlider.getY() - 10, sustainSlider.getWidth(), 20);
    releaseLabel.setBounds(releaseSlider.getX(), releaseSlider.getY() - 10, releaseSlider.getWidth(), 20);
}

void adsrComponent::setSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::seagreen);
    slider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);
    slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 50, 25);
    addAndMakeVisible(slider);
}

void adsrComponent::setLabelParams(juce::Label& label)
{
    attackLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    attackLabel.setFont(15.0f);
    attackLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(attackLabel);

    decayLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    decayLabel.setFont(15.0f);
    decayLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(decayLabel);

    sustainLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    sustainLabel.setFont(15.0f);
    sustainLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(sustainLabel);

    releaseLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    releaseLabel.setFont(15.0f);
    releaseLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(releaseLabel);
}