#ifndef N_DEVICE_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_DEVICE_EVENT_DESCRIPTOR_HPP_INCLUDED

#include <NCustomEventDescriptor.hpp>
#include <NDevice.hpp>
namespace Neurotec { namespace Devices { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomEventDescriptor_;
#include <NDeviceEventDescriptor.h>
}}}

namespace Neurotec { namespace Devices { namespace ComponentModel
{

class N_CLASS(NDeviceEventDescriptor) : public ::Neurotec::ComponentModel::N_CLASS(NCustomEventDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NDeviceEventDescriptor, NCustomEventDescriptor)

private:
	N_CLASS(NDeviceEventDescriptor)(HNObject handle, bool claimHandle)
		: ::Neurotec::ComponentModel::N_CLASS(NCustomEventDescriptor)(handle, claimHandle)
	{
	}

};

}}}

#endif // !N_DEVICE_EVENT_DESCRIPTOR_HPP_INCLUDED
