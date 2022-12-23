#include "Music.h"
#include "helper_functions.h"


Music::Music(){};

Music::Music(Clip* pClips, int mNumOfClips, int mTicks)
{
    assert(mTicks>=0 && "Ticks must be greater than 0");
    this->pClips = pClips;
    this->mNumOfClips = mNumOfClips;
    this->mEndedWith =0;
    this->mTicks = mTicks;
};
 Music::Music(const Music& rMusic){
    this->pClips = rMusic.pClips;
    this->mNumOfClips = rMusic.mNumOfClips;
    this->mTicks = rMusic.mTicks;
    this->mPairsPerTicks = rMusic.mPairsPerTicks;
    this->mEndedWith =rMusic.mEndedWith;
 }

bool Music::checkPlayAdvanceStep()
{
    int clipsTicksCount = 0;
    for(int i =0; i<this->mNumOfClips; i++)
    {
        clipsTicksCount += this->pClips[i].ticks;
    }
    if(((double)this->mTicks/(double)clipsTicksCount) == (this->mTicks/clipsTicksCount))
        return true;
    return false;
}

bool Music::start( vector<pair<float, float>> mPairsPerTicks)
{
    if(this->checkPlayAdvanceStep()){
        this->mPairsPerTicks = mPairsPerTicks;
        int countTicks = 0;
        Action actionPriority;
        while(countTicks<mTicks)
        {
            actionPriority = this->pClips[mEndedWith].prioritizeAction(this->mPairsPerTicks.at(countTicks));
            this->pClips[mEndedWith].start();
            countTicks+=pClips[mEndedWith].ticks;
            switch(actionPriority)
            {
                case Action::none:
                    mEndedWith=mEndedWith;
                    break;
                case Action::any:
                    mEndedWith =randomInt(0,mNumOfClips, -1);
                    break;
                case Action::other:
                    mEndedWith= randomInt(0,mNumOfClips, mEndedWith);
                    break;
                case Action::next:
                    mEndedWith++;
                    if(mEndedWith>=mNumOfClips)
                        mEndedWith = 0;
                    break;
                case Action::previous:
                    mEndedWith--;
                    if(mEndedWith<0)
                        mEndedWith = mNumOfClips-1;
                    break;
                default:
                    cout << "AN ERROR OCCURED" <<endl;
                    break;
            }

        }
        return true;

    }
    else{
        cout << "The playback should ADVANCE the number of steps given." <<endl;
        return false;
    }

};


