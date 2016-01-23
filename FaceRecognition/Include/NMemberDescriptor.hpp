#ifndef N_MEMBER_DESCRIPTOR_HPP_INCLUDED
#define N_MEMBER_DESCRIPTOR_HPP_INCLUDED

#include <NDescriptor.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NMemberDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NMemberDescriptor) : public N_CLASS(NDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NMemberDescriptor, NDescriptor)

protected:
	N_CLASS(NMemberDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NDescriptor)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NType) * GetComponentType() const
	{
		return GetObject<HandleType, N_CLASS(NType)>(NMemberDescriptorGetComponentType, true, true);
	}
};

}}

#endif // !N_MEMBER_DESCRIPTOR_HPP_INCLUDED
