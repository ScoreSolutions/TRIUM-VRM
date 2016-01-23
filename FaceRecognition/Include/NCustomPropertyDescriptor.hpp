#ifndef N_CUSTOM_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_CUSTOM_PROPERTY_DESCRIPTOR_HPP_INCLUDED

#include <NPropertyDescriptor.hpp>
namespace Neurotec { namespace ComponentModel
{
#include <NCustomPropertyDescriptor.h>
}}

namespace Neurotec { namespace ComponentModel
{

class N_CLASS(NCustomPropertyDescriptor) : public N_CLASS(NPropertyDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NCustomPropertyDescriptor, NPropertyDescriptor)

protected:
	N_CLASS(NCustomPropertyDescriptor)(HNObject handle, bool claimHandle)
		: N_CLASS(NPropertyDescriptor)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NValue) * GetData() const
	{
		return GetObject<HandleType, N_CLASS(NValue)>(NCustomPropertyDescriptorGetData);
	}

};

}}

#endif // !N_CUSTOM_PROPERTY_DESCRIPTOR_HPP_INCLUDED
