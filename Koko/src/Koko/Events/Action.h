#ifndef ACTION_H
#define ACTION_H

enum class Action
{
	None = 0,
	AppClose, AppPause,
	StateRemove, StatePause, StateResume,
	LayerRemove,
	EntityRemove
};

#endif