// dengluView.cpp : CdengluView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "denglu.h"
#endif

#include "dengluDoc.h"
#include "dengluView.h"
#include "NewProject.h"
#include "CalVen.h"
#include "SelVen.h"
#include "SelectAlgo.h"
#include "sqlite3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdengluView

IMPLEMENT_DYNCREATE(CdengluView, CView)

BEGIN_MESSAGE_MAP(CdengluView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CdengluView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_NewPro, &CdengluView::OnNewpro)
	ON_COMMAND(ID_OpenPro, &CdengluView::OnOpenpro)
//	ON_COMMAND(IDC_LIST1, &CdengluView::OnList1)
ON_COMMAND(ID_CalV, &CdengluView::OnCalv)
ON_COMMAND(ID_SelV, &CdengluView::OnSelv)
END_MESSAGE_MAP()

// CdengluView 构造/析构

CdengluView::CdengluView()
{
	// TODO: 在此处添加构造代码
	projectID=0;
	isprint=false;
	isversion=false;
	m_venversion = L"SDF(B)-4-No9.6";
	BITMAP BM;
	Bit_SDF_4_No9_6.LoadBitmap(IDB_BITMAP1);
	Bit_SDF_4_No9_6.GetBitmap(&BM);
	m_Height=BM.bmHeight;
	m_Width=BM.bmWidth;
}

CdengluView::~CdengluView()
{
}

BOOL CdengluView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdengluView 绘制

void CdengluView::OnDraw(CDC* pDC)
{
	CdengluDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->SetTextColor(RGB(255,0,0));
	pDC->TextOut(300,50,_T("您好,欢迎使用隧道风机选型系统"));
	if(projectID != 0)
		CreateMessage(pDC);//绘制项目信息
	if(isprint)
	    CreateVen(pDC);
	if(isversion)
		CreateVenversion(pDC);
}


// CdengluView 打印


void CdengluView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdengluView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdengluView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdengluView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CdengluView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdengluView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CdengluView 诊断

#ifdef _DEBUG
void CdengluView::AssertValid() const
{
	CView::AssertValid();
}

void CdengluView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdengluDoc* CdengluView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdengluDoc)));
	return (CdengluDoc*)m_pDocument;
}
#endif //_DEBUG


// CdengluView 消息处理程序


void CdengluView::OnNewpro()
{
	// TODO: 在此添加命令处理程序代码
	CNewProject dlg;
	 if (dlg.DoModal() == IDOK) {
        companyName = dlg.m_CompanyName;
        contactPerson = dlg.m_ContactPerson;
        contactPhone = dlg.m_ContactPhone;
        projectID = dlg.m_ProjectID;
        projectAddress = dlg.m_ProjectAddress;
		projectName = dlg.m_ProjectName;

        CString sql;
        sql.Format(_T("INSERT INTO P_Company (甲方公司名称,项目ID,甲方联系人, 甲方联系电话, 项目地址,项目名称) VALUES ('%s','%d', '%s', '%s', '%s','%s');"),
               companyName, projectID,contactPerson, contactPhone, projectAddress,projectName);
    // 将 CString 转换为 UTF-8 编码的 const char*
    CStringA sqlUTF8(sql);

    sqlite3* db;
    int rc = sqlite3_open("mydb.db", &db);
    if (rc) {
        AfxMessageBox(_T("无法打开数据库"));
        return;
    }

    char* errMsg;
    rc = sqlite3_exec(db, sqlUTF8, 0, 0, &errMsg); // 使用 sqlUTF8
    if (rc != SQLITE_OK) {
        AfxMessageBox(CString(errMsg));
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
    }
	 Invalidate();
}


void CdengluView::CreateMessage(CDC * pDC)
{
	int x = 50;
    int y = 100;
    int lineHeight = 50;
    // 绘制项目信息
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(x, y, _T("当前项目信息: ") );
    y += lineHeight;
    pDC->TextOut(x, y, _T("甲方公司名称: ") + companyName);
    y += lineHeight;
	CString strDisplay;
    strDisplay.Format(L"项目ID: %d",projectID);
	pDC->TextOut(x, y,strDisplay);
    y += lineHeight;
    pDC->TextOut(x, y, _T("甲方联系人: ") + contactPerson);
    y += lineHeight;
    pDC->TextOut(x, y, _T("甲方联系人电话: ") + contactPhone);
    y += lineHeight;
    pDC->TextOut(x, y, _T("项目名称: ") + projectName);
    y += lineHeight;
    pDC->TextOut(x, y, _T("项目地点: ") + projectAddress);
}


void CdengluView::OnOpenpro()
{
	// TODO: 在此添加命令处理程序代码
	COpenPro dlg;
	
	if(dlg.DoModal()==IDOK)
	{
// 获取数据
		projectID = dlg.projectID;
		companyName = dlg.companyName;
		contactPerson = dlg.contactPerson;
		contactPhone = dlg.contactPhone;
		projectName = dlg.projectName;
		projectAddress = dlg.projectAddress;
	}
	Invalidate();
}

void CdengluView::OnCalv()
{
	// TODO: 在此添加命令处理程序代码
	CCalVen dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_d=dlg.m_d;
		m_a=dlg.m_a;
		m_s=dlg.m_s;
		isprint=true;
	}
	Invalidate();
}


void CdengluView::CreateVen(CDC* pDC)
{
	CSelectAlgo ven;
	ven.calculateFanSpecs(m_d,m_a,m_s);
	int x = 500;
    int y = 100;
    int lineHeight = 50;
    // 绘制项目信息
	pDC->SetTextColor(RGB(0,0,0));
	CString str;
	str.Format(L"隧道直径:%f,海拔高度:%f,斜道坡度:%f",m_d,m_a,m_s);
	pDC->TextOut(x, y, _T("隧道参数: ")+ str);
    y += lineHeight;
	pDC->TextOut(x, y, _T("需要风机的参数: "));
    y += lineHeight;
	str.Format(L"风量:%f m³/h",ven.airFlow);
	pDC->TextOut(x, y, str);
    y += lineHeight;
	str.Format(L"全压:%f Pa",ven.totalPressure);
	pDC->TextOut(x, y,str);
    y += lineHeight;
	str.Format(L"功率:%f kW",ven.power);
    pDC->TextOut(x, y,str);
    y += lineHeight;
	str.Format(L"转速:%f rpm",ven.rotationSpeed);
    pDC->TextOut(x, y, str);
    y += lineHeight;
	str.Format(L"比转数:%f",ven.specificSpeed);
    pDC->TextOut(x, y,str);
    y += lineHeight;
	str.Format(L"噪声水平:%f dB",ven.noiseLevel);
    pDC->TextOut(x, y,str);

}


void CdengluView::OnSelv()
{
	// TODO: 在此添加命令处理程序代码
	CSelVen dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_airflow=dlg.m_airflow;
		m_airpressure=dlg.m_airpressure;
		isversion = true;
	}
	Invalidate();
}


#include <Python.h>

void CdengluView::CreateVenversion(CDC* pDC)
{
    int x = 50;
    int y = 550;
    int lineHeight = 50;

    // 绘制项目信息
    pDC->SetTextColor(RGB(0, 0, 0));
    pDC->TextOut(x, y, _T("风机选型: "));
    y += lineHeight;

    CString str;
    str.Format(L"风量: %f, 风压: %f", m_airflow, m_airpressure);
    pDC->TextOut(x, y, str);
    y += lineHeight;

    // 初始化 Python 解释器
    if (!Py_IsInitialized()) {
        Py_Initialize();
        if (!Py_IsInitialized()) {
            AfxMessageBox(_T("Python 初始化失败！"));
            return;
        }
    }

    // 添加当前目录到 Python 模块搜索路径
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");

    // 加载 Python 模块
    PyObject* pModule = PyImport_ImportModule("decisionTree");
    if (!pModule) {
        PyErr_Print();  // 打印 Python 错误信息
        AfxMessageBox(_T("无法加载 Python 模块！"));
        return;
    }

    // 获取 Python 函数
    PyObject* pFunc = PyObject_GetAttrString(pModule, "decisiontree");
    if (!pFunc || !PyCallable_Check(pFunc)) {
        AfxMessageBox(_T("无法找到 Python 函数！"));
        Py_XDECREF(pModule);
        return;
    }

    // 准备参数
    PyObject* pArgs = PyTuple_New(2);
    if (!pArgs) {
        AfxMessageBox(_T("无法创建参数元组！"));
        Py_XDECREF(pFunc);
        Py_XDECREF(pModule);
        return;
    }

    PyTuple_SetItem(pArgs, 0, PyFloat_FromDouble(m_airflow));
    PyTuple_SetItem(pArgs, 1, PyFloat_FromDouble(m_airpressure));

    // 调用 Python 函数
    PyObject* pResult = PyObject_CallObject(pFunc, pArgs);
    if (!pResult) {
        PyErr_Print();  // 打印 Python 错误信息
        AfxMessageBox(_T("Python 函数调用失败！"));
        Py_XDECREF(pArgs);
        Py_XDECREF(pFunc);
        Py_XDECREF(pModule);
        return;
    }

    // 解析返回值
    if (PyDict_Check(pResult)) {
        PyObject* pKey, * pValue;
        Py_ssize_t pos = 0;

        while (PyDict_Next(pResult, &pos, &pKey, &pValue)) {
            // 获取键和值
            wchar_t* keyWChar = PyUnicode_AsWideCharString(pKey, NULL);
            wchar_t* valueWChar = PyUnicode_AsWideCharString(pValue, NULL);

            if (keyWChar && valueWChar) {
                // 转换为 CString
                CString key(keyWChar);
                CString value(valueWChar);

                // 绘制结果
                CString resultStr;
                resultStr.Format(L"%s: %s", key, value);
                pDC->TextOut(x, y, resultStr);
                y += lineHeight;
            }

            // 释放 Python 分配的内存
            if (keyWChar) PyMem_Free(keyWChar);
            if (valueWChar) PyMem_Free(valueWChar);
        }
    }
    else {
        AfxMessageBox(_T("返回值不是字典类型！"));
    }

    // 清理
    Py_XDECREF(pArgs);
    Py_XDECREF(pResult);
    Py_XDECREF(pFunc);
    Py_XDECREF(pModule);

    // 绘制风机型号
    pDC->TextOut(x, y, _T("风机型号: ") + m_venversion);
    y += lineHeight;

    // 绘制图片
    CDC MemDC_ven;
    MemDC_ven.CreateCompatibleDC(NULL);
    MemDC_ven.SelectObject(&Bit_SDF_4_No9_6);
    pDC->StretchBlt(450, 550, m_Width, m_Height, &MemDC_ven, 0, 0, m_Width, m_Height, SRCCOPY);
}
