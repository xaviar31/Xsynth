/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
XsynthAudioProcessorEditor::XsynthAudioProcessorEditor (XsynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), adsr(audioProcessor.apvts)
{
    setSize (400, 400);

    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "OSC", oscSelector);

    // makde adsr visible
    addAndMakeVisible(adsr);
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
    //set adsr bounds
    adsr.setBounds(getLocalBounds());
}

