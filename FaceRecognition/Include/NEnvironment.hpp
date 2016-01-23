#ifndef N_ENVIRONMENT_HPP_INCLUDED
#define N_ENVIRONMENT_HPP_INCLUDED

#include <NCore.h>
namespace Neurotec
{
#include <NEnvironment.h>
}

namespace Neurotec
{

class N_CLASS(NEnvironment)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NEnvironment)

public:
	static N_CLASS(NString) GetCurrentDirectory()
	{
		HNString hPath;
		NCheck(NEnvironmentGetCurrentDirectory(&hPath));
		return N_CLASS(NString)(hPath, true);
	}

	static N_CLASS(NString) GetSystemDirectory()
	{
		HNString hPath;
		NCheck(NEnvironmentGetSystemDirectory(&hPath));
		return N_CLASS(NString)(hPath, true);
	}
};

}
#endif // !N_ENVIRONMENT_HPP_INCLUDED
