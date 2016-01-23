#include <NImage.hpp>

#ifndef N_MONOCHROME_IMAGE_HPP_INCLUDED
#define N_MONOCHROME_IMAGE_HPP_INCLUDED

namespace Neurotec { namespace Images
{
#include <NMonochromeImage.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NMonochromeImage) : public N_CLASS(NImage)
{
	N_DECLARE_OBJECT_CLASS(NMonochromeImage, NImage)

private:
	N_CLASS(NMonochromeImage)(HNObject handle, bool claimHandle)
		: N_CLASS(NImage)(handle, claimHandle)
	{
	}

public:
	bool GetMinValue() const
	{
		NBool value;
		NCheck(NMonochromeImageGetMinValue(GetHandle(), &value));
		return value != 0;
	}

	void SetMinValue(bool value)
	{
		NCheck(NMonochromeImageSetMinValue(GetHandle(), value ? NTrue : NFalse));
	}

	bool GetMaxValue() const
	{
		NBool value;
		NCheck(NMonochromeImageGetMaxValue(GetHandle(), &value));
		return value != 0;
	}

	void SetMaxValue(bool value)
	{
		NCheck(NMonochromeImageSetMaxValue(GetHandle(), value ? NTrue : NFalse));
	}

	bool GetPixel(NUInt x, NUInt y) const
	{
		NBool value;
		NCheck(NMonochromeImageGetPixel(GetHandle(), x, y, &value));
		return value != 0;
	}

	void SetPixel(NUInt x, NUInt y, bool value)
	{
		NCheck(NMonochromeImageSetPixel(GetHandle(), x, y, value ? NTrue : NFalse));
	}
};

}}

#endif // !N_MONOCHROME_IMAGE_HPP_INCLUDED
