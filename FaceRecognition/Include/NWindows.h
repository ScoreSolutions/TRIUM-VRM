#ifndef N_WINDOWS_H_INCLUDED
#define N_WINDOWS_H_INCLUDED

#include <NDefs.h>

#ifdef N_WINDOWS
	#ifdef N_MSVC
		#pragma warning(push)
		#pragma warning(disable: 4005)
		#ifdef N_WINDOWS_CE
			#pragma warning(disable: 4201 4214 4115)
		#endif
	#endif
	#include <windows.h>
	#ifdef N_MSVC
		#pragma warning(pop)
	#endif
#endif

#endif // !N_WINDOWS_H_INCLUDED
