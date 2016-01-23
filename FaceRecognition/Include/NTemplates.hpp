#ifndef N_TEMPLATES_HPP_INCLUDED
#define N_TEMPLATES_HPP_INCLUDED

#include <NBiometrics.hpp>
#include <NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NTemplates.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NBiometrics)) " instead")
	N_CLASS(NTemplates)
{
private:
	N_CLASS(NTemplates)()
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

#endif // !N_TEMPLATES_HPP_INCLUDED
