// DLGImgMatch.cpp: 实现文件
//

#include "stdafx.h"
#include "DLGImgMatch.h"
#include "afxdialogex.h"

extern CString srcfilePath;
extern CString dstfilePath;
// DLGImgMatch 对话框

IMPLEMENT_DYNAMIC(DLGImgMatch, CDialog)

DLGImgMatch::DLGImgMatch(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLGMATCH, pParent)
{

}

DLGImgMatch::~DLGImgMatch()
{
}

void DLGImgMatch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DLGImgMatch, CDialog)
	ON_BN_CLICKED(IDOK, &DLGImgMatch::OnBnClickedOk)
END_MESSAGE_MAP()


// DLGImgMatch 消息处理程序


void DLGImgMatch::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_MEDIT_SRC, srcfilePath);
	GetDlgItemText(IDC_MEDIT_DST, dstfilePath);
	if (!srcfilePath.IsEmpty()&& !dstfilePath.IsEmpty())
	{
		EndDialog(0);
	}
	else
	{
		MessageBox(_T("请检查文件路径"), _T("提示"), MB_OKCANCEL);
	}
}
