#include "Music.h"
#include "helper_functions.h"


Music::Music(){};

Music::Music(Clip* clips, int numOfClips)
{
    this->clips = clips;
    this->numOfClips = numOfClips;
    this->endedWith =0;
};
 Music::Music(const Music& music){
    this->clips = music.clips;
    this->numOfClips = music.numOfClips;
    this->ticks = music.ticks;
    this->pairsPerTicks = music.pairsPerTicks;
    this->endedWith =music.endedWith;
 }

void Music::start(int ticks, vector<pair<float, float>> pairsPerTicks)
{
    this->ticks = ticks;
    this->pairsPerTicks = pairsPerTicks;
    int countTicks = 0;
    action actionPriority;
    while(countTicks<ticks)
    {
        actionPriority = this->clips[endedWith].prioritizeAction(this->pairsPerTicks.at(countTicks));
        this->clips[endedWith].start(ticks-countTicks);
        countTicks+=clips[endedWith].ticks;
        switch(actionPriority)
        {
            case action::none:
                endedWith=endedWith;
                break;
            case action::any:
                endedWith =randomInt(0,numOfClips, -1);
                break;
            case action::other:
                endedWith= randomInt(0,numOfClips, endedWith);
                break;
            case action::next:
                endedWith++;
                if(endedWith>=numOfClips)
                    endedWith = 0;
                break;
            case action::previous:
                endedWith--;
                if(endedWith<0)
                    endedWith = numOfClips-1;
                break;
            default:
                cout << "AN ERROR OCCURED";
                break;
        }

    }


};


