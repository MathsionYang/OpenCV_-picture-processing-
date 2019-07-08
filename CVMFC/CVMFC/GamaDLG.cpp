// GamaDLG.cpp: 实现文件
//

#include "stdafx.h"
#include "GamaDLG.h"
#include "afxdialogex.h"
extern double gama;
extern double gama1;

// GamaDLG 对话框

IMPLEMENT_DYNAMIC(GamaDLG, CDialog)

GamaDLG::GamaDLG(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

GamaDLG::~GamaDLG()
{
}

void GamaDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GamaDLG, CDialog)
	ON_BN_CLICKED(IDOK, &GamaDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// GamaDLG 消息处理程序


void GamaDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	gama = GetDlgItemInt(IDC_EDIT_GAMA);//获取GAMA值
	EndDialog(0);
	
}
