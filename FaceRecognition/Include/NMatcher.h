#ifndef N_MATCHER_H_INCLUDED
#define N_MATCHER_H_INCLUDED

#include <NfsMatcher.h>
#include <NlsMatcher.h>
#include <NesMatcher.h>
#include <NMMatchDetails.h>
#include <NMatchingDetails.h>
#include <NMatcherParams.h>
#include <NMatchers.h>
#include <NTemplate.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMatcher, NObject)

NResult N_API NMCreate(HNMatcher * phMatcher);

N_DEPRECATED("function is deprecated, use NMVerifyExN instead")
NResult N_API NMVerifyN(HNMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, NMMatchDetails * * ppMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMVerifyEx instead")
NResult N_API NMVerify(HNMatcher hMatcher, const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, NMMatchDetails * * ppMatchDetails, NInt * pScore);
NResult N_API NMVerifyExN(HNMatcher hMatcher, HNBuffer hTemplate1, HNBuffer hTemplate2, HNMatchingDetails * phMatchingDetails, NInt * pScore);
NResult N_API NMVerifyEx(HNMatcher hMatcher, const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, HNMatchingDetails * phMatchingDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyStartExN instead")
NResult N_API NMIdentifyStartN(HNMatcher hMatcher, HNBuffer hTemplate, NMMatchDetails * * ppMatchDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyStartEx instead")
NResult N_API NMIdentifyStart(HNMatcher hMatcher, const void * pTemplate, NSizeType templateSize, NMMatchDetails * * ppMatchDetails);
NResult N_API NMIdentifyStartExN(HNMatcher hMatcher, HNBuffer hTemplate, HNMatchingDetails * phMatchingDetails);
NResult N_API NMIdentifyStartEx(HNMatcher hMatcher, const void * pTemplate, NSizeType templateSize, HNMatchingDetails * phMatchingDetails);
N_DEPRECATED("function is deprecated, use NMIdentifyNextExN instead")
NResult N_API NMIdentifyNextN(HNMatcher hMatcher, HNBuffer hTemplate, NMMatchDetails * pMatchDetails, NInt * pScore);
N_DEPRECATED("function is deprecated, use NMIdentifyNextEx instead")
NResult N_API NMIdentifyNext(HNMatcher hMatcher, const void * pTemplate, NSizeType templateSize, NMMatchDetails * pMatchDetails, NInt * pScore);
NResult N_API NMIdentifyNextExN(HNMatcher hMatcher, HNBuffer hTemplate, HNMatchingDetails hMatchingDetails, NInt * pScore);
NResult N_API NMIdentifyNextEx(HNMatcher hMatcher, const void * pTemplate, NSizeType templateSize, HNMatchingDetails hMatchingDetails, NInt * pScore);
NResult N_API NMIdentifyEnd(HNMatcher hMatcher);

NResult N_API NMPrepareTemplate(HNMatcher hMatcher, HNTemplate hTemplate);

#ifdef N_CPP
}
#endif

#endif // !N_MATCHER_H_INCLUDED
