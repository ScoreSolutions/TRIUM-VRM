#ifndef N_PLUGIN_H_INCLUDED
#define N_PLUGIN_H_INCLUDED

#include <NCore.h>
#include <NPluginModule.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NPluginState_
{
	npsNone = 0,
	npsLoadError = 1,
	npsNotRecognized = 2,
	npsInvalidModule = 3,
	npsInterfaceTypeMismatch = 4,
	npsInterfaceVersionMismatch = 5,
	npsInvalidInterface = 6,
	npsUnplugged = 64,
	npsUnused = 65,
	npsDisabled = 66,
	npsDuplicate = 67,
	npsIncompatibleWithOtherPlugins = 68,
	npsPluggingError = 69,
	npsPlugged = 128
} NPluginState;

N_DECLARE_TYPE(NPluginState)

N_DECLARE_OBJECT_TYPE(NPlugin, NObject)

NResult N_API NPluginPlug(HNPlugin hPlugin);
NResult N_API NPluginUnplug(HNPlugin hPlugin);
NResult N_API NPluginEnable(HNPlugin hPlugin);
NResult N_API NPluginDisable(HNPlugin hPlugin);

NResult N_API NPluginGetFileNameN(HNPlugin hPlugin, HNString * phValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NPluginGetFileNameA(HNPlugin hPlugin, NAChar * szValue, NInt valueSize);
#endif
#ifndef N_NO_UNICODE
NResult N_API NPluginGetFileNameW(HNPlugin hPlugin, NWChar * szValue, NInt valueSize);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NPluginGetFileName(HNPlugin hPlugin, NChar * szValue, NInt valueSize);
#endif
#define NPluginGetFileName N_FUNC_AW(NPluginGetFileName)

NResult N_API NPluginGetState(HNPlugin hPlugin, NPluginState * pValue);
NResult N_API NPluginGetErrorCode(HNPlugin hPlugin, NResult * pValue);
NResult N_API NPluginGetError(HNPlugin hPlugin, HNError * phValue);
NResult N_API NPluginGetLoadTime(HNPlugin hPlugin, NTimeSpan_ * pValue);
NResult N_API NPluginGetModule(HNPlugin hPlugin, HNPluginModule * phValue);
NResult N_API NPluginGetSelectedInterfaceVersion(HNPlugin hPlugin, NVersion_ * pValue);
NResult N_API NPluginGetPlugTime(HNPlugin hPlugin, NTimeSpan_ * pValue);

NResult N_API NPluginAddChanging(HNPlugin hPlugin, HNCallback hCallback);
NResult N_API NPluginAddChangingCallback(HNPlugin hPlugin, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginRemoveChanging(HNPlugin hPlugin, HNCallback hCallback);
NResult N_API NPluginRemoveChangingCallback(HNPlugin hPlugin, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginAddChanged(HNPlugin hPlugin, HNCallback hCallback);
NResult N_API NPluginAddChangedCallback(HNPlugin hPlugin, NObjectCallback pCallback, void * pParam);
NResult N_API NPluginRemoveChanged(HNPlugin hPlugin, HNCallback hCallback);
NResult N_API NPluginRemoveChangedCallback(HNPlugin hPlugin, NObjectCallback pCallback, void * pParam);

#ifdef N_CPP
}
#endif

#endif // !N_PLUGIN_H_INCLUDED
