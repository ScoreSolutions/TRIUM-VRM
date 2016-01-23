#ifndef NS_ATTRIBUTES_HPP_INCLUDED
#define NS_ATTRIBUTES_HPP_INCLUDED

#include <NBiometricAttributes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NSAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NSAttributes) : public N_CLASS(NBiometricAttributes)
{
	N_DECLARE_OBJECT_CLASS(NSAttributes, NBiometricAttributes)

private:
	static HNSAttributes Create(NInt phraseId)
	{
		HNSAttributes handle;
		NCheck(NSAttributesCreate(phraseId, &handle));
		return handle;
	}

	N_CLASS(NSAttributes)(HNObject handle, bool claimHandle)
		: N_CLASS(NBiometricAttributes)(handle, claimHandle)
	{
	}

public:
	explicit N_CLASS(NSAttributes)(NInt phraseId)
		: N_CLASS(NBiometricAttributes)(Create(phraseId), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSAttributes);
	}

	NInt GetPhraseId() const
	{
		NInt value;
		NCheck(NSAttributesGetPhraseId(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !NS_ATTRIBUTES_HPP_INCLUDED
