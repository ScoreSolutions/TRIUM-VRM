#ifndef N_MICROPHONE_H_INCLUDED
#define N_MICROPHONE_H_INCLUDED

#include <NCaptureDevice.h>
#include <NSoundBuffer.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NMicrophone, NCaptureDevice)

NResult N_API NMicrophoneGetSoundSample(HNMicrophone hDevice, HNSoundBuffer * phSoundBuffer);

#ifdef N_CPP
}
#endif

#endif // !N_MICROPHONE_H_INCLUDED
