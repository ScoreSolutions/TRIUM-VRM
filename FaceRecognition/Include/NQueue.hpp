#ifndef N_QUEUE_HPP_INCLUDED
#define N_QUEUE_HPP_INCLUDED

#include <NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <NQueue.h>
}}}

namespace Neurotec { namespace Collections
{

class N_CLASS(NQueue) : private Internal::NQueue
{
	N_DECLARE_PRIMITIVE_CLASS(NQueue)

public:
	explicit N_CLASS(NQueue)(NSizeType elementSize)
	{
		NCheck(Internal::NQueueInit(this, elementSize, NULL));
	}

	template<typename T> N_CLASS(NQueue)()
	{
		NCheck(Internal::NQueueInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType())));
	}

	N_CLASS(NQueue)(N_CLASS(NType) * pElementType)
	{
		NCheck(Internal::NQueueInit(this, 0, N_CLASS(NObject)::ToHandle(pElementType)));
	}

	N_CLASS(NQueue)(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NQueueInitP(this, 0, pElementTypeOf));
	}

	N_CLASS(NQueue)(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NQueueInitWithCapacity(this, elementSize, NULL, capacity));
	}

	template<typename T> N_CLASS(NQueue)(NInt capacity)
	{
		NCheck(Internal::NQueueInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity));
	}

	N_CLASS(NQueue)(N_CLASS(NType) * pElementType, NInt capacity)
	{
		NCheck(Internal::NQueueInitWithCapacity(this, 0, N_CLASS(NObject)::ToHandle(pElementType), capacity));
	}

	N_CLASS(NQueue)(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NQueueInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	N_CLASS(NQueue)(NSizeType elementSize, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitEx(this, elementSize, NULL, capacity, maxCapacity, growthDelta, alignment));
	}

	template<typename T> N_CLASS(NQueue)(NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitEx(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity, maxCapacity, growthDelta, alignment));
	}

	N_CLASS(NQueue)(N_CLASS(NType) * pElementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitEx(this, 0, N_CLASS(NObject)::ToHandle(pElementType), capacity, maxCapacity, growthDelta, alignment));
	}

	N_CLASS(NQueue)(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NQueueInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, alignment));
	}

	~N_CLASS(NQueue)()
	{
		NCheck(Internal::NQueueDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NQueueGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NQueueSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NQueueGetCount(this, &value));
		return value;
	}

	bool Contains(const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NQueueContains(this, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NBool result;
		NCheck(Internal::NQueueContains(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result != 0;
	}

	bool Contains(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NQueueContains(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NQueueContainsP(this, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetFront(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NQueueGetFront(this, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetFront()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NQueueGetFront(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetFront(N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NQueueGetFront(this, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetFront(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NQueueGetFrontP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Peek(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueuePeek(this, NULL, pValue, valueSize));
	}

	template<typename T> T Peek()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NCheck(Internal::NQueuePeek(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &value, sizeof(value)));
		try
		{
			return N_CLASS(NTypeTraits)<T>::FromNative(value);
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNative(value);
			throw;
		}
	}

	void Peek(N_CLASS(NType) * pValueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueuePeek(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Peek(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueuePeekP(this, pValueTypeOf, pValue, valueSize));
	}

	void Dequeue(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueDequeue(this, NULL, pValue, valueSize));
	}

	template<typename T> T Dequeue()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NCheck(Internal::NQueueDequeue(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &value, sizeof(value)));
		try
		{
			return N_CLASS(NTypeTraits)<T>::FromNative(value);
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNative(value);
			throw;
		}
	}

	void Dequeue(N_CLASS(NType) * pValueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueDequeue(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Dequeue(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueDequeueP(this, pValueTypeOf, pValue, valueSize));
	}

	void Enqueue(const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueEnqueue(this, NULL, pValue, valueSize));
	}

	template<typename T> void Enqueue(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NQueueEnqueue(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Enqueue(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueEnqueue(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Enqueue(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NQueueEnqueueP(this, pValueTypeOf, pValue, valueSize));
	}

	void Clear()
	{
		NCheck(Internal::NQueueClear(this));
	}

	NInt CopyTo(void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NQueueCopyTo(this, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt count = NCheck(Internal::NQueueCopyTo(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), arValues ? N_CLASS(NTypeTraits)<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(N_CLASS(NType) * pValueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NQueueCopyTo(this, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NQueueCopyToP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NQueueToArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * ToArray(NInt * pCount)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NQueueToArray(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &count));
		try
		{
			typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(pValues, count);
			pValues = NULL; count = 0;
			return values.ToArray(pCount);
		}
		catch (...)
		{
			N_CLASS(NTypeTraits)<T>::FreeNativeArray(pValues, count);
			throw;
		}
	}

	void * ToArray(N_CLASS(NType) * pValueType, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NQueueToArray(this, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NQueueToArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_QUEUE_HPP_INCLUDED
