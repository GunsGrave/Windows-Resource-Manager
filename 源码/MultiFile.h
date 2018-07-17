#pragma once

#ifdef DLL_FILE
#define TEST_API __declspec(dllexport)
#else
#define TEST_API __declspec(dllimport)
#endif

#define MAX_PATH_LEN 10000

class TEST_API CMultiFile
{
public:
	CMultiFile();
	void AddFile(CString path);
	TCHAR* GetPath();
	CString GetCStringPath();
	int GetCount();
	void Reset();
private:
	TCHAR FilePath[MAX_PATH_LEN];
	TCHAR* ptr;
	int count;
};
