#ifndef N_FILE_STREAM_HPP_INCLUDED
#define N_FILE_STREAM_HPP_INCLUDED

#include <NStream.hpp>
namespace Neurotec { namespace IO
{
#include <NFileStream.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NFileStream) : public N_CLASS(NStream)
{
	N_DECLARE_OBJECT_CLASS(NFileStream, NStream)

private:
	static HNFileStream Create(const N_CLASS(NStringWrapper) & path, NFileMode mode)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateN(path.GetHandle(), mode, &handle));
		return handle;
	}

	static HNFileStream Create(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateWithAccessN(path.GetHandle(), mode, access, &handle));
		return handle;
	}

	static HNFileStream Create(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access, NFileShare share)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateWithAccessAndShareN(path.GetHandle(), mode, access, share, &handle));
		return handle;
	}

	static HNFileStream Create(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize)
	{
		HNFileStream handle;
		NCheck(NFileStreamCreateWithAccessShareAndBufferSizeN(path.GetHandle(), mode, access, share, bufferSize, &handle));
		return handle;
	}

	static HNFileStream Create(NHandle handle, bool ownsHandle, NFileAccess access)
	{
		HNFileStream hStream;
		NCheck(NFileStreamCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, access, &hStream));
		return hStream;
	}

	static HNFileStream Create(NHandle handle, bool ownsHandle, NFileAccess access, NSizeType bufferSize)
	{
		HNFileStream hStream;
		NCheck(NFileStreamCreateFromOSHandleWithBufferSize(handle, ownsHandle ? NTrue : NFalse, access, bufferSize, &hStream));
		return hStream;
	}

	N_CLASS(NFileStream)(HNObject handle, bool claimHandle)
		: N_CLASS(NStream)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NFileStream)(const N_CLASS(NStringWrapper) & path, NFileMode mode)
		: N_CLASS(NStream)(Create(path, mode), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	N_CLASS(NFileStream)(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access)
		: N_CLASS(NStream)(Create(path, mode, access), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	N_CLASS(NFileStream)(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access, NFileShare share)
		: N_CLASS(NStream)(Create(path, mode, access, share), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	N_CLASS(NFileStream)(const N_CLASS(NStringWrapper) & path, NFileMode mode, NFileAccess access, NFileShare share, NSizeType bufferSize)
		: N_CLASS(NStream)(Create(path, mode, access, share, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	N_CLASS(NFileStream)(NHandle handle, NFileAccess access)
		: N_CLASS(NStream)(Create(handle, true, access), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	N_CLASS(NFileStream)(NHandle handle, bool ownsHandle, NFileAccess access)
		: N_CLASS(NStream)(Create(handle, ownsHandle, access), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	N_CLASS(NFileStream)(NHandle handle, NFileAccess access, NSizeType bufferSize)
		: N_CLASS(NStream)(Create(handle, true, access, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	N_CLASS(NFileStream)(NHandle handle, bool ownsHandle, NFileAccess access, NSizeType bufferSize)
		: N_CLASS(NStream)(Create(handle, ownsHandle, access, bufferSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFileStream);
	}

	NHandle GetOSHandle()
	{
		NHandle value;
		NCheck(NFileStreamGetOSHandle(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_FILE_STREAM_HPP_INCLUDED
