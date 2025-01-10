// LoginDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "denglu.h"
#include "LoginDialog.h"
#include "RegisterDialog.h"
#include "afxdialogex.h"


// CLoginDialog 对话框

IMPLEMENT_DYNAMIC(CLoginDialog, CDialogEx)

CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDialog::IDD, pParent)
{

}

CLoginDialog::~CLoginDialog()
{
}

void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDialog::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CLoginDialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLoginDialog 消息处理程序


void CLoginDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString username, password;
    GetDlgItemText(IDC_EDIT1, username);
    GetDlgItemText(IDC_EDIT2, password);

    sqlite3* db = NULL;
    char* errMsg = NULL;
    int rc = sqlite3_open("mydb.db", &db);
    if (rc != SQLITE_OK) {
        AfxMessageBox(_T("Failed to open database!"));
        return;
    }

    CString query;
    query.Format(_T("SELECT * FROM users WHERE username='%s' AND password='%s'"), username, password);
    sqlite3_stmt* stmt = NULL;
    rc = sqlite3_prepare_v2(db, CT2A(query), -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        AfxMessageBox(_T("Failed to prepare query!"));
        sqlite3_close(db);
        return;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        AfxMessageBox(_T("Login successful!"));
        CDialog::OnOK(); // 关闭登录对话框
    } else {
        AfxMessageBox(_T("Invalid username or password!"));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


void CLoginDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL CLoginDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	sqlite3* db = NULL;
    char* errMsg = NULL;
    int rc = sqlite3_open("mydb.db", &db);
    if (rc != SQLITE_OK) {
        AfxMessageBox(_T("Failed to open database!"));
        return FALSE;
    }

    // 创建表
    const char* sql = "CREATE TABLE IF NOT EXISTS users (username TEXT PRIMARY KEY,password TEXT NOT NULL);"
					  "CREATE TABLE IF NOT EXISTS U_Plink(username TEXT,项目ID INTEGER,项目名称 TEXT NOT NULL,风机型号 TEXT NOT NULL,PRIMARY KEY (username, 项目ID));"
                      "CREATE TABLE IF NOT EXISTS P_Company (甲方公司名称 TEXT, 项目ID INTEGER PRIMARY KEY, 甲方联系人 TEXT, 甲方联系电话 TEXT, 项目地址 TEXT,项目名称 TEXT);"
                      "CREATE TABLE IF NOT EXISTS Ventilation (风机型号 TEXT PRIMARY KEY, 风量 REAL, 风压 REAL);";
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        AfxMessageBox(_T("Failed to create table!"));
        sqlite3_close(db);
        return FALSE;
    }

    sqlite3_close(db);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CLoginDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegisterDialog dlg;
    if (dlg.DoModal() == IDOK) {
        AfxMessageBox(_T("注册成功，请登录！"));
    }
}
