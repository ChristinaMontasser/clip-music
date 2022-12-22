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
    string name;
    FollowAction actions[ACTIONS];
public:
    int ticks;
    Clip();
    Clip(string name, int ticks, FollowAction* actions);
    Clip(const Clip& clip);
    string getName();
    FollowAction* getFollowAction();
    void start();
    action prioritizeAction(pair<float, float> likelihood);
    bool operator==(const Clip& clip);
};
