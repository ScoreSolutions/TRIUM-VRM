#ifndef N_MEDIA_TYPES_HPP_INCLUDED
#define N_MEDIA_TYPES_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Media
{
#include <NMediaTypes.h>
}}

namespace Neurotec { namespace Media
{

class N_CLASS(NMediaTypes)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NMediaTypes)

public:
	static N_CLASS(NType) * NMediaTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NMediaType), true, true);
	}

	static N_CLASS(NType) * NMediaStateNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NMediaState), true, true);
	}

	static N_CLASS(NType) * NVideoInterlaceModeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NVideoInterlaceMode), true, true);
	}

	static bool IsMediaTypeValid(NMediaType value)
	{
		return NMediaTypeIsValid(value) != 0;
	}

	static bool IsMediaTypeValidSingle(NMediaType value)
	{
		return NMediaTypeIsValidSingle(value) != 0;
	}

	static bool IsVideoInterlaceModeValid(NVideoInterlaceMode value)
	{
		return NVideoInterlaceModeIsValid(value) != 0;
	}
};

}}

#endif // !N_MEDIA_TYPES_HPP_INCLUDED
