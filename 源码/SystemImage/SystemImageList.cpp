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
	if( m_gRefCount == 0 ) //如是计数器为0，说明还未初始化    
	{   
		ASSERT( ! m_gpSmallImageList && ! m_gpLargeImageList );     
		InitGlobalList( m_gpSmallImageList, TRUE ); //初始化小图标链表   
		InitGlobalList( m_gpLargeImageList, FALSE );  //初始化大图标链表      
	}        
	m_gRefCount ++; //计数器加1 
}

CSystemImageList::~CSystemImageList()
{
	m_gRefCount--; //将计数器减1    
	if( m_gRefCount == 0 ) //如果CSystemImageList类的对象已经全部被销毁    
	{   DestroyGlobalList( m_gpLargeImageList ); //销毁大图标链表  
	DestroyGlobalList( m_gpSmallImageList ); //销毁小图标链表     
	} 
}

	CImageList * CSystemImageList::m_gpLargeImageList; //大图标链表				  		
	CImageList * CSystemImageList::m_gpSmallImageList; //小图标链表        		
	int CSystemImageList::m_gRefCount;
//初始化链表  
BOOL CSystemImageList::InitGlobalList( CImageList *& rpImageList, BOOL bSmall  ) 
{      
	BOOL bRet = FALSE;       
	if( ! rpImageList )  //如果链表为空     
	{
		rpImageList = new CImageList; //分配内存         
		if( rpImageList )  //如果分配内存成功    
		{    
			SHFILEINFO sfi;    
			DWORD dwFlags = SHGFI_USEFILEATTRIBUTES|SHGFI_SYSICONINDEX;     
			if( bSmall )  //指定图标的大小     
				dwFlags |=  SHGFI_SMALLICON;      
			size_t size = sizeof( SHFILEINFO );    
			//获取操作系统图标链表    
			DWORD dw = SHGetFileInfo( NULL, FILE_ATTRIBUTE_NORMAL,
				                 &sfi, size, dwFlags );      
			rpImageList->Attach( (HIMAGELIST)dw ); //保存链表          
			rpImageList->SetBkColor( CLR_NONE );  //设置背景模式      
			bRet = TRUE;    
		}      
	}     
	return( bRet ); 
}

//销毁图标链表  
void CSystemImageList::DestroyGlobalList( CImageList *& rpImageList ) 
{      
	if( rpImageList ) //判断图像链表指针是否为空    
	{  
		rpImageList->Detach();  //将图标链表对象与图标链表对象的句柄分离    
		delete rpImageList;    //销毁图标链表   
		rpImageList = NULL;  //     
	}  
}



//返回链表指针  
CImageList * CSystemImageList::GetImageList( BOOL bSmall /* = TRUE */ ) const  
{      
	CImageList * pList = NULL;     
	if( bSmall )   
		pList = m_gpSmallImageList;     
	else    
		pList = m_gpLargeImageList;      
	return( pList );  
} 

//返回指定文件的图标句柄  
HICON CSystemImageList::GetIcon( const CString& sName, BOOL bOpen,  BOOL bSmall )  
{      
	SHFILEINFO sfi;       //指定属性     
	DWORD dwFlags = SHGFI_DISPLAYNAME | SHGFI_ICON | SHGFI_LARGEICON;     
	size_t size = sizeof( SHFILEINFO ); //得到缓冲区大小      
	if( bSmall )   dwFlags |= SHGFI_SMALLICON;  //指定小图标属性         
	if( bOpen )   dwFlags |= SHGFI_OPENICON;   //指定打开图标属性           
	//获取文件属性    
	SHGetFileInfo( sName, NULL , &sfi, size,    SHGFI_DISPLAYNAME | SHGFI_ICON | SHGFI_LARGEICON);    
	return( sfi.hIcon );  //返回图标句标  
}
