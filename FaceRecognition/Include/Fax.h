#ifndef FAX_H_INCLUDED
#define FAX_H_INCLUDED

#include <NImage.h>

#define FAX_GROUP3OPT_2DENCODING   0x1 // 2-dimensional coding
#define FAX_GROUP3OPT_UNCOMPRESSED 0x2 // data not compressed
#define FAX_GROUP3OPT_FILLBITS     0x4 // fill to byte boundary

#define FAX_GROUP4OPT_UNCOMPRESSED 0x2 // data not compressed

NResult N_API Fax3Decode(HNBuffer hSrcBuffer, NUInt width, NSizeType dstStride, NUInt options, HNBuffer hDstBuffer);
NResult N_API Fax3Encode(HNBuffer hSrcBuffer, NUInt width, NSizeType stride, NUInt options, HNStream hOutputStream);

NResult N_API Fax4Decode(HNBuffer hSrcBuffer, NUInt width, NSizeType dstStride, NUInt options, HNBuffer hDstBuffer);
NResult N_API Fax4Encode(HNBuffer hSrcBuffer, NUInt width, NSizeType stride, NUInt options, HNStream hOutputStream);

#endif // !FAX_H_INCLUDED
