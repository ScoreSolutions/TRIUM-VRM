#ifndef N_LICENSING_HPP_INCLUDED
#define N_LICENSING_HPP_INCLUDED

#include <NCore.hpp>
#include <NLicense.hpp>
namespace Neurotec { namespace Licensing
{
#include <NLicensing.h>
}}

namespace Neurotec { namespace Licensing
{

#include <NNoDeprecate.h>
class N_CLASS(NLicensing)
{
private:
	N_CLASS(NLicensing)()
	{
	}

public:
	N_DEPRECATED("method is deprecated, use N_NATIVE_MODULE_OF(NLicensing) instead")
	static void GetInfo(NLibraryInfo * pValue)
	{
		NCheck(NLicensingGetInfo(pValue));
	}

	N_DECLARE_MODULE_CLASS(NLicensing)
};
#include <NReDeprecate.h>

}}

#endif // !N_LICENSING_HPP_INCLUDED
