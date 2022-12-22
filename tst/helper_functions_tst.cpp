#include "gtest/gtest.h"
#include "helper_functions.h"
#include <vector>
#include <Clip.h>
#include <Macros.h>
#include <iostream>
#include <string>

vector<string> arrangeDataHelpFunctions(string command)
{
    stringstream stream(command);
    vector<string> commands;
    string tok;
    while(getline(stream, tok, ' ')) {
        commands.push_back(tok);
    }
    return commands;
}
//command_clip takes the string of the command of a clip and returns a clip object 
TEST(helper_functions_clip, command_clip) {
    //Arrange --> set all preconditions 
    string command = "clips hello 2 1 0 next none";
    vector<string> commands = arrangeDataHelpFunctions(command);
    ASSERT_EQ(commands[COMMAND], "clips");
    //Act --> run the test
    EXPECT_EQ(commandClip(commands).getName(), commands[CLIP_NAME]);
    EXPECT_EQ(commandClip(commands).getFollowAction()[0].actionName, STRING_TO_ACTION_CONVERTER.at(commands[FOLLOW_ACTION_NAME]));
    EXPECT_EQ(commandClip(commands).getFollowAction()[1].actionName, STRING_TO_ACTION_CONVERTER.at(commands[FOLLOW_ACTION_NAME+1])); 
}

TEST(helper_functions_ticks, command_ticks_without_likelihood) {
    //CASE 1, if they send without likelihood
    string command = "ticks 10";
    vector<string> commands = arrangeDataHelpFunctions(command);
    ASSERT_EQ(commands[COMMAND], "ticks");
    EXPECT_GE(commandTicks(commands).size(), stoi(commands[TICKS_TICKS]));
}

TEST(helper_functions_ticks, command_ticks_with_some_likelihoods) {
    //CASE 2, if they were send with not enough likelihood list, others will be generated
    //But the sent ones will be as it is 
    string command = "ticks 10 0.3 0.1";
    vector<string> commands = arrangeDataHelpFunctions(command);
    ASSERT_EQ(commands[COMMAND], "ticks");
    EXPECT_GE(commandTicks(commands).size(), stoi(commands[TICKS_TICKS]));
    EXPECT_GE(commandTicks(commands).at(0).first, stof(commands[TICKS_START_PAIR]));

}