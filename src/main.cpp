#include <iostream>
#include <vector>
#include<map>
#include <assert.h>
#include <string>
#include "helper_functions.h"
#include "Music.h"
#include <sstream>
#include <algorithm>

using namespace std;

//Command Line run
int main()
{   //Clip command
    vector<Clip> clips;
    vector<string> duplicationCheck;
    Clip* clipsArr;
    Music globalTick;
    int flag = 0;
    int numOfClips=0;
    while(true)
    {
       // Music tick();
        string command;
        getline(cin, command);
        std::stringstream stream(command);
        vector<string> commands;
        string tok;
        while(getline(stream, tok, ' ')) {
            commands.push_back(tok);
        }
         // clip <name> <Music to play> <chance1> <chance2> <action1> <action2>
        if(commands[COMMAND] == "clip")
        {
            Clip commandClipObj = commandClip(commands);
            auto it = find(duplicationCheck.begin(), duplicationCheck.end(), commands[CLIP_NAME]);
            if (it == duplicationCheck.end())
            {
                clips.push_back(commandClipObj);
                duplicationCheck.push_back(commandClipObj.getName());
            }
            else
            {
                int index = (it - duplicationCheck.begin());
                clips[index] = commandClipObj;

            }
            flag =0;
        }
        else if(commands[COMMAND] == "ticks")
        {
            if(flag == 0)
            {
                //Copy them to an array to be sent to the class
                numOfClips = clips.size();
                clipsArr = new Clip[numOfClips];
                int i=0;
                for(auto it:clips)
                {
                    clipsArr[i] = it;
                    i++;
                }
                clips.clear();
                flag =1;
                Music tick(clipsArr, numOfClips, stoi(commands[TICKS_TICKS]));
                globalTick = tick;
            }
            globalTick.start(commandTicks(commands));
        }
        else{
            cout<<"UNDEFINED COMMAND";
            break;
        }

    }

  return 0;
}

