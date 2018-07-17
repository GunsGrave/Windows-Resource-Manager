// myexplorerDoc.cpp : implementation of the CMyexplorerDoc class
//

#include "stdafx.h"
#include "myexplorer.h"

#include "myexplorerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerDoc

IMPLEMENT_DYNCREATE(CMyexplorerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyexplorerDoc, CDocument)
	//{{AFX_MSG_MAP(CMyexplorerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerDoc construction/destruction

CMyexplorerDoc::CMyexplorerDoc()
{
	// TODO: add one-time construction code here

}

CMyexplorerDoc::~CMyexplorerDoc()
{
}

BOOL CMyexplorerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyexplorerDoc serialization

void CMyexplorerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerDoc diagnostics

#ifdef _DEBUG
void CMyexplorerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyexplorerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyexplorerDoc commands
