#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
#define N_BIOMETRIC_TYPES_HPP_INCLUDED

#include <NTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NBiometricTypes.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef N_BIOMETRIC_QUALITY_MIN
#undef N_BIOMETRIC_QUALITY_MAX
#undef N_BIOMETRIC_QUALITY_UNKNOWN
#undef N_BIOMETRIC_QUALITY_FAILED

#undef N_PHRASE_ID_UNKNOWN

const NByte N_BIOMETRIC_QUALITY_MIN = 0;
const NByte N_BIOMETRIC_QUALITY_MAX = 100;
const NByte N_BIOMETRIC_QUALITY_UNKNOWN = 254;
const NByte N_BIOMETRIC_QUALITY_FAILED = 255;

const NInt N_PHRASE_ID_UNKNOWN = 0;

class N_CLASS(NFMinutia) : public NFMinutia_
{
	N_DECLARE_STRUCT_CLASS(NFMinutia)

public:
	N_CLASS(NFMinutia)(NUShort x, NUShort y, NFMinutiaType type, NByte angle, NByte quality = 0, NByte curvature = 255, NByte g = 255)
	{
		X = x;
		Y = y;
		Type = type;
		Angle = angle;
		Quality = quality;
		Curvature = curvature;
		G = g;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NFMinutiaToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NFMinutia)

class N_CLASS(NFMinutiaNeighbor) : public NFMinutiaNeighbor_
{
	N_DECLARE_STRUCT_CLASS(NFMinutiaNeighbor)

public:
	N_CLASS(NFMinutiaNeighbor)(NInt index, NByte ridgeCount)
	{
		Index = index;
		RidgeCount = ridgeCount;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NFMinutiaNeighborToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NFMinutiaNeighbor)

class N_CLASS(NFCore) : public NFCore_
{
	N_DECLARE_STRUCT_CLASS(NFCore)

public:
	N_CLASS(NFCore)(NUShort x, NUShort y, NInt angle = -1)
	{
		X = x;
		Y = y;
		Angle = angle;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NFCoreToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NFCore)

class N_CLASS(NFDelta) : public NFDelta_
{
	N_DECLARE_STRUCT_CLASS(NFDelta)

public:
	N_CLASS(NFDelta)(NUShort x, NUShort y, NInt angle1 = -1, NInt angle2 = -1, NInt angle3 = -1)
	{
		X = x;
		Y = y;
		Angle1 = angle1;
		Angle2 = angle2;
		Angle3 = angle3;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NFDeltaToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NFDelta)

class N_CLASS(NFDoubleCore) : public NFDoubleCore_
{
	N_DECLARE_STRUCT_CLASS(NFDoubleCore)

public:
	N_CLASS(NFDoubleCore)(NUShort x, NUShort y)
	{
		X = x;
		Y = y;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NFDoubleCoreToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NFDoubleCore)

class N_CLASS(NLFeaturePoint) : public NLFeaturePoint_
{
	N_DECLARE_STRUCT_CLASS(NLFeaturePoint)

public:
	N_CLASS(NLFeaturePoint)(NUShort code, NUShort x, NUShort y, NByte confidence = N_BIOMETRIC_QUALITY_UNKNOWN)
	{
		Code = code;
		X = x;
		Y = y;
		Confidence = confidence;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NLFeaturePointToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NLFeaturePoint)

class N_CLASS(NBiometricTypes)
{
	N_DECLARE_STATIC_OBJECT_CLASS(NBiometricTypes)

public:
	static N_CLASS(NType) * NBiometricTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NBiometricType), true, true);
	}

	static N_CLASS(NType) * NBiometricSubtypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NBiometricSubtype), true, true);
	}

