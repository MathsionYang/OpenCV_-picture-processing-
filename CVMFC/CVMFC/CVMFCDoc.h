#if !defined(AFX_CVMFCDOC_H__8AF3661A_43CD_4CCC_B491_E79754F18AB1__INCLUDED_)
#define AFX_CVMFCDOC_H__8AF3661A_43CD_4CCC_B491_E79754F18AB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCVMFCDoc : public CDocument
{
protected: // create from serialization only
	CCVMFCDoc();
	DECLARE_DYNCREATE(CCVMFCDoc)
	BOOL Load(IplImage** pImg,LPCTSTR pszFilename);
	BOOL Save(LPCTSTR pszFilename,IplImage* pImg);
   
// Attributes
public:
	IplImage*	pImg;
	int			m_Display;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCVMFCDoc)
	public:
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCVMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCVMFCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CVMFCDOC_H__8AF3661A_43CD_4CCC_B491_E79754F18AB1__INCLUDED_)
