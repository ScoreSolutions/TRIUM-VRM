#include <NTypes.hpp>

#ifndef N_OBJECT_HPP_INCLUDED
#define N_OBJECT_HPP_INCLUDED

#include <NParameters.hpp>
#include <NCallback.hpp>
namespace Neurotec
{
namespace IO
{
extern "C"
{
N_DECLARE_OBJECT_TYPE(NBuffer, NObject)
N_DECLARE_OBJECT_TYPE(NStream, NObject)
}
}
using ::Neurotec::IO::HNBuffer;
using ::Neurotec::IO::HNStream;
#include <NObject.h>
}
#include <NWindows.hpp>
#include <NMonitor.hpp>
#include <NSyncChangeObject.hpp>
#include <memory>
#include <vector>
#include <cstring>

namespace Neurotec
{

#undef N_OBJECT_REF_RET

const NUInt N_OBJECT_REF_RET = 0x00000010;

#if defined(N_FRAMEWORK_MFC)
	typedef CRuntimeClass NClass;
	typedef CObject CNObjectBase;

	#define N_CLASS_OF(name) RUNTIME_CLASS(C##name)
	#define N_DECLARE_CLASS(name) DECLARE_DYNAMIC(C##name)
	#define N_IMPLEMENT_CLASS(name, baseName) IMPLEMENT_DYNAMIC(C##name, C##baseName)

	inline N_CLASS(NString) NGetClassName(const NClass * pClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		return N_CLASS(NString)(pClass->m_lpszClassName);
	}

	inline bool NIsClassAssignableFrom(const NClass * pClass, const NClass * pOtherClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		return pClass == pOtherClass || pClass->IsDerivedFrom(pOtherClass);
	}

	inline const NClass * NGetObjectClass(const N_CLASS(NObjectBase) * pObject)
	{
		if (!pObject) NThrowArgumentNullException(N_T("pObject"));
		return pObject->GetRuntimeClass();
	}
#elif defined(N_FRAMEWORK_WX)
	typedef wxClassInfo NClass;
	typedef wxObject wxNObjectBase;

	#define N_CLASS_OF(name) CLASSINFO(wx##name)
	#define N_DECLARE_CLASS(name) DECLARE_CLASS(wx##name)
	#define N_IMPLEMENT_CLASS(name, baseName) IMPLEMENT_CLASS(wx##name, wx##baseName)

	inline N_CLASS(NString) NGetClassName(const NClass * pClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		return N_CLASS(NStringWrapper)(pClass->GetClassName()).GetString();
	}

	inline bool NIsClassAssignableFrom(const NClass * pClass, const NClass * pOtherClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		if (!pOtherClass) return false;
		return pOtherClass->IsKindOf(pClass);
	}

	inline const NClass * NGetObjectClass(const N_CLASS(NObjectBase) * pObject)
	{
		if (!pObject) NThrowArgumentNullException(N_T("pObject"));
		return pObject->GetClassInfo();
	}
/*#elif defined(N_FRAMEWORK_QT)
	typedef QMetaObject NClass;
	typedef QObject QNObjectBase;

	#define N_CLASS_OF(name) (&Q##name::staticMetaObject)
	#define N_DECLARE_CLASS(name) Q_OBJECT
	#define N_IMPLEMENT_CLASS(name, baseName)

	inline N_CLASS(NString) NGetClassName(const NClass * pClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		return N_CLASS(NString)(pClass->className());
	}

	inline bool NIsClassAssignabledFrom(const NClass * pClass, const NClass * pOtherClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		while (pOtherClass)
		{
			if (pOtherClass == pClass) return true;
			else pOtherClass = pOtherClass->superClass();
		}
		return false;
	}

	inline const NClass * NGetObjectClass(const N_CLASS(NObjectBase) * pObject)
	{
		if (!pObject) NThrowArgumentNullException(N_T("pObject"));
		return pObject->metaObject();
	}
*/#else
	class N_CLASS(NObjectBase);

	struct N_CLASS(NClass)
	{
		const NChar * szName;
		const N_CLASS(NClass) * pBaseClass;
		NSizeType instanceSize;

		bool IsSubclassOf(const N_CLASS(NClass) * pClass) const
		{
			if (!pClass) NThrowArgumentNullException(N_T("pClass"));
			const N_CLASS(NClass) * pThisClass = pBaseClass;
			while (pThisClass)
			{
				if (pThisClass == pClass) return true;
				pThisClass = pThisClass->pBaseClass;
			}
			return false;
		}

		bool IsAssignableFrom(const N_CLASS(NClass) * pClass) const
		{
			if (!pClass) return false;
			while (pClass)
			{
				if (pClass == this) return true;
				pClass = pClass->pBaseClass;
			}
			return false;
		}

		bool IsInstanceOfClass(const N_CLASS(NObjectBase) * pObject) const;
	};

	typedef N_CLASS(NClass) NClass;

	class N_CLASS(NObjectBase)
	{
	private:
		N_CLASS(NObjectBase)(const N_CLASS(NObjectBase) &);
		N_CLASS(NObjectBase) & operator=(const N_CLASS(NObjectBase) &);

	protected:
		N_CLASS(NObjectBase)()
		{
		}

	public:
		static const N_CLASS(NClass) N_JOIN_SYMBOLS(class, N_CLASS(NObjectBase));

		virtual ~N_CLASS(NObjectBase)()
		{
		}

		virtual const N_CLASS(NClass) * GetClass() const
		{
			return &N_JOIN_SYMBOLS(class, N_CLASS(NObjectBase));
		}
	};

	inline bool N_CLASS(NClass)::IsInstanceOfClass(const N_CLASS(NObjectBase) * pObject) const
	{
		if (!pObject) return false;
		return IsAssignableFrom(pObject->GetClass());
	}

	#define N_CLASS_OF(name) (&N_CLASS(name)::N_JOIN_SYMBOLS(class, N_CLASS(name)))
	#define N_DECLARE_CLASS(name) \
		public:\
			static const ::Neurotec::N_CLASS(NClass) N_JOIN_SYMBOLS(class, N_CLASS(name));\
			virtual const ::Neurotec::N_CLASS(NClass) * GetClass() const;
	#define N_IMPLEMENT_CLASS(name, baseName) \
		const ::Neurotec::N_CLASS(NClass) N_CLASS(name)::N_JOIN_SYMBOLS(class, N_CLASS(name)) = { N_STRINGIZE(N_CLASS(name)), &N_CLASS(baseName)::N_JOIN_SYMBOLS(class, N_CLASS(baseName)), sizeof(N_CLASS(name)) };\
		const ::Neurotec::N_CLASS(NClass) * N_CLASS(name)::GetClass() const { return &N_CLASS(name)::N_JOIN_SYMBOLS(class, N_CLASS(name)); }

	inline N_CLASS(NString) NGetClassName(const NClass * pClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		return N_CLASS(NString)(pClass->szName);
	}

	inline bool NIsClassAssignableFrom(const NClass * pClass, const NClass * pOtherClass)
	{
		if (!pClass) NThrowArgumentNullException(N_T("pClass"));
		return pClass->IsAssignableFrom(pOtherClass);
	}

