
#pragma once


// CNewProject �Ի���

class CNewProject : public CDialogEx
{
	DECLARE_DYNAMIC(CNewProject)

public:
	CNewProject(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewProject();

// �Ի�������
	enum { IDD = IDD_Project };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_CompanyName;
//	CEdit m_ContactPerson;
	CString m_ContactPerson;
//	CString m_Contactphone;
//	CString m_ProjectID;
	CString m_ProjectAddress;
	afx_msg void OnEnChangeEdit5();
//	CEdit m_ProjectName;
	CString m_ProjectName;
//	CString m_ProjectID;
//	CString m_ContactPhone;
	CString m_ContactPhone;
	int m_ProjectID;
};
