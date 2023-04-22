#pragma once

#ifdef AL_PLATFORM_WINDOWS
	#ifdef AL_BUILD_DLL
		#define APRIL_API __declspec(dllexport)
	#else
		#define APRIL_API __declspec(dllimport)
	#endif // AL_BUILD_DLL
#else
	#error April only supports windows!
#endif // AL_PLATFORM_WINDOWS
