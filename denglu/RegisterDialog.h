#pragma once


// CRegisterDialog �Ի���

class CRegisterDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterDialog)

public:
	CRegisterDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
