#ifndef STATE_STACK_H
#define STATE_STACK_H
#include "State.h"
#include <vector>

#include "Event/Action.h"

class StateStack
{
private:
	std::vector<State*> m_States;

public:
	StateStack();
	~StateStack();

	void PushState(State* state);
	void PopState(); //change to State* state
	void ChangeState(State* state);

	void NotifyStates();
	void Listen(Action action);

	auto& Back() { return m_States.back(); }
	bool Empty() { return m_States.empty(); }
};

#endif