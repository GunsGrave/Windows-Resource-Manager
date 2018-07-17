// SystemImageList.cpp: implementation of the CSystemImageList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#ifndef DLL_FILE
 #define DLL_FILE
#endif


//#include "myexplorer.h"
#include "SystemImageList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#ifndef DLL_FILE
 #define DLL_FILE
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSystemImageList::CSystemImageList()
{
	if( m_gRefCount == 0 ) //���Ǽ�����Ϊ0��˵����δ��ʼ��    
	{   
		ASSERT( ! m_gpSmallImageList && ! m_gpLargeImageList );     
		InitGlobalList( m_gpSmallImageList, TRUE ); //��ʼ��Сͼ������   
		InitGlobalList( m_gpLargeImageList, FALSE );  //��ʼ����ͼ������      
	}        
	m_gRefCount ++; //��������1 
}

CSystemImageList::~CSystemImageList()
{
	m_gRefCount--; //����������1    
	if( m_gRefCount == 0 ) //���CSystemImageList��Ķ����Ѿ�ȫ��������    
	{   DestroyGlobalList( m_gpLargeImageList ); //���ٴ�ͼ������  
	DestroyGlobalList( m_gpSmallImageList ); //����Сͼ������     
	} 
}

	CImageList * CSystemImageList::m_gpLargeImageList; //��ͼ������				  		
	CImageList * CSystemImageList::m_gpSmallImageList; //Сͼ������        		
	int CSystemImageList::m_gRefCount;
//��ʼ������  
BOOL CSystemImageList::InitGlobalList( CImageList *& rpImageList, BOOL bSmall  ) 
{      
	BOOL bRet = FALSE;       
	if( ! rpImageList )  //�������Ϊ��     
	{
		rpImageList = new CImageList; //�����ڴ�         
		if( rpImageList )  //��������ڴ�ɹ�    
		{    
			SHFILEINFO sfi;    
			DWORD dwFlags = SHGFI_USEFILEATTRIBUTES|SHGFI_SYSICONINDEX;     
			if( bSmall )  //ָ��ͼ��Ĵ�С     
				dwFlags |=  SHGFI_SMALLICON;      
			size_t size = sizeof( SHFILEINFO );    
			//��ȡ����ϵͳͼ������    
			DWORD dw = SHGetFileInfo( NULL, FILE_ATTRIBUTE_NORMAL,
				                 &sfi, size, dwFlags );      
			rpImageList->Attach( (HIMAGELIST)dw ); //��������          
			rpImageList->SetBkColor( CLR_NONE );  //���ñ���ģʽ      
			bRet = TRUE;    
		}      
	}     
	return( bRet ); 
}

//����ͼ������  
void CSystemImageList::DestroyGlobalList( CImageList *& rpImageList ) 
{      
	if( rpImageList ) //�ж�ͼ������ָ���Ƿ�Ϊ��    
	{  
		rpImageList->Detach();  //��ͼ�����������ͼ���������ľ������    
		delete rpImageList;    //����ͼ������   
		rpImageList = NULL;  //     
	}  
}



//��������ָ��  
CImageList * CSystemImageList::GetImageList( BOOL bSmall /* = TRUE */ ) const  
{      
	CImageList * pList = NULL;     
	if( bSmall )   
		pList = m_gpSmallImageList;     
	else    
		pList = m_gpLargeImageList;      
	return( pList );  
} 

//����ָ���ļ���ͼ����  
HICON CSystemImageList::GetIcon( const CString& sName, BOOL bOpen,  BOOL bSmall )  
{      
	SHFILEINFO sfi;       //ָ������     
	DWORD dwFlags = SHGFI_DISPLAYNAME | SHGFI_ICON | SHGFI_LARGEICON;     
	size_t size = sizeof( SHFILEINFO ); //�õ���������С      
	if( bSmall )   dwFlags |= SHGFI_SMALLICON;  //ָ��Сͼ������         
	if( bOpen )   dwFlags |= SHGFI_OPENICON;   //ָ����ͼ������           
	//��ȡ�ļ�����    
	SHGetFileInfo( sName, NULL , &sfi, size,    SHGFI_DISPLAYNAME | SHGFI_ICON | SHGFI_LARGEICON);    
	return( sfi.hIcon );  //����ͼ����  
}
