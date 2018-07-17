// MyInputDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "myexplorer.h"
#include "MyInputDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyInputDlg1 dialog


CMyInputDlg1::CMyInputDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CMyInputDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyInputDlg1)
	m_strInput = _T("");
	//}}AFX_DATA_INIT
}


void CMyInputDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyInputDlg1)
	DDX_Text(pDX, IDC_EDIT1, m_strInput);
	DDV_MaxChars(pDX, m_strInput, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyInputDlg1, CDialog)
	//{{AFX_MSG_MAP(CMyInputDlg1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyInputDlg1 message handlers
