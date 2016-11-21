// dllmain.h : Declaration of module class.
//#include "IFileManagerCOM_i.c"

class CIFileManagerCOMModule : public ATL::CAtlDllModuleT< CIFileManagerCOMModule >
{
public :
	DECLARE_LIBID(LIBID_IFileManagerCOMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IFILEMANAGERCOM, "{76424BC9-15E2-46BD-BA51-EDBD453627FE}")
};

extern class CIFileManagerCOMModule _AtlModule;
