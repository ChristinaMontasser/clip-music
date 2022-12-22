#include "gtest/gtest.h"
#include "helper_functions.h"
#include <vector>
#include <Clip.h>
#include <Macros.h>
#include <iostream>
#include <string>
//We can not test random because it's random u know :D
/*int randomInt(int start, int range, int notNum);
float randomFloat();*/


//Clip command_clip(vector<string> commands);


//command_clip takes the string of the command of a clip and returning a clip object 
TEST(command_clip_1, hf_f1) {
    //Arrange --> set all preconditions 
    string command = "clips hello 2 1 0 next none";
    stringstream stream(command);
    vector<string> commands;
    string tok;
    while(getline(stream, tok, ' ')) {
        commands.push_back(tok);
    }
    ASSERT_EQ(commands[COMMAND], "clips");
    //Act --> run the test
    //Clip clip =command_clip(commands);
    //Assert --> verify the test
    EXPECT_EQ(command_clip(commands).getName(), commands[CLIP_NAME]);
    // EXPECT_EQ(command_clip(commands).getFollowAction()[0].actionName, strToActionConverter.at(commands[FOLLOW_ACTION_NAME]));
    // EXPECT_EQ(command_clip(commands).getFollowAction()[0].actionName, strToActionConverter.at(commands[FOLLOW_ACTION_NAME+1]));
    
}

//vector<pair<float, float>> command_ticks(vector<string> commands);
TEST(command_ticks_1, hf_f2) {
    //CASE 1, if they send without likelihood
    string command = "ticks 10";
    stringstream stream(command);
    vector<string> commands;
    string tok;
    while(getline(stream, tok, ' ')) {
        commands.push_back(tok);
    }
    ASSERT_EQ(commands[COMMAND], "ticks");
    EXPECT_GE(command_ticks(commands).size(), stoi(commands[TICKS_TICKS]));
}

TEST(command_ticks_2, hf_f2) {
    //CASE 2, if they send with not enough likelihood list, others will be generated
    //But the sent ones will be as it is 
    string command = "ticks 10 0.3 0.1";
    stringstream stream(command);
    vector<string> commands;
    string tok;
    while(getline(stream, tok, ' ')) {
        commands.push_back(tok);
    }
    ASSERT_EQ(commands[COMMAND], "ticks");
    EXPECT_GE(command_ticks(commands).size(), stoi(commands[TICKS_TICKS]));
    EXPECT_GE(command_ticks(commands).at(0).first, stof(commands[TICKS_START_PAIR]));

    //CASE 2, if they send without likelihoo
}