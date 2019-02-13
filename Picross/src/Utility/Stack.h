#ifndef STACK_H
#define STACK_H
#include <vector>
#include <type_traits>
#include "Event/Action.h"

template <typename T>
class Stack
{
private:
	typename std::vector<T*> m_Entities;
	typename std::vector<T*>::iterator m_Insert;

public:
	Stack() noexcept
	{
		m_Insert = end();
	}

	~Stack() noexcept
	{
		for (auto& e : m_Entities)
		{
			delete e;
		}
	}

	template <typename T>
	typename std::enable_if<std::is_base_of<Layer, T>::value>::type
		Push(T* t)
	{
		t->OnAttach();
		m_Insert = m_Entities.insert(begin(), t);
	}

	template <typename T>
	typename std::enable_if<!std::is_base_of<Layer, T>::value>::type
		Push(T* t)
	{
		m_Insert = m_Entities.insert(begin(), t);
	}

	template <typename T>
	typename std::enable_if<std::is_base_of<Layer, T>::value>::type
		PushBack(T* t)
	{
		t->OnAttach();
		m_Insert = m_Entities.insert(end(), t);
	}

	template <typename T>
	typename std::enable_if<!std::is_base_of<Layer, T>::value>::type
		PushBack(T* t)
	{
		m_Insert = m_Entities.insert(end(), t);
	}
	
	template <typename T>
	typename std::enable_if<std::is_base_of<Layer, T>::value>::type
		Pop(T* t)
	{
		auto it = std::find(begin(), end(), t);
		if (it != end())
		{
			t->OnDetach();
			m_Entities.erase(it);
			//m_Insert = begin();
		}
	}

	template <typename T>
	typename std::enable_if<!std::is_base_of<Layer, T>::value>::type
		Pop(T* t)
	{
		auto it = std::find(begin(), end(), t);
		if (it != end())
		{
			m_Entities.erase(it);
			--m_Insert;
		}
	}

	void Pop()
	{
		if (size() > 0)
		{
			//m_Entities.front()->OnDetach();
			auto temp = m_Entities.erase(begin());
			/*if (size() == 0)
			{
				m_Insert = temp;
			}
			else
			{
				m_Insert = begin();
			}*/
		}
	}

	template <typename T>
	typename std::enable_if<!std::is_base_of<Layer, T>::value>::type
		Pop()
	{
		if (size() > 0)
		{
			auto temp = m_Entities.erase(begin());
			/*if (size() == 0)
			{
				m_Insert = temp;
			}
			else
			{
				m_Insert = begin();
			}*/
		}
	}

	void PopBack()
	{
		if (size() > 0)
		{
			/*if (std::is_base_of<Layer, T>())
			{
				t->OnDetach();
			}*/
			m_Entities.erase(end() - 1);
			//--m_Insert;
		}
	}

	void Notify()
	{
		for (auto& e : m_Entities)
		{
			e->Notify(this);
		}
	}

	void Listen(Action action)
	{
		//TODO: Remove this
		if (action == Action::StateRemove)
		{
			Pop();
		}
	}

	inline auto begin()		{ return m_Entities.begin(); }
	inline auto rbegin()	{ return m_Entities.rbegin(); }

	inline auto end()		{ return m_Entities.end(); }
	inline auto rend()		{ return m_Entities.rend(); }

	inline auto& front()	{ return m_Entities.front(); }
	inline auto& back()		{ return m_Entities.back(); }

	inline auto size()		{ return m_Entities.size(); }
	inline bool empty()		{ return m_Entities.empty(); }

	typename T* operator[](unsigned int i)
	{
		return i >= (int)size() ? back() : m_Entities[i];
	}
};

#endif