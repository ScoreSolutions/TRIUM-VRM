#ifndef N_PIXEL_FORMAT_HPP_INCLUDED
#define N_PIXEL_FORMAT_HPP_INCLUDED

#include <NSampleFormat.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::Media::NExtraChannel;
using ::Neurotec::Media::NChannelFormat;
using ::Neurotec::Media::NSampleFormat_;
#include <NPixelFormat.h>
}}

namespace Neurotec { namespace Images
{

#undef NPF_UNDEFINED

#undef NPF_GRAYSCALE_1U
#undef NPF_GRAYSCALE_2U
#undef NPF_GRAYSCALE_4U
#undef NPF_GRAYSCALE_8U
#undef NPF_GRAYSCALE_8S
#undef NPF_GRAYSCALE_A_8U
#undef NPF_GRAYSCALE_A_8S
#undef NPF_GRAYSCALE_PA_8U
#undef NPF_GRAYSCALE_PA_8S
#undef NPF_GRAYSCALE_16U
#undef NPF_GRAYSCALE_16S
#undef NPF_GRAYSCALE_A_16U
#undef NPF_GRAYSCALE_A_16S
#undef NPF_GRAYSCALE_PA_16U
#undef NPF_GRAYSCALE_PA_16S
#undef NPF_GRAYSCALE_32U
#undef NPF_GRAYSCALE_32S
#undef NPF_GRAYSCALE_A_32U
#undef NPF_GRAYSCALE_A_32S
#undef NPF_GRAYSCALE_PA_32U
#undef NPF_GRAYSCALE_PA_32S
#undef NPF_GRAYSCALE_64U
#undef NPF_GRAYSCALE_64S
#undef NPF_GRAYSCALE_A_64U
#undef NPF_GRAYSCALE_A_64S
#undef NPF_GRAYSCALE_PA_64U
#undef NPF_GRAYSCALE_PA_64S
#undef NPF_GRAYSCALE_32F
#undef NPF_GRAYSCALE_A_32F
#undef NPF_GRAYSCALE_PA_32F
#undef NPF_GRAYSCALE_64F
#undef NPF_GRAYSCALE_A_64F
#undef NPF_GRAYSCALE_PA_64F

#undef NPF_RGB_8U
#undef NPF_RGB_8S
#undef NPF_RGB_A_8U
#undef NPF_RGB_A_8S
#undef NPF_RGB_PA_8U
#undef NPF_RGB_PA_8S
#undef NPF_RGB_16U
#undef NPF_RGB_16S
#undef NPF_RGB_A_16U
#undef NPF_RGB_A_16S
#undef NPF_RGB_PA_16U
#undef NPF_RGB_PA_16S
#undef NPF_RGB_32U
#undef NPF_RGB_32S
#undef NPF_RGB_A_32U
#undef NPF_RGB_A_32S
#undef NPF_RGB_PA_32U
#undef NPF_RGB_PA_32S
#undef NPF_RGB_64U
#undef NPF_RGB_64S
#undef NPF_RGB_A_64U
#undef NPF_RGB_A_64S
#undef NPF_RGB_PA_64U
#undef NPF_RGB_PA_64S
#undef NPF_RGB_32F
#undef NPF_RGB_A_32F
#undef NPF_RGB_PA_32F
#undef NPF_RGB_64F
#undef NPF_RGB_A_64F
#undef NPF_RGB_PA_64F
#undef NPF_RGB_8U_INDEXED_1
#undef NPF_RGB_8U_INDEXED_2
#undef NPF_RGB_8U_INDEXED_4
#undef NPF_RGB_8U_INDEXED_8
#undef NPF_RGB_A_8U_INDEXED_1
#undef NPF_RGB_A_8U_INDEXED_2
#undef NPF_RGB_A_8U_INDEXED_4
#undef NPF_RGB_A_8U_INDEXED_8

class N_CLASS(NPixelFormat) : public ::Neurotec::Media::N_CLASS(NSampleFormat)
{
	N_DECLARE_BASIC_CLASS_DERIVED(NPixelFormat, ::Neurotec::Media::N_CLASS(NSampleFormat))

public:
	static N_CLASS(NType) * NPixelTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NPixelType), true, true);
	}

	static bool IsPixelTypeValid(NPixelType value)
	{
		return NPixelTypeIsValid(value) != 0;
	}

	static bool CanPixelTypeBeIndexed(NPixelType value)
	{
		return NPixelTypeCanBeIndexed(value) != 0;
	}

	static NSizeType CalcRowSize(NInt bitsPerPixel, NUInt length, NSizeType alignment = 1)
	{
		NSizeType value;
		NCheck(NPixelFormatCalcRowSize(bitsPerPixel, length, alignment, &value));
		return value;
	}

	N_CLASS(NPixelFormat)(NPixelType pixelType, NExtraChannel extraChannel, NInt channelCount, NChannelFormat channelFormat, NInt bitsPerChannel, NInt bitsPerIndex, NBool isSeparated)
	{
		NCheck(NPixelFormatCreate(pixelType, extraChannel, channelCount, channelFormat, bitsPerChannel, bitsPerIndex, isSeparated, &value));
	}

	NSizeType GetRowSize(NUInt length, NSizeType alignment = 1) const
	{
		NSizeType value;
		NCheck(NPixelFormatGetRowSize(this->value, length, alignment, &value));
		return value;
	}

	NSizeType GetPaletteSize(NInt length) const
	{
		NSizeType value;
		NCheck(NPixelFormatGetPaletteSize(this->value, length, &value));
		return value;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NPixelFormatToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	NPixelType GetPixelType() const
	{
		return NPixelFormatGetPixelType(value);
	}

	NInt GetBitsPerPixel() const
	{
		return NPixelFormatGetBitsPerPixel(value);
	}

	NSizeType GetBytesPerPixel() const
	{
		return NPixelFormatGetBytesPerPixel(value);
	}
};
N_TYPEDEF_TYPE(NPixelFormat)

