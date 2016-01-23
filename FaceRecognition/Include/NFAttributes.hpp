#ifndef NF_ATTRIBUTES_HPP_INCLUDED
#define NF_ATTRIBUTES_HPP_INCLUDED

#include <NBiometricAttributes.hpp>
#include <NGeometry.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Geometry::NRect_;
#include <NFAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NFAttributes) : public N_CLASS(NBiometricAttributes)
{
	N_DECLARE_OBJECT_CLASS(NFAttributes, NBiometricAttributes)

private:
	static HNFAttributes Create(NFImpressionType impressionType, NFPosition position)
	{
		HNFAttributes handle;
		NCheck(NFAttributesCreate(impressionType, position, &handle));
		return handle;
	}

	N_CLASS(NFAttributes)(HNObject handle, bool claimHandle)
		: N_CLASS(NBiometricAttributes)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NFAttributes)(NFImpressionType impressionType, NFPosition position)
		: N_CLASS(NBiometricAttributes)(Create(impressionType, position), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFAttributes);
	}

	NFImpressionType GetImpressionType() const
	{
		NFImpressionType value;
		NCheck(NFAttributesGetImpressionType(GetHandle(), &value));
		return value;
	}

	NFPosition GetPosition() const
	{
		NFPosition value;
		NCheck(NFAttributesGetPosition(GetHandle(), &value));
		return value;
	}

	NInt GetImageIndex() const
	{
		NInt value;
		NCheck(NFAttributesGetImageIndex(GetHandle(), &value));
		return value;
	}

	void SetImageIndex(NInt value)
	{
		NCheck(NFAttributesSetImageIndex(GetHandle(), value));
	}

	::Neurotec::Geometry::N_CLASS(NRect) GetBoundingRect() const
	{
		::Neurotec::Geometry::N_CLASS(NRect) value;
		NCheck(NFAttributesGetBoundingRect(GetHandle(), &value));
		return value;
	}

	void SetBoundingRect(const ::Neurotec::Geometry::N_CLASS(NRect) & value)
	{
		NCheck(NFAttributesSetBoundingRect(GetHandle(), &value));
	}
};

}}

#endif // !NF_ATTRIBUTES_HPP_INCLUDED
