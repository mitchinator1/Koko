#ifndef STATE_STACK_H
#define STATE_STACK_H
#include "State.h"

#include <vector>

class StateStack
{
private:
	std::vector<State*> m_States;

public:
	StateStack();
	~StateStack();

	void PushState(State* state);
	void PopState();
	void ChangeState(State* state);

	auto& Back() { return m_States.back(); }

};

#endif