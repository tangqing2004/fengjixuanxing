#pragma once
#include "stdafx.h"
#include "denglu.h"
#include "afxdialogex.h"

// CCalVen �Ի���

class CCalVen : public CDialogEx
{
	DECLARE_DYNAMIC(CCalVen)

public:
	CCalVen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCalVen();

// �Ի�������
	enum { IDD = IDD_CalVen };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	int m_d;
	float m_d;//���ֱ��
	float m_a;//���θ߶�
	float m_s;//�µ�б��
};
