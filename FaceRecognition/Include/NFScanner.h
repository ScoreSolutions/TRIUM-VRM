#ifndef NF_SCANNER_H_INCLUDED
#define NF_SCANNER_H_INCLUDED

#include <NBiometricDevice.h>
#include <NGeometry.h>
#include <NImage.h>
#include <NFAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFScanner, NBiometricDevice)

typedef NResult (N_CALLBACK NFScannerPreviewCallback)(HNFScanner hDevice, HNImage hImage, NBiometricStatus * pStatus, const HNFAttributes * arhObjects, NInt objectCount, void * pParam);

NResult N_API NFScannerGetSupportedImpressionTypes(HNFScanner hDevice, NFImpressionType * arValue, NInt valueLength);
NResult N_API NFScannerGetSupportedPositions(HNFScanner hDevice, NFPosition * arValue, NInt valueLength);
NResult N_API NFScannerCapture(HNFScanner hDevice, NInt timeoutMilliseconds, HNImage * phImage);
NResult N_API NFScannerCaptureEx(HNFScanner hDevice, NFImpressionType impressionType, NFPosition position, const NFPosition * arMissingPositions, NInt missingPositionCount,
	NBool automatic, NInt timeoutMilliseconds, NBiometricStatus * pStatus, HNFAttributes * * parhObjects, NInt * pObjectCount, HNImage * phImage);

NResult N_API NFScannerAddPreview(HNFScanner hDevice, HNCallback hCallback);
NResult N_API NFScannerAddPreviewCallback(HNFScanner hDevice, NFScannerPreviewCallback pCallback, void * pParam);
NResult N_API NFScannerRemovePreview(HNFScanner hDevice, HNCallback hCallback);
NResult N_API NFScannerRemovePreviewCallback(HNFScanner hDevice, NFScannerPreviewCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !NF_SCANNER_H_INCLUDED
