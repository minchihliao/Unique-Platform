#pragma once

#ifdef UQ_PLAFORM_WINDOWS
	#ifdef UQ_BULD_DLL
		#define UNQIUE_API __declspec(dllexport)
	#else
		#define UNQIUE_API __declspec(dllimport)
	#endif
#else
	#error Unique only supports Windos!
#endif // UQ_PLAFORM_WINDOWS


#ifdef UQ_ENABLE_ASSERTS
#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define UQ_ASSERT(x, ...)
#define UQ_CORE_ASSERT(x, ...)
#endif




#define BIT(x) (1 << x)