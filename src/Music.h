#include "Clip.h"
#pragma once

class Music
{
private:
    Clip *pClips;
    int mNumOfClips;
    int mTicks;
    int mEndedWith;
    vector<pair<float, float>> mPairsPerTicks;
public:
    Music();
    Music(Clip* pClips, int mNumOfClips, int mTicks);
    Music(const Music& rMusic);
    bool checkPlayAdvanceStep();
    bool start( vector<pair<float, float>> mPairsPerTicks);
};

