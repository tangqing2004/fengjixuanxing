#pragma once


// CSelVen �Ի���

class CSelVen : public CDialogEx
{
	DECLARE_DYNAMIC(CSelVen)

public:
	CSelVen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelVen();

// �Ի�������
	enum { IDD = IDD_SelVen };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	float m_airflow;
	float m_airpressure;
};
