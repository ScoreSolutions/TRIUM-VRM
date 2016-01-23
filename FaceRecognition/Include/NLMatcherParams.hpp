#ifndef NL_MATCHER_PARAMS_HPP_INCLUDED
#define NL_MATCHER_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NLMatcherParams.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NLMP_MATCHING_THRESHOLD
#undef NLMP_MATCHING_SPEED

const NUShort NLMP_MATCHING_THRESHOLD = 10000;
const NUShort NLMP_MATCHING_SPEED = 10001;
}}

#endif // !NL_MATCHER_PARAMS_HPP_INCLUDED
