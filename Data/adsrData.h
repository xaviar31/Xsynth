/*
  ==============================================================================

    adsrData.h
    Created: 29 Sep 2023 2:22:43pm
    Author:  Xavi

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class adsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
private:
    juce::ADSR::Parameters adsrParams;
};
