#pragma once
#include "Koko/Core/Core.h"

#ifdef KOKO_PLATFORM_WINDOWS

extern Koko::Application* Koko::CreateApplication();

int main(int argc, char** argv)
{
	Koko::Log::Init();

	KK_PROFILE_BEGIN_SESSION("Startup", "KokoProfile-Startup.json");
	auto app = Koko::CreateApplication();
	KK_PROFILE_END_SESSION();

	KK_PROFILE_BEGIN_SESSION("Runtime", "KokoProfile-Runtime.json");
	app->Run();
	KK_PROFILE_END_SESSION();

	KK_PROFILE_BEGIN_SESSION("Shutdown", "KokoProfile-Shutdown.json");
	delete app;
	KK_PROFILE_END_SESSION();
}

#endif