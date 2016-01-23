#ifndef CAMERA_MAN_HPP_INCLUDED
#define CAMERA_MAN_HPP_INCLUDED

#include <Camera.hpp>
#include <NDeviceManager.hpp>
namespace Neurotec { namespace DeviceManager
{
using ::Neurotec::Devices::HNDeviceManager;
#include <CameraMan.h>
}}

namespace Neurotec { namespace DeviceManager
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Devices::" N_STRINGIZEA(N_CLASS(NDeviceManager)) " instead")
N_CLASS(CameraMan)
{
	N_DECLARE_STATIC_OBJECT_CLASS(CameraMan)

public:
	class CameraCollection : public ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(Camera), N_CLASS(NObject), true, true>
	{
	private:
		CameraCollection()
			: ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(Camera), N_CLASS(NObject), true, true>(NULL)
		{
		}

	protected:
		virtual NResult GetCountNative(HNObject, NInt * pValue) const
		{
			return CameraManGetCameraCount(pValue);
		}

		virtual NResult GetNative(HNObject, NInt index, HCamera * phValue) const
		{
			return CameraManGetCamera(index, phValue);
		}

		virtual NResult GetAllNative(HNObject, HCamera *, NInt) const
		{
			NThrowNotImplementedException();
		}

	public:
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(Camera), N_CLASS(NObject), true, true>::Get;
		using ::Neurotec::Collections::N_CLASS(NObjectReadOnlyCollection)<N_CLASS(Camera), N_CLASS(NObject), true, true>::operator[];

		N_CLASS(Camera) * Get(const N_CLASS(NStringWrapper) & id) const
		{
			HCamera handle;
			NCheck(CameraManGetCameraByIdN(id.GetHandle(), &handle));
			return N_CLASS(NObject)::FromHandle<N_CLASS(Camera)>(handle, false, true);
		}

		N_CLASS(Camera) * operator[](const N_CLASS(NStringWrapper) & id) const
		{
			return Get(id);
		}

		friend class N_CLASS(CameraMan);
	};

private:
	static ::std::auto_ptr<CameraCollection> cameras;

public:
	static void Initialize()
	{
		NCheck(CameraManInitialize());
	}

	static void Uninitialize()
	{
		CameraManUninitialize();
	}

	::Neurotec::Devices::N_CLASS(NDeviceManager) * GetDeviceManager()
	{
		return N_CLASS(NObject)::GetObject< ::Neurotec::Devices::N_CLASS(NDeviceManager)>(CameraManGetDeviceManager, true, true);
	}

	N_CLASS(Camera) * GetCameraFromDevice(::Neurotec::Devices::N_CLASS(NCamera) * pDevice)
	{
		HCamera hCamera;
		NCheck(CameraManGetCameraFromDevice(N_CLASS(NObject)::ToHandle(pDevice), &hCamera));
		return N_CLASS(NObject)::FromHandle<N_CLASS(Camera)>(hCamera, false, true);
	}

	static CameraCollection * GetCameras()
	{
		return cameras.get();
	}
};
#include <NReDeprecate.h>

}}

#endif // !CAMERA_MAN_HPP_INCLUDED
