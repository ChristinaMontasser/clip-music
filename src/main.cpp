#include <iostream>
#include <vector>
#include<map>
#include <assert.h>
#include <string>
#include "helper_functions.h"
#include "Music.h"
#include <sstream>
using namespace std;

//Command Line run
int main()
{   //Clip command
    map<string, Clip> clips;
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
            if(clips.count(commands[CLIP_NAME])==0)
                clips.insert(make_pair(commands[CLIP_NAME], commandClipObj));
            else
                clips[commands[CLIP_NAME]] = commandClipObj;
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
                    clipsArr[i] = it.second;
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

