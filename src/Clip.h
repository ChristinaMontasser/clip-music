#include<iostream>
#include <vector>
#include <assert.h>
#include <string>
#include "Macros.h"
#include "Types.h"
using namespace std;

#pragma once
class Clip
{
private:
    string mName;
    FollowAction mActions[ACTIONS];
public:
    unsigned int ticks;
    Clip();
    Clip(string mName, unsigned int ticks, FollowAction* mActions);
    Clip(const Clip& r_r_clip);
    string getName();
    FollowAction* getFollowAction();
    void start();
    Action prioritizeAction(pair<float, float> likelihood);
    bool operator==(const Clip& clip);
};
