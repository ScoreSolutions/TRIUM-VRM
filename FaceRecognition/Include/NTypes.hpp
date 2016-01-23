#ifndef N_TYPES_HPP_INCLUDED
#define N_TYPES_HPP_INCLUDED

#include <stdarg.h>
namespace Neurotec
{
#include <NTypes.h>
}

#ifndef N_CPP
	#error Only C++ is supported.
#endif

#ifndef N_FRAMEWORK_NO_AUTO_DETECT
	// Try auto-detect the framework
	#if defined(_MFC_VER)
		#define N_FRAMEWORK_MFC
	#elif defined(wxMAJOR_VERSION)
		#define N_FRAMEWORK_WX
	#elif defined(QT_VERSION)
		#define N_FRAMEWORK_QT
	#else
	#endif
#endif

#include <NNoDeprecate.h>
#if defined(N_MSVC)
	#if _MSC_VER >= 1600
		#include <unordered_map>
		#include <unordered_set>
		#define N_HASH_MAP ::std::unordered_map
		#define N_HASH_SET ::std::unordered_set
		#define N_HASH_NAMESPACE_BEGIN namespace std {
		#define N_HASH_NAMESPACE_END }
	#elif _MSC_VER >= 1500
		#include <unordered_map>
		#include <unordered_set>
		#define N_HASH_MAP ::std::tr1::unordered_map
		#define N_HASH_SET ::std::tr1::unordered_set
		#define N_HASH_NAMESPACE_BEGIN namespace std { namespace tr1 {
		#define N_HASH_NAMESPACE_END } }
	#else
		#include <hash_map>
		#include <hash_set>
		#define N_HASH_MAP ::stdext::hash_map
		#define N_HASH_SET ::stdext::hash_set
		#define N_HASH_NAMESPACE_BEGIN namespace stdext {
		#define N_HASH_NAMESPACE_END }
	#endif
#elif defined(N_GCC)
	#if N_GCC_VERSION >= 40000
		#include <tr1/unordered_map>
		#include <tr1/unordered_set>
		#define N_HASH_MAP ::std::tr1::unordered_map
		#define N_HASH_SET ::std::tr1::unordered_set
		#define N_NEED_HASH
		#define N_HASH_NAMESPACE_BEGIN namespace std { namespace tr1 {
		#define N_HASH_NAMESPACE_END } }
	#else
		#include <ext/hash_map>
		#include <ext/hash_set>
		#define N_HASH_MAP ::__gnu_cxx::hash_map
		#define N_HASH_SET ::__gnu_cxx::hash_set
		#define N_NEED_HASH
		#define N_HASH_NAMESPACE_BEGIN namespace __gnu_cxx {
		#define N_HASH_NAMESPACE_END }
		N_HASH_NAMESPACE_BEGIN
			template<typename T> struct hash<const T *>
			{
				size_t operator()(const T * const & k) const
				{
					return (size_t)k;
				}
			};
			template<typename T> struct hash<T *>
			{
				size_t operator()(T * const & k) const
				{
					return (size_t)k;
				}
			};
		N_HASH_NAMESPACE_END
	#endif
#else
	#include <hash_map>
	#include <hash_set>
	#define N_HASH_MAP ::std::hash_map
	#define N_HASH_SET ::std::hash_set
#endif
#include <NReDeprecate.h>

#ifdef N_MSVC
	#define N_THROW(args) throw(...)
	#define N_THROW_NONE throw()
	#define N_THROW_ANY throw(...)
#else
	#define N_THROW(args) throw args
	#define N_THROW_NONE throw()
	#define N_THROW_ANY throw(...)
#endif

namespace Neurotec
{
#undef N_UINT8_MIN
#undef N_UINT8_MAX
#undef N_INT8_MIN
#undef N_INT8_MAX
#undef N_UINT16_MIN
#undef N_UINT16_MAX
#undef N_INT16_MIN
#undef N_INT16_MAX
#undef N_UINT32_MIN
#undef N_UINT32_MAX
#undef N_INT32_MIN
#undef N_INT32_MAX
#ifndef N_NO_INT_64
	#undef N_UINT64_MIN
	#undef N_UINT64_MAX
	#undef N_INT64_MIN
	#undef N_INT64_MAX
#endif
#undef N_BYTE_MIN
#undef N_BYTE_MAX
#undef N_SBYTE_MIN
#undef N_SBYTE_MAX
#undef N_USHORT_MIN
#undef N_USHORT_MAX
#undef N_SHORT_MIN
#undef N_SHORT_MAX
#undef N_UINT_MIN
#undef N_UINT_MAX
#undef N_INT_MIN
#undef N_INT_MAX
#ifndef N_NO_INT_64
	#undef N_ULONG_MIN
	#undef N_ULONG_MAX
	#undef N_LONG_MIN
	#undef N_LONG_MAX
#endif
#ifndef N_NO_FLOAT
	#undef N_SINGLE_MIN
	#undef N_SINGLE_MAX
	#undef N_SINGLE_EPSILON
	#undef N_DOUBLE_MIN
	#undef N_DOUBLE_MAX
	#undef N_DOUBLE_EPSILON
	#undef N_FLOAT_MIN
	#undef N_FLOAT_MAX
	#undef N_FLOAT_EPSILON
#endif
#undef NTrue
#undef NFalse
#ifndef N_NO_UNICODE
	#undef N_WCHAR_SIZE
#endif
#undef N_SIZE_TYPE_MIN
#undef N_SIZE_TYPE_MAX
#undef N_SSIZE_TYPE_MIN
#undef N_SSIZE_TYPE_MAX

#ifdef N_MSVC
	const NUInt8 N_UINT8_MIN = 0x00ui8;
	const NUInt8 N_UINT8_MAX = 0xFFui8;
	const NInt8 N_INT8_MIN = 0x80i8;
	const NInt8 N_INT8_MAX = 0x7Fi8;
	const NUInt16 N_UINT16_MIN = 0x0000ui16;
	const NUInt16 N_UINT16_MAX = 0xFFFFui16;
	const NInt16 N_INT16_MIN = 0x8000i16;
	const NInt16 N_INT16_MAX = 0x7FFFi16;
	const NUInt32 N_UINT32_MIN = 0x00000000ui32;
	const NUInt32 N_UINT32_MAX = 0xFFFFFFFFui32;
	const NInt32 N_INT32_MIN = 0x80000000i32;
	const NInt32 N_INT32_MAX = 0x7FFFFFFFi32;
#else
	const NUInt8 N_UINT8_MIN = ((NUInt8)0x00u);
	const NUInt8 N_UINT8_MAX = ((NUInt8)0xFFu);
	const NInt8 N_INT8_MIN = ((NInt8)0x80);
	const NInt8 N_INT8_MAX = ((NInt8)0x7F);
	const NUInt16 N_UINT16_MIN = ((NUInt16)0x0000u);
	const NUInt16 N_UINT16_MAX = ((NUInt16)0xFFFFu);
	const NInt16 N_INT16_MIN = ((NInt16)0x8000);
	const NInt16 N_INT16_MAX = ((NInt16)0x7FFF);
	const NUInt32 N_UINT32_MIN = 0x00000000u;
	const NUInt32 N_UINT32_MAX = 0xFFFFFFFFu;
	const NInt32 N_INT32_MIN = 0x80000000;
	const NInt32 N_INT32_MAX = 0x7FFFFFFF;
#endif

#ifndef N_NO_INT_64
	#ifdef N_MSVC
		const NUInt64 N_UINT64_MIN = 0x0000000000000000ui64;
		const NUInt64 N_UINT64_MAX = 0xFFFFFFFFFFFFFFFFui64;
		const NInt64 N_INT64_MIN = 0x8000000000000000i64;
		const NInt64 N_INT64_MAX = 0x7FFFFFFFFFFFFFFFi64;
	#else
		const NUInt64 N_UINT64_MIN = 0x0000000000000000ull;
		const NUInt64 N_UINT64_MAX = 0xFFFFFFFFFFFFFFFFull;
		const NInt64 N_INT64_MIN = 0x8000000000000000ll;
		const NInt64 N_INT64_MAX = 0x7FFFFFFFFFFFFFFFll;
	#endif
#endif

const NByte N_BYTE_MIN = N_UINT8_MIN;
const NByte N_BYTE_MAX = N_UINT8_MAX;
const NSByte N_SBYTE_MIN = N_INT8_MIN;
const NSByte N_SBYTE_MAX = N_INT8_MAX;
const NUShort N_USHORT_MIN = N_UINT16_MIN;
const NUShort N_USHORT_MAX = N_UINT16_MAX;
const NShort N_SHORT_MIN = N_INT16_MIN;
const NShort N_SHORT_MAX = N_INT16_MAX;
const NUInt N_UINT_MIN = N_UINT32_MIN;
const NUInt N_UINT_MAX = N_UINT32_MAX;
const NInt N_INT_MIN = N_INT32_MIN;
const NInt N_INT_MAX = N_INT32_MAX;

#ifndef N_NO_INT_64
	const NULong N_ULONG_MIN = N_UINT64_MIN;
	const NULong N_ULONG_MAX = N_UINT64_MAX;
	const NLong N_LONG_MIN = N_INT64_MIN;
	const NLong N_LONG_MAX = N_INT64_MAX;
#endif

#ifndef N_NO_FLOAT
	const NSingle N_SINGLE_MIN = -3.402823466e+38F;
	const NSingle N_SINGLE_MAX = 3.402823466e+38F;
	const NSingle N_SINGLE_EPSILON = 1.192092896e-07F;
	const NDouble N_DOUBLE_MIN = -1.7976931348623158e+308;
	const NDouble N_DOUBLE_MAX = 1.7976931348623158e+308;
	const NDouble N_DOUBLE_EPSILON = 2.2204460492503131e-016;

