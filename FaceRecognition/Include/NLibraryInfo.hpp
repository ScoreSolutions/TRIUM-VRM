#ifndef N_LIBRARY_INFO_HPP_INCLUDED
#define N_LIBRARY_INFO_HPP_INCLUDED

#include <NTypes.hpp>
#include <NError.hpp>
namespace Neurotec
{
#include <NLibraryInfo.h>
}

namespace Neurotec
{
#undef N_LI_TITLE_MAX_LENGTH
#undef N_LI_PRODUCT_MAX_LENGTH
#undef N_LI_COMPANY_MAX_LENGTH
#undef N_LI_COPYRIGHT_MAX_LENGTH
#undef N_LI_ACTIVATED_MAX_LENGTH

const NSizeType N_LI_TITLE_MAX_LENGTH     = 128;
const NSizeType N_LI_PRODUCT_MAX_LENGTH   = 128;
const NSizeType N_LI_COMPANY_MAX_LENGTH   =  64;
const NSizeType N_LI_COPYRIGHT_MAX_LENGTH = 192;
const NSizeType N_LI_ACTIVATED_MAX_LENGTH = 256;
}

#endif // !N_LIBRARY_INFO_HPP_INCLUDED
