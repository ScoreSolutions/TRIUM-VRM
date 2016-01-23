#include <NMediaFormat.hpp>

#ifndef N_AUDIO_FORMAT_HPP_INCLUDED
#define N_AUDIO_FORMAT_HPP_INCLUDED

namespace Neurotec { namespace Media
{
#include <NAudioFormat.h>
}}

namespace Neurotec { namespace Media
{

#undef N_AUDIO_FORMAT_UNKNOWN
#undef N_AUDIO_FORMAT_PCM
#undef N_AUDIO_FORMAT_FLOAT
#undef N_AUDIO_FORMAT_DTS
#undef N_AUDIO_FORMAT_DRM
#undef N_AUDIO_FORMAT_MSP1
#undef N_AUDIO_FORMAT_MPEG
#undef N_AUDIO_FORMAT_MP3
#undef N_AUDIO_FORMAT_DOLBY_AC3_SPDIF
#undef N_AUDIO_FORMAT_RAW_AAC1
#undef N_AUDIO_FORMAT_WM_AUDIO_V8
#undef N_AUDIO_FORMAT_WM_AUDIO_V9
#undef N_AUDIO_FORMAT_WM_AUDIO_LOSSLESS
#undef N_AUDIO_FORMAT_WMA_SPDIF
#undef N_AUDIO_FORMAT_ADTS
#undef N_AUDIO_FORMAT_AAC

const NUInt N_AUDIO_FORMAT_UNKNOWN           =      0;
const NUInt N_AUDIO_FORMAT_PCM               =      1;
const NUInt N_AUDIO_FORMAT_FLOAT             = 0x0003;
const NUInt N_AUDIO_FORMAT_DTS               = 0x0008;
const NUInt N_AUDIO_FORMAT_DRM               = 0x0009;
const NUInt N_AUDIO_FORMAT_MSP1              = 0x000A;
const NUInt N_AUDIO_FORMAT_MPEG              = 0x0050;
const NUInt N_AUDIO_FORMAT_MP3               = 0x0055;
const NUInt N_AUDIO_FORMAT_DOLBY_AC3_SPDIF   = 0x0092;
const NUInt N_AUDIO_FORMAT_RAW_AAC1          = 0x00FF;
const NUInt N_AUDIO_FORMAT_WM_AUDIO_V8       = 0x0161;
const NUInt N_AUDIO_FORMAT_WM_AUDIO_V9       = 0x0162;
const NUInt N_AUDIO_FORMAT_WM_AUDIO_LOSSLESS = 0x0163;
const NUInt N_AUDIO_FORMAT_WMA_SPDIF         = 0x0164;
const NUInt N_AUDIO_FORMAT_ADTS              = 0x1600;
const NUInt N_AUDIO_FORMAT_AAC               = 0x1610;

class N_CLASS(NAudioFormat) : public N_CLASS(NMediaFormat)
{
	N_DECLARE_OBJECT_CLASS(NAudioFormat, NMediaFormat)

private:
	static HNAudioFormat Create()
	{
		HNAudioFormat handle;
		NCheck(NAudioFormatCreate(&handle));
		return handle;
	}

	N_CLASS(NAudioFormat)(HNObject handle, bool claimHandle)
		: N_CLASS(NMediaFormat)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NString) MediaSubtypeToString(NUInt value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NAudioFormatMediaSubtypeToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	N_CLASS(NAudioFormat)()
		: N_CLASS(NMediaFormat)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NAudioFormat);
	}

	NInt GetChannelCount() const
	{
		NInt value;
		NCheck(NAudioFormatGetChannelCount(GetHandle(), &value));
		return value;
	}

	void SetChannelCount(NInt value)
	{
		NCheck(NAudioFormatSetChannelCount(GetHandle(), value));
	}

	NInt GetSampleRate() const
	{
		NInt value;
		NCheck(NAudioFormatGetSampleRate(GetHandle(), &value));
		return value;
	}

	void SetSampleRate(NInt value)
	{
		NCheck(NAudioFormatSetSampleRate(GetHandle(), value));
	}

	NInt GetBitsPerChannel() const
	{
		NInt value;
		NCheck(NAudioFormatGetBitsPerChannel(GetHandle(), &value));
		return value;
	}

	void SetBitsPerChannel(NInt value)
	{
		NCheck(NAudioFormatSetBitsPerChannel(GetHandle(), value));
	}
};

}}

#endif // !N_AUDIO_FORMAT_HPP_INCLUDED
