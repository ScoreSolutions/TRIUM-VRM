#ifndef TIFF_HPP_INCLUDED
#define TIFF_HPP_INCLUDED

#include <NImage.hpp>
namespace Neurotec { namespace Images
{
#include <Tiff.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(TiffInfo) : public N_CLASS(NImageInfo)
{
	N_DECLARE_OBJECT_CLASS(TiffInfo, NImageInfo)

public:
	N_CLASS(TiffInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NImageInfo)(handle, claimHandle)
	{
	}
};

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) ", " N_STRINGIZEA(N_CLASS(NImageFormat)) "::GetTiff and " N_STRINGIZEA(N_CLASS(TiffInfo)) " instead")
	N_CLASS(Tiff)
{
private:
	N_CLASS(Tiff)() {}
	N_CLASS(Tiff)(const N_CLASS(Tiff)&) {}

public:
	static N_CLASS(NImage)* LoadImage(const N_CLASS(NStringWrapper) & fileName)
	{
		HNImage handle;
		NCheck(TiffLoadImageFromFileN(fileName.GetHandle(), &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImage)* LoadImage(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNImage handle;
		NCheck(TiffLoadImageFromMemoryN(pBuffer->GetHandle(), &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImage)* LoadImage(const void * pBuffer, NSizeType bufferSize)
	{
		HNImage handle;
		NCheck(TiffLoadImageFromMemory(pBuffer, bufferSize, &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}

	static N_CLASS(NImage)* LoadImage(::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNImage handle;
		NCheck(TiffLoadImageFromStream(pStream->GetHandle(), &handle));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(handle);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(handle);
			throw;
		}
	}
};
#include <NReDeprecate.h>

}}

#endif // !TIFF_HPP_INCLUDED
