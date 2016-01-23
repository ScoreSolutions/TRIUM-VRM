#ifndef N_BUFFERED_STREAM_HPP_INCLUDED
#define N_BUFFERED_STREAM_HPP_INCLUDED

#include <NStream.hpp>
namespace Neurotec { namespace IO
{
#include <NBufferedStream.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NBufferedStream) : public N_CLASS(NStream)
{
	N_DECLARE_OBJECT_CLASS(NBufferedStream, NStream)

private:
	static HNBufferedStream Create(N_CLASS(NStream) * pInnerStream)
	{
		if (!pInnerStream) NThrowArgumentNullException(N_T("pInnerStream"));
		HNBufferedStream handle;
		NCheck(NBufferedStreamCreate(pInnerStream->GetHandle(), &handle));
		return handle;
	}

	static HNBufferedStream Create(N_CLASS(NStream) * pInnerStream, NSizeType bufferSize)
	{
		if (!pInnerStream) NThrowArgumentNullException(N_T("pInnerStream"));
		HNBufferedStream handle;
		NCheck(NBufferedStreamCreateWithBufferSize(pInnerStream->GetHandle(), bufferSize, &handle));
		return handle;
	}

	N_CLASS(NBufferedStream)(HNObject handle, bool claimHandle)
		: N_CLASS(NStream)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NBufferedStream)(N_CLASS(NStream) * pInnerStream)
		: N_CLASS(NStream)(Create(pInnerStream), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBufferedStream);
	}

	N_CLASS(NBufferedStream)(N_CLASS(NStream) * pInnerStream, NSizeType bufferSize)
		: N_CLASS(NStream)(Create(pInnerStream, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NBufferedStream);
	}
};

}}

#endif // !N_BUFFERED_STREAM_HPP_INCLUDED
