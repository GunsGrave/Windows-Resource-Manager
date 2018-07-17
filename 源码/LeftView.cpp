// LeftView.cpp : implementation of the CLeftView class
//

#include "stdafx.h"
#include "myexplorer.h"
#include "myexplorerDoc.h"
#include "MainFrm.h"
#include "myexplorerView.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnTreeSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView construction/destruction

CLeftView::CLeftView()
{
	// TODO: add construction code here
	m_pTreeCtrl = &GetTreeCtrl();
}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= TVS_HASBUTTONS | TVS_LINESATROOT ;//| TVS_HASLINES;

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CMyexplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: You may populate your TreeView with items by directly accessing
	//  its tree control through a call to m_pTreeCtrl->
	Initialize();
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CMyexplorerDoc* CLeftView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyexplorerDoc)));
	return (CMyexplorerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView implementations

void CLeftView::Initialize()
{
    LPITEMIDLIST itemlist;
    char buf[256];
    int  iDesktopIcon;
    int  iComputerIcon;
 
    m_pTreeCtrl->DeleteAllItems();
 
    m_pTreeCtrl->SetImageList (NULL,0);
 
    SHGetSpecialFolderLocation (this->m_hWnd, CSIDL_DESKTOP, &itemlist);
    SHGetPathFromIDList(itemlist, buf ); 
    m_DesktopPath=buf;
 
    m_ImageList.Create( GetSystemMetrics(SM_CXSMICON), 
                  GetSystemMetrics(SM_CYSMICON), 
                  ILC_COLOR24, 50, 50);
 
    m_ImageList.SetBkColor( GetSysColor(COLOR_WINDOW) );
 
    iDesktopIcon  = m_ImageList.Add(ExtractIcon( AfxGetApp()->m_hInstance, "shell32.dll", 34));
    iComputerIcon = m_ImageList.Add(ExtractIcon( AfxGetApp()->m_hInstance, "shell32.dll", 15));
 
    m_DrivesRoot = m_pTreeCtrl->InsertItem("我的电脑", iComputerIcon, iComputerIcon, TVI_ROOT);
    m_DesktopRoot = AddItem(m_DesktopPath, TVI_ROOT, iDesktopIcon, iDesktopIcon);

	m_pTreeCtrl->InsertItem("",m_DrivesRoot);

	if(HasSubDir(m_DesktopPath))
		m_pTreeCtrl->InsertItem("",m_DesktopRoot);

	m_pListView = reinterpret_cast<CMyexplorerView*>( ((CMainFrame*)AfxGetMainWnd())->m_wndSplitter.GetPane(0, 1) );
} 

HTREEITEM CLeftView::AddItem(const char * path, HTREEITEM parent, int iconEx, int iconEx2)
{
    SHFILEINFO shinfo, shinfo_sel;
 
    SHGetFileInfo( path, NULL, 
                   &shinfo, 
                   sizeof(shinfo), 
                   SHGFI_DISPLAYNAME | SHGFI_ICON | SHGFI_SMALLICON);
 
    SHGetFileInfo( path, NULL, 
                   &shinfo_sel, 
                   sizeof(shinfo_sel), 
                   SHGFI_DISPLAYNAME |  SHGFI_ICON | SHGFI_OPENICON | SHGFI_SMALLICON);
 
    int icon    = iconEx !=-1 ? iconEx  : m_ImageList.Add(shinfo.hIcon);
    int iconsel = iconEx2!=-1 ? iconEx2 : m_ImageList.Add(shinfo_sel.hIcon);
 
    m_pTreeCtrl->SetImageList (&m_ImageList,LVSIL_NORMAL);

    return m_pTreeCtrl->InsertItem( shinfo.szDisplayName, icon, iconsel, parent );
}

 
void CLeftView::DeleteAllChild(HTREEITEM itm, bool isEmpty)
{
    HTREEITEM child;
 
    child= m_pTreeCtrl->GetChildItem(itm);
 
    while (child)
    {
         
        if (m_pTreeCtrl->GetChildItem(child))
            DeleteAllChild(m_pTreeCtrl->GetChildItem(child), isEmpty);
 
        m_pTreeCtrl->DeleteItem (child);
 
        m_pTreeCtrl->SetImageList(&m_ImageList,TVSIL_NORMAL);
 
        child= m_pTreeCtrl->GetChildItem(itm);
    }
 
    if (isEmpty)
        m_pTreeCtrl->InsertItem( "",itm);
}
 
 
void CLeftView::ExpandBranch(HTREEITEM parent)
{
 
    if(parent==m_DrivesRoot)
    {
        char *ptr;
 
        DeleteAllChild(parent,false);
        GetLogicalDriveStrings(500,m_DrivesName);
 
        ptr=m_DrivesName;
 
        while (*ptr)
        {
            HTREEITEM itm = AddItem(ptr, m_DrivesRoot);
			m_pTreeCtrl->InsertItem("",itm);
            ptr+=strlen(ptr)+1;
        }
    }
    else
    {
        m_strFullPath = "";
        CString pathWildcard;
 
        m_strFullPath=GetFullPath(parent);
        DeleteAllChild(parent,false);
        pathWildcard=m_strFullPath+"\\*.*";
 
        CFileFind finder;
        BOOL bWorking = finder.FindFile(pathWildcard);
        while (bWorking)
        {
            bWorking = finder.FindNextFile();
            if ( finder.IsDirectory() && !finder.IsDots() )
            {
                HTREEITEM itm=AddItem (finder.GetFilePath(), parent );
                if( HasSubDir( finder.GetFilePath() ) )
					m_pTreeCtrl->InsertItem("",itm);
            }
		}
    }
}

BOOL CLeftView::HasSubDir(CString path)
{
	CFileFind finder;
	BOOL bWorking = finder.FindFile(path+"\\*.*");
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if( finder.IsDirectory() && !finder.IsDots() )
			return TRUE;
	}
	return FALSE;
}

 
/*CString CLeftView::GetPathFromHere(CString s, HTREEITEM itm)
{
    HTREEITEM parent   = m_pTreeCtrl->GetParentItem(itm);
    HTREEITEM itmChild = m_pTreeCtrl->GetChildItem(itm);
 
    if(!itmChild) return GetPathFromHere(s,parent);
 
    if (itm==m_DrivesRoot) return "";
         
    if (parent==m_DrivesRoot)
    {
        HTREEITEM child;
 
        char *ptr=m_DrivesName;
        child=m_pTreeCtrl->GetChildItem(parent);
         
        while (child)
        {
            if (child==itm)
            {
                s=CString(ptr)+s;
                return s;
            }
            ptr+=strlen(ptr)+1;
            child=m_pTreeCtrl->GetNextItem(child, TVGN_NEXT);
        }
    }
    else if (itm==m_DesktopRoot)
    {
		s=m_DesktopPath+'\\'+s;
        return s;
    }
    else
    {
        if (m_pTreeCtrl->GetItemText(itm)!= CString(""))
		{
            s=m_pTreeCtrl->GetItemText(itm)+'\\'+s;
		}
 
        s=GetPathFromHere(s,parent);
    }
 
    if (!itmChild && s.GetLength()>0)
        s=s.Left (s.GetLength()-1);
 
    return s;
}*/
 
