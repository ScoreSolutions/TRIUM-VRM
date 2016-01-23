#ifndef N_PLUGIN_MODULE_HPP_INCLUDED
#define N_PLUGIN_MODULE_HPP_INCLUDED

#include <NModule.hpp>
namespace Neurotec { namespace Plugins
{
#include <NPluginModule.h>
}}
#include <NMemory.hpp>

namespace Neurotec { namespace Plugins
{

class N_CLASS(NPluginModule) : public N_CLASS(NModule)
{
	N_DECLARE_OBJECT_CLASS(NPluginModule, NModule)

private:
	static HNPluginModule Create()
	{
		HNPluginModule handle;
		NCheck(NPluginModuleCreate(&handle));
		return handle;
	}

	N_CLASS(NPluginModule)(HNObject handle, bool claimHandle)
		: N_CLASS(NModule)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NPluginModule)()
		: N_CLASS(NModule)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NPluginModule);
	}

	N_CLASS(NString) GetPluginName() const
	{
		return GetString(NPluginModuleGetPluginNameN);
	}

	void SetPluginName(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NPluginModuleSetPluginNameN, value);
	}

	N_CLASS(NString) GetInterfaceType() const
	{
		return GetString(NPluginModuleGetInterfaceTypeN);
	}

	void SetInterfaceType(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NPluginModuleSetInterfaceTypeN, value);
	}

	NInt GetInterfaceVersions(N_CLASS(NVersionRange) * arValues, NInt valuesLength) const
	{
		return NCheck(NPluginModuleGetInterfaceVersions(GetHandle(), reinterpret_cast<NVersionRange_ *>(arValues), valuesLength));
	}

	N_CLASS(NVersionRange) * GetInterfaceVersions(NInt * pCount) const
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		auto_array<N_CLASS(NVersionRange)> values(GetInterfaceVersions(NULL, 0));
		*pCount = GetInterfaceVersions(values.get(), values.size());
		return values.release();
	}

	NInt GetPriority() const
	{
		NInt value;
		NCheck(NPluginModuleGetPriority(GetHandle(), &value));
		return value;
	}

	void SetPriority(NInt value)
	{
		NCheck(NPluginModuleSetPriority(GetHandle(), value));
	}

	N_CLASS(NString) GetIncompatiblePlugins() const
	{
		return GetString(NPluginModuleGetIncompatiblePluginsN);
	}

	void SetIncompatiblePlugins(const N_CLASS(NStringWrapper) & value)
	{
		SetString(NPluginModuleSetIncompatiblePluginsN, value);
	}
};

}}

#endif // !N_PLUGIN_MODULE_HPP_INCLUDED
