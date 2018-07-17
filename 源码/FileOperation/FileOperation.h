// FileOperation.h : main header file for the FILEOPERATION DLL
//

#if !defined(AFX_FILEOPERATION_H__6C4A3291_07D8_4128_BCD1_CFAD5FCBE2F2__INCLUDED_)
#define AFX_FILEOPERATION_H__6C4A3291_07D8_4128_BCD1_CFAD5FCBE2F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileOperationApp
// See FileOperation.cpp for the implementation of this class
//

class CFileOperationApp : public CWinApp
{
public:
	CFileOperationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOperationApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFileOperationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPERATION_H__6C4A3291_07D8_4128_BCD1_CFAD5FCBE2F2__INCLUDED_)
