# Live_Max
# Task Description: Follow Me
A clip in Live contains musical content, ranging from a short sound to an entire song. Some
clips play once, while others loop forever. Clips start playing when they are triggered. Clips
can also have Follow Actions, which allow creating groups of clips that can trigger each
other. A clip can have one or two Follow Actions that define what happens after a clip has
been playing for a set amount of time.
Every Follow Action has an associated Chance value that controls the likelihood of each of
the two Follow Actions occurring. For example, if action1 has Chance set to 1, and
action2 has Chance set to 0, action1 will be chosen every time. If, on the other hand,
action2 has Chance set to 10 in this scenario, action1 will be chosen ten times less
often than action2 on average.
We want you to write a program that simulates this behavior in a simplified way.

# Input description
Each input line consists of a keyword followed by arguments. There are two kinds of input
lines:
1. Clip definition: creates a named clip with a set of properties
clip <name> <ticks to play> <chance1> <chance2> <action1>
<action2>

2. Ticks command: runs the program a certain number of ticks
ticks <ticks to play> <...optional list of floating point numbers>

The clip definition defines a clip and its Follow Actions. ticks to play is the number of
steps that the clip should “play” before it triggers another clip as defined by the Follow
Actions. There are two Follow Actions associated with each clip, and they are chosen
randomly so that their relative occurrence corresponds to the specified follow chances.

Possible values for action1 and action2 are:

**none** Nothing happens – the clip keeps playing.

**any** Any clip (including the playing one) can be triggered (at random).

**other** Any other clip can be triggered (at random).

**next** The next clip (in the order they were created) will be triggered.

**previous** The previous clip will be triggered.

The list of clips should “wrap around”. In other words, if the next action is executed on the
last clip in the list, the first clip in the list should begin playing. Similarly, executing the
previous action on the first clip should begin playback of the last clip.
If a clip is created with the same name as an existing clip, the new clip should replace the
existing clip.

The ticks command indicates the number of times a clip is played. The ticks line may
optionally contain floating point numbers after the number of ticks. If these are supplied,
there should be one pair per tick.
For each tick, there are potentially two points where a random number may be needed. The
pairs of numbers, if supplied, should make the behavior deterministic at these points. Each
of the two numbers in the pair has a different purpose. If these numbers are absent in the
ticks input, random numbers should be used instead. 


