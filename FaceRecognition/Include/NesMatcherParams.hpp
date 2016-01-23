#ifndef NES_MATCHER_PARAMS_HPP_INCLUDED
#define NES_MATCHER_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NesMatcherParams.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NESM_PART_NONE
#undef NESM_PART_NEM

#undef NESMP_MATCHING_THRESHOLD

const NUShort NESM_PART_NONE = 0;
const NUShort NESM_PART_NEM = 1;

const NUShort NESMP_MATCHING_THRESHOLD = 100;
}}

#endif // !NES_MATCHER_PARAMS_HPP_INCLUDED
