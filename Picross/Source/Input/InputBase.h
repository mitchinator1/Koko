#ifndef INPUT_BASE_H
#define INPUT_BASE_H
#include <memory>
#include "../Display.h"

namespace Input
{
	class InputBase
	{
	private:
		std::shared_ptr<Display> s_Display;

	public:
		InputBase(std::shared_ptr<Display> display) : s_Display(display) {}
		virtual ~InputBase() {}
	};
}

#endif