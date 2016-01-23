#ifndef N_BIOMETRIC_ATTRIBUTES_HPP_INCLUDED
#define N_BIOMETRIC_ATTRIBUTES_HPP_INCLUDED

#include <NBiometricTypes.hpp>
#include <NObject.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NBiometricAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NBiometricAttributes) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NBiometricAttributes, NObject)

protected:
	N_CLASS(NBiometricAttributes)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	NBiometricType GetBiometricType() const
	{
		NBiometricType value;
		NCheck(NBiometricAttributesGetBiometricType(GetHandle(), &value));
		return value;
	}

	NBiometricStatus GetStatus() const
	{
		NBiometricStatus value;
		NCheck(NBiometricAttributesGetStatus(GetHandle(), &value));
		return value;
	}

	void SetStatus(NBiometricStatus value)
	{
		NCheck(NBiometricAttributesSetStatus(GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NBiometricAttributesGetQuality(GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NBiometricAttributesSetQuality(GetHandle(), value));
	}
};

}}

#endif // !N_BIOMETRIC_ATTRIBUTES_HPP_INCLUDED
