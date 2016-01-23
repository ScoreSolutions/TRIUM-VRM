#ifndef FP_SCANNER_MAN_H_INCLUDED
#define FP_SCANNER_MAN_H_INCLUDED

#include <FPScanner.h>
#include <NDeviceManager.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(FPScannerMan)

typedef void (N_CALLBACK FPScannerManScannerCallbackEx)(HFPScanner hScanner, void * pParam);

typedef void (N_CALLBACK FPScannerManScannerCallbackN)(HNString hScannerId, void * pParam);
#ifndef N_NO_ANSI_FUNC
typedef void (N_CALLBACK FPScannerManScannerCallbackA)(const NAChar * szScannerId, void * pParam);
#endif
#ifndef N_NO_UNICODE
typedef void (N_CALLBACK FPScannerManScannerCallbackW)(const NWChar * szScannerId, void * pParam);
#endif
#define FPScannerManScannerCallback N_CALLBACK_AW(FPScannerManScannerCallback)

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetAvailableModulesN(HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetAvailableModulesA(NAChar * * pszValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetAvailableModulesW(NWChar * * pszValue);
#endif
#define FPScannerManGetAvailableModules N_FUNC_AW(FPScannerManGetAvailableModules)

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManInitialize(void);

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManInitializeWithModulesN(HNString hModules);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManInitializeWithModulesA(const NAChar * szModules);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManInitializeWithModulesW(const NWChar * szModules);
#endif
#define FPScannerManInitializeWithModules N_FUNC_AW(FPScannerManInitializeWithModules)

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManInitialize(void);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
void N_API FPScannerManUninitialize(void);

NResult N_API FPScannerManGetDeviceManager(HNDeviceManager * phDeviceManager);
NResult N_API FPScannerManGetScannerFromDevice(HNFScanner hDevice, HFPScanner * phScanner);

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetScannerCount(NInt * pValue);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetScanner(NInt index, HFPScanner * pValue);

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetScannerByIdN(HNString hId, HFPScanner * pValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetScannerByIdA(const NAChar * szId, HFPScanner * pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManGetScannerByIdW(const NWChar * szId, HFPScanner * pValue);
#endif
#define FPScannerManGetScannerById N_FUNC_AW(FPScannerManGetScannerById)

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerAddedCallbackEx(FPScannerManScannerCallbackEx pCallback, void * pParam);

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerAddedCallbackN(FPScannerManScannerCallbackN pCallback, void * pParam);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerAddedCallbackA(FPScannerManScannerCallbackA pCallback, void * pParam);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerAddedCallbackW(FPScannerManScannerCallbackW pCallback, void * pParam);
#endif
#define FPScannerManSetScannerAddedCallback N_FUNC_AW(FPScannerManSetScannerAddedCallback)

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerRemovedCallbackEx(FPScannerManScannerCallbackEx pCallback, void * pParam);

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerRemovedCallbackN(FPScannerManScannerCallbackN pCallback, void * pParam);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerRemovedCallbackA(FPScannerManScannerCallbackA pCallback, void * pParam);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerManSetScannerRemovedCallbackW(FPScannerManScannerCallbackW pCallback, void * pParam);
#endif
#define FPScannerManSetScannerRemovedCallback N_FUNC_AW(FPScannerManSetScannerRemovedCallback)

#ifdef N_CPP
}
#endif

#endif // !FP_SCANNER_MAN_H_INCLUDED
