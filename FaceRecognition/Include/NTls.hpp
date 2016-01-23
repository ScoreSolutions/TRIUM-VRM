#ifndef N_TLS_HPP_INCLUDED
#define N_TLS_HPP_INCLUDED

#include <NObject.hpp>
namespace Neurotec { namespace Threading
{
#include <NTls.h>
}}

namespace Neurotec { namespace Threading
{

class N_CLASS(NTls) : public N_CLASS(NObjectBase)
{
private:
	static HNTls Create(NTlsDisposeProc pDispose)
	{
		HNTls hTls;
		NCheck(NTlsCreate(pDispose, &hTls));
		return hTls;
	}

	static HNTls Create()
	{
		HNTls hTls;
		NCheck(NTlsCreateForObject(&hTls));
		return hTls;
	}

	HNTls handle;
	NBool ownsHandle;

public:
	explicit N_CLASS(NTls)(HNTls handle, bool ownsHandle = true)
		: handle(handle), ownsHandle(ownsHandle)
	{
		if (!handle) NThrowArgumentNullException(N_T("handle"));
	}

	explicit N_CLASS(NTls)(NTlsDisposeProc pDispose)
		: handle(Create(pDispose)), ownsHandle(true)
	{
	}

	explicit N_CLASS(NTls)()
		: handle(Create()), ownsHandle(true)
	{
	}

	~N_CLASS(NTls)()
	{
		if (ownsHandle && handle != NULL) NCheck(NTlsFree(handle));
	}

	HNTls GetHandle() const
	{
		return handle;
	}

	void * GetValue() const
	{
		void * pValue;
		NCheck(NTlsGetValue(GetHandle(), &pValue));
		return pValue;
	}

	void SetValue(void * pValue)
	{
		NCheck(NTlsSetValue(GetHandle(), pValue));
	}

	template<typename T> T * GetObject() const;

	void SetObject(N_CLASS(NObject) * pValue)
	{
		NCheck(NTlsSetObject(GetHandle(), N_CLASS(NObject)::ToHandle(pValue)));
	}

	N_DECLARE_CLASS(NTls)
};

template<typename T> inline T * N_CLASS(NTls)::GetObject() const
{
	HNObject hValue;
	NCheck(NTlsGetObject(GetHandle(), &hValue));
	try
	{
		return N_CLASS(NObject)::FromHandle<T>(hValue, true, true);
	}
	catch (...)
	{
		N_CLASS(NObject)::Unref(hValue);
		throw;
	}
}

}}

#endif // !N_TLS_HPP_INCLUDED
