#pragma once
enum action
{
    none,
    any,
    other,
    next,
    previous
};

struct FollowAction
{
    action actionName;
    int chance;
};



