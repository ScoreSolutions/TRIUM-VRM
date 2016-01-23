#ifndef N_DEVICE_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_DEVICE_PROPERTY_DESCRIPTOR_HPP_INCLUDED

#include <NCustomPropertyDescriptor.hpp>
#include <NDevice.hpp>
namespace Neurotec { namespace Devices { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomPropertyDescriptor_;
#include <NDevicePropertyDescriptor.h>
}}}

namespace Neurotec { namespace Devices { namespace ComponentModel
{

class N_CLASS(NDevicePropertyDescriptor) : public ::Neurotec::ComponentModel::N_CLASS(NCustomPropertyDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NDevicePropertyDescriptor, NCustomPropertyDescriptor)

private:
	N_CLASS(NDevicePropertyDescriptor)(HNObject handle, bool claimHandle)
		: ::Neurotec::ComponentModel::N_CLASS(NCustomPropertyDescriptor)(handle, claimHandle)
	{
	}

};

}}}

#endif // !N_DEVICE_PROPERTY_DESCRIPTOR_HPP_INCLUDED
