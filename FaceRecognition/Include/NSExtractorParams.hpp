#ifndef NS_EXTRACTOR_PARAMS_HPP_INCLUDED
#define NS_EXTRACTOR_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NSExtractorParams.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NSEP_MIN_PHRASE_DURATION
#undef NSEP_MAX_PHRASE_DURATION
#undef NSEP_MAX_PAUSE_DURATION
#undef NSEP_USE_SPEAKER_DETECTION

const NUShort NSEP_MIN_PHRASE_DURATION = 34036;
const NUShort NSEP_MAX_PHRASE_DURATION = 34037;
const NUShort NSEP_MAX_PAUSE_DURATION = 35012;
const NUShort NSEP_USE_SPEAKER_DETECTION = 35020;
}}

#endif // !NS_EXTRACTOR_PARAMS_HPP_INCLUDED
