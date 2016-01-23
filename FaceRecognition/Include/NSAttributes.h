#ifndef NS_ATTRIBUTES_H_INCLUDED
#define NS_ATTRIBUTES_H_INCLUDED

#include <NBiometricAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSAttributes, NBiometricAttributes)

NResult N_API NSAttributesCreate(NInt phraseId, HNSAttributes * phAttributes);

NResult N_API NSAttributesGetPhraseId(HNSAttributes hAttributes, NInt * pValue);

#ifdef N_CPP
}
#endif

#endif // !NS_ATTRIBUTES_H_INCLUDED