	const NFloat N_FLOAT_MIN = N_SINGLE_MIN;
	const NFloat N_FLOAT_MAX = N_SINGLE_MAX;
	const NFloat N_FLOAT_EPSILON = N_SINGLE_EPSILON;
#endif

const NBool NTrue = 1;
const NBool NFalse = 0;

#ifndef N_NO_UNICODE
	#if defined(N_WINDOWS) || (defined(__SIZEOF_WCHAR_T__) && __SIZEOF_WCHAR_T__ == 2)
		#define N_WCHAR_SIZE 2
	#else // !defined(N_WINDOWS) && (!defined(__SIZEOF_WCHAR_T__) || __SIZEOF_WCHAR_T__ != 2)
		#define N_WCHAR_SIZE 4
	#endif // !defined(N_WINDOWS) && (!defined(__SIZEOF_WCHAR_T__) || __SIZEOF_WCHAR_T__ != 2)
#endif // !N_NO_UNICODE

#ifdef N_64
	const NSizeType N_SIZE_TYPE_MIN = N_UINT64_MIN;
	const NSizeType N_SIZE_TYPE_MAX = N_UINT64_MAX;
	const NSSizeType N_SSIZE_TYPE_MIN = N_INT64_MIN;
	const NSSizeType N_SSIZE_TYPE_MAX = N_INT64_MAX;
#else
	const NSizeType N_SIZE_TYPE_MIN = N_UINT32_MIN;
	const NSizeType N_SIZE_TYPE_MAX = N_UINT32_MAX;
	const NSSizeType N_SSIZE_TYPE_MIN = N_INT32_MIN;
	const NSSizeType N_SSIZE_TYPE_MAX = N_INT32_MAX;
#endif
}

// Define various types
#if defined(N_FRAMEWORK_MFC)
	#include <NNoDeprecate.h>
	#include <afx.h>
	#include <NReDeprecate.h>

	#define N_CLASS_(name) C##name
#elif defined(N_FRAMEWORK_WX)
	#include <NNoDeprecate.h>
	#include <memory>
	#include <wx/string.h>
	#include <wx/object.h>
	#include <NReDeprecate.h>

	#define N_CLASS_(name) wx##name
#elif defined(N_FRAMEWORK_QT)
	#include <NNoDeprecate.h>
	#include <memory>
	#include <QString>
	#include <QObject>
	#include <NReDeprecate.h>

	#define N_CLASS_(name) Q##name
#else
	#define N_FRAMEWORK_NATIVE

	#include <NNoDeprecate.h>
	#include <memory>
	#include <string>
	#include <NReDeprecate.h>

	#define N_CLASS_(name) name
#endif

#define N_CLASS(name) N_CLASS_(name)

#ifndef N_FRAMEWORK_NATIVE
	#define N_TYPEDEF_TYPE(name) typedef N_CLASS(name) name;
#else
	#define N_TYPEDEF_TYPE(name)
#endif

#define N_DECLARE_NON_COPYABLE(name) \
	private:\
		N_CLASS(name)(const N_CLASS(name) &);\
		N_CLASS(name) & operator=(const N_CLASS(name) &);

#define N_NATIVE_TYPE_OF(name) (N_CLASS(name)::NativeTypeOf())

#define N_DECLARE_TYPE_CLASS(name) \
	public:\
		static ::Neurotec::N_CLASS(NType) * NativeTypeOf()\
		{\
			return ::Neurotec::N_CLASS(NObject)::GetObject< ::Neurotec::N_CLASS(NType)>(N_TYPE_OF(name), true, true);\
		}
#define N_DECLARE_PRIMITIVE_CLASS(name) \
	N_DECLARE_NON_COPYABLE(name)
#define N_DECLARE_BASIC_CLASS_EX(name, fieldAccess) \
	N_DECLARE_TYPE_CLASS(name)\
fieldAccess:\
	name##_ value;\
