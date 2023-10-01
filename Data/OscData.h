/*
  ==============================================================================

    OscData.h
    Created: 30 Sep 2023 7:47:37pm
    Author:  Xavi

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void setWaveType(const int waveChoice);
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void setWaveFreq(const int midiNoteNumber);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);
private:

};
