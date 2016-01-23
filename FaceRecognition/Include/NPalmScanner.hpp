#include <NDevice.hpp>

#ifndef N_PALM_SCANNER_HPP_INCLUDED
#define N_PALM_SCANNER_HPP_INCLUDED

#include <NFScanner.hpp>
namespace Neurotec { namespace Devices
{
#include <NPalmScanner.h>
}}

namespace Neurotec { namespace Devices
{

class N_CLASS(NPalmScanner) : public N_CLASS(NFScanner)
{
	N_DECLARE_OBJECT_CLASS(NPalmScanner, NFScanner)

private:
	N_CLASS(NPalmScanner)(HNObject handle, bool claimHandle)
		: N_CLASS(NFScanner)(handle, claimHandle)
	{
	}
};

}}

#endif // !N_IRIS_SCANNER_HPP_INCLUDED
