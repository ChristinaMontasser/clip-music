#include "Clip.h"
#include <unordered_map>

static unordered_map<string, action> const strToActionConverter =
                                                {
                                                    {"none", action::none},
                                                    {"any", action::any},
                                                    {"other", action::other},
                                                    {"next", action::next},
                                                    {"previous", action::previous},
                                                };

int randomInt(int start, int range, int notNum);
float randomFloat();
Clip command_clip(vector<string> commands);
vector<pair<float, float>> command_ticks(vector<string> commands);


