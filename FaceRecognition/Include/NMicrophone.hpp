#include <NCaptureDevice.hpp>

#ifndef N_MICROPHONE_HPP_INCLUDED
#define N_MICROPHONE_HPP_INCLUDED

#include <NSoundBuffer.hpp>
namespace Neurotec { namespace Devices
{
using ::Neurotec::Sound::HNSoundBuffer;
#include <NMicrophone.h>
}}

namespace Neurotec { namespace Devices
{
class N_CLASS(NMicrophone) : public N_CLASS(NCaptureDevice)
{
	N_DECLARE_OBJECT_CLASS(NMicrophone, NCaptureDevice)

private:
	N_CLASS(NMicrophone)(HNObject handle, bool claimHandle)
		: N_CLASS(NCaptureDevice)(handle, claimHandle)
	{
	}

public:
	::Neurotec::Sound::N_CLASS(NSoundBuffer) * GetSoundSample()
	{
		HNSoundBuffer hSoundBuffer = NULL;
		NCheck(NMicrophoneGetSoundSample(GetHandle(), &hSoundBuffer));
		try
		{
			return FromHandle< ::Neurotec::Sound::N_CLASS(NSoundBuffer)>(hSoundBuffer);
		}
		catch (...)
		{
			Unref(hSoundBuffer);
			throw;
		}
	}
};

}}

#endif // !N_MICROPHONE_HPP_INCLUDED
