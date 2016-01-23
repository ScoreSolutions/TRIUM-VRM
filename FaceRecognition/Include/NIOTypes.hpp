#ifndef N_IO_TYPES_HPP_INCLUDED
#define N_IO_TYPES_HPP_INCLUDED

#include <NTypes.hpp>
namespace Neurotec { namespace IO
{
#include <NIOTypes.h>
}}

namespace Neurotec { namespace IO
{

class N_CLASS(NIOTypes)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NIOTypes)

public:
	static N_CLASS(NType) * NByteOrderNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NByteOrder), true, true);
	}

	static N_CLASS(NType) * NSeekOriginNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NSeekOrigin), true, true);
	}

	static N_CLASS(NType) * NFileModeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFileMode), true, true);
	}

	static N_CLASS(NType) * NFileAccessNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFileAccess), true, true);
	}

	static N_CLASS(NType) * NFileShareNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFileShare), true, true);
	}

	static bool IsByteOrderValid(NByteOrder value)
	{
		return NByteOrderIsValid(value) != 0;
	}

	static NByteOrder GetByteOrderSystem()
	{
		return NByteOrderGetSystem();
	}

	static bool IsByteOrderReverse(NByteOrder value)
	{
		return NByteOrderIsReverse(value) != 0;
	}

	static bool IsSeekOriginValid(NSeekOrigin value)
	{
		return NSeekOriginIsValid(value) != 0;
	}

	static bool IsFileModeValid(NFileMode value)
	{
		return NFileModeIsValid(value) != 0;
	}

	static bool IsFileAccessValid(NFileAccess value)
	{
		return NFileAccessIsValid(value) != 0;
	}

	static bool IsFileShareValid(NFileShare value)
	{
		return NFileShareIsValid(value) != 0;
	}
};

}}

#endif // !N_IO_TYPES_HPP_INCLUDED
