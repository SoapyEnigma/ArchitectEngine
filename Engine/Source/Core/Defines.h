#pragma once

#ifdef WW_PLATFORM_WINDOWS
	#ifdef WW_BUILD_DLL
		#define WW_API __declspec(dllexport)
	#else
		#define WW_API __declspec(dllimport)
	#endif
#else
	//#error WW only supports windows!
#endif