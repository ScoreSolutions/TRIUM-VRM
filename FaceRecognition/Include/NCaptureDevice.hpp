#include <NDevice.hpp>

#ifndef N_CAPTURE_DEVICE_HPP_INCLUDED
#define N_CAPTURE_DEVICE_HPP_INCLUDED

#include <NMediaFormat.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Media::HNMediaFormat;
using ::Neurotec::Media::NMediaType;
#include <NCaptureDevice.h>
}}

namespace Neurotec { namespace Devices
{
class N_CLASS(NCaptureDevice) : public N_CLASS(NDevice)
{
	N_DECLARE_OBJECT_CLASS(NCaptureDevice, NDevice)

protected:
	N_CLASS(NCaptureDevice)(HNObject handle, bool claimHandle)
		: N_CLASS(NDevice)(handle, claimHandle)
	{
	}

public:
	void StartCapturing()
	{
		NCheck(NCaptureDeviceStartCapturing(GetHandle()));
	}

	void StopCapturing()
	{
		NCheck(NCaptureDeviceStopCapturing(GetHandle()));
	}

	::Neurotec::Media::N_CLASS(NMediaFormat) * * GetFormats(NInt * pCount) const
	{
		return GetObjects<HandleType, ::Neurotec::Media::N_CLASS(NMediaFormat)>(NCaptureDeviceGetFormats, pCount);
	}

	::Neurotec::Media::N_CLASS(NMediaFormat) * GetCurrentFormat() const
	{
		return GetObject<HandleType, ::Neurotec::Media::N_CLASS(NMediaFormat)>(NCaptureDeviceGetCurrentFormat);
	}

	void SetCurrentFormat(::Neurotec::Media::N_CLASS(NMediaFormat) * pValue)
	{
		NCheck(NCaptureDeviceSetCurrentFormat(GetHandle(), ToHandle(pValue)));
	}

	bool IsCapturing() const
	{
		NBool value;
		NCheck(NCaptureDeviceIsCapturing(GetHandle(), &value));
		return value != 0;
	}

	NMediaType GetMediaType() const
	{
		NMediaType value;
		NCheck(NCaptureDeviceGetMediaType(GetHandle(), &value));
		return value;
	}

	void AddIsCapturingChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NCaptureDeviceAddIsCapturingChanged(GetHandle(), callback.GetHandle()));
	}

	void RemoveIsCapturingChangedCallback(Callback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(CallbackImpl, pCallback, pParam);
		NCheck(NCaptureDeviceRemoveIsCapturingChanged(GetHandle(), callback.GetHandle()));
	}
};

}}

#endif // !N_CAPTURE_DEVICE_HPP_INCLUDED
