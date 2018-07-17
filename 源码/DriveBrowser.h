#if !defined(AFX_DRIVEBROWSER_H__6AC88C44_C1F9_4AA8_AC64_F754559105BC__INCLUDED_)
#define AFX_DRIVEBROWSER_H__6AC88C44_C1F9_4AA8_AC64_F754559105BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DriveBrowser.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDriveBrowser view

class CDriveBrowser : public CTreeView
{
protected:
	CDriveBrowser();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDriveBrowser)

// Attributes
public:
	CString m_strFullPath;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriveBrowser)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDriveBrowser();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDriveBrowser)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVEBROWSER_H__6AC88C44_C1F9_4AA8_AC64_F754559105BC__INCLUDED_)
