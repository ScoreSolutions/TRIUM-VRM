#ifndef N_EXTRACTORS_HPP_INCLUDED
#define N_EXTRACTORS_HPP_INCLUDED

#include <NBiometrics.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NExtractors.h>
}}

#include <NNoDeprecate.h>
namespace Neurotec { namespace Biometrics
{

class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NBiometrics)) " instead")
	N_CLASS(NExtractors)
{
private:
	N_CLASS(NExtractors)()
	{
	}

public:
	static void GetInfo(NLibraryInfo * pValue)
	{
		N_CLASS(NBiometrics)::GetInfo(pValue);
	}
};
#include <NReDeprecate.h>

}}

#endif // !N_EXTRACTORS_HPP_INCLUDED
