#ifndef NLS_MATCHER_PARAMS_HPP_INCLUDED
#define NLS_MATCHER_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NlsMatcherParams.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NLSM_PART_NONE
#undef NLSM_PART_NLM

#undef NLSMP_MATCHING_THRESHOLD

const NUShort NLSM_PART_NONE = 0;
const NUShort NLSM_PART_NLM = 1;

const NUShort NLSMP_MATCHING_THRESHOLD = 100;
}}

#endif // !NLS_MATCHER_PARAMS_HPP_INCLUDED