public:\
	N_CLASS(name)(const N_CLASS(name) & other)\
		: value(other.value)\
	{\
	}\
	N_CLASS(name) & operator=(const N_CLASS(name) & other)\
	{\
		this->value = other.value;\
		return *this;\
	}\
	explicit N_CLASS(name)(name##_ value)\
		: value(value)\
	{\
	}\
	N_CLASS(name)()\
	{\
	}\
	bool operator==(const N_CLASS(name) & value) const\
	{\
		return this->value == value.value;\
	}\
	bool operator!=(const N_CLASS(name) & value) const\
	{\
		return this->value != value.value;\
	}\
public:\
	typedef name##_ NativeType;\
	name##_ GetValue() const\
	{\
		return value;\
	}
#define N_DECLARE_COMPARABLE_BASIC_CLASS_EX(name, fieldAccess) \
	N_DECLARE_BASIC_CLASS_EX(name, fieldAccess)\
public:\
	bool operator>(const N_CLASS(name) & value) const\
	{\
		return this->value > value.value;\
	}\
	bool operator<(const N_CLASS(name) & value) const\
	{\
		return this->value < value.value;\
	}\
	bool operator>=(const N_CLASS(name) & value) const\
	{\
		return this->value > value.value;\
	}\
	bool operator<=(const N_CLASS(name) & value) const\
	{\
		return this->value < value.value;\
	}
#define N_DECLARE_BASIC_CLASS(name) N_DECLARE_BASIC_CLASS_EX(name, private)
#define N_DECLARE_COMPARABLE_BASIC_CLASS(name) N_DECLARE_COMPARABLE_BASIC_CLASS_EX(name, private)
#define N_DECLARE_BASIC_CLASS_BASE(name) N_DECLARE_BASIC_CLASS_EX(name, protected)
#define N_DECLARE_COMPARABLE_BASIC_CLASS_BASE(name) N_DECLARE_COMPARABLE_BASIC_CLASS_EX(name, protected)
#define N_DECLARE_BASIC_CLASS_DERIVED(name, baseName) \
	N_DECLARE_TYPE_CLASS(name)\
public:\
	N_CLASS(name)(const N_CLASS(name) & other)\
		: baseName(other)\
	{\
	}\
	N_CLASS(name) & operator=(const N_CLASS(name) & other)\
	{\
		return (N_CLASS(name) &)baseName::operator=(other);\
	}\
	explicit N_CLASS(name)(name##_ value)\
		: baseName(value)\
	{\
	}\
	N_CLASS(name)()\
	{\
	}\
	operator baseName() const\
	{\
		return baseName(value);\
	}\
	bool operator==(const N_CLASS(name) & value) const\
	{\
		return baseName::operator==(value);\
	}\
	bool operator!=(const N_CLASS(name) & value) const\
	{\
		return baseName::operator!=(value);\
	}
#define N_DECLARE_COMPARABLE_BASIC_CLASS_DERIVED(name) \
	N_DECLARE_BASIC_CLASS_DERIVED(name)\
public:\
	bool operator>(const N_CLASS(name) & value) const\
	{\
		return baseName::operator>(value);\
	}\
	bool operator<(const N_CLASS(name) & value) const\
	{\
		return baseName::operator<(value);\
	}\
	bool operator>=(const N_CLASS(name) & value) const\
	{\
		return baseName::operator>=(value);\
	}\
	bool operator<=(const N_CLASS(name) & value) const\
	{\
		return baseName::operator<=(value);\
	}
#define N_DECLARE_STRUCT_CLASS(name) \
	N_DECLARE_TYPE_CLASS(name)\
public:\
	typedef struct name##_ NativeType;\
	N_CLASS(name)()\
	{\
	}\
	N_CLASS(name)(const struct name##_ & value)\
	{\
		memcpy(this, &value, sizeof(value));\
	}\
	N_CLASS(name) & operator=(const struct name##_ & value)\
	{\
		memcpy(this, &value, sizeof(value));\
		return *this;\
	}\
	operator name##_() const\
	{\
		return *static_cast<const name##_ *>(this);\
	}
#define N_DECLARE_DISPOSABLE_STRUCT_CLASS(name) \
	N_DECLARE_TYPE_CLASS(name)\
public:\
	typedef struct name##_ NativeType;\
	N_CLASS(name)()\
	{\
		memset(this, 0, sizeof(*this));\
	}\
	N_CLASS(name)(const N_CLASS(name) & other)\
	{\
		NCheck(name##Copy(&other, this));\
	}\
	~N_CLASS(name)()\
	{\
		NCheck(name##Dispose(this));\
	}\
	N_CLASS(name) & operator=(const N_CLASS(name) & other)\
	{\
		NCheck(name##Set(&other, this));\
		return *this;\
	}

namespace Neurotec
{

class N_CLASS(NObject);
class N_CLASS(NModule);
class N_CLASS(NType);
class N_CLASS(NValue);
class N_CLASS(NArray);
class N_CLASS(NString);
class N_CLASS(NStringWrapper);
namespace Text
{
class N_CLASS(NStringBuilder);
}
class N_CLASS(NException);
namespace IO
{
class N_CLASS(NBuffer);
class N_CLASS(NStream);
}
NInt NCheck(NResult result);
void N_NO_RETURN NThrowArgumentOutOfRangeException(const N_CLASS(NStringWrapper) & paramName);
void N_NO_RETURN NThrowArgumentException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL);
void N_NO_RETURN NThrowArgumentException(const N_CLASS(NStringWrapper) & message, const N_CLASS(NStringWrapper) & paramName, N_CLASS(NException) * pInnerException = NULL);
void N_NO_RETURN NThrowArgumentInsufficientException(const N_CLASS(NStringWrapper) & paramName);
void N_NO_RETURN NThrowArgumentNullException(const N_CLASS(NStringWrapper) & paramName);
void N_NO_RETURN NThrowArgumentElementNullException(const N_CLASS(NStringWrapper) & paramName);
void N_NO_RETURN NThrowArgumentLessThanZeroException(const N_CLASS(NStringWrapper) & paramName);
void N_NO_RETURN NThrowArgumentLessThanMinusOneException(const N_CLASS(NStringWrapper) & paramName);
void N_NO_RETURN NThrowOverflowException();
void N_NO_RETURN NThrowInvalidOperationException(const N_CLASS(NStringWrapper) & message, N_CLASS(NException) * pInnerException = NULL);
void N_NO_RETURN NThrowNotImplementedException();
void N_NO_RETURN NThrowNullReferenceException();

template<typename T, typename TNative> class N_CLASS(NDummyArray);
template<typename T> struct N_CLASS(NTypeTraits)
{
	typedef T NativeType;
	static N_CLASS(NType) * GetNativeType() { return T::NativeTypeOf(); }
	static const NUShort TypeId = 0;
	static NativeType ToNative(const T & value) { return value; }
	static T FromNative(NativeType value) { return value; }
	static void FreeNative(NativeType value) { N_UNREFERENCED_PARAMETER(value); }
	typedef N_CLASS(NDummyArray)<T, T> NativeArrayType;
	T * GetNativeArray(N_CLASS(NDummyArray)<T, T> &, T * arValues) { return arValues; }
	void FreeNativeArray(T * arValues, NInt) { NFree(arValues); }
};

}

#include <NString.hpp>
#include <NCallback.hpp>

namespace Neurotec
{

#undef NCharTypeOf
inline NResult N_API NCharTypeOf(HNType * phValue)
{
#ifdef N_UNICODE
	return NWCharTypeOf(phValue);
#else
	return NACharTypeOf(phValue);
#endif
}

class N_CLASS(NTypes)
{
public:
	struct CallbackParam
	{
		void * pCallback;
		void * pParam;

		CallbackParam(void * pCallback, void * pParam)
			: pCallback(pCallback), pParam(pParam)
		{
		}

		operator size_t() const
		{
			return (size_t)pCallback ^ (size_t)pParam;
		}

		bool operator==(const CallbackParam & other) const
		{
			return this->pCallback == other.pCallback && this->pParam == other.pParam;
		}
	};

private:
	static NResult N_API OnCallbackFree(void * ptr, void *);
	static NResult N_API OnCallbackGetHashCode(void * ptr, NInt * pValue, void *);
	static NResult N_API OnCallbackEquals(void * ptr, void * otherPtr, NBool * pResult, void *);
	static NResult N_API PointerFreeProcImpl(void * ptr, void * pParam);
	static NResult N_API PointerGetHashCodeImpl(void * ptr, NInt * pValue, void * pParam);
	static NResult N_API PointerEqualsImpl(void * ptr, void * otherPtr, NBool * pResult, void * pParam);

	N_CLASS(NTypes)();
	N_CLASS(NTypes) & operator=(const N_CLASS(NTypes) &);

public:
	typedef void (* PointerFreeProc)(const void * ptr, void * pParam);
	typedef NInt (* PointerGetHashCodeProc)(void * ptr, void * pParam);
	typedef bool (* PointerEqualsProc)(void * ptr, void * otherPtr, void * pParam);

	template<typename TNative, typename T> static N_CLASS(NCallback) CreateCallback(TNative pNativeCallback, T pCallback, void * pParam)
	{
		if (!pCallback)
		{
			if (!pParam) NThrowArgumentNullException(N_T("pCallback"));
			return N_CLASS(NCallback)();
		}
		::std::auto_ptr<CallbackParam> p(new CallbackParam(reinterpret_cast<void *>(pCallback), pParam));
		N_CLASS(NCallback) callback(pNativeCallback, p.get(), OnCallbackFree, OnCallbackGetHashCode, OnCallbackEquals);
		p.release();
		return callback;
	}

	static N_CLASS(NType) * NUInt8NativeTypeOf();
	static N_CLASS(NType) * NInt8NativeTypeOf();
	static N_CLASS(NType) * NUInt16NativeTypeOf();
	static N_CLASS(NType) * NInt16NativeTypeOf();
	static N_CLASS(NType) * NUInt32NativeTypeOf();
	static N_CLASS(NType) * NInt32NativeTypeOf();
	static N_CLASS(NType) * NUInt64NativeTypeOf();
	static N_CLASS(NType) * NInt64NativeTypeOf();
	static N_CLASS(NType) * NSingleNativeTypeOf();
	static N_CLASS(NType) * NDoubleNativeTypeOf();
	static N_CLASS(NType) * NBooleanNativeTypeOf();
	static N_CLASS(NType) * NSizeTypeNativeTypeOf();
	static N_CLASS(NType) * NSSizeTypeNativeTypeOf();
	static N_CLASS(NType) * NPointerNativeTypeOf();
	static N_CLASS(NType) * NResultNativeTypeOf();
	static N_CLASS(NType) * NACharNativeTypeOf();
#ifndef N_NO_UNICODE
	static N_CLASS(NType) * NWCharNativeTypeOf();
#endif
	static N_CLASS(NType) * NCharNativeTypeOf();
	static N_CLASS(NType) * NStringNativeTypeOf();
	static N_CLASS(NType) * NMemoryTypeNativeTypeOf();
	static N_CLASS(NType) * NAttributesNativeTypeOf();
	static N_CLASS(NType) * NOSFamilyNativeTypeOf();
	static N_CLASS(NType) * NativeTypeOf();

#ifndef N_NO_FLOAT
	static NSingle GetSinglePositiveInfinity() { return NSingleGetPositiveInfinity(); }
	static NSingle GetSingleNegativeInfinity() { return NSingleGetNegativeInfinity(); }
	static NSingle GetSingleNaN() { return NSingleGetNaN(); }
	static bool IsSingleInfinity(NSingle value) { return NSingleIsInfinity(value) != 0; }
	static bool IsSingleNegativeInfinity(NSingle value) { return NSingleIsNegativeInfinity(value) != 0; }
	static bool IsSinglePositiveInfinity(NSingle value) { return NSingleIsPositiveInfinity(value) != 0; }
	static bool IsSingleNaN(NSingle value) { return NSingleIsNaN(value) != 0; }
	static NDouble GetDoublePositiveInfinity() { return NDoubleGetPositiveInfinity(); }
	static NDouble GetDoubleNegativeInfinity() { return NDoubleGetNegativeInfinity(); }
	static NDouble GetDoubleNaN() { return NDoubleGetNaN(); }
	static bool IsDoubleInfinity(NDouble value) { return NDoubleIsInfinity(value) != 0; }
	static bool IsDoubleNegativeInfinity(NDouble value) { return NDoubleIsNegativeInfinity(value) != 0; }
	static bool IsDoublePositiveInfinity(NDouble value) { return NDoubleIsPositiveInfinity(value) != 0; }
	static bool IsDoubleNaN(NDouble value) { return NDoubleIsNaN(value) != 0; }
#endif // !N_NO_FLOAT

	static NChar CharFromDigit(NInt value) { return NCharFromDigit(value); }
	static NChar CharFromHexDigit(NInt value, bool lowercase = false) { return NCharFromHexDigit(value, lowercase); }
	static NChar CharFromOctDigit(NInt value) { return NCharFromOctDigit(value); }
	static NChar CharFromBinDigit(NInt value) { return NCharFromBinDigit(value); }

	static NInt CharToChars(NChar value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NCharToChars(value, szFormat, arValue, valueLength)); }
	static NInt UInt8ToChars(NUInt8 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt8ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int8ToChars(NInt8 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt8ToChars(value, szFormat, arValue, valueLength)); }
	static NInt UInt16ToChars(NUInt16 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt16ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int16ToChars(NInt16 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt16ToChars(value, szFormat, arValue, valueLength)); }
	static NInt UInt32ToChars(NUInt32 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt32ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int32ToChars(NInt32 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt32ToChars(value, szFormat, arValue, valueLength)); }
#ifndef N_NO_INT_64
	static NInt UInt64ToChars(NUInt64 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NUInt64ToChars(value, szFormat, arValue, valueLength)); }
	static NInt Int64ToChars(NInt64 value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NInt64ToChars(value, szFormat, arValue, valueLength)); }
#endif // !N_NO_INT_64
	static NInt SizeTypeToChars(NSizeType value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NSizeTypeToChars(value, szFormat, arValue, valueLength)); }
	static NInt SSizeTypeToChars(NSSizeType value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NSSizeTypeToChars(value, szFormat, arValue, valueLength)); }
	static NInt PointerToChars(const void * value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NPointerToChars(value, szFormat, arValue, valueLength)); }
#ifndef N_NO_FLOAT
	static NInt SingleToChars(NSingle value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NSingleToChars(value, szFormat, arValue, valueLength)); }
	static NInt DoubleToChars(NDouble value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NDoubleToChars(value, szFormat, arValue, valueLength)); }
