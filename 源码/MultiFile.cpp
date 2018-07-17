#include "stdafx.h"
/*#include "MultiFile.h"

CMultiFile::CMultiFile()
{
	Reset();
}

void CMultiFile::Reset()
{
	count=0;
	memset(FilePath, 0, sizeof(FilePath));
	ptr=FilePath;
}

void CMultiFile::AddFile(CString path)
{
	++count;
	lstrcpy(ptr,path);
	ptr+=lstrlen(ptr)+1;
}

TCHAR* CMultiFile::GetPath()
{
	return FilePath;
}

CString CMultiFile::GetCStringPath()
{
	CString s;
	s.Format(_T("%s"),FilePath);
	return s;
}

int CMultiFile::GetCount()
{
	return count;
}*/