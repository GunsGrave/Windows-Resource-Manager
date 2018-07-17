#if !defined(AFX_MYINPUTDLG_H__86A4EBAE_D72B_4E2F_B3CF_F935147E2493__INCLUDED_)
#define AFX_MYINPUTDLG_H__86A4EBAE_D72B_4E2F_B3CF_F935147E2493__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyInputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyInputDlg dialog

class CMyInputDlg : public CDialog
{
// Construction
public:
	CMyInputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyInputDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strInput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyInputDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYINPUTDLG_H__86A4EBAE_D72B_4E2F_B3CF_F935147E2493__INCLUDED_)
