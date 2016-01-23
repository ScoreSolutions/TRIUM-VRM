#ifndef N_MEDIA_READER_HPP_INCLUDED
#define N_MEDIA_READER_HPP_INCLUDED

#include <NMediaSource.hpp>
#include <NSoundBuffer.hpp>
#include <NImage.hpp>
namespace Neurotec { namespace Media
{
using ::Neurotec::Sound::HNSoundBuffer;
using ::Neurotec::Images::HNImage;
#include <NMediaReader.h>
}}

namespace Neurotec { namespace Media
{

class N_CLASS(NMediaReader) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NMediaReader, NObject)

private:
	static HNMediaReader Create(N_CLASS(NMediaSource) * pSource, NMediaType mediaTypes, bool isLive, NUInt flags)
	{
		if (!pSource) NThrowArgumentNullException(N_T("pSource"));
		HNMediaReader handle;
		NCheck(NMediaReaderCreate(pSource->GetHandle(), mediaTypes, isLive, flags, &handle));
		return handle;
	}

	static HNMediaReader Create(const N_CLASS(NStringWrapper) & fileNameOrUrl, bool isUrl, NMediaType mediaTypes, bool isLive, NUInt flags)
	{
		HNMediaReader handle;
		if (isUrl)
		{
			NCheck(NMediaReaderCreateFromUrlN(fileNameOrUrl.GetHandle(), mediaTypes, isLive, flags, &handle));
		}
		else
		{
			NCheck(NMediaReaderCreateFromFileN(fileNameOrUrl.GetHandle(), mediaTypes, isLive, flags, &handle));
		}
		return handle;
	}

	N_CLASS(NMediaReader)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NMediaReader)(N_CLASS(NMediaSource) * pSource, NMediaType mediaTypes, bool isLive, NUInt flags = 0)
		: N_CLASS(NObject)(Create(pSource, mediaTypes, isLive, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMediaReader);
	}

	N_CLASS(NMediaReader)(const N_CLASS(NStringWrapper) & fileNameOrUrl, NMediaType mediaTypes, bool isLive, bool isUrl = false, NUInt flags = 0)
		: N_CLASS(NObject)(Create(fileNameOrUrl, isUrl, mediaTypes, isLive, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMediaReader);
	}

	N_CLASS(NMediaSource) * GetSource()
	{
		return GetObject<HandleType, N_CLASS(NMediaSource)>(NMediaReaderGetSource, true, true);
	}

	void Start()
	{
		NCheck(NMediaReaderStart(GetHandle()));
	}

	void Stop()
	{
		NCheck(NMediaReaderStop(GetHandle()));
	}

	void Pause()
	{
		NCheck(NMediaReaderPause(GetHandle()));
	}

	::Neurotec::Sound::N_CLASS(NSoundBuffer) * ReadAudioSample(N_CLASS(NTimeSpan) * pTimeStamp = NULL, N_CLASS(NTimeSpan) * pDuration = NULL)
	{
		HNSoundBuffer hSoundBuffer;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadAudioSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hSoundBuffer));
		try
		{
			if (pTimeStamp) *pTimeStamp = N_CLASS(NTimeSpan)(ts);
			if (pDuration) *pDuration = N_CLASS(NTimeSpan)(d);
			return FromHandle< ::Neurotec::Sound::N_CLASS(NSoundBuffer)>(hSoundBuffer);
		}
		catch (...)
		{
			Unref(hSoundBuffer);
			throw;
		}
	}

#ifndef N_FRAMEWORK_NATIVE
	::Neurotec::Sound::N_CLASS(NSoundBuffer) * ReadAudioSample(NTimeSpanType * pTimeStamp, NTimeSpanType * pDuration = NULL)
	{
		HNSoundBuffer hSoundBuffer;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadAudioSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hSoundBuffer));
		try
		{
			if (pTimeStamp) *pTimeStamp = N_CLASS(NTimeSpan)(ts);
			if (pDuration) *pDuration = N_CLASS(NTimeSpan)(d);
			return FromHandle< ::Neurotec::Sound::N_CLASS(NSoundBuffer)>(hSoundBuffer);
		}
		catch (...)
		{
			Unref(hSoundBuffer);
			throw;
		}
	}
#endif

	::Neurotec::Images::N_CLASS(NImage) * ReadVideoSample(N_CLASS(NTimeSpan) * pTimeStamp = NULL, N_CLASS(NTimeSpan) * pDuration = NULL)
	{
		HNImage hImage;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadVideoSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hImage));
		try
		{
			if (pTimeStamp) *pTimeStamp = N_CLASS(NTimeSpan)(ts);
			if (pDuration) *pDuration = N_CLASS(NTimeSpan)(d);
			return FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hImage);
		}
		catch (...)
		{
			Unref(hImage);
			throw;
		}
	}

#ifndef N_FRAMEWORK_NATIVE
	::Neurotec::Images::N_CLASS(NImage) * ReadVideoSample(NTimeSpanType * pTimeStamp, NTimeSpanType * pDuration = NULL)
	{
		HNImage hImage;
		NTimeSpan_ ts = 0, d = 0;
		NCheck(NMediaReaderReadVideoSample(GetHandle(), pTimeStamp ? &ts : NULL, pDuration ? &d : NULL, &hImage));
		try
		{
			if (pTimeStamp) *pTimeStamp = N_CLASS(NTimeSpan)(ts);
			if (pDuration) *pDuration = N_CLASS(NTimeSpan)(d);
			return FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hImage);
		}
		catch (...)
		{
			Unref(hImage);
			throw;
		}
	}
#endif

	bool IsLive()
	{
		NBool value;
		NCheck(NMediaReaderIsLive(GetHandle(), &value));
		return value != 0;
	}

	NMediaState GetState()
	{
		NMediaState value;
		NCheck(NMediaReaderGetState(GetHandle(), &value));
		return value;
	}

	N_CLASS(NTimeSpan) GetLength()
	{
		NTimeSpan_ value;
		NCheck(NMediaReaderGetLength(GetHandle(), &value));
		return N_CLASS(NTimeSpan)(value);
	}

	N_CLASS(NTimeSpan) GetPosition()
	{
		NTimeSpan_ value;
		NCheck(NMediaReaderGetPosition(GetHandle(), &value));
		return N_CLASS(NTimeSpan)(value);
	}

	void SetPosition(N_CLASS(NTimeSpan) value)
	{
		NCheck(NMediaReaderSetPosition(GetHandle(), value.GetValue()));
	}
};

}}

#endif // !N_MEDIA_READER_HPP_INCLUDED
