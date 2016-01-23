#ifndef NL_ATTRIBUTES_H_INCLUDED
#define NL_ATTRIBUTES_H_INCLUDED

#include <NBiometricAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NLAttributes, NBiometricAttributes)

NResult N_API NLAttributesCreate(HNLAttributes * phAttributes);

#ifdef N_CPP
}
#endif

#endif // !NL_ATTRIBUTES_H_INCLUDED
