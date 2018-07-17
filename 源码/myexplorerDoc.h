// myexplorerDoc.h : interface of the CMyexplorerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYEXPLORERDOC_H__88BC5E83_466F_43BC_8080_2ACF3C47A394__INCLUDED_)
#define AFX_MYEXPLORERDOC_H__88BC5E83_466F_43BC_8080_2ACF3C47A394__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyexplorerDoc : public CDocument
{
protected: // create from serialization only
	CMyexplorerDoc();
	DECLARE_DYNCREATE(CMyexplorerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyexplorerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyexplorerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyexplorerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEXPLORERDOC_H__88BC5E83_466F_43BC_8080_2ACF3C47A394__INCLUDED_)
