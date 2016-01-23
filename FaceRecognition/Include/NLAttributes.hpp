#ifndef NL_ATTRIBUTES_HPP_INCLUDED
#define NL_ATTRIBUTES_HPP_INCLUDED

#include <NBiometricAttributes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NLAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NLAttributes) : public N_CLASS(NBiometricAttributes)
{
	N_DECLARE_OBJECT_CLASS(NLAttributes, NBiometricAttributes)

private:
	static HNLAttributes Create()
	{
		HNLAttributes handle;
		NCheck(NLAttributesCreate(&handle));
		return handle;
	}

	N_CLASS(NLAttributes)(HNObject handle, bool claimHandle)
		: N_CLASS(NBiometricAttributes)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NLAttributes)()
		: N_CLASS(NBiometricAttributes)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLAttributes);
	}
};

}}

#endif // !NL_ATTRIBUTES_HPP_INCLUDED
