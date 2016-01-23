#ifndef N_MEDIA_PROC_H_INCLUDED
#define N_MEDIA_PROC_H_INCLUDED

#include <NGrayscaleImageProc.h>
#include <NRgbImageProc.h>
#include <NSoundProc.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NMediaProc)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NMediaProcModuleOf() instead")
NResult N_API NMediaProcGetInfoA(NLibraryInfoA * pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NMediaProcModuleOf() instead")
NResult N_API NMediaProcGetInfoW(NLibraryInfoW * pValue);
#endif
#define NMediaProcGetInfo N_FUNC_AW(NMediaProcGetInfo)

#ifdef N_CPP
}
#endif

#endif // !N_MEDIA_PROC_H_INCLUDED