#endif // !N_NO_FLOAT
	static NInt BooleanToChars(NBoolean value, const NChar * szFormat, NChar * arValue, NInt valueLength) { return NCheck(NBooleanToChars(value, szFormat, arValue, valueLength)); }

	static N_CLASS(NString) CharToString(NChar value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NCharToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) UInt8ToString(NUInt8 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NUInt8ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) Int8ToString(NInt8 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NInt8ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) UInt16ToString(NUInt16 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NUInt16ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) Int16ToString(NInt16 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NInt16ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) UInt32ToString(NUInt32 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NUInt32ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) Int32ToString(NInt32 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NInt32ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

#ifndef N_NO_INT_64
	static N_CLASS(NString) UInt64ToString(NUInt64 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NUInt64ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) Int64ToString(NInt64 value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NInt64ToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
#endif // !N_NO_INT_64

	static N_CLASS(NString) SizeTypeToString(NSizeType value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NSizeTypeToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) SSizeTypeToString(NSSizeType value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NSSizeTypeToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) PointerToString(const void * value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NPointerToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

#ifndef N_NO_FLOAT
	static N_CLASS(NString) SingleToString(NSingle value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NSingleToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static N_CLASS(NString) DoubleToString(NDouble value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NDoubleToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
#endif // !N_NO_FLOAT

	static N_CLASS(NString) BooleanToString(NBoolean value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		HNString hValue;
		NCheck(NBooleanToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static bool CharIsWhiteSpace(NChar value) { return NCharIsWhiteSpace(value) != 0; }
	static bool CharIsAscii(NChar value) { return NCharIsAscii(value) != 0; }
	static bool CharIsLetter(NChar value) { return NCharIsLetter(value) != 0; }
	static bool CharIsLower(NChar value) { return NCharIsLower(value) != 0; }
	static bool CharIsUpper(NChar value) { return NCharIsUpper(value) != 0; }
	static bool CharIsDigit(NChar value) { return NCharIsDigit(value) != 0; }
	static bool CharIsHexDigit(NChar value) { return NCharIsHexDigit(value) != 0; }
	static bool CharIsOctDigit(NChar value) { return NCharIsOctDigit(value) != 0; }
	static bool CharIsBinDigit(NChar value) { return NCharIsBinDigit(value) != 0; }
	static NChar CharToLower(NChar value) { return NCharToLower(value); }
	static NChar CharToUpper(NChar value) { return NCharToUpper(value); }
	static NInt CharToDigit(NChar value) { return NCharToDigit(value); }
	static NInt CharToHexDigit(NChar value) { return NCharToHexDigit(value); }
	static NInt CharToOctDigit(NChar value) { return NCharToOctDigit(value); }
	static NInt CharToBinDigit(NChar value) { return NCharToBinDigit(value); }

	static bool CharTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NChar * pValue)
	{
		NBool result;
		NCheck(NCharTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool UInt8TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt8 * pValue)
	{
		NBool result;
		NCheck(NUInt8TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int8TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt8 * pValue)
	{
		NBool result;
		NCheck(NInt8TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool UInt16TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt16 * pValue)
	{
		NBool result;
		NCheck(NUInt16TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int16TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt16 * pValue)
	{
		NBool result;
		NCheck(NInt16TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool UInt32TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt32 * pValue)
	{
		NBool result;
		NCheck(NUInt32TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int32TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt32 * pValue)
	{
		NBool result;
		NCheck(NInt32TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

#ifndef N_NO_INT_64
	static bool UInt64TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NUInt64 * pValue)
	{
		NBool result;
		NCheck(NUInt64TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool Int64TryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NInt64 * pValue)
	{
		NBool result;
		NCheck(NInt64TryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}
#endif // !N_NO_INT_64

	static bool SizeTypeTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSizeType * pValue)
	{
		NBool result;
		NCheck(NSizeTypeTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool SSizeTypeTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSSizeType * pValue)
	{
		NBool result;
		NCheck(NSSizeTypeTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool PointerTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, void * * pValue)
	{
		NBool result;
		NCheck(NPointerTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

#ifndef N_NO_FLOAT
	static bool SingleTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NSingle * pValue)
	{
		NBool result;
		NCheck(NSingleTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool DoubleTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NDouble * pValue)
	{
		NBool result;
		NCheck(NDoubleTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}
#endif // !N_NO_FLOAT

	static bool BooleanTryParse(const NChar * arValue, NInt valueLength, const NChar * szFormat, NBoolean * pValue)
	{
		NBool result;
		NCheck(NBooleanTryParseStrOrChars(arValue, valueLength, szFormat, pValue, &result));
		return result != 0;
	}

	static bool CharTryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NChar * pValue)
	{
		NBool result;
		NCheck(NCharTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool CharTryParse(const N_CLASS(NStringWrapper) & value, NChar * pValue) { return CharTryParse(value, N_CLASS(NString)(), pValue); }

	static bool UInt8TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NUInt8 * pValue)
	{
		NBool result;
		NCheck(NUInt8TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt8TryParse(const N_CLASS(NStringWrapper) & value, NUInt8 * pValue) { return UInt8TryParse(value, N_CLASS(NString)(), pValue); }

	static bool Int8TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NInt8 * pValue)
	{
		NBool result;
		NCheck(NInt8TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int8TryParse(const N_CLASS(NStringWrapper) & value, NInt8 * pValue) { return Int8TryParse(value, N_CLASS(NString)(), pValue); }

	static bool UInt16TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NUInt16 * pValue)
	{
		NBool result;
		NCheck(NUInt16TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt16TryParse(const N_CLASS(NStringWrapper) & value, NUInt16 * pValue) { return UInt16TryParse(value, N_CLASS(NString)(), pValue); }

	static bool Int16TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NInt16 * pValue)
	{
		NBool result;
		NCheck(NInt16TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int16TryParse(const N_CLASS(NStringWrapper) & value, NInt16 * pValue) { return Int16TryParse(value, N_CLASS(NString)(), pValue); }

	static bool UInt32TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NUInt32 * pValue)
	{
		NBool result;
		NCheck(NUInt32TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt32TryParse(const N_CLASS(NStringWrapper) & value, NUInt32 * pValue) { return UInt32TryParse(value, N_CLASS(NString)(), pValue); }

	static bool Int32TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NInt32 * pValue)
	{
		NBool result;
		NCheck(NInt32TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int32TryParse(const N_CLASS(NStringWrapper) & value, NInt32 * pValue) { return Int32TryParse(value, N_CLASS(NString)(), pValue); }

#ifndef N_NO_INT_64
	static bool UInt64TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NUInt64 * pValue)
	{
		NBool result;
		NCheck(NUInt64TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool UInt64TryParse(const N_CLASS(NStringWrapper) & value, NUInt64 * pValue) { return UInt64TryParse(value, N_CLASS(NString)(), pValue); }

	static bool Int64TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NInt64 * pValue)
	{
		NBool result;
		NCheck(NInt64TryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool Int64TryParse(const N_CLASS(NStringWrapper) & value, NInt64 * pValue) { return Int64TryParse(value, N_CLASS(NString)(), pValue); }
#endif // !N_NO_INT_64

	static bool SizeTypeTryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NSizeType * pValue)
	{
		NBool result;
		NCheck(NSizeTypeTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool SizeTypeTryParse(const N_CLASS(NStringWrapper) & value, NSizeType * pValue) { return SizeTypeTryParse(value, N_CLASS(NString)(), pValue); }

	static bool SSizeTypeTryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NSSizeType * pValue)
	{
		NBool result;
		NCheck(NSSizeTypeTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool SSizeTypeTryParse(const N_CLASS(NStringWrapper) & value, NSSizeType * pValue) { return SSizeTypeTryParse(value, N_CLASS(NString)(), pValue); }

	static bool PointerTryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, void * * pValue)
	{
		NBool result;
		NCheck(NPointerTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool PointerTryParse(const N_CLASS(NStringWrapper) & value, void * * pValue) { return PointerTryParse(value, N_CLASS(NString)(), pValue); }

#ifndef N_NO_FLOAT
	static bool SingleTryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NSingle * pValue)
	{
		NBool result;
		NCheck(NSingleTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool SingleTryParse(const N_CLASS(NStringWrapper) & value, NSingle * pValue) { return SingleTryParse(value, N_CLASS(NString)(), pValue); }

	static bool DoubleTryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NDouble * pValue)
	{
		NBool result;
		NCheck(NDoubleTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool DoubleTryParse(const N_CLASS(NStringWrapper) & value, NDouble * pValue) { return DoubleTryParse(value, N_CLASS(NString)(), pValue); }
#endif // !N_NO_FLOAT

	static bool BooleanTryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, NBoolean * pValue)
	{
		NBool result;
		NCheck(NBooleanTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool BooleanTryParse(const N_CLASS(NStringWrapper) & value, NBoolean * pValue) { return BooleanTryParse(value, N_CLASS(NString)(), pValue); }

	static NChar CharParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NChar value;
		NCheck(NCharParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NUInt8 UInt8Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt8 value;
		NCheck(NUInt8ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt8 Int8Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt8 value;
		NCheck(NInt8ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NUInt16 UInt16Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt16 value;
		NCheck(NUInt16ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt16 Int16Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt16 value;
		NCheck(NInt16ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NUInt32 UInt32Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt32 value;
		NCheck(NUInt32ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt32 Int32Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt32 value;
		NCheck(NInt32ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

#ifndef N_NO_INT_64
	static NUInt64 UInt64Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NUInt64 value;
		NCheck(NUInt64ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NInt64 Int64Parse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NInt64 value;
		NCheck(NInt64ParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}
#endif // !N_NO_INT_64

	static NSizeType SizeTypeParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NSizeType value;
		NCheck(NSizeTypeParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NSSizeType SSizeTypeParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NSSizeType value;
		NCheck(NSSizeTypeParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static void * PointerParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		void * value;
		NCheck(NPointerParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

#ifndef N_NO_FLOAT
	static NSingle SingleParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NSingle value;
		NCheck(NSingleParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NDouble DoubleParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NDouble value;
		NCheck(NDoubleParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}
#endif // !N_NO_FLOAT

	static NBoolean BooleanParse(const NChar * arValue, NInt valueLength, const NChar * szFormat = NULL)
	{
		NBoolean value;
		NCheck(NBooleanParseStrOrChars(arValue, valueLength, szFormat, &value));
		return value;
	}

	static NChar CharParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NChar result;
		NCheck(NCharParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NUInt8 UInt8Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NUInt8 result;
		NCheck(NUInt8ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt8 Int8Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NInt8 result;
		NCheck(NInt8ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NUInt16 UInt16Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NUInt16 result;
		NCheck(NUInt16ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt16 Int16Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NInt16 result;
		NCheck(NInt16ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NUInt32 UInt32Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NUInt32 result;
		NCheck(NUInt32ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt32 Int32Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NInt32 result;
		NCheck(NInt32ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

#ifndef N_NO_INT_64
	static NUInt64 UInt64Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NUInt64 result;
		NCheck(NUInt64ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NInt64 Int64Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NInt64 result;
		NCheck(NInt64ParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}
#endif // !N_NO_INT_64

	static NSizeType SizeTypeParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NSizeType result;
		NCheck(NSizeTypeParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NSSizeType SSizeTypeParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NSSizeType result;
		NCheck(NSSizeTypeParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static void * PointerParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		void * result;
		NCheck(NPointerParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

#ifndef N_NO_FLOAT
	static NSingle SingleParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NSingle result;
		NCheck(NSingleParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NDouble DoubleParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NDouble result;
		NCheck(NDoubleParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}
#endif // !N_NO_FLOAT

	static NBoolean BooleanParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		NBoolean result;
		NCheck(NBooleanParseN(value.GetHandle(), format.GetHandle(), &result));
		return result;
	}

	static NOSFamily GetOSFamilyCurrent()
	{
		return NOSFamilyGetCurrent();
	}

	friend class N_CLASS(NValue);
	friend class N_CLASS(NArray);
	friend class IO::N_CLASS(NBuffer);
};

template<typename T, typename TNative> class N_CLASS(NDummyArray)
{
private:
	TNative * arValues;
	NInt count;
	bool ownsPtr;

public:
	explicit N_CLASS(NDummyArray)(NInt count)
		: arValues(NULL), count(count), ownsPtr(false)
	{
	}

	N_CLASS(NDummyArray)(TNative * arValues, NInt count, bool ownsPtr)
		: arValues(arValues), count(count), ownsPtr(ownsPtr)
	{
	}

	~N_CLASS(NDummyArray)()
	{
		if (ownsPtr)
		{
			NFree(arValues);
		}
	}

	NInt GetCount() const
	{
		return count;
	}

	const TNative * GetPtr() const
	{
		return arValues;
	}

	TNative * GetPtr()
	{
		return arValues;
	}

	TNative * Release(NInt * pCount = NULL)
	{
		T * ptr = arValues;
		if (pCount) *pCount = count;
		arValues = NULL;
		count = 0;
		ownsPtr = false;
		return ptr;
	}

	T * ToArray(NInt * pCount = NULL)
	{
		return ToArray(count, pCount);
	}

	T * ToArray(NInt realCount, NInt * pCount = NULL)
	{
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		if (realCount > count) NThrowArgumentException(N_T("realCount is greater than count"));
		TNative * ptr = Release();
		if (pCount) *pCount = realCount;
		return reinterpret_cast<T *>(ptr);
	}

	NInt CopyTo(T * arValues, NInt valuesLength)
	{
		return CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(T * arValues, NInt valuesLength, NInt realCount) const
	{
		if (!arValues && valuesLength != 0) NThrowArgumentNullException(N_T("arValues"));
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (valuesLength < realCount) NThrowArgumentInsufficientException(N_T("valuesLength"));
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		if (realCount > count) NThrowArgumentException(N_T("realCount is greater than count"));
		return realCount;
	}
};

class N_CLASS(NBooleanArray)
{
private:
	NBool * arValues;
	NInt count;
	bool ownsPtr;

	static NBool * Alloc(NInt count)
	{
		if (count == 0) return NULL;
		if (count < 0) NThrowArgumentLessThanZeroException(N_T("count"));
		if (N_SIZE_TYPE_MAX / sizeof(NBool) < (NSizeType)count) NThrowOverflowException();
		return reinterpret_cast<NBool *>(NAlloc((NSizeType)count * sizeof(NBool)));
	}

public:
	explicit N_CLASS(NBooleanArray)(NInt count)
		: arValues(Alloc(count)), count(count), ownsPtr(true)
	{
	}

	N_CLASS(NBooleanArray)(const bool * arValues, NInt count)
		: arValues(Alloc(count)), count(count), ownsPtr(true)
	{
		if (!arValues && count != 0) NThrowArgumentNullException(N_T("arValues"));
		if (count < 0) NThrowArgumentLessThanZeroException(N_T("count"));
		const bool * pValue = arValues;
		NBool * pDstValue = this->arValues;
		for (NInt i = 0; i < count; i++, pValue++, pDstValue++)
		{
			*pDstValue = *pValue != 0;
		}
	}

	N_CLASS(NBooleanArray)(NBool * arValues, NInt count, bool ownsPtr = true)
		: arValues(arValues), count(count), ownsPtr(ownsPtr)
	{
	}

	~N_CLASS(NBooleanArray)()
	{
		if (ownsPtr)
		{
			NFree(arValues);
		}
	}

	int GetCount() const
	{
		return count;
	}

	const NBool * GetPtr() const
	{
		return arValues;
	}

	NBool * GetPtr()
	{
		return arValues;
	}

	NBool * Release(NInt * pCount = NULL)
	{
		NBool * ptr = arValues;
		if (pCount) *pCount = count;
		arValues = NULL;
		count = 0;
		ownsPtr = false;
		return ptr;
	}

	bool * ToArray(NInt * pCount = NULL)
	{
		return ToArray(count, pCount);
	}

	bool * ToArray(NInt realCount, NInt * pCount = NULL)
	{
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		auto_array<bool> values(realCount);
		CopyTo(values.get(), realCount, realCount);
		if (pCount) *pCount = realCount;
		return values.release();
	}

	NInt CopyTo(bool * arValues, NInt valuesLength)
	{
		return CopyTo(arValues, valuesLength, count);
	}

	NInt CopyTo(bool * arValues, NInt valuesLength, NInt realCount) const
	{
		if (!arValues && valuesLength != 0) NThrowArgumentNullException(N_T("arValues"));
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (valuesLength < realCount) NThrowArgumentInsufficientException(N_T("valuesLength"));
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		if (realCount > count) NThrowArgumentException(N_T("realCount is greater than count"));
		const NBool * pSrcValue = this->arValues;
		bool * pValue = arValues;
		for (NInt i = 0; i < realCount; i++, pSrcValue++, pValue++)
		{
			*pValue = *pSrcValue ? NTrue : NFalse;
		}
		return realCount;
	}
};

}

#ifdef N_NEED_HASH
	N_HASH_NAMESPACE_BEGIN
		template<> struct hash< ::Neurotec::N_CLASS(NTypes)::CallbackParam>
		{
			size_t operator()(::Neurotec::N_CLASS(NTypes)::CallbackParam const & k) const
			{
				return (size_t)k;
			}
		};
	N_HASH_NAMESPACE_END
#endif

#include <NType.hpp>

namespace Neurotec
{

inline NResult N_API N_CLASS(NTypes)::OnCallbackFree(void * ptr, void *)
{
	delete reinterpret_cast<CallbackParam *>(ptr);
	return N_OK;
}

inline NResult N_API N_CLASS(NTypes)::OnCallbackGetHashCode(void * ptr, NInt * pValue, void *)
{
	NResult result = N_OK;
	try
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		size_t hashCode = (size_t)*reinterpret_cast<CallbackParam *>(ptr);
	#ifdef N_64
		*pValue = (NInt)((hashCode >> 32) ^ (hashCode & 0xFFFFFFFF));
	#else
		*pValue = (NInt)hashCode;
	#endif
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NTypes)::OnCallbackEquals(void * ptr, void * otherPtr, NBool * pResult, void *)
{
	NResult result = N_OK;
	try
	{
		if (!pResult) NThrowArgumentNullException(N_T("pResult"));
		*pResult = *reinterpret_cast<CallbackParam *>(ptr) == *reinterpret_cast<CallbackParam *>(otherPtr);
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NTypes)::PointerFreeProcImpl(void * ptr, void * pParam)
{
	NResult result = N_OK;
	try
	{
		CallbackParam * p = reinterpret_cast<CallbackParam *>(pParam);
		reinterpret_cast<PointerFreeProc>(p->pCallback)(ptr, p->pParam);
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NTypes)::PointerGetHashCodeImpl(void * ptr, NInt * pValue, void * pParam)
{
	NResult result = N_OK;
	try
	{
		if (!pValue) NThrowArgumentNullException(N_T("pValue"));
		CallbackParam * p = reinterpret_cast<CallbackParam *>(pParam);
		*pValue = reinterpret_cast<PointerGetHashCodeProc>(p->pCallback)(ptr, p->pParam);
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NTypes)::PointerEqualsImpl(void * ptr, void * otherPtr, NBool * pResult, void * pParam)
{
	NResult result = N_OK;
	try
	{
		if (!pResult) NThrowArgumentNullException(N_T("pResult"));
		CallbackParam * p = reinterpret_cast<CallbackParam *>(pParam);
		*pResult = reinterpret_cast<PointerEqualsProc>(p->pCallback)(ptr, otherPtr, p->pParam);
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

class N_CLASS(NGuid) : public NGuid_
{
	N_DECLARE_STRUCT_CLASS(NGuid)

public:
	static bool TryParse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format, N_CLASS(NGuid) * pValue)
	{
		NBool result;
		NCheck(NGuidTryParseN(value.GetHandle(), format.GetHandle(), pValue, &result));
		return result != 0;
	}
	static bool TryParse(const N_CLASS(NStringWrapper) & value, N_CLASS(NGuid) * pValue) { return TryParse(value, N_CLASS(NString)(), pValue); }

	static N_CLASS(NGuid) Parse(const N_CLASS(NStringWrapper) & value, const N_CLASS(NStringWrapper) & format = N_CLASS(NString)())
	{
		N_CLASS(NGuid) theValue;
		NCheck(NGuidParseN(value.GetHandle(), format.GetHandle(), &theValue));
		return theValue;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NGuidToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NGuid)

class N_CLASS(NURational) : public NURational_
{
	N_DECLARE_STRUCT_CLASS(NURational)

public:
	N_CLASS(NURational)(NUInt numerator, NUInt denominator)
	{
		Numerator = numerator;
		Denominator = denominator;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NURationalToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NURational)

class N_CLASS(NRational) : public NRational_
{
	N_DECLARE_STRUCT_CLASS(NRational)

public:
	N_CLASS(NRational)(NInt numerator, NInt denominator)
	{
		Numerator = numerator;
		Denominator = denominator;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NRationalToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NRational)

class N_CLASS(NComplex) : public NComplex_
{
	N_DECLARE_STRUCT_CLASS(NComplex)

public:
	N_CLASS(NComplex)(NDouble real, NDouble imaginary)
	{
		Real = real;
		Imaginary = imaginary;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NComplexToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NComplex)

class N_CLASS(NIndexPair) : public NIndexPair_
{
	N_DECLARE_STRUCT_CLASS(NIndexPair)

public:
	N_CLASS(NIndexPair)(NInt index1, NInt index2)
	{
		Index1 = index1;
		Index2 = index2;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NIndexPairToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NIndexPair)

class N_CLASS(NRange) : public NRange_
{
	N_DECLARE_STRUCT_CLASS(NRange)

public:
	N_CLASS(NRange)(NInt from, NInt to)
	{
		From = from;
		To = to;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NRangeToStringN(this, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}
};
N_TYPEDEF_TYPE(NRange)

class N_CLASS(NVersion)
{
	N_DECLARE_COMPARABLE_BASIC_CLASS(NVersion)

public:
	N_CLASS(NVersion)(NInt major, NInt minor)
		: value(NVersionMake(major, minor))
	{
		if (major < N_BYTE_MIN || major > N_BYTE_MAX) NThrowArgumentOutOfRangeException(N_T("major"));
		if (minor < N_BYTE_MIN || minor > N_BYTE_MAX) NThrowArgumentOutOfRangeException(N_T("minor"));
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NVersionToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	NInt GetMajor() const
	{
		return NVersionGetMajor(value);
	}

	NInt GetMinor() const
	{
		return NVersionGetMinor(value);
	}
};
N_TYPEDEF_TYPE(NVersion)

class N_CLASS(NVersionRange)
{
	N_DECLARE_BASIC_CLASS(NVersionRange)

public:
	static N_CLASS(NVersionRange) Intersect(const N_CLASS(NVersionRange) & value1, const N_CLASS(NVersionRange) & value2)
	{
		return N_CLASS(NVersionRange)(NVersionRangeIntersect(value1.value, value2.value));
	}

	N_CLASS(NVersionRange)(const N_CLASS(NVersion) & from, const N_CLASS(NVersion) & to)
		: value(NVersionRangeMake(from.GetValue(), to.GetValue()))
	{
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NVersionRangeToStringN(value, format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	bool Contains(const N_CLASS(NVersion) & value) const
	{
		return NVersionRangeContains(this->value, value.GetValue()) != 0;
	}

	bool Contains(const N_CLASS(NVersionRange) & value) const
	{
		return NVersionRangeContainsRange(this->value, value.value) != 0;
	}

	bool IntersectsWith(const N_CLASS(NVersionRange) & value) const
	{
		return NVersionRangeIntersectsWith(this->value, value.value) != 0;
	}

	N_CLASS(NVersionRange) Intersect(const N_CLASS(NVersionRange) & value) const
	{
		return Intersect(*this, value);
	}

	N_CLASS(NVersion) GetFrom() const
	{
		return N_CLASS(NVersion)(NVersionRangeGetFrom(value));
	}

	N_CLASS(NVersion) GetTo() const
	{
		return N_CLASS(NVersion)(NVersionRangeGetTo(value));
	}
};
N_TYPEDEF_TYPE(NVersionRange)

class N_CLASS(NNameStringPair) : public NNameStringPair_
{
	N_DECLARE_DISPOSABLE_STRUCT_CLASS(NNameStringPair)

public:
	N_CLASS(NNameStringPair)(const N_CLASS(NStringWrapper) & key, const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NNameStringPairCreateN(key.GetHandle(), value.GetHandle(), this));
	}

	N_CLASS(NString) GetKey() const
	{
		return N_CLASS(NString)(hKey, false);
	}

	void SetName(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hKey));
	}

	N_CLASS(NString) GetValue() const
	{
		return N_CLASS(NString)(hValue, false);
	}

	void SetValue(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hValue));
	}
};
N_TYPEDEF_TYPE(NNameStringPair)

inline N_CLASS(NType) * N_CLASS(NTypes)::NUInt8NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NUInt8), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NInt8NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NInt8), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NUInt16NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NUInt16), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NInt16NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NInt16), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NUInt32NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NUInt32), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NInt32NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NInt32), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NUInt64NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NUInt64), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NInt64NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NInt64), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NSingleNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NSingle), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NDoubleNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NDouble), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NBooleanNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NBoolean), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NSizeTypeNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NSizeType), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NSSizeTypeNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NSSizeType), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NPointerNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NPointer), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NResultNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NResult), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NACharNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NAChar), true, true);
}

#ifndef N_NO_UNICODE
inline N_CLASS(NType) * N_CLASS(NTypes)::NWCharNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NAChar), true, true);
}
#endif

inline N_CLASS(NType) * N_CLASS(NTypes)::NCharNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NChar), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NStringNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NString), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NMemoryTypeNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NMemoryType), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NAttributesNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NAttributes), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NOSFamilyNativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NOSFamily), true, true);
}

inline N_CLASS(NType) * N_CLASS(NTypes)::NativeTypeOf()
{
	return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NTypes), true, true);
}

}

#endif // !N_TYPES_HPP_INCLUDED
