#ifndef NE_MATCHER_H_INCLUDED
#define NE_MATCHER_H_INCLUDED

#include <NemMatchDetails.h>
#include <NEMatcherParams.h>
#include <NERecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NEMatcher, NObject)

N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NemCreate(HNEMatcher * phMatcher);

N_DEPRECATED("function is deprecated, use NMVerifyN instead")
NResult N_API NemVerifyN(HNEMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, NemMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMVerify instead")
NResult N_API NemVerify(HNEMatcher hMatcher, const void * pTemplate1, NSizeType template1Size,
	const void * pTemplate2, NSizeType template2Size, NemMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyStartN instead")
NResult N_API NemIdentifyStartN(HNEMatcher hMatcher, HNBuffer hTemplate, NemMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyStart instead")
NResult N_API NemIdentifyStart(HNEMatcher hMatcher, const void * pTemplate, NSizeType templateSize, NemMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyNextN instead")
NResult N_API NemIdentifyNextN(HNEMatcher hMatcher, HNBuffer hTemplate, NemMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyNext instead")
NResult N_API NemIdentifyNext(HNEMatcher hMatcher, const void * pTemplate, NSizeType templateSize, NemMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyEnd instead")
NResult N_API NemIdentifyEnd(HNEMatcher hMatcher);

#ifdef N_CPP
}
#endif

#endif // !NE_MATCHER_H_INCLUDED
