#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <sstream>
#include <functional>

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace EventEngine
{

	enum class Type
	{
		None = 0,
		WindowClose, WindowResize,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum Category
	{
		None		= 0,
		Application = BIT(0),
		Input		= BIT(1),
		Keyboard	= BIT(2),
		Mouse		= BIT(3),
		MouseButton	= BIT(4)
	};

#define CLASS_TYPE(type)	static Type GetStaticType() { return Type::##type; }\
							virtual Type GetEventType() const override { return GetStaticType(); }\
							virtual const char* GetName() const override { return #type; }

#define CLASS_CATEGORY(category)	virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
		friend class Dispatcher;

	public:
		bool Handled = false;

	public:
		virtual Type GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(Category category)	{ return GetCategoryFlags() & category;	}
	};

	class Dispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		Dispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}

#endif