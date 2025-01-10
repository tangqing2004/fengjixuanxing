// CalVen.cpp : 实现文件
//

#include "stdafx.h"
#include "denglu.h"
#include "CalVen.h"
#include "afxdialogex.h"


// CCalVen 对话框

IMPLEMENT_DYNAMIC(CCalVen, CDialogEx)

CCalVen::CCalVen(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalVen::IDD, pParent)
{

	//  m_d = 0;
	m_d = 0.0f;
	m_a = 0.0f;
	m_s = 0.0f;
}

CCalVen::~CCalVen()
{
}

void CCalVen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  D//  DX_Text(p//  DX, I//  DC_E//  DIT1, m_d);
	DDX_Text(pDX, IDC_EDIT1, m_d);
	DDX_Text(pDX, IDC_EDIT2, m_a);
	DDX_Text(pDX, IDC_EDIT3, m_s);
}


BEGIN_MESSAGE_MAP(CCalVen, CDialogEx)
END_MESSAGE_MAP()


// CCalVen 消息处理程序
