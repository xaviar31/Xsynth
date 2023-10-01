/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
XsynthAudioProcessorEditor::XsynthAudioProcessorEditor (XsynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.apvts, "OSC1WAVETYPE", "FMFREQ", "FMDEPTH"), adsr(audioProcessor.apvts)
{
    setSize (400, 400);
    addAndMakeVisible(adsr);
    addAndMakeVisible(osc);
}

XsynthAudioProcessorEditor::~XsynthAudioProcessorEditor()
{
}

//==============================================================================
void XsynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void XsynthAudioProcessorEditor::resized()
{
    //set bounds
    adsr.setBounds(getLocalBounds());
    osc.setBounds(10, 10, 90, 250);
}

