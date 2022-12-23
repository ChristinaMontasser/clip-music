#include "gtest/gtest.h"
#include "helper_functions.h"
#include <vector>
#include <Clip.h>
#include <Macros.h>
#include <iostream>
#include <string>
#include <Types.h>

struct ClipArrangedData
{
    vector<std::pair<float, float>> likelihood;
    Clip clip;
};

ClipArrangedData arrangeDataClip(string command_1, string command_2)
{
    ClipArrangedData arrangedData;
    stringstream stream(command_1);
    vector<string> commands_1;
    string tok;
    while(getline(stream, tok, ' ')) {
        commands_1.push_back(tok);
    };
    stringstream stream_2(command_2);
    vector<string> commands_2;
    while(getline(stream_2, tok, ' ')) {
        commands_2.push_back(tok);
    };
    vector<std::pair<float, float>> likelihood = commandTicks(commands_2);

    Clip clip= commandClip(commands_1);
    arrangedData.likelihood = likelihood;
    arrangedData.clip = clip;
    return arrangedData;
}


    //Function name  , one secnario of that function 
TEST(Clip_constructor, normal_scenerio) {

    //arrange
    string name = "hello";
    int ticks = 3;
    FollowAction actions[2];
    actions[0].actionName = Action::next;
    actions[1].actionName = Action::none;
    //act
    actions[0].chance = float(1.0);
    actions[1].chance = float(0.0);

    //assert
    EXPECT_EQ(Clip(name, ticks, actions).getName(), name);
    EXPECT_EQ(Clip(name, ticks, actions).getFollowAction()[0].chance, 1.0);
}

//action prioritizeAction(pair<float, float> likelihood);
TEST(Clip_prioritizeAction, likelihood_1_0) {
    string command_1 = "clips hello 2 1 0 next none";
    string command_2 = "ticks 10 0.3 0.8";
    ClipArrangedData arrangedData = arrangeDataClip(command_1, command_2);
    EXPECT_EQ(arrangedData.clip.prioritizeAction(arrangedData.likelihood[0]), Action::next);
}

TEST(Clip_prioritizeAction, likelihood_num_num) {
    string command_1 = "clips hello 2 3.0 2.0 next none";
    string command_2 = "ticks 4 0.3 0.8";
    ClipArrangedData arrangedData = arrangeDataClip(command_1, command_2);
    EXPECT_EQ(arrangedData.clip.prioritizeAction(arrangedData.likelihood.at(0)), Action::none); //Because 0.8 > 0.3
}

