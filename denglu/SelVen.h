#pragma once


// CSelVen 对话框

class CSelVen : public CDialogEx
{
	DECLARE_DYNAMIC(CSelVen)

public:
	CSelVen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelVen();

// 对话框数据
	enum { IDD = IDD_SelVen };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float m_airflow;
	float m_airpressure;
};
