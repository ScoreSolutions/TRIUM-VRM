#ifndef N_ERROR_H_INCLUDED
#define N_ERROR_H_INCLUDED

#include <NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

#ifndef N_NO_ERROR_CODES

#define N_OK                               0
#define N_E_FAILED                        -1
  #define N_E_CORE                        -2
    #define N_E_ABANDONED_MUTEX          -25
    #define N_E_ARGUMENT                 -10
      #define N_E_ARGUMENT_NULL          -11
      #define N_E_ARGUMENT_OUT_OF_RANGE  -12
      #define N_E_INVALID_ENUM_ARGUMENT  -16
    #define N_E_ARITHMETIC               -17
      #define N_E_OVERFLOW                -8
    #define N_E_BAD_IMAGE_FORMAT         -26
    #define N_E_DLL_NOT_FOUND            -27
    #define N_E_ENTRY_POINT_NOT_FOUND    -28
    #define N_E_FORMAT                   -13
      #define N_E_FILE_FORMAT            -29
    #define N_E_INDEX_OUT_OF_RANGE        -9
    #define N_E_INVALID_CAST             -18
    #define N_E_INVALID_OPERATION         -7
    #define N_E_IO                       -14
      #define N_E_DIRECTORY_NOT_FOUND    -19
      #define N_E_DRIVE_NOT_FOUND        -20
      #define N_E_END_OF_STREAM          -15
      #define N_E_FILE_NOT_FOUND         -21
      #define N_E_FILE_LOAD              -22
      #define N_E_PATH_TOO_LONG          -23
      #define N_E_SOCKET                 -31
    #define N_E_KEY_NOT_FOUND            -32
    #define N_E_NOT_IMPLEMENTED           -5
    #define N_E_NOT_SUPPORTED             -6
    #define N_E_NULL_REFERENCE            -3
    #define N_E_OUT_OF_MEMORY             -4
    #define N_E_SECURITY                 -24
    #define N_E_TIMEOUT                  -30

    #define N_E_EXTERNAL                 -90
      #define N_E_CLR                    -93
      #define N_E_COM                    -92
      #define N_E_CPP                    -96
      #define N_E_JVM                    -97
      #define N_E_MAC                    -95
      #define N_E_SYS                    -94
      #define N_E_WIN32                  -91

    #define N_E_PARAMETER               -100
      #define N_E_PARAMETER_READ_ONLY   -101

    #define N_E_NOT_ACTIVATED           -200

#endif // !N_NO_ERROR_CODES

#define NFailed(result) ((result) < 0)
#define NSucceeded(result) ((result) >= 0)

#define NE_PRESERVE_INNER_ERROR 0x00000001
#define NE_NO_CALL_STACK        0x00000002
#define NE_MERGE_CALL_STACK     0x00000004
#define NE_IS_DIRECTORY_ACCESS  0x00000100
#define NE_SKIP_ONE_FRAME       0x01000000

struct NCallStackEntry_
{
	void * addr;
	HNString hFunction;
	HNString hFile;
	NInt line;
};
#if !defined(N_ERROR_HPP_INCLUDED) && !defined(N_OBJECT_HPP_INCLUDED)
typedef struct NCallStackEntry_ NCallStackEntry;
#endif
N_DECLARE_TYPE(NCallStackEntry)

