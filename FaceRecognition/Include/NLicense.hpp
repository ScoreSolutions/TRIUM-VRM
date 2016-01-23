#ifndef N_LICENSE_HPP_INCLUDED
#define N_LICENSE_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Licensing
{
#include <NLicense.h>
}}

namespace Neurotec { namespace Licensing
{

class N_CLASS(NLicenseInfo) : public NLicenseInfo_
{
	N_DECLARE_STRUCT_CLASS(NLicenseInfo)

public:
	N_CLASS(NLicenseInfo)(bool isObtained, NInt distributorId, NInt serialNumber)
	{
		IsObtained = isObtained ? NTrue : NFalse;
		DistributorId = distributorId;
		SerialNumber = serialNumber;
	}

	bool GetIsObtained() const
	{
		return IsObtained != 0;
	}

	void SetIsObtained(bool value)
	{
		IsObtained = value ? NTrue : NFalse;
	}
};
N_TYPEDEF_TYPE(NLicenseInfo)

class N_CLASS(NLicense)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NLicense)

public:
	static bool Obtain(const N_CLASS(NStringWrapper) & address, const N_CLASS(NStringWrapper) & port, const N_CLASS(NStringWrapper) & products)
	{
		NBool available;
		NCheck(NLicenseObtainN(address.GetHandle(), port.GetHandle(), products.GetHandle(), &available));
		return available != 0;
	}

	static bool ObtainComponents(const N_CLASS(NStringWrapper) & address, const N_CLASS(NStringWrapper) & port, const N_CLASS(NStringWrapper) & components)
	{
		NBool available;
		NCheck(NLicenseObtainComponentsN(address.GetHandle(), port.GetHandle(), components.GetHandle(), &available));
		return available != 0;
	}

	static void Release(const N_CLASS(NStringWrapper) & products)
	{
		NCheck(NLicenseReleaseN(products.GetHandle()));
	}

	static void ReleaseComponents(const N_CLASS(NStringWrapper) & components)
	{
		NCheck(NLicenseReleaseComponentsN(components.GetHandle()));
	}

	static void GetInfo(const N_CLASS(NStringWrapper) & product, NLicenseInfo * pLicenseInfo)
	{
		NCheck(NLicenseGetInfoN(product.GetHandle(), pLicenseInfo));
	}

	static void GetInfoForComponent(const N_CLASS(NStringWrapper) & component, NLicenseInfo * pLicenseInfo)
	{
		NCheck(NLicenseGetInfoForComponentN(component.GetHandle(), pLicenseInfo));
	}

	static bool IsComponentActivated(const N_CLASS(NStringWrapper) & name)
	{
		NBool value;
		NCheck(NLicenseIsComponentActivatedN(name.GetHandle(), &value));
		return value != 0;
	}

	static N_CLASS(NString) GenerateId(const N_CLASS(NStringWrapper) & serialNumber)
	{
		HNString hValue;
		NCheck(NLicenseGenerateIdN(NULL, serialNumber.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GenerateId(const N_CLASS(NStringWrapper) & idGenPath, const N_CLASS(NStringWrapper) & serialNumber)
	{
		HNString hValue;
		NCheck(NLicenseGenerateIdN(idGenPath.GetHandle(), serialNumber.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GenerateDeactivationId(const N_CLASS(NStringWrapper) & productName)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdN(NULL, productName.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GenerateDeactivationId(const N_CLASS(NStringWrapper) & idGenPath, const N_CLASS(NStringWrapper) & productName)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdN(idGenPath.GetHandle(), productName.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GenerateDeactivationIdForLicense(const N_CLASS(NStringWrapper) & license)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdForLicenseN(NULL, license.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) GenerateDeactivationIdForLicense(const N_CLASS(NStringWrapper) & idGenPath, const N_CLASS(NStringWrapper) & license)
	{
		HNString hValue;
		NCheck(NLicenseGenerateDeactivationIdForLicenseN(idGenPath.GetHandle(), license.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) ActivateOnline(const N_CLASS(NStringWrapper) & id)
	{
		HNString hValue;
		NCheck(NLicenseActivateOnlineN(id.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static void DeactivateOnline(const N_CLASS(NStringWrapper) & license)
	{
		NCheck(NLicenseDeactivateOnlineN(NULL, license.GetHandle()));
	}

	static void DeactivateOnline(const N_CLASS(NStringWrapper) & idGenPath, const N_CLASS(NStringWrapper) & license)
	{
		NCheck(NLicenseDeactivateOnlineN(idGenPath.GetHandle(), license.GetHandle()));
	}

	static void DeactivateOnlineWithId(const N_CLASS(NStringWrapper) & license, const N_CLASS(NStringWrapper) & deactivationId)
	{
		NCheck(NLicenseDeactivateOnlineWithIdN(license.GetHandle(), deactivationId.GetHandle()));
	}
};

}}

#endif // !N_LICENSE_HPP_INCLUDED
