#ifndef N_IMAGE_WRITER_HPP_INCLUDED
#define N_IMAGE_WRITER_HPP_INCLUDED

#include <NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::HNStream;
using ::Neurotec::IO::NFileAccess;
using ::Neurotec::IO::HNBuffer;
#include <NImageWriter.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NImage);
class N_CLASS(NImageInfo);
class N_CLASS(NImageFormat);

class N_CLASS(NImageWriter) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NImageWriter, NObject)

private:
	N_CLASS(NImageWriter)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	void Write(N_CLASS(NImage) * pImage, N_CLASS(NImageInfo) * pInfo = NULL, NUInt flags = 0);

	::Neurotec::IO::N_CLASS(NBuffer) * GetBuffer()
	{
		HNBuffer hValue;
		NCheck(NImageWriterGetBuffer(GetHandle(), &hValue));
		try
		{
			return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hValue);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use GetBuffer instead")
	void * DetachBuffer(NSizeType * pBufferSize)
	{
		void * pBuffer;
		NCheck(NImageWriterDetachBuffer(GetHandle(), &pBuffer, pBufferSize));
		return pBuffer;
	}
#include <NReDeprecate.h>

	N_CLASS(NImageFormat) * GetFormat() const;
};

}}

#include <NImage.hpp>
#include <NImageInfo.hpp>
#include <NImageFormat.hpp>

namespace Neurotec { namespace Images
{

inline N_CLASS(NImageFormat) * N_CLASS(NImageWriter)::GetFormat() const
{
	return GetObject<HandleType, N_CLASS(NImageFormat)>(NImageWriterGetFormatEx, true, true);
}

inline void N_CLASS(NImageWriter)::Write(N_CLASS(NImage) * pImage, N_CLASS(NImageInfo) * pInfo, NUInt flags)
{
	if (!pImage) NThrowArgumentNullException(N_T("pImage"));
	NCheck(NImageWriterWrite(GetHandle(), pImage->GetHandle(), ToHandle(pInfo), flags));
}

}}

#endif // !N_IMAGE_WRITER_HPP_INCLUDED
