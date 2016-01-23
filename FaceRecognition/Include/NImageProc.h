#ifndef N_IMAGE_PROC_H_INCLUDED
#define N_IMAGE_PROC_H_INCLUDED

#include <NMediaProc.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NImageProcModuleOf NMediaProcModuleOf
#define NImageProcGetInfo NMediaProcGetInfo
#define NImageProcGetInfoA NMediaProcGetInfoA
#define NImageProcGetInfoW NMediaProcGetInfoW

#ifdef N_MSVC
	#pragma deprecated("NImageProcModuleOf")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_PROC_H_INCLUDED
