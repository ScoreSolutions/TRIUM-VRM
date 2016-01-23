#ifndef N_PLUGIN_MANAGER_H_INCLUDED
#define N_PLUGIN_MANAGER_H_INCLUDED

#include <NPlugin.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NPluginManager, NObject)

NResult N_API NPluginManagerGetInstances(HNPluginManager * * parhValues, NInt * pValueCount);

NResult N_API NPluginManagerGetPluginCount(HNPluginManager hPluginManager, NInt * pValue);
NResult N_API NPluginManagerGetPlugin(HNPluginManager hPluginManager, NInt index, HNPlugin * phValue);

NResult N_API NPluginManagerAddPluginN(HNPluginManager hPluginManager, HNPluginModule hModule, HNString hDirectory, HNPlugin * phPlugin);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerAddPluginA(HNPluginManager hPluginManager, HNPluginModule hModule, const NAChar * szDirectory, HNPlugin * phPlugin);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerAddPluginW(HNPluginManager hPluginManager, HNPluginModule hModule, const NWChar * szDirectory, HNPlugin * phPlugin);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerAddPlugin(HNPluginManager hPluginManager, HNPluginModule hModule, const NChar * szDirectory, HNPlugin * phPlugin);
#endif
#define NPluginManagerAddPlugin N_FUNC_AW(NPluginManagerAddPlugin)

NResult N_API NPluginManagerAddPluginFromFileN(HNPluginManager hPluginManager, HNString hFileName, HNPlugin * phPlugin);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerAddPluginFromFileA(HNPluginManager hPluginManager, const NAChar * szFileName, HNPlugin * phPlugin);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerAddPluginFromFileW(HNPluginManager hPluginManager, const NWChar * szFileName, HNPlugin * phPlugin);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerAddPluginFromFile(HNPluginManager hPluginManager, const NChar * szFileName, HNPlugin * phPlugin);
#endif
#define NPluginManagerAddPluginFromFile N_FUNC_AW(NPluginManagerAddPluginFromFile)

