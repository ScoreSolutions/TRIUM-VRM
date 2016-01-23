#ifndef NF_SEGMENTER_PARAMS_HPP_INCLUDED
#define NF_SEGMENTER_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics { namespace Tools
{
#include <NFSegmenterParams.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Tools
{
#undef NFSP_REMOVE_BACKGROUND
#undef NFSP_USE_OLD

const NUShort NFSP_REMOVE_BACKGROUND = 10001;
const NUShort NFSP_USE_OLD = 30001;
}}}

#endif // !NF_SEGMENTER_PARAMS_HPP_INCLUDED
