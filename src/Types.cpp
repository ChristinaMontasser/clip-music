enum action
{
    none,
    any,
    other,
    next,
    previous
};


struct FollowAction{
    action actionName;
    float chance;
};
