#ifndef N_IMAGES_H_INCLUDED
#define N_IMAGES_H_INCLUDED

#include <NRgbImage.h>
#include <NMedia.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NImages)

NResult N_API NImagesGetGrayscaleColorWrapperEx(HNImage hImage, const struct NRgb_ * pMinColor, const struct NRgb_ * pMaxColor, HNImage * phDstImage);
NResult N_API NImagesRecolorImage(HNImage hImage, NPixelFormat_ pixelFormat, HNArray hMinValue, HNArray hMaxValue, HNImage * phDstImage);

#define NImagesModuleOf NMediaModuleOf
#define NImagesGetInfo NMediaGetInfo
#define NImagesGetInfoA NMediaGetInfoA
#define NImagesGetInfoW NMediaGetInfoW

#ifdef N_MSVC
	#pragma deprecated("NImagesModuleOf")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_IMAGES_H_INCLUDED
