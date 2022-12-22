#include "Clip.h"
#pragma once

class Music
{
private:
    Clip* clips;
    int numOfClips;
    int ticks;
    int endedWith;
    vector<pair<float, float>> pairsPerTicks;
public:
    Music();
    Music(Clip* clips, int numOfClips, int ticks);
    Music(const Music& music);
    bool checkPlayAdvanceStep();
    bool start( vector<pair<float, float>> pairsPerTicks);
};

