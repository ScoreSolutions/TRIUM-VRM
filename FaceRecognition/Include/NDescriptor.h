#ifndef N_DESCRIPTOR_H_INCLUDED
#define N_DESCRIPTOR_H_INCLUDED

#include <NType.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDescriptor, NObject)

NResult N_API NDescriptorGetName(HNDescriptor hDescriptor, HNString * phValue);
NResult N_API NDescriptorGetAttributes(HNDescriptor hDescriptor, NAttributes * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_DESCRIPTOR_H_INCLUDED
