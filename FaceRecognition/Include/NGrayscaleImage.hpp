#include <NImage.hpp>

#ifndef N_GRAYSCALE_IMAGE_HPP_INCLUDED
#define N_GRAYSCALE_IMAGE_HPP_INCLUDED

namespace Neurotec { namespace Images
{
#include <NGrayscaleImage.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NGrayscaleImage) : public N_CLASS(NImage)
{
	N_DECLARE_OBJECT_CLASS(NGrayscaleImage, NImage)

private:
	N_CLASS(NGrayscaleImage)(HNObject handle, bool claimHandle)
		: N_CLASS(NImage)(handle, claimHandle)
	{
	}

public:
	NByte GetMinValue() const
	{
		NByte value;
		NCheck(NGrayscaleImageGetMinValue(GetHandle(), &value));
		return value;
	}

	void SetMinValue(NByte value)
	{
		NCheck(NGrayscaleImageSetMinValue(GetHandle(), value));
	}

	NByte GetMaxValue() const
	{
		NByte value;
		NCheck(NGrayscaleImageGetMaxValue(GetHandle(), &value));
		return value;
	}

	void SetMaxValue(NByte value)
	{
		NCheck(NGrayscaleImageSetMaxValue(GetHandle(), value));
	}

	NByte GetPixel(NUInt x, NUInt y) const
	{
		NByte value;
		NCheck(NGrayscaleImageGetPixel(GetHandle(), x, y, &value));
		return value;
	}

	void SetPixel(NUInt x, NUInt y, NByte value)
	{
		NCheck(NGrayscaleImageSetPixel(GetHandle(), x, y, value));
	}
};

}}

#endif // !N_GRAYSCALE_IMAGE_HPP_INCLUDED