const N_CLASS(NPixelFormat) NPF_UNDEFINED(0);

const N_CLASS(NPixelFormat) NPF_GRAYSCALE_1U(0x00001001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_2U(0x00101001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_4U(0x00201001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_8U(0x00301001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_8S(0x00311001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_8U(0x00302101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_8S(0x00312101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_8U(0x00302201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_8S(0x00312201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_16U(0x00401001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_16S(0x00411001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_16U(0x00402101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_16S(0x00412101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_16U(0x00402201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_16S(0x00412201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_32U(0x00501001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_32S(0x00511001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_32U(0x00502101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_32S(0x00512101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_32U(0x00502201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_32S(0x00512201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_64U(0x00601001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_64S(0x00611001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_64U(0x00602101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_64S(0x00612101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_64U(0x00602201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_64S(0x00612201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_32F(0x00521001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_32F(0x00522101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_32F(0x00522201);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_64F(0x00621001);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_A_64F(0x00622101);
const N_CLASS(NPixelFormat) NPF_GRAYSCALE_PA_64F(0x00622201);

const N_CLASS(NPixelFormat) NPF_RGB_8U(0x00303003);
const N_CLASS(NPixelFormat) NPF_RGB_8S(0x00313003);
const N_CLASS(NPixelFormat) NPF_RGB_A_8U(0x00304103);
const N_CLASS(NPixelFormat) NPF_RGB_A_8S(0x00314103);
const N_CLASS(NPixelFormat) NPF_RGB_PA_8U(0x00304203);
const N_CLASS(NPixelFormat) NPF_RGB_PA_8S(0x00314203);
const N_CLASS(NPixelFormat) NPF_RGB_16U(0x00403003);
const N_CLASS(NPixelFormat) NPF_RGB_16S(0x00413003);
const N_CLASS(NPixelFormat) NPF_RGB_A_16U(0x00404103);
const N_CLASS(NPixelFormat) NPF_RGB_A_16S(0x00414103);
const N_CLASS(NPixelFormat) NPF_RGB_PA_16U(0x00404203);
const N_CLASS(NPixelFormat) NPF_RGB_PA_16S(0x00414203);
const N_CLASS(NPixelFormat) NPF_RGB_32U(0x00503003);
const N_CLASS(NPixelFormat) NPF_RGB_32S(0x00513003);
const N_CLASS(NPixelFormat) NPF_RGB_A_32U(0x00504103);
const N_CLASS(NPixelFormat) NPF_RGB_A_32S(0x00514103);
const N_CLASS(NPixelFormat) NPF_RGB_PA_32U(0x00504203);
const N_CLASS(NPixelFormat) NPF_RGB_PA_32S(0x00514203);
const N_CLASS(NPixelFormat) NPF_RGB_64U(0x00603003);
const N_CLASS(NPixelFormat) NPF_RGB_64S(0x00613003);
const N_CLASS(NPixelFormat) NPF_RGB_A_64U(0x00604103);
const N_CLASS(NPixelFormat) NPF_RGB_A_64S(0x00614103);
const N_CLASS(NPixelFormat) NPF_RGB_PA_64U(0x00604203);
const N_CLASS(NPixelFormat) NPF_RGB_PA_64S(0x00614203);
const N_CLASS(NPixelFormat) NPF_RGB_32F(0x00523003);
const N_CLASS(NPixelFormat) NPF_RGB_A_32F(0x00524103);
const N_CLASS(NPixelFormat) NPF_RGB_PA_32F(0x00524203);
const N_CLASS(NPixelFormat) NPF_RGB_64F(0x00623003);
const N_CLASS(NPixelFormat) NPF_RGB_A_64F(0x00624103);
const N_CLASS(NPixelFormat) NPF_RGB_PA_64F(0x00624203);
const N_CLASS(NPixelFormat) NPF_RGB_8U_INDEXED_1(0x01303003);
const N_CLASS(NPixelFormat) NPF_RGB_8U_INDEXED_2(0x02303003);
const N_CLASS(NPixelFormat) NPF_RGB_8U_INDEXED_4(0x03303003);
const N_CLASS(NPixelFormat) NPF_RGB_8U_INDEXED_8(0x04303003);
const N_CLASS(NPixelFormat) NPF_RGB_A_8U_INDEXED_1(0x01304103);
const N_CLASS(NPixelFormat) NPF_RGB_A_8U_INDEXED_2(0x02304103);
const N_CLASS(NPixelFormat) NPF_RGB_A_8U_INDEXED_4(0x03304103);
const N_CLASS(NPixelFormat) NPF_RGB_A_8U_INDEXED_8(0x04304103);

N_DEPRECATED("constant is deprecated, use NPF_GRAYSCALE_1U instead")
const N_CLASS(NPixelFormat) npfMonochrome(NPF_GRAYSCALE_1U);
N_DEPRECATED("constant is deprecated, use NPF_GRAYSCALE_8U instead")
const N_CLASS(NPixelFormat) npfGrayscale(NPF_GRAYSCALE_8U);
N_DEPRECATED("constant is deprecated, use NPF_RGB_8U instead")
const N_CLASS(NPixelFormat) npfRgb(NPF_RGB_8U);

}}

#endif // !N_PIXEL_FORMAT_HPP_INCLUDED
