#include "Mouse.h"
#include "../Display.h"

namespace Input
{
	Mouse::Mouse(std::shared_ptr<Display>& display)
		: x(0.0), y(0.0)
		, s_Display(display)
		, m_Held(false), m_Toggled(false)
		, m_ToggledTime(0.0f)
	{

	}

	Mouse::~Mouse()
	{

	}

	void Mouse::GetInput()
	{
		glfwGetCursorPos(s_Display->Window, &x, &y);
		ToViewportSpace(&x, &y);

		if (glfwGetMouseButton(s_Display->Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && m_ToggledTime < glfwGetTime() - DELAY)
		{
			m_ToggledTime = (float)glfwGetTime();
			m_Toggled = true;
			m_Held = true;
		}
		else if (glfwGetMouseButton(s_Display->Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			m_Held = false;
			m_Toggled = false;
		}
		else
		{
			m_Toggled = false;
		}
	}

	void Mouse::ToViewportSpace(double* x, double* y)
	{
		*x = *x / (s_Display->Width	 / 100.0);
		*y = *y / (s_Display->Height / 100.0);
	}
}