#pragma once

#ifdef LN_PLATFORM_WINDOWS
	#ifdef LN_BUILD_DLL
		#define LAUNCH_API __declspec(dllexport)
	#else
		#define LAUNCH_API __declspec(dllimport)
	#endif
#else
	#error Launch only supports Windows
#endif
