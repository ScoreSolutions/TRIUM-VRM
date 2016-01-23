#ifndef N_IMAGE_INFO_H_INCLUDED
#define N_IMAGE_INFO_H_INCLUDED

#include <NExpandableObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageInfo, NExpandableObject)

#ifdef N_CPP
}
#endif

#include <NImageFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NImageInfoCreate(HNImageInfo * phInfo);

NResult N_API NImageInfoGetFormat(HNImageInfo hInfo, HNImageFormat * phValue);
NResult N_API NImageInfoGetFormatEx(HNImageInfo hInfo, HNImageFormat * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_INFO_H_INCLUDED
