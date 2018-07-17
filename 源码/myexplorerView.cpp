// myexplorerView.cpp : implementation of the CMyexplorerView class
//

#include "stdafx.h"
#include "myexplorer.h"

#include "myexplorerDoc.h"
#include "myexplorerView.h"

#include "MainFrm.h"
#include "SplitStr.h"
#include "MyInputDlg.h"
#include "MyInputDlg1.h"
//#include "FileOP.h"
#include "SearchDlg.h"


#pragma comment(lib,"FileOperation.lib")
#pragma comment(lib,"MultipleFiles.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerView

IMPLEMENT_DYNCREATE(CMyexplorerView, CListView)

BEGIN_MESSAGE_MAP(CMyexplorerView, CListView)
	//{{AFX_MSG_MAP(CMyexplorerView)
	ON_NOTIFY_REFLECT(HDN_ITEMCHANGED, OnItemchanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnListRclick)
	ON_COMMAND(ID_MENUITEM32776, OnMenuOpen)
	ON_COMMAND(ID_MENUITEM32779, OnMenuCut)
	ON_COMMAND(ID_MENUITEM32780, OnMenuCopy)
	ON_COMMAND(ID_MENUITEM32781, OnMenuDelete)
	ON_COMMAND(ID_MENUITEM32785, OnMenuRecycle)
	ON_COMMAND(ID_MENUITEM32777, OnMenuRefresh)
	ON_COMMAND(ID_MENUITEM32778, OnMenuToParentDir)
	ON_COMMAND(ID_MENUITEM32782, OnMenuPaste)
	ON_COMMAND(ID_MENUITEM32783, OnMenuNewFile)
	ON_COMMAND(ID_MENUITEM32784, OnMenuNewDir)
	ON_COMMAND(ID_MENUITEM32791, OnMenuSearch)
	ON_COMMAND(ID_MENUITEM32792, OnMenuRename)
	ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, OnEndlabeledit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerView construction/destruction

CMyexplorerView::CMyexplorerView()
{
	// TODO: add construction code here
	m_pListCtrl = &GetListCtrl();
	//m_strCutCopyPath = "";
	//m_strCutCopyName = "";
	m_bFlag = 0;
	//m_strSelFilePath="";
	//m_iSelFileCount=0;
	m_bSearch = 0;
}

CMyexplorerView::~CMyexplorerView()
{
}

BOOL CMyexplorerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerView drawing

void CMyexplorerView::OnDraw(CDC* pDC)
{
	CMyexplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, "Item!");
	// TODO: add draw code for native data here
}

void CMyexplorerView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to m_pListCtrl->
	LONG lStyle;
    lStyle=GetWindowLong(m_pListCtrl->m_hWnd, GWL_STYLE); //获取当前窗口style
    lStyle |=LVS_EDITLABELS  ;                                //设置style
    SetWindowLong(m_pListCtrl->m_hWnd, GWL_STYLE, lStyle);//设置style

	m_pLeftView = reinterpret_cast<CLeftView*>( ((CMainFrame*)AfxGetMainWnd())->m_wndSplitter.GetPane(0, 1) );
}

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerView diagnostics

#ifdef _DEBUG
void CMyexplorerView::AssertValid() const
{
	CListView::AssertValid();
}

