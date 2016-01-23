#ifndef N_LICENSING_SERVICE_HPP_INCLUDED
#define N_LICENSING_SERVICE_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Licensing
{
#include <NLicensingService.h>
}}

namespace Neurotec { namespace Licensing
{

class N_CLASS(NLicensingService)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NLicensingService)

public:
	static N_CLASS(NType) * NLicensingServiceStatusNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NLicensingServiceStatus), true, true);
	}

	static void Install(const N_CLASS(NStringWrapper) & binPath, const N_CLASS(NStringWrapper) & conf)
	{
		NCheck(NLicensingServiceInstallN(binPath.GetHandle(), conf.GetHandle()));
	}

	static void Uninstall(void)
	{
		NCheck(NLicensingServiceUninstall());
	}

	static void Start(void)
	{
		NCheck(NLicensingServiceStart());
	}

	static void Stop(void)
	{
		NCheck(NLicensingServiceStop());
	}

	static NLicensingServiceStatus GetStatus(void)
	{
		NLicensingServiceStatus s;
		NCheck(NLicensingServiceGetStatus(&s));
		return s;
	}

	static N_CLASS(NString) GetBinPath(void)
	{
		HNString hValue;
		NCheck(NLicensingServiceGetBinPath(&hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GetConfPath(void)
	{
		HNString hValue;
		NCheck(NLicensingServiceGetConfPath(&hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static bool IsTrial(void)
	{
		NBool isTrial;
		NCheck(NLicensingServiceIsTrial(&isTrial));
		return isTrial != 0;
	}
};

}}

#endif // !N_LICENSING_SERVICE_HPP_INCLUDED
