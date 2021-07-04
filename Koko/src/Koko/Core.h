#ifndef CORE_H
#define CORE_H

#ifdef KOKO_PLATFORM_WINDOWS
#if KOKO_DYNAMIC_LINK
#ifdef KOKO_BUILD_DLL
#define KK_API __declspec(dllexport)
#else
#define KK_API __declspec(dllimport)
#endif
#else
#define KK_API
#endif
#else
//#error Koko only supports Windows!
#endif

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#endif