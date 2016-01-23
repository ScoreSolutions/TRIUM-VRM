#ifndef NFS_MATCHER_PARAMS_HPP_INCLUDED
#define NFS_MATCHER_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NfsMatcherParams.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NFSM_PART_NONE
#undef NFSM_PART_NFM

#undef NFSMP_MATCHING_THRESHOLD
#undef NFSMP_MIN_MATCHED_FINGER_COUNT
#undef NFSMP_MIN_MATCHED_FINGER_COUNT_THRESHOLD

const NUShort NFSM_PART_NONE = 0;
const NUShort NFSM_PART_NFM = 1;

const NUShort NFSMP_MATCHING_THRESHOLD = 100;
const NUShort NFSMP_MIN_MATCHED_FINGER_COUNT = 201;
const NUShort NFSMP_MIN_MATCHED_FINGER_COUNT_THRESHOLD = 202;
}}

#endif // !NFS_MATCHER_PARAMS_HPP_INCLUDED
