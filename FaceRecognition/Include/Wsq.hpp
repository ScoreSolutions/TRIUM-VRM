#ifndef WSQ_HPP_INCLUDED
#define WSQ_HPP_INCLUDED

#include <NImage.hpp>
#include <NistCom.hpp>
namespace Neurotec { namespace Images
{
#include <Wsq.h>
}}

namespace Neurotec { namespace Images
{

#undef WSQ_DEFAULT_BIT_RATE
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN32_X86
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN64_X64
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_I386
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_AMD64
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL64
#undef WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_POWERPC

const NFloat WSQ_DEFAULT_BIT_RATE = 0.75f;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN32_X86 = 10150;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_WIN64_X64 = 10151;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_I386 = 10152;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_DEBIAN_AMD64 = 10153;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL = 10154;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_INTEL64 = 10155;
const NUShort WSQ_IMPLEMENTATION_NEUROTECHNOLOGY_MACOSX_POWERPC = 10156;

class N_CLASS(WsqInfo) : public N_CLASS(NImageInfo)
{
	N_DECLARE_OBJECT_CLASS(WsqInfo, NImageInfo)

private:
	N_CLASS(WsqInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NImageInfo)(handle, claimHandle)
	{
	}

public:
	NFloat GetBitRate() const
	{
		NFloat value;
		NCheck(WsqInfoGetBitRate(GetHandle(), &value));
		return value;
	}

	void SetBitRate(NFloat value)
	{
		NCheck(WsqInfoSetBitRate(GetHandle(), value));
	}

	NUShort GetImplementationNumber() const
	{
		NUShort value;
		NCheck(WsqInfoGetImplementationNumber(GetHandle(), &value));
		return value;
	}

	bool HasNistCom() const
	{
		NBool value;
		NCheck(WsqInfoHasNistCom(GetHandle(), &value));
		return value != 0;
	}

	void SetHasNistCom(bool value)
	{
		NCheck(WsqInfoSetHasNistCom(GetHandle(), value ? NTrue : NFalse));
	}

	N_CLASS(NistCom) * GetNistCom() const
	{
		HNistCom hValue;
		NCheck(WsqInfoGetNistCom(GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NistCom)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}
};

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NImage)) ", " N_STRINGIZEA(N_CLASS(NImageFormat)) "::GetWsq and " N_STRINGIZEA(N_CLASS(WsqInfo)) " instead")
	N_CLASS(Wsq)
{
private:
	N_CLASS(Wsq)() {}
	N_CLASS(Wsq)(const N_CLASS(Wsq)&) {}

public:
	static N_CLASS(NImage)* LoadImage(const N_CLASS(NStringWrapper) & fileName)
	{
		HNImage handle;
		NCheck(WsqLoadImageFromFileN(fileName.GetHandle(), &handle));
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
		NCheck(WsqLoadImageFromMemoryN(pBuffer->GetHandle(), &handle));
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
		NCheck(WsqLoadImageFromMemory(pBuffer, bufferSize, &handle));
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
		NCheck(WsqLoadImageFromStream(pStream->GetHandle(), &handle));
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

	static void SaveImage(N_CLASS(NImage) * pImage, const N_CLASS(NStringWrapper) & fileName)
	{
		SaveImage(pImage, WSQ_DEFAULT_BIT_RATE, fileName);
	}

	static void SaveImage(N_CLASS(NImage) * pImage, NFloat bitRate, const N_CLASS(NStringWrapper) & fileName)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(WsqSaveImageToFileN(pImage->GetHandle(), bitRate, fileName.GetHandle()));
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage)
	{
		return SaveImage(pImage, WSQ_DEFAULT_BIT_RATE);
	}

	static ::Neurotec::IO::N_CLASS(NBuffer) * SaveImage(N_CLASS(NImage) * pImage, NFloat bitRate)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNBuffer hBuffer;
		NCheck(WsqSaveImageToMemoryN(pImage->GetHandle(), bitRate, &hBuffer));
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
		return SaveImage(pImage, WSQ_DEFAULT_BIT_RATE, pBufferSize);
	}

	static void * SaveImage(N_CLASS(NImage) * pImage, NFloat bitRate, NSizeType * pBufferSize)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		void * pBuffer;
		NCheck(WsqSaveImageToMemory(pImage->GetHandle(), bitRate, &pBuffer, pBufferSize));
		return pBuffer;
	}

	static void SaveImage(N_CLASS(NImage) * pImage, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		SaveImage(pImage, WSQ_DEFAULT_BIT_RATE, pStream);
	}

	static void SaveImage(N_CLASS(NImage) * pImage, NFloat bitRate, ::Neurotec::IO::N_CLASS(NStream) * pStream)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		NCheck(WsqSaveImageToStream(pImage->GetHandle(), bitRate, pStream->GetHandle()));
	}
};
#include <NReDeprecate.h>

}}

#endif // !WSQ_HPP_INCLUDED
