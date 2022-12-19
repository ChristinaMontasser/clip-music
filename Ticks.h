#include "Clip.h"
#pragma once

class Ticks
{
private:
    Clip* clips;
    int numOfClips;
    int ticks;
    vector<pair<float, float>> pairsPerTicks;
public:
    Ticks();
    Ticks(Clip* clips, int numOfClips, int ticks, vector<pair<float, float>> pairsPerTicks);
    void start();
};

