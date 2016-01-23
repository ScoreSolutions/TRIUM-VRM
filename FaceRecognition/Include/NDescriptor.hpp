#ifndef N_DESCRIPTOR_HPP_INCLUDED
#define N_DESCRIPTOR_HPP_INCLUDED

#include <NType.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NDescriptor) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NDescriptor, NObject)

protected:
	N_CLASS(NDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NString) GetName() const
	{
		return GetString(NDescriptorGetName);
	}

	NAttributes GetAttributes() const
	{
		NAttributes value;
		NCheck(NDescriptorGetAttributes(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_DESCRIPTOR_HPP_INCLUDED
