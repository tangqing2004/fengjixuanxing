// SelVen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "denglu.h"
#include "SelVen.h"
#include "afxdialogex.h"


// CSelVen �Ի���

IMPLEMENT_DYNAMIC(CSelVen, CDialogEx)

CSelVen::CSelVen(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelVen::IDD, pParent)
	, m_airflow(0)
	, m_airpressure(0)
{

}

CSelVen::~CSelVen()
{
}

void CSelVen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_airflow);
	DDX_Text(pDX, IDC_EDIT2, m_airpressure);
}


BEGIN_MESSAGE_MAP(CSelVen, CDialogEx)
END_MESSAGE_MAP()


// CSelVen ��Ϣ�������
