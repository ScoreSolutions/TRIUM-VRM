#ifndef NL_MATCHER_H_INCLUDED
#define NL_MATCHER_H_INCLUDED

#include <NLMatcherParams.h>
#include <NLRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NLMatcher, NObject)

N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NlmCreate(HNLMatcher *phMatcher);

N_DEPRECATED("function is deprecated, use NMVerifyN instead")
NResult N_API NlmVerifyN(HNLMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, NDouble * pScore);
N_DEPRECATED("function is deprecated, use NMVerify instead")
NResult N_API NlmVerify(HNLMatcher hMatcher, const void *pTemplate1, NSizeType template1Size,
	const void *pTemplate2, NSizeType template2Size, NDouble *pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyStartN instead")
NResult N_API NlmIdentifyStartN(HNLMatcher hMatcher, HNBuffer hTemplate);
N_DEPRECATED("function is deprecated, use NMIdentifyStart instead")
NResult N_API NlmIdentifyStart(HNLMatcher hMatcher, const void *pTemplate, NSizeType templateSize);
N_DEPRECATED("function is deprecated, use NMIdentifyNextN instead")
NResult N_API NlmIdentifyNextN(HNLMatcher hMatcher, HNBuffer hTemplate, NDouble * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyNext instead")
NResult N_API NlmIdentifyNext(HNLMatcher hMatcher, const void *pTemplate, NSizeType templateSize, NDouble *pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyEnd instead")
NResult N_API NlmIdentifyEnd(HNLMatcher hMatcher);

#ifdef N_CPP
}
#endif

#endif // !NL_MATCHER_H_INCLUDED
