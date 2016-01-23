#ifndef N_DEVICES_H_INCLUDED
#define N_DEVICES_H_INCLUDED

#include <NCore.h>
#include <NDeviceManager.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NDevices)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NDevicesModuleOf() instead")
NResult N_API NDevicesGetInfoA(NLibraryInfoA * pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NDevicesModuleOf() instead")
NResult N_API NDevicesGetInfoW(NLibraryInfoW * pValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NDevicesModuleOf() instead")
NResult N_API NDevicesGetInfo(NLibraryInfo * pValue);
#endif
#define NDevicesGetInfo N_FUNC_AW(NDevicesGetInfo)

#ifdef N_CPP
}
#endif

#endif // !N_DEVICES_H_INCLUDED
