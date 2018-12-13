#ifndef RENDERER_H
#define RENDERER_H
#include <memory>
#include "../Display.h"

class Renderer
{
private:
	std::shared_ptr<Display> m_Display;

public:
	Renderer(std::shared_ptr<Display> display);
	virtual ~Renderer();

	void Render();

private:
	void Clear();
	void Swap();
};

#endif