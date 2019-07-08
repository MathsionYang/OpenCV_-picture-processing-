#pragma once


// DLGImgMatch 对话框

class DLGImgMatch : public CDialog
{
	DECLARE_DYNAMIC(DLGImgMatch)

public:
	DLGImgMatch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DLGImgMatch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGMATCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
