#pragma once


#ifdef DLL_FILE
#define TEST_API __declspec(dllexport)
#else
#define TEST_API __declspec(dllimport)
#endif


class TEST_API CFileOP
{
public:
	static int DeleteFile(TCHAR *FromPath, BOOL bRecycle=FALSE);
	static bool CopyFile(TCHAR* To,TCHAR* From);
	static bool MoveFile(TCHAR* To,TCHAR* From);
	static bool ReNameFile(TCHAR* To,TCHAR* From);

	static BOOL TypeOf(CString path);//0:do not exists,1:dir,2:file,3:dots
};
