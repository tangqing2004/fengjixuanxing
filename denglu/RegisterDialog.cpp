// RegisterDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "denglu.h"
#include "RegisterDialog.h"
#include "afxdialogex.h"


// CRegisterDialog 对话框

IMPLEMENT_DYNAMIC(CRegisterDialog, CDialogEx)

CRegisterDialog::CRegisterDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegisterDialog::IDD, pParent)
{

}

CRegisterDialog::~CRegisterDialog()
{
}

void CRegisterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegisterDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRegisterDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CRegisterDialog 消息处理程序


void CRegisterDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString username, password,password1;
    GetDlgItemText(IDC_EDIT1, username);
    GetDlgItemText(IDC_EDIT2, password);
	GetDlgItemText(IDC_EDIT3,password1);
	if(password!=password1)
	{
		AfxMessageBox(_T("两次密码不相同"));
		return;
	}

    sqlite3* db = NULL;
    char* errMsg = NULL;
    int rc = sqlite3_open("mydb.db", &db);
    if (rc != SQLITE_OK) {
        AfxMessageBox(_T("Failed to open database!"));
        return;
    }

    CString query;
    query.Format(_T("INSERT INTO users (username, password) VALUES ('%s', '%s')"), username, password);
    rc = sqlite3_exec(db, CT2A(query), NULL, 0, &errMsg);
    if (rc == SQLITE_CONSTRAINT) {
    AfxMessageBox(_T("用户名已存在"));
	return ;
    } else if (rc != SQLITE_OK) {
    AfxMessageBox(_T("注册失败"));
    } else {
    AfxMessageBox(_T("注册成功"));
}

    CDialog::OnOK(); // 关闭注册对话框

    sqlite3_close(db);
}
