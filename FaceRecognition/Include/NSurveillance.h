#ifndef N_SURVEILLANCE_H_INCLUDED
#define N_SURVEILLANCE_H_INCLUDED

#include <CameraMan.h>
#include <NDeviceManager.h>
#include <NCamera.h>
#include <NSurveillanceEventDetails.h>
#include <NSurveillanceParams.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_MODULE(NSurveillance)

#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NSurveillanceModuleOf() instead")
NResult N_API NSurveillanceGetInfoA(NLibraryInfoA * pValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NSurveillanceModuleOf() instead")
NResult N_API NSurveillanceGetInfoW(NLibraryInfoW * pValue);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use NSurveillanceModuleOf() instead")
NResult N_API NSurveillanceGetInfo(NLibraryInfo * pValue);
#endif
#define NSurveillanceGetInfo N_FUNC_AW(NSurveillanceGetInfo)

N_DECLARE_OBJECT_TYPE(NSurveillance, NObject)

typedef enum NSurveillanceEventType_
{
	nsetAny = -1,
	nsetImageCaptured = 1,
	nsetFacesDetected = 2,
	nsetSubjectAppeared = 3,
	nsetSubjectTrack = 4,
	nsetSubjectDisappeared = 5,
} NSurveillanceEventType;

N_DECLARE_TYPE(NSurveillanceEventType)

typedef NResult (N_CALLBACK NSurveillanceEventCallbackEx)(HNSurveillance hSurveillance, NSurveillanceEventType eventType, HNSurveillanceEventDetails hDetails, void * pParam);

NResult N_API NSurveillanceCreate(HNSurveillance * phSurveillance);

NResult N_API NSurveillanceGetDeviceManager(HNSurveillance hSurveillance, HNDeviceManager * phValue);

// Source
NResult N_API NSurveillanceGetSourceCountEx(HNSurveillance hSurveillance, NInt * pCount);
N_DEPRECATED("function is deprecated, use NSurveillanceAddSourceEx2 instead")
NResult N_API NSurveillanceAddSourceEx(HNSurveillance hSurveillance, HCamera hCamera);
NResult N_API NSurveillanceAddSourceEx2(HNSurveillance hSurveillance, HNCamera hSource, NInt * pIndex);
NResult N_API NSurveillanceRemoveSourceEx(HNSurveillance hSurveillance, NInt index);
N_DEPRECATED("function is deprecated, use NSurveillanceGetSourceEx2 instead")
NResult N_API NSurveillanceGetSourceEx(HNSurveillance hSurveillance, NInt index, HCamera * phCamera);
NResult N_API NSurveillanceGetSourceEx2(HNSurveillance hSurveillance, NInt index, HNCamera * phValue);
NResult N_API NSurveillanceClearSourcesEx(HNSurveillance hSurveillance);

// Work
NResult N_API NSurveillanceAddEventEx(HNSurveillance hSurveillance, NSurveillanceEventType eventType, HNCallback hCallback);
NResult N_API NSurveillanceAddEventCallbackEx(HNSurveillance hSurveillance, NSurveillanceEventCallbackEx pCallback, NSurveillanceEventType eventType, void * pParam);
NResult N_API NSurveillanceRemoveEventEx(HNSurveillance hSurveillance, NSurveillanceEventType eventType, HNCallback hCallback);
NResult N_API NSurveillanceRemoveEventCallbackEx(HNSurveillance hSurveillance, NSurveillanceEventCallbackEx pCallback, NSurveillanceEventType eventType, void * pParam);
NResult N_API NSurveillanceAddIsRunningChanged(HNSurveillance hSurveillance, HNCallback hCallback);
NResult N_API NSurveillanceAddIsRunningChangedCallback(HNSurveillance hSurveillance, NObjectCallback pCallback, void * pParam);
NResult N_API NSurveillanceRemoveIsRunningChanged(HNSurveillance hSurveillance, HNCallback hCallback);
NResult N_API NSurveillanceRemoveIsRunningChangedCallback(HNSurveillance hSurveillance, NObjectCallback pCallback, void * pParam);
NResult N_API NSurveillanceStartEx(HNSurveillance hSurveillance);
NResult N_API NSurveillanceStopEx(HNSurveillance hSurveillance);
NResult N_API NSurveillanceIsRunning(HNSurveillance hSurveillance, NBool * pValue);

// Internal database
NResult N_API NSurveillanceAddTemplateExN(HNSurveillance hSurveillance, HNBuffer hTemplate, HNValue hTemplateId);
NResult N_API NSurveillanceAddTemplateExTN(HNSurveillance hSurveillance, HNBuffer hTemplate, const void * templateId);
NResult N_API NSurveillanceAddTemplateExIN(HNSurveillance hSurveillance, const void * pTemplate, NSizeType templateSize, HNValue hTemplateId);
NResult N_API NSurveillanceAddTemplateEx(HNSurveillance hSurveillance, const void * pTemplate, NSizeType templateSize, const void * templateId);
NResult N_API NSurveillanceRemoveTemplateExN(HNSurveillance hSurveillance, HNValue hTemplateId);
NResult N_API NSurveillanceRemoveTemplateEx(HNSurveillance hSurveillance, const void * templateId);
NResult N_API NSurveillanceRemoveAllTemplatesEx(HNSurveillance hSurveillance);
NResult N_API NSurveillanceGetTemplateIdsExN(HNSurveillance hSurveillance, HNValue * arhTemplateIds, NInt templateIdsLength);
NResult N_API NSurveillanceGetTemplateIdsEx(HNSurveillance hSurveillance, const void * * arTemplateIds);

#ifdef N_CPP
}
#endif

#endif // !N_SURVEILLANCE_H_INCLUDED
