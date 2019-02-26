#pragma once

#ifdef GAME_ENGINE_PLATFORM_WINDOWS
	#ifdef GAME_ENGINE_BUILD_DLL
		#define GE_API __declspec(dllexport)
	#else
		#define GE_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif