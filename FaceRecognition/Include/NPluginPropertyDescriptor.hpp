#ifndef N_PLUGIN_PROPERTY_DESCRIPTOR_HPP_INCLUDED
#define N_PLUGIN_PROPERTY_DESCRIPTOR_HPP_INCLUDED

#include <NCustomPropertyDescriptor.hpp>
#include <NPlugin.hpp>
namespace Neurotec { namespace Plugins { namespace ComponentModel
{
using ::Neurotec::ComponentModel::HNCustomPropertyDescriptor_;
#include <NPluginPropertyDescriptor.h>
}}}

namespace Neurotec { namespace Plugins { namespace ComponentModel
{

class N_CLASS(NPluginPropertyDescriptor) : public ::Neurotec::ComponentModel::N_CLASS(NCustomPropertyDescriptor)
{
	N_DECLARE_OBJECT_CLASS(NPluginPropertyDescriptor, NCustomPropertyDescriptor)

private:
	N_CLASS(NPluginPropertyDescriptor)(HNObject handle, bool claimHandle)
		: ::Neurotec::ComponentModel::N_CLASS(NCustomPropertyDescriptor)(handle, claimHandle)
	{
	}

};

}}}

#endif // !N_PLUGIN_PROPERTY_DESCRIPTOR_HPP_INCLUDED