	static N_CLASS(NType) * NBiometricStatusNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NBiometricStatus), true, true);
	}

	static N_CLASS(NType) * NFImpressionTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFImpressionType), true, true);
	}

	static N_CLASS(NType) * NFPositionNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFPosition), true, true);
	}

	static N_CLASS(NType) * NEPositionNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NEPosition), true, true);
	}

	static N_CLASS(NType) * NFPatternClassNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFPatternClass), true, true);
	}

	static N_CLASS(NType) * NFMinutiaFormatNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFMinutiaFormat), true, true);
	}

	static N_CLASS(NType) * NFMinutiaTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFMinutiaType), true, true);
	}

	static N_CLASS(NType) * NFRidgeCountsTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFRidgeCountsType), true, true);
	}

	static N_CLASS(NType) * NGenderNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NGender), true, true);
	}

	static N_CLASS(NType) * NLPropertiesNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NLProperties), true, true);
	}

	static N_CLASS(NType) * NLExpressionNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NLExpression), true, true);
	}

	static bool IsBiometricTypeValid(NBiometricType value)
	{
		return NBiometricTypeIsValid(value) != 0;
	}

	static bool IsBiometricSubtypeValid(NBiometricSubtype value)
	{
		return NBiometricSubtypeIsValid(value) != 0;
	}

	static bool IsBiometricStatusValid(NBiometricStatus value)
	{
		return NBiometricStatusIsValid(value) != 0;
	}

	static bool IsBiometricStatusFinal(NBiometricStatus value)
	{
		return NBiometricStatusIsFinal(value) != 0;
	}

	static bool IsImpressionTypeValidFinger(NFImpressionType value)
	{
		return NFImpressionTypeIsValidFinger(value) != 0;
	}

	static bool IsImpressionTypeValidPalm(NFImpressionType value)
	{
		return NFImpressionTypeIsValidPalm(value) != 0;
	}

	static bool IsImpressionTypeValid(NFImpressionType value)
	{
		return NFImpressionTypeIsValid(value) != 0;
	}

	static bool IsImpressionTypeGeneric(NFImpressionType value)
	{
		return NFImpressionTypeIsGeneric(value) != 0;
	}

	static bool IsImpressionTypeFinger(NFImpressionType value)
	{
		return NFImpressionTypeIsFinger(value) != 0;
	}

	static bool IsImpressionTypePalm(NFImpressionType value)
	{
		return NFImpressionTypeIsPalm(value) != 0;
	}

	static NFImpressionType ToImpressionTypeFinger(NFImpressionType value)
	{
		return NFImpressionTypeToFinger(value);
	}

	static bool IsImpressionTypePlain(NFImpressionType value)
	{
		return NFImpressionTypeIsPlain(value) != 0;
	}

	static bool IsImpressionTypeRolled(NFImpressionType value)
	{
		return NFImpressionTypeIsRolled(value) != 0;
	}

	static bool IsImpressionTypeSwipe(NFImpressionType value)
	{
		return NFImpressionTypeIsSwipe(value) != 0;
	}

	static bool IsImpressionTypeContactless(NFImpressionType value)
	{
		return NFImpressionTypeIsContactless(value) != 0;
	}

	static bool IsImpressionTypeContact(NFImpressionType value)
	{
		return NFImpressionTypeIsContact(value) != 0;
	}

	static bool IsImpressionTypeLiveScan(NFImpressionType value)
	{
		return NFImpressionTypeIsLiveScan(value) != 0;
	}

	static bool IsImpressionTypeNonliveScan(NFImpressionType value)
	{
		return NFImpressionTypeIsNonliveScan(value) != 0;
	}

	static bool IsImpressionTypeLatent(NFImpressionType value)
	{
		return NFImpressionTypeIsLatent(value) != 0;
	}

	static bool IsImpressionTypeOptical(NFImpressionType value)
	{
		return NFImpressionTypeIsOptical(value) != 0;
	}

	static bool IsImpressionTypeNonOptical(NFImpressionType value)
	{
		return NFImpressionTypeIsNonOptical(value) != 0;
	}

	static bool IsImpressionTypeCompatibleWith(NFImpressionType value, NFImpressionType otherValue)
	{
		return NFImpressionTypeIsCompatibleWith(value, otherValue) != 0;
	}

	static bool IsImpressionTypeOneOf(NFImpressionType value, NFImpressionType * arSupportedImpressionTypes, NInt supportedImressionTypeCount)
	{
		NBool result;
		NCheck(NFImpressionTypeIsOneOf(value, arSupportedImpressionTypes, supportedImressionTypeCount, &result));
		return result != 0;
	}

	static bool IsPositionValidTheFinger(NFPosition value)
	{
		return NFPositionIsValidTheFinger(value) != 0;
	}

	static bool IsPositionValidFinger(NFPosition value)
	{
		return NFPositionIsValidFinger(value) != 0;
	}

	static bool IsPositionValidPalm(NFPosition value)
	{
		return NFPositionIsValidPalm(value) != 0;
	}

	static bool IsPositionValid(NFPosition value)
	{
		return NFPositionIsValid(value) != 0;
	}

	static bool IsPositionTheFinger(NFPosition value)
	{
		return NFPositionIsTheFinger(value) != 0;
	}

	static bool IsPositionFinger(NFPosition value)
	{
		return NFPositionIsFinger(value) != 0;
	}

	static bool IsPositionThePalm(NFPosition value)
	{
		return NFPositionIsThePalm(value) != 0;
	}

	static bool IsPositionPalm(NFPosition value)
	{
		return NFPositionIsPalm(value) != 0;
	}

	static bool IsPositionSingleFinger(NFPosition value)
	{
		return NFPositionIsSingleFinger(value) != 0;
	}

	static bool IsPositionTwoFingers(NFPosition value)
	{
		return NFPositionIsTwoFingers(value) != 0;
	}

	static bool IsPositionThreeFingers(NFPosition value)
	{
		return NFPositionIsThreeFingers(value) != 0;
	}

	static bool IsPositionFourFingers(NFPosition value)
	{
		return NFPositionIsFourFingers(value) != 0;
	}

	static bool IsPositionKnown(NFPosition value)
	{
		return NFPositionIsKnown(value) != 0;
	}

	static bool IsPositionRight(NFPosition value)
	{
		return NFPositionIsRight(value) != 0;
	}

	static bool IsPositionLeft(NFPosition value)
	{
		return NFPositionIsLeft(value) != 0;
	}

	static bool IsPositionLeftAndRight(NFPosition value)
	{
		return NFPositionIsLeftAndRight(value) != 0;
	}

	static bool IsPositionCompatibleWith(NFPosition value, NFPosition otherValue)
	{
		return NFPositionIsCompatibleWith(value, otherValue) != 0;
	}

	static bool IsPositionCompatibleWith(NFPosition value, NFImpressionType imp)
	{
		return NFPositionIsCompatibleWithImpressionType(value, imp) != 0;
	}

	static bool IsPositionOneOf(NFPosition value, NFPosition * arSupportedPositions, NInt supportedPositionCount)
	{
		NBool result;
		NCheck(NFPositionIsOneOf(value, arSupportedPositions, supportedPositionCount, &result));
		return result != 0;
	}

	static NInt GetPositionAvailableParts(NFPosition value, NFPosition * arMissingPositions, NInt missingPositionCount, NFPosition * arResults, NInt resultsLength = N_INT_MAX)
	{
		return NCheck(NFPositionGetAvailableParts(value, arMissingPositions, missingPositionCount, arResults, resultsLength));
	}

	static NFPosition * GetPositionAvailableParts(NFPosition value, NFPosition * arMissingPositions, NInt missingPositionCount, NInt * pCount)
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		NInt count = GetPositionAvailableParts(value, arMissingPositions, missingPositionCount, NULL, 0);
		auto_array<NFPosition> results(count);
		*pCount = GetPositionAvailableParts(value, arMissingPositions, missingPositionCount, results.get(), count);
		return results.release();
	}

	static bool IsPositionValidTheEye(NEPosition value)
	{
		return NEPositionIsValidTheEye(value) != 0;
	}

	static bool IsPositionValid(NEPosition value)
	{
		return NEPositionIsValid(value) != 0;
	}

	static bool IsPositionSingleEye(NEPosition value)
	{
		return NEPositionIsSingleEye(value) != 0;
	}

	static bool IsPositionTwoEyes(NEPosition value)
	{
		return NEPositionIsTwoEyes(value) != 0;
	}

	static bool IsPositionKnown(NEPosition value)
	{
		return NEPositionIsKnown(value) != 0;
	}

	static bool IsPositionRight(NEPosition value)
	{
		return NEPositionIsRight(value) != 0;
	}

	static bool IsPositionLeft(NEPosition value)
	{
		return NEPositionIsLeft(value) != 0;
	}

	static bool IsPositionRightAndLeft(NEPosition value)
	{
		return NEPositionIsRightAndLeft(value) != 0;
	}

	static bool IsPositionOneOf(NEPosition value, NEPosition * arSupportedPositions, NInt supportedPositionCount)
	{
		NBool result;
		NCheck(NEPositionIsOneOf(value, arSupportedPositions, supportedPositionCount, &result));
		return result != 0;
	}

	static NInt GetPositionAvailableParts(NEPosition value, NEPosition * arMissingPositions, NInt missingPositionCount, NEPosition * arResults, NInt resultsLength = N_INT_MAX)
	{
		return NCheck(NEPositionGetAvailableParts(value, arMissingPositions, missingPositionCount, arResults, resultsLength));
	}

	static NEPosition * GetPositionAvailableParts(NEPosition value, NEPosition * arMissingPositions, NInt missingPositionCount, NInt * pCount)
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		NInt count = GetPositionAvailableParts(value, arMissingPositions, missingPositionCount, NULL, 0);
		auto_array<NEPosition> results(count);
		*pCount = GetPositionAvailableParts(value, arMissingPositions, missingPositionCount, results.get(), count);
		return results.release();
	}

	static NDouble AngleToRadians(NInt value)
	{
		return NBiometricAngleToRadians(value);
	}

	static NInt AngleFromRadians(NDouble value)
	{
		return NBiometricAngleFromRadians(value);
	}

	static N_CLASS(NString) AngleToString(NInt value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NBiometricAngleToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static bool IsQualityValid(NByte value)
	{
		return NBiometricQualityIsValid(value) != 0;
	}

	static N_CLASS(NString) QualityToString(NByte value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NBiometricQualityToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};

}}

#endif // !N_BIOMETRIC_TYPES_HPP_INCLUDED
