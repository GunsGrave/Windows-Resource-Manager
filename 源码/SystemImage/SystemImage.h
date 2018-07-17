// SystemImage.h : main header file for the SYSTEMIMAGE DLL
//

#if !defined(AFX_SYSTEMIMAGE_H__08703474_4DEF_4DF8_AAD1_2125441123CA__INCLUDED_)
#define AFX_SYSTEMIMAGE_H__08703474_4DEF_4DF8_AAD1_2125441123CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSystemImageApp
// See SystemImage.cpp for the implementation of this class
//

class CSystemImageApp : public CWinApp
{
public:
	CSystemImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemImageApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CSystemImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMIMAGE_H__08703474_4DEF_4DF8_AAD1_2125441123CA__INCLUDED_)
