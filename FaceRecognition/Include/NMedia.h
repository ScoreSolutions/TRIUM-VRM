#ifndef N_MEDIA_H_INCLUDED
#define N_MEDIA_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NMedia)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NMediaModuleOf() instead")
NResult N_API NMediaGetInfoA(NLibraryInfoA *pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NMediaModuleOf() instead")
NResult N_API NMediaGetInfoW(NLibraryInfoW *pValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NMediaModuleOf() instead")
NResult N_API NMediaGetInfo(NLibraryInfo * pValue);
#endif
#define NMediaGetInfo N_FUNC_AW(NMediaGetInfo)

#ifdef N_CPP
}
#endif

#endif // !N_MEDIA_H_INCLUDED
