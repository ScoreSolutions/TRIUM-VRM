#ifndef NF_RECORD_HPP_INCLUDED
#define NF_RECORD_HPP_INCLUDED

#include <NCore.hpp>
#include <NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NFRecord.h>
#include <NFRecordV1.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NFR_RESOLUTION
#undef NFR_MAX_FINGER_DIMENSION
#undef NFR_MAX_FINGER_MINUTIA_COUNT
#undef NFR_MAX_FINGER_CORE_COUNT
#undef NFR_MAX_FINGER_DELTA_COUNT
#undef NFR_MAX_FINGER_DOUBLE_CORE_COUNT
#undef NFR_MAX_PALM_DIMENSION
#undef NFR_MAX_PALM_MINUTIA_COUNT
#undef NFR_MAX_PALM_CORE_COUNT
#undef NFR_MAX_PALM_DELTA_COUNT
#undef NFR_MAX_PALM_DOUBLE_CORE_COUNT
#undef NFR_MAX_DIMENSION
#undef NFR_MAX_MINUTIA_COUNT
#undef NFR_MAX_CORE_COUNT
#undef NFR_MAX_DELTA_COUNT
#undef NFR_MAX_DOUBLE_CORE_COUNT
#undef NFR_MAX_POSSIBLE_POSITION_COUNT

#undef NFR_SKIP_RIDGE_COUNTS
#undef NFR_SKIP_SINGULAR_POINTS
#undef NFR_SKIP_BLOCKED_ORIENTS
#undef NFR_SAVE_BLOCKED_ORIENTS
#undef NFR_ALLOW_OUT_OF_BOUNDS_FEATURES
#undef NFR_SKIP_QUALITIES
#undef NFR_SKIP_CURVATURES
#undef NFR_SKIP_GS
#undef NFR_SAVE_V1
#undef NFR_SAVE_V2
#undef NFR_SAVE_V3

const NUShort NFR_RESOLUTION = 500;
const NUShort NFR_MAX_FINGER_DIMENSION = 2047;
const NInt NFR_MAX_FINGER_MINUTIA_COUNT = 255;
const NInt NFR_MAX_FINGER_CORE_COUNT = 15;
const NInt NFR_MAX_FINGER_DELTA_COUNT = 15;
const NInt NFR_MAX_FINGER_DOUBLE_CORE_COUNT = 15;
const NUShort NFR_MAX_PALM_DIMENSION = 16383;
const NInt NFR_MAX_PALM_MINUTIA_COUNT = 65535;
const NInt NFR_MAX_PALM_CORE_COUNT = 255;
const NInt NFR_MAX_PALM_DELTA_COUNT = 255;
const NInt NFR_MAX_PALM_DOUBLE_CORE_COUNT = 255;
const NInt NFR_MAX_POSSIBLE_POSITION_COUNT = 255;
const NUInt NFR_SKIP_RIDGE_COUNTS = 0x00010000;
const NUInt NFR_SKIP_SINGULAR_POINTS = 0x00020000;
const NUInt NFR_SKIP_BLOCKED_ORIENTS = 0x00040000;
const NUInt NFR_SAVE_BLOCKED_ORIENTS = 0x00040000;
const NUInt NFR_ALLOW_OUT_OF_BOUNDS_FEATURES = 0x00080000;
const NUInt NFR_SKIP_QUALITIES = 0x00100000;
const NUInt NFR_SKIP_CURVATURES = 0x00200000;
const NUInt NFR_SKIP_GS = 0x00400000;
const NUInt NFR_SAVE_V1 = 0x10000000;
const NUInt NFR_SAVE_V2 = 0x20000000;
const NUInt NFR_SAVE_V3 = 0x30000000;

class N_CLASS(NFRecord) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NFRecord, NObject)

