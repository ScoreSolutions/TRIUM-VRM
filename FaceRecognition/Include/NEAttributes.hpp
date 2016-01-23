#ifndef NE_ATTRIBUTES_HPP_INCLUDED
#define NE_ATTRIBUTES_HPP_INCLUDED

#include <NBiometricAttributes.hpp>
#include <NGeometry.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Geometry::NRect_;
#include <NEAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NEAttributes) : public N_CLASS(NBiometricAttributes)
{
	N_DECLARE_OBJECT_CLASS(NEAttributes, NBiometricAttributes)

private:
	static HNEAttributes Create(NEPosition position)
	{
		HNEAttributes handle;
		NCheck(NEAttributesCreate(position, &handle));
		return handle;
	}

	N_CLASS(NEAttributes)(HNObject handle, bool claimHandle)
		: N_CLASS(NBiometricAttributes)(handle, claimHandle)
	{
	}

public:
	explicit N_CLASS(NEAttributes)(NEPosition position)
		: N_CLASS(NBiometricAttributes)(Create(position), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NEAttributes);
	}

	NEPosition GetPosition() const
	{
		NEPosition value;
		NCheck(NEAttributesGetPosition(GetHandle(), &value));
		return value;
	}

	NInt GetImageIndex() const
	{
		NInt value;
		NCheck(NEAttributesGetImageIndex(GetHandle(), &value));
		return value;
	}

	void SetImageIndex(NInt value)
	{
		NCheck(NEAttributesSetImageIndex(GetHandle(), value));
	}

	::Neurotec::Geometry::N_CLASS(NRect) GetBoundingRect() const
	{
		::Neurotec::Geometry::N_CLASS(NRect) value;
		NCheck(NEAttributesGetBoundingRect(GetHandle(), &value));
		return value;
	}

	void SetBoundingRect(const ::Neurotec::Geometry::N_CLASS(NRect) & value)
	{
		NCheck(NEAttributesSetBoundingRect(GetHandle(), &value));
	}
};

}}

#endif // !NE_ATTRIBUTES_HPP_INCLUDED
