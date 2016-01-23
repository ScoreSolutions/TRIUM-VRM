#ifndef N_IMAGE_INFO_HPP_INCLUDED
#define N_IMAGE_INFO_HPP_INCLUDED

#include <NExpandableObject.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::HNStream;
using ::Neurotec::IO::NFileAccess;
using ::Neurotec::IO::HNBuffer;
#include <NImageInfo.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NImageFormat);

class N_CLASS(NImageInfo) : public N_CLASS(NExpandableObject)
{
	N_DECLARE_OBJECT_CLASS(NImageInfo, NExpandableObject)

private:
	static HNImageInfo Create()
	{
		HNImageInfo handle;
		NCheck(NImageInfoCreate(&handle));
		return handle;
	}

protected:
	N_CLASS(NImageInfo)(HNObject handle, bool claimHandle)
		: N_CLASS(NExpandableObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NImageInfo)()
		: N_CLASS(NExpandableObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NImageInfo);
	}

	N_CLASS(NImageFormat) * GetFormat() const;
};

}}

#include <NImageFormat.hpp>

namespace Neurotec { namespace Images
{

inline N_CLASS(NImageFormat) * N_CLASS(NImageInfo)::GetFormat() const
{
	return GetObject<HandleType, N_CLASS(NImageFormat)>(NImageInfoGetFormatEx, true, true);
}

}}

#endif // !N_IMAGE_INFO_HPP_INCLUDED