	inline const NClass * NGetObjectClass(const N_CLASS(NObjectBase) * pObject)
	{
		if (!pObject) NThrowArgumentNullException(N_T("pObject"));
		return pObject->GetClass();
	}
#endif

namespace Collections
{
template<typename TOwner> class N_CLASS(NStringReadOnlyCollection);
template<typename TOwner> class N_CLASS(NStringCollection);
}

class N_CLASS(NObject) : public N_CLASS(NObjectBase)
{
private:
	typedef N_CLASS(NType) * (* NativeTypeOfProc)();

protected:
	typedef N_CLASS(NObject) * (* FromHandleProc)(HNObject handle);

private:
	enum State
	{
		nosNone = 0,
		nosOwnsHandle = 1,
		nosNativeAllocated = 2,
		nosRegistered = 4,
		nosNative = 8,
	};

	static ::Neurotec::Threading::NMonitorType warmedUpTypesLock;
	static N_HASH_SET<NativeTypeOfProc> warmedUpTypes;
	static ::Neurotec::Threading::NMonitorType typeMapLock;
	static N_HASH_MAP<HNType, FromHandleProc> typeMap;
	static ::Neurotec::Threading::NMonitorType objectMapLock;
	static N_HASH_MAP<HNObject, N_CLASS(NObject) *> objectMap;

	static void WarmUpType(NativeTypeOfProc pNativeTypeOf)
	{
		bool warmUp = false;
		{
			::Neurotec::Threading::NMonitorLockerType warmedUpTypesLocker(N_MONITOR_LOCKER_ARGS(warmedUpTypesLock));
			if (warmedUpTypes.find(pNativeTypeOf) == warmedUpTypes.end())
			{
				warmUp = true;
			}
		}
		if (warmUp)
		{
			::Neurotec::Threading::NMonitorLockerType objectMapLocker(N_MONITOR_LOCKER_ARGS(objectMapLock)); // Obtain object map lock first to prevent deadlock
			::Neurotec::Threading::NMonitorLockerType warmedUpTypesLocker(N_MONITOR_LOCKER_ARGS(typeMapLock));
			if (warmedUpTypes.find(pNativeTypeOf) == warmedUpTypes.end()) // If we need to add it, as we may have race condition here
			{
				warmedUpTypes.insert(pNativeTypeOf);
				pNativeTypeOf();
			}
		}
	}

	static N_CLASS(NObject) * N_JOIN_SYMBOLS(N_CLASS(NObject), FromHandle)(HNObject handle)
	{
		return new N_CLASS(NObject)(handle, false);
	}

	static NResult N_API OnTypeDisposed(HNObject hObject, void *);

	static struct N_JOIN_SYMBOLS(N_CLASS(NObject), Initializer)
	{
		N_JOIN_SYMBOLS(N_CLASS(NObject), Initializer)()
		{
			RegisterType(N_TYPE_OF(NObject), N_JOIN_SYMBOLS(N_CLASS(NObject), FromHandle));
		}

		~N_JOIN_SYMBOLS(N_CLASS(NObject), Initializer)()
		{
			for (N_HASH_MAP<HNObject, N_CLASS(NObject) *>::iterator i = objectMap.begin(); i != objectMap.end(); i++)
			{
				N_CLASS(NObject) * pObject = i->second;
				i->second = NULL;
				pObject->state = (State)(pObject->state & ~nosRegistered);
				delete pObject;
			}
			for (N_HASH_MAP<HNType, FromHandleProc>::iterator i = typeMap.begin(); i != typeMap.end(); i++)
			{
				NCheck(NObjectRemoveDisposedCallback(i->first, OnTypeDisposed, NULL));
			}
		}
	} N_JOIN_SYMBOLS(initializer, N_CLASS(NObject));

	static NResult N_API OnDisposed(HNObject, void * pParam);

	HNObject handle;
	State state;
	N_CLASS(NObject) * pOwner;

	N_CLASS(NObject)(const N_CLASS(NObject) &);
	N_CLASS(NObject) & operator=(const N_CLASS(NObject) &);

	void Init()
	{
	}

	void Uninit();

protected:
	static void RegisterType(NTypeOfProc pTypeOf, FromHandleProc pFromHandle)
	{
		RegisterType(pTypeOf, pFromHandle, 0);
	}

	static void RegisterType(NTypeOfProc pTypeOf, FromHandleProc pFromHandle, NInt derivedTypeCount, ...)
	{
		va_list args;
		va_start(args, derivedTypeCount);
		RegisterType(pTypeOf, pFromHandle, derivedTypeCount, args);
		va_end(args);
	}

	static void RegisterType(NTypeOfProc pTypeOf, FromHandleProc pFromHandle, NInt derivedTypeCount, va_list args)
	{
		if (!pTypeOf) NThrowArgumentNullException(N_T("pTypeOf"));
		if (!pFromHandle) NThrowArgumentNullException(N_T("pFromHandle"));
		HNType hType;
		NCheck(pTypeOf(&hType));
		try
		{
			::Neurotec::Threading::NMonitorLockerType typeMapLocker(N_MONITOR_LOCKER_ARGS(typeMapLock));
			if (typeMap.count(hType) == 0) // Because static initialization in methods is not required to be serialized
			{
				NCheck(NObjectAddDisposedCallback(hType, OnTypeDisposed, NULL));
				typeMap.insert(::std::pair<const HNType, FromHandleProc>(hType, pFromHandle));
			}
			Unref(hType); hType = NULL;
		}
		catch (...)
		{
			Unref(hType);
			throw;
		}
		for (NInt i = 0; i < derivedTypeCount; i++)
		{
			WarmUpType(va_arg(args, NativeTypeOfProc));
		}
	}

	static void N_JOIN_SYMBOLS(N_CLASS(NObject), RegisterType)()
	{
	}

	static NResult N_API OnSyncChanging(HNObject hObject, void * pParam);
	static NResult N_API OnSyncChanged(HNObject hObject, void * pParam);
	static NResult N_API CallbackImpl(HNObject hObject, void * pParam);
	static NResult N_API PropertyChangedCallbackImpl(HNObject hObject, HNString hPropertyName, void * pParam);

	N_CLASS(NObject)(HNObject handle, bool claimHandle)
		: handle(handle), state(nosNone), pOwner(NULL)
	{
		if (!handle) NThrowArgumentNullException(N_T("handle"));
		state = (State)((claimHandle ? nosOwnsHandle : nosNone) | nosNativeAllocated);
		Init();
	}

	N_CLASS(NObject)(NSSizeType handleOffset)
		: handle(NULL), state(nosNative), pOwner(NULL)
	{
		handle = (HNObject)((NByte *)this + handleOffset);
		Init();
	}

#ifdef N_DEBUG
	void Check() const
	{
		if (IsDisposed()) NThrowInvalidOperationException(N_T("Native object is disposed"));
	}
#endif

#include <NNoDeprecate.h>
	template<typename THandle> N_CLASS(NString) GetString(NResult (N_CALLBACK pGetString)(THandle handle, HNString * phValue)) const;
	template<typename THandle> void SetString(NResult (N_CALLBACK pSetString)(THandle handle, HNString hValue), const N_CLASS(NStringWrapper) & value);
	template<typename THandle, typename T> T * GetObject(NResult (N_CALLBACK pGetObject)(THandle handle, typename T::HandleType * phValue), bool ownsHandle = true, bool cache = false) const;

	template<typename THandle, typename T> void SetObject(NResult (N_CALLBACK pSetObject)(THandle handle, typename T::HandleType hValue), T * pValue)
	{
		THandle hObj = static_cast<THandle>(GetHandle());
		NCheck(pSetObject(hObj, ToHandle(pValue)));
	}

	template<typename THandle, typename T> T * * GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * * parhValues, NInt * pValueCount), NInt * pCount, bool ownsHandles = true, bool cache = false) const;
	template<typename THandle, typename T> NInt GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * arhValues, NInt valuesLength), T * * arpValues, NInt valuesLength, bool ownsHandles = true, bool cache = false) const;
	template<typename THandle, typename T> T * * GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * arhValues, NInt valuesLength), NInt * pCount, bool ownsHandles = true, bool cache = false) const;
