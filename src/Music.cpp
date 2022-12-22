#include "Music.h"
#include "helper_functions.h"


Music::Music(){};

Music::Music(Clip* clips, int numOfClips, int ticks)
{
    this->clips = clips;
    this->numOfClips = numOfClips;
    this->endedWith =0;
    this->ticks = ticks;
};
 Music::Music(const Music& music){
    this->clips = music.clips;
    this->numOfClips = music.numOfClips;
    this->ticks = music.ticks;
    this->pairsPerTicks = music.pairsPerTicks;
    this->endedWith =music.endedWith;
 }

bool Music::checkPlayAdvanceStep()
{
    int clipsTicksCount = 0;
    for(int i =0; i<this->numOfClips; i++)
    {
        clipsTicksCount += this->clips[i].ticks;
    }
    if(((double)this->ticks/(double)clipsTicksCount) == (this->ticks/clipsTicksCount))
        return true;
    return false;
}
bool Music::start( vector<pair<float, float>> pairsPerTicks)
{
    if(this->checkPlayAdvanceStep()){   
        this->pairsPerTicks = pairsPerTicks;
        int countTicks = 0;
        action actionPriority;
        while(countTicks<ticks)
        {
            actionPriority = this->clips[endedWith].prioritizeAction(this->pairsPerTicks.at(countTicks));
            this->clips[endedWith].start();
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
        return true;

    }
    else{
        cout << "The playback should ADVANCE the number of steps given.";
        return false;
    }

};


