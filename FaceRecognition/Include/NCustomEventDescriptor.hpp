#ifndef N_CUSTOM_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_EVENT_DESCRIPTOR_HPP_INCLUDED

#include <NEventDescriptor.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NCustomEventDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NCustomEventDescriptor) : public N_CLASS(NEventDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NCustomEventDescriptor, NEventDescriptor)

protected:
	N_CLASS(NCustomEventDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NEventDescriptor)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NValue) * GetData() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NCustomEventDescriptorGetData);
	}

};

}}

#endif // !N_CUSTOM_EVENT_DESCRIPTOR_HPP_INCLUDED
