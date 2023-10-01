/*
  ==============================================================================

    OscData.cpp
    Created: 30 Sep 2023 7:47:37pm
    Author:  Xavi

  ==============================================================================
*/

#include "OscData.h"

// switch between sine, saw, or square wave
void OscData::setWaveType(const int waveChoice)
{
    switch (waveChoice)
    {
    case 0:
        //sine wave
        initialise([](float x) { return std::sin(x); });
        break;
    case 1:
        //saw wave
        initialise([](float x) {return x / juce::MathConstants<float>::pi; });
        break;
    case 2:
        //sqare wave
        initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f; });
        break;
    default:
        jassertfalse; // pause execution (not supposed to be here)
        break;
    }
}

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    prepare(spec);
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::setWaveFreq(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}