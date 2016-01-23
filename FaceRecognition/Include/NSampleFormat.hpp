#ifndef N_SAMPLE_FORMAT_HPP_INCLUDED
#define N_SAMPLE_FORMAT_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Media
{
#include <NSampleFormat.h>
}}

namespace Neurotec { namespace Media
{
#undef N_SAMPLE_FORMAT_MAX_CHANNEL_COUNT

const NInt N_SAMPLE_FORMAT_MAX_CHANNEL_COUNT = 15;

class N_CLASS(NSampleFormat)
{
	N_DECLARE_BASIC_CLASS_BASE(NSampleFormat)

public:
	static N_CLASS(NType) * NExtraChannelNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NExtraChannel), true, true);
	}

	static N_CLASS(NType) * NChannelFormatNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NChannelFormat), true, true);
	}

	static bool IsExtraChannelValid(NExtraChannel value)
	{
		return NExtraChannelIsValid(value) != 0;
	}

	static bool IsChannelFormatValid(NChannelFormat value)
	{
		return NChannelFormatIsValid(value) != 0;
	}

	NExtraChannel GetExtraChannel() const
	{
		return NSampleFormatGetExtraChannel(value);
	}

	NInt GetChannelCount() const
	{
		return NSampleFormatGetChannelCount(value);
	}

	NChannelFormat GetChannelFormat() const
	{
		return NSampleFormatGetChannelFormat(value);
	}

	NInt GetBitsPerChannel() const
	{
		return NSampleFormatGetBitsPerChannel(value);
	}

	bool IsIndexed() const
	{
		return NSampleFormatIsIndexed(value) != 0;
	}

	NInt GetBitsPerIndex() const
	{
		return NSampleFormatGetBitsPerIndex(value);
	}

	NInt GetMaxPaletteLength() const
	{
		return NSampleFormatGetMaxPaletteLength(value);
	}

	bool IsSeparated() const
	{
		return NSampleFormatIsSeparated(value) != 0;
	}

	NInt GetPlaneCount() const
	{
		return NSampleFormatGetPlaneCount(value);
	}

	NInt GetBitsPerValue() const
	{
		return NSampleFormatGetBitsPerValue(value);
	}

	NInt GetBitsPerSample() const
	{
		return NSampleFormatGetBitsPerSample(value);
	}

	NInt GetBitsPerPaletteEntry() const
	{
		return NSampleFormatGetBitsPerPaletteEntry(value);
	}

	NSizeType GetBytesPerChannel() const
	{
		return NSampleFormatGetBytesPerChannel(value);
	}

	NSizeType GetBytesPerValue() const
	{
		return NSampleFormatGetBytesPerValue(value);
	}

	NSizeType GetBytesPerSample() const
	{
		return NSampleFormatGetBytesPerSample(value);
	}

	NSizeType GetBytesPerPaletteEntry() const
	{
		return NSampleFormatGetBytesPerPaletteEntry(value);
	}

	N_CLASS(NType) * GetChannelType() const
	{
		HNType hValue;
		NCheck(NSampleFormatGetChannelType(value, &hValue));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NType)>(hValue);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hValue);
			throw;
		}
	}
};
N_TYPEDEF_TYPE(NSampleFormat)

}}

#endif // !N_SAMPLE_FORMAT_HPP_INCLUDED
