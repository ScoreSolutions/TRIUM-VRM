#ifndef N_CORE_LIBRARY_CPP_INCLUDED
#define N_CORE_LIBRARY_CPP_INCLUDED

#include <NCore.hpp>
#include <NWeakReference.hpp>
#include <NList.hpp>
#include <NListList.hpp>
#include <NQueue.hpp>
#include <NStack.hpp>
#include <NEvent.hpp>
#include <NParameters.hpp>
#include <NMonitor.hpp>
#include <NInterlocked.hpp>
#include <NRWLock.hpp>
#include <NWaitObject.hpp>
#include <NMutex.hpp>
#include <NSemaphore.hpp>
#include <NSyncEvent.hpp>
#include <NThread.hpp>
#include <NTls.hpp>
#include <NSyncChangeObject.hpp>
#include <NPluginManager.hpp>
#include <NStopwatch.hpp>
#include <NEncoding.hpp>
#include <NStringBuilder.hpp>
#include <NFile.hpp>
#include <NDirectory.hpp>
#include <NPath.hpp>
#include <NEnvironment.hpp>
#include <NFileStream.hpp>
#include <NMemoryStream.hpp>
#include <NBufferedStream.hpp>
#include <NCustomStream.hpp>
#include <NBinaryReader.hpp>
#include <NBinaryWriter.hpp>
#include <NTextReader.hpp>
#include <NTextWriter.hpp>
#include <NStreamReader.hpp>
#include <NStreamWriter.hpp>
#include <NStringReader.hpp>
#include <NStringWriter.hpp>
#include <NConsole.hpp>
#include <NEnum.hpp>
#include <NValue.hpp>
#include <NArray.hpp>
#include <NPropertyBag.hpp>
#include <NExpandableObject.hpp>
#include <NTypeDescriptor.hpp>
#include <NCustomParameterDescriptor.hpp>
#include <NCustomMethodDescriptor.hpp>
#include <NCustomPropertyDescriptor.hpp>
#include <NCustomEventDescriptor.hpp>
#include <NPluginMethodDescriptor.hpp>
#include <NPluginPropertyDescriptor.hpp>
#include <NPluginEventDescriptor.hpp>
#include <NParameterBag.hpp>

using namespace ::Neurotec::Plugins;
using namespace ::Neurotec::Plugins::ComponentModel;
using namespace ::Neurotec::IO;

