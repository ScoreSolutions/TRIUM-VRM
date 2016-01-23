#ifndef N_IMAGE_READER_HPP_INCLUDED
#define N_IMAGE_READER_HPP_INCLUDED

#include <NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::HNStream;
using ::Neurotec::IO::NFileAccess;
using ::Neurotec::IO::HNBuffer;
#include <NImageReader.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NImage);
class N_CLASS(NImageInfo);
class N_CLASS(NImageFormat);

class N_CLASS(NImageReader) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NImageReader, NObject)

private:
	N_CLASS(NImageReader)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NImage) * Read(NUInt flags = 0, N_CLASS(NImageInfo) * * ppInfo = NULL);
	N_CLASS(NImageInfo) * ReadInfo(NUInt flags = 0);

	N_CLASS(NImageFormat) * GetFormat() const;
};

}}

#include <NImage.hpp>
#include <NImageInfo.hpp>
#include <NImageFormat.hpp>

namespace Neurotec { namespace Images
{

inline N_CLASS(NImageFormat) * N_CLASS(NImageReader)::GetFormat() const
{
	return GetObject<HandleType, N_CLASS(NImageFormat)>(NImageReaderGetFormatEx, true, true);
}

inline N_CLASS(NImage) * N_CLASS(NImageReader)::Read(NUInt flags, N_CLASS(NImageInfo) * * ppInfo)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageReaderRead(GetHandle(), flags, ppInfo ? &hInfo : NULL, &hImage));
	N_CLASS(NImage) * pImage = NULL;
	N_CLASS(NImageInfo) * pInfo = NULL;
	try
	{
		pInfo = FromHandle<N_CLASS(NImageInfo)>(hInfo);
		pImage = FromHandle<N_CLASS(NImage)>(hImage);
		if (ppInfo) *ppInfo = pInfo;
		return pImage;
	}
	catch (...)
	{
		UnrefOrDelete(hInfo, pInfo);
		UnrefOrDelete(hImage, pImage);
		throw;
	}
}

inline N_CLASS(NImageInfo) * N_CLASS(NImageReader)::ReadInfo(NUInt flags)
{
	HNImageInfo hInfo;
	NCheck(NImageReaderReadInfo(GetHandle(), flags, &hInfo));
	try
	{
		return FromHandle<N_CLASS(NImageInfo)>(hInfo);
	}
	catch (...)
	{
		Unref(hInfo);
		throw;
	}
}

}}

#endif // !N_IMAGE_READER_HPP_INCLUDED
