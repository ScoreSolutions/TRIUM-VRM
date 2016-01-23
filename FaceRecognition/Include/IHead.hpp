#ifndef IHEAD_HPP_INCLUDED
#define IHEAD_HPP_INCLUDED

#include <NImage.hpp>
namespace Neurotec { namespace Images
{
#include <IHead.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(IHeadInfo) : public N_CLASS(NImageInfo)
{
	N_DECLARE_OBJECT_CLASS(IHeadInfo, NImageInfo)

private:
	N_CLASS(IHeadInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NImageInfo)(handle, claimHandle)
	{
	}
};

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) ", " N_STRINGIZEA(N_CLASS(NImageFormat)) "::GetIHead and " N_STRINGIZEA(N_CLASS(IHeadInfo)) " instead")
	N_CLASS(IHead)
{
private:
	N_CLASS(IHead)() {}
	N_CLASS(IHead)(const N_CLASS(IHead)&) {}

public:
	static N_CLASS(NImage)* LoadImage(const N_CLASS(NStringWrapper) & fileName)
	{
		HNImage handle;
		NCheck(IHeadLoadImageFromFileN(fileName.GetHandle(), &handle));
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
		NCheck(IHeadLoadImageFromMemoryN(pBuffer->GetHandle(), &handle));
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
		NCheck(IHeadLoadImageFromMemory(pBuffer, bufferSize, &handle));
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
		NCheck(IHeadLoadImageFromStream(pStream->GetHandle(), &handle));
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

	static void SaveImage(N_CLASS(NImage)* pImage, const N_CLASS(NStringWrapper) & fileName)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(IHeadSaveImageToFileN(pImage->GetHandle(), fileName.GetHandle()));
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNBuffer hBuffer;
		NCheck(IHeadSaveImageToMemoryN(pImage->GetHandle(), &hBuffer));
		try
		{
			return N_CLASS(NObject)::FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hBuffer);
			throw;
		}
	}

	static void * SaveImage(N_CLASS(NImage) * pImage, NSizeType * pBufferSize)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		void * pBuffer;
		NCheck(IHeadSaveImageToMemory(pImage->GetHandle(), &pBuffer, pBufferSize));
		return pBuffer;
	}

	static void SaveImage(N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		NCheck(IHeadSaveImageToStream(pImage->GetHandle(), pStream->GetHandle()));
	}
};
#include <NReDeprecate.h>

}}

#endif // !IHEAD_HPP_INCLUDED
