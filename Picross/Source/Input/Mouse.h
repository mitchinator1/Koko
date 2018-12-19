#ifndef MOUSE_H
#define MOUSE_H
#include <memory>

namespace State { class StateBase; }
struct Display;

namespace Input
{
	class Mouse
	{
	public:
		double x, y;

	protected:
		std::shared_ptr<Display> s_Display;

		bool m_Held;
		bool m_Toggled;
		float m_ToggledTime;
		
		const float DELAY = 0.25f;

	public:
		Mouse(std::shared_ptr<Display>& display);
		virtual ~Mouse();

		void GetInput(); //TODO: Change to bool. if no input, return false.

	private:
		void ToViewportSpace(double* x, double* y);
	};
}

#endif