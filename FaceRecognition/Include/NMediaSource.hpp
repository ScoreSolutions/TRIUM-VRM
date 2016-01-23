#ifndef N_MEDIA_SOURCE_HPP_INCLUDED
#define N_MEDIA_SOURCE_HPP_INCLUDED

#include <NMediaFormat.hpp>
namespace Neurotec { namespace Media
{
#include <NMediaSource.h>
}}

namespace Neurotec { namespace Media
{

#undef NMS_DO_NOT_USE_DIRECT_SHOW
#undef NMS_DO_NOT_USE_WINDOWS_MEDIA_FOUNDATION
#undef NMS_PREFER_DIRECT_SHOW
#undef NMS_ALLOW_DUPLICATE_DEVICES

const NUInt NMS_DO_NOT_USE_DIRECT_SHOW              = 0x00000001;
const NUInt NMS_DO_NOT_USE_WINDOWS_MEDIA_FOUNDATION = 0x00000002;
const NUInt NMS_PREFER_DIRECT_SHOW                  = 0x00000004;
const NUInt NMS_ALLOW_DUPLICATE_DEVICES             = 0x00000008;

class N_CLASS(NMediaSource) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NMediaSource, NObject)

private:
	N_CLASS(NMediaSource)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NMediaSource) * * EnumDevices(NMediaType mediaType, NInt * pCount, NUInt flags = 0)
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		HNMediaSource * arhDevices = NULL;
		NInt deviceCount = 0;
		NCheck(NMediaSourceEnumDevices(mediaType, flags, &arhDevices, &deviceCount));
		try
		{
			N_CLASS(NObjectArray)<N_CLASS(NMediaSource)> devices(arhDevices, deviceCount);
			arhDevices = NULL; deviceCount = 0;
			return devices.ToArray(pCount);
		}
		catch (...)
		{
			UnrefArray(arhDevices, deviceCount);
			throw;
		}
	}

	static N_CLASS(NMediaSource) * FromFile(const N_CLASS(NStringWrapper) & fileName, NUInt flags = 0)
	{
		HNMediaSource handle;
		NCheck(NMediaSourceCreateFromFileN(fileName.GetHandle(), flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NMediaSource)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NMediaSource) * FromUrl(const N_CLASS(NStringWrapper) & url, NUInt flags = 0)
	{
		HNMediaSource handle;
		NCheck(NMediaSourceCreateFromUrlN(url.GetHandle(), flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NMediaSource)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	N_CLASS(NMediaFormat) * * GetFormats(NMediaType mediaType, NInt * pCount) const
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		HNMediaFormat * arhFormats = NULL;
		NInt formatCount = 0;
		NCheck(NMediaSourceGetFormats(GetHandle(), mediaType, &arhFormats, &formatCount));
		try
		{
			N_CLASS(NObjectArray)<N_CLASS(NMediaFormat)> formats(arhFormats, formatCount);
			arhFormats = NULL; formatCount = 0;
			return formats.ToArray(pCount);
		}
		catch (...)
		{
			UnrefArray(arhFormats, formatCount);
			throw;
		}
	}

	N_CLASS(NMediaFormat) * GetCurrentFormat(NMediaType mediaType) const
	{
		HNMediaFormat hFormat;
		NCheck(NMediaSourceGetCurrentFormat(GetHandle(), mediaType, &hFormat));
		try
		{
			return FromHandle<N_CLASS(NMediaFormat)>(hFormat);
		}
		catch (...)
		{
			Unref(hFormat);
			throw;
		}
	}

	void SetCurrentFormat(NMediaType mediaType, N_CLASS(NMediaFormat) * pValue)
	{
		NCheck(NMediaSourceSetCurrentFormat(GetHandle(), mediaType, ToHandle(pValue)));
	}

	N_CLASS(NString) GetId() const
	{
		return GetString(NMediaSourceGetIdN);
	}

	N_CLASS(NString) GetDisplayName() const
	{
		return GetString(NMediaSourceGetDisplayNameN);
	}

	NMediaType GetMediaType() const
	{
		NMediaType value;
		NCheck(NMediaSourceGetMediaType(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_MEDIA_SOURCE_HPP_INCLUDED
