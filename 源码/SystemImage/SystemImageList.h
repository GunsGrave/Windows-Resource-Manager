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
	//�õ�ͼ������      
	CImageList * GetImageList( BOOL bSmall = TRUE ) const;     
	//�õ�ָ���ļ���ͼ��      
	HICON GetIcon( const CString& sName, BOOL bOpen = FALSE, BOOL bSmall = TRUE ) ; 

private:      		
	static CImageList * m_gpLargeImageList; //��ͼ������				  		
	static CImageList * m_gpSmallImageList; //Сͼ������        		
	static int m_gRefCount; //������  
private:      		  		
	//��ʼ����̬�б�      		
	BOOL InitGlobalList( CImageList *& rpImageList, BOOL bSmall = TRUE );     	
	//���پ�̬����	
	void DestroyGlobalList( CImageList *& rpImageList );
};

#endif // !defined(AFX_SYSTEMIMAGELIST_H__E7D7D558_317F_4D99_9AC9_3E90BD1447B6__INCLUDED_)
