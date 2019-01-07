#ifndef APPLICATION_EVENT_H
#define APPLICATION_EVENT_H
#include "Event.h"

namespace EventEngine
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		CLASS_TYPE(WindowClose)
		CLASS_CATEGORY(Application)
	};

	class WindowResizeEvent : public Event
	{
	private:
		unsigned int m_Width, m_Height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		CLASS_TYPE(WindowResize)
		CLASS_CATEGORY(Application)		
	};

	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		CLASS_TYPE(AppTick)
		CLASS_CATEGORY(Application)
	};

	class AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		CLASS_TYPE(AppUpdate)
		CLASS_CATEGORY(Application)
	};

	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		CLASS_TYPE(AppRender)
		CLASS_CATEGORY(Application)
	};
}

#endif