#include <NDevice.hpp>

#ifndef N_FINGER_SCANNER_HPP_INCLUDED
#define N_FINGER_SCANNER_HPP_INCLUDED

#include <NFScanner.hpp>
namespace Neurotec { namespace Devices
{
#include <NFingerScanner.h>
}}

namespace Neurotec { namespace Devices
{

class N_CLASS(NFingerScanner) : public N_CLASS(NFScanner)
{
	N_DECLARE_OBJECT_CLASS(NFingerScanner, NFScanner)

private:
	N_CLASS(NFingerScanner)(HNObject handle, bool claimHandle)
		: N_CLASS(NFScanner)(handle, claimHandle)
	{
	}
};

}}

#endif // !N_FINGER_SCANNER_HPP_INCLUDED
