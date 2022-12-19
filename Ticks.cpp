#include "Ticks.h"
#include "helper_functions.h"


Ticks::Ticks(){};

Ticks::Ticks(Clip* clips, int numOfClips, int ticks, vector<pair<float, float>> pairsPerTicks)
{
    this->clips = clips;
    this->numOfClips = numOfClips;
    this->ticks = ticks;
    this->pairsPerTicks = pairsPerTicks;
};

void Ticks::start()
{
    int i=0;
    int countTicks = clips[i].ticks;
    action actionPriority = this->clips[i].prioritizeAction(pairsPerTicks.at(0));
    this->clips[i].start();
    while(countTicks<ticks)
    {
        switch(actionPriority)
        {
            case action::none:
                i=i;
                break;
            case action::any:
                i =randomInt(0,numOfClips, -1);
                break;
            case action::other:
                i= randomInt(0,numOfClips, i);
                break;
            case action::next:
                i++;
                if(i>=numOfClips)
                    i = 0;
                break;
            case action::previous:
                i--;
                if(i<0)
                    i = numOfClips-1;
                break;
            default:
                cout << "AN ERROR OCCURED";
                break;
        }
        countTicks+=clips[i].ticks;
        actionPriority = this->clips[i].prioritizeAction(pairsPerTicks.at(countTicks-clips[i].ticks));
        this->clips[i].start();
    }

};


