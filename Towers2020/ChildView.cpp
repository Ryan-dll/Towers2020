
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Towers2020.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Game.h"
#include <iostream>

using namespace Gdiplus;

// CChildView

CChildView::CChildView()
{
	//mGame = CGame();
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_LOAD32776, &CChildView::OnFileLoad32776)
	ON_UPDATE_COMMAND_UI(ID_FILE_LOAD32776, &CChildView::OnUpdateFileLoad32776)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

/**
* ChildView's OnPaint function
*/
void CChildView::OnPaint()
{
    CPaintDC paintDC(this);     // device context for painting
    CDoubleBufferDC dc(&paintDC); // device context for painting

    Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}
	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	CRect rect;
    GetClientRect(&rect);
	
	//
	// Prevent tunnelling
	//
	while (elapsed > MaxElapsed)
	{
		mGame.Update(MaxElapsed);

		elapsed -= MaxElapsed;
	}

	// Consume any remaining time
	if (elapsed > 0)
	{
		mGame.Update(elapsed);
	}
	mGame.OnDraw(&graphics, rect.Width(), rect.Height());
}


/**
* File Load
*/
void CChildView::OnFileLoad32776()
{
	CFileDialog dlg(true,  // true = Open dialog box
		L".xml",           // Default file extension
		nullptr,            // Default file name (none)
		0,    // Flags
		L"XML Files (*.xml)|*.xml|All Files (*.*)|*.*||");  // Filter
	if (dlg.DoModal() != IDOK)
		return;

	std::wstring filename = dlg.GetPathName();

	mGame.Load(filename);
	Invalidate();
}


/**
* Load file
* \param: pCmdUI UI
*/
void CChildView::OnUpdateFileLoad32776(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(true);
}


/**
* Override Default function
* \param pDC idk
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return FALSE;
}


/**
 * Handle timer events
 * \param nIDEvent The timer event ID
 */
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}
