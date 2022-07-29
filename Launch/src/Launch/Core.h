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

#ifdef LN_ENABLE_ASSERTS
	#define LN_ASSERT(x, ...) { if(!(x)) { LN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LN_CORE_ASSERT(x, ...) { if(!(x)) { LN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LN_ASSERT(x, ...)
	#define LN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)