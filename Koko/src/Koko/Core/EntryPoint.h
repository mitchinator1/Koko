#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H
#include "Koko/Core/Core.h"

#ifdef KOKO_PLATFORM_WINDOWS

extern Koko::Application* Koko::CreateApplication();

int main(int argc, char** argv)
{
	Koko::Log::Init();

	auto app = Koko::CreateApplication();
	app->Run();
	delete app;
}

#endif

#endif