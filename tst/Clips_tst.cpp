#include "gtest/gtest.h"
#include "helper_functions.h"
#include <vector>
#include <Clip.h>
#include <Macros.h>
#include <iostream>
#include <string>
#include <Types.h>


/*
    int ticks;
    Clip();
    Clip(string name, int ticks, FollowAction* actions);
    Clip(const Clip& clip);
    string getName();
    FollowAction* getFollowAction();
    void start(int amount);
    action prioritizeAction(pair<float, float> likelihood);
    bool operator==(const Clip& clip);
*/

    //Function name  , one secnario of that function 
TEST(Clip_constructor, test1) {

    //arrange
    string name = "hello";
    int ticks = 3;
    FollowAction actions[2];
    actions[0].actionName = action::next;
    actions[1].actionName = action::none;
    //act
    actions[0].chance = 1;
    actions[1].chance = 0;

    //assert
    EXPECT_EQ(Clip(name, ticks, actions).getName(), name);
}

//action prioritizeAction(pair<float, float> likelihood);
TEST(Clip_prioritizeAction, likelihood_1_0) {
    //Case when they are "1, 0" 
    string command_1 = "clips hello 2 1 0 next none";
    stringstream stream(command_1);
    vector<string> commands_1;
    string tok;
    while(getline(stream, tok, ' ')) {
        commands_1.push_back(tok);
    };
    string command_2 = "ticks 1 0.3 0.8";
    stringstream stream_2(command_2);
    vector<string> commands_2;
    while(getline(stream_2, tok, ' ')) {
        commands_2.push_back(tok);
    };
    vector<std::pair<float, float>> likelihood = command_ticks(commands_2);

    Clip clip=command_clip(commands_1);
    EXPECT_EQ(clip.prioritizeAction(likelihood[0]), action::next);
}

TEST(Clip_prioritizeAction, likelihood_num_num) {
    //Case when they are "1, 0" 
    string command_1 = "clips hello 2 3 1 next none";
    stringstream stream(command_1);
    vector<string> commands_1;
    string tok;
    while(getline(stream, tok, ' ')) {
        commands_1.push_back(tok);
    };
    string command_2 = "ticks 10 0.3 0.8";
    stringstream stream_2(command_2);
    vector<string> commands_2;
    while(getline(stream_2, tok, ' ')) {
        commands_2.push_back(tok);
    };
    vector<std::pair<float, float>> likelihood = command_ticks(commands_2);

    Clip clip=command_clip(commands_1);
    EXPECT_EQ(clip.prioritizeAction(likelihood.at(0)), action::none); //Because it's 0.8 > 0.3
}

