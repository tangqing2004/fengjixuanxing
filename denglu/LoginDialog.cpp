// LoginDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "denglu.h"
#include "LoginDialog.h"
#include "RegisterDialog.h"
#include "afxdialogex.h"


// CLoginDialog �Ի���

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


// CLoginDialog ��Ϣ�������


void CLoginDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
        CDialog::OnOK(); // �رյ�¼�Ի���
    } else {
        AfxMessageBox(_T("Invalid username or password!"));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


void CLoginDialog::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CLoginDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	sqlite3* db = NULL;
    char* errMsg = NULL;
    int rc = sqlite3_open("mydb.db", &db);
    if (rc != SQLITE_OK) {
        AfxMessageBox(_T("Failed to open database!"));
        return FALSE;
    }

    // ������
    const char* sql = "CREATE TABLE IF NOT EXISTS users (username TEXT PRIMARY KEY,password TEXT NOT NULL);"
					  "CREATE TABLE IF NOT EXISTS U_Plink(username TEXT,��ĿID INTEGER,��Ŀ���� TEXT NOT NULL,����ͺ� TEXT NOT NULL,PRIMARY KEY (username, ��ĿID));"
                      "CREATE TABLE IF NOT EXISTS P_Company (�׷���˾���� TEXT, ��ĿID INTEGER PRIMARY KEY, �׷���ϵ�� TEXT, �׷���ϵ�绰 TEXT, ��Ŀ��ַ TEXT,��Ŀ���� TEXT);"
                      "CREATE TABLE IF NOT EXISTS Ventilation (����ͺ� TEXT PRIMARY KEY, ���� REAL, ��ѹ REAL);";
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        AfxMessageBox(_T("Failed to create table!"));
        sqlite3_close(db);
        return FALSE;
    }

    sqlite3_close(db);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CLoginDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRegisterDialog dlg;
    if (dlg.DoModal() == IDOK) {
        AfxMessageBox(_T("ע��ɹ������¼��"));
    }
}
