#pragma once


// GamaDLG 对话框

class GamaDLG : public CDialog
{
	DECLARE_DYNAMIC(GamaDLG)

public:
	GamaDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GamaDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
