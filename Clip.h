#include<iostream>
#include <bits/stdc++.h>
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
    void start(int amount);
    action prioritizeAction(pair<float, float> likelihood);
};
