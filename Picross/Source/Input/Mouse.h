#ifndef MOUSE_H
#define MOUSE_H
#include <memory>

class Window;

namespace Input
{
	class Mouse
	{
	public:
		double x, y;

	protected:
		std::shared_ptr<Window> s_Window;

		bool m_Held;
		bool m_Toggled;
		float m_ToggledTime;
		
		const float DELAY = 0.25f;

	public:
		Mouse(std::shared_ptr<Window>& display);
		virtual ~Mouse();

		bool GetInput();

	private:
		void ToViewportSpace(double* x, double* y);
	};
}

#endif