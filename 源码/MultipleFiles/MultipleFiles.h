// MultipleFiles.h : main header file for the MULTIPLEFILES DLL
//

#if !defined(AFX_MULTIPLEFILES_H__0A5E11F1_0870_479F_9076_4D163DDC4B99__INCLUDED_)
#define AFX_MULTIPLEFILES_H__0A5E11F1_0870_479F_9076_4D163DDC4B99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultipleFilesApp
// See MultipleFiles.cpp for the implementation of this class
//

class CMultipleFilesApp : public CWinApp
{
public:
	CMultipleFilesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultipleFilesApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMultipleFilesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIPLEFILES_H__0A5E11F1_0870_479F_9076_4D163DDC4B99__INCLUDED_)
