#ifndef N_EXPANDABLE_OBJECT_HPP_INCLUDED
#define N_EXPANDABLE_OBJECT_HPP_INCLUDED

#include <NObject.hpp>
#include <NPropertyBag.hpp>
namespace Neurotec
{
#include <NExpandableObject.h>
}

namespace Neurotec
{

class N_CLASS(NExpandableObject) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NExpandableObject, NObject)

protected:
	N_CLASS(NExpandableObject)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NPropertyBag) * GetProperties() const
	{
		return GetObject<HandleType, N_CLASS(NPropertyBag)>(NExpandableObjectGetProperties, true, true);
	}
};

}

#endif // !N_EXPANDABLE_OBJECT_HPP_INCLUDED
