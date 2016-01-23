#ifndef CAMERA_HPP_INCLUDED
#define CAMERA_HPP_INCLUDED

#include <NImage.hpp>
#include <CameraParams.hpp>
#include <NCamera.hpp>
namespace Neurotec { namespace DeviceManager
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Devices::HNCamera;
#include <Camera.h>
}}

namespace Neurotec { namespace DeviceManager
{

class N_CLASS(CameraMan);

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Devices::" N_STRINGIZEA(N_CLASS(NCamera)) " instead")
N_CLASS(Camera) : public N_CLASS(NObject)
{
private:
	N_CLASS(Camera)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	::Neurotec::Devices::N_CLASS(NCamera) * GetDevice() const
	{
		return GetObject<HandleType, ::Neurotec::Devices::N_CLASS(NCamera)>(CameraGetDevice, true, true);
	}

	N_CLASS(NString) GetId() const
	{
		return GetString(CameraGetIdN);
	}

	NInt GetVideoFormats(CameraVideoFormat * arVideoFormats)
	{
		return NCheck(CameraGetVideoFormats(GetHandle(), arVideoFormats));
	}

	CameraVideoFormat GetVideoFormat()
	{
		CameraVideoFormat value;
		NCheck(CameraGetVideoFormat(GetHandle(), &value));
		return value;
	}

	void SetVideoFormat(const CameraVideoFormat & value)
	{
		NCheck(CameraSetVideoFormat(GetHandle(), &value));
	}

	bool IsCapturing()
	{
		NBool value;
		NCheck(CameraIsCapturing(GetHandle(), &value));
		return value != 0;
	}

	void StartCapturing()
	{
		NCheck(CameraStartCapturing(GetHandle()));
	}

	void StopCapturing()
	{
		NCheck(CameraStopCapturing(GetHandle()));
	}

	::Neurotec::Images::N_CLASS(NImage) * GetCurrentFrame()
	{
		HNImage handle;
		NCheck(CameraGetCurrentFrame(GetHandle(), &handle));
		try
		{
			return FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	bool GetMirrorHorizontal()
	{
		return GetParameter<bool>(CAMERAP_MIRROR_HORIZONTAL);
	}

	void SetMirrorHorizontal(bool value)
	{
		SetParameter(CAMERAP_MIRROR_HORIZONTAL, value);
	}

	bool GetMirrorVertical()
	{
		return GetParameter<bool>(CAMERAP_MIRROR_VERTICAL);
	}

	void SetMirrorVertical(bool value)
	{
		SetParameter(CAMERAP_MIRROR_VERTICAL, value);
	}

	bool GetAutomaticSettings()
	{
		return GetParameter<bool>(CAMERAP_AUTOMATIC_SETTINGS);
	}

	void SetAutomaticSettings(bool value)
	{
		SetParameter(CAMERAP_AUTOMATIC_SETTINGS, value);
	}

	NUInt GetGain()
	{
		return GetParameter<NUInt>(CAMERAP_GAIN);
	}

	void SetGain(NUInt value)
	{
		SetParameter(CAMERAP_GAIN, value);
	}

	NUInt GetGainMin()
	{
		return GetParameter<NUInt>(CAMERAP_GAIN_MIN);
	}

	NUInt GetGainMax()
	{
		return GetParameter<NUInt>(CAMERAP_GAIN_MAX);
	}

	NUInt GetExposure()
	{
		return GetParameter<NUInt>(CAMERAP_EXPOSURE);
	}

	void SetExposure(NUInt value)
	{
		SetParameter(CAMERAP_EXPOSURE, value);
	}

	NUInt GetExposureMin()
	{
		return GetParameter<NUInt>(CAMERAP_EXPOSURE_MIN);
	}

	NUInt GetExposureMax()
	{
		return GetParameter<NUInt>(CAMERAP_EXPOSURE_MAX);
	}

	N_CLASS(NString) GetIpUsername()
	{
		return GetParameter<N_CLASS(NString)>(CAMERAP_IP_USERNAME);
	}

	void SetIpUsername(const N_CLASS(NStringWrapper) & value)
	{
		SetParameter(CAMERAP_IP_USERNAME, value);
	}

	N_CLASS(NString) GetIpPassword()
	{
		return GetParameter<N_CLASS(NString)>(CAMERAP_IP_PASSWORD);
	}

	void SetIpPassword(const N_CLASS(NStringWrapper) & value)
	{
		SetParameter(CAMERAP_IP_PASSWORD, value);
	}

	N_CLASS(NString) GetIpChannelId()
	{
		return GetParameter<N_CLASS(NString)>(CAMERAP_IP_CHANNEL_ID);
	}

	void SetIpChannelId(const N_CLASS(NStringWrapper) & value)
	{
		SetParameter(CAMERAP_IP_CHANNEL_ID, value);
	}

	N_CLASS(NString) GetIpChannelName()
	{
		return GetParameter<N_CLASS(NString)>(CAMERAP_IP_CHANNEL_NAME);
	}

	void SetIpChannelName(const N_CLASS(NStringWrapper) & value)
	{
		SetParameter(CAMERAP_IP_CHANNEL_NAME, value);
	}

	N_DECLARE_OBJECT_CLASS(Camera, NObject)
};
#include <NReDeprecate.h>

}}

#endif // !CAMERA_HPP_INCLUDED
