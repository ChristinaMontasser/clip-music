#include "helper_functions.h"

int randomInt(int start, int range, int notNum)
{
    // A function to generate random numbers
    int random = (start + rand() % range);
    if(notNum != -1)
    {
        while(notNum == random)
        {
            random = (start + rand() % range);
        }
    }
    return random;
}

//Standalone functions
float randomFloat()
{
    // A function to generate random numbers
    return ((float) rand()) / (float) RAND_MAX;
}

Clip commandClip(vector<string> commands)
{
    assert(commands.size() == 7);
    FollowAction follow_actions[ACTIONS];
    for(int i=0; i<ACTIONS; i++)
    {
        follow_actions[i].actionName = STRING_TO_ACTION_CONVERTER.at(commands[i+FOLLOW_ACTION_NAME]);
        follow_actions[i].chance = stoi(commands[i+FOLLOW_ACTION_CHANCE]);
    }

    return Clip(commands[CLIP_NAME], stoi(commands[CLIP_TICKS]), follow_actions);
}


vector<pair<float, float>> commandTicks(vector<string> commands)
{
        vector<pair<float, float>> ticks_pair;
        //ticks <ticks to play> <...optional list of floating point numbers>
        if(commands.size()== TICKS_WITHOUT_PAIR)
        {
            //Random and add to a vector
            for(int i=0; i<stoi(commands[TICKS_TICKS]); i++)
            {
                ticks_pair.push_back(pair<float, float>(randomFloat(), randomFloat()));
            }
        }
        else if((commands.size()> TICKS_WITHOUT_PAIR) && (commands.size() < 2*stoi(commands[TICKS_TICKS])))
        {
            //Add the existing values
            for(int i=TICKS_START_PAIR; i<commands.size(); i= i+2)
            {
                ticks_pair.push_back(pair<float, float>(stof(commands[i]), stof(commands[i+1])));
            }
            //Estimate the others
            for(int i=0; i<stoi(commands[TICKS_TICKS])+((commands.size()-2)/2); i++)
            {
                ticks_pair.push_back(pair<float, float>(randomFloat(), randomFloat()));
            }
        }
        else{
            for(int i=TICKS_START_PAIR; i<commands.size(); i= i+2)
            {
                ticks_pair.push_back(pair<float, float>(stof(commands[i]), stof(commands[i+1])));
            }
        }
        return ticks_pair;
}
