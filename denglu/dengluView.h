
// dengluView.h : CdengluView 类的接口
//

#pragma once
#include "OpenPro.h"

class CdengluView : public CView
{
protected: // 仅从序列化创建
	CdengluView();
	DECLARE_DYNCREATE(CdengluView)

// 特性
public:
	CdengluDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CdengluView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CString companyName;      // 甲方公司名称
    CString contactPerson;    // 甲方联系人
    CString contactPhone;     // 甲方联系人电话
    CString projectName;      // 项目名称
    CString projectAddress;   // 项目地点
	int projectID;        // 项目ID
	float m_d;//隧道直径
	float m_a;//海拔高度
	float m_s;//坡道斜度
	//风量
    double airFlow;
    //全压
    double totalPressure;
    //计算功率
    double power;
    // 计算转速
    double rotationSpeed;
    // 计算比转数
    double specificSpeed;
    // 计算噪声水平
    double noiseLevel;
	 // 计算风机规格
	bool isprint;//是否绘制风机所需参数
	bool isversion;//是否绘制风机型号
	float m_airflow;//选型的风量
	float m_airpressure;//选型的风压
	CString m_venversion;//风机型号
	CBitmap Bit_SDF_4_No9_6;//型号图片
	int m_Height;
	int m_Width;
// 生成的消息映射函数
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

#ifndef _DEBUG  // dengluView.cpp 中的调试版本
inline CdengluDoc* CdengluView::GetDocument() const
   { return reinterpret_cast<CdengluDoc*>(m_pDocument); }
#endif

