#ifndef N_STACK_HPP_INCLUDED
#define N_STACK_HPP_INCLUDED

#include <NType.hpp>
namespace Neurotec { namespace Collections { namespace Internal
{
#include <NStack.h>
}}}

namespace Neurotec { namespace Collections
{

class N_CLASS(NStack) : private Internal::NStack
{
	N_DECLARE_PRIMITIVE_CLASS(NStack)

public:
	explicit N_CLASS(NStack)(NSizeType elementSize)
	{
		NCheck(Internal::NStackInit(this, elementSize, NULL));
	}

	template<typename T> N_CLASS(NStack)()
	{
		NCheck(Internal::NStackInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType())));
	}

	N_CLASS(NStack)(N_CLASS(NType) * pElementType)
	{
		NCheck(Internal::NStackInit(this, 0, N_CLASS(NObject)::ToHandle(pElementType)));
	}

	N_CLASS(NStack)(NTypeOfProc pElementTypeOf)
	{
		NCheck(Internal::NStackInitP(this, 0, pElementTypeOf));
	}

	N_CLASS(NStack)(NSizeType elementSize, NInt capacity)
	{
		NCheck(Internal::NStackInitWithCapacity(this, elementSize, NULL, capacity));
	}

	template<typename T> N_CLASS(NStack)(NInt capacity)
	{
		NCheck(Internal::NStackInit(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity));
	}

	N_CLASS(NStack)(N_CLASS(NType) * pElementType, NInt capacity)
	{
		NCheck(Internal::NStackInitWithCapacity(this, 0, N_CLASS(NObject)::ToHandle(pElementType), capacity));
	}

	N_CLASS(NStack)(NTypeOfProc pElementTypeOf, NInt capacity)
	{
		NCheck(Internal::NStackInitWithCapacityP(this, 0, pElementTypeOf, capacity));
	}

	N_CLASS(NStack)(NSizeType elementSize, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NStackInitEx(this, elementSize, NULL, capacity, maxCapacity, growthDelta, alignment));
	}

	template<typename T> N_CLASS(NStack)(NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NStackInitEx(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), capacity, maxCapacity, growthDelta, alignment));
	}

	N_CLASS(NStack)(N_CLASS(NType) * pElementType, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NStackInitEx(this, 0, N_CLASS(NObject)::ToHandle(pElementType), capacity, maxCapacity, growthDelta, alignment));
	}

	N_CLASS(NStack)(NTypeOfProc pElementTypeOf, NInt capacity, NInt maxCapacity, NInt growthDelta, NSizeType alignment)
	{
		NCheck(Internal::NStackInitExP(this, 0, pElementTypeOf, capacity, maxCapacity, growthDelta, alignment));
	}

	~N_CLASS(NStack)()
	{
		NCheck(Internal::NStackDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NStackGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NStackSetCapacity(this, value));
	}

	NInt GetCount()
	{
		NInt value;
		NCheck(Internal::NStackGetCount(this, &value));
		return value;
	}

	bool Contains(const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NStackContains(this, NULL, pValue, valueSize, &result));
		return result != 0;
	}

	template<typename T> bool Contains(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NBool result;
		NCheck(Internal::NStackContains(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v), &result));
		return result != 0;
	}

	bool Contains(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NStackContains(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize, &result));
		return result != 0;
	}

	bool Contains(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NBool result;
		NCheck(Internal::NStackContainsP(this, pValueTypeOf, pValue, valueSize, &result));
		return result != 0;
	}

	void * GetTop(NSizeType elementSize)
	{
		void * pValue;
		NCheck(Internal::NStackGetTop(this, elementSize, NULL, &pValue));
		return pValue;
	}

	template<typename T> typename N_CLASS(NTypeTraits)<T>::NativeType * GetTop()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType * pValue;
		NCheck(Internal::NStackGetTop(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), (void * *)&pValue));
		return pValue;
	}

	void * GetTop(N_CLASS(NType) * pElementType)
	{
		void * pValue;
		NCheck(Internal::NStackGetTop(this, 0, N_CLASS(NObject)::ToHandle(pElementType), &pValue));
		return pValue;
	}

	void * GetTop(NTypeOfProc pElementTypeOf)
	{
		void * pValue;
		NCheck(Internal::NStackGetTopP(this, 0, pElementTypeOf, &pValue));
		return pValue;
	}

	void Peek(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPeek(this, NULL, pValue, valueSize));
	}

	template<typename T> T Peek()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NCheck(Internal::NStackPeek(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &value, sizeof(value)));
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
		NCheck(Internal::NStackPeek(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Peek(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPeekP(this, pValueTypeOf, pValue, valueSize));
	}

	void Pop(void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPop(this, NULL, pValue, valueSize));
	}

	template<typename T> T Pop()
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType value;
		NCheck(Internal::NStackPop(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &value, sizeof(value)));
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

	void Pop(N_CLASS(NType) * pValueType, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPop(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Pop(NTypeOfProc pValueTypeOf, void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPopP(this, pValueTypeOf, pValue, valueSize));
	}

	void Push(const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPush(this, NULL, pValue, valueSize));
	}

	template<typename T> void Push(const T & value)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
		NCheck(Internal::NStackPush(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &v, sizeof(v)));
	}

	void Push(N_CLASS(NType) * pValueType, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPush(this, N_CLASS(NObject)::ToHandle(pValueType), pValue, valueSize));
	}

	void Push(NTypeOfProc pValueTypeOf, const void * pValue, NSizeType valueSize)
	{
		NCheck(Internal::NStackPushP(this, pValueTypeOf, pValue, valueSize));
	}

	void Clear()
	{
		NCheck(Internal::NStackClear(this));
	}

	NInt CopyTo(void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NStackCopyTo(this, NULL, pValues, valuesSize, valuesLength));
	}

	template<typename T> NInt CopyTo(T * arValues, NInt valuesLength)
	{
		typename N_CLASS(NTypeTraits)<T>::NativeArrayType values(arValues ? valuesLength : 0);
		NInt count = NCheck(Internal::NStackCopyTo(this, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), arValues ? N_CLASS(NTypeTraits)<T>::GetNativeArray(values, arValues) : NULL,
			(NSizeType)valuesLength * sizeof(N_CLASS(NTypeTraits)<T>::NativeType), valuesLength));
		return values.CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(N_CLASS(NType) * pValueType, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NStackCopyTo(this, N_CLASS(NObject)::ToHandle(pValueType), pValues, valuesSize, valuesLength));
	}

	NInt CopyTo(NTypeOfProc pValueTypeOf, void * pValues, NSizeType valuesSize, NInt valuesLength)
	{
		return NCheck(Internal::NStackCopyToP(this, pValueTypeOf, pValues, valuesSize, valuesLength));
	}

	void * ToArray(NSizeType elementSize, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NStackToArray(this, elementSize, NULL, &pValues, pCount));
		return pValues;
	}

	template<typename T> T * ToArray(NInt * pCount)
	{
		void * pValues;
		NInt count;
		NCheck(Internal::NStackToArray(this, 0, N_CLASS(NObject)::ToHandle(N_CLASS(NTypeTraits)<T>::GetNativeType()), &pValues, &count));
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
		NCheck(Internal::NStackToArray(this, 0, N_CLASS(NObject)::ToHandle(pValueType), &pValues, pCount));
		return pValues;
	}

	void * ToArray(NTypeOfProc pValueTypeOf, NInt * pCount)
	{
		void * pValues;
		NCheck(Internal::NStackToArrayP(this, 0, pValueTypeOf, &pValues, pCount));
		return pValues;
	}
};

}}

#endif // !N_STACK_HPP_INCLUDED
