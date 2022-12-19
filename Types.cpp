#include "Ticks.h"
enum action
{
    none,
    any,
    other,
    next,
    previous
};


struct FollowAction;{
    action actionName;
    int chance;
    int playedTimes = 0;
}
