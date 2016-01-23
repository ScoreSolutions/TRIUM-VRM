#ifndef N_BIOMETRICS_H_INCLUDED
#define N_BIOMETRICS_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NBiometrics)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NBiometricsModuleOf() instead")
NResult N_API NBiometricsGetInfoA(NLibraryInfoA * pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NBiometricsModuleOf() instead")
NResult N_API NBiometricsGetInfoW(NLibraryInfoW * pValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NBiometricsModuleOf() instead")
NResult N_API NBiometricsGetInfo(NLibraryInfo * pValue);
#endif
#define NBiometricsGetInfo N_FUNC_AW(NBiometricsGetInfo)

#ifdef N_CPP
}
#endif

#endif // !N_BIOMETRICS_H_INCLUDED
