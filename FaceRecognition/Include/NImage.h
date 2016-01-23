#ifndef N_IMAGE_H_INCLUDED
#define N_IMAGE_H_INCLUDED

#include <NPixelFormat.h>
#include <NObject.h>
#include <NArray.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImage, NObject)
N_DECLARE_OBJECT_TYPE(NGrayscaleImage, NImage)
N_DECLARE_OBJECT_TYPE(NMonochromeImage, NImage)
N_DECLARE_OBJECT_TYPE(NRgbImage, NImage)

#ifdef N_CPP
}
#endif

#include <NImageInfo.h>
#include <NImageFormat.h>

#include <NImageDefWinTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NI_READ_UNKNOWN_IMAGE      0x00000001
#define NI_WRITE_UNKNOWN_IMAGE     0x00000001
#define NI_DST_SWAP_CHANNELS       0x00000100
#define NI_DST_ALPHA_CHANNEL_FIRST 0x00000200
#define NI_DST_BOTTOM_TO_TOP       0x00000400
#define NI_SRC_SWAP_CHANNELS       0x00001000
#define NI_SRC_ALPHA_CHANNEL_FIRST 0x00002000
#define NI_SRC_BOTTOM_TO_TOP       0x00004000

#define NI_ALL_DST 0x00000F00
#define NI_ALL_SRC 0x0000F000
#define NI_ALL_DST_AND_SRC (NI_ALL_DST | NI_ALL_SRC)

typedef enum NImageRotateFlipType_
{
	nirftRotateNone = 0,
	nirftRotate90 = 1,
	nirftRotate180 = 2,
	nirftRotate270 = 3,
	nirftFlipNone = 0,
	nirftFlipX = 4,
	nirftFlipY = 8,
	nirftFlipXY = nirftFlipX | nirftFlipY,
	nirftNone = nirftRotateNone | nirftFlipNone
} NImageRotateFlipType;

N_DECLARE_TYPE(NImageRotateFlipType)

