#include "stdafx.h"
#include "denglu.h"
#include "NewProject.h"
#include "afxdialogex.h"


// CNewProject 对话框

IMPLEMENT_DYNAMIC(CNewProject, CDialogEx)

CNewProject::CNewProject(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewProject::IDD, pParent)
{

	m_CompanyName = _T("");
	m_ContactPerson = _T("");
	//  m_Contactphone = _T("");
	//  m_ProjectID = _T("");
	m_ProjectAddress = _T("");
	m_ProjectName = _T("");
	//  m_ProjectID = _T("");
	//  m_ContactPhone = _T("");
	m_ContactPhone = _T("");
	m_ProjectID = 0;
}

CNewProject::~CNewProject()
{
}

void CNewProject::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_CompanyName);
	//  DDX_Control(pDX, IDC_EDIT2, m_ContactPerson);
	DDX_Text(pDX, IDC_EDIT2, m_ContactPerson);
	//  DDX_Text(pDX, IDC_EDIT3, m_Contactphone);
	//  DDV_MaxChars(pDX, m_Contactphone, 11);
	//  DDX_Text(pDX, IDC_EDIT4, m_ProjectID);
	DDX_Text(pDX, IDC_EDIT5, m_ProjectAddress);
	//  DDX_Control(pDX, IDC_EDIT4, m_ProjectName);
	DDX_Text(pDX, IDC_EDIT4, m_ProjectName);
	//  DDX_Text(pDX, IDC_EDIT6, m_ProjectID);
	//  DDX_Text(pDX, IDC_EDIT3, m_ContactPhone);
	DDX_Text(pDX, IDC_EDIT3, m_ContactPhone);
	DDV_MaxChars(pDX, m_ContactPhone, 11);
	DDX_Text(pDX, IDC_EDIT6, m_ProjectID);
	DDV_MinMaxInt(pDX, m_ProjectID, 0, 10000);
}


BEGIN_MESSAGE_MAP(CNewProject, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT5, &CNewProject::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CNewProject 消息处理程序


void CNewProject::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
