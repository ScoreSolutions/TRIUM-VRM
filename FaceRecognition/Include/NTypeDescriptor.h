#ifndef N_TYPE_DESCRIPTOR_H_INCLUDED
#define N_TYPE_DESCRIPTOR_H_INCLUDED

#include <NPropertyDescriptor.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(NTypeDescriptor)

NResult N_API NTypeDescriptorGetProperties(HNObject hObject, HNPropertyDescriptor * * parhProperties, NInt * pPropertyCount);
NResult N_API NTypeDescriptorGetPropertiesForType(HNType hType, HNPropertyDescriptor * * parhProperties, NInt * pPropertyCount);
NResult N_API NTypeDescriptorGetDefaultPropertyName(HNObject hObject, HNString * phValue);
NResult N_API NTypeDescriptorGetDefaultPropertyNameForType(HNType hType, HNString * phValue);

#ifdef N_CPP
}
#endif

#endif // !N_TYPE_DESCRIPTOR_H_INCLUDED
