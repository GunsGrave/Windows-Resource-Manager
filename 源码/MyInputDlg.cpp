// MyInputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "myexplorer.h"
#include "MyInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyInputDlg dialog


CMyInputDlg::CMyInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyInputDlg)
	m_strInput = _T("");
	//}}AFX_DATA_INIT
}


void CMyInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyInputDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strInput);
	DDV_MaxChars(pDX, m_strInput, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyInputDlg, CDialog)
	//{{AFX_MSG_MAP(CMyInputDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyInputDlg message handlers
