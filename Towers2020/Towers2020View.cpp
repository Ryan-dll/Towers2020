
// Towers2020View.cpp : implementation of the CTowers2020View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Towers2020.h"
#endif

#include "Towers2020Doc.h"
#include "Towers2020View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTowers2020View

IMPLEMENT_DYNCREATE(CTowers2020View, CView)

BEGIN_MESSAGE_MAP(CTowers2020View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTowers2020View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTowers2020View construction/destruction

CTowers2020View::CTowers2020View() noexcept
{
	// TODO: add construction code here

}

CTowers2020View::~CTowers2020View()
{
}

BOOL CTowers2020View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTowers2020View drawing

void CTowers2020View::OnDraw(CDC* /*pDC*/)
{
	CTowers2020Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTowers2020View printing


void CTowers2020View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTowers2020View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTowers2020View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTowers2020View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTowers2020View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTowers2020View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTowers2020View diagnostics

#ifdef _DEBUG
void CTowers2020View::AssertValid() const
{
	CView::AssertValid();
}

void CTowers2020View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTowers2020Doc* CTowers2020View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTowers2020Doc)));
	return (CTowers2020Doc*)m_pDocument;
}
#endif //_DEBUG


// CTowers2020View message handlers
