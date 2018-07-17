// LeftView.h : interface of the CLeftView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTVIEW_H__8BDD5F64_9867_4438_B1EC_DA7278FAAA05__INCLUDED_)
#define AFX_LEFTVIEW_H__8BDD5F64_9867_4438_B1EC_DA7278FAAA05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyexplorerDoc;

class CLeftView : public CTreeView
{
protected: // create from serialization only
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// Attributes
public:
	CMyexplorerDoc* GetDocument();

	CString m_strFullPath;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	bool SetFolder (CString path);
    CString GetFullPath (HTREEITEM item);
	void Initialize();
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLeftView)
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTreeSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	HTREEITEM DirToItem(HTREEITEM current, char *dir);
    CString GetPathFromHere (CString s, HTREEITEM itm);
    void ExpandBranch (HTREEITEM parent);
    void DeleteAllChild (HTREEITEM itm,  bool isEmpty=true);
    HTREEITEM AddItem(const char * path, HTREEITEM parent, int iconEx=-1, int iconEx2=-1);
	BOOL CLeftView::HasSubDir(CString path);
    
    HTREEITEM m_DesktopRoot;//desktop_root;
    CString   m_DesktopPath;
 
    HTREEITEM m_DrivesRoot;
    char      m_DrivesName[512];
 
    CImageList m_ImageList;
	CMyexplorerView* m_pListView;
	CTreeCtrl* m_pTreeCtrl;
};

#ifndef _DEBUG  // debug version in LeftView.cpp
inline CMyexplorerDoc* CLeftView::GetDocument()
   { return (CMyexplorerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__8BDD5F64_9867_4438_B1EC_DA7278FAAA05__INCLUDED_)