NResult N_API NPluginManagerGetPluginByNameN(HNPluginManager hPluginManager, HNString hName, HNPlugin * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerGetPluginByNameA(HNPluginManager hPluginManager, const NAChar * szId, HNPlugin * phValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerGetPluginByNameW(HNPluginManager hPluginManager, const NWChar * szId, HNPlugin * phValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerGetPluginByName(HNPluginManager hPluginManager, const NChar * szId, HNPlugin * phValue);
#endif
#define NPluginManagerGetPluginByName N_FUNC_AW(NPluginManagerGetPluginByName)

NResult N_API NPluginManagerGetDisabledPluginCount(HNPluginManager hPluginManager, NInt * pValue);

NResult N_API NPluginManagerGetDisabledPluginN(HNPluginManager hPluginManager, NInt index, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerGetDisabledPluginA(HNPluginManager hPluginManager, NInt index, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerGetDisabledPluginW(HNPluginManager hPluginManager, NInt index, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerGetDisabledPlugin(HNPluginManager hPluginManager, NInt index, NChar * szValue, NInt valueSize);
#endif
#define NPluginManagerGetDisabledPlugin N_FUNC_AW(NPluginManagerGetDisabledPlugin)

NResult N_API NPluginManagerAddDisabledPluginN(HNPluginManager hPluginManager, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerAddDisabledPluginA(HNPluginManager hPluginManager, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerAddDisabledPluginW(HNPluginManager hPluginManager, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerAddDisabledPlugin(HNPluginManager hPluginManager, const NChar * szValue, NInt * pIndex);
#endif
#define NPluginManagerAddDisabledPlugin N_FUNC_AW(NPluginManagerAddDisabledPlugin)

NResult N_API NPluginManagerRemoveDisabledPluginN(HNPluginManager hPluginManager, HNString hValue, NInt * pIndex);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerRemoveDisabledPluginA(HNPluginManager hPluginManager, const NAChar * szValue, NInt * pIndex);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerRemoveDisabledPluginW(HNPluginManager hPluginManager, const NWChar * szValue, NInt * pIndex);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerRemoveDisabledPlugin(HNPluginManager hPluginManager, const NChar * szValue, NInt * pIndex);
#endif
#define NPluginManagerRemoveDisabledPlugin N_FUNC_AW(NPluginManagerRemoveDisabledPlugin)

NResult N_API NPluginManagerRemoveDisabledPluginAt(HNPluginManager hPluginManager, NInt index);
NResult N_API NPluginManagerClearDisabledPlugins(HNPluginManager hPluginManager);

NResult N_API NPluginManagerEnsurePluginSearchPerformed(HNPluginManager hPluginManager);
NResult N_API NPluginManagerRefresh(HNPluginManager hPluginManager);
NResult N_API NPluginManagerPlugAll(HNPluginManager hPluginManager);
NResult N_API NPluginManagerUnplugAll(HNPluginManager hPluginManager);

NResult N_API NPluginManagerGetPluginSearchPathN(HNPluginManager hPluginManager, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerGetPluginSearchPathA(HNPluginManager hPluginManager, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerGetPluginSearchPathW(HNPluginManager hPluginManager, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerGetPluginSearchPath(HNPluginManager hPluginManager, NChar * szValue, NInt valueSize);
#endif
#define NPluginManagerGetPluginSearchPath N_FUNC_AW(NPluginManagerGetPluginSearchPath)

NResult N_API NPluginManagerSetPluginSearchPathN(HNPluginManager hPluginManager, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerSetPluginSearchPathA(HNPluginManager hPluginManager, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerSetPluginSearchPathW(HNPluginManager hPluginManager, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerSetPluginSearchPath(HNPluginManager hPluginManager, const NChar * szValue);
#endif
#define NPluginManagerSetPluginSearchPath N_FUNC_AW(NPluginManagerSetPluginSearchPath)

NResult N_API NPluginManagerGetInterfaceTypeN(HNPluginManager hPluginManager, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginManagerGetInterfaceTypeA(HNPluginManager hPluginManager, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginManagerGetInterfaceTypeW(HNPluginManager hPluginManager, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginManagerGetInterfaceType(HNPluginManager hPluginManager, NChar * szValue, NInt valueSize);
#endif
#define NPluginManagerGetInterfaceType N_FUNC_AW(NPluginManagerGetInterfaceType)

NResult N_API NPluginManagerGetInterfaceVersions(HNPluginManager hPluginManager, NVersionRange_ * arValues, NInt valuesLength);
NResult N_API NPluginManagerAllowsUnplug(HNPluginManager hPluginManager, NBool * pValue);

typedef NResult (N_CALLBACK NPluginManagerPluginCallback)(HNPluginManager hPluginManager, HNPlugin hPlugin, void * pParam);

NResult N_API NPluginManagerAddPluginsChanging(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerAddPluginsChangingCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginManagerRemovePluginsChanging(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerRemovePluginsChangingCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginManagerAddPluginsChanged(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerAddPluginsChangedCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginManagerRemovePluginsChanged(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerRemovePluginsChangedCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginManagerAddPluginAdded(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerAddPluginAddedCallback(HNPluginManager hPluginManager, NPluginManagerPluginCallback pCallback, void * pParam);
NResult N_API NPluginManagerRemovePluginAdded(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerRemovePluginAddedCallback(HNPluginManager hPluginManager, NPluginManagerPluginCallback pCallback, void * pParam);
NResult N_API NPluginManagerAddDisabledPluginsChanging(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerAddDisabledPluginsChangingCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginManagerRemoveDisabledPluginsChanging(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerRemoveDisabledPluginsChangingCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginManagerAddDisabledPluginsChanged(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerAddDisabledPluginsChangedCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginManagerRemoveDisabledPluginsChanged(HNPluginManager hPluginManager, HNCallback hCallback);
NResult N_API NPluginManagerRemoveDisabledPluginsChangedCallback(HNPluginManager hPluginManager, NObjectCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_MANAGER_H_INCLUDED
