#ifndef N_CUSTOM_STREAM_HPP_INCLUDED
#define N_CUSTOM_STREAM_HPP_INCLUDED

#include <NStream.hpp>
#include <NCore.hpp>
namespace Neurotec { namespace IO
{
#include <NCustomStream.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NCustomStream) : public N_CLASS(NStream)
{
	N_DECLARE_OBJECT_CLASS(NCustomStream, NStream)

public:
	typedef void (* FlushProc)(void * pParam);
	typedef NLong (* GetLengthProc)(void * pParam);
	typedef void (* SetLengthProc)(NLong value, void * pParam);
	typedef NLong (* GetPositionProc)(void * pParam);
	typedef void (* SetPositionProc)(NLong value, void * pParam);
	typedef void (* SeekProc)(NLong offset, NSeekOrigin origin, void * pParam);
	typedef NInt (* ReadByteProc)(void * pParam);
	typedef NSizeType (* ReadProc)(void * pBuffer, NSizeType bufferSize, void * pParam);
	typedef void (* WriteByteProc)(NByte value, void * pParam);
	typedef void (* WriteProc)(const void * pBuffer, NSizeType bufferSize, void * pParam);

private:
	static NResult N_API FlushProcImpl(void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<FlushProc>(p->pCallback)(p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API GetLengthProcImpl(NLong * pValue, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pValue) NThrowArgumentNullException(N_T("pValue"));
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			*pValue = reinterpret_cast<GetLengthProc>(p->pCallback)(p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API SetLengthProcImpl(NLong value, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<SetLengthProc>(p->pCallback)(value, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API GetPositionProcImpl(NLong * pValue, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pValue) NThrowArgumentNullException(N_T("pValue"));
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			*pValue = reinterpret_cast<GetPositionProc>(p->pCallback)(p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API SetPositionProcImpl(NLong value, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<SetPositionProc>(p->pCallback)(value, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API SeekProcImpl(NLong offset, NSeekOrigin origin, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<SeekProc>(p->pCallback)(offset, origin, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API ReadByteProcImpl(NInt * pValue, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pValue) NThrowArgumentNullException(N_T("pValue"));
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			*pValue = reinterpret_cast<ReadByteProc>(p->pCallback)(p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API ReadProcImpl(void * pBuffer, NSizeType bufferSize, NSizeType * pSizeRead, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			if (!pSizeRead) NThrowArgumentNullException(N_T("pSizeRead"));
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			*pSizeRead = reinterpret_cast<ReadProc>(p->pCallback)(pBuffer, bufferSize, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API WriteByteProcImpl(NByte value, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<WriteByteProc>(p->pCallback)(value, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API WriteProcImpl(const void * pBuffer, NSizeType bufferSize, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<WriteProc>(p->pCallback)(pBuffer, bufferSize, p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}


	static HNCustomStream Create(bool canRead, bool canWrite, bool canSeek,
		FlushProc pFlush, void * pFlushParam,
		GetLengthProc pGetLength, void * pGetLengthParam,
		SetLengthProc pSetLength, void * pSetLengthParam,
		GetPositionProc pGetPosition, void * pGetPositionParam,
		SetPositionProc pSetPosition, void * pSetPositionParam,
		SeekProc pSeek, void * pSeekParam,
		ReadByteProc pReadByte, void * pReadByteParam,
		ReadProc pRead, void * pReadParam,
		WriteByteProc pWriteByte, void * pWriteByteParam,
		WriteProc pWrite, void * pWriteParam)
	{
		N_CLASS(NCallback) flush = N_CLASS(NTypes)::CreateCallback(FlushProcImpl, pFlush, pFlushParam);
		N_CLASS(NCallback) getLength = N_CLASS(NTypes)::CreateCallback(GetLengthProcImpl, pGetLength, pGetLengthParam);
		N_CLASS(NCallback) setLength = N_CLASS(NTypes)::CreateCallback(SetLengthProcImpl, pSetLength, pSetLengthParam);
		N_CLASS(NCallback) getPosition = N_CLASS(NTypes)::CreateCallback(GetPositionProcImpl, pGetPosition, pGetPositionParam);
		N_CLASS(NCallback) setPosition = N_CLASS(NTypes)::CreateCallback(SetPositionProcImpl, pSetPosition, pSetPositionParam);
		N_CLASS(NCallback) seek = N_CLASS(NTypes)::CreateCallback(SeekProcImpl, pSeek, pSeekParam);
		N_CLASS(NCallback) readByte = N_CLASS(NTypes)::CreateCallback(ReadByteProcImpl, pReadByte, pReadByteParam);
		N_CLASS(NCallback) read = N_CLASS(NTypes)::CreateCallback(ReadProcImpl, pRead, pReadParam);
		N_CLASS(NCallback) writeByte = N_CLASS(NTypes)::CreateCallback(WriteByteProcImpl, pWriteByte, pWriteByteParam);
		N_CLASS(NCallback) write = N_CLASS(NTypes)::CreateCallback(WriteProcImpl, pWrite, pWriteParam);
		HNCustomStream handle;
		NCheck(NCustomStreamCreateN(canRead ? NTrue : NFalse, canWrite ? NTrue : NFalse, canSeek ? NTrue : NFalse,
			flush.GetHandle(), getLength.GetHandle(), setLength.GetHandle(), getPosition.GetHandle(), setPosition.GetHandle(),
			seek.GetHandle(), readByte.GetHandle(), read.GetHandle(), writeByte.GetHandle(), write.GetHandle(), &handle));
		return handle;
	}

	N_CLASS(NCustomStream)(HNObject handle, bool claimHandle)
		: N_CLASS(NStream)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NCustomStream)(bool canRead, bool canWrite, bool canSeek,
		FlushProc pFlush, void * pFlushParam,
		GetLengthProc pGetLength, void * pGetLengthParam,
		SetLengthProc pSetLength, void * pSetLengthParam,
		GetPositionProc pGetPosition, void * pGetPositionParam,
		SetPositionProc pSetPosition, void * pSetPositionParam,
		SeekProc pSeek, void * pSeekParam,
		ReadByteProc pReadByte, void * pReadByteParam,
		ReadProc pRead, void * pReadParam,
		WriteByteProc pWriteByte, void * pWriteByteParam,
		WriteProc pWrite, void * pWriteParam)
		: N_CLASS(NStream)(Create(canRead, canWrite, canSeek,
			pFlush, pFlushParam,
			pGetLength, pGetLengthParam,
			pSetLength, pSetLengthParam,
			pGetPosition, pGetPositionParam,
			pSetPosition, pSetPositionParam,
			pSeek, pSeekParam,
			pReadByte, pReadByteParam,
			pRead, pReadParam,
			pWriteByte, pWriteByteParam,
			pWrite, pWriteParam), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NCustomStream);
	}
};

}}

#endif // !N_CUSTOM_STREAM_HPP_INCLUDED
