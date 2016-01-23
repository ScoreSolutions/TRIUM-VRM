#ifndef N_PLUGIN_EVENT_DESCRIPTOR_HPP_INCLUDED
#define N_PLUGIN_EVENT_DESCRIPTOR_HPP_INCLUDED

#include <NCustomEventDescriptor.hpp>
#include <NPlugin.hpp>
namespace Neurotec { namespace Plugins { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomEventDescriptor_;
#include <NPluginEventDescriptor.h>
}}}

namespace Neurotec { namespace Plugins { namespace ComponentModel
{

class N_CLASS(NPluginEventDescriptor) : public ::Neurotec::ComponentModel::N_CLASS(NCustomEventDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NPluginEventDescriptor, NCustomEventDescriptor)

private:
	N_CLASS(NPluginEventDescriptor)(HNObject handle, bool claimHandle)
		: ::Neurotec::ComponentModel::N_CLASS(NCustomEventDescriptor)(handle, claimHandle)
	{
	}

};

}}}

#endif // !N_PLUGIN_EVENT_DESCRIPTOR_HPP_INCLUDED
