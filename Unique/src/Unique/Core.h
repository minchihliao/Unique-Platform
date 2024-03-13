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
