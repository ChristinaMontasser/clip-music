#include "Clip.h"
#include <unordered_map>

static unordered_map<string, Action> const STRING_TO_ACTION_CONVERTER =
                                                {
                                                    {"none", Action::none},
                                                    {"any", Action::any},
                                                    {"other", Action::other},
                                                    {"next", Action::next},
                                                    {"previous", Action::previous},
                                                };

int randomInt(int start, int range, int notNum);
float randomFloat();
Clip commandClip(vector<string> commands);
vector<pair<float, float>> commandTicks(vector<string> commands);


