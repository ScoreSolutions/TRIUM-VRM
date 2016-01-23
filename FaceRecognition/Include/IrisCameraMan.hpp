#ifndef IRIS_CAMERA_MAN_HPP_INCLUDED
#define IRIS_CAMERA_MAN_HPP_INCLUDED

#include <IrisCamera.hpp>
#include <NDeviceManager.hpp>
namespace Neurotec { namespace DeviceManager
{
using ::Neurotec::Devices::HNDeviceManager;
#include <IrisCameraMan.h>
}}

namespace Neurotec { namespace DeviceManager
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Devices::" N_STRINGIZEA(N_CLASS(NDeviceManager)) " instead")
N_CLASS(IrisCameraMan)
{
	N_DECLARE_STATIC_OBJECT_CLASS(IrisCameraMan)

public:
	class IrisCameraCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(IrisCamera), N_CLASS(NObject), true, true>
	{
	private:
		IrisCameraCollection()
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(IrisCamera), N_CLASS(NObject), true, true>(NULL)
		{
		}

	protected:
		virtual NResult GetCountNative(HNObject, NInt * pValue) const
		{
			return IrisCameraManGetCameraCount(pValue);
		}

		virtual NResult GetNative(HNObject, NInt index, HIrisCamera * phValue) const
		{
			return IrisCameraManGetCamera(index, phValue);
		}

		virtual NResult GetAllNative(HNObject, HIrisCamera *, NInt) const
		{
			NThrowNotImplementedException();
		}

	public:
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(IrisCamera), N_CLASS(NObject), true, true>::Get;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(IrisCamera), N_CLASS(NObject), true, true>::operator[];

		N_CLASS(IrisCamera) * Get(const N_CLASS(NStringWrapper) & id) const
		{
			HIrisCamera handle;
			NCheck(IrisCameraManGetCameraByIdN(id.GetHandle(), &handle));
			return N_CLASS(NObject)::FromHandle<N_CLASS(IrisCamera)>(handle, false, true);
		}

		N_CLASS(IrisCamera) * operator[](const N_CLASS(NStringWrapper) & id) const
		{
			return Get(id);
		}

		friend class N_CLASS(IrisCameraMan);
	};

private:
	static ::std::auto_ptr<IrisCameraCollection> cameras;

public:
	static void Initialize()
	{
		NCheck(IrisCameraManInitialize());
	}

	static void Uninitialize()
	{
		IrisCameraManUninitialize();
	}

	::Neurotec::Devices::N_CLASS(NDeviceManager) * GetDeviceManager()
	{
		return N_CLASS(NObject)::GetObject< ::Neurotec::Devices::N_CLASS(NDeviceManager)>(IrisCameraManGetDeviceManager, true, true);
	}

	N_CLASS(IrisCamera) * GetCameraFromDevice(::Neurotec::Devices::N_CLASS(NIrisScanner) * pDevice)
	{
		HIrisCamera hIrisCamera;
		NCheck(IrisCameraManGetCameraFromDevice(N_CLASS(NObject)::ToHandle(pDevice), &hIrisCamera));
		return N_CLASS(NObject)::FromHandle<N_CLASS(IrisCamera)>(hIrisCamera, false, true);
	}

	static IrisCameraCollection * GetCameras()
	{
		return cameras.get();
	}
};
#include <NReDeprecate.h>

}}

#endif // !IRIS_CAMERA_MAN_HPP_INCLUDED
