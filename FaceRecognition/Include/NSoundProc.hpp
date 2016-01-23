#ifndef N_SOUND_PROC_HPP_INCLUDED
#define N_SOUND_PROC_HPP_INCLUDED

#include <NSoundBuffer.hpp>
namespace Neurotec { namespace Sound { namespace Processing
{
using ::Neurotec::Sound::HNSoundBuffer;
#include <NSoundProc.h>
}}}

namespace Neurotec { namespace Sound { namespace Processing
{

class N_CLASS(NSoundProc)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NSoundProc)

public:
	static NDouble GetSoundLevel(N_CLASS(NSoundBuffer) * pSoundBuffer)
	{
		if (!pSoundBuffer) NThrowArgumentNullException(N_T("pSoundBuffer"));
		NDouble soundLevel;
		NCheck(NspGetSoundLevel(pSoundBuffer->GetHandle(), &soundLevel));
		return soundLevel;
	}
};

}}}

#endif // !N_SOUND_PROC_HPP_INCLUDED
