    /*Music();
    Music(Clip* clips, int numOfClips,int ticks);
    Music(const Music& music);
    bool checkPlayAdvanceStep();
    void start(int ticks, vector<pair<float, float>> pairsPerTicks);*/

#include "gtest/gtest.h"
#include "helper_functions.h"
#include <vector>
#include <Clip.h>
#include <Macros.h>
#include <iostream>
#include <string>
#include <Music.h>

TEST(Music_start, test1){
//Arrange 
    //Clips objects to be sent to music object 
    map<string, Clip> clips_music; 
    string command_1[]= {"clips hello 2 1 0 next none", "clips world 3 1 0 previous none"};
            string tok;

    for(int i=0; i<2; i++)
    {
        stringstream stream(command_1[i]);
        vector<string> commands;
        while(getline(stream, tok, ' ')) {
            commands.push_back(tok);
        };
        clips_music.insert(make_pair(commands[CLIP_NAME], command_clip(commands)));
    }
    string command_2 = "ticks 10 0.3 0.8";
    stringstream stream_2(command_2);
    vector<string> commands_2;
    while(getline(stream_2, tok, ' ')) {
        commands_2.push_back(tok);
    };
    int numOfClips = clips_music.size();
    Clip* clipsArr = new Clip[numOfClips];
    int i=0;
    for(auto it:clips_music)
    {
        clipsArr[i] = it.second;
        i++;
    }
    Music music(clipsArr, 2, stoi(commands_2[TICKS_TICKS]));
    vector<std::pair<float, float>> likelihood= command_ticks(commands_2);
//Act

   EXPECT_TRUE(music.start(likelihood));

//Assert

}


TEST(Music_start, test2){
//Arrange 
    //Clips objects to be sent to music object 
    map<string, Clip> clips_music; 
    string command_1[]= {"clips hello 1 1 0 next none", "clips world 3 1 0 previous none"};
            string tok;

    for(int i=0; i<2; i++)
    {
        stringstream stream(command_1[i]);
        vector<string> commands;
        while(getline(stream, tok, ' ')) {
            commands.push_back(tok);
        };
        clips_music.insert(make_pair(commands[CLIP_NAME], command_clip(commands)));
    }
    string command_2 = "ticks 10 0.3 0.8";
    stringstream stream_2(command_2);
    vector<string> commands_2;
    while(getline(stream_2, tok, ' ')) {
        commands_2.push_back(tok);
    };
    int numOfClips = clips_music.size();
    Clip* clipsArr = new Clip[numOfClips];
    int i=0;
    for(auto it:clips_music)
    {
        clipsArr[i] = it.second;
        i++;
    }
    Music music(clipsArr, 2, stoi(commands_2[TICKS_TICKS]));
    vector<std::pair<float, float>> likelihood= command_ticks(commands_2);
//Act

   EXPECT_FALSE(music.start(likelihood));

//Assert

}
