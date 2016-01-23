#ifndef NE_ATTRIBUTES_H_INCLUDED
#define NE_ATTRIBUTES_H_INCLUDED

#include <NBiometricAttributes.h>
#include <NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NEAttributes, NBiometricAttributes)

NResult N_API NEAttributesCreate(NEPosition position, HNEAttributes * phAttributes);

NResult N_API NEAttributesGetPosition(HNEAttributes hAttributes, NEPosition * pValue);
NResult N_API NEAttributesGetImageIndex(HNEAttributes hAttributes, NInt * pValue);
NResult N_API NEAttributesSetImageIndex(HNEAttributes hAttributes, NInt value);
NResult N_API NEAttributesGetBoundingRect(HNEAttributes hAttributes, struct NRect_ * pValue);
NResult N_API NEAttributesSetBoundingRect(HNEAttributes hAttributes, const struct NRect_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !NE_ATTRIBUTES_H_INCLUDED
