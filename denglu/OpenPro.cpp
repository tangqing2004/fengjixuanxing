// OpenPro.cpp : 实现文件
//

#include "stdafx.h"
#include "denglu.h"
#include "OpenPro.h"
#include "afxdialogex.h"
#include "sqlite3.h"


// COpenPro 对话框

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
    // 在这里添加消息映射
	ON_BN_CLICKED(IDCANCEL, &COpenPro::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &COpenPro::OnItemchangedList1)
END_MESSAGE_MAP()

// COpenPro 消息处理程序
BOOL COpenPro::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	 // 获取 List Control 控件
    CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);

    // 添加列标题
    pListCtrl->InsertColumn(0, _T("甲方公司名称"), LVCFMT_LEFT, 100);
    pListCtrl->InsertColumn(1, _T("项目ID"), LVCFMT_LEFT, 80);
    pListCtrl->InsertColumn(2, _T("甲方联系人"), LVCFMT_LEFT, 100);
    pListCtrl->InsertColumn(3, _T("甲方联系电话"), LVCFMT_LEFT, 100);
    pListCtrl->InsertColumn(4, _T("项目地址"), LVCFMT_LEFT, 150);
    pListCtrl->InsertColumn(5, _T("项目名称"), LVCFMT_LEFT, 150);
	pListCtrl->SetExtendedStyle(pListCtrl->GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	LoadData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void COpenPro::LoadData(void)
{
	sqlite3* db;
    sqlite3_stmt* stmt;
    CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);

    // 打开数据库
    if (sqlite3_open("mydb.db", &db) == SQLITE_OK)
    {
        // 准备 SQL 查询
        const char* sql = "SELECT * FROM P_Company";
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK)
        {
            int index = 0;
            // 遍历查询结果
            while (sqlite3_step(stmt) == SQLITE_ROW)
            {
                // 获取每一列的数据
                CString companyName = CString((const char*)sqlite3_column_text(stmt, 0));
                int projectID = sqlite3_column_int(stmt, 1);
                CString contactPerson = CString((const char*)sqlite3_column_text(stmt, 2));
                CString contactPhone = CString((const char*)sqlite3_column_text(stmt, 3));
                CString projectAddress = CString((const char*)sqlite3_column_text(stmt, 4));
                CString projectName = CString((const char*)sqlite3_column_text(stmt, 5));

                // 插入数据到 List Control
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
        AfxMessageBox(_T("无法打开数据库！"));
    }
}


void COpenPro::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void COpenPro::OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	// 获取选中的项目
        CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
        POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
        if (pos != NULL)
        {
            int nItem = pListCtrl->GetNextSelectedItem(pos);
			
            // 获取数据
            projectID = _ttoi(pListCtrl->GetItemText(nItem, 1));
            companyName = pListCtrl->GetItemText(nItem, 0);
            contactPerson = pListCtrl->GetItemText(nItem, 2);
            contactPhone = pListCtrl->GetItemText(nItem, 3);
            projectName = pListCtrl->GetItemText(nItem, 5);
            projectAddress = pListCtrl->GetItemText(nItem, 4);
        }
	*pResult = 0;
}
