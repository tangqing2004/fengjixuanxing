// RegisterDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "denglu.h"
#include "RegisterDialog.h"
#include "afxdialogex.h"


// CRegisterDialog �Ի���

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


// CRegisterDialog ��Ϣ�������


void CRegisterDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString username, password,password1;
    GetDlgItemText(IDC_EDIT1, username);
    GetDlgItemText(IDC_EDIT2, password);
	GetDlgItemText(IDC_EDIT3,password1);
	if(password!=password1)
	{
		AfxMessageBox(_T("�������벻��ͬ"));
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
    AfxMessageBox(_T("�û����Ѵ���"));
	return ;
    } else if (rc != SQLITE_OK) {
    AfxMessageBox(_T("ע��ʧ��"));
    } else {
    AfxMessageBox(_T("ע��ɹ�"));
}

    CDialog::OnOK(); // �ر�ע��Ի���

    sqlite3_close(db);
}
