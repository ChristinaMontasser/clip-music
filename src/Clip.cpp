#include "Clip.h"

//Constructors
Clip::Clip(){};
Clip::Clip(string name, int ticks, FollowAction* actions)
{
    this->name = name;
    this->ticks = ticks;
    for(int i=0; i<ACTIONS; i++)
    {
        this->actions[i].actionName= actions[i].actionName;
        this->actions[i].chance = actions[i].chance;
    }
};
Clip::Clip(const Clip& clip)
{
    this->name = clip.name;
    this->ticks = clip.ticks;
    for(int i=0; i<ACTIONS; i++)
    {
        this->actions[i].actionName= clip.actions[i].actionName;
        this->actions[i].chance = clip.actions[i].chance;
    }
};

string Clip::getName(){
    return this->name;
};

FollowAction* Clip::getFollowAction(){
    return actions;
};

void Clip::start() //COMMENT
{
    for(int i=0; i<this->ticks; i++)
    {
        cout<< this->name << endl;
    }
}

action Clip::prioritizeAction(pair<float, float> likelihood){
    //Edge cases
    if(this->actions[0].chance == 0)
        return this->actions[1].actionName;
    if(this->actions[1].chance == 0)
        return this->actions[0].actionName;
    if(likelihood.first>likelihood.second)
        return this->actions[0].actionName;
    else
        return this->actions[1].actionName;
}

bool Clip::operator==(const Clip& clip){
    return ticks==clip.ticks && name==clip.name && actions[0].actionName==clip.actions[0].actionName &&
        actions[1].actionName==clip.actions[1].actionName;
}