#include <NReDeprecate.h>

public:
	typedef void (* Callback)(N_CLASS(NObject) * pObject, void * pParam);
	typedef void (* PropertyChangedCallback)(N_CLASS(NObject) * pObject, N_CLASS(NString) propertyName, void * pParam);

	static void Unref(HNObject handle)
	{
		if (handle) NCheck(NObjectUnref(handle));
	}

	template<typename THandle> static void UnrefElements(THandle * arhObjects, NInt objectCount)
	{
		THandle p0 = NULL;
		HNObject p = p0;
		NCheck(NObjectUnrefElements(reinterpret_cast<HNObject *>(arhObjects), objectCount));
		N_UNREFERENCED_PARAMETER(p);
	}

	template<typename THandle> static void UnrefArray(THandle * arhObjects, NInt objectCount)
	{
		THandle p0 = NULL;
		HNObject p = p0;
		NCheck(NObjectUnrefArray(reinterpret_cast<HNObject *>(arhObjects), objectCount));
		N_UNREFERENCED_PARAMETER(p);
	}

	static bool Equals(N_CLASS(NObject) * pObject1, N_CLASS(NObject) * pObject2)
	{
		if (!pObject1 && !pObject2) return true;
		if (!pObject1 || !pObject2) return false;
		return pObject1->Equals(pObject2);
	}

#include <NNoDeprecate.h>
	template<typename T> static T * FromHandle(typename T::HandleType handle, bool ownsHandle = true, bool cache = false);

	static void UnrefOrDelete(HNObject hObject, N_CLASS(NObject) * pObject)
	{
		if (pObject) delete pObject;
		else if (hObject) NCheck(NObjectUnref(hObject));
	}

	template<typename T> static typename T::HandleType ToHandle(const T * pObject, bool addRef = false);
	template<typename T> static NInt ToHandleArray(T * const * arpObjects, NInt objectCount, typename T::HandleType * arhObjects, NInt objectsLength, bool addRef = false);

	template<typename T> static T * GetObject(NResult (N_CALLBACK pGetObject)(typename T::HandleType * phValue), bool ownsHandle = true, bool cache = false);

	template<typename T> void SetObject(NResult (N_CALLBACK pSetObject)(typename T::HandleType hValue), T * pValue)
	{
		NCheck(pSetObject(ToHandle(pValue)));
	}

	template<typename T> static T * * GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * * parhValues, NInt * pValueCount), NInt * pCount, bool ownsHandle = true, bool cache = false);
	template<typename T> static NInt GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * arhValues, NInt valuesLength), T * * arpValues, NInt valuesLength, bool ownsHandle = true, bool cache = false);
	template<typename T> static T * * GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * arhValues, NInt valuesLength), NInt * pCount, bool ownsHandle = true, bool cache = false);
#include <NReDeprecate.h>

	static N_CLASS(NString) GetString(NResult (N_CALLBACK pGetString)(HNString * phValue))
	{
		HNString hValue;
		NCheck(pGetString(&hValue));
		return N_CLASS(NString)(hValue, true);
	}

	static void SetString(NResult (N_CALLBACK pSetString)(HNString hValue), const N_CLASS(NStringWrapper) & value)
	{
		NCheck(pSetString(value.GetHandle()));
	}

	static void CopyProperties(N_CLASS(NObject) * pDstObject, const N_CLASS(NObject) * pSrcObject)
	{
		if (!pDstObject) NThrowArgumentNullException(N_T("pDstObject"));
		if (!pSrcObject) NThrowArgumentNullException(N_T("pSrcObject"));
		NCheck(NObjectCopyProperties(pDstObject->GetHandle(), pSrcObject->GetHandle()));
	}

	static void CopyParameters(N_CLASS(NObject) * pDstObject, const N_CLASS(NObject) * pSrcObject)
	{
		CopyProperties(pDstObject, pSrcObject);
	}

	template<typename T> static void SaveMany(T * const * arpObjects, NInt objectCount, ::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0);
	template<typename T> static ::Neurotec::IO::N_CLASS(NBuffer) * SaveMany(T * const * arpObjects, NInt objectCount, NUInt flags = 0);
	template<typename T> static NSizeType GetSizeMany(T * const * arpObjects, NInt objectCount, NUInt flags = 0);
	template<typename T> static NSizeType SaveMany(T * const * arpObjects, NInt objectCount, ::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0);
	template<typename T> static NSizeType SaveMany(T * const * arpObjects, NInt objectCount, void * pBuffer, NSizeType bufferSize, NUInt flags = 0);

	virtual ~N_CLASS(NObject)()
	{
		Uninit();
	}

	bool IsDisposed() const
	{
	#ifdef N_DEBUG
		if (this == NULL) NThrowNullReferenceException();
	#endif
		return (state & (nosNativeAllocated | nosNative)) == 0;
	}

	HNObject GetHandle() const
	{
	#ifdef N_DEBUG
		Check();
	#endif
		return handle;
	}

	NInt Ref()
	{
		return NCheck(NObjectRef(GetHandle()));
	}

	NInt Unref()
	{
		return NCheck(NObjectUnref(GetHandle()));
	}

	HNObject RefHandle() const
	{
		NCheck(NObjectRef(GetHandle()));
		return handle;
	}

	N_CLASS(NObject) * RefObject() const
	{
		HNObject handle = RefHandle();
		try
		{
			return FromHandle<N_CLASS(NObject)>(handle);
		}
		catch (...)
		{
			NCheck(NObjectUnref(handle));
			throw;
		}
	}

	N_CLASS(NType) * GetNativeType() const;

	N_CLASS(NObject) * GetOwner() const
	{
		return GetObject<HandleType, N_CLASS(NObject)>(NObjectGetOwnerEx, true, true);
	}

	NUInt GetFlags() const
	{
		NUInt value;
		NCheck(NObjectGetFlags(GetHandle(), &value));
		return value;
	}

	void SetFlags(NUInt value)
	{
		NCheck(NObjectSetFlags(GetHandle(), value));
	}

	bool Equals(N_CLASS(NObject) * pObject) const
	{
		if (this != NULL && pObject == this) return true;
		else if (!pObject) return false;
		NBool result;
		NCheck(NObjectEquals(GetHandle(), pObject->GetHandle(), &result));
		return result != 0;
	}

	NInt CompareTo(N_CLASS(NObject) * pObject) const
	{
		if (this != NULL && pObject == this) return 0;
		else if (!pObject) return 1;
		NInt result;
		NCheck(NObjectEquals(GetHandle(), pObject->GetHandle(), &result));
		return result;
	}

	NInt GetHashCode() const
	{
		NInt value;
		NCheck(NObjectGetHashCode(GetHandle(), &value));
		return value;
	}

	N_CLASS(NString) ToString(const N_CLASS(NStringWrapper) & format = N_CLASS(NString)()) const
	{
		HNString hValue;
		NCheck(NObjectToStringN(GetHandle(), format.GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	N_CLASS(NObject) * Clone() const
	{
		HNObject hClonedObject;
		NCheck(NObjectClone(GetHandle(), &hClonedObject));
		try
		{
			return FromHandle<N_CLASS(NObject)>(hClonedObject);
		}
		catch (...)
		{
			Unref(hClonedObject);
			throw;
		}
	}

	void Reset()
	{
		NCheck(NObjectReset(GetHandle()));
	}

	N_CLASS(NValue) * GetProperty(const N_CLASS(NStringWrapper) & name) const;
	bool GetProperty(const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const;
	template<typename T> T GetProperty(const N_CLASS(NStringWrapper) & name, NAttributes attributes = naNone, bool * pHasValue = NULL) const;

	NInt GetParameter(NUShort partId, NUShort parameterId, NInt typeId, void * pValue, NSizeType valueSize = N_SIZE_TYPE_MAX) const
	{
		return NCheck(NObjectGetParameterWithPartEx(GetHandle(), partId, parameterId, typeId, pValue, valueSize));
	}
	N_DEPRECATED("method is deprecated, use GetParameter(NUShort, NUShort, NInt, void *, NSizeType) const instead")
	NInt GetParameter(NUShort partId, NUShort parameterId, void * pValue) const { return GetParameter(partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX); }
	template<typename T> T GetParameter(NUShort partId, NUShort parameterId) const;

	void SetProperty(const N_CLASS(NStringWrapper) & name, N_CLASS(NValue) * pValue);
	void SetProperty(const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue = true);
	template<typename T> void SetProperty(const N_CLASS(NStringWrapper) & name, const T & value, NAttributes attributes = naNone, bool hasValue = true);

	void SetParameter(NUShort partId, NUShort parameterId, NInt typeId, const void * pValue, NSizeType valueSize = N_SIZE_TYPE_MAX)
	{
		NCheck(NObjectSetParameterWithPartEx(GetHandle(), partId, parameterId, typeId, pValue, valueSize));
	}
	N_DEPRECATED("method is deprecated, use SetParameter(NUShort, NUShort, NInt, const void *, NSizeType) instead")
	void SetParameter(NUShort partId, NUShort parameterId, const void * pValue) { SetParameter(partId, parameterId, -1, pValue, N_SIZE_TYPE_MAX); }
	template<typename T> void SetParameter(NUShort partId, NUShort parameterId, const T & value);

	void ResetProperty(const N_CLASS(NStringWrapper) & name)
	{
		NCheck(NObjectResetPropertyN(GetHandle(), name.GetHandle()));
	}

	NInt GetParameter(NUShort parameterId, NInt typeId, void * pValue, NSizeType valueSize = N_SIZE_TYPE_MAX) const { return GetParameter((NUShort)0, parameterId, typeId, pValue, valueSize); }
#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use GetParameter(NUShort, NInt, void *, NSizeType) const instead")
	NInt GetParameter(NUShort parameterId, void * pValue) const
	{
		return GetParameter((NUShort)0, parameterId, pValue);
	}
#include <NReDeprecate.h>
	template<typename T> T GetParameter(NUShort parameterId) const { return GetParameter<T>((NUShort)0, parameterId); }

	void SetParameter(NUShort parameterId, NInt typeId, const void * pValue, NSizeType valueSize = N_SIZE_TYPE_MAX) { SetParameter((NUShort)0, parameterId, typeId, pValue, valueSize); }
#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use SetParameter(NUShort, NInt, const void *, NSizeType) instead")
	void SetParameter(NUShort parameterId, const void * pValue)
	{
		SetParameter((NUShort)0, parameterId, pValue);
	}
#include <NReDeprecate.h>
	template<typename T> void SetParameter(NUShort parameterId, const T & value) { SetParameter<T>((NUShort)0, parameterId, value); }

	void Save(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags = 0) const;
	::Neurotec::IO::N_CLASS(NBuffer) * Save(NUInt flags = 0) const;

	NSizeType GetSize(NUInt flags = 0) const
	{
		NSizeType value;
		NCheck(NObjectGetSize(GetHandle(), flags, &value));
		return value;
	}

	NSizeType Save(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags = 0) const;

	NSizeType Save(void * pBuffer, NSizeType bufferSize, NUInt flags = 0) const
	{
		NSizeType size;
		NCheck(NObjectSaveToMemoryDst(GetHandle(), pBuffer, bufferSize, flags, &size));
		return size;
	}

	void AddPropertyChangedCallback(PropertyChangedCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(PropertyChangedCallbackImpl, pCallback, pParam);
		NCheck(NObjectAddPropertyChanged(GetHandle(), callback.GetHandle()));
	}

	void RemovePropertyChangedCallback(PropertyChangedCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(PropertyChangedCallbackImpl, pCallback, pParam);
		NCheck(NObjectRemovePropertyChanged(GetHandle(), callback.GetHandle()));
	}

	template<typename TOwner> friend class ::Neurotec::Collections::N_CLASS(NStringReadOnlyCollection);
	template<typename TOwner> friend class ::Neurotec::Collections::N_CLASS(NStringCollection);

	typedef HNObject HandleType;
	static ::Neurotec::N_CLASS(NType) * NativeTypeOf();
	N_DECLARE_CLASS(NObject)

	friend class N_CLASS(NValue);
	friend class N_CLASS(NArray);
};

#define N_DECLARE_STATIC_OBJECT_CLASS(name) \
	N_DECLARE_TYPE_CLASS(name)\
	N_DECLARE_NON_COPYABLE(name)\
	private:\
		N_CLASS(name)();
#define N_OBJECT_CLASS_REGISTER_TYPE(name) { N_JOIN_SYMBOLS(N_CLASS(name), RegisterType)(); }
#define N_DECLARE_OBJECT_CLASS(name, baseName) \
		N_DECLARE_NON_COPYABLE(name)\
	private:\
		static ::Neurotec::N_CLASS(NObject) * N_JOIN_SYMBOLS(N_CLASS(name), FromHandle)(HNObject handle) { return new N_CLASS(name)(handle, false); }\
	protected:\
		static void N_JOIN_SYMBOLS(N_CLASS(name), RegisterType)();\
	public:\
		typedef H##name HandleType;\
		static ::Neurotec::N_CLASS(NType) * NativeTypeOf()\
		{\
			N_OBJECT_CLASS_REGISTER_TYPE(name);\
			return ::Neurotec::N_CLASS(NObject)::GetObject< ::Neurotec::N_CLASS(NType)>(N_TYPE_OF(name), true, true);\
		}\
		H##name GetHandle() const { return static_cast<H##name>(N_CLASS(baseName)::GetHandle()); }\
		H##name RefHandle() const { return static_cast<H##name>(N_CLASS(baseName)::RefHandle()); }\
	N_DECLARE_CLASS(name)
#define N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, args) \
	void N_CLASS(name)::N_JOIN_SYMBOLS(N_CLASS(name), RegisterType)()\
	{\
		static bool registered = false;\
		if (!registered)\
		{\
			N_OBJECT_CLASS_REGISTER_TYPE(baseName);\
			RegisterType args;\
			registered = true;\
		}\
	}\
	N_IMPLEMENT_CLASS(name, baseName)
#define N_IMPLEMENT_OBJECT_CLASS(name, baseName) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle)))
#define N_IMPLEMENT_OBJECT_CLASS_1(name, baseName, dt1) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 1, N_CLASS(dt1)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_2(name, baseName, dt1, dt2) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 2, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_3(name, baseName, dt1, dt2, dt3) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 3, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_4(name, baseName, dt1, dt2, dt3, dt4) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 4, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf, N_CLASS(dt4)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_5(name, baseName, dt1, dt2, dt3, dt4, dt5) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 5, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf, N_CLASS(dt4)::NativeTypeOf, N_CLASS(dt5)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_6(name, baseName, dt1, dt2, dt3, dt4, dt5, dt6) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 6, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf, N_CLASS(dt4)::NativeTypeOf, N_CLASS(dt5)::NativeTypeOf, N_CLASS(dt6)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_7(name, baseName, dt1, dt2, dt3, dt4, dt5, dt6, dt7) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 7, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf, N_CLASS(dt4)::NativeTypeOf, N_CLASS(dt5)::NativeTypeOf, N_CLASS(dt6)::NativeTypeOf, N_CLASS(dt7)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_8(name, baseName, dt1, dt2, dt3, dt4, dt5, dt6, dt7, dt8) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 8, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf, N_CLASS(dt4)::NativeTypeOf, N_CLASS(dt5)::NativeTypeOf, N_CLASS(dt6)::NativeTypeOf, N_CLASS(dt7)::NativeTypeOf, N_CLASS(dt8)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_9(name, baseName, dt1, dt2, dt3, dt4, dt5, dt6, dt7, dt8, dt9) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 9, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf, N_CLASS(dt4)::NativeTypeOf, N_CLASS(dt5)::NativeTypeOf, N_CLASS(dt6)::NativeTypeOf, N_CLASS(dt7)::NativeTypeOf, N_CLASS(dt8)::NativeTypeOf, N_CLASS(dt9)::NativeTypeOf))
#define N_IMPLEMENT_OBJECT_CLASS_10(name, baseName, dt1, dt2, dt3, dt4, dt5, dt6, dt7, dt8, dt9, dt10) N_IMPLEMENT_OBJECT_CLASS_ARGS(name, baseName, (N_TYPE_OF(name), N_JOIN_SYMBOLS(N_CLASS(name), FromHandle), 10, N_CLASS(dt1)::NativeTypeOf, N_CLASS(dt2)::NativeTypeOf, N_CLASS(dt3)::NativeTypeOf, N_CLASS(dt4)::NativeTypeOf, N_CLASS(dt5)::NativeTypeOf, N_CLASS(dt6)::NativeTypeOf, N_CLASS(dt7)::NativeTypeOf, N_CLASS(dt8)::NativeTypeOf, N_CLASS(dt9)::NativeTypeOf, N_CLASS(dt10)::NativeTypeOf))

#include <NNoDeprecate.h>
template<typename T> class N_CLASS(NObjectArray)
{
private:
	typename T::HandleType * arhObjects;
	NInt count;
	bool ownsPtr;
	bool ownsHandles;
	bool cache;

	static typename T::HandleType * Alloc(NInt count)
	{
		if (count == 0) return NULL;
		if (count < 0) NThrowArgumentLessThanZeroException(N_T("count"));
		if (N_SIZE_TYPE_MAX / sizeof(typename T::HandleType) < (NSizeType)count) NThrowOverflowException();
		return reinterpret_cast<typename T::HandleType *>(NCAlloc((NSizeType)count * sizeof(typename T::HandleType)));
	}

public:
	N_CLASS(NObjectArray)(NInt count)
		: arhObjects(Alloc(count)), count(count), ownsPtr(true), ownsHandles(true), cache(false)
	{
	}

	N_CLASS(NObjectArray)(NInt count, bool ownsHandles, bool cache)
		: arhObjects(Alloc(count)), count(count), ownsPtr(true), ownsHandles(ownsHandles), cache(cache)
	{
	}

	N_CLASS(NObjectArray)(T * const * arpObjects, NInt count)
		: arhObjects(Alloc(count)), count(count), ownsPtr(true), ownsHandles(true), cache(false)
	{
		if (!arpObjects && count != 0) NThrowArgumentNullException(N_T("arpObjects"));
		if (count < 0) NThrowArgumentLessThanZeroException(N_T("count"));
		T * const * ppObject = arpObjects;
		typename T::HandleType * phObject = arhObjects;
		for (NInt i = 0; i < count; i++, ppObject++, phObject++)
		{
			if (!*ppObject)
			{
				*phObject = NULL;
			}
			else
			{
				*phObject = (*ppObject)->RefHandle();
			}
		}
	}

	N_CLASS(NObjectArray)(typename T::HandleType * arhObjects, NInt count)
		: arhObjects(arhObjects), count(count), ownsPtr(true), ownsHandles(true), cache(false)
	{
	}

	N_CLASS(NObjectArray)(typename T::HandleType * arhObjects, NInt count, bool ownsPtr, bool ownsHandles, bool cache)
		: arhObjects(arhObjects), count(count), ownsPtr(ownsPtr), ownsHandles(ownsHandles), cache(cache)
	{
	}

	~N_CLASS(NObjectArray)()
	{
		if (ownsHandles)
		{
			N_CLASS(NObject)::UnrefElements(arhObjects, count);
		}
		if (ownsPtr)
		{
			NFree(arhObjects);
		}
	}

	int GetCount() const
	{
		return count;
	}

	const typename T::HandleType * GetPtr() const
	{
		return arhObjects;
	}

	typename T::HandleType * GetPtr()
	{
		return arhObjects;
	}

	typename T::HandleType * Release(NInt * pCount = NULL)
	{
		typename T::HandleType * ptr = arhObjects;
		if (pCount) *pCount = count;
		arhObjects = NULL;
		count = 0;
		ownsPtr = false;
		return ptr;
	}

	T * * ToArray(NInt * pCount = NULL)
	{
		return ToArray(count, pCount);
	}

	T * * ToArray(NInt realCount, NInt * pCount = NULL)
	{
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		auto_array<T *> pObjects(realCount);
		CopyTo(pObjects.get(), realCount, realCount);
		if (pCount) *pCount = realCount;
		return pObjects.release();
	}

	NInt CopyTo(T * * arpValues, NInt valuesLength)
	{
		return CopyTo(arpValues, valuesLength, count);
	}

	NInt CopyTo(T * * arpValues, NInt valuesLength, NInt realCount) const
	{
		if (!arpValues && valuesLength != 0) NThrowArgumentNullException(N_T("arpValues"));
		if (valuesLength < 0) NThrowArgumentLessThanZeroException(N_T("valuesLength"));
		if (valuesLength < realCount) NThrowArgumentInsufficientException(N_T("valuesLength"));
		if (realCount < 0) NThrowArgumentLessThanZeroException(N_T("realCount"));
		if (realCount > count) NThrowArgumentException(N_T("realCount is greater than count"));
		const typename T::HandleType * phObject = arhObjects;
		T * * ppObject = arpValues;
		NInt i = 0;
		try
		{
			for (; i < realCount; i++, phObject++, ppObject++)
			{
				typename T::HandleType hObject = *phObject;
				if (!hObject)
				{
					*ppObject = NULL;
				}
				else
				{
					if (ownsHandles) NCheck(NObjectRef(hObject));
					try
					{
						*ppObject = N_CLASS(NObject)::FromHandle<T>(hObject, ownsHandles, cache);
					}
					catch (...)
					{
						if (ownsHandles) NCheck(NObjectUnref(hObject));
						throw;
					}
				}
			}
		}
		catch (...)
		{
			if (!cache)
			{
				T * * ppObject = arpValues + i;
				for (; i >= 0; i--, ppObject--)
				{
					delete *ppObject;
				}
			}
			throw;
		}
		return realCount;
	}
};
#include <NReDeprecate.h>

template<typename T> class NAutoUnref
{
private:
	T * pObject;

public:
	explicit NAutoUnref(T * pObject = NULL)
		: pObject(pObject)
	{
	}

	NAutoUnref(NAutoUnref & value)
		: pObject(value.Release())
	{
	}

	~NAutoUnref()
	{
		Reset();
	}

	NAutoUnref & operator=(NAutoUnref & value)
	{
		Reset(value.Release());
		return (*this);
	}

	T * Get() const
	{
		return pObject;
	}

	T * Release()
	{
		T * pObject = this->pObject;
		this->pObject = NULL;
		return pObject;
	}

	void Reset(T * pObject = NULL)
	{
		if (pObject != this->pObject)
		{
			if (this->pObject) this->pObject->Unref();
			this->pObject = pObject;
		}
	}

	T * operator->() const
	{
		return Get();
	}

	T & operator*() const
	{
		return *Get();
	}
};

template<typename T> class NAutoUnrefArray
{
private:
	T * * ptr;
	NInt count;

public:
	NAutoUnrefArray()
		: ptr(NULL), count(0)
	{
	}

	NAutoUnrefArray(T * * ptr, NInt count)
		: ptr(ptr), count(count)
	{
	}

	NAutoUnrefArray(NInt count)
		: ptr((T * *)NCAlloc(sizeof(T *) * count)), count(count)
	{
	}

	NAutoUnrefArray(NAutoUnrefArray & value)
		: ptr(value.ptr), count(value.count)
	{
		value.Release();
	}

	~NAutoUnrefArray()
	{
		Reset();
	}

	NAutoUnrefArray & operator=(NAutoUnrefArray & value)
	{
		NInt count = value.count;
		Reset(value.Release(), count);
		return (*this);
	}

	T * & operator[](int index) const
	{
		return Get()[index];
	}

	T * * Get() const
	{
		return ptr;
	}

	T * & Get(int index) const
	{
		return ptr[index];
	}

	int GetCount() const
	{
		return count;
	}

	T * * Release()
	{
		T * * ptr = this->ptr;
		this->ptr = NULL;
		count = 0;
		return ptr;
	}

	void Reset()
	{
		Reset(NULL, 0);
	}

	void Reset(T * * ptr, NInt count)
	{
		if (ptr != this->ptr)
		{
			if (this->ptr)
			{
				for (NInt i = 0; i < this->count; i++)
				{
					if (this->ptr[i]) this->ptr[i]->Unref();
				}
				NFree(this->ptr);
			}
			this->ptr = ptr;
		}
		this->count = count;
	}
};

}

#include <NType.hpp>
#include <NError.hpp>

namespace Neurotec
{

inline ::Neurotec::N_CLASS(NType) * N_CLASS(NObject)::NativeTypeOf()
{
	HNType hValue;
	NCheck(N_TYPE_OF(NObject)(&hValue));
	return FromHandle< ::Neurotec::N_CLASS(NType)>(hValue, true, true);
}

inline NResult N_API N_CLASS(NObject)::OnTypeDisposed(HNObject hObject, void *)
{
	NResult result = N_OK;
	try
	{
		::Neurotec::Threading::NMonitorLockerType typeMapLocker(N_MONITOR_LOCKER_ARGS(typeMapLock));
		typeMap.erase(static_cast<HNType>(hObject));
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NObject)::OnDisposed(HNObject, void * pParam)
{
	NResult result = N_OK;
	try
	{
		N_CLASS(NObject) * pObject = reinterpret_cast<N_CLASS(NObject) *>(pParam);
		pObject->state = (State)(pObject->state & ~nosNativeAllocated);
		delete pObject;
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

#include <NNoDeprecate.h>
template<typename T> inline T * N_CLASS(NObject)::FromHandle(typename T::HandleType handle, bool ownsHandle, bool cache)
{
	if (!handle) return NULL;
	bool exitObjectMapLock = false;
	T * pObject = NULL;
	try
	{
		if (cache)
		{
			::Neurotec::Threading::NEnterMonitor(objectMapLock); exitObjectMapLock = true;
			N_HASH_MAP<HNObject, N_CLASS(NObject) *>::const_iterator o = objectMap.find(handle);
			if (o != objectMap.end())
			{
				if (o->second) pObject = &dynamic_cast<T&>(*o->second);
			}
		}
		if (!pObject)
		{
			WarmUpType(T::NativeTypeOf);
			::Neurotec::Threading::NMonitorLockerType typeMapLocker(N_MONITOR_LOCKER_ARGS(typeMapLock));
			HNType hType;
			NCheck(NObjectGetType(handle, &hType));
			try
			{
				FromHandleProc pFromHandle = NULL;
				do
				{
					N_HASH_MAP<HNType, FromHandleProc>::const_iterator t = typeMap.find(hType);
					if (t == typeMap.end())
					{
						HNType hBaseType;
						NCheck(NTypeGetBaseType(hType, &hBaseType));
						Unref(hType); hType = hBaseType;
						if (!hBaseType) break;
					}
					else pFromHandle = t->second;
				} while (!pFromHandle);
				if (!pFromHandle) NThrowInvalidOperationException(N_T("No types are registered yet for the specified handle type"));
				pObject = &dynamic_cast<T&>(*pFromHandle(handle));
				if (ownsHandle)
				{
					if ((pObject->state & (int)nosNative) == nosNative) NThrowInvalidOperationException(N_T("Native NObject can not own the handle"));
					if (!cache) pObject->state = (State)(pObject->state | nosOwnsHandle);
				}
				if (cache && (pObject->state & (int)nosNative) != nosNative)
				{
					try
					{
						NCheck(NObjectAddDisposedCallback(handle, OnDisposed, pObject));
						objectMap.insert(::std::pair<const HNObject, N_CLASS(NObject) *>(handle, pObject));
						pObject->state = (State)(pObject->state | nosRegistered);
						if (ownsHandle) Unref(handle);
					}
					catch (...)
					{
						delete (N_CLASS(NObject) *)pObject;
						throw;
					}
				}
				Unref(hType); hType = NULL;
			}
			catch (...)
			{
				Unref(hType);
				throw;
			}
		}
		else
		{
			if (ownsHandle) Unref(handle);
		}
		if (exitObjectMapLock) ::Neurotec::Threading::NExitMonitor(objectMapLock);
		return pObject;
	}
	catch (...)
	{
		if (exitObjectMapLock) ::Neurotec::Threading::NExitMonitor(objectMapLock);
		throw;
	}
}

template<typename T> inline typename T::HandleType N_CLASS(NObject)::ToHandle(const T * pObject, bool addRef)
{
	return !pObject ? NULL : addRef ? pObject->RefHandle() : pObject->GetHandle();
}

template<typename T> inline NInt N_CLASS(NObject)::ToHandleArray(T * const * arpObjects, NInt objectCount, typename T::HandleType * arhObjects, NInt objectsLength, bool addRef)
{
	if (!arpObjects && objectCount != 0) NThrowArgumentNullException(N_T("arpObjects"));
	if (objectCount < 0) NThrowArgumentLessThanZeroException(N_T("objectCount"));
	if (arhObjects)
	{
		if (objectsLength < objectCount) NThrowArgumentInsufficientException(N_T("objectsLength"));
		T * const * pObject = arpObjects;
		typename T::HandleType * phObject = arhObjects;
		NInt i = 0;
		try
		{
			for (; i < objectCount; i++, pObject++, phObject++)
			{
				if (!*pObject)
				{
					*phObject = NULL;
				}
				else
				{
					*phObject = addRef ? (*pObject)->RefHandle() : (*pObject)->GetHandle();
				}
			}
		}
		catch (...)
		{
			if (addRef)
			{
				for (; i >= 0; i--, phObject--)
				{
					Unref(*phObject);
				}
			}
			throw;
		}
	}
	return objectCount;
}

template<typename T> inline T * N_CLASS(NObject)::GetObject(NResult (N_CALLBACK pGetObject)(typename T::HandleType * phValue), bool ownsHandle, bool cache)
{
	typename T::HandleType hValue;
	NCheck(pGetObject(&hValue));
	try
	{
		return FromHandle<T>(hValue, ownsHandle, cache);
	}
	catch (...)
	{
		if (ownsHandle) Unref(hValue);
		throw;
	}
}

template<typename T> inline T * * N_CLASS(NObject)::GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * * parhValues, NInt * pValueCount), NInt * pCount, bool ownsHandles, bool cache)
{
	if (!pCount) NThrowArgumentNullException(N_T("pCount"));
	typename T::HandleType * arhValues = NULL;
	NInt valueCount = 0;
	NCheck(pGetObjects(&arhValues, &valueCount));
	try
	{
		N_CLASS(NObjectArray)<T> objects(arhValues, valueCount, true, ownsHandles, cache);
		arhValues = NULL; valueCount = 0;
		return objects.ToArray(pCount);
	}
	catch (...)
	{
		if (ownsHandles) UnrefArray(arhValues, valueCount);
		else NFree(arhValues);
		throw;
	}
}

template<typename T> inline NInt N_CLASS(NObject)::GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * arhValues, NInt valuesLength), T * * arpValues, NInt valuesLength, bool ownsHandles, bool cache)
{
	N_CLASS(NObjectArray)<T> objects(arpValues ? valuesLength : 0, ownsHandles, cache);
	NInt count = NCheck(pGetObjects(arpValues ? objects.GetPtr() : NULL, valuesLength));
	objects.CopyTo(arpValues, valuesLength, count);
	return count;
}

template<typename T> inline T * * N_CLASS(NObject)::GetObjects(NResult (N_CALLBACK pGetObjects)(typename T::HandleType * arhValues, NInt valuesLength), NInt * pCount, bool ownsHandles, bool cache)
{
	if (!pCount) NThrowArgumentNullException(N_T("pCount"));
	N_CLASS(NObjectArray)<T> objects(NCheck(pGetObjects(NULL, 0)), ownsHandles, cache);
	NInt count = NCheck(pGetObjects(objects.GetPtr(), objects.GetCount()));
	return objects.ToArray(count, pCount);
}

template<typename THandle> inline N_CLASS(NString) N_CLASS(NObject)::GetString(NResult (N_CALLBACK pGetString)(THandle handle, HNString * phValue)) const
{
	HNString hValue;
	NCheck(pGetString(static_cast<THandle>(GetHandle()), &hValue));
	return N_CLASS(NString)(hValue, true);
}

template<typename THandle> inline void N_CLASS(NObject)::SetString(NResult (N_CALLBACK pSetString)(THandle handle, HNString hValue), const N_CLASS(NStringWrapper) & value)
{
	NCheck(pSetString(static_cast<THandle>(GetHandle()), value.GetHandle()));
}

template<typename THandle, typename T> inline T * N_CLASS(NObject)::GetObject(NResult (N_CALLBACK pGetObject)(THandle handle, typename T::HandleType * phValue), bool ownsHandle, bool cache) const
{
	THandle hObj = static_cast<THandle>(GetHandle());
	typename T::HandleType hValue;
	NCheck(pGetObject(hObj, &hValue));
	try
	{
		return FromHandle<T>(hValue, ownsHandle, cache);
	}
	catch (...)
	{
		if (ownsHandle) Unref(hValue);
		throw;
	}
}

template<typename THandle, typename T> inline T * * N_CLASS(NObject)::GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * * parhValues, NInt * pValueCount), NInt * pCount, bool ownsHandles, bool cache) const
{
	if (!pCount) NThrowArgumentNullException(N_T("pCount"));
	THandle hObj = static_cast<THandle>(GetHandle());
	typename T::HandleType * arhValues = NULL;
	NInt valueCount = 0;
	NCheck(pGetObjects(hObj, &arhValues, &valueCount));
	try
	{
		N_CLASS(NObjectArray)<T> objects(arhValues, valueCount, true, ownsHandles, cache);
		arhValues = NULL; valueCount = 0;
		return objects.ToArray(pCount);
	}
	catch (...)
	{
		if (ownsHandles) UnrefArray(arhValues, valueCount);
		else NFree(arhValues);
		throw;
	}
}

template<typename THandle, typename T> inline NInt N_CLASS(NObject)::GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * arhValues, NInt valuesLength), T * * arpValues, NInt valuesLength, bool ownsHandles, bool cache) const
{
	THandle hObj = static_cast<THandle>(GetHandle());
	N_CLASS(NObjectArray)<T> objects(arpValues ? valuesLength : 0, ownsHandles, cache);
	NInt count = NCheck(pGetObjects(hObj, arpValues ? objects.GetPtr() : NULL, valuesLength));
	objects.CopyTo(arpValues, valuesLength, count);
	return count;
}

template<typename THandle, typename T> inline T * * N_CLASS(NObject)::GetObjects(NResult (N_CALLBACK pGetObjects)(THandle handle, typename T::HandleType * arhValues, NInt valuesLength), NInt * pCount, bool ownsHandles, bool cache) const
{
	if (!pCount) NThrowArgumentNullException(N_T("pCount"));
	THandle hObj = static_cast<THandle>(GetHandle());
	N_CLASS(NObjectArray)<T> objects(NCheck(pGetObjects(hObj, NULL, 0)), ownsHandles, cache);
	NInt count = NCheck(pGetObjects(hObj, objects.GetPtr(), objects.GetCount()));
	return objects.ToArray(count, pCount);
}

#include <NReDeprecate.h>

inline N_CLASS(NValue) * N_CLASS(NObject)::GetProperty(const N_CLASS(NStringWrapper) & name) const
{
	HNValue hValue;
	NCheck(NObjectGetPropertyN(GetHandle(), name.GetHandle(), &hValue));
	try
	{
		return FromHandle<N_CLASS(NValue)>(hValue);
	}
	catch (...)
	{
		Unref(hValue);
		throw;
	}
}

inline bool N_CLASS(NObject)::GetProperty(const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pValueType, NAttributes attributes, void * arValues, NSizeType valuesSize, NInt valuesLength) const
{
	if (!pValueType) NThrowArgumentNullException(N_T("pValueType"));
	NBool hasValue;
	NCheck(NObjectGetPropertyNN(GetHandle(), name.GetHandle(), pValueType->GetHandle(), attributes, arValues, valuesSize, valuesLength, &hasValue));
	return hasValue != 0;
}

template<typename T> inline T N_CLASS(NObject)::GetProperty(const N_CLASS(NStringWrapper) & name, NAttributes attributes, bool * pHasValue) const
{
	typename N_CLASS(NTypeTraits)<T>::NativeType value;
	NBool hasValue;
	NCheck(NObjectGetPropertyNN(GetHandle(), name.GetHandle(), N_CLASS(NTypeTraits)<T>::GetNativeType()->GetHandle(), attributes, &value, sizeof(value), 1, pHasValue ? &hasValue : NULL));
	try
	{
		T v = N_CLASS(NTypeTraits)<T>::FromNative(value);
		if (pHasValue) *pHasValue = hasValue != 0;
		return v;
	}
	catch (...)
	{
		N_CLASS(NTypeTraits)<T>::FreeNative(value);
		throw;
	}
}

template<typename T> inline T N_CLASS(NObject)::GetParameter(NUShort partId, NUShort parameterId) const
{
	typename N_CLASS(NTypeTraits)<T>::NativeType value;
	GetParameter(partId, parameterId, N_CLASS(NTypeTraits)<T>::TypeId, &value, sizeof(value));
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

inline void N_CLASS(NObject)::SetProperty(const N_CLASS(NStringWrapper) & name, N_CLASS(NValue) * pValue)
{
	NCheck(NObjectSetPropertyN(GetHandle(), name.GetHandle(), ToHandle(pValue)));
}

inline void N_CLASS(NObject)::SetProperty(const N_CLASS(NStringWrapper) & name, N_CLASS(NType) * pValueType, NAttributes attributes, const void * arValues, NSizeType valuesSize, NInt valuesLength, bool hasValue)
{
	if (!pValueType) NThrowArgumentNullException(N_T("pValueType"));
	NCheck(NObjectSetPropertyNN(GetHandle(), name.GetHandle(), pValueType->GetHandle(), attributes, arValues, valuesSize, valuesLength, hasValue ? NTrue : NFalse));
}

template<typename T> inline void N_CLASS(NObject)::SetProperty(const N_CLASS(NStringWrapper) & name, const T & value, NAttributes attributes, bool hasValue)
{
	typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
	NCheck(NObjectSetPropertyNN(GetHandle(), name.GetHandle(), N_CLASS(NTypeTraits)<T>::GetNativeType()->GetHandle(), attributes, &v, sizeof(v), 1, hasValue ? NTrue : NFalse));
}

template<typename T> inline void N_CLASS(NObject)::SetParameter(NUShort partId, NUShort parameterId, const T & value)
{
	typename N_CLASS(NTypeTraits)<T>::NativeType v = N_CLASS(NTypeTraits)<T>::ToNative(value);
	SetParameter(partId, parameterId, N_CLASS(NTypeTraits)<T>::TypeId, &v, sizeof(v));
}

}

#include <NBuffer.hpp>
#include <NStream.hpp>
#include <NCore.hpp>

namespace Neurotec
{
template<typename T> inline void N_CLASS(NObject)::SaveMany(T * const * arpObjects, NInt objectCount, ::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags)
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	N_CLASS(NObjectArray)<T> objects(arpObjects, objectCount);
	NCheck(NObjectSaveManyToStream(objects.GetPtr(), objects.GetCount(), pStream->GetHandle(), flags));
}

template<typename T> inline ::Neurotec::IO::N_CLASS(NBuffer) * N_CLASS(NObject)::SaveMany(T * const * arpObjects, NInt objectCount, NUInt flags)
{
	N_CLASS(NObjectArray)<T> objects(arpObjects, objectCount);
	HNBuffer hBuffer;
	NCheck(NObjectSaveManyToMemoryN(objects.GetPtr(), objects.GetCount(), flags, &hBuffer));
	try
	{
		return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
	}
	catch (...)
	{
		Unref(hBuffer);
		throw;
	}
}

template<typename T> inline NSizeType GetSizeMany(T * const * arpObjects, NInt objectCount, NUInt flags)
{
	N_CLASS(NObjectArray)<T> objects(arpObjects, objectCount);
	NSizeType size;
	NCheck(NObjectGetSizeMany(objects.GetPtr(), objects.GetCount(), flags, &size));
	return size;
}

template<typename T> inline NSizeType N_CLASS(NObject)::SaveMany(T * const * arpObjects, NInt objectCount, ::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags)
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	N_CLASS(NObjectArray)<T> objects(arpObjects, objectCount);
	NSizeType size;
	NCheck(NObjectSaveManyToMemoryDstN(objects.GetPtr(), objects.GetCount(), pBuffer->GetHandle(), flags, &size));
	return size;
}

template<typename T> inline NSizeType SaveMany(T * const * arpObjects, NInt objectCount, void * pBuffer, NSizeType bufferSize, NUInt flags)
{
	N_CLASS(NObjectArray)<T> objects(arpObjects, objectCount);
	NSizeType size;
	NCheck(NObjectSaveManyToMemoryDst(objects.GetPtr(), objects.GetCount(), pBuffer, bufferSize, flags, &size));
	return size;
}

inline void N_CLASS(NObject)::Save(::Neurotec::IO::N_CLASS(NStream) * pStream, NUInt flags) const
{
	if (!pStream) NThrowArgumentNullException(N_T("pStream"));
	NCheck(NObjectSaveToStream(GetHandle(), pStream->GetHandle(), flags));
}

inline ::Neurotec::IO::N_CLASS(NBuffer) * N_CLASS(NObject)::Save(NUInt flags) const
{
	HNBuffer hBuffer;
	NCheck(NObjectSaveToMemoryN(GetHandle(), flags, &hBuffer));
	try
	{
		return FromHandle< ::Neurotec::IO::N_CLASS(NBuffer)>(hBuffer);
	}
	catch (...)
	{
		Unref(hBuffer);
		throw;
	}
}

inline NSizeType N_CLASS(NObject)::Save(::Neurotec::IO::N_CLASS(NBuffer) * pBuffer, NUInt flags) const
{
	if (!pBuffer) NThrowArgumentNullException(N_T("pBuffer"));
	NSizeType size;
	NCheck(NObjectSaveToMemoryDstN(GetHandle(), pBuffer->GetHandle(), flags, &size));
	return size;
}

inline NResult N_API N_CLASS(NObject)::OnSyncChanging(HNObject, void * pParam)
{
	NResult result = N_OK;
	try
	{
		::Neurotec::Threading::N_CLASS(NSyncChangeObject) * p = reinterpret_cast< ::Neurotec::Threading::N_CLASS(NSyncChangeObject) *>(pParam);
		p->OnChanging();
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NObject)::OnSyncChanged(HNObject, void * pParam)
{
	NResult result = N_OK;
	try
	{
		::Neurotec::Threading::N_CLASS(NSyncChangeObject) * p = reinterpret_cast< ::Neurotec::Threading::N_CLASS(NSyncChangeObject) *>(pParam);
		p->OnChanged();
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NObject)::CallbackImpl(HNObject hObject, void * pParam)
{
	NResult result = N_OK;
	try
	{
		N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
		reinterpret_cast<Callback>(p->pCallback)(FromHandle<N_CLASS(NObject)>(hObject, false, true), p->pParam);
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline NResult N_API N_CLASS(NObject)::PropertyChangedCallbackImpl(HNObject hObject, HNString hPropertyName, void * pParam)
{
	NResult result = N_OK;
	try
	{
		N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
		reinterpret_cast<PropertyChangedCallback>(p->pCallback)(FromHandle<N_CLASS(NObject)>(hObject, false, true), N_CLASS(NString)(hPropertyName, false), p->pParam);
	}
	N_EXCEPTION_CATCH_AND_SET_LAST(result);
	return result;
}

inline void N_CLASS(NObject)::Uninit()
{
	if ((state & nosRegistered) == nosRegistered)
	{
		::Neurotec::Threading::NMonitorLockerType objectMapLocker(N_MONITOR_LOCKER_ARGS(objectMapLock));
		objectMap.erase(handle);
		state = (State)(state & ~nosRegistered);
	}
	if ((state & (int)nosNativeAllocated) == nosNativeAllocated)
	{
		state = (State)(state & ~nosNativeAllocated);
		if ((state & (int)nosOwnsHandle) == nosOwnsHandle)
		{
			NCheck(NObjectUnref(handle));
		}
		else if ((state & (int)nosNative) != nosNative)
		{
			NCheck(NObjectRemoveDisposedCallback(handle, OnDisposed, this));
		}
	}
}

inline N_CLASS(NType) * N_CLASS(NObject)::GetNativeType() const
{
	return GetObject<HandleType, N_CLASS(NType)>(NObjectGetType, true, true);
}
}

#endif // !N_OBJECT_HPP_INCLUDED
