#ifndef NF_ATTRIBUTES_H_INCLUDED
#define NF_ATTRIBUTES_H_INCLUDED

#include <NBiometricAttributes.h>
#include <NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFAttributes, NBiometricAttributes)

NResult N_API NFAttributesCreate(NFImpressionType impressionType, NFPosition position, HNFAttributes * phAttributes);

NResult N_API NFAttributesGetImpressionType(HNFAttributes hAttributes, NFImpressionType * pValue);
NResult N_API NFAttributesGetPosition(HNFAttributes hAttributes, NFPosition * pValue);
NResult N_API NFAttributesGetImageIndex(HNFAttributes hAttributes, NInt * pValue);
NResult N_API NFAttributesSetImageIndex(HNFAttributes hAttributes, NInt value);
NResult N_API NFAttributesGetBoundingRect(HNFAttributes hAttributes, struct NRect_ * pValue);
NResult N_API NFAttributesSetBoundingRect(HNFAttributes hAttributes, const struct NRect_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !NF_ATTRIBUTES_H_INCLUDED
