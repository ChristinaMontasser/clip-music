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

struct MusicArrangedData
{
    vector<std::pair<float, float>> likelihood;
    Music music;
};
MusicArrangedData arrangeDataMusic(string* command_1, string command_2){
    map<string, Clip> clips_music; 
    MusicArrangedData arrangeData;
    string tok;
    for(int i=0; i<ACTIONS; i++)
    {
        stringstream stream(command_1[i]);
        vector<string> commands;
        while(getline(stream, tok, ' ')) {
            commands.push_back(tok);
        };
        clips_music.insert(make_pair(commands[CLIP_NAME], commandClip(commands)));
    }
    int numOfClips = clips_music.size();
    Clip* clipsArr = new Clip[numOfClips];
    int i=0;
    for(auto it:clips_music)
    {
        clipsArr[i] = it.second;
        i++;
    }
    //Tick
    stringstream stream_2(command_2);
    vector<string> commands_2;
    while(getline(stream_2, tok, ' ')) {
        commands_2.push_back(tok);
    };

    arrangeData.music =Music(clipsArr, 2, stoi(commands_2[TICKS_TICKS]));
    arrangeData.likelihood= commandTicks(commands_2);
    return arrangeData;
}

TEST(Music_start, advanced_playback){
    string command_1[]= {"clips hello 2 1 0 next none", "clips world 3 1 0 previous none"};
    string command_2 = "ticks 10 0.3 0.8";
    MusicArrangedData arrangedData = arrangeDataMusic(command_1, command_2);
    EXPECT_TRUE(arrangedData.music.start(arrangedData.likelihood));
}


TEST(Music_start, non_advanced_playback){
    //Arrange     
    string command_1[]= {"clips hello 1 1 0 next none", "clips world 3 1 0 previous none"};
    string command_2 = "ticks 10 0.3 0.8";
    MusicArrangedData arrangedData = arrangeDataMusic(command_1, command_2);
    //Act & Assert 
    EXPECT_FALSE(arrangedData.music.start(arrangedData.likelihood));
}
