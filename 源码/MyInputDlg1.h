#if !defined(AFX_MYINPUTDLG1_H__CCE92F67_DD9D_406E_8F81_42FDA104826E__INCLUDED_)
#define AFX_MYINPUTDLG1_H__CCE92F67_DD9D_406E_8F81_42FDA104826E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyInputDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyInputDlg1 dialog

class CMyInputDlg1 : public CDialog
{
// Construction
public:
	CMyInputDlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyInputDlg1)
	enum { IDD = IDD_DIALOG2 };
	CString	m_strInput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyInputDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyInputDlg1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYINPUTDLG1_H__CCE92F67_DD9D_406E_8F81_42FDA104826E__INCLUDED_)
