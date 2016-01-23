#ifndef N_BIOMETRICS_LIBRARY_CPP_INCLUDED
#define N_BIOMETRICS_LIBRARY_CPP_INCLUDED

#include <NCoreLibrary.cpp>
#include <NMediaLibrary.cpp>
#include <NMediaProcLibrary.cpp>

#include <NFRecord.hpp>
#include <NLRecord.hpp>
#include <NERecord.hpp>
#include <NSRecord.hpp>
#include <NFTemplate.hpp>
#include <NLTemplate.hpp>
#include <NETemplate.hpp>
#include <NSTemplate.hpp>
#include <NTemplate.hpp>
#include <NTemplates.hpp>

#include <NEMatcher.hpp>
#include <NesMatcher.hpp>
#include <NFMatcher.hpp>
#include <NfsMatcher.hpp>
#include <NLMatcher.hpp>
#include <NlsMatcher.hpp>
#include <NMMatchDetails.hpp>
#include <NemMatchDetails.hpp>
#include <NesmMatchDetails.hpp>
#include <NfmMatchDetails.hpp>
#include <NfsmMatchDetails.hpp>
#include <NlsmMatchDetails.hpp>

#include <NMatchingDetails.hpp>
#include <NMatcher.hpp>

#include <NFAttributes.hpp>
#include <NEAttributes.hpp>
#include <NLAttributes.hpp>
#include <NSAttributes.hpp>

#include <NEExtractor.hpp>
#include <NFExtractor.hpp>
#include <NLExtractor.hpp>
#include <NSExtractor.hpp>

#include <NFSegmenter.hpp>
#include <Ntfi.hpp>
#include <NESegmenter.hpp>

using namespace ::Neurotec::Images;
using namespace ::Neurotec::Sound;

namespace Neurotec { namespace Biometrics
{

N_IMPLEMENT_OBJECT_CLASS_1(NFRecord, NObject, NFTemplate)
N_IMPLEMENT_OBJECT_CLASS_1(NLRecord, NObject, NLTemplate)
N_IMPLEMENT_OBJECT_CLASS_1(NERecord, NObject, NETemplate)
N_IMPLEMENT_OBJECT_CLASS_1(NSRecord, NObject, NSTemplate)
N_IMPLEMENT_OBJECT_CLASS_2(NFTemplate, NObject, NTemplate, NFRecord)
N_IMPLEMENT_OBJECT_CLASS_2(NLTemplate, NObject, NTemplate, NLRecord)
N_IMPLEMENT_OBJECT_CLASS_2(NETemplate, NObject, NTemplate, NERecord)
N_IMPLEMENT_OBJECT_CLASS_2(NSTemplate, NObject, NTemplate, NSRecord)
N_IMPLEMENT_OBJECT_CLASS_4(NTemplate, NObject, NFTemplate, NLTemplate, NETemplate, NSTemplate)

#include <NNoDeprecate.h>
N_IMPLEMENT_OBJECT_CLASS(NEMatcher, NObject)
N_IMPLEMENT_OBJECT_CLASS(NesMatcher, NObject)
N_IMPLEMENT_OBJECT_CLASS(NFMatcher, NObject)
N_IMPLEMENT_OBJECT_CLASS(NfsMatcher, NObject)
N_IMPLEMENT_OBJECT_CLASS(NLMatcher, NObject)
N_IMPLEMENT_OBJECT_CLASS(NlsMatcher, NObject)
#include <NReDeprecate.h>
N_IMPLEMENT_OBJECT_CLASS_2(NMatchingDetailsBase, NObject, NXMatchingDetails, NMatchingDetails)
N_IMPLEMENT_OBJECT_CLASS_4(NXMatchingDetails, NMatchingDetailsBase, NEMatchingDetails, NFMatchingDetails, NLMatchingDetails, NSMatchingDetails)
N_IMPLEMENT_OBJECT_CLASS(NEMatchingDetails, NXMatchingDetails)
N_IMPLEMENT_OBJECT_CLASS(NFMatchingDetails, NXMatchingDetails)
N_IMPLEMENT_OBJECT_CLASS(NLMatchingDetails, NXMatchingDetails)
N_IMPLEMENT_OBJECT_CLASS(NSMatchingDetails, NXMatchingDetails)
N_IMPLEMENT_OBJECT_CLASS(NMatchingDetails, NMatchingDetailsBase)
N_IMPLEMENT_OBJECT_CLASS(NMatcher, NObject)

N_IMPLEMENT_OBJECT_CLASS_4(NBiometricAttributes, NObject, NEAttributes, NFAttributes, NLAttributes, NSAttributes)
N_IMPLEMENT_OBJECT_CLASS(NEAttributes, NBiometricAttributes)
N_IMPLEMENT_OBJECT_CLASS(NFAttributes, NBiometricAttributes)
N_IMPLEMENT_OBJECT_CLASS(NLAttributes, NBiometricAttributes)
N_IMPLEMENT_OBJECT_CLASS(NSAttributes, NBiometricAttributes)

N_IMPLEMENT_OBJECT_CLASS_2(NEExtractor, NObject, NERecord, NImage)
N_IMPLEMENT_OBJECT_CLASS_2(NFExtractor, NObject, NFRecord, NImage)
N_IMPLEMENT_OBJECT_CLASS_2(NLExtractor, NObject, NLRecord, NImage)
N_IMPLEMENT_OBJECT_CLASS_2(NSExtractor, NObject, NSRecord, NSoundBuffer)

namespace Tools
{
N_IMPLEMENT_OBJECT_CLASS(NFSegment, NObject)
N_IMPLEMENT_OBJECT_CLASS(NtfiAttributes, NObject)
N_IMPLEMENT_OBJECT_CLASS_2(Ntfi, NObject, NtfiAttributes, NImage)
N_IMPLEMENT_OBJECT_CLASS(NESegmenterAttributes, NObject)
N_IMPLEMENT_OBJECT_CLASS_2(NESegmenter, NObject, NESegmenterAttributes, NImage)
}

}}

#endif // !N_BIOMETRICS_LIBRARY_CPP_INCLUDED
