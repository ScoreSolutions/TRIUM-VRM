#ifndef N_BUFFER_HPP_INCLUDED
#define N_BUFFER_HPP_INCLUDED

#include <NObject.hpp>
namespace Neurotec { namespace IO
{
#include <NBuffer.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NBuffer) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NBuffer, NObject)

private:
	static HNBuffer Create(NSizeType size)
	{
		HNBuffer handle;
		NCheck(NBufferCreate(size, &handle));
		return handle;
	}

	static HNBuffer Create(void * ptr, NSizeType size, bool ownsPtr)
	{
		HNBuffer handle;
		NCheck(NBufferCreateFromPtr(ptr, size, ownsPtr ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNBuffer Create(void * ptr, NSizeType size, NMemoryType ptrType)
	{
		HNBuffer handle;
		NCheck(NBufferCreateFromPtrEx(ptr, size, ptrType, &handle));
		return handle;
	}

	static HNBuffer Create(const void * ptr, NSizeType size)
	{
		HNBuffer handle;
		NCheck(NBufferCreateFromConstPtr(ptr, size, &handle));
		return handle;
	}

	static HNBuffer Create(void * ptr, NSizeType size, N_CLASS(NTypes)::PointerFreeProc pFree, void * pFreeParam);

	static HNBuffer Create(N_CLASS(NBuffer) * pSrcBuffer, NSizeType offset, NSizeType size)
	{
		if (!pSrcBuffer) NThrowArgumentNullException(N_T("pSrcBuffer"));
		HNBuffer handle;
		NCheck(NBufferCreateFromBuffer(pSrcBuffer->GetHandle(), offset, size, &handle));
		return handle;
	}

	N_CLASS(NBuffer)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static void Copy(N_CLASS(NBuffer) * pSrcBuffer, NSizeType srcOffset, N_CLASS(NBuffer) * pDstBuffer, NSizeType dstOffset, NSizeType size)
	{
		if (!pSrcBuffer) NThrowArgumentNullException(N_T("pSrcBuffer"));
		if (!pDstBuffer) NThrowArgumentNullException(N_T("pDstBuffer"));
		NCheck(NBufferCopy(pSrcBuffer->GetHandle(), srcOffset, pDstBuffer->GetHandle(), dstOffset, size));
	}

	static N_CLASS(NBuffer) * GetEmpty()
	{
		HNBuffer hValue;
		NCheck(NBufferGetEmpty(&hValue));
		return FromHandle<N_CLASS(NBuffer)>(hValue, true, true);
	}

	explicit N_CLASS(NBuffer)(NSizeType size)
		: N_CLASS(NObject)(Create(size), true)
	{
	}

	N_CLASS(NBuffer)(void * ptr, NSizeType size, bool ownsPtr = true)
		: N_CLASS(NObject)(Create(ptr, size, ownsPtr), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBuffer);
	}

	N_CLASS(NBuffer)(void * ptr, NSizeType size, NMemoryType ptrType)
		: N_CLASS(NObject)(Create(ptr, size, ptrType), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBuffer);
	}

	N_CLASS(NBuffer)(const void * ptr, NSizeType size)
		: N_CLASS(NObject)(Create(ptr, size), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBuffer);
	}

	N_CLASS(NBuffer)(void * ptr, NSizeType size, N_CLASS(NTypes)::PointerFreeProc pFree, void * pFreeParam)
		: N_CLASS(NObject)(Create(ptr, size, pFree, pFreeParam), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBuffer);
	}

	N_CLASS(NBuffer)(N_CLASS(NBuffer) * pSrcBuffer, NSizeType offset, NSizeType size)
		: N_CLASS(NObject)(Create(pSrcBuffer, offset, size), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBuffer);
	}

	void CopyTo(N_CLASS(NBuffer) * pDstBuffer, NSizeType dstOffset) const
	{
		if (!pDstBuffer) NThrowArgumentNullException(N_T("pDstBuffer"));
		NCheck(NBufferCopyTo(GetHandle(), pDstBuffer->GetHandle(), dstOffset));
	}

	void CopyTo(void * pDstBuffer, NSizeType dstBufferSize) const
	{
		NCheck(NBufferCopyToPtr(GetHandle(), pDstBuffer, dstBufferSize));
	}

	void CopyTo(NSizeType offset, void * pDstBuffer, NSizeType dstBufferSize, NSizeType size) const
	{
		NCheck(NBufferCopyToPtrRange(GetHandle(), offset, pDstBuffer, dstBufferSize, size));
	}

	void CopyFrom(void * pSrcBuffer, NSizeType srcBufferSize, NSizeType offset)
	{
		NCheck(NBufferCopyFromPtr(GetHandle(), pSrcBuffer, srcBufferSize, offset));
	}

	const void * GetPtr() const
	{
		void * value;
		NCheck(NBufferGetPtr(GetHandle(), &value));
		return value;
	}

	void * ToPtr(NSizeType * pBufferSize)
	{
		void * pBuffer;
		NCheck(NBufferToPtr(GetHandle(), pBufferSize, &pBuffer));
		return pBuffer;
	}

	void * GetPtr()
	{
		void * value;
		NCheck(NBufferGetPtr(GetHandle(), &value));
		return value;
	}

	NSizeType GetSize() const
	{
		NSizeType value;
		NCheck(NBufferGetSize(GetHandle(), &value));
		return value;
	}
};

}}

#include <NCore.hpp>

namespace Neurotec { namespace IO
{

inline HNBuffer N_CLASS(NBuffer)::Create(void * ptr, NSizeType size, N_CLASS(NTypes)::PointerFreeProc pFree, void * pFreeParam)
{
	N_CLASS(NCallback) free = N_CLASS(NTypes)::CreateCallback(N_CLASS(NTypes)::PointerFreeProcImpl, pFree, pFreeParam);
	HNBuffer handle;
	NCheck(NBufferCreateFromPtrWithFree(ptr, size, free.GetHandle(), &handle));
	return handle;
}

}}

#endif // !N_BUFFER_HPP_INCLUDED
