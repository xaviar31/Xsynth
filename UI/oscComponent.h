/*
  ==============================================================================

    oscComponent.h
    Created: 30 Sep 2023 8:15:11pm
    Author:  Xavi

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class oscComponent  : public juce::Component
{
public:
    oscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectionID, juce::String fmFreqID, juce::String fmDepthID);
    ~oscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscWaveSelection;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveSelectionAttachment;

    juce::Slider fmFreqSlider;
    juce::Slider fmDepthSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> fmFreqAttachment;

    juce::Label fmFreqLabel { "FM Freq", "FM Freq" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(oscComponent)
};
