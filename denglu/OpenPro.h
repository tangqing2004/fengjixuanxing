#pragma once
#include "afxcmn.h"


// COpenPro �Ի���

class COpenPro : public CDialogEx
{
	DECLARE_DYNAMIC(COpenPro)

public:
	COpenPro(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COpenPro();
	int projectID;
	CString companyName;
	CString contactPerson;
	CString contactPhone;
	CString projectName;
	CString projectAddress;

// �Ի�������
	enum { IDD = IDD_OpenProject };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl* m_ProjectList;
//	afx_msg void OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	void LoadData(void);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
