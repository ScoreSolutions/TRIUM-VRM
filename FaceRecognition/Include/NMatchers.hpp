#ifndef N_MATCHERS_HPP_INCLUDED
#define N_MATCHERS_HPP_INCLUDED

#include <NBiometrics.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NMatchers.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NBiometrics)) " instead")
	N_CLASS(NMatchers)
{
private:
	N_CLASS(NMatchers)()
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

#endif // !N_MATCHERS_HPP_INCLUDED
