#ifndef N_CAMERA_H_INCLUDED
#define N_CAMERA_H_INCLUDED

#include <NCaptureDevice.h>
#include <NImage.h>
#include <NGeometry.h>
#include <NVideoFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NCameraStatus_
{
	ncsNone = 0,
	ncsOk = 1,
	ncsAutoFocusFailure = 2,
	ncsLensClosed = 3,
	ncsMirrorUp = 4,
	ncsSensorCleaning = 5,
	ncsSilentOperation = 6,
	ncsStroboCharge = 7,
	ncsNoLens = 8,
} NCameraStatus;

N_DECLARE_TYPE(NCameraStatus)

N_DECLARE_OBJECT_TYPE(NCamera, NCaptureDevice)

typedef NResult (N_CALLBACK NCameraStillCapturedCallback)(HNCamera hDevice, HNStream hStream, HNValue hId, HNPropertyBag hProperties, void * pParam);

NResult N_API NCameraGetFrame(HNCamera hDevice, HNImage * phImage);
NResult N_API NCameraIsFocusSupported(HNCamera hDevice, NBool * pValue);
NResult N_API NCameraIsFocusRegionSupported(HNCamera hDevice, NBool * pValue);
NResult N_API NCameraGetFocusRegion(HNCamera hDevice, struct NRectF_ * pValue, NBool * pHasValue);
NResult N_API NCameraSetFocusRegion(HNCamera hDevice, const struct NRectF_ * pValue);
NResult N_API NCameraResetFocus(HNCamera hDevice);
NResult N_API NCameraFocus(HNCamera hDevice, NCameraStatus * pStatus);
NResult N_API NCameraIsStillCaptureSupported(HNCamera hDevice, NBool * pValue);
NResult N_API NCameraGetStillFormats(HNCamera hDevice, HNVideoFormat * * parhFormats, NInt * pFormatCount);
NResult N_API NCameraGetCurrentStillFormat(HNCamera hDevice, HNVideoFormat * phFormat);
NResult N_API NCameraSetCurrentStillFormat(HNCamera hDevice, HNVideoFormat hFormat);
NResult N_API NCameraCaptureStill(HNCamera hDevice, NCameraStatus * pStatus);

NResult N_API NCameraAddStillCaptured(HNCamera hDevice, HNCallback hCallback);
NResult N_API NCameraAddStillCapturedCallback(HNCamera hDevice, NCameraStillCapturedCallback pCallback, void * pParam);
NResult N_API NCameraRemoveStillCaptured(HNCamera hDevice, HNCallback hCallback);
NResult N_API NCameraRemoveStillCapturedCallback(HNCamera hDevice, NCameraStillCapturedCallback pCallback, void * pParam);

#define NCameraStartCapturing(hDevice) NCaptureDeviceStartCapturing(hDevice)
#define NCameraStopCapturing(hDevice) NCaptureDeviceStopCapturing(hDevice)
#define NCameraIsCapturing(hDevice, pValue) NCaptureDeviceIsCapturing(hDevice, pValue)
#define NCameraAddIsCapturingChangedCallback(hDevice, pCallback, pParam) NCaptureDeviceAddIsCapturingChangedCallback(hDevice, pCallback, pParam)
#define NCameraRemoveIsCapturingChangedCallback(hDevice, pCallback, pParam) NCaptureDeviceRemoveIsCapturingChangedCallback(hDevice, pCallback, pParam)

#ifdef N_MSVC
	#pragma deprecated("NCameraStartCapturing", "NCameraStopCapturing", "NCameraIsCapturing")
	#pragma deprecated("NCameraAddIsCapturingChangedCallback", "NCameraRemoveIsCapturingChangedCallback")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_CAMERA_H_INCLUDED