NResult N_API NCallStackEntryCreateN(void * addr, HNString hFunction, HNString hFile, NInt line, struct NCallStackEntry_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NCallStackEntryCreateA(void * addr, const NAChar * szFunction, const NAChar * szFile, NInt line, struct NCallStackEntry_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NCallStackEntryCreateW(void * addr, const NWChar * szFunction, const NWChar * szFile, NInt line, struct NCallStackEntry_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NCallStackEntryCreate(void * addr, const NChar * szFunction, const NChar * szFile, NInt line, NCallStackEntry * pValue);
#endif
#define NCallStackEntryCreate N_FUNC_AW(NCallStackEntryCreate)

NResult N_API NCallStackEntryDispose(struct NCallStackEntry_ * pValue);
NResult N_API NCallStackEntryCopy(const struct NCallStackEntry_ * pSrcValue, struct NCallStackEntry_ * pDstValue);
NResult N_API NCallStackEntrySet(const struct NCallStackEntry_ * pSrcValue, struct NCallStackEntry_ * pDstValue);

N_DECLARE_OBJECT_TYPE(NError, NObject)

NInt N_API NErrorGetLastSysError(void);
NUInt N_API NErrorGetLastWin32Error(void);

NResult N_API NErrorGetDefaultMessageN(NResult code, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetDefaultMessageExA(NResult code, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetDefaultMessageExW(NResult code, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetDefaultMessageEx(NResult code, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetDefaultMessageEx N_FUNC_AW(NErrorGetDefaultMessageEx)

NResult N_API NErrorGetSysErrorMessageN(NInt errnum, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetSysErrorMessageExA(NInt errnum, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetSysErrorMessageExW(NInt errnum, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetSysErrorMessageEx(NInt errnum, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetSysErrorMessageEx N_FUNC_AW(NErrorGetSysErrorMessageEx)

NResult N_API NErrorGetMachErrorMessageN(NInt err, HNString * phValue);

NResult N_API NErrorGetMacErrorMessageN(NInt err, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetMacErrorMessageExA(NInt err, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetMacErrorMessageExW(NInt err, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetMacErrorMessageEx(NInt err, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetMacErrorMessageEx N_FUNC_AW(NErrorGetMacErrorMessageEx)

NResult N_API NErrorGetWin32ErrorMessageN(NUInt errorCode, HNString * phValue);

NResult N_NO_INLINE N_API NErrorSetLastEx(HNError hError, NUInt flags);

NResult N_NO_INLINE N_API NErrorSetLastN(NResult code, HNString hMessage, HNString hParam, NInt externalError, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetLastMPNA(NResult code, HNString hMessage, HNString hParam, NInt externalError, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetLastMPNW(NResult code, HNString hMessage, HNString hParam, NInt externalError, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetLastMPN(NResult code, HNString hMessage, HNString hParam, NInt externalError, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetLastMPN N_FUNC_AW(NErrorSetLastMPN)
NResult N_NO_INLINE N_API NErrorSetLastPNA(NResult code, const NAChar * szMessage, HNString hParam, NInt externalError, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetLastPNW(NResult code, const NWChar * szMessage, HNString hParam, NInt externalError, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetLastPN(NResult code, const NChar * szMessage, HNString hParam, NInt externalError, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetLastPN N_FUNC_AW(NErrorSetLastPN)
NResult N_NO_INLINE N_API NErrorSetLastA(NResult code, const NAChar * szMessage, const NAChar * szParam, NInt externalError, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetLastW(NResult code, const NWChar * szMessage, const NWChar * szParam, NInt externalError, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetLast(NResult code, const NChar * szMessage, const NChar * szParam, NInt externalError, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetLast N_FUNC_AW(NErrorSetLast)

NResult N_NO_INLINE N_API NErrorSetComN(NInt comError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetComMPNA(NInt comError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetComMPNW(NInt comError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetComMPN(NInt comError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetComMPN N_FUNC_AW(NErrorSetComMPN)
NResult N_NO_INLINE N_API NErrorSetComPNA(NInt comError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetComPNW(NInt comError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetComPN(NInt comError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetComPN N_FUNC_AW(NErrorSetComPN)
NResult N_NO_INLINE N_API NErrorSetComA(NInt comError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetComW(NInt comError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetCom(NInt comError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetCom N_FUNC_AW(NErrorSetCom)

NResult N_NO_INLINE N_API NErrorSetMachN(NInt32 machError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetMachMPNA(NInt32 machError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMachMPNW(NInt32 machError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMachMPN(NInt32 machError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMachMPN N_FUNC_AW(NErrorSetMachMPN)
NResult N_NO_INLINE N_API NErrorSetMachPNA(NInt32 machError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMachPNW(NInt32 machError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMachPN(NInt32 machError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMachPN N_FUNC_AW(NErrorSetMachPN)
NResult N_NO_INLINE N_API NErrorSetMachA(NInt32 machError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMachW(NInt32 machError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMach(NInt32 machError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMach N_FUNC_AW(NErrorSetMach)

NResult N_NO_INLINE N_API NErrorSetMacN(NInt macError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetMacMPNA(NInt macError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMacMPNW(NInt macError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorSetMacMPN(NInt macError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMacMPN N_FUNC_AW(NErrorSetMacMPN)
NResult N_NO_INLINE N_API NErrorSetMacPNA(NInt macError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMacPNW(NInt macError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMacPN(NInt macError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMacPN N_FUNC_AW(NErrorSetMacPN)
NResult N_NO_INLINE N_API NErrorSetMacA(NInt macError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetMacW(NInt macError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetMac(NInt macError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetMac N_FUNC_AW(NErrorSetMac)

NResult N_NO_INLINE N_API NErrorSetSysN(NInt sysError, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetSysMPNA(NInt sysError, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetSysMPNW(NInt sysError, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetSysMPN(NInt sysError, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetSysMPN N_FUNC_AW(NErrorSetSysMPN)
NResult N_NO_INLINE N_API NErrorSetSysPNA(NInt sysError, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetSysPNW(NInt sysError, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetSysPN(NInt sysError, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetSysPN N_FUNC_AW(NErrorSetSysPN)
NResult N_NO_INLINE N_API NErrorSetSysA(NInt sysError, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetSysW(NInt sysError, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetSys(NInt sysError, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetSys N_FUNC_AW(NErrorSetSys)

NResult N_NO_INLINE N_API NErrorSetWin32N(NUInt win32Error, HNString hMessage, HNString hParam, HNString hExternalCallStack, NUInt flags);
NResult N_NO_INLINE N_API NErrorSetWin32MPNA(NUInt win32Error, HNString hMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetWin32MPNW(NUInt win32Error, HNString hMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetWin32MPN(NUInt win32Error, HNString hMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetWin32MPN N_FUNC_AW(NErrorSetWin32MPN)
NResult N_NO_INLINE N_API NErrorSetWin32PNA(NUInt win32Error, const NAChar * szMessage, HNString hParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetWin32PNW(NUInt win32Error, const NWChar * szMessage, HNString hParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetWin32PN(NUInt win32Error, const NChar * szMessage, HNString hParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetWin32PN N_FUNC_AW(NErrorSetWin32PN)
NResult N_NO_INLINE N_API NErrorSetWin32A(NUInt win32Error, const NAChar * szMessage, const NAChar * szParam, const NAChar * szExternalCallStack, NUInt flags);
#ifndef N_NO_UNICODE
NResult N_NO_INLINE N_API NErrorSetWin32W(NUInt win32Error, const NWChar * szMessage, const NWChar * szParam, const NWChar * szExternalCallStack, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_NO_INLINE N_API NErrorSetWin32(NUInt win32Error, const NChar * szMessage, const NChar * szParam, const NChar * szExternalCallStack, NUInt flags);
#endif
#define NErrorSetWin32 N_FUNC_AW(NErrorSetWin32)

void N_NO_INLINE N_API NErrorAppendN(void * addr, HNString hFunction, HNString hFile, NInt line);
void N_NO_INLINE N_API NErrorAppendA(void * addr, const NAChar * szFunction, const NAChar * szFile, NInt line);
#ifndef N_NO_UNICODE
void N_NO_INLINE N_API NErrorAppendW(void * addr, const NAChar * szFunction, const NWChar * szFile, NInt line);
#endif
#ifdef N_DOCUMENTATION
void N_NO_INLINE N_API NErrorAppend(void * addr, const NAChar * szFunction, const NChar * szFile, NInt line);
#endif
#define NErrorAppend N_FUNC_AW(NErrorAppend)

NResult N_NO_INLINE N_API NErrorReport(NResult res);
NResult N_NO_INLINE N_API NErrorReportEx(NResult errorCode, HNError hError);
void N_NO_INLINE N_API NErrorSuppress(NResult result);

N_DEPRECATED("function is deprecated, use NErrorGetLastEx instead.")
HNError N_API NErrorGetLast();
NResult N_API NErrorGetLastEx(NUInt flags, HNError * phError);

N_DEPRECATED("function is deprecated, use NErrorGetCodeEx instead.")
NResult N_API NErrorGetCode(HNError hError);
NResult N_API NErrorGetCodeEx(HNError hError, NResult * pValue);

NResult N_API NErrorGetMessageN(HNError hError, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetMessageExA(HNError hError, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetMessageExW(HNError hError, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetMessageEx(HNError hError, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetMessageEx N_FUNC_AW(NErrorGetMessageEx)

NResult N_API NErrorGetParamN(HNError hError, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetParamExA(HNError hError, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetParamExW(HNError hError, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetParamEx(HNError hError, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetParamEx N_FUNC_AW(NErrorGetParamEx)

N_DEPRECATED("function is deprecated, use NErrorGetExternalErrorEx instead.")
NInt N_API NErrorGetExternalError(HNError hError);
NResult N_API NErrorGetExternalErrorEx(HNError hError, NInt * pValue);

NResult N_API NErrorGetExternalCallStackN(HNError hError, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetExternalCallStackExA(HNError hError, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetExternalCallStackExW(HNError hError, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetExternalCallStackEx(HNError hError, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetExternalCallStackEx N_FUNC_AW(NErrorGetExternalCallStackEx)

N_DEPRECATED("function is deprecated, use NErrorGetCallStackCount instead.")
NInt N_API NErrorGetCallStackLength(HNError hError);
NResult N_API NErrorGetCallStackCount(HNError hError, NInt * pValue);

NResult N_API NErrorGetCallStackEntry(HNError hError, NInt index, struct NCallStackEntry_ * pValue);

#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetCallStackFunctionExA(HNError hError, NInt index, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetCallStackFunctionExW(HNError hError, NInt index, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetCallStackFunctionEx(HNError hError, NInt index, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetCallStackFunctionEx N_FUNC_AW(NErrorGetCallStackFunctionEx)

#ifndef N_NO_ANSI_FUNC
NResult N_API NErrorGetCallStackFileExA(HNError hError, NInt index, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NErrorGetCallStackFileExW(HNError hError, NInt index, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NErrorGetCallStackFileEx(HNError hError, NInt index, NChar * szValue, NInt valueSize);
#endif
#define NErrorGetCallStackFileEx N_FUNC_AW(NErrorGetCallStackFileEx)

N_DEPRECATED("function is deprecated, use NErrorGetCallStackLineEx instead.")
NInt N_API NErrorGetCallStackLine(HNError hError, NInt index);
NResult N_API NErrorGetCallStackLineEx(HNError hError, NInt index, NInt * pValue);
NResult N_API NErrorGetCallStackN(HNError hError, HNString * phValue);
N_DEPRECATED("function is deprecated, use NErrorGetInnerErrorEx instead.")
HNError N_API NErrorGetInnerError(HNError hError);
NResult N_API NErrorGetInnerErrorEx(HNError hError, HNError * phValue);

#define NErrorGetComError(hError) (NErrorGetCode(hError) == N_E_COM ? NErrorGetExternalError(HNError hError) : 0)
#define NErrorGetSysError(hError) (NErrorGetCode(hError) == N_E_SYS ? NErrorGetExternalError(HNError hError) : 0)
#define NErrorGetWin32Error(hError) (NErrorGetCode(hError) == N_E_WIN32 ? (NUInt)NErrorGetExternalError(HNError hError) : 0)
#define NErrorGetClrError(hError) NULL

#define NErrorGetDefaultMessageA(code, szValue) NErrorGetDefaultMessageExA(code, szValue, N_INT_MAX)
#define NErrorGetDefaultMessageW(code, szValue) NErrorGetDefaultMessageExW(code, szValue, N_INT_MAX)
#define NErrorGetDefaultMessage(code, szValue) NErrorGetDefaultMessageEx(code, szValue, N_INT_MAX)
#define NErrorGetSysErrorMessageA(errnum, szValue) NErrorGetSysErrorMessageExA(errnum, szValue, N_INT_MAX)
#define NErrorGetSysErrorMessageW(errnum, szValue) NErrorGetSysErrorMessageExW(errnum, szValue, N_INT_MAX)
#define NErrorGetSysErrorMessage(errnum, szValue) NErrorGetSysErrorMessageEx(errnum, szValue, N_INT_MAX)
#define NErrorGetMacErrorMessageA(err, szValue) NErrorGetMacErrorMessageExA(err, szValue, N_INT_MAX)
#define NErrorGetMacErrorMessageW(err, szValue) NErrorGetMacErrorMessageExW(err, szValue, N_INT_MAX)
#define NErrorGetMacErrorMessage(err, szValue) NErrorGetMacErrorMessageEx(err, szValue, N_INT_MAX)
#define NErrorGetMessageA(hError, szValue) NErrorGetMessageExA(hError, szValue, N_INT_MAX)
#define NErrorGetMessageW(hError, szValue) NErrorGetMessageExW(hError, szValue, N_INT_MAX)
#define NErrorGetMessage(hError, szValue) NErrorGetMessageEx(hError, szValue, N_INT_MAX)
#define NErrorGetParamA(hError, szValue) NErrorGetParamExA(hError, szValue, N_INT_MAX)
#define NErrorGetParamW(hError, szValue) NErrorGetParamExW(hError, szValue, N_INT_MAX)
#define NErrorGetParam(hError, szValue) NErrorGetParamEx(hError, szValue, N_INT_MAX)
#define NErrorGetExternalCallStackA(hError, szValue) NErrorGetExternalCallStackExA(hError, szValue, N_INT_MAX)
#define NErrorGetExternalCallStackW(hError, szValue) NErrorGetExternalCallStackExW(hError, szValue, N_INT_MAX)
#define NErrorGetExternalCallStack(hError, szValue) NErrorGetExternalCallStackEx(hError, szValue, N_INT_MAX)
#define NErrorGetCallStackFunctionA(hError, index, szValue) NErrorGetCallStackFunctionExA(hError, index, szValue, N_INT_MAX)
#define NErrorGetCallStackFunctionW(hError, index, szValue) NErrorGetCallStackFunctionExW(hError, index, szValue, N_INT_MAX)
#define NErrorGetCallStackFunction(hError, index, szValue) NErrorGetCallStackFunctionEx(hError, index, szValue, N_INT_MAX)
#define NErrorGetCallStackFileA(hError, index, szValue) NErrorGetCallStackFileExA(hError, index, szValue, N_INT_MAX)
#define NErrorGetCallStackFileW(hError, index, szValue) NErrorGetCallStackFileExW(hError, index, szValue, N_INT_MAX)
#define NErrorGetCallStackFile(hError, index, szValue) NErrorGetCallStackFileEx(hError, index, szValue, N_INT_MAX)

#ifdef N_MSVC
	#pragma deprecated("NErrorGetDefaultMessageA", "NErrorGetDefaultMessageW", "NErrorGetDefaultMessage")
	#pragma deprecated("NErrorGetSysErrorMessageA", "NErrorGetSysErrorMessageW", "NErrorGetSysErrorMessage")
	#pragma deprecated("NErrorGetMacErrorMessageA", "NErrorGetMacErrorMessageW", "NErrorGetMacErrorMessage")
	#pragma deprecated("NErrorGetMessageA", "NErrorGetMessageW", "NErrorGetMessage")
	#pragma deprecated("NErrorGetParamA", "NErrorGetParamW", "NErrorGetParam")
	#pragma deprecated("NErrorGetExternalCallStackA", "NErrorGetExternalCallStackW", "NErrorGetExternalCallStack")
	#pragma deprecated("NErrorGetCallStackFunctionA", "NErrorGetCallStackFunctionW", "NErrorGetCallStackFunction")
	#pragma deprecated("NErrorGetCallStackFileA", "NErrorGetCallStackFileW", "NErrorGetCallStackFile")
	#pragma deprecated("NErrorGetComError", "NErrorGetSysError", "NErrorGetWin32Error", "NErrorGetClrError")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_ERROR_H_INCLUDED
