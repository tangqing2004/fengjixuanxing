
// dengluView.h : CdengluView ��Ľӿ�
//

#pragma once
#include "OpenPro.h"

class CdengluView : public CView
{
protected: // �������л�����
	CdengluView();
	DECLARE_DYNCREATE(CdengluView)

// ����
public:
	CdengluDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CdengluView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CString companyName;      // �׷���˾����
    CString contactPerson;    // �׷���ϵ��
    CString contactPhone;     // �׷���ϵ�˵绰
    CString projectName;      // ��Ŀ����
    CString projectAddress;   // ��Ŀ�ص�
	int projectID;        // ��ĿID
	float m_d;//���ֱ��
	float m_a;//���θ߶�
	float m_s;//�µ�б��
	//����
    double airFlow;
    //ȫѹ
    double totalPressure;
    //���㹦��
    double power;
    // ����ת��
    double rotationSpeed;
    // �����ת��
    double specificSpeed;
    // ��������ˮƽ
    double noiseLevel;
	 // ���������
	bool isprint;//�Ƿ���Ʒ���������
	bool isversion;//�Ƿ���Ʒ���ͺ�
	float m_airflow;//ѡ�͵ķ���
	float m_airpressure;//ѡ�͵ķ�ѹ
	CString m_venversion;//����ͺ�
	CBitmap Bit_SDF_4_No9_6;//�ͺ�ͼƬ
	int m_Height;
	int m_Width;
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNewpro();
	void CreateMessage(CDC * pDC);
	afx_msg void OnOpenpro();
//	virtual void OnInitialUpdate();
	CListCtrl m_ProjectList;
//	void LoadProjectData(void);
//	afx_msg void OnList1();
	afx_msg void OnCalv();
	void CreateVen(CDC* pDC);
	afx_msg void OnSelv();
	void CreateVenversion(CDC * pDC);
};

#ifndef _DEBUG  // dengluView.cpp �еĵ��԰汾
inline CdengluDoc* CdengluView::GetDocument() const
   { return reinterpret_cast<CdengluDoc*>(m_pDocument); }
#endif

