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
    Music(Clip* clips, int numOfClips);
    void start(int ticks, vector<pair<float, float>> pairsPerTicks);
    Music(const Music& music);

};

