#ifndef N_LIBRARY_INFO_H_INCLUDED
#define N_LIBRARY_INFO_H_INCLUDED

#include <NTypes.h>
#include <NError.h>

#ifdef N_CPP
extern "C"
{
#endif

#define N_LI_TITLE_MAX_LENGTH     128
#define N_LI_PRODUCT_MAX_LENGTH   128
#define N_LI_COMPANY_MAX_LENGTH    64
#define N_LI_COPYRIGHT_MAX_LENGTH 192
#define N_LI_ACTIVATED_MAX_LENGTH 256

#ifndef N_NO_ANSI_FUNC
typedef struct NLibraryInfoA_
{
	NAChar Title[N_LI_TITLE_MAX_LENGTH];
	NAChar Product[N_LI_PRODUCT_MAX_LENGTH];
	NAChar Company[N_LI_COMPANY_MAX_LENGTH];
	NAChar Copyright[N_LI_COPYRIGHT_MAX_LENGTH];
	NInt VersionMajor;
	NInt VersionMinor;
	NInt VersionBuild;
	NInt VersionRevision;
	NAChar Activated[N_LI_ACTIVATED_MAX_LENGTH];
} NLibraryInfoA;
#endif
#ifndef N_NO_UNICODE
typedef struct NLibraryInfoW_
{
	NWChar Title[N_LI_TITLE_MAX_LENGTH];
	NWChar Product[N_LI_PRODUCT_MAX_LENGTH];
	NWChar Company[N_LI_COMPANY_MAX_LENGTH];
	NWChar Copyright[N_LI_COPYRIGHT_MAX_LENGTH];
	NInt VersionMajor;
	NInt VersionMinor;
	NInt VersionBuild;
	NInt VersionRevision;
	NWChar Activated[N_LI_ACTIVATED_MAX_LENGTH];
} NLibraryInfoW;
#endif
#ifdef N_DOCUMENTATION
typedef struct NLibraryInfo_
{
	NChar Title[N_LI_TITLE_MAX_LENGTH];
	NChar Product[N_LI_PRODUCT_MAX_LENGTH];
	NChar Company[N_LI_COMPANY_MAX_LENGTH];
	NChar Copyright[N_LI_COPYRIGHT_MAX_LENGTH];
	NInt VersionMajor;
	NInt VersionMinor;
	NInt VersionBuild;
	NInt VersionRevision;
	NChar Activated[N_LI_ACTIVATED_MAX_LENGTH];
} NLibraryInfo;
#endif
#define NLibraryInfo N_STRUCT_AW(NLibraryInfo)

#ifdef N_CPP
}
#endif

#endif // !N_LIBRARY_INFO_H_INCLUDED
