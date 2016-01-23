#ifndef N_GEOMETRY_HPP_INCLUDED
#define N_GEOMETRY_HPP_INCLUDED

#include <NTypes.hpp>
namespace Neurotec { namespace Geometry
{
#include <NGeometry.h>
}}

namespace Neurotec { namespace Geometry
{

class N_CLASS(NPoint) : public NPoint_
{
	N_DECLARE_STRUCT_CLASS(NPoint)

public:
	N_CLASS(NPoint)(NInt x, NInt y)
	{
		X = x;
		Y = y;
	}
};
N_TYPEDEF_TYPE(NPoint)

class N_CLASS(NPointF) : public NPointF_
{
	N_DECLARE_STRUCT_CLASS(NPointF)

public:
	N_CLASS(NPointF)(NFloat x, NFloat y)
	{
		X = x;
		Y = y;
	}
};
N_TYPEDEF_TYPE(NPointF)

class N_CLASS(NPointD) : public NPointD_
{
	N_DECLARE_STRUCT_CLASS(NPointD)

public:
	N_CLASS(NPointD)(NDouble x, NDouble y)
	{
		X = x;
		Y = y;
	}
};
N_TYPEDEF_TYPE(NPointD)

class N_CLASS(NSize) : public NSize_
{
	N_DECLARE_STRUCT_CLASS(NSize)

public:
	N_CLASS(NSize)(NInt width, NInt height)
	{
		Width = width;
		Height = height;
	}
};
N_TYPEDEF_TYPE(NSize)

class N_CLASS(NSizeF) : public NSizeF_
{
	N_DECLARE_STRUCT_CLASS(NSizeF)

public:
	N_CLASS(NSizeF)(NFloat width, NFloat height)
	{
		Width = width;
		Height = height;
	}
};
N_TYPEDEF_TYPE(NSizeF)

class N_CLASS(NSizeD) : public NSizeD_
{
	N_DECLARE_STRUCT_CLASS(NSizeD)

public:
	N_CLASS(NSizeD)(NDouble width, NDouble height)
	{
		Width = width;
		Height = height;
	}
};
N_TYPEDEF_TYPE(NSizeD)

class N_CLASS(NRect) : public NRect_
{
	N_DECLARE_STRUCT_CLASS(NRect)

public:
	N_CLASS(NRect)(NInt x, NInt y, NInt width, NInt height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
};
N_TYPEDEF_TYPE(NRect)

class N_CLASS(NRectF) : public NRectF_
{
	N_DECLARE_STRUCT_CLASS(NRectF)

public:
	N_CLASS(NRectF)(NFloat x, NFloat y, NFloat width, NFloat height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
};
N_TYPEDEF_TYPE(NRectF)

class N_CLASS(NRectD) : public NRectD_
{
	N_DECLARE_STRUCT_CLASS(NRectD)

public:
	N_CLASS(NRectD)(NDouble x, NDouble y, NDouble width, NDouble height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
};
N_TYPEDEF_TYPE(NRectD)

class N_CLASS(NGeometry)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NGeometry)

public:
	static N_CLASS(NType) * NInterpolationModeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NInterpolationMode), true, true);
	}
};

}}

#endif // !N_GEOMETRY_HPP_INCLUDED
