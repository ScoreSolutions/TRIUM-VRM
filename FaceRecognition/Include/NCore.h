#ifndef N_CORE_H_INCLUDED
#define N_CORE_H_INCLUDED

#include <NTypes.h>
#include <NError.h>
#include <NMemory.h>
#include <NObject.h>
#include <NModule.h>
#include <NLibraryInfo.h>
#include <NTimeSpan.h>
#include <NDateTime.h>
#include <NStringBuilder.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NCore)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NCoreModuleOf() instead")
NResult N_API NCoreGetInfoA(NLibraryInfoA * pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NCoreModuleOf() instead")
NResult N_API NCoreGetInfoW(NLibraryInfoW * pValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NCoreModuleOf() instead")
NResult N_API NCoreGetInfo(NLibraryInfo * pValue);
#endif
#define NCoreGetInfo N_FUNC_AW(NCoreGetInfo)

NResult N_API NCoreOnStart(void);
NResult N_API NCoreOnThreadStart(void);
NResult N_API NCoreOnThreadExit(void);
NResult N_API NCoreOnExitEx(NBool isProcessTermination);

NResult N_NO_INLINE N_API NCoreGetCallStack(NInt framesToSkip, HNString * phValue);

typedef NResult (N_CALLBACK NErrorSuppressedCallback)(NResult error, HNError hError, void * pParam);

NResult N_API NCoreAddErrorSuppressed(HNCallback hCallback);
NResult N_API NCoreAddErrorSuppressedCallback(NErrorSuppressedCallback pCallback, void * pParam);
NResult N_API NCoreRemoveErrorSuppressed(HNCallback hCallback);
NResult N_API NCoreRemoveErrorSuppressedCallback(NErrorSuppressedCallback pCallback, void * pParam);

#define NCoreOnThreadExitEx(isProcessTermination) NCoreOnThreadExit()
#define NCoreOnExit() NCoreOnExitEx(NFalse)

#ifdef N_MSVC
	#pragma deprecated("NCoreOnThreadExitEx", "NCoreOnExit")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_CORE_H_INCLUDED