N_DEPRECATED("function is deprecated, use NImageCreateWrapperExN, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateWrapperN(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	HNBuffer hPixels, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateWrapperEx, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateWrapper(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	void * pPixels, NBool ownsPixels, HNImage * phImage);
NResult N_API NImageCreateWrapperExN(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride,
	HNBuffer hPixels, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateWrapperEx(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride,
	void * pPixels, NSizeType pixelsSize, NBool ownsPixels, NUInt flags, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateWrapperForPartExN, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateWrapperForPartN(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	HNBuffer hPixels, NUInt left, NUInt top, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateWrapperForPartEx, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateWrapperForPart(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	void * pPixels, NUInt left, NUInt top, HNImage * phImage);
NResult N_API NImageCreateWrapperForPartExN(NPixelFormat_ pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
	HNBuffer hPixels, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateWrapperForPartEx(NPixelFormat_ pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
	void * pPixels, NSizeType pixelsSize, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateWrapperForPlanesPartN(NPixelFormat_ pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
	HNBuffer * arhPlanes, NInt planeCount, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateWrapperForPlanesPart(NPixelFormat_ pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
	void * const * arpPlanes, const NSizeType * arPlaneSizes, NInt planeCount, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageCreateWrapperForImagePartEx2, NImageSetHorzResolution, NImageSetVertResolution and NImageSetResolutionIsAspectRatio instead")
NResult N_API NImageCreateWrapperForImagePartEx(HNImage hSrcImage, NUInt left, NUInt top, NUInt width, NUInt height,
	NFloat horzResolution, NFloat vertResolution, HNImage * phImage);
NResult N_API NImageCreateWrapperForImagePartEx2(HNImage hSrcImage, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageCreateEx, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreate(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution, HNImage * phImage);
NResult N_API NImageCreateEx(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NUInt flags, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageCreateFromDataExN, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateFromDataN(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	NSizeType srcStride, HNBuffer hSrcPixels, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromDataEx, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateFromData(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	NSizeType srcStride, const void * pSrcPixels, HNImage * phImage);
NResult N_API NImageCreateFromDataExN(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride,
	NSizeType srcStride, HNBuffer hSrcPixels, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateFromDataEx(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride,
	NSizeType srcStride, const void * pSrcPixels, NSizeType srcPixelsSize, NUInt flags, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromDataPartExN, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateFromDataPartN(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	NSizeType srcStride, HNBuffer hSrcPixels, NUInt left, NUInt top, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromDataPartEx, NImageSetHorzResolution and NImageSetVertResolution instead")
NResult N_API NImageCreateFromDataPart(NPixelFormat_ pixelFormat, NUInt width, NUInt height, NSizeType stride, NFloat horzResolution, NFloat vertResolution,
	NSizeType srcStride, const void * pSrcPixels, NUInt left, NUInt top, HNImage * phImage);
NResult N_API NImageCreateFromDataPartExN(NPixelFormat_ pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight,
	NSizeType srcStride, HNBuffer hSrcPixels, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateFromDataPartEx(NPixelFormat_ pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight,
	NSizeType srcStride, const void * pSrcPixels, NSizeType srcPixelsSize, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateFromDataPlanesPartN(NPixelFormat_ pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight,
	NSizeType srcStride, HNBuffer * arhSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateFromDataPlanesPart(NPixelFormat_ pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight,
	NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags, HNImage * phImage);

N_DEPRECATED("function is deprecated, use NImageCreateFromImageEx2, NImageToGrayscale, NImageToMonochrome or NImageToRgb and NImageSetHorzResolution, NImageSetVertResolution and NImageSetResolutionIsAspectRatio instead")
NResult N_API NImageCreateFromImageEx(NPixelFormat_ pixelFormat, NSizeType stride, NFloat horzResolution, NFloat vertResolution, HNImage hSrcImage, HNImage * phImage);
NResult N_API NImageCreateFromImageEx2(NPixelFormat_ pixelFormat, NSizeType stride, HNImage hSrcImage, NUInt flags, HNImage * phImage);
N_DEPRECATED("function is deprecated, use NImageCreateFromImagePartEx2, NImageSetHorzResolution, NImageSetVertResolution and NImageSetResolutionIsAspectRatio instead")
NResult N_API NImageCreateFromImagePartEx(NPixelFormat_ pixelFormat, NSizeType stride, NFloat horzResolution, NFloat vertResolution, HNImage hSrcImage,
	NUInt left, NUInt top, NUInt width, NUInt height, HNImage * phImage);
NResult N_API NImageCreateFromImagePartEx2(NPixelFormat_ pixelFormat, NSizeType stride, HNImage hSrcImage,
	NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags, HNImage * phImage);

NResult N_API NImageCreateFromFileExN(HNString hFileName, HNImageFormat hImageFormat, NUInt flags, HNImageInfo * phInfo, HNImage * phImage);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageCreateFromFileExA(const NAChar * szFileName, HNImageFormat hImageFormat, NUInt flags, HNImageInfo * phInfo, HNImage * phImage);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageCreateFromFileExW(const NWChar * szFileName, HNImageFormat hImageFormat, NUInt flags, HNImageInfo * phInfo, HNImage * phImage);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageCreateFromFileEx(const NChar * szFileName, HNImageFormat hImageFormat, NUInt flags, HNImageInfo * phInfo, HNImage * phImage);
#endif
#define NImageCreateFromFileEx N_FUNC_AW(NImageCreateFromFileEx)

NResult N_API NImageCreateFromMemoryN(HNBuffer hBuffer, HNImageFormat hImageFormat, NUInt flags, NSizeType * pSize, HNImageInfo * phInfo, HNImage * phImage);
NResult N_API NImageCreateFromMemory(const void * pBuffer, NSizeType bufferSize, HNImageFormat hImageFormat, NUInt flags, NSizeType * pSize, HNImageInfo * phInfo, HNImage * phImage);
NResult N_API NImageCreateFromStream(HNStream hStream, HNImageFormat hImageFormat, NUInt flags, HNImageInfo * phInfo, HNImage * phImage);

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
NResult N_API NImageCreateFromHBitmap(HBITMAP hBitmap, NUInt flags, HNImage * phImage);
NResult N_API NImageCreateFromBitmapInfoAndBits(BITMAPINFO * pBitmapInfo, NSizeType bitmapInfoSize, const void * pBits, NSizeType bitsSize, NUInt flags, HNImage * phImage);
#endif

NResult N_API NImageCopyDataPlanesExN(
	NPixelFormat_ srcPixelFormat, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	HNBuffer hSrcPalette, NInt srcPaletteLength, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const HNBuffer * arhSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NPixelFormat_ dstPixelFormat,HNArray hDstMinValue, HNArray hDstMaxValue,
	HNBuffer hDstPalette, NInt dstPaletteLength, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, const HNBuffer * arhDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
	NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyDataPlanesEx(
	NPixelFormat_ srcPixelFormat, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	const void * pSrcPalette, NSizeType srcPaletteSize, NInt srcPaletteLength, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NPixelFormat_ dstPixelFormat, HNArray hDstMinValue, HNArray hDstMaxValue,
	const void * pDstPalette, NSizeType dstPaletteSize, NInt dstPaletteLength, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
	NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyDataPlanesN(NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const HNBuffer * arhSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, const HNBuffer * arhDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
	NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyDataPlanes(NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
	NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyDataN(NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, HNBuffer hSrcPixels, NUInt srcLeft, NUInt srcTop,
	NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, HNBuffer hDstPixels, NUInt dstLeft, NUInt dstTop,
	NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyData(NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * pSrcPixels, NSizeType srcPixelsSize, NUInt srcLeft, NUInt srcTop,
	NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * pDstPixels, NSizeType dstPixelsSizes, NUInt dstLeft, NUInt dstTop,
	NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopy(HNImage hSrcImage, NUInt left, NUInt top, NUInt width, NUInt height, HNImage hDstImage, NUInt dstLeft, NUInt dstTop);

NResult N_API NImageCopyFromDataN(HNImage hImage, NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
	HNBuffer hSrcPixels, NUInt left, NUInt top, NUInt flags);
NResult N_API NImageCopyFromData(HNImage hImage, NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
	const void * pSrcPixels, NSizeType srcPixelsSize, NUInt left, NUInt top, NUInt flags);
NResult N_API NImageCopyFromDataPartN(HNImage hImage, NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
	HNBuffer hSrcPixels, NUInt srcLeft, NUInt srcTop,
	NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyFromDataPart(HNImage hImage, NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
	const void * pSrcPixels, NSizeType srcPixelsSize, NUInt srcLeft, NUInt srcTop,
	NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyFromDataPlanesPartN(HNImage hImage, NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
	const HNBuffer * arhSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyFromDataPlanesPart(HNImage hImage, NPixelFormat_ srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
	const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyFromDataPlanesPartExN(HNImage hImage,
	NPixelFormat_ srcPixelFormat, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	HNBuffer hSrcPalette, NInt srcPaletteLength, NUInt srcWidth, NUInt srcHeight,
	NSizeType srcStride, const HNBuffer * arhSrcPlanes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyFromDataPlanesPartEx(HNImage hImage,
	NPixelFormat_ srcPixelFormat, HNArray hSrcMinValue, HNArray hSrcMaxValue,
	const void * pSrcPalette, NSizeType srcPaletteSize, NInt srcPaletteLength, NUInt srcWidth, NUInt srcHeight,
	NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
	NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags);

NResult N_API NImageCopyToDataN(HNImage hImage, NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight,
	NSizeType dstStride, HNBuffer hDstPixels, NUInt dstLeft, NUInt dstTop, NUInt flags);
NResult N_API NImageCopyToData(HNImage hImage, NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight,
	NSizeType dstStride, void * pDstPixels, NSizeType dstPixelsSize, NUInt dstLeft, NUInt dstTop, NUInt flags);
NResult N_API NImageCopyToDataPartN(HNImage hImage, NUInt left, NUInt top, NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
	HNBuffer hDstPixels, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyToDataPart(HNImage hImage, NUInt left, NUInt top, NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
	void * pDstPixels, NSizeType dstPixelsSize, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyToDataPlanesPartN(HNImage hImage, NUInt left, NUInt top, NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
	const HNBuffer * arhDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyToDataPlanesPart(HNImage hImage, NUInt left, NUInt top, NPixelFormat_ dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
	void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyToDataPlanesPartExN(HNImage hImage, NUInt left, NUInt top,
	NPixelFormat_ dstPixelFormat, HNArray hDstMinValue, HNArray hDstMaxValue,
	HNBuffer hDstPalette, NInt dstPaletteLength, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
	const HNBuffer * arhDstPlanes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyToDataPlanesPartEx(HNImage hImage, NUInt left, NUInt top,
	NPixelFormat_ dstPixelFormat, HNArray hDstMinValue, HNArray hDstMaxValue,
	const void * pDstPalette, NSizeType dstPaletteSize, NInt dstPaletteLength, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
	void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags);
NResult N_API NImageCopyTo(HNImage hImage, HNImage hDstImage, NUInt dstLeft, NUInt dstTop);

NResult N_API NImageExportPalette(HNImage hImage,
	NPixelFormat_ dstPixelFormat, HNArray hDstMinValue, HNArray hDstMaxValue,
	NUInt flags, NInt * pPaletteLength, HNBuffer * phPalette);

NResult N_API NImageSaveToFileExN(HNImage hImage, HNString hFileName, HNImageFormat hImageFormat, HNImageInfo hInfo, NUInt flags);
#ifndef N_NO_ANSI_FUNC
NResult N_API NImageSaveToFileExA(HNImage hImage, const NAChar * szFileName, HNImageFormat hImageFormat, HNImageInfo hInfo, NUInt flags);
#endif
#ifndef N_NO_UNICODE
NResult N_API NImageSaveToFileExW(HNImage hImage, const NWChar * szFileName, HNImageFormat hImageFormat, HNImageInfo hInfo, NUInt flags);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NImageSaveToFileEx(HNImage hImage, const NChar * szFileName, HNImageFormat hImageFormat, HNImageInfo hInfo, NUInt flags);
#endif
#define NImageSaveToFileEx N_FUNC_AW(NImageSaveToFileEx)

NResult N_API NImageSaveToMemoryN(HNImage hImage, HNImageFormat hImageFormat, HNImageInfo hInfo, NUInt flags, HNBuffer * phBuffer);
N_DEPRECATED("function is deprecated, use NImageSaveToMemoryN instead")
NResult N_API NImageSaveToMemory(HNImage hImage, HNImageFormat hImageFormat, HNImageInfo hInfo, NUInt flags, void * * ppBuffer, NSizeType * pBufferSize);
NResult N_API NImageSaveToStream(HNImage hImage, HNStream hStream, HNImageFormat hImageFormat, HNImageInfo hInfo, NUInt flags);

NResult N_API NImageFlipHorizontally(HNImage hImage);
NResult N_API NImageFlipVertically(HNImage hImage);
NResult N_API NImageFlipDiagonally(HNImage hImage);
NResult N_API NImageRotateFlip(HNImage hImage, NImageRotateFlipType rotateFlipType, HNImage * phResultImage);
NResult N_API NImageCrop(HNImage hImage, NUInt left, NUInt top, NUInt width, NUInt height, HNImage * phResultImage);
NResult N_API NImageToMonochrome(HNImage hImage, HNMonochromeImage * phResultImage);
NResult N_API NImageToGrayscale(HNImage hImage, HNGrayscaleImage * phResultImage);
NResult N_API NImageToRgb(HNImage hImage, HNRgbImage * phResultImage);

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
NResult N_API NImageToHBitmap(HNImage hImage, HBITMAP * phBitmap);
#endif

NResult N_API NImageGetPixelFormat(HNImage hImage, NPixelFormat_ * pValue);
NResult N_API NImageGetMinValue(HNImage hImage, HNArray * phValue);
NResult N_API NImageSetMinValue(HNImage hImage, HNArray hValue);
NResult N_API NImageGetMaxValue(HNImage hImage, HNArray * phValue);
NResult N_API NImageSetMaxValue(HNImage hImage, HNArray hValue);
NResult N_API NImageGetWidth(HNImage hImage, NUInt * pValue);
NResult N_API NImageGetHeight(HNImage hImage, NUInt * pValue);
NResult N_API NImageGetStride(HNImage hImage, NSizeType * pValue);
NResult N_API NImageGetPlaneSize(HNImage hImage, NSizeType * pValue);
NResult N_API NImageGetImageSize(HNImage hImage, NSizeType * pValue);
NResult N_API NImageGetHorzResolution(HNImage hImage, NFloat * pValue);
NResult N_API NImageSetHorzResolution(HNImage hImage, NFloat value);
NResult N_API NImageGetVertResolution(HNImage hImage, NFloat * pValue);
NResult N_API NImageSetVertResolution(HNImage hImage, NFloat value);
NResult N_API NImageGetResolutionIsAspectRatio(HNImage hImage, NBool * pValue);
NResult N_API NImageSetResolutionIsAspectRatio(HNImage hImage, NBool value);
NResult N_API NImageGetPixel(HNImage hImage, NUInt x, NUInt y, HNArray * phValue);
NResult N_API NImageSetPixel(HNImage hImage, NUInt x, NUInt y, HNArray hValue);
NResult N_API NImageGetIndex(HNImage hImage, NUInt x, NUInt y, NInt * pValue);
NResult N_API NImageSetIndex(HNImage hImage, NUInt x, NUInt y, NInt value);
NResult N_API NImageGetPlaneCount(HNImage hImage, NInt * pValue);
NResult N_API NImageGetPlane(HNImage hImage, NInt index, HNBuffer * phValue);
NResult N_API NImageGetPlanePtr(HNImage hImage, NInt index, void * pValue);
NResult N_API NImageGetPlanes(HNImage hImage, HNBuffer * arhValues, NInt valuesLength);
NResult N_API NImageGetPlanePtrs(HNImage hImage, void * * arValues, NInt valuesLength);
NResult N_API NImageGetPaletteLength(HNImage hImage, NInt * pValue);
NResult N_API NImageGetPaletteSize(HNImage hImage, NSizeType * pValue);
NResult N_API NImageGetPaletteEntry(HNImage hImage, NInt index, HNArray * phValue);
NResult N_API NImageSetPaletteEntry(HNImage hImage, NInt index, HNArray hValue);
NResult N_API NImageGetPalette(HNImage hImage, HNBuffer * phValue);
NResult N_API NImageGetPalettePtr(HNImage hImage, void * * pValue);
NResult N_API NImageSetPaletteN(HNImage hImage, HNBuffer hPalette, NInt paletteLength);
NResult N_API NImageSetPalette(HNImage hImage, const void * pPalette, NSizeType paletteSize, NInt paletteLength);
NResult N_API NImageGetPixelsN(HNImage hImage, HNBuffer * phValue);
#define NImageGetPixels(hImage, pValue) NImageGetPixelsPtr(hImage, pValue)
NResult N_API NImageGetPixelsPtr(HNImage hImage, void * * pValue);
NResult N_API NImageGetInfo(HNImage hImage, HNImageInfo * phValue);

#define NImageFree(hImage) NObjectFree(hImage)
#define NImageCreateWrapperForImagePart(hSrcImage, left, top, width, height, phImage) NImageCreateWrapperForImagePartEx2(hSrcImage, left, top, width, height, 0, phImage)
#define NImageCreateFromImage(pixelFormat, stride, hSrcImage, phImage) NImageCreateFromImageEx2(pixelFormat, stride, hSrcImage, 0, phImage)
#define NImageCreateFromImagePart(pixelFormat, stride, hSrcImage, left, top, width, height, phImage) NImageCreateFromImagePartEx2(pixelFormat, stride, hSrcImage, left, top, width, height, 0, phImage)
#define NImageCreateFromFileA(szFileName, hImageFormat, phImage) NImageCreateFromFileExA(szFileName, hImageFormat, 0, NULL, phImage)
#define NImageCreateFromFileW(szFileName, hImageFormat, phImage) NImageCreateFromFileExW(szFileName, hImageFormat, 0, NULL, phImage)
#define NImageCreateFromFile(szFileName, hImageFormat, phImage) NImageCreateFromFileEx(szFileName, hImageFormat, 0, NULL, phImage)
#define NImageClone(hImage, phClonedImage) NObjectClone(hImage, (HNObject *)phClonedImage)
#define NImageSaveToFileA(hImage, szFileName, hImageFormat) NImageSaveToFileExA(hImage, szFileName, hImageFormat, NULL, 0)
#define NImageSaveToFileW(hImage, szFileName, hImageFormat) NImageSaveToFileExW(hImage, szFileName, hImageFormat, NULL, 0)
#define NImageSaveToFile(hImage, szFileName, hImageFormat) NImageSaveToFileEx(hImage, szFileName, hImageFormat, NULL, 0)

#ifdef N_MSVC
	#pragma deprecated("NImageFree", "NImageCreateWrapperForImagePart", "NImageCreateFromImage", "NImageCreateFromImagePart", "NImageCreateFromFileA", "NImageCreateFromFileW", "NImageCreateFromFile", \
		"NImageClone", "NImageSaveToFileA", "NImageSaveToFileW", "NImageSaveToFile", "NImageGetPixels")
#endif

#ifdef N_CPP
}
#endif

#include <NImageUndefWinTypes.h>

#endif // !N_IMAGE_H_INCLUDED
