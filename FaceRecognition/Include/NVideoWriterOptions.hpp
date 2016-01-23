#ifndef N_VIDEO_WRITER_OPTIONS_HPP_INCLUDED
#define N_VIDEO_WRITER_OPTIONS_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Video
{
#include <NVideoWriterOptions.h>
}}

#if defined(N_FRAMEWORK_WX)
#include <wx/window.h>
#elif defined(N_FRAMEWORK_MFC)
#include <afxwin.h>
#endif

namespace Neurotec { namespace Video
{

class N_CLASS(NVideoWriterOptions) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NVideoWriterOptions, NObject)

private:
	static HNVideoWriterOptions Create(NHandle hParent)
	{
		HNVideoWriterOptions handle;
		NCheck(NVideoWriterOptionsCreateWithGui(hParent, &handle));
		return handle;
	}

#if defined(N_FRAMEWORK_WX)
	static HNVideoWriterOptions Create(const wxWindow * pParent)
	{
		if (!pParent) NThrowArgumentNullException(N_T("pParent"));
		return Create((NHandle)pParent->GetHandle());
	}
#elif defined(N_FRAMEWORK_MFC)
	static HNVideoWriterOptions Create(const CWnd * pParent)
	{
		if (!pParent) NThrowArgumentNullException(N_T("pParent"));
		return Create((NHandle)pParent->GetSafeHwnd());
	}
#endif

	N_CLASS(NVideoWriterOptions)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
#ifdef N_WINDOWS
	N_CLASS(NVideoWriterOptions)(HWND parent)
		: N_CLASS(NObject)(Create((NHandle)parent), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NVideoWriterOptions);
	}
#endif

#if defined(N_FRAMEWORK_WX)
	N_CLASS(NVideoWriterOptions)(const wxWindow * pParent)
		: N_CLASS(NObject)(Create(pParent), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NVideoWriterOptions);
	}
#elif defined(N_FRAMEWORK_MFC)
	N_CLASS(NVideoWriterOptions)(const CWnd * pParent)
		: N_CLASS(NObject)(Create(pParent), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NVideoWriterOptions);
	}
#endif
};

}}

#endif // !N_VIDEO_WRITER_OPTIONS_HPP_INCLUDED
