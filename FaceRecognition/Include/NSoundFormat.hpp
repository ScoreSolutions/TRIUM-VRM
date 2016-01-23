#ifndef N_SOUND_FORMAT_HPP_INCLUDED
#define N_SOUND_FORMAT_HPP_INCLUDED

#include <NSampleFormat.hpp>
namespace Neurotec { namespace Sound
{
using ::Neurotec::Media::NChannelFormat;
using ::Neurotec::Media::NSampleFormat_;
#include <NSoundFormat.h>
}}

namespace Neurotec { namespace Sound
{

#undef NSF_UNDEFINED

#undef NSF_MONO_8U
#undef NSF_MONO_8S
#undef NSF_MONO_16U
#undef NSF_MONO_16S
#undef NSF_MONO_32U
#undef NSF_MONO_32S
#undef NSF_MONO_64U
#undef NSF_MONO_64S
#undef NSF_MONO_32F
#undef NSF_MONO_64F

#undef NSF_STEREO_8U
#undef NSF_STEREO_8S
#undef NSF_STEREO_16U
#undef NSF_STEREO_16S
#undef NSF_STEREO_32U
#undef NSF_STEREO_32S
#undef NSF_STEREO_64U
#undef NSF_STEREO_64S
#undef NSF_STEREO_32F
#undef NSF_STEREO_64F

class N_CLASS(NSoundFormat) : public ::Neurotec::Media::N_CLASS(NSampleFormat)
{
	N_DECLARE_BASIC_CLASS_DERIVED(NSoundFormat, ::Neurotec::Media::N_CLASS(NSampleFormat))

public:
	static N_CLASS(NType) * NSoundTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NSoundType), true, true);
	}

	static bool IsSoundTypeValid(NSoundType value)
	{
		return NSoundTypeIsValid(value) != 0;
	}

	static NSizeType CalcBlockSize(NInt bitsPerSample, NInt length)
	{
		NSizeType value;
		NCheck(NSoundFormatCalcBlockSize(bitsPerSample, length, &value));
		return value;
	}

	N_CLASS(NSoundFormat)(NSoundType soundType, NInt channelCount, NChannelFormat channelFormat, NInt bitsPerChannel)
	{
		NCheck(NSoundFormatCreate(soundType, channelCount, channelFormat, bitsPerChannel, &value));
	}

	NSizeType GetBlockSize(NInt length) const
	{
		NSizeType value;
		NCheck(NSoundFormatGetBlockSize(this->value, length, &value));
		return value;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NSoundFormatToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	NSoundType GetSoundType() const
	{
		return NSoundFormatGetSoundType(value);
	}
};
N_TYPEDEF_TYPE(NSoundFormat)

const N_CLASS(NSoundFormat) NSF_UNDEFINED(0);

const N_CLASS(NSoundFormat) NSF_MONO_8U(0x00301001);
const N_CLASS(NSoundFormat) NSF_MONO_8S(0x00311001);
const N_CLASS(NSoundFormat) NSF_MONO_16U(0x00401001);
const N_CLASS(NSoundFormat) NSF_MONO_16S(0x00411001);
const N_CLASS(NSoundFormat) NSF_MONO_32U(0x00501001);
const N_CLASS(NSoundFormat) NSF_MONO_32S(0x00511001);
const N_CLASS(NSoundFormat) NSF_MONO_64U(0x00601001);
const N_CLASS(NSoundFormat) NSF_MONO_64S(0x00611001);
const N_CLASS(NSoundFormat) NSF_MONO_32F(0x00521001);
const N_CLASS(NSoundFormat) NSF_MONO_64F(0x00621001);

const N_CLASS(NSoundFormat) NSF_STEREO_8U(0x00302002);
const N_CLASS(NSoundFormat) NSF_STEREO_8S(0x00312002);
const N_CLASS(NSoundFormat) NSF_STEREO_16U(0x00402002);
const N_CLASS(NSoundFormat) NSF_STEREO_16S(0x00412002);
const N_CLASS(NSoundFormat) NSF_STEREO_32U(0x00502002);
const N_CLASS(NSoundFormat) NSF_STEREO_32S(0x00512002);
const N_CLASS(NSoundFormat) NSF_STEREO_64U(0x00602002);
const N_CLASS(NSoundFormat) NSF_STEREO_64S(0x00612002);
const N_CLASS(NSoundFormat) NSF_STEREO_32F(0x00522002);
const N_CLASS(NSoundFormat) NSF_STEREO_64F(0x00622002);

}}

#endif // !N_SOUND_FORMAT_HPP_INCLUDED
