#ifndef N_MEDIA_PROC_HPP_INCLUDED
#define N_MEDIA_PROC_HPP_INCLUDED

#include <NSoundProc.hpp>
#include <NGrayscaleImageProc.hpp>
#include <NRgbImageProc.hpp>
namespace Neurotec { namespace Media { namespace Processing
{
#include <NMediaProc.h>
}}}

namespace Neurotec { namespace Media { namespace Processing
{

class N_CLASS(NMediaProc)
{
private:
	N_CLASS(NMediaProc)()
	{
	}

	N_DECLARE_MODULE_CLASS(NMediaProc)
};

}}}

#endif // !N_MEDIA_PROC_HPP_INCLUDED
