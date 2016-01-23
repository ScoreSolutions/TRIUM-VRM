#ifndef N_VIDEO_WRITER_HPP_INCLUDED
#define N_VIDEO_WRITER_HPP_INCLUDED

#include <NImages.hpp>
#include <NVideoWriterOptions.hpp>
namespace Neurotec { namespace Video
{
using Neurotec::Images::HNImage;
#include <NVideoWriter.h>
}}

namespace Neurotec { namespace Video
{

class N_CLASS(NVideoWriter) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NVideoWriter, NObject)

private:
	static HNVideoWriter Create(const N_CLASS(NStringWrapper) & fileName, NInt width, NInt height, NDouble frameRate, N_CLASS(NVideoWriterOptions) * pOptions)
	{
		HNVideoWriter handle;
		NCheck(NVideoWriterCreateFileN(fileName.GetHandle(), width, height, frameRate, ToHandle(pOptions), &handle));
		return handle;
	}

	N_CLASS(NVideoWriter)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NVideoWriter)(const N_CLASS(NStringWrapper) & fileName, NInt width, NInt height, NDouble frameRate, N_CLASS(NVideoWriterOptions) * pOptions)
		: N_CLASS(NObject)(Create(fileName, width, height, frameRate, pOptions), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NVideoWriter);
	}

	void WriteFrame(Neurotec::Images::N_CLASS(NImage) * pFrame)
	{
		NCheck(NVideoWriterWriteFrame(GetHandle(), pFrame->GetHandle()));
	}
};

}}

#endif // !N_VIDEO_WRITER_HPP_INCLUDED
