#ifndef N_LICENSING_H_INCLUDED
#define N_LICENSING_H_INCLUDED

#include <NCore.h>
#include <NLicense.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NLicensing)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NLicensingModuleOf() instead")
NResult N_API NLicensingGetInfoA(NLibraryInfoA * pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NLicensingModuleOf() instead")
NResult N_API NLicensingGetInfoW(NLibraryInfoW * pValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NLicensingModuleOf() instead")
NResult N_API NLicensingGetInfo(NLibraryInfo * pValue);
#endif
#define NLicensingGetInfo N_FUNC_AW(NLicensingGetInfo)

#ifdef N_CPP
}
#endif

#endif /**!doc !N_LICENSING_H_INCLUDED */
