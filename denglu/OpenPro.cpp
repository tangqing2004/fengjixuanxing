// OpenPro.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "denglu.h"
#include "OpenPro.h"
#include "afxdialogex.h"
#include "sqlite3.h"


// COpenPro �Ի���

IMPLEMENT_DYNAMIC(COpenPro, CDialogEx)

COpenPro::COpenPro(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpenPro::IDD, pParent)
{
	projectID = 0;
}

COpenPro::~COpenPro()
{
}

void COpenPro::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, m_ProjectList);
}

BEGIN_MESSAGE_MAP(COpenPro, CDialogEx)
    // �����������Ϣӳ��
	ON_BN_CLICKED(IDCANCEL, &COpenPro::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &COpenPro::OnItemchangedList1)
END_MESSAGE_MAP()

// COpenPro ��Ϣ�������
BOOL COpenPro::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	 // ��ȡ List Control �ؼ�
    CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);

    // ����б���
    pListCtrl->InsertColumn(0, _T("�׷���˾����"), LVCFMT_LEFT, 100);
    pListCtrl->InsertColumn(1, _T("��ĿID"), LVCFMT_LEFT, 80);
    pListCtrl->InsertColumn(2, _T("�׷���ϵ��"), LVCFMT_LEFT, 100);
    pListCtrl->InsertColumn(3, _T("�׷���ϵ�绰"), LVCFMT_LEFT, 100);
    pListCtrl->InsertColumn(4, _T("��Ŀ��ַ"), LVCFMT_LEFT, 150);
    pListCtrl->InsertColumn(5, _T("��Ŀ����"), LVCFMT_LEFT, 150);
	pListCtrl->SetExtendedStyle(pListCtrl->GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	LoadData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void COpenPro::LoadData(void)
{
	sqlite3* db;
    sqlite3_stmt* stmt;
    CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);

    // �����ݿ�
    if (sqlite3_open("mydb.db", &db) == SQLITE_OK)
    {
        // ׼�� SQL ��ѯ
        const char* sql = "SELECT * FROM P_Company";
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
        {
            int index = 0;
            // ������ѯ���
            while (sqlite3_step(stmt) == SQLITE_ROW)
            {
                // ��ȡÿһ�е�����
                CString companyName = CString((const char*)sqlite3_column_text(stmt, 0));
                int projectID = sqlite3_column_int(stmt, 1);
                CString contactPerson = CString((const char*)sqlite3_column_text(stmt, 2));
                CString contactPhone = CString((const char*)sqlite3_column_text(stmt, 3));
                CString projectAddress = CString((const char*)sqlite3_column_text(stmt, 4));
                CString projectName = CString((const char*)sqlite3_column_text(stmt, 5));

                // �������ݵ� List Control
				CString str;
				str.Format(L"%d",projectID);
                pListCtrl->InsertItem(index, companyName);
                pListCtrl->SetItemText(index, 1, str);
                pListCtrl->SetItemText(index, 2, contactPerson);
                pListCtrl->SetItemText(index, 3, contactPhone);
                pListCtrl->SetItemText(index, 4, projectAddress);
                pListCtrl->SetItemText(index, 5, projectName);

                index++;
            }
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
    else
    {
        AfxMessageBox(_T("�޷������ݿ⣡"));
    }
}


void COpenPro::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void COpenPro::OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ��ȡѡ�е���Ŀ
        CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
        POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
        if (pos != NULL)
        {
            int nItem = pListCtrl->GetNextSelectedItem(pos);
			
            // ��ȡ����
            projectID = _ttoi(pListCtrl->GetItemText(nItem, 1));
            companyName = pListCtrl->GetItemText(nItem, 0);
            contactPerson = pListCtrl->GetItemText(nItem, 2);
            contactPhone = pListCtrl->GetItemText(nItem, 3);
            projectName = pListCtrl->GetItemText(nItem, 5);
            projectAddress = pListCtrl->GetItemText(nItem, 4);
        }
	*pResult = 0;
}