public:
	class MinutiaCollection : public ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFMinutia), N_CLASS(NFRecord)>
	{
		MinutiaCollection(N_CLASS(NFRecord) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFMinutia), N_CLASS(NFRecord)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetMinutiaCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetMinutiaCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNFRecord handle, NInt value)
		{
			return NFRecordSetMinutiaCapacity(handle, value);
		}

		virtual NResult GetNative(HNFRecord handle, NInt index, N_CLASS(NFMinutia) * pValue) const
		{
			return NFRecordGetMinutia(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNFRecord handle, N_CLASS(NFMinutia) * arValues, NInt valuesLength) const
		{
			return NFRecordGetMinutiaeEx(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNFRecord handle, NInt index, const N_CLASS(NFMinutia) * pValue)
		{
			return NFRecordSetMinutia(handle, index, pValue);
		}

		virtual NResult AddNative(HNFRecord handle, const N_CLASS(NFMinutia) * pValue)
		{
			return NFRecordAddMinutia(handle, pValue);
		}

		virtual NResult AddWithOutIndexNative(HNFRecord, const N_CLASS(NFMinutia) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNFRecord handle, NInt index, const N_CLASS(NFMinutia) * pValue)
		{
			return NFRecordInsertMinutia(handle, index, pValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNFRecord, const N_CLASS(NFMinutia) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNFRecord handle, NInt index)
		{
			return NFRecordRemoveMinutia(handle, index);
		}

		virtual NResult RemoveRangeNative(HNFRecord, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNFRecord handle)
		{
			return NFRecordClearMinutiae(handle);
		}

		friend class N_CLASS(NFRecord);
	};

	class MinutiaNeighborsCollection : public ::Neurotec::Collections::N_CLASS(NStructArrayCollection)<N_CLASS(NFMinutiaNeighbor), N_CLASS(NFMinutia), N_CLASS(NFRecord)>
	{
		MinutiaNeighborsCollection(N_CLASS(NFRecord) * pOwner, MinutiaCollection * pMinutiaCollection)
			: ::Neurotec::Collections::N_CLASS(NStructArrayCollection)<N_CLASS(NFMinutiaNeighbor), N_CLASS(NFMinutia), N_CLASS(NFRecord)>(pOwner, pMinutiaCollection)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFRecord handle, NInt baseIndex, NInt * pValue) const
		{
			return NFRecordGetMinutiaNeighborCount(handle, baseIndex, pValue);
		}

		virtual NResult GetCapacityNative(HNFRecord, NInt, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNFRecord, NInt, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNFRecord handle, NInt baseIndex, NInt index, N_CLASS(NFMinutiaNeighbor) * pValue) const
		{
			return NFRecordGetMinutiaNeighbor(handle, baseIndex, index, pValue);
		}

		virtual NResult GetAllNative(HNFRecord handle, NInt baseIndex, N_CLASS(NFMinutiaNeighbor) * arValues, NInt valuesLength) const
		{
			return NFRecordGetMinutiaNeighborsEx(handle, baseIndex, arValues, valuesLength);
		}

		virtual NResult SetNative(HNFRecord handle, NInt baseIndex, NInt index, const N_CLASS(NFMinutiaNeighbor) * pValue)
		{
			return NFRecordSetMinutiaNeighbor(handle, baseIndex, index, pValue);
		}

		virtual NResult AddNative(HNFRecord, NInt, const N_CLASS(NFMinutiaNeighbor) *)
		{
			NThrowNotSupportedException();
		}

		virtual NResult AddWithOutIndexNative(HNFRecord, NInt, const N_CLASS(NFMinutiaNeighbor) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNFRecord, NInt, NInt, const N_CLASS(NFMinutiaNeighbor) *)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveWithOutIndexNative(HNFRecord, NInt, const N_CLASS(NFMinutiaNeighbor) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNFRecord, NInt, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult RemoveRangeNative(HNFRecord, NInt, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNFRecord, NInt)
		{
			NThrowNotSupportedException();
		}

		friend class N_CLASS(NFRecord);
	};

	class CoreCollection : public ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFCore), N_CLASS(NFRecord)>
	{
		CoreCollection(N_CLASS(NFRecord) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFCore), N_CLASS(NFRecord)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetCoreCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetCoreCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNFRecord handle, NInt value)
		{
			return NFRecordSetCoreCapacity(handle, value);
		}

		virtual NResult GetNative(HNFRecord handle, NInt index, N_CLASS(NFCore) * pValue) const
		{
			return NFRecordGetCore(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNFRecord handle, N_CLASS(NFCore) * arValues, NInt valuesLength) const
		{
			return NFRecordGetCoresEx(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNFRecord handle, NInt index, const N_CLASS(NFCore) * pValue)
		{
			return NFRecordSetCore(handle, index, pValue);
		}

		virtual NResult AddNative(HNFRecord handle, const N_CLASS(NFCore) * pValue)
		{
			return NFRecordAddCore(handle, pValue);
		}

		virtual NResult AddWithOutIndexNative(HNFRecord, const N_CLASS(NFCore) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNFRecord handle, NInt index, const N_CLASS(NFCore) * pValue)
		{
			return NFRecordInsertCore(handle, index, pValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNFRecord, const N_CLASS(NFCore) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNFRecord handle, NInt index)
		{
			return NFRecordRemoveCore(handle, index);
		}

		virtual NResult RemoveRangeNative(HNFRecord, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNFRecord handle)
		{
			return NFRecordClearCores(handle);
		}

		friend class N_CLASS(NFRecord);
	};

	class DeltaCollection : public ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFDelta), N_CLASS(NFRecord)>
	{
		DeltaCollection(N_CLASS(NFRecord) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFDelta), N_CLASS(NFRecord)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetDeltaCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetDeltaCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNFRecord handle, NInt value)
		{
			return NFRecordSetDeltaCapacity(handle, value);
		}

		virtual NResult GetNative(HNFRecord handle, NInt index, N_CLASS(NFDelta) * pValue) const
		{
			return NFRecordGetDelta(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNFRecord handle, N_CLASS(NFDelta) * arValues, NInt valuesLength) const
		{
			return NFRecordGetDeltasEx(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNFRecord handle, NInt index, const N_CLASS(NFDelta) * pValue)
		{
			return NFRecordSetDelta(handle, index, pValue);
		}

		virtual NResult AddNative(HNFRecord handle, const N_CLASS(NFDelta) * pValue)
		{
			return NFRecordAddDelta(handle, pValue);
		}

		virtual NResult AddWithOutIndexNative(HNFRecord, const N_CLASS(NFDelta) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNFRecord handle, NInt index, const N_CLASS(NFDelta) * pValue)
		{
			return NFRecordInsertDelta(handle, index, pValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNFRecord, const N_CLASS(NFDelta) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNFRecord handle, NInt index)
		{
			return NFRecordRemoveDelta(handle, index);
		}

		virtual NResult RemoveRangeNative(HNFRecord, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNFRecord handle)
		{
			return NFRecordClearDeltas(handle);
		}

		friend class N_CLASS(NFRecord);
	};

	class DoubleCoreCollection : public ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFDoubleCore), N_CLASS(NFRecord)>
	{
		DoubleCoreCollection(N_CLASS(NFRecord) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStructCollection)<N_CLASS(NFDoubleCore), N_CLASS(NFRecord)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetDoubleCoreCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetDoubleCoreCapacity(handle, pValue);
		}

		virtual NResult SetCapacityNative(HNFRecord handle, NInt value)
		{
			return NFRecordSetDoubleCoreCapacity(handle, value);
		}

		virtual NResult GetNative(HNFRecord handle, NInt index, N_CLASS(NFDoubleCore) * pValue) const
		{
			return NFRecordGetDoubleCore(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNFRecord handle, N_CLASS(NFDoubleCore) * arValues, NInt valuesLength) const
		{
			return NFRecordGetDoubleCoresEx(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNFRecord handle, NInt index, const N_CLASS(NFDoubleCore) * pValue)
		{
			return NFRecordSetDoubleCore(handle, index, pValue);
		}

		virtual NResult AddNative(HNFRecord handle, const N_CLASS(NFDoubleCore) * pValue)
		{
			return NFRecordAddDoubleCore(handle, pValue);
		}

		virtual NResult AddWithOutIndexNative(HNFRecord, const N_CLASS(NFDoubleCore) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNFRecord handle, NInt index, const N_CLASS(NFDoubleCore) * pValue)
		{
			return NFRecordInsertDoubleCore(handle, index, pValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNFRecord, const N_CLASS(NFDoubleCore) *, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNFRecord handle, NInt index)
		{
			return NFRecordRemoveDoubleCore(handle, index);
		}

		virtual NResult RemoveRangeNative(HNFRecord, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNFRecord handle)
		{
			return NFRecordClearDoubleCores(handle);
		}

		friend class N_CLASS(NFRecord);
	};

	class PossiblePositionCollection : public ::Neurotec::Collections::N_CLASS(NValueCollection)<NFPosition, N_CLASS(NFRecord)>
	{
		PossiblePositionCollection(N_CLASS(NFRecord) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NValueCollection)<NFPosition, N_CLASS(NFRecord)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNFRecord handle, NInt * pValue) const
		{
			return NFRecordGetPossiblePositionCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNFRecord, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNFRecord, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNFRecord handle, NInt index, NFPosition * pValue) const
		{
			return NFRecordGetPossiblePosition(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNFRecord handle, NFPosition * arValues, NInt valuesLength) const
		{
			return NFRecordGetPossiblePositions(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNFRecord handle, NInt index, NFPosition value)
		{
			return NFRecordSetPossiblePosition(handle, index, value);
		}

		virtual NResult AddNative(HNFRecord handle, NFPosition value)
		{
			return NFRecordAddPossiblePosition(handle, value);
		}

		virtual NResult AddWithOutIndexNative(HNFRecord, NFPosition, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult InsertNative(HNFRecord handle, NInt index, NFPosition value)
		{
			return NFRecordInsertPossiblePosition(handle, index, value);
		}

		virtual NResult RemoveWithOutIndexNative(HNFRecord, NFPosition, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNFRecord handle, NInt index)
		{
			return NFRecordRemovePossiblePosition(handle, index);
		}

		virtual NResult RemoveRangeNative(HNFRecord, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNFRecord handle)
		{
			return NFRecordClearPossiblePositions(handle);
		}

		friend class N_CLASS(NFRecord);
	};

private:
	static N_CLASS(NType) * NFMinutiaOrderNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NFMinutiaOrder), true, true);
	}

	static HNFRecord Create(bool isPalm, NUShort width, NUShort height,
		NUShort horzResolution, NUShort vertResolution, NUInt flags)
	{
		HNFRecord handle;
		NCheck(NFRecordCreateEx(isPalm, width, height, horzResolution, vertResolution, flags, &handle));
		return handle;
	}

	static HNFRecord Create(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags, NSizeType * pSize)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		HNFRecord handle;
		NCheck(NFRecordCreateFromMemoryN(pBuffer->GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HNFRecord Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HNFRecord handle;
		NCheck(NFRecordCreateFromMemory(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	::std::auto_ptr<MinutiaCollection> minutiae;
	::std::auto_ptr<MinutiaNeighborsCollection> minutiaeNeighbors;
	::std::auto_ptr<CoreCollection> cores;
	::std::auto_ptr<DeltaCollection> deltas;
	::std::auto_ptr<DoubleCoreCollection> doubleCores;
	::std::auto_ptr<PossiblePositionCollection> possiblePositions;

	N_CLASS(NFRecord)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	void Init()
	{
		minutiae.reset(new MinutiaCollection(this));
		minutiaeNeighbors.reset(new MinutiaNeighborsCollection(this, minutiae.get()));
		cores.reset(new CoreCollection(this));
		deltas.reset(new DeltaCollection(this));
		doubleCores.reset(new DoubleCoreCollection(this));
		possiblePositions.reset(new PossiblePositionCollection(this));
	}

public:
	using N_CLASS(NObject)::GetSize;

	static NSizeType GetSize(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NSizeType value;
		NCheck(NFRecordGetSizeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NSizeType GetSize(const void * pBuffer, NSizeType bufferSize)
	{
		NSizeType value;
		NCheck(NFRecordGetSizeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetWidth(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NFRecordGetWidthMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetWidth(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetWidthMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetHeight(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NFRecordGetHeightMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetHeight(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetHeightMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetHorzResolution(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NFRecordGetHorzResolutionMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetHorzResolution(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetHorzResolutionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetVertResolution(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NFRecordGetVertResolutionMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetVertResolution(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetVertResolutionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NFPosition GetPosition(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NFPosition value;
		NCheck(NFRecordGetPositionMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NFPosition GetPosition(const void * pBuffer, NSizeType bufferSize)
	{
		NFPosition value;
		NCheck(NFRecordGetPositionMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NFImpressionType GetImpressionType(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NFImpressionType value;
		NCheck(NFRecordGetImpressionTypeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NFImpressionType GetImpressionType(const void * pBuffer, NSizeType bufferSize)
	{
		NFImpressionType value;
		NCheck(NFRecordGetImpressionTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NFPatternClass GetPatternClass(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NFPatternClass value;
		NCheck(NFRecordGetPatternClassMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NFPatternClass GetPatternClass(const void * pBuffer, NSizeType bufferSize)
	{
		NFPatternClass value;
		NCheck(NFRecordGetPatternClassMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetQuality(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NByte value;
		NCheck(NFRecordGetQualityMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NByte GetQuality(const void * pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NFRecordGetQualityMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NByte GetG(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NByte value;
		NCheck(NFRecordGetGMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NByte GetG(const void * pBuffer, NSizeType bufferSize)
	{
		NByte value;
		NCheck(NFRecordGetGMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NUShort GetCbeffProductType(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NUShort value;
		NCheck(NFRecordGetCbeffProductTypeMemN(pBuffer->GetHandle(), &value));
		return value;
	}

	static NUShort GetCbeffProductType(const void * pBuffer, NSizeType bufferSize)
	{
		NUShort value;
		NCheck(NFRecordGetCbeffProductTypeMem(pBuffer, bufferSize, &value));
		return value;
	}

	static NSizeType GetMaxSize(NInt version, bool isPalm, NFMinutiaFormat minutiaFormat, NInt minutiaCount, NFRidgeCountsType ridgeCountsType,
		NInt coreCount, NInt deltaCount, NInt doubleCoreCount, NInt boWidth = 0, NInt boHeight = 0)
	{
		NSizeType value;
		NCheck(NFRecordGetMaxSize(version, isPalm ? NTrue : NFalse, minutiaFormat, minutiaCount, ridgeCountsType,
			coreCount, deltaCount, doubleCoreCount, boWidth, boHeight, &value));
		return value;
	}

	static NSizeType GetMaxSizeV1(NFMinutiaFormat minutiaFormat, NInt minutiaCount,
		NInt coreCount, NInt deltaCount, NInt doubleCoreCount, NInt boWidth = 0, NInt boHeight = 0)
	{
		return GetMaxSize(1, false, minutiaFormat, minutiaCount, nfrctNone, coreCount, deltaCount, doubleCoreCount, boWidth, boHeight);
	}

	static void Check(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer)
	{
		if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
		NCheck(NFRecordCheckN(pBuffer->GetHandle()));
	}

	static void Check(const void * pBuffer, NSizeType bufferSize)
	{
		NCheck(NFRecordCheck(pBuffer, bufferSize));
	}

	N_CLASS(NFRecord)(bool isPalm, NUShort width, NUShort height,
		NUShort horzResolution, NUShort vertResolution, NUInt flags = 0)
		: N_CLASS(NObject)(Create(isPalm, width, height, horzResolution, vertResolution, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFRecord);
		Init();
	}

	N_CLASS(NFRecord)(NUShort width, NUShort height,
		NUShort horzResolution, NUShort vertResolution, NUInt flags = 0)
		: N_CLASS(NObject)(Create(false, width, height, horzResolution, vertResolution, flags), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFRecord);
		Init();
	}

	explicit N_CLASS(NFRecord)(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFRecord);
		Init();
	}

	N_CLASS(NFRecord)(const void * pBuffer, NSizeType bufferSize, NUInt flags = 0, NSizeType * pSize = NULL)
		: N_CLASS(NObject)(Create(pBuffer, bufferSize, flags, pSize), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFRecord);
		Init();
	}

	void SortMinutiae(NFMinutiaOrder order)
	{
		NCheck(NFRecordSortMinutiae((HNFRecord)GetHandle(), order));
	}

	void TruncateMinutiae(NInt maxCount)
	{
		NCheck(NFRecordTruncateMinutiae((HNFRecord)GetHandle(), maxCount));
	}

	void TruncateMinutiaeByQuality(NByte threshold, NInt maxCount)
	{
		NCheck(NFRecordTruncateMinutiaeByQuality((HNFRecord)GetHandle(), threshold, maxCount));
	}

	NUShort GetWidth() const
	{
		NUShort value;
		NCheck(NFRecordGetWidth((HNFRecord)GetHandle(), &value));
		return value;
	}

	NUShort GetHeight() const
	{
		NUShort value;
		NCheck(NFRecordGetHeight((HNFRecord)GetHandle(), &value));
		return value;
	}

	NUShort GetHorzResolution() const
	{
		NUShort value;
		NCheck(NFRecordGetHorzResolution((HNFRecord)GetHandle(), &value));
		return value;
	}

	NUShort GetVertResolution() const
	{
		NUShort value;
		NCheck(NFRecordGetVertResolution((HNFRecord)GetHandle(), &value));
		return value;
	}

	NFPosition GetPosition() const
	{
		NFPosition value;
		NCheck(NFRecordGetPosition((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetPosition(NFPosition value)
	{
		NCheck(NFRecordSetPosition((HNFRecord)GetHandle(), value));
	}

	NFImpressionType GetImpressionType() const
	{
		NFImpressionType value;
		NCheck(NFRecordGetImpressionType((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetImpressionType(NFImpressionType value)
	{
		NCheck(NFRecordSetImpressionType((HNFRecord)GetHandle(), value));
	}

	NFPatternClass GetPatternClass() const
	{
		NFPatternClass value;
		NCheck(NFRecordGetPatternClass((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetPatternClass(NFPatternClass value)
	{
		NCheck(NFRecordSetPatternClass((HNFRecord)GetHandle(), value));
	}

	NByte GetQuality() const
	{
		NByte value;
		NCheck(NFRecordGetQuality((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetQuality(NByte value)
	{
		NCheck(NFRecordSetQuality((HNFRecord)GetHandle(), value));
	}

	NByte GetG() const
	{
		NByte value;
		NCheck(NFRecordGetG((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetG(NByte value)
	{
		NCheck(NFRecordSetG((HNFRecord)GetHandle(), value));
	}

	NUShort GetCbeffProductType() const
	{
		NUShort value;
		NCheck(NFRecordGetCbeffProductType((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetCbeffProductType(NUShort value)
	{
		NCheck(NFRecordSetCbeffProductType((HNFRecord)GetHandle(), value));
	}

	NFRidgeCountsType GetRidgeCountsType() const
	{
		NFRidgeCountsType value;
		NCheck(NFRecordGetRidgeCountsType((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetRidgeCountsType(NFRidgeCountsType value)
	{
		NCheck(NFRecordSetRidgeCountsType((HNFRecord)GetHandle(), value));
	}

	NFMinutiaFormat GetMinutiaFormat() const
	{
		NFMinutiaFormat value;
		NCheck(NFRecordGetMinutiaFormat((HNFRecord)GetHandle(), &value));
		return value;
	}

	void SetMinutiaFormat(NFMinutiaFormat value)
	{
		NCheck(NFRecordSetMinutiaFormat((HNFRecord)GetHandle(), value));
	}

	NSizeType GetSizeV1(NUInt flags = 0) const
	{
		return GetSize(NFR_SAVE_V1 | flags);
	}

	NSizeType SaveV1(void * pBuffer, NSizeType bufferSize, NUInt flags = 0) const
	{
		return SaveV1(pBuffer, bufferSize, NFR_SAVE_V1 | flags);
	}

	MinutiaCollection * GetMinutiae() const
	{
		return minutiae.get();
	}

	MinutiaNeighborsCollection * GetMinutiaeNeighbors() const
	{
		return minutiaeNeighbors.get();
	}

	CoreCollection * GetCores() const
	{
		return cores.get();
	}

	DeltaCollection * GetDeltas() const
	{
		return deltas.get();
	}

	DoubleCoreCollection * GetDoubleCores() const
	{
		return doubleCores.get();
	}

	PossiblePositionCollection * GetPossiblePositions() const
	{
		return possiblePositions.get();
	}
};

}}

#endif // !NF_RECORD_HPP_INCLUDED
