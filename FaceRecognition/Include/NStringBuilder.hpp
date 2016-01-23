#ifndef N_STRING_BUILDER_HPP_INCLUDED
#define N_STRING_BUILDER_HPP_INCLUDED

#include <NTypes.hpp>
namespace Neurotec { namespace Text { namespace Internal
{
#include <NStringBuilder.h>
}}}

namespace Neurotec { namespace Text
{

class N_CLASS(NStringBuilder) : private Internal::NStringBuilder
{
public:
	N_CLASS(NStringBuilder)()
	{
		NCheck(Internal::NStringBuilderInit(this));
	}

	N_CLASS(NStringBuilder)(NInt capacity)
	{
		NCheck(Internal::NStringBuilderInitWithCapacity(this, capacity));
	}

	N_CLASS(NStringBuilder)(NInt capacity, NInt maxCapacity, NInt growthDelta)
	{
		NCheck(Internal::NStringBuilderInitEx(this, capacity, maxCapacity, growthDelta));
	}

	N_CLASS(NStringBuilder)(const N_CLASS(NString) & value)
	{
		NCheck(Internal::NStringBuilderInitWithStringN(this, value.GetHandle()));
	}

	N_CLASS(NStringBuilder)(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(Internal::NStringBuilderInitWithStringN(this, value.GetHandle()));
	}

	N_CLASS(NStringBuilder)(const NChar * arValue, NInt valueLength = -1)
	{
		NCheck(Internal::NStringBuilderInitWithStrOrChars(this, arValue, valueLength));
	}

	~N_CLASS(NStringBuilder)()
	{
		NCheck(Internal::NStringBuilderDispose(this));
	}

	NInt GetCapacity()
	{
		NInt value;
		NCheck(Internal::NStringBuilderGetCapacity(this, &value));
		return value;
	}

	void SetCapacity(NInt value)
	{
		NCheck(Internal::NStringBuilderSetCapacity(this, value));
	}

	NInt GetLength()
	{
		NInt value;
		NCheck(Internal::NStringBuilderGetLength(this, &value));
		return value;
	}

	void SetLength(NInt value)
	{
		NCheck(Internal::NStringBuilderSetLength(this, value));
	}

	NChar GetChar(NInt index)
	{
		NChar value;
		NCheck(Internal::NStringBuilderGetChar(this, index, &value));
		return value;
	}

	void SetChar(NInt index, NChar value)
	{
		NCheck(Internal::NStringBuilderSetChar(this, index, value));
	}

