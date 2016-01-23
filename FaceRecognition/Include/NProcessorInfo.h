#ifndef N_PROCESSOR_INFO_H_INCLUDED
#define N_PROCESSOR_INFO_H_INCLUDED

#include <NCore.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NProcessorVendor_
{
	npvUnknown = 0,
	npvAmd = 1,
	npvCentaur = 2,
	npvCyrix = 3,
	npvIntel = 4,
	npvNationalSemiconductor = 5,
	npvNexGen = 6,
	npvRiseTechnology = 7,
	npvSiS = 8,
	npvTransmeta = 9,
	npvUmc = 10,
	npvVia = 11
} NProcessorVendor;

N_DECLARE_TYPE(NProcessorVendor)

N_DECLARE_STATIC_OBJECT_TYPE(NProcessorInfo)

NResult N_API NProcessorInfoGetCount(NInt * pValue);

NResult N_API NProcessorInfoGetVendorNameN(HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NProcessorInfoGetVendorNameExA(NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NProcessorInfoGetVendorNameExW(NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NProcessorInfoGetVendorNameEx(NChar * szValue, NInt valueSize);
#endif
#define NProcessorInfoGetVendorNameEx N_FUNC_AW(NProcessorInfoGetVendorNameEx)

NResult N_API NProcessorInfoGetVendor(NProcessorVendor * pValue);
NResult N_API NProcessorInfoGetModelInfo(NInt * pFamily, NInt * pModel, NInt * pStepping);

NResult N_API NProcessorInfoGetModelNameN(HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NProcessorInfoGetModelNameExA(NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NProcessorInfoGetModelNameExW(NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NProcessorInfoGetModelNameEx(NChar * szValue, NInt valueSize);
#endif
#define NProcessorInfoGetModelNameEx N_FUNC_AW(NProcessorInfoGetModelNameEx)

NResult N_API NProcessorInfoIsMmxSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIs3DNowSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSseSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse2SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse3SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSsse3SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsLZCntSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsPopCntSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse41SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse42SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse4aSupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsSse5SupportedEx(NBool * pValue);
NResult N_API NProcessorInfoIsNeonSupported(NBool * pValue);

N_DEPRECATED("function is deprecated, use NProcessorInfoIsMmxSupportedEx instead")
NBool N_API NProcessorInfoIsMmxSupported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIs3DNowSupportedEx instead")
NBool N_API NProcessorInfoIs3DNowSupported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSseSupportedEx instead")
NBool N_API NProcessorInfoIsSseSupported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSse2SupportedEx instead")
NBool N_API NProcessorInfoIsSse2Supported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSse3SupportedEx instead")
NBool N_API NProcessorInfoIsSse3Supported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSsse3SupportedEx instead")
NBool N_API NProcessorInfoIsSsse3Supported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsLZCntSupportedEx instead")
NBool N_API NProcessorInfoIsLZCntSupported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsPopCntSupportedEx instead")
NBool N_API NProcessorInfoIsPopCntSupported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSse41SupportedEx instead")
NBool N_API NProcessorInfoIsSse41Supported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSse42SupportedEx instead")
NBool N_API NProcessorInfoIsSse42Supported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSse4aSupportedEx instead")
NBool N_API NProcessorInfoIsSse4aSupported();
N_DEPRECATED("function is deprecated, use NProcessorInfoIsSse5SupportedEx instead")
NBool N_API NProcessorInfoIsSse5Supported();

#define NProcessorInfoGetVendorNameA(szValue) NProcessorInfoGetVendorNameExA(szValue, N_INT_MAX)
#define NProcessorInfoGetVendorNameW(szValue) NProcessorInfoGetVendorNameExW(szValue, N_INT_MAX)
#define NProcessorInfoGetVendorName(szValue) NProcessorInfoGetVendorNameEx(szValue, N_INT_MAX)
#define NProcessorInfoGetModelNameA(szValue) NProcessorInfoGetModelNameExA(szValue, N_INT_MAX)
#define NProcessorInfoGetModelNameW(szValue) NProcessorInfoGetModelNameExW(szValue, N_INT_MAX)
#define NProcessorInfoGetModelName(szValue) NProcessorInfoGetModelNameEx(szValue, N_INT_MAX)

#ifdef N_MSVC
	#pragma deprecated("NProcessorInfoGetVendorNameA", "NProcessorInfoGetVendorNameW", "NProcessorInfoGetVendorName")
	#pragma deprecated("NProcessorInfoGetModelNameA", "NProcessorInfoGetModelNameW", "NProcessorInfoGetModelName")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_PROCESSOR_INFO_H_INCLUDED
