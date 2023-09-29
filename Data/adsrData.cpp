/*
  ==============================================================================

    adsrData.cpp
    Created: 29 Sep 2023 2:22:43pm
    Author:  Xavi

  ==============================================================================
*/

#include "adsrData.h"

void adsrData::updateADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;

    setParameters(adsrParams);
}
