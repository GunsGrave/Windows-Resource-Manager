// SystemImageList.h: interface for the CSystemImageList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "myexplorer.h"
#if !defined(AFX_SYSTEMIMAGELIST_H__E7D7D558_317F_4D99_9AC9_3E90BD1447B6__INCLUDED_)
#define AFX_SYSTEMIMAGELIST_H__E7D7D558_317F_4D99_9AC9_3E90BD1447B6__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef DLL_FILE
#define TEST_API __declspec(dllexport)
#else
#define TEST_API __declspec(dllimport)
#endif

class TEST_API CSystemImageList : public CObject  
{
public:
	CSystemImageList();
	virtual ~CSystemImageList();
	//得到图标链表      
	CImageList * GetImageList( BOOL bSmall = TRUE ) const;     
	//得到指定文件的图标      
	HICON GetIcon( const CString& sName, BOOL bOpen = FALSE, BOOL bSmall = TRUE ) ; 

private:      		
	static CImageList * m_gpLargeImageList; //大图标链表				  		
	static CImageList * m_gpSmallImageList; //小图标链表        		
	static int m_gRefCount; //计数器  
private:      		  		
	//初始化静态列表      		
	BOOL InitGlobalList( CImageList *& rpImageList, BOOL bSmall = TRUE );     	
	//销毁静态链表	
	void DestroyGlobalList( CImageList *& rpImageList );
};

#endif // !defined(AFX_SYSTEMIMAGELIST_H__E7D7D558_317F_4D99_9AC9_3E90BD1447B6__INCLUDED_)
