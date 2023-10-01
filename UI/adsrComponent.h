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
    adsrComponent(juce::AudioProcessorValueTreeState& apvts);
    ~adsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void setSliderParams(juce::Slider& slider);

    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;

    void setLabelParams(juce::Label& label);

    juce::Label attackLabel{ "Attack", "Attack" };
    juce::Label decayLabel{ "Decay", "Decay" };
    juce::Label sustainLabel{ "Sustain", "Sustain" };
    juce::Label releaseLabel{ "Release", "Release" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (adsrComponent)
};
