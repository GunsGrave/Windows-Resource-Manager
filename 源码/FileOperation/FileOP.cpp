#include "stdafx.h"

#ifndef DLL_FILE
 #define DLL_FILE
#endif

#include "FileOP.h"

//ɾ���ļ������ļ���
int CFileOP::DeleteFile(TCHAR *FromPath, BOOL bRecycle)
{
	SHFILEOPSTRUCT FileOp={0};

	if(bRecycle)
		FileOp.fFlags |= FOF_ALLOWUNDO; //����Żػ���վ
	FileOp.pFrom = FromPath;
	FileOp.pTo = NULL; //һ��Ҫ��NULL
	FileOp.wFunc = FO_DELETE; //ɾ������
	return SHFileOperation(&FileOp) ;
}

//�����ļ����ļ���
bool CFileOP::CopyFile(TCHAR* To,TCHAR* From)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags |= FOF_NOCONFIRMATION; //������ȷ�϶Ի���
	//FOF_NOCONFIRMMKDIR ; //��Ҫʱֱ�Ӵ���һ���ļ���,�����û�ȷ��
	FileOp.pFrom = From;
	FileOp.pTo = To;
	FileOp.wFunc = FO_COPY;
	return SHFileOperation(&FileOp) == 0;
}

//�ƶ��ļ����ļ���
bool CFileOP::MoveFile(TCHAR* To,TCHAR* From)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags |= FOF_NOCONFIRMATION; //������ȷ�϶Ի���
	//FOF_NOCONFIRMMKDIR ; //��Ҫʱֱ�Ӵ���һ���ļ���,�����û�ȷ��
	FileOp.pFrom = From;
	FileOp.pTo = To;
	FileOp.wFunc = FO_MOVE;
	return SHFileOperation(&FileOp) == 0; 
}


//�������ļ����ļ���
bool CFileOP::ReNameFile(TCHAR* To,TCHAR* From)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags = FOF_NOCONFIRMATION; //������ȷ�϶Ի���
	FileOp.pFrom = From;
	FileOp.pTo = To;
	FileOp.wFunc = FO_RENAME;
	return SHFileOperation(&FileOp) == 0; 
}

BOOL CFileOP::TypeOf(CString path)
{
	CFileFind finder;
	if(finder.FindFile(path))
	{
		finder.FindNextFile();
		if(finder.IsDots())
			return 3;
		if(finder.IsDirectory())
			return 1;
		return 2;
	}
	else return 0;
}
