#ifndef WINDOW_H
#define WINDOW_H
#include "kkpch.h"

#include "Core.h"
#include "Event/Event.h"

struct WindowProps
{
	std::string Title;
	unsigned int Width, Height;

	WindowProps(const std::string& title = "Koko Engine Sandbox",
		unsigned int width = 1800,
		unsigned int height = 1400)
		: Title(title), Width(width), Height(height)
	{
	}
};

class KK_API Window
{
public:
	using EventCallbackFn = std::function<void(Koko::Event&)>;
	
	virtual ~Window() {}
	
	virtual void OnUpdate()				   = 0;

	virtual unsigned int GetWidth()	 const = 0;
	virtual unsigned int GetHeight() const = 0;

	virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
	virtual void SetVSync(bool enabled)	   = 0;
	virtual bool IsVSync()			 const = 0;

	static Window* Create(const WindowProps& props = WindowProps());
};

#endif