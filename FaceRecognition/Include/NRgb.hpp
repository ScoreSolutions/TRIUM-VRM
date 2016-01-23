#ifndef N_RGB_HPP_INCLUDED
#define N_RGB_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Images
{
#include <NRgb.h>
}}

namespace Neurotec { namespace Images
{

class N_CLASS(NRgb) : public NRgb_
{
	N_DECLARE_STRUCT_CLASS(NRgb)

public:
	N_CLASS(NRgb)(NByte red, NByte green, NByte blue)
	{
		Red = red;
		Green = green;
		Blue = blue;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NRgbToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NRgb)

}}

#endif // !N_RGB_IMAGE_HPP_INCLUDED
