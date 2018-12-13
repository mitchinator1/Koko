#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<Display> display)
	: m_Display(display)
{
}


Renderer::~Renderer()
{
}

void Renderer::Render()
{
	Clear();

	Swap();
}

void Renderer::Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Swap()
{
	glfwSwapBuffers(m_Display->Window);
}