namespace Neurotec
{

#if defined(N_FRAMEWORK_MFC)
	N_IMPLEMENT_CLASS(NException, Exception)
	N_IMPLEMENT_CLASS(NObject, Object)
	namespace Threading
	{
		N_IMPLEMENT_CLASS(NTls, Object)
	}
#elif defined(N_FRAMEWORK_WX)
	N_IMPLEMENT_CLASS(NException, Object)
	N_IMPLEMENT_CLASS(NObject, Object)
	namespace Threading
	{
		N_IMPLEMENT_CLASS(NTls, Object)
	}
/*#elif defined(N_FRAMEWORK_QT)
	N_IMPLEMENT_CLASS(NException, Object)
	N_IMPLEMENT_CLASS(NObject, Object)
	namespace Threading
	{
		N_IMPLEMENT_CLASS(NTls, Object)
	}
*/#else
	const N_CLASS(NClass) N_CLASS(NObjectBase)::N_JOIN_SYMBOLS(class, N_CLASS(NObjectBase)) = { N_STRINGIZE(N_CLASS(NObjectBase)), NULL, sizeof(N_CLASS(NObjectBase)) };
	N_IMPLEMENT_CLASS(NException, NObjectBase)
	N_IMPLEMENT_CLASS(NObject, NObjectBase)
	namespace Threading
	{
		N_IMPLEMENT_CLASS(NTls, NObjectBase)
	}
#endif

::Neurotec::Threading::NMonitorType N_CLASS(NObject)::warmedUpTypesLock N_MONITOR_ARGS_P;
N_HASH_SET<N_CLASS(NObject)::NativeTypeOfProc> N_CLASS(NObject)::warmedUpTypes;
::Neurotec::Threading::NMonitorType N_CLASS(NObject)::typeMapLock N_MONITOR_ARGS_P;
N_HASH_MAP<HNType, N_CLASS(NObject)::FromHandleProc> N_CLASS(NObject)::typeMap;
::Neurotec::Threading::NMonitorType N_CLASS(NObject)::objectMapLock N_MONITOR_ARGS_P;
N_HASH_MAP<HNObject, N_CLASS(NObject) *> N_CLASS(NObject)::objectMap;
N_CLASS(NObject)::N_JOIN_SYMBOLS(N_CLASS(NObject), Initializer) N_CLASS(NObject)::N_JOIN_SYMBOLS(initializer, N_CLASS(NObject));
N_IMPLEMENT_OBJECT_CLASS_4(NType, NObject, NModule, NBuffer, NStream, NValue)
N_IMPLEMENT_OBJECT_CLASS_2(NValue, NObject, NArray, NPropertyBag)
N_IMPLEMENT_OBJECT_CLASS(NArray, NValue)
N_IMPLEMENT_OBJECT_CLASS_1(NModule, NObject, NPluginModule)
N_IMPLEMENT_OBJECT_CLASS_1(NPropertyBag, NObject, NExpandableObject)
N_IMPLEMENT_OBJECT_CLASS_1(NExpandableObject, NObject, NPropertyBag)

N_IMPLEMENT_CLASS(NCoreException, NException)
namespace Threading
{
N_IMPLEMENT_CLASS(NAbandonedMutexException, NCoreException)
N_IMPLEMENT_OBJECT_CLASS_3(NWaitObject, NObject, NMutex, NSemaphore, NSyncEvent)
N_IMPLEMENT_OBJECT_CLASS(NMutex, NWaitObject)
N_IMPLEMENT_OBJECT_CLASS(NSemaphore, NWaitObject)
N_IMPLEMENT_OBJECT_CLASS(NSyncEvent, NWaitObject)
N_IMPLEMENT_OBJECT_CLASS(NThread, NObject)
}
N_IMPLEMENT_CLASS(NArgumentException, NCoreException)
N_IMPLEMENT_CLASS(NArgumentNullException, NArgumentException)
N_IMPLEMENT_CLASS(NArgumentOutOfRangeException, NArgumentException)
N_IMPLEMENT_CLASS(NInvalidEnumArgumentException, NArgumentException)
N_IMPLEMENT_CLASS(NArithmeticException, NCoreException)
N_IMPLEMENT_CLASS(NOverflowException, NArithmeticException)
N_IMPLEMENT_CLASS(NBadImageFormatException, NCoreException)
N_IMPLEMENT_CLASS(NDllNotFoundException, NCoreException)
N_IMPLEMENT_CLASS(NEntryPointNotFoundException, NCoreException)
N_IMPLEMENT_CLASS(NFormatException, NCoreException)
namespace IO
{
N_IMPLEMENT_CLASS(NFileFormatException, NFormatException)
N_IMPLEMENT_OBJECT_CLASS(NBuffer, NObject)
N_IMPLEMENT_OBJECT_CLASS_4(NStream, NObject, NFileStream, NMemoryStream, NBufferedStream, NCustomStream)
N_IMPLEMENT_OBJECT_CLASS(NFileStream, NStream)
N_IMPLEMENT_OBJECT_CLASS(NMemoryStream, NStream)
N_IMPLEMENT_OBJECT_CLASS(NBufferedStream, NStream)
N_IMPLEMENT_OBJECT_CLASS(NCustomStream, NStream)
N_IMPLEMENT_OBJECT_CLASS(NBinaryReader, NObject)
N_IMPLEMENT_OBJECT_CLASS(NBinaryWriter, NObject)
N_IMPLEMENT_OBJECT_CLASS_2(NTextReader, NObject, NStreamReader, NStringReader)
N_IMPLEMENT_OBJECT_CLASS_2(NTextWriter, NObject, NStreamWriter, NStringWriter)
N_IMPLEMENT_OBJECT_CLASS(NStreamReader, NTextReader)
N_IMPLEMENT_OBJECT_CLASS(NStringReader, NTextReader)
N_IMPLEMENT_OBJECT_CLASS(NStreamWriter, NTextWriter)
N_IMPLEMENT_OBJECT_CLASS(NStringWriter, NTextWriter)
}
N_IMPLEMENT_CLASS(NIndexOutOfRangeException, NCoreException)
N_IMPLEMENT_CLASS(NInvalidCastException, NCoreException)
N_IMPLEMENT_CLASS(NInvalidOperationException, NCoreException)
namespace IO
{
N_IMPLEMENT_CLASS(NIOException, NCoreException)
N_IMPLEMENT_CLASS(NDirectoryNotFoundException, NIOException)
N_IMPLEMENT_CLASS(NDriveNotFoundException, NIOException)
N_IMPLEMENT_CLASS(NEndOfStreamException, NIOException)
N_IMPLEMENT_CLASS(NFileNotFoundException, NIOException)
N_IMPLEMENT_CLASS(NFileLoadException, NIOException)
N_IMPLEMENT_CLASS(NPathTooLongException, NIOException)
}
namespace Net
{
N_IMPLEMENT_CLASS(NSocketException, NIOException)
}
namespace Collections
{
N_IMPLEMENT_CLASS(NKeyNotFoundException, NCoreException)
}
N_IMPLEMENT_CLASS(NNotImplementedException, NCoreException)
N_IMPLEMENT_CLASS(NNotSupportedException, NCoreException)
N_IMPLEMENT_CLASS(NNullReferenceException, NCoreException)
N_IMPLEMENT_CLASS(NOutOfMemoryException, NCoreException)
namespace Security
{
N_IMPLEMENT_CLASS(NSecurityException, NCoreException)
}
N_IMPLEMENT_CLASS(NTimeoutException, NCoreException)
N_IMPLEMENT_CLASS(NExternalException, NCoreException)
N_IMPLEMENT_CLASS(NClrException, NExternalException)
N_IMPLEMENT_CLASS(NComException, NExternalException)
N_IMPLEMENT_CLASS(NCppException, NExternalException)
N_IMPLEMENT_CLASS(NJvmException, NExternalException)
N_IMPLEMENT_CLASS(NMacException, NExternalException)
N_IMPLEMENT_CLASS(NSysException, NExternalException)
N_IMPLEMENT_CLASS(NWin32Exception, NExternalException)
N_IMPLEMENT_CLASS(NParameterException, NCoreException)
N_IMPLEMENT_CLASS(NParameterReadOnlyException, NParameterException)
N_IMPLEMENT_CLASS(NNotActivatedException, NCoreException)
N_IMPLEMENT_CLASS(NeurotecException, NCoreException)

namespace Plugins
{
N_IMPLEMENT_OBJECT_CLASS(NPluginModule, NModule)
N_IMPLEMENT_OBJECT_CLASS_1(NPlugin, NObject, NPluginManager)
N_IMPLEMENT_OBJECT_CLASS_1(NPluginManager, NObject, NPlugin)
namespace ComponentModel
{
N_IMPLEMENT_OBJECT_CLASS(NPluginMethodDescriptor, NCustomMethodDescriptor)
N_IMPLEMENT_OBJECT_CLASS(NPluginPropertyDescriptor, NCustomPropertyDescriptor)
N_IMPLEMENT_OBJECT_CLASS(NPluginEventDescriptor, NCustomEventDescriptor)
}
}

namespace Diagnostics
{
N_IMPLEMENT_OBJECT_CLASS(NStopwatch, NObject)
} // namespace Diagnostics

namespace ComponentModel
{
N_IMPLEMENT_OBJECT_CLASS_2(NDescriptor, NObject, NParameterDescriptor, NMemberDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NParameterDescriptor, NDescriptor, NCustomParameterDescriptor)
N_IMPLEMENT_OBJECT_CLASS_3(NMemberDescriptor, NDescriptor, NMethodDescriptor, NPropertyDescriptor, NEventDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NMethodDescriptor, NMemberDescriptor, NCustomMethodDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NPropertyDescriptor, NMemberDescriptor, NCustomPropertyDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NEventDescriptor, NMemberDescriptor, NCustomEventDescriptor)
N_IMPLEMENT_OBJECT_CLASS(NCustomParameterDescriptor, NParameterDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NCustomMethodDescriptor, NMethodDescriptor, NPluginMethodDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NCustomPropertyDescriptor, NPropertyDescriptor, NPluginPropertyDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NCustomEventDescriptor, NEventDescriptor, NPluginEventDescriptor)
N_IMPLEMENT_OBJECT_CLASS_1(NParameterBag, NObject, NPropertyBag)

}

}

#endif // !N_CORE_LIBRARY_CPP_INCLUDED
