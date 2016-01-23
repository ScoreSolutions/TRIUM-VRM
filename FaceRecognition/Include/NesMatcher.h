#ifndef NES_MATCHER_H_INCLUDED
#define NES_MATCHER_H_INCLUDED

#include <NEMatcher.h>
#include <NesmMatchDetails.h>
#include <NesMatcherParams.h>
#include <NETemplate.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NesMatcher, NObject)

N_DEPRECATED("function is deprecated, use NMCreate instead")
NResult N_API NesmCreate(HNesMatcher * phMatcher);

N_DEPRECATED("function is deprecated, use NMVerifyN instead")
NResult N_API NesmVerifyN(HNesMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, NesmMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMVerify instead")
NResult N_API NesmVerify(HNesMatcher hMatcher, const void * template1, NSizeType template1Size,
	const void * template2, NSizeType template2Size, NesmMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyStartN instead")
NResult N_API NesmIdentifyStartN(HNesMatcher hMatcher, HNBuffer hTemplate, NesmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyStart instead")
NResult N_API NesmIdentifyStart(HNesMatcher hMatcher, const void * templ, NSizeType templSize, NesmMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyNextN instead")
NResult N_API NesmIdentifyNextN(HNesMatcher hMatcher, HNBuffer hTemplate, NesmMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyNext instead")
NResult N_API NesmIdentifyNext(HNesMatcher hMatcher, const void * templ, NSizeType templSize, NesmMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyEnd instead")
NResult N_API NesmIdentifyEnd(HNesMatcher hMatcher);

#ifdef N_CPP
}
#endif

#endif // !NES_MATCHER_H_INCLUDED