void CMyexplorerView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMyexplorerDoc* CMyexplorerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyexplorerDoc)));
	return (CMyexplorerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerView operation

BOOL CMyexplorerView::SetFolder(CString sFile) 
{  
	int index; 
	if (sFile == "")
	{
		/*char *ptr;
		char DrivesName[512];
		SHFILEINFO shinfo;
		CImageList * imageList;
 
        m_pListCtrl->DeleteAllItems();
        GetLogicalDriveStrings(500,DrivesName);
 
        ptr=DrivesName;
 
        while (*ptr)
        {
			SHGetFileInfo( path, NULL, 
						   &shinfo, 
						   sizeof(shinfo), 
						   SHGFI_DISPLAYNAME );
 
			imageList = m_SysImageList.GetImageList( FALSE );  
			m_pListCtrl->SetImageList(imageList, LVSIL_NORMAL); //设置图标链表
			HICON icon =  m_SysImageList.GetIcon(ptr, FALSE,FALSE);     
			index = imageList->Add(icon); //添加到图标链中    
			//插入列表项    
			m_pListCtrl->InsertItem( 1, ((CString)ptr).Left(2), index ); 
            ptr+=strlen(ptr)+1;
        }*/
		//::MessageBox(NULL,"","",MB_OK);//////////////////////////////////////////////////////////
		return FALSE;
		
	}
	if(m_bSearch)
		m_bSearch=FALSE;

	CFileFind finder;  
	int bWorking = finder.FindFile(sFile+"\\*.*");  
	if( bWorking ) 
	{   
		m_pListCtrl->DeleteAllItems(); //删除所有列表项
	}   else {finder.Close(); return FALSE;}
    
	m_strCurDirPath = sFile + "\\";    //得到大图标链表 
	SetCsaPath();

	CImageList * imageList = m_SysImageList.GetImageList( FALSE );  
	m_pListCtrl->SetImageList(imageList, LVSIL_NORMAL); //设置图标链表

	while( bWorking )
	{   //得到下一个列表项    
		bWorking = finder.FindNextFile();   
		//如果不是“.”或“..”   
		if(!finder.IsDots())   
		{      //获取图标   
			HICON icon =  m_SysImageList.GetIcon(m_strCurDirPath+finder.GetFileName(), FALSE,FALSE);     
			index = imageList->Add(icon); //添加到图标链中    
			//插入列表项    
			m_pListCtrl->InsertItem( 1, finder.GetFileName(), index );   
		}  
	}
	finder.Close();
	return TRUE;
}

void CMyexplorerView::ToParentDir()
{
	int n=m_csaPath.GetSize()-2;
	for( ; n>=0 && !SetFolder(CsaToCsPath(m_csaPath, 0, n)) ; --n);
}

void CMyexplorerView::SetCsaPath()
{
	CSplitStr splitter;
	splitter.SetData(m_strCurDirPath);
	splitter.SetSplitFlag('\\');
	m_csaPath.RemoveAll();
	splitter.GetSplitStrArray(m_csaPath);
}

CString CMyexplorerView::CsaToCsPath(CStringArray &csa, int start, int end)//start、end为下标,包含它们所指的元素
{
	if(start<=end)
	{
		int i;
		CString path=csa[start];

		for(i=start+1;i<=end;++i)
			path=path+"\\"+csa[i];
		return path;
	}
	return "";
}

void CMyexplorerView::Refresh()
{
	if(m_bSearch)
	{
		int count = m_pListCtrl->GetItemCount();
		int i;
		for(i=0;i<count;++i)
			if(CFileOP::TypeOf(m_pListCtrl->GetItemText(i,0))==0)
				m_pListCtrl->DeleteItem(i);
	}
	else
	{
		CFileFind finder;
		CString DirPath=m_strCurDirPath.Left(m_strCurDirPath.GetLength()-1);
		if(finder.FindFile(DirPath+"\\*.*"))
			SetFolder(DirPath);
		else ToParentDir();
		finder.Close();
	}
}

BOOL CMyexplorerView::Open(CString path)
{
	CFileFind finder;
	if( finder.FindFile(path) )
	{
		finder.FindNextFile();
		if(!finder.IsDots())
		{
			if(finder.IsDirectory())
			{
				SetFolder(path);
			}
			else
				ShellExecute(NULL,"open",path,NULL,NULL, SW_SHOWNORMAL);
		}
		finder.Close();
		return TRUE;
	}
	else
	{
		Refresh();
		::MessageBox(this->m_hWnd,"\""+path+"\"打开失败","提示",MB_OK);
		return FALSE;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CMyexplorerView message handlers
void CMyexplorerView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window
}

void CMyexplorerView::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	/*NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	strSelItemPath = m_pListCtrl->GetItemText(pNMListView->iItem,pNMListView->iSubItem);*/
	
	*pResult = 0;
}

void CMyexplorerView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	Open(m_strCurDirPath + m_pListCtrl->GetItemText(pNMListView->iItem,0) );

	*pResult = 0;
}

