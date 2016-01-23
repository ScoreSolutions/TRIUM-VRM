#ifndef N_MEDIA_FORMAT_HPP_INCLUDED
#define N_MEDIA_FORMAT_HPP_INCLUDED

#include <NMediaTypes.hpp>
#include <NExpandableObject.hpp>
namespace Neurotec { namespace Media
{
#include <NMediaFormat.h>
}}

namespace Neurotec { namespace Media
{

class N_CLASS(NMediaFormat) : public N_CLASS(NExpandableObject)
{
	N_DECLARE_OBJECT_CLASS(NMediaFormat, NExpandableObject)

protected:
	N_CLASS(NMediaFormat)(HNObject handle, bool claimHandle)
		: N_CLASS(NExpandableObject)(handle, claimHandle)
	{
	}

public:
	NMediaType GetMediaType() const
	{
		NMediaType value;
		NCheck(NMediaFormatGetMediaType(GetHandle(), &value));
		return value;
	}

	NUInt GetMediaSubtype() const
	{
		NUInt value;
		NCheck(NMediaFormatGetMediaSubtype(GetHandle(), &value));
		return value;
	}

	void SetMediaSubtype(NUInt value)
	{
		NCheck(NMediaFormatSetMediaSubtype(GetHandle(), value));
	}

	bool IsCompatibleWith(N_CLASS(NMediaFormat) * pOtherFormat) const
	{
		NBool result;
		NCheck(NMediaFormatIsCompatibleWith(GetHandle(), ToHandle(pOtherFormat), &result));
		return result != 0;
	}
};

}}

#endif // !N_MEDIA_FORMAT_HPP_INCLUDED
