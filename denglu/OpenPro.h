#pragma once
#include "afxcmn.h"


// COpenPro 对话框

class COpenPro : public CDialogEx
{
	DECLARE_DYNAMIC(COpenPro)

public:
	COpenPro(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COpenPro();
	int projectID;
	CString companyName;
	CString contactPerson;
	CString contactPhone;
	CString projectName;
	CString projectAddress;

// 对话框数据
	enum { IDD = IDD_OpenProject };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl* m_ProjectList;
//	afx_msg void OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	void LoadData(void);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
