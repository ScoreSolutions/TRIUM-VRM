#ifndef NE_MATCHER_PARAMS_HPP_INCLUDED
#define NE_MATCHER_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NEMatcherParams.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NEMP_MATCHING_THRESHOLD
#undef NEMP_MATCHING_SPEED
#undef NEMP_MAXIMAL_ROTATION

const NUShort NEMP_MATCHING_THRESHOLD = 10000;
const NUShort NEMP_MATCHING_SPEED = 10001;
const NUShort NEMP_MAXIMAL_ROTATION = 10002;
}}

#endif // !NE_MATCHER_PARAMS_HPP_INCLUDED
