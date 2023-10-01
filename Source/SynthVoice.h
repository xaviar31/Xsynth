/*
  ==============================================================================

    SynthVoice.h
    Created: 28 Sep 2023 3:45:28pm
    Author:  Xavi

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "../Data/adsrData.h"
#include "../Data/OscData.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

    void SynthVoice::update(const float attack, const float decay, const float sustain, const float release);
    OscData& getOscillator() { return osc; }
private:
    adsrData adsr;
    juce::AudioBuffer<float> synthBuffer;

    OscData osc;
    //juce::dsp::Oscillator<float> osc{ [](float x) { return x / juce::MathConstants<float>::pi; } };
    juce::dsp::Gain<float> gain;
    bool isPrepared{ false };
};