#ifndef N_VIRTUAL_DEVICE_HPP_INCLUDED
#define N_VIRTUAL_DEVICE_HPP_INCLUDED

#include <NCore.hpp>
#include <NBiometricTypes.hpp>
#include <NVideoFormat.hpp>
#include <NAudioFormat.hpp>
#include <NDevices.hpp>

namespace Neurotec { namespace Devices { namespace Virtual
{
using Neurotec::Biometrics::NFImpressionType;
using Neurotec::Biometrics::NFPosition;
using Neurotec::Biometrics::NEPosition;
using Neurotec::Media::HNMediaFormat;
using Neurotec::Media::HNVideoFormat;
using Neurotec::Media::HNAudioFormat;
#include <NVirtualDevice.h>
}}}

namespace Neurotec { namespace Devices { namespace Virtual
{

class N_CLASS(NVirtualDevice) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NVirtualDevice, NObject)

private:
	N_CLASS(NVirtualDevice)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
		Init();
	}

	static HNVirtualDevice Create()
	{
		HNVirtualDevice handle;
		NCheck(NVirtualDeviceCreate(&handle));
		return handle;
	}

public:
	class SourceCollection : public ::Neurotec::Collections::N_CLASS(NStringCollection)<N_CLASS(NVirtualDevice)>
	{
		SourceCollection(N_CLASS(NVirtualDevice) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NStringCollection)<N_CLASS(NVirtualDevice)>(pOwner)
		{
		}

	protected:
		virtual bool SupportsAddWithOutIndex() const
		{
			return true;
		}

		virtual NResult GetCountNative(HNVirtualDevice handle, NInt * pValue) const
		{
			return NVirtualDeviceGetSourceCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNVirtualDevice, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNVirtualDevice, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNVirtualDevice handle, NInt index, HNString * phValue) const
		{
			return NVirtualDeviceGetSource(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNVirtualDevice, HNString *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNVirtualDevice handle, NInt index, HNString hValue)
		{
			return NVirtualDeviceSetSourceN(handle, index, hValue);
		}

		virtual NResult AddNative(HNVirtualDevice, HNString)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNVirtualDevice handle, HNString hValue, NInt * pIndex)
		{
			return NVirtualDeviceAddSourceN(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNVirtualDevice handle, NInt index, HNString hValue)
		{
			return NVirtualDeviceInsertSourceN(handle, index, hValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNVirtualDevice, HNString, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNVirtualDevice handle, NInt index)
		{
			return NVirtualDeviceRemoveSource(handle, index);
		}

		virtual NResult RemoveRangeNative(HNVirtualDevice, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNVirtualDevice handle)
		{
			return NVirtualDeviceClearSources(handle);
		}

		friend class N_CLASS(NVirtualDevice);
	};

	class VideoFormatCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::Media::N_CLASS(NVideoFormat), N_CLASS(NVirtualDevice)>
	{
		VideoFormatCollection(N_CLASS(NVirtualDevice) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::Media::N_CLASS(NVideoFormat), N_CLASS(NVirtualDevice)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNVirtualDevice handle, NInt * pValue) const
		{
			return NVirtualDeviceGetVideoFormatCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNVirtualDevice, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNVirtualDevice, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNVirtualDevice handle, NInt index, HNVideoFormat * phValue) const
		{
			return NVirtualDeviceGetVideoFormat(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNVirtualDevice, HNVideoFormat *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNVirtualDevice handle, NInt index, HNVideoFormat hValue)
		{
			return NVirtualDeviceSetVideoFormat(handle, index, hValue);
		}

		virtual NResult AddNative(HNVirtualDevice, HNVideoFormat)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNVirtualDevice handle, HNVideoFormat hValue, NInt * pIndex)
		{
			return NVirtualDeviceAddVideoFormat(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNVirtualDevice handle, NInt index, HNVideoFormat hValue)
		{
			return NVirtualDeviceInsertVideoFormat(handle, index, hValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNVirtualDevice, HNVideoFormat, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNVirtualDevice handle, NInt index)
		{
			return NVirtualDeviceRemoveVideoFormat(handle, index);
		}

		virtual NResult RemoveRangeNative(HNVirtualDevice, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNVirtualDevice handle)
		{
			return NVirtualDeviceClearVideoFormats(handle);
		}

		friend class N_CLASS(NVirtualDevice);
	};

	class AudioFormatCollection : public ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::Media::N_CLASS(NAudioFormat), N_CLASS(NVirtualDevice)>
	{
		AudioFormatCollection(N_CLASS(NVirtualDevice) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NObjectCollection)< ::Neurotec::Media::N_CLASS(NAudioFormat), N_CLASS(NVirtualDevice)>(pOwner)
		{
		}

	protected:
		virtual NResult GetCountNative(HNVirtualDevice handle, NInt * pValue) const
		{
			return NVirtualDeviceGetAudioFormatCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNVirtualDevice, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNVirtualDevice, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNVirtualDevice handle, NInt index, HNAudioFormat * phValue) const
		{
			return NVirtualDeviceGetAudioFormat(handle, index, phValue);
		}

		virtual NResult GetAllNative(HNVirtualDevice, HNAudioFormat *, NInt) const
		{
			NThrowNotImplementedException();
		}

		virtual NResult SetNative(HNVirtualDevice handle, NInt index, HNAudioFormat hValue)
		{
			return NVirtualDeviceSetAudioFormat(handle, index, hValue);
		}

		virtual NResult AddNative(HNVirtualDevice, HNAudioFormat)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNVirtualDevice handle, HNAudioFormat hValue, NInt * pIndex)
		{
			return NVirtualDeviceAddAudioFormat(handle, hValue, pIndex);
		}

		virtual NResult InsertNative(HNVirtualDevice handle, NInt index, HNAudioFormat hValue)
		{
			return NVirtualDeviceInsertAudioFormat(handle, index, hValue);
		}

		virtual NResult RemoveWithOutIndexNative(HNVirtualDevice, HNAudioFormat, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNVirtualDevice handle, NInt index)
		{
			return NVirtualDeviceRemoveAudioFormat(handle, index);
		}

		virtual NResult RemoveRangeNative(HNVirtualDevice, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNVirtualDevice handle)
		{
			return NVirtualDeviceClearAudioFormats(handle);
		}

		friend class N_CLASS(NVirtualDevice);
	};

	class ImpressionTypeCollection : public ::Neurotec::Collections::N_CLASS(NValueCollection)<NFImpressionType, N_CLASS(NVirtualDevice)>
	{
		ImpressionTypeCollection(N_CLASS(NVirtualDevice) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NValueCollection)<NFImpressionType, N_CLASS(NVirtualDevice)>(pOwner)
		{
		}

	protected:
		virtual bool SupportsAddWithOutIndex() const
		{
			return true;
		}

		virtual NResult GetCountNative(HNVirtualDevice handle, NInt * pValue) const
		{
			return NVirtualDeviceGetSupportedImpressionTypeCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNVirtualDevice, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNVirtualDevice, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNVirtualDevice handle, NInt index, NFImpressionType * pValue) const
		{
			return NVirtualDeviceGetSupportedImpressionType(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNVirtualDevice handle, NFImpressionType * arValues, NInt valuesLength) const
		{
			return NVirtualDeviceGetSupportedImpressionTypes(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNVirtualDevice handle, NInt index, NFImpressionType value)
		{
			return NVirtualDeviceSetSupportedImpressionType(handle, index, value);
		}

		virtual NResult AddNative(HNVirtualDevice, NFImpressionType)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNVirtualDevice handle, NFImpressionType value, NInt * pIndex)
		{
			return NVirtualDeviceAddSupportedImpressionType(handle, value, pIndex);
		}

		virtual NResult InsertNative(HNVirtualDevice handle, NInt index, NFImpressionType value)
		{
			return NVirtualDeviceInsertSupportedImpressionType(handle, index, value);
		}

		virtual NResult RemoveWithOutIndexNative(HNVirtualDevice, NFImpressionType, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNVirtualDevice handle, NInt index)
		{
			return NVirtualDeviceRemoveSupportedImpressionType(handle, index);
		}

		virtual NResult RemoveRangeNative(HNVirtualDevice, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNVirtualDevice handle)
		{
			return NVirtualDeviceClearSupportedImpressionTypes(handle);
		}

		friend class N_CLASS(NVirtualDevice);
	};

	class FingerPositionCollection : public ::Neurotec::Collections::N_CLASS(NValueCollection)<NFPosition, N_CLASS(NVirtualDevice)>
	{
		FingerPositionCollection(N_CLASS(NVirtualDevice) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NValueCollection)<NFPosition, N_CLASS(NVirtualDevice)>(pOwner)
		{
		}

	protected:
		virtual bool SupportsAddWithOutIndex() const
		{
			return true;
		}

		virtual NResult GetCountNative(HNVirtualDevice handle, NInt * pValue) const
		{
			return NVirtualDeviceGetSupportedFingerPositionCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNVirtualDevice, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNVirtualDevice, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNVirtualDevice handle, NInt index, NFPosition * pValue) const
		{
			return NVirtualDeviceGetSupportedFingerPosition(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNVirtualDevice handle, NFPosition * arValues, NInt valuesLength) const
		{
			return NVirtualDeviceGetSupportedFingerPositions(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNVirtualDevice handle, NInt index, NFPosition value)
		{
			return NVirtualDeviceSetSupportedFingerPosition(handle, index, value);
		}

		virtual NResult AddNative(HNVirtualDevice, NFPosition)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNVirtualDevice handle, NFPosition value, NInt * pIndex)
		{
			return NVirtualDeviceAddSupportedFingerPosition(handle, value, pIndex);
		}

		virtual NResult InsertNative(HNVirtualDevice handle, NInt index, NFPosition value)
		{
			return NVirtualDeviceInsertSupportedFingerPosition(handle, index, value);
		}

		virtual NResult RemoveWithOutIndexNative(HNVirtualDevice, NFPosition, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNVirtualDevice handle, NInt index)
		{
			return NVirtualDeviceRemoveSupportedFingerPosition(handle, index);
		}

		virtual NResult RemoveRangeNative(HNVirtualDevice, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNVirtualDevice handle)
		{
			return NVirtualDeviceClearSupportedFingerPositions(handle);
		}

		friend class N_CLASS(NVirtualDevice);
	};

	class IrisPositionCollection : public ::Neurotec::Collections::N_CLASS(NValueCollection)<NEPosition, N_CLASS(NVirtualDevice)>
	{
		IrisPositionCollection(N_CLASS(NVirtualDevice) * pOwner)
			: ::Neurotec::Collections::N_CLASS(NValueCollection)<NEPosition, N_CLASS(NVirtualDevice)>(pOwner)
		{
		}

	protected:
		virtual bool SupportsAddWithOutIndex() const
		{
			return true;
		}

		virtual NResult GetCountNative(HNVirtualDevice handle, NInt * pValue) const
		{
			return NVirtualDeviceGetSupportedIrisPositionCount(handle, pValue);
		}

		virtual NResult GetCapacityNative(HNVirtualDevice, NInt *) const
		{
			NThrowNotSupportedException();
		}

		virtual NResult SetCapacityNative(HNVirtualDevice, NInt)
		{
			NThrowNotSupportedException();
		}

		virtual NResult GetNative(HNVirtualDevice handle, NInt index, NEPosition * pValue) const
		{
			return NVirtualDeviceGetSupportedIrisPosition(handle, index, pValue);
		}

		virtual NResult GetAllNative(HNVirtualDevice handle, NEPosition * arValues, NInt valuesLength) const
		{
			return NVirtualDeviceGetSupportedIrisPositions(handle, arValues, valuesLength);
		}

		virtual NResult SetNative(HNVirtualDevice handle, NInt index, NEPosition value)
		{
			return NVirtualDeviceSetSupportedIrisPosition(handle, index, value);
		}

		virtual NResult AddNative(HNVirtualDevice, NEPosition)
		{
			NThrowNotImplementedException();
		}

		virtual NResult AddWithOutIndexNative(HNVirtualDevice handle, NEPosition value, NInt * pIndex)
		{
			return NVirtualDeviceAddSupportedIrisPosition(handle, value, pIndex);
		}

		virtual NResult InsertNative(HNVirtualDevice handle, NInt index, NEPosition value)
		{
			return NVirtualDeviceInsertSupportedIrisPosition(handle, index, value);
		}

		virtual NResult RemoveWithOutIndexNative(HNVirtualDevice, NEPosition, NInt *)
		{
			NThrowNotImplementedException();
		}

		virtual NResult RemoveAtNative(HNVirtualDevice handle, NInt index)
		{
			return NVirtualDeviceRemoveSupportedIrisPosition(handle, index);
		}

		virtual NResult RemoveRangeNative(HNVirtualDevice, NInt, NInt)
		{
			NThrowNotImplementedException();
		}

		virtual NResult ClearNative(HNVirtualDevice handle)
		{
			return NVirtualDeviceClearSupportedIrisPositions(handle);
		}

		friend class N_CLASS(NVirtualDevice);
	};

private:
	::std::auto_ptr<SourceCollection> sources;
	::std::auto_ptr<VideoFormatCollection> videoFormats;
	::std::auto_ptr<AudioFormatCollection> audioFormats;
	::std::auto_ptr<ImpressionTypeCollection> impressionTypes;
	::std::auto_ptr<FingerPositionCollection> fingerPositions;
	::std::auto_ptr<IrisPositionCollection> irisPositions;

	void Init()
	{
		sources.reset(new SourceCollection(this));
		videoFormats.reset(new VideoFormatCollection(this));
		audioFormats.reset(new AudioFormatCollection(this));
		impressionTypes.reset(new ImpressionTypeCollection(this));
		fingerPositions.reset(new FingerPositionCollection(this));
		irisPositions.reset(new IrisPositionCollection(this));
	}

public:
	static N_CLASS(NType) * NVirtualDeviceOptionsNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NVirtualDeviceOptions), true, true);
	}

	N_CLASS(NVirtualDevice)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NVirtualDevice);
		Init();
	}

	NDeviceType GetDeviceType() const
	{
		NDeviceType value;
		NCheck(NVirtualDeviceGetDeviceType(GetHandle(), &value));
		return value;
	}

	void SetDeviceType(NDeviceType value)
	{
		NCheck(NVirtualDeviceSetDeviceType(GetHandle(), value));
	}

	N_CLASS(NString) GetDisplayName() const
	{
		HNString hValue;
		NCheck(NVirtualDeviceGetDisplayName(GetHandle(), &hValue));
		return N_CLASS(NString)(hValue, true);
	}

	void SetDisplayName(const N_CLASS(NStringWrapper) & value)
	{
		NCheck(NVirtualDeviceSetDisplayName(GetHandle(), value.GetHandle()));
	}

	::Neurotec::Media::N_CLASS(NMediaFormat) * GetCurrentFormat() const
	{
		return GetObject<HandleType, ::Neurotec::Media::N_CLASS(NMediaFormat)>(NVirtualDeviceGetCurrentFormat);
	}

	void SetCurrentFormat(::Neurotec::Media::N_CLASS(NMediaFormat) * pValue)
	{
		NCheck(NVirtualDeviceSetCurrentFormat(GetHandle(), ToHandle(pValue)));
	}

	NVirtualDeviceOptions GetOptions() const
	{
		NVirtualDeviceOptions value;
		NCheck(NVirtualDeviceGetOptions(GetHandle(), &value));
		return value;
	}

	void SetOptions(NVirtualDeviceOptions value)
	{
		NCheck(NVirtualDeviceSetOptions(GetHandle(), value));
	}

	bool GetIsPluggedIn() const
	{
		NBool value;
		NCheck(NVirtualDeviceGetIsPluggedIn(GetHandle(), &value));
		return value != 0;
	}

	void SetIsPluggedIn(bool value)
	{
		NCheck(NVirtualDeviceSetIsPluggedIn(GetHandle(), value ? NTrue : NFalse));
	}

	SourceCollection * GetSources()
	{
		return sources.get();
	}

	VideoFormatCollection * GetVideoFormats()
	{
		return videoFormats.get();
	}

	AudioFormatCollection * GetAudioFormats()
	{
		return audioFormats.get();
	}

	ImpressionTypeCollection * GetImpressionTypes()
	{
		return impressionTypes.get();
	}

	FingerPositionCollection * GetFingerPositions()
	{
		return fingerPositions.get();
	}

	IrisPositionCollection * GetIrisPositions()
	{
		return irisPositions.get();
	}
};

}}}

#endif //!N_VIRTUAL_DEVICE_HPP_INCLUDED
