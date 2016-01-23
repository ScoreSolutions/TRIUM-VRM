#ifndef N_BIOMETRICS_HPP_INCLUDED
#define N_BIOMETRICS_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NBiometrics.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_CLASS(NBiometrics)
{
private:
	N_CLASS(NBiometrics)()
	{
	}

public:
	N_DEPRECATED("method is deprecated, use N_NATIVE_MODULE_OF(NBiometrics) instead")
	static void GetInfo(NLibraryInfo * pValue)
	{
		NCheck(NBiometricsGetInfo(pValue));
	}

	N_DECLARE_MODULE_CLASS(NBiometrics)
};
#include <NReDeprecate.h>

}}

#endif // !N_BIOMETRICS_HPP_INCLUDED
