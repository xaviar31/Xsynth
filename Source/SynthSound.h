/*
  ==============================================================================

    SynthSound.h
    Created: 28 Sep 2023 3:45:49pm
    Author:  Xavi

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override
    {
        return true;
    }
    bool appliesToChannel(int midiChannel) override
    {
        return true;
    }
};