#include "stdafx.h"

#ifndef DLL_FILE
 #define DLL_FILE
#endif

#include "FileOP.h"

//删除文件或者文件夹
int CFileOP::DeleteFile(TCHAR *FromPath, BOOL bRecycle)
{
	SHFILEOPSTRUCT FileOp={0};

	if(bRecycle)
		FileOp.fFlags |= FOF_ALLOWUNDO; //允许放回回收站
	FileOp.pFrom = FromPath;
	FileOp.pTo = NULL; //一定要是NULL
	FileOp.wFunc = FO_DELETE; //删除操作
	return SHFileOperation(&FileOp) ;
}

//复制文件或文件夹
bool CFileOP::CopyFile(TCHAR* To,TCHAR* From)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags |= FOF_NOCONFIRMATION; //不出现确认对话框
	//FOF_NOCONFIRMMKDIR ; //需要时直接创建一个文件夹,不需用户确定
	FileOp.pFrom = From;
	FileOp.pTo = To;
	FileOp.wFunc = FO_COPY;
	return SHFileOperation(&FileOp) == 0;
}

//移动文件或文件夹
bool CFileOP::MoveFile(TCHAR* To,TCHAR* From)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags |= FOF_NOCONFIRMATION; //不出现确认对话框
	//FOF_NOCONFIRMMKDIR ; //需要时直接创建一个文件夹,不需用户确定
	FileOp.pFrom = From;
	FileOp.pTo = To;
	FileOp.wFunc = FO_MOVE;
	return SHFileOperation(&FileOp) == 0; 
}


//重命名文件或文件夹
bool CFileOP::ReNameFile(TCHAR* To,TCHAR* From)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags = FOF_NOCONFIRMATION; //不出现确认对话框
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
