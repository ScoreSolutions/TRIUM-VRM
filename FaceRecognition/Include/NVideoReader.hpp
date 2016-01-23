#ifndef N_VIDEO_READER_HPP_INCLUDED
#define N_VIDEO_READER_HPP_INCLUDED

#include <NImages.hpp>
namespace Neurotec { namespace Video
{
using Neurotec::Images::HNImage;
#include <NVideoReader.h>
}}

namespace Neurotec { namespace Video
{

#include <NNoDeprecate.h>

class N_DEPRECATED("class is deprecated, use Neurotec::Media::" N_STRINGIZEA(N_CLASS(NMediaReader)) " instead")
	N_CLASS(NVideoReader) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NVideoReader, NObject);

private:
	static HNVideoReader Create(const N_CLASS(NStringWrapper) & fileName)
	{
		HNVideoReader handle;
		NCheck(NVideoReaderCreateFromFileN(fileName.GetHandle(), &handle));
		return handle;
	}

	N_CLASS(NVideoReader)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NVideoReader)(const N_CLASS(NStringWrapper) & fileName)
		: N_CLASS(NObject)(Create(fileName), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NVideoReader);
	}

	Neurotec::Images::N_CLASS(NImage)* GetFrame(NInt frameIndex) const
	{
		HNImage handle;
		NCheck(NVideoReaderGetFrame(GetHandle(), frameIndex, &handle));
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

	NInt GetFrameCount() const
	{
		NInt value;
		NCheck(NVideoReaderGetFrameCount(GetHandle(), &value));
		return value;
	}

	NUInt GetFrameWidth() const
	{
		NUInt value;
		NCheck(NVideoReaderGetFrameWidth(GetHandle(), &value));
		return value;
	}

	NUInt GetFrameHeight() const
	{
		NUInt value;
		NCheck(NVideoReaderGetFrameHeight(GetHandle(), &value));
		return value;
	}

	NDouble GetFrameRate() const
	{
		NDouble value;
		NCheck(NVideoReaderGetFrameRate(GetHandle(), &value));
		return value;
	}
};
#include <NReDeprecate.h>

}}

#endif // !N_VIDEO_READER_HPP_INCLUDED
