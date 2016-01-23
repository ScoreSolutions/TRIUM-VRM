#ifndef N_CUSTOM_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_METHOD_DESCRIPTOR_HPP_INCLUDED

#include <NMethodDescriptor.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NCustomMethodDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NCustomMethodDescriptor) : public N_CLASS(NMethodDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NCustomMethodDescriptor, NMethodDescriptor)

protected:
	N_CLASS(NCustomMethodDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NMethodDescriptor)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NValue) * GetData() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NCustomMethodDescriptorGetData);
	}

};

}}

#endif // !N_CUSTOM_METHOD_DESCRIPTOR_HPP_INCLUDED