void CMyexplorerView::OnListRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CRect rect;  
	CPoint p;  
	GetCursorPos(&p);  
	m_pListCtrl->ScreenToClient(&p); 
	
	CMenu m_Menu1;
	UINT uFlags;
	if( (m_iSelItem=m_pListCtrl->HitTest(p, &uFlags)) != -1 )//&& (TVHT_ONITEM & uFlags) )
	{ 
		int count=m_pListCtrl->GetItemCount();
		//m_strSelFilePath="";
		//m_iSelFileCount=0;
		m_SelFilePath.Reset();
		int i;
		for(i=0;i<count;++i)
		{
			if(m_pListCtrl->GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
			{
				//m_strCurDirPath += m_strCurDirPath + m_pListCtrl->GetItemText(i,0)
				m_SelFilePath.AddFile( m_strCurDirPath + m_pListCtrl->GetItemText(i,0) );
				//++m_iSelFileCount;
			}
		}
        m_Menu1.LoadMenu(ID_MENU1);  
        CMenu *m_SubMenu1 = m_Menu1.GetSubMenu(0);  

		if(m_SelFilePath.GetCount()>1)
		{
			m_SubMenu1->EnableMenuItem(ID_MENUITEM32776, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			m_SubMenu1->EnableMenuItem(ID_MENUITEM32792, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		}

		m_pListCtrl->ClientToScreen(&p);
        m_SubMenu1->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, this);
	}
	else
	{
		m_Menu1.LoadMenu(ID_MENU2);  
        CMenu *m_SubMenu1 = m_Menu1.GetSubMenu(0); 
		
		if(m_bSearch)
		{
			m_SubMenu1->EnableMenuItem(ID_MENUITEM32778, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			m_SubMenu1->EnableMenuItem(ID_MENUITEM32782, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			m_SubMenu1->EnableMenuItem(ID_MENUITEM32783, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			m_SubMenu1->EnableMenuItem(ID_MENUITEM32784, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			m_SubMenu1->EnableMenuItem(ID_MENUITEM32791, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		}

		m_pListCtrl->ClientToScreen(&p);
        m_SubMenu1->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, this);
	}

	*pResult = 0;
}

void CMyexplorerView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
    LVITEMA item = pDispInfo->item;
    CString str = item.pszText;
    str.TrimLeft();
    str.TrimRight();
    if (str.GetLength() > 0)
	{
		CMultiFile OldPath,NewPath;

		OldPath.AddFile( m_strCurDirPath + m_pListCtrl->GetItemText(item.iItem,0) );
		NewPath.AddFile( m_strCurDirPath + item.pszText );

		if( CFileOP::ReNameFile( NewPath.GetPath(), OldPath.GetPath() ) )
		{
			m_pListCtrl->SetItemText(item.iItem,item.iSubItem,item.pszText);
			Refresh();
		}
	}
	
	*pResult = 0;
}

///////////////////////////////////////////////////////////////////
////////Menu1
void CMyexplorerView::OnMenuOpen()
{
	Open(m_SelFilePath.GetCStringPath());
}

void CMyexplorerView::OnMenuCut()
{
	m_pCutCopyPath = m_SelFilePath.GetPath();
	m_bFlag=1;
}

void CMyexplorerView::OnMenuCopy()
{
	m_pCutCopyPath = m_SelFilePath.GetPath();
	m_bFlag=2;
}

/*BOOL CMyexplorerView::ForCutCopy()
{
	CString path = m_strCurDirPath + m_pListCtrl->GetItemText(m_SelItem,0);
	CFileFind finder;
	if(!finder.FindFile(path))
	{
		Refresh();
		finder.Close();
		::MessageBox(this->m_hWnd,"\""+path+"\"不存在","提示",MB_OK);
		return FALSE;
	}
	finder.Close();
	m_strCutCopyPath = path;
}*/

void CMyexplorerView::OnMenuDelete()
{
	/*CFile tmp;
	tmp.Remove(path);*/
	//Delete(path);
	//RecycleFileOrFolder(m_strSelFilePath,TRUE);

	CFileOP::DeleteFile(m_SelFilePath.GetPath());
	Refresh();
}

void CMyexplorerView::OnMenuRecycle()
{
	CFileOP::DeleteFile(m_SelFilePath.GetPath(),TRUE);
	Refresh();
}

/*void CMyexplorerView::Delete(CString path, BOOL bAskBeforeDel)
{
	if(bAskBeforeDel)
		if( ::MessageBox(this->m_hWnd,"确定要删除\""+path+"\"?","提示",MB_YESNO) == IDNO )
			return;

	int type = CFileOP::TypeOf(path);
	if(type==0)
		::MessageBox(this->m_hWnd,"\""+path+"\"不存在","提示",MB_OK);
	else if(type==1)
	{
		if( !RemoveDirectory(path) )///////////////////////////////////////////////////
		{
			//::MessageBox(this->m_hWnd,"\""+path+"\"删除失败","提示",MB_OK);
			CString str;
			str.Format("%d",GetLastError());
			::MessageBox(this->m_hWnd,"删除失败!错误号："+str,"提示",MB_OK);
		}
	}
	else if(type==2)
		if( !DeleteFile(path) )
		{
			//::MessageBox(this->m_hWnd,"\""+path+"\"删除失败","提示",MB_OK);
			CString str;
			str.Format("%d",GetLastError());
			::MessageBox(this->m_hWnd,"删除失败!错误号："+str,"提示",MB_OK);
		}
	//Refresh();////////////
}*/

/*BOOL CMyexplorerView::RecycleFileOrFolder(CString strPath, BOOL bDelete)  
{  
    strPath += '\0';  
    SHFILEOPSTRUCT  shDelFile;  
    memset(&shDelFile,0,sizeof(SHFILEOPSTRUCT));  
    shDelFile.fFlags |= FOF_SILENT;             // 不显示进度  
    shDelFile.fFlags |= FOF_NOERRORUI;          // 不报告错误信息  
    shDelFile.fFlags |= FOF_NOCONFIRMATION;     // 直接删除，不进行确认  
  
    // 设置SHFILEOPSTRUCT的参数为删除做准备  
    shDelFile.wFunc = FO_DELETE;        // 执行的操作  
    shDelFile.pFrom = strPath;          // 操作的对象，也就是目录（注意：以“\0\0”结尾）  
    shDelFile.pTo = NULL;               // 必须设置为NULL  
    if (bDelete) //根据传递的bDelete参数确定是否删除到回收站  
    {      
        shDelFile.fFlags &= ~FOF_ALLOWUNDO;    //直接删除，不进入回收站  
    }   
    else   
    {             
        shDelFile.fFlags |= FOF_ALLOWUNDO;    //删除到回收站  
    }  
  
    BOOL bres = SHFileOperation(&shDelFile);    //删除  
    return !bres;  
}  */

void CMyexplorerView::OnMenuRename()
{
	m_pListCtrl->SetFocus();
	CEdit* pEdit = m_pListCtrl->EditLabel(m_iSelItem);
	/*if(!pEdit)
		::MessageBox(this->m_hWnd,"1","",MB_OK);*/
}



///////////////////////////////////////////////////////////////////
////////Menu2
void CMyexplorerView::OnMenuRefresh()
{
		Refresh();
}

void CMyexplorerView::OnMenuToParentDir()
{
	ToParentDir();
}

void CMyexplorerView::OnMenuPaste()
{
	if(m_bFlag==1)
	{
		/*CString destPath = m_strCurDirPath + m_strCutCopyName;
		if(destPath == m_strCutCopyPath)
		{
			m_bFlag=0;
			return;
		}
		int type = TypeOf(m_strCutCopyPath);
		if(type==0)
		{
			Refresh();
			m_bFlag=0;
			::MessageBox(this->m_hWnd,"\""+m_strCutCopyPath+"\"不存在","提示",MB_OK);
			return;
		}
		int destExist = CFileOP::TypeOf(destPath);
		if(type==2)
		{
			if(destExist)
			{
				if(::MessageBox(this->m_hWnd,"文件\""+destPath+"\"已存在,是否覆盖？","提示",MB_YESNO) == IDNO )
				{
					m_bFlag=0;
					return;
				}
			}
			if(!CopyFile(m_strCutCopyPath,destPath,FALSE))
			{
				m_bFlag=0;
				CString str;
				str.Format("%d",GetLastError());
				::MessageBox(this->m_hWnd,"粘贴失败！错误号："+str,"提示",MB_OK);
				return;
			}
			Refresh();
		}
		else if(type==1)/////////////////////////////////////////////////////////////
		{
		}

		if(m_bFlag==1)
			Delete(m_strCutCopyPath,FALSE);*/
		CString DestPath=m_strCurDirPath.Left(m_strCurDirPath.GetLength()-1);
		CMultiFile file;
		file.AddFile(DestPath);
		CFileOP::MoveFile(file.GetPath(), m_SelFilePath.GetPath());
	}
	else if(m_bFlag==2)
	{
		CString DestPath=m_strCurDirPath.Left(m_strCurDirPath.GetLength()-1);
		CMultiFile file;
		file.AddFile(DestPath);
		CFileOP::CopyFile(file.GetPath(), m_SelFilePath.GetPath());
	}
	else return;
	Refresh();
	m_bFlag=0;
}

void CMyexplorerView::OnMenuNewFile()
{
	CFileFind temp;
	if( temp.FindFile(m_strCurDirPath+"*.*") )
	{
		CString tmp;
		int i;

		CString s = m_strCurDirPath + "新建文件";
		CString path = s;

		CFileFind finder;
		for(i=1;finder.FindFile(path);++i)
		{
			tmp.Format(_T("(%d)"),i);
			path=s+tmp;
		}

		CFile file;
		if( file.Open(path,CFile::modeCreate) )
		{
			CImageList * imageList = m_SysImageList.GetImageList( FALSE );  
			m_pListCtrl->SetImageList(imageList, LVSIL_NORMAL); //设置图标链表

			HICON icon;
			int index;

			icon = m_SysImageList.GetIcon(path, FALSE,FALSE);     
			index = imageList->Add(icon); //添加到图标链中    

			m_pListCtrl->InsertItem(0,"新建文件"+tmp,index);

			m_pListCtrl->SetFocus();
			CEdit* pEdit = m_pListCtrl->EditLabel(0);
		}
		file.Close();
		finder.Close();
	}
	else Refresh();
}

void CMyexplorerView::OnMenuNewDir()
{
	CFileFind temp;
	if( temp.FindFile(m_strCurDirPath+"*.*") )
	{
		CString tmp;
		int i;

		CString s = m_strCurDirPath + "新建文件夹";
		CString path = s;

		CFileFind finder;

		for(i=1;finder.FindFile(path);++i)
		{
			tmp.Format(_T("(%d)"),i);
			path=s+tmp;
		}

		if( CreateDirectory(path,NULL) )
		{
			CImageList * imageList = m_SysImageList.GetImageList( FALSE );  
			m_pListCtrl->SetImageList(imageList, LVSIL_NORMAL); //设置图标链表

			HICON icon;
			int index;

			icon = m_SysImageList.GetIcon(path, FALSE,FALSE);     
			index = imageList->Add(icon); //添加到图标链中    

			m_pListCtrl->InsertItem(0,"新建文件夹"+tmp,index);

			m_pListCtrl->SetFocus();
			CEdit* pEdit = m_pListCtrl->EditLabel(0);
		}
		finder.Close();
	}
	else Refresh();
}

void CMyexplorerView::OnMenuSearch()
{
	CSearchDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_bSearch=TRUE;

		m_pListCtrl->DeleteAllItems();
		CString DirPath=m_strCurDirPath;
		m_strCurDirPath="";

		Search(DirPath,dlg.m_strInput);
	}
}

void CMyexplorerView::Search(CString DirPath, CString FileName)
{
	CImageList * imageList = m_SysImageList.GetImageList( FALSE );  
	m_pListCtrl->SetImageList(imageList, LVSIL_NORMAL); //设置图标链表
	HICON icon;
	CString FilePath;

	int index;
	CFileFind finder;
	BOOL bWorking = finder.FindFile(DirPath+"*.*");
	while(bWorking)
	{
		bWorking = finder.FindNextFile();
		if(!finder.IsDots())
		{
			FilePath = DirPath+finder.GetFileName();
			if(finder.GetFileName()==FileName)
			{
				icon = m_SysImageList.GetIcon(FilePath, FALSE,FALSE);     
				index = imageList->Add(icon); //添加到图标链中    
				//插入列表项    
				m_pListCtrl->InsertItem( 1, FilePath, index );   
			}
			if(finder.IsDirectory())
				Search( FilePath+"\\", FileName);
		}
	}
}
