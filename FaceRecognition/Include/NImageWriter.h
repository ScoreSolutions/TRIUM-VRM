#ifndef N_IMAGE_WRITER_H_INCLUDED
#define N_IMAGE_WRITER_H_INCLUDED

#include <NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NImageWriter, NObject)

#ifdef N_CPP
}
#endif

#include <NBuffer.h>
#include <NImage.h>
#include <NImageInfo.h>
#include <NImageFormat.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NImageWriterWrite(HNImageWriter hWriter, HNImage hImage, HNImageInfo hInfo, NUInt flags);
NResult N_API NImageWriterGetBuffer(HNImageWriter hWriter, HNBuffer * phValue);
N_DEPRECATED("function is deprecated, use NImageWriterGetBuffer instead")
NResult N_API NImageWriterDetachBuffer(HNImageWriter hWriter, void * * ppBuffer, NSizeType * pBufferSize);

NResult N_API NImageWriterGetFormat(HNImageWriter hWriter, HNImageFormat * phValue);
NResult N_API NImageWriterGetFormatEx(HNImageWriter hWriter, HNImageFormat * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_IMAGE_WRITER_H_INCLUDED
