#ifndef FP_SCANNER_H_INCLUDED
#define FP_SCANNER_H_INCLUDED

#include <NGrayscaleImage.h>
#include <NFScanner.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(FPScanner, NObject)

typedef void (N_CALLBACK FPScannerCallback)(HFPScanner hScanner, void * pParam);
typedef void (N_CALLBACK FPScannerImageScannedCallback)(HFPScanner hScanner, HNGrayscaleImage hImage, void * pParam);

NResult N_API FPScannerGetDevice(HFPScanner hScanner, HNFScanner * phDevice);

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerGetIdN(HFPScanner hScanner, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerGetIdA(HFPScanner hScanner, NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerGetIdW(HFPScanner hScanner, NWChar * szValue);
#endif
#define FPScannerGetId N_FUNC_AW(FPScannerGetId)

N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerIsCapturing(HFPScanner hScanner, NBool * pValue);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerSetIsCapturingChangedCallback(HFPScanner hScanner, FPScannerCallback pCallback, void * pParam);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerSetFingerPlacedCallback(HFPScanner hScanner, FPScannerCallback pCallback, void * pParam);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerSetFingerRemovedCallback(HFPScanner hScanner, FPScannerCallback pCallback, void * pParam);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerSetImageScannedCallback(HFPScanner hScanner, FPScannerImageScannedCallback pCallback, void * pParam);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerStartCapturing(HFPScanner hScanner);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerStartCapturingEx(HFPScanner hScanner, NFImpressionType impressionType);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerStartCapturingForOneImage(HFPScanner hScanner);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerStartCapturingForOneImageEx(HFPScanner hScanner, NFImpressionType impressionType);
N_DEPRECATED("function is deprecated, use NFScanner API instead")
NResult N_API FPScannerStopCapturing(HFPScanner hScanner);

#ifdef N_CPP
}
#endif

#endif // !FP_SCANNER_H_INCLUDED
