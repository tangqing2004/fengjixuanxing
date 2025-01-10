#include "stdafx.h"
#include "denglu.h"
#include "NewProject.h"
#include "afxdialogex.h"


// CNewProject �Ի���

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


// CNewProject ��Ϣ�������


void CNewProject::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
