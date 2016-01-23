#ifndef N_SOUND_BUFFER_HPP_INCLUDED
#define N_SOUND_BUFFER_HPP_INCLUDED

#include <NSoundFormat.hpp>
#include <NArray.hpp>
namespace Neurotec { namespace Sound
{
#include <NSoundBuffer.h>
}}

namespace Neurotec { namespace Sound
{

#undef NSB_ALL_DST
#undef NSB_ALL_SRC
#undef NSB_ALL_DST_AND_SRC

const NUInt NSB_ALL_DST = 0x00000F00;
const NUInt NSB_ALL_SRC = 0x0000F000;
const NUInt NSB_ALL_DST_AND_SRC = (NSB_ALL_DST | NSB_ALL_SRC);

class N_CLASS(NSoundBuffer) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NSoundBuffer, NObject)

private:
	N_CLASS(NSoundBuffer)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NSoundBuffer) * GetWrapper(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt sampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSamples, NUInt flags = 0)
	{
		if (!pSamples) NThrowArgumentNullException(N_T("pSamples"));
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperN(soundFormat.GetValue(), sampleRate, sampleCount, pSamples->GetHandle(), flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * GetWrapper(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt sampleCount, void * pSamples, NSizeType samplesSize, bool ownsSamples, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapper(soundFormat.GetValue(), sampleRate, sampleCount, pSamples, samplesSize, ownsSamples ? NTrue : NFalse, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * GetWrapper(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt srcSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSamples, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSamples) NThrowArgumentNullException(N_T("pSamples"));
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperForPartN(soundFormat.GetValue(), sampleRate, srcSampleCount, pSamples->GetHandle(), sampleIndex, sampleCount, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * GetWrapper(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt srcSampleCount, void * pSamples, NSizeType samplesSize, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperForPart(soundFormat.GetValue(), sampleRate, srcSampleCount, pSamples, samplesSize, sampleIndex, sampleCount, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * GetWrapper(N_CLASS(NSoundBuffer) * pSrcSoundBuffer, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSrcSoundBuffer) NThrowArgumentNullException(N_T("pSrcSoundBuffer"));
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateWrapperForSoundBufferPart(pSrcSoundBuffer->GetHandle(), sampleIndex, sampleCount, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * Create(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreate(soundFormat.GetValue(), sampleRate, sampleCount, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromData(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt sampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSamples, NUInt flags = 0)
	{
		if (!pSamples) NThrowArgumentNullException(N_T("pSamples"));
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromDataN(soundFormat.GetValue(), sampleRate, sampleCount, pSamples->GetHandle(), flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromData(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromData(soundFormat.GetValue(), sampleRate, sampleCount, pSamples, samplesSize, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromData(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt srcSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSamples, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSamples) NThrowArgumentNullException(N_T("pSamples"));
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromDataPartN(soundFormat.GetValue(), sampleRate, srcSampleCount, pSamples->GetHandle(), sampleIndex, sampleCount, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromData(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt srcSampleCount, const void * pSamples, NSizeType samplesSize, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromDataPart(soundFormat.GetValue(), sampleRate, srcSampleCount, pSamples, samplesSize, sampleIndex, sampleCount, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromSoundBuffer(const N_CLASS(NSoundFormat) & soundFormat, N_CLASS(NSoundBuffer) * pSrcSoundBuffer, NUInt flags = 0)
	{
		if (!pSrcSoundBuffer) NThrowArgumentNullException(N_T("pSrcSoundBuffer"));
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromSoundBuffer(soundFormat.GetValue(), pSrcSoundBuffer->GetHandle(), flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromSoundBuffer(const N_CLASS(NSoundFormat) & soundFormat, N_CLASS(NSoundBuffer) * pSrcSoundBuffer, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSrcSoundBuffer) NThrowArgumentNullException(N_T("pSrcSoundBuffer"));
		HNSoundBuffer handle;
		NCheck(NSoundBufferCreateFromSoundBufferPart(soundFormat.GetValue(), pSrcSoundBuffer->GetHandle(), sampleIndex, sampleCount, flags, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromFile(const N_CLASS(NStringWrapper) & fileName, NUInt flags = 0)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromFileN(fileName.GetHandle(), flags, &hSoundBuffer));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(hSoundBuffer);
		}
		catch (...)
		{
			Unref(hSoundBuffer);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromMemory(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &hSoundBuffer));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(hSoundBuffer);
		}
		catch (...)
		{
			Unref(hSoundBuffer);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
	{
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromMemory(pBuffer, bufferSize, flags, pSize, &hSoundBuffer));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(hSoundBuffer);
		}
		catch (...)
		{
			Unref(hSoundBuffer);
			throw;
		}
	}

	static N_CLASS(NSoundBuffer) * FromStream(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0)
	{
		if (!pStream) NThrowArgumentNullException(N_T("pStream"));
		HNSoundBuffer hSoundBuffer;
		NCheck(NSoundBufferCreateFromStream(pStream->GetHandle(), flags, &hSoundBuffer));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(hSoundBuffer);
		}
		catch (...)
		{
			Unref(hSoundBuffer);
			throw;
		}
	}

	static void Copy(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, NInt srcSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcSamples, NInt srcSampleIndex,
		const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, NInt dstSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSrcSamples) NThrowArgumentNullException(N_T("pSrcSamples"));
		if (!pDstSamples) NThrowArgumentNullException(N_T("pDstSamples"));
		NCheck(NSoundBufferCopyDataExN(srcSoundFormat.GetValue(), srcSampleRate, ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), srcSampleCount, pSrcSamples->GetHandle(), srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, ToHandle(pDstMinValue), ToHandle(pDstMaxValue), dstSampleCount, pDstSamples->GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	static void Copy(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex,
		const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyDataEx(srcSoundFormat.GetValue(), srcSampleRate, ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, ToHandle(pDstMinValue), ToHandle(pDstMaxValue), dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	static void Copy(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcSamples, NInt srcSampleIndex,
		const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSrcSamples) NThrowArgumentNullException(N_T("pSrcSamples"));
		if (!pDstSamples) NThrowArgumentNullException(N_T("pDstSamples"));
		NCheck(NSoundBufferCopyDataN(srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples->GetHandle(), srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples->GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	static void Copy(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex,
		const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyData(srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex,
			dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	static void Copy(N_CLASS(NSoundBuffer) * pSrcSoundBuffer, NInt sampleIndex, N_CLASS(NSoundBuffer) * pDstSoundBuffer, NInt dstSampleIndex, NInt sampleCount)
	{
		if (!pSrcSoundBuffer) NThrowArgumentNullException(N_T("pSrcSoundBuffer"));
		if (!pDstSoundBuffer) NThrowArgumentNullException(N_T("pDstSoundBuffer"));
		NCheck(NSoundBufferCopy(pSrcSoundBuffer->GetHandle(), sampleIndex, pDstSoundBuffer->GetHandle(), dstSampleIndex, sampleCount));
	}

	void CopyFrom(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcSamples, NInt sampleIndex, NUInt flags = 0)
	{
		if (!pSrcSamples) NThrowArgumentNullException(N_T("pSrcSamples"));
		NCheck(NSoundBufferCopyFromDataN(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples->GetHandle(), sampleIndex, flags));
	}

	void CopyFrom(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt sampleIndex, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromData(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples, srcSamplesSize, sampleIndex, flags));
	}

	void CopyFrom(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcSamples, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSrcSamples) NThrowArgumentNullException(N_T("pSrcSamples"));
		NCheck(NSoundBufferCopyFromDataPartN(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples->GetHandle(), srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void CopyFrom(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromDataPart(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void CopyFrom(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, NInt srcSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSrcSamples, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		if (!pSrcSamples) NThrowArgumentNullException(N_T("pSrcSamples"));
		NCheck(NSoundBufferCopyFromDataPartExN(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), srcSampleCount, pSrcSamples->GetHandle(), srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void CopyFrom(const N_CLASS(NSoundFormat) & srcSoundFormat, NInt srcSampleRate, N_CLASS(NArray) * pSrcMinValue, N_CLASS(NArray) * pSrcMaxValue, NInt srcSampleCount, const void * pSrcSamples, NSizeType srcSamplesSize, NInt srcSampleIndex, NInt sampleIndex, NInt sampleCount, NUInt flags = 0)
	{
		NCheck(NSoundBufferCopyFromDataPartEx(GetHandle(), srcSoundFormat.GetValue(), srcSampleRate, ToHandle(pSrcMinValue), ToHandle(pSrcMaxValue), srcSampleCount, pSrcSamples, srcSamplesSize, srcSampleIndex, sampleIndex, sampleCount, flags));
	}

	void Append(N_CLASS(NSoundBuffer) * pOther)
	{
		if (!pOther) NThrowArgumentNullException(N_T("pOther"));
		NCheck(NSoundBufferAppend(GetHandle(), pOther->GetHandle()));
	}

	void Append(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt sampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSamples, NUInt flags = 0)
	{
		if (!pSamples) NThrowArgumentNullException(N_T("pSamples"));
		NCheck(NSoundBufferAppendDataN(GetHandle(), soundFormat.GetValue(), sampleRate, sampleCount, pSamples->GetHandle(), flags));
	}

	void Append(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags = 0)
	{
		NCheck(NSoundBufferAppendData(GetHandle(), soundFormat.GetValue(), sampleRate, sampleCount, pSamples, samplesSize, flags));
	}

	void Append(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, N_CLASS(NArray) * pMinValue, N_CLASS(NArray) * pMaxValue, NInt sampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pSamples, NUInt flags = 0)
	{
		if (!pSamples) NThrowArgumentNullException(N_T("pSamples"));
		NCheck(NSoundBufferAppendDataExN(GetHandle(), soundFormat.GetValue(), sampleRate, ToHandle(pMinValue), ToHandle(pMaxValue), sampleCount, pSamples->GetHandle(), flags));
	}

	void Append(const N_CLASS(NSoundFormat) & soundFormat, NInt sampleRate, N_CLASS(NArray) * pMinValue, N_CLASS(NArray) * pMaxValue, NInt sampleCount, const void * pSamples, NSizeType samplesSize, NUInt flags = 0)
	{
		NCheck(NSoundBufferAppendDataEx(GetHandle(), soundFormat.GetValue(), sampleRate, ToHandle(pMinValue), ToHandle(pMaxValue), sampleCount, pSamples, samplesSize, flags));
	}

	void Clear()
	{
		NCheck(NSoundBufferClear(GetHandle()));
	}

	void CopyTo(N_CLASS(NSoundBuffer) * pDstSoundBuffer, NInt dstSampleIndex) const
	{
		if (!pDstSoundBuffer) NThrowArgumentNullException(N_T("pDstSoundBuffer"));
		NCheck(NSoundBufferCopyTo(GetHandle(), pDstSoundBuffer->GetHandle(), dstSampleIndex));
	}

	void CopyTo(const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pDstSamples, NInt dstSampleIndex, NUInt flags = 0) const
	{
		if (!pDstSamples) NThrowArgumentNullException(N_T("pDstSamples"));
		NCheck(NSoundBufferCopyToDataN(GetHandle(), dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples->GetHandle(), dstSampleIndex, flags));
	}

	void CopyTo(const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToData(GetHandle(), dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, flags));
	}

	void CopyTo(NInt sampleIndex, const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		if (!pDstSamples) NThrowArgumentNullException(N_T("pDstSamples"));
		NCheck(NSoundBufferCopyToDataPartN(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples->GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	void CopyTo(NInt sampleIndex, const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToDataPart(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	void CopyTo(NInt sampleIndex, const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, NInt dstSampleCount, ::Neurotec::IO::N_CLASS(NBuffer) * pDstSamples, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		if (!pDstSamples) NThrowArgumentNullException(N_T("pDstSamples"));
		NCheck(NSoundBufferCopyToDataPartExN(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, ToHandle(pDstMinValue), ToHandle(pDstMaxValue), dstSampleCount, pDstSamples->GetHandle(), dstSampleIndex, sampleCount, flags));
	}

	void CopyTo(NInt sampleIndex, const N_CLASS(NSoundFormat) & dstSoundFormat, NInt dstSampleRate, N_CLASS(NArray) * pDstMinValue, N_CLASS(NArray) * pDstMaxValue, NInt dstSampleCount, void * pDstSamples, NSizeType dstSamplesSize, NInt dstSampleIndex, NInt sampleCount, NUInt flags = 0) const
	{
		NCheck(NSoundBufferCopyToDataPartEx(GetHandle(), sampleIndex, dstSoundFormat.GetValue(), dstSampleRate, ToHandle(pDstMinValue), ToHandle(pDstMaxValue), dstSampleCount, pDstSamples, dstSamplesSize, dstSampleIndex, sampleCount, flags));
	}

	N_CLASS(NSoundBuffer) * Crop(NInt sampleIndex, NInt sampleCount) const
	{
		HNSoundBuffer handle;
		NCheck(NSoundBufferCrop(GetHandle(), sampleIndex, sampleCount, &handle));
		try
		{
			return FromHandle<N_CLASS(NSoundBuffer)>(handle);
		}
		catch (...)
		{
			Unref(handle);
			throw;
		}
	}

	void Save(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NObject) * pReserved = NULL, NUInt flags = 0) const;
	::Neurotec::IO::N_CLASS(NBuffer) * Save(N_CLASS(NObject) * pReserved = NULL, NUInt flags = 0) const;
	void Save(::Neurotec::IO::N_CLASS(NStream) * pSteam, N_CLASS(NObject) * pReserved = NULL, NUInt flags = 0) const;

	N_CLASS(NSoundFormat) GetSoundFormat() const
	{
		NSoundFormat_ value;
		NCheck(NSoundBufferGetSoundFormat(GetHandle(), &value));
		return N_CLASS(NSoundFormat)(value);
	}

	N_CLASS(NArray) * GetMinValue() const
	{
		HNArray hValue;
		NCheck(NSoundBufferGetMinValue(GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void SetMinValue(N_CLASS(NArray) * pValue)
	{
		NCheck(NSoundBufferSetMinValue(GetHandle(), ToHandle(pValue)));
	}

	N_CLASS(NArray) * GetMaxValue() const
	{
		HNArray hValue;
		NCheck(NSoundBufferGetMaxValue(GetHandle(), &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, true);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void SetMaxValue(N_CLASS(NArray) * pValue)
	{
		NCheck(NSoundBufferSetMaxValue(GetHandle(), ToHandle(pValue)));
	}

	NInt GetSampleRate() const
	{
		NInt value;
		NCheck(NSoundBufferGetSampleRate(GetHandle(), &value));
		return value;
	}

	NInt GetLength() const
	{
		NInt value;
		NCheck(NSoundBufferGetLength(GetHandle(), &value));
		return value;
	}

	void SetLength(NInt value)
	{
		NCheck(NSoundBufferSetLength(GetHandle(), value));
	}

	NInt GetCapacity() const
	{
		NInt value;
		NCheck(NSoundBufferGetCapacity(GetHandle(), &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(NSoundBufferSetCapacity(GetHandle(), value));
	}

	N_CLASS(NArray) * GetSample(NInt sampleIndex) const
	{
		HNArray hValue;
		NCheck(NSoundBufferGetSample(GetHandle(), sampleIndex, &hValue));
		try
		{
			return FromHandle<N_CLASS(NArray)>(hValue, true, false);
		}
		catch (...)
		{
			Unref(hValue);
			throw;
		}
	}

	void SetSample(NInt sampleIndex, N_CLASS(NArray) * pValue)
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		NCheck(NSoundBufferSetSample(GetHandle(), sampleIndex, pValue->GetHandle()));
	}

	::Neurotec::IO::N_CLASS(NBuffer) * GetSamples()
	{
		HNBuffer hValue;
		NCheck(NSoundBufferGetSamplesN(GetHandle(), &hValue));
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

	const void * GetSamplesPtr() const
	{
		void * pValue;
		NCheck(NSoundBufferGetSamplesPtr(GetHandle(), &pValue));
		return pValue;
	}

	void * GetSamplesPtr()
	{
		void * pValue;
		NCheck(NSoundBufferGetSamplesPtr(GetHandle(), &pValue));
		return pValue;
	}

	NSizeType GetSamplesSize() const
	{
		NSizeType value;
		NCheck(NSoundBufferGetSamplesSize(GetHandle(), &value));
		return value;
	}
};

}}

namespace Neurotec { namespace Sound
{

inline void N_CLASS(NSoundBuffer)::Save(const N_CLASS(NStringWrapper) & fileName, N_CLASS(NObject) * pReserved, NUInt flags) const
{
	NCheck(NSoundBufferSaveToFileN(GetHandle(), fileName.GetHandle(), ToHandle(pReserved), flags));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * N_CLASS(NSoundBuffer)::Save(N_CLASS(NObject) * pReserved, NUInt flags) const
{
	HNBuffer hBuffer;
	NCheck(NSoundBufferSaveToMemoryN(GetHandle(), ToHandle(pReserved), flags, &hBuffer));
	try
	{
		return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
	}
	catch (...)
	{
		Unref(hBuffer);
		throw;
	}
}

inline void N_CLASS(NSoundBuffer)::Save(::Neurotec::IO::N_CLASS(NStream) * pStream, N_CLASS(NObject) * pReserved, NUInt flags) const
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NSoundBufferSaveToStream(GetHandle(), pStream->GetHandle(), ToHandle(pReserved), flags));
}

}}

#endif // !N_SOUND_BUFFER_HPP_INCLUDED
