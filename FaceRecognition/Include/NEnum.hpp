#ifndef N_ENUM_HPP_INCLUDED
#define N_ENUM_HPP_INCLUDED

#include <NType.hpp>
namespace Neurotec
{
#include <NEnum.h>
}

namespace Neurotec
{

class N_CLASS(NEnum)
{
private:
	N_CLASS(NEnum)();
	N_CLASS(NEnum)(const N_CLASS(NTypes) &);

public:
	static N_CLASS(NString) ToString(N_CLASS(NType) * pType, NInt32 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		HNString hValue;
		NCheck(NEnumToStringN(pType->GetHandle(), value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static bool TryParse(N_CLASS(NType) * pType, const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NInt32 * pValue)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NBool result;
		NCheck(NEnumTryParseN(pType->GetHandle(), value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool TryParse(N_CLASS(NType) * pType, const N_CLASS(NStringWrapper) & value, NInt32 * pValue) { return TryParse(pType, value, N_CLASS(NString)(), pValue); }

	static NInt32 Parse(N_CLASS(NType) * pType, const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NInt32 result;
		NCheck(NEnumParseN(pType->GetHandle(), value.GetHandle(), format.GetHandle(), &result));
		return result;
	}
};

}

#endif // !N_ENUM_HPP_INCLUDED
