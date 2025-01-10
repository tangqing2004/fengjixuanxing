
#pragma once


// CNewProject 对话框

class CNewProject : public CDialogEx
{
	DECLARE_DYNAMIC(CNewProject)

public:
	CNewProject(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewProject();

// 对话框数据
	enum { IDD = IDD_Project };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
