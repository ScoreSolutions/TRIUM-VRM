#ifndef NLS_MATCHER_H_INCLUDED
#define NLS_MATCHER_H_INCLUDED

#include <NLMatcher.h>
#include <NlsmMatchDetails.h>
#include <NlsMatcherParams.h>
#include <NLTemplate.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NlsMatcher, NObject)

N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NlsmCreate(HNlsMatcher * phMatcher);

N_DEPRECATED("function is deprecated, use NMVerifyN instead")
NResult N_API NlsmVerifyN(HNlsMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, NlsmMatchDetails * * ppMatchDetails, NDouble * pScore);
N_DEPRECATED("function is deprecated, use NMVerify instead")
NResult N_API NlsmVerify(HNlsMatcher hMatcher, const void * template1, NSizeType template1Size,
	const void * template2, NSizeType template2Size, NlsmMatchDetails * * ppMatchDetails, NDouble * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyStartN instead")
NResult N_API NlsmIdentifyStartN(HNlsMatcher hMatcher, HNBuffer hTemplate, NlsmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyStart instead")
NResult N_API NlsmIdentifyStart(HNlsMatcher hMatcher, const void * templ, NSizeType templSize, NlsmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyNextN instead")
NResult N_API NlsmIdentifyNextN(HNlsMatcher hMatcher, HNBuffer hTemplate, NlsmMatchDetails * pMatchDetails, NDouble * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyNext instead")
NResult N_API NlsmIdentifyNext(HNlsMatcher hMatcher, const void * templ, NSizeType templSize, NlsmMatchDetails * pMatchDetails, NDouble * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyEnd instead")
NResult N_API NlsmIdentifyEnd(HNlsMatcher hMatcher);

#ifdef N_CPP
}
#endif

#endif // !NLS_MATCHER_H_INCLUDED
