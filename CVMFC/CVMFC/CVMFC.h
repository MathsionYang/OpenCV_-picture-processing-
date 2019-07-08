// CVMFC.h : main header file for the CVMFC application
//

#if !defined(AFX_CVMFC_H__841315CE_EB42_4A30_B309_7FCAF1B80D48__INCLUDED_)
#define AFX_CVMFC_H__841315CE_EB42_4A30_B309_7FCAF1B80D48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCVMFCApp:
// See CVMFC.cpp for the implementation of this class
//

class CCVMFCApp : public CWinApp
{
public:
	CCVMFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCVMFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCVMFCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CVMFC_H__841315CE_EB42_4A30_B309_7FCAF1B80D48__INCLUDED_)
