#pragma once
enum Action
{
    none,
    any,
    other,
    next,
    previous
};

struct FollowAction
{
    Action actionName;
    float chance;
};



