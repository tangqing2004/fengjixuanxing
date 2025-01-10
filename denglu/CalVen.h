#pragma once
#include "stdafx.h"
#include "denglu.h"
#include "afxdialogex.h"

// CCalVen 对话框

class CCalVen : public CDialogEx
{
	DECLARE_DYNAMIC(CCalVen)

public:
	CCalVen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCalVen();

// 对话框数据
	enum { IDD = IDD_CalVen };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	int m_d;
	float m_d;//隧道直径
	float m_a;//海拔高度
	float m_s;//坡道斜度
};
