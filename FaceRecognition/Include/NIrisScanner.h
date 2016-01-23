#ifndef N_IRIS_SCANNER_H_INCLUDED
#define N_IRIS_SCANNER_H_INCLUDED

#include <NBiometricDevice.h>
#include <NImage.h>
#include <NEAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NIrisScanner, NBiometricDevice)

typedef NResult (N_CALLBACK NIrisScannerPreviewCallback)(HNIrisScanner hDevice, HNImage hImage, NBiometricStatus * pStatus, const HNEAttributes * arhObjects, NInt objectCount, void * pParam);

NResult N_API NIrisScannerGetSupportedPositions(HNIrisScanner hDevice, NEPosition * arValue, NInt valueLength);
NResult N_API NIrisScannerCapture(HNIrisScanner hDevice, NEPosition position, NInt timeoutMilliseconds, HNImage * phImage);
NResult N_API NIrisScannerCaptureEx(HNIrisScanner hDevice, NEPosition position, const NEPosition * arMissingPositions, NInt missingPositionCount,
	NBool automatic, NInt timeoutMilliseconds, NBiometricStatus * pStatus, HNEAttributes * * parhObjects, NInt * pObjectCount, HNImage * phImage);

NResult N_API NIrisScannerAddPreview(HNIrisScanner hDevice, HNCallback hCallback);
NResult N_API NIrisScannerAddPreviewCallback(HNIrisScanner hDevice, NIrisScannerPreviewCallback pCallback, void * pParam);
NResult N_API NIrisScannerRemovePreview(HNIrisScanner hDevice, HNCallback hCallback);
NResult N_API NIrisScannerRemovePreviewCallback(HNIrisScanner hDevice, NIrisScannerPreviewCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_IRIS_SCANNER_H_INCLUDED