CString CLeftView::GetFullPath(HTREEITEM item)
{
	CString path = "";
	HTREEITEM parent = m_pTreeCtrl->GetParentItem(item);
	if(!parent)
	{
		if(item==m_DesktopRoot)
			return m_DesktopPath;
		return "";
	}
	while(parent != m_DrivesRoot)
	{
		path=m_pTreeCtrl->GetItemText(item)+"\\"+path;
		item=parent;
		parent = m_pTreeCtrl->GetParentItem(item);
	}

	char *ptr=m_DrivesName;
	HTREEITEM child = m_pTreeCtrl->GetChildItem(parent);
	while (child)
    {
        if (child==item)
        {
            path=CString(ptr)+path;
            return path.Left(path.GetLength()-1);
        }
        ptr+=strlen(ptr)+1;
        child=m_pTreeCtrl->GetNextItem(child, TVGN_NEXT);
    }
	return "";
}
 
bool CLeftView::SetFolder(CString path_in)
{
    char path[MAX_PATH];
    char *delimiters="\\";
    char *token;
 
    char *pathStart=path;
 
    HTREEITEM current=m_DrivesRoot;
 
    strcpy(path,path_in);
 
    m_pTreeCtrl->Expand(current,TVE_EXPAND );
    token=strtok (path,delimiters);
    while (token!=NULL)
        {
        current=DirToItem(current, token);
        if (!current)
            {
            return false;
            }
         
        m_pTreeCtrl->Expand(current,TVE_EXPAND );
        token=strtok(NULL,delimiters);
        }
 
    m_pTreeCtrl->SelectItem(current);
    return true;
}
 
HTREEITEM CLeftView::DirToItem(HTREEITEM current, char *dir)
{
    if (current==m_DrivesRoot)
        {
        HTREEITEM child;
        CString szDir(dir);
 
        szDir+="\\";
        szDir.MakeUpper();
 
        char *ptr=m_DrivesName;
        child=m_pTreeCtrl->GetChildItem(current);
         
        while (child)
            {
            if (szDir==CString(ptr))
                {
                return child;
                }
            ptr+=strlen(ptr)+1;
            child=m_pTreeCtrl->GetNextItem(child, TVGN_NEXT);
            }
        }
    else
        {
        HTREEITEM child;
        CString szChildText;
        CString szDir(dir);
 
        szDir.MakeUpper();
 
        child=m_pTreeCtrl->GetChildItem(current);
        while (child)
            {
            szChildText=m_pTreeCtrl->GetItemText(child);
            szChildText.MakeUpper();
 
            if ( szChildText==szDir)
                {
                return child;
                }
            child=m_pTreeCtrl->GetNextItem(child, TVGN_NEXT);
            }
        }
 
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

void CLeftView::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	TV_ITEM itm= pNMTreeView->itemNew;
 
    if (itm.state & TVIS_EXPANDED)
	{
        ExpandBranch(itm.hItem);
	}
    else
    {
        DeleteAllChild(itm.hItem);
    }
	
	*pResult = 0;
}

void CLeftView::OnTreeSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	TV_ITEM itm= pNMTreeView->itemNew; //得到用户所选择的节点 
	CString path = GetFullPath(itm.hItem); //得到节点全路径   
	//reinterpret_cast<CMyexplorerView*>( ((CMainFrame*)AfxGetMainWnd())->m_wndSplitter.GetPane(0, 1) )->SetFolder(path);  //打开用户所选择的文件夹
	m_pListView->SetFolder(path);

	*pResult = 0;
}