	N_CLASS(NStringBuilder) & Append(bool value)
	{
		NCheck(Internal::NStringBuilderAppendBoolean(this, value ? NTrue : NFalse));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NFloat value)
	{
		NCheck(Internal::NStringBuilderAppendSingle(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NDouble value)
	{
		NCheck(Internal::NStringBuilderAppendDouble(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NSByte value)
	{
		NCheck(Internal::NStringBuilderAppendSByte(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NShort value)
	{
		NCheck(Internal::NStringBuilderAppendInt16(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NInt value)
	{
		NCheck(Internal::NStringBuilderAppendInt32(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NLong value)
	{
		NCheck(Internal::NStringBuilderAppendInt64(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NByte value)
	{
		NCheck(Internal::NStringBuilderAppendByte(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NUShort value)
	{
		NCheck(Internal::NStringBuilderAppendUInt16(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NUInt value)
	{
		NCheck(Internal::NStringBuilderAppendUInt32(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(NULong value)
	{
		NCheck(Internal::NStringBuilderAppendUInt64(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendSizeType(NSizeType value)
	{
		NCheck(Internal::NStringBuilderAppendSizeType(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendSSizeType(NSSizeType value)
	{
		NCheck(Internal::NStringBuilderAppendSSizeType(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(const void * value)
	{
		NCheck(Internal::NStringBuilderAppendPointer(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendResult(NResult value)
	{
		NCheck(Internal::NStringBuilderAppendResult(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(N_CLASS(NType) * pType, const void * pValue, NSizeType valueSize)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(Internal::NStringBuilderAppendValue(this, pType->GetHandle(), pValue, valueSize));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(N_CLASS(NObject) * pObject)
	{
		NCheck(Internal::NStringBuilderAppendObject(this, N_CLASS(NObject)::ToHandle(pObject)));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendChar(NChar value)
	{
		NCheck(Internal::NStringBuilderAppendChar(this, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendChar(NChar value, NInt repeatCount)
	{
		NCheck(Internal::NStringBuilderAppendCharRepeat(this, value, repeatCount));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(const NChar * arValue, NInt valueLength)
	{
		NCheck(Internal::NStringBuilderAppendChars(this, arValue, valueLength));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(const N_CLASS(NString) & value)
	{
		NCheck(Internal::NStringBuilderAppendN(this, value.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(Internal::NStringBuilderAppendN(this, value.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & Append(const NChar * szValue)
	{
		NCheck(Internal::NStringBuilderAppend(this, szValue));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendFormat(const N_CLASS(NString) & format, ...)
	{
		va_list args;
		va_start(args, format);
		try
		{
			AppendFormat(format, args);
			va_end(args);
			return *this;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	N_CLASS(NStringBuilder) & AppendFormat(const N_CLASS(NStringWrapper) & format, ...)
	{
		va_list args;
		va_start(args, format);
		try
		{
			AppendFormat(format, args);
			va_end(args);
			return *this;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	N_CLASS(NStringBuilder) & AppendFormat(const NChar * szFormat, ...)
	{
		va_list args;
		va_start(args, szFormat);
		try
		{
			AppendFormat(szFormat, args);
			va_end(args);
			return *this;
		}
		catch (...)
		{
			va_end(args);
			throw;
		}
	}

	N_CLASS(NStringBuilder) & AppendFormat(const N_CLASS(NString) & value, va_list args)
	{
		NCheck(Internal::NStringBuilderAppendFormatVAN(this, value.GetHandle(), args));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendFormat(const N_CLASS(NStringWrapper) & value, va_list args)
	{
		NCheck(Internal::NStringBuilderAppendFormatVAN(this, value.GetHandle(), args));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendFormat(const NChar * szValue, va_list args)
	{
		NCheck(Internal::NStringBuilderAppendFormatVA(this, szValue, args));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendLine()
	{
		NCheck(Internal::NStringBuilderAppendEmptyLine(this));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendLine(const N_CLASS(NString) & value)
	{
		NCheck(Internal::NStringBuilderAppendLineN(this, value.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendLine(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(Internal::NStringBuilderAppendLineN(this, value.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & AppendLine(const NChar * szValue)
	{
		NCheck(Internal::NStringBuilderAppendLine(this, szValue));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, bool value)
	{
		NCheck(Internal::NStringBuilderInsertBoolean(this, index, value ? NTrue : NFalse));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NFloat value)
	{
		NCheck(Internal::NStringBuilderInsertSingle(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NDouble value)
	{
		NCheck(Internal::NStringBuilderInsertDouble(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NSByte value)
	{
		NCheck(Internal::NStringBuilderInsertSByte(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NShort value)
	{
		NCheck(Internal::NStringBuilderInsertInt16(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NInt value)
	{
		NCheck(Internal::NStringBuilderInsertInt32(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NLong value)
	{
		NCheck(Internal::NStringBuilderInsertInt64(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NByte value)
	{
		NCheck(Internal::NStringBuilderInsertByte(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NUShort value)
	{
		NCheck(Internal::NStringBuilderInsertUInt16(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NUInt value)
	{
		NCheck(Internal::NStringBuilderInsertUInt32(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, NULong value)
	{
		NCheck(Internal::NStringBuilderInsertUInt64(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & InsertSizeType(NInt index, NSizeType value)
	{
		NCheck(Internal::NStringBuilderInsertSizeType(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & InsertSSizeType(NInt index, NSSizeType value)
	{
		NCheck(Internal::NStringBuilderInsertSSizeType(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, const void * value)
	{
		NCheck(Internal::NStringBuilderInsertPointer(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & InsertResult(NInt index, NResult value)
	{
		NCheck(Internal::NStringBuilderInsertResult(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, N_CLASS(NType) * pType, const void * pValue, NSizeType valueSize)
	{
		if (!pType) NThrowArgumentNullException(N_T("pType"));
		NCheck(Internal::NStringBuilderInsertValue(this, index, pType->GetHandle(), pValue, valueSize));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, N_CLASS(NObject) * pObject)
	{
		NCheck(Internal::NStringBuilderInsertObject(this, index, N_CLASS(NObject)::ToHandle(pObject)));
		return *this;
	}

	N_CLASS(NStringBuilder) & InsertChar(NInt index, NChar value)
	{
		NCheck(Internal::NStringBuilderInsertChar(this, index, value));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, const NChar * arValue, NInt valueLength)
	{
		NCheck(Internal::NStringBuilderInsertChars(this, index, arValue, valueLength));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, const N_CLASS(NString) & value)
	{
		NCheck(Internal::NStringBuilderInsertN(this, index, value.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, const N_CLASS(NStringWrapper) & value)
	{
		NCheck(Internal::NStringBuilderInsertN(this, index, value.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & Insert(NInt index, const NChar * szValue)
	{
		NCheck(Internal::NStringBuilderInsert(this, index, szValue));
		return *this;
	}

	N_CLASS(NStringBuilder) & Clear()
	{
		NCheck(Internal::NStringBuilderClear(this));
		return *this;
	}

	void CopyToStr(NInt sourceIndex, NChar * szValue, NInt valueSize, NInt count)
	{
		NCheck(Internal::NStringBuilderCopyToString(this, sourceIndex, szValue, valueSize, count));
	}

	void CopyTo(NInt sourceIndex, NChar * arValue, NInt valueLength, NInt count)
	{
		NCheck(Internal::NStringBuilderCopyTo(this, sourceIndex, arValue, valueLength, count));
	}

	N_CLASS(NStringBuilder) & Remove(NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderRemove(this, startIndex, count));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(NChar oldValue, NChar newValue)
	{
		NCheck(Internal::NStringBuilderReplace(this, oldValue, newValue));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(NChar oldValue, NChar newValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceInRange(this, oldValue, newValue, startIndex, count));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const N_CLASS(NString) & oldValue, const N_CLASS(NString) & newValue)
	{
		NCheck(Internal::NStringBuilderReplaceStringN(this, oldValue.GetHandle(), newValue.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const N_CLASS(NStringWrapper) & oldValue, const N_CLASS(NStringWrapper) & newValue)
	{
		NCheck(Internal::NStringBuilderReplaceStringN(this, oldValue.GetHandle(), newValue.GetHandle()));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const NChar * szOldValue, const NChar * szNewValue)
	{
		NCheck(Internal::NStringBuilderReplaceString(this, szOldValue, szNewValue));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const NChar * arOldValue, NInt oldValueLength, const NChar * arNewValue, NInt newValueLength)
	{
		NCheck(Internal::NStringBuilderReplaceChars(this, arOldValue, oldValueLength, arNewValue, newValueLength));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const N_CLASS(NString) & oldValue, const N_CLASS(NString) & newValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceStringInRangeN(this, oldValue.GetHandle(), newValue.GetHandle(), startIndex, count));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const N_CLASS(NStringWrapper) & oldValue, const N_CLASS(NStringWrapper) & newValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceStringInRangeN(this, oldValue.GetHandle(), newValue.GetHandle(), startIndex, count));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const NChar * szOldValue, const NChar * szNewValue, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceStringInRange(this, szOldValue, szNewValue, startIndex, count));
		return *this;
	}

	N_CLASS(NStringBuilder) & Replace(const NChar * arOldValue, NInt oldValueLength, const NChar * arNewValue, NInt newValueLength, NInt startIndex, NInt count)
	{
		NCheck(Internal::NStringBuilderReplaceCharsInRange(this, arOldValue, oldValueLength, arNewValue, newValueLength, startIndex, count));
		return *this;
	}

	N_CLASS(NString) ToString(NInt startIndex, NInt length)
	{
		HNString hValue;
		NCheck(Internal::NStringBuilderToStringRange(this, startIndex, length, &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	N_CLASS(NString) ToString()
	{
		HNString hValue;
		NCheck(Internal::NStringBuilderToString(this, &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	N_CLASS(NString) DetachStringN()
	{
		HNString hValue;
		NCheck(Internal::NStringBuilderDetachStringN(this, &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	NChar * GetBuffer(NInt * pLength = NULL)
	{
		NChar * szValue;
		NCheck(Internal::NStringBuilderGetBuffer(this, pLength, &szValue));
		return szValue;
	}

	NChar * GetCharsBuffer(NInt * pLength)
	{
		NChar * arValue;
		NCheck(Internal::NStringBuilderGetCharsBuffer(this, pLength, &arValue));
		return arValue;
	}

	NChar * DetachString(NInt * pLength = NULL)
	{
		NChar * szValue;
		NCheck(Internal::NStringBuilderDetachString(this, &szValue, pLength));
		return szValue;
	}

	NChar * DetachCharArray(NInt * pLength)
	{
		NChar * arValue;
		NCheck(Internal::NStringBuilderDetachCharArray(this, &arValue, pLength));
		return arValue;
	}

	NChar operator[](NInt index)
	{
		return GetChar(index);
	}

	friend class ::Neurotec::N_CLASS(NStringWrapper);
};

}}

namespace Neurotec
{

inline N_CLASS(NStringWrapper)::N_CLASS(NStringWrapper)(::Neurotec::Text::N_CLASS(NStringBuilder) & value)
	: header(), handle(NULL), ownsHandle(true)
{
	NCheck(::Neurotec::Text::Internal::NStringBuilderGetStringWrapper(&value, &header, &handle));
}

}

#endif // !N_STRING_BUILDER_HPP_INCLUDED
