// myexplorerView.h : interface of the CMyexplorerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYEXPLORERVIEW_H__599EEB08_4FE4_4D34_8468_A078D7FA0DC0__INCLUDED_)
#define AFX_MYEXPLORERVIEW_H__599EEB08_4FE4_4D34_8468_A078D7FA0DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SystemImageList.h"
#include "FileOP.h"
#include "MultiFile.h"

#pragma comment(lib,"SystemImage.lib")

class CLeftView;

class CMyexplorerView : public CListView
{
protected: // create from serialization only
	CMyexplorerView();
	DECLARE_DYNCREATE(CMyexplorerView)

// Attributes
public:
	CMyexplorerDoc* GetDocument();

	CString m_strCurDirPath;//“‘"\\"Ω·Œ≤
	CStringArray m_csaPath;
	int m_iSelItem;
	CMultiFile m_SelFilePath;
	TCHAR* m_pCutCopyPath;
	BOOL m_bFlag;//0:none,1:cut,2:copy

	CSystemImageList m_SysImageList;
	/*CString strSelItemPath;
	CString strSrcPath;
	CString strDesPath;*/
	UINT nOption;

	//CString m_strSelFilePath;
	//int m_iSelFileCount;

	CListCtrl* m_pListCtrl;
	CLeftView* m_pLeftView;

	BOOL m_bSearch;

// Operations
public:
	BOOL SetFolder(CString sFile);

	void ToParentDir();
	void Refresh();
	void Search(CString DirPath,CString FileName);

	BOOL Open(CString path);
	//void Delete(CString path,BOOL bAskBeforeDel=TRUE);
//	BOOL RecycleFileOrFolder(CString strPath, BOOL bDelete=FALSE);

	//BOOL ForCutCopy();

	void SetCsaPath();
	CString CsaToCsPath(CStringArray &csa, int start,int end);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyexplorerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyexplorerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyexplorerView)
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuCut();
	afx_msg void OnMenuCopy();
	afx_msg void OnMenuDelete();
	afx_msg void OnMenuRecycle();
	afx_msg void OnMenuRefresh();
	afx_msg void OnMenuToParentDir();
	afx_msg void OnMenuPaste();
	afx_msg void OnMenuNewFile();
	afx_msg void OnMenuNewDir();
	afx_msg void OnMenuSearch();
	afx_msg void OnMenuRename();
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in myexplorerView.cpp
inline CMyexplorerDoc* CMyexplorerView::GetDocument()
   { return (CMyexplorerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEXPLORERVIEW_H__599EEB08_4FE4_4D34_8468_A078D7FA0DC0__INCLUDED_)
