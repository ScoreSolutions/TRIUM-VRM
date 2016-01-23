#ifndef N_VIDEO_HPP_INCLUDED
#define N_VIDEO_HPP_INCLUDED

#include <NMedia.hpp>
namespace Neurotec { namespace Video
{
#include <NVideo.h>
}}

namespace Neurotec { namespace Video
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use Neurotec::Media::" N_STRINGIZEA(N_CLASS(NMedia)) " instead")
	N_CLASS(NVideo)
{
private:
	N_CLASS(NVideo)()
	{
	}

public:
	static void GetInfo(NLibraryInfo * pValue)
	{
		NCheck(::Neurotec::Media::NMediaGetInfo(pValue));
	}
};
#include <NReDeprecate.h>

}}

#endif // !N_VIDEO_HPP_INCLUDED
