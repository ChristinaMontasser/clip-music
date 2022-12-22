#include "Clip.h"

//Constructors
Clip::Clip(){};
Clip::Clip(string mName, int ticks, FollowAction* mActions)
{
    this->mName = mName;
    this->ticks = ticks;
    for(int i=0; i<ACTIONS; i++)
    {
        this->mActions[i].actionName= mActions[i].actionName;
        this->mActions[i].chance = mActions[i].chance;
    }
};
Clip::Clip(const Clip& r_clip)
{
    this->mName = r_clip.mName;
    this->ticks = r_clip.ticks;
    for(int i=0; i<ACTIONS; i++)
    {
        this->mActions[i].actionName= r_clip.mActions[i].actionName;
        this->mActions[i].chance = r_clip.mActions[i].chance;
    }
};

string Clip::getName(){
    return this->mName;
};

FollowAction* Clip::getFollowAction(){
    return mActions;
};

void Clip::start() //COMMENT
{
    for(int i=0; i<this->ticks; i++)
    {
        cout<< this->mName << endl;
    }
}

Action Clip::prioritizeAction(pair<float, float> likelihood){
    //Edge cases
    if(this->mActions[0].chance == 0)
        return this->mActions[1].actionName;
    if(this->mActions[1].chance == 0)
        return this->mActions[0].actionName;
    if(likelihood.first>likelihood.second)
        return this->mActions[0].actionName;
    else
        return this->mActions[1].actionName;
}

bool Clip::operator==(const Clip& clip){
    return ticks==clip.ticks && mName==clip.mName && mActions[0].actionName==clip.mActions[0].actionName &&
        mActions[1].actionName==clip.mActions[1].actionName;
}
