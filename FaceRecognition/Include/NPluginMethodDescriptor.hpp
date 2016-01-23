#ifndef N_PLUGIN_METHOD_DESCRIPTOR_HPP_INCLUDED
#define N_PLUGIN_METHOD_DESCRIPTOR_HPP_INCLUDED

#include <NCustomMethodDescriptor.hpp>
#include <NCustomParameterDescriptor.hpp>
#include <NPlugin.hpp>
namespace Neurotec { namespace Plugins { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomParameterDescriptor;
using ::Neurotec::ComponentModel::HNCustomMethodDescriptor_;
#include <NPluginMethodDescriptor.h>
}}}

namespace Neurotec { namespace Plugins { namespace ComponentModel
{

class N_CLASS(NPluginMethodDescriptor) : public ::Neurotec::ComponentModel::N_CLASS(NCustomMethodDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NPluginMethodDescriptor, NCustomMethodDescriptor)

private:
	N_CLASS(NPluginMethodDescriptor)(HNObject handle, bool claimHandle)
		: ::Neurotec::ComponentModel::N_CLASS(NCustomMethodDescriptor)(handle, claimHandle)
	{
	}

};

}}}

#endif // !N_PLUGIN_METHOD_DESCRIPTOR_HPP_INCLUDED
