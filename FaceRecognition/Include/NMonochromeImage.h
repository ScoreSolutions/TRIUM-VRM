#ifndef N_MONOCHROME_IMAGE_H_INCLUDED
#define N_MONOCHROME_IMAGE_H_INCLUDED

#include <NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NMonochromeImageGetMinValue(HNMonochromeImage hImage, NBool * pValue);
NResult N_API NMonochromeImageSetMinValue(HNMonochromeImage hImage, NBool value);
NResult N_API NMonochromeImageGetMaxValue(HNMonochromeImage hImage, NBool * pValue);
NResult N_API NMonochromeImageSetMaxValue(HNMonochromeImage hImage, NBool value);
NResult N_API NMonochromeImageGetPixel(HNMonochromeImage hImage, NUInt x, NUInt y, NBool * pValue);
NResult N_API NMonochromeImageSetPixel(HNMonochromeImage hImage, NUInt x, NUInt y, NBool value);

#ifdef N_CPP
}
#endif

#endif // !N_MONOCHROME_IMAGE_H_INCLUDED
