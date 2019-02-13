#include "StateStack.h"

StateStack::StateStack()
{

}

StateStack::~StateStack()
{
	for (State* state : m_States)
	{
		delete state;
	}
}

void StateStack::PushState(State* state)
{
	if (!m_States.empty())
	{
		m_States.back()->Pause();
	}

	m_States.emplace_back(state);
}

void StateStack::PopState()
{
	if (m_States.size() >= 1)
	{
		m_States.pop_back();
	}

	if (!m_States.empty())
	{
		m_States.back()->Resume();
	}
}

void StateStack::ChangeState(State* state)
{
	//TODO: Change to StateChangeEvent event(MenuState);
	if (!m_States.empty())
	{
		m_States.pop_back();
	}

	m_States.emplace_back(state);
}

void StateStack::NotifyStates()
{
	for (auto& state : m_States)
	{
		//state->Notify(this);
	}
}

void StateStack::Listen(Action action)
{
	if (action == Action::StateClose)
	{
		PopState();
	}
}