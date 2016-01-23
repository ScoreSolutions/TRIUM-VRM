#ifndef N_DIRECTORY_HPP_INCLUDED
#define N_DIRECTORY_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace IO
{
#include <NDirectory.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NDirectory)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NDirectory)

public:
	static bool Exists(const N_CLASS(NStringWrapper) & path)
	{
		NBool value;
		NCheck(NDirectoryExistsN(path.GetHandle(), &value));
		return value != 0;
	}
};

}}

#endif // !N_DIRECTORY_HPP_INCLUDED
