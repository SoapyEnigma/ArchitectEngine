#pragma once

#ifdef AE_PLATFORM_WINDOWS
	#ifdef AE_BUILD_DLL
		#define AE_API __declspec(dllexport)
	#else
		#define AE_API __declspec(dllimport)
	#endif
#else
	//#error AE only supports windows!
#endif

#ifdef AE_ENABLE_ASSERTS
	#define AE_ENGINE_ASSERT(x, ...) { if(!(x)) { AE_ENGINE_CRITICAL("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AE_APP_ASSERT(x, ...) { if(!(x)) { AE_APP_CRITICAL("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AE_ENGINE_ASSERT(x, ...)
	#define AE_APP_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)