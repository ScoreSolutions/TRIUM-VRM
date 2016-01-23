#ifndef N_DEVICE_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_DEVICE_METHOD_DESCRIPTOR_HPP_INCLUDED

#include <NCustomMethodDescriptor.hpp>
#include <NCustomParameterDescriptor.hpp>
#include <NDevice.hpp>
namespace Neurotec { namespace Devices { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomParameterDescriptor;
using ::Neurotec::ComponentModel::HNCustomMethodDescriptor_;
#include <NDeviceMethodDescriptor.h>
}}}

namespace Neurotec { namespace Devices { namespace ComponentModel
{

class N_CLASS(NDeviceMethodDescriptor) : public ::Neurotec::ComponentModel::N_CLASS(NCustomMethodDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NDeviceMethodDescriptor, NCustomMethodDescriptor)

private:
	N_CLASS(NDeviceMethodDescriptor)(HNObject handle, bool claimHandle)
		: ::Neurotec::ComponentModel::N_CLASS(NCustomMethodDescriptor)(handle, claimHandle)
	{
	}

};

}}}

#endif // !N_DEVICE_METHOD_DESCRIPTOR_HPP_INCLUDED
