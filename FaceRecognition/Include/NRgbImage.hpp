#include <NImage.hpp>

#ifndef N_RGB_IMAGE_HPP_INCLUDED
#define N_RGB_IMAGE_HPP_INCLUDED

#include <NRgb.hpp>
namespace Neurotec { namespace Images
{
#include <NRgbImage.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NRgbImage) : public N_CLASS(NImage)
{
	N_DECLARE_OBJECT_CLASS(NRgbImage, NImage)

private:
	N_CLASS(NRgbImage)(HNObject handle, bool claimHandle)
		: N_CLASS(NImage)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NRgb) GetMinValue() const
	{
		N_CLASS(NRgb) value;
		NCheck(NRgbImageGetMinValue(GetHandle(), &value));
		return value;
	}

	void SetMinValue(const N_CLASS(NRgb) &value)
	{
		NCheck(NRgbImageSetMinValue(GetHandle(), &value));
	}

	N_CLASS(NRgb) GetMaxValue() const
	{
		N_CLASS(NRgb) value;
		NCheck(NRgbImageGetMaxValue(GetHandle(), &value));
		return value;
	}

	void SetMaxValue(const N_CLASS(NRgb) &value)
	{
		NCheck(NRgbImageSetMaxValue(GetHandle(), &value));
	}

	N_CLASS(NRgb) GetPixel(NUInt x, NUInt y) const
	{
		N_CLASS(NRgb) value;
		NCheck(NRgbImageGetPixel(GetHandle(), x, y, &value));
		return value;
	}

	void SetPixel(NUInt x, NUInt y, const N_CLASS(NRgb) &value)
	{
		NCheck(NRgbImageSetPixel(GetHandle(), x, y, &value));
	}
};

}}

#endif // !N_RGB_IMAGE_HPP_INCLUDED
