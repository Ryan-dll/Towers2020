
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
	ON_COMMAND(ID_FILE_LOAD32776, &CChildView::OnFileLoad)
	ON_UPDATE_COMMAND_UI(ID_FILE_LOAD32776, &CChildView::OnUpdateFileLoad32776)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_LEVELS_LEVEL0, &CChildView::OnLevelsLevel0)
	ON_COMMAND(ID_LEVELS_LEVEL1, &CChildView::OnLevelsLevel1)
	ON_COMMAND(ID_LEVELS_LEVEL2, &CChildView::OnLevelsLevel2)
	ON_COMMAND(ID_FILE_SAVEAS, &CChildView::OnFileSaveas)
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

    Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context]

	CRect rect;
	GetClientRect(&rect);

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

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());
	
	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;
	
	//
	// Prevent tunnelling
	//
	while (elapsed > MaxElapsed)
	{
		mGame.Update(MaxElapsed);

		elapsed -= MaxElapsed;
	}

	if (mLevelStart)
	{
		mMessage.DrawBeginMessage(&graphics, mLevel);
		if (!mDisplayed)
		{
			mDisplayTime = time.QuadPart;
			mDisplayed = true;
		}
	}
	long long continued = time.QuadPart - mDisplayTime;
	double passTime = double(continued) / mTimeFreq;
	if (passTime > 1)
	{
		mLevelStart = false;
	}

	// Consume any remaining time
	if (elapsed > 0)
	{
		mGame.Update(elapsed);
	}
	
}


/**
* File Load
*/
void CChildView::OnFileLoad()
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


/**
 * Called when there is a left mouse button press
 * \param nFlags Flags associated with the mouse button press
 * \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	mGame.OnLButtonDown(point.x, point.y);
	Invalidate();
}

/**
 * Called when the left mouse button is released
 * \param nFlags Flags associated with the mouse button release
 * \param point Where the button was pressed
 */
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	OnMouseMove(nFlags, point);
}

/**
 * Called when the mouse is moved
 * \param nFlags Flags associated with the mouse movement
 * \param point Where the button was pressed
 */
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	mGame.OnMouseMove(nFlags, point.x, point.y);
	Invalidate();
}


void CChildView::OnLevelsLevel0()
{
	std::wstring filename = L"levels\\level0.xml";
	mGame.Load(filename);
	mLevelStart = true;
	mLevel = 0;
	mDisplayed = false;
	Invalidate();
}


void CChildView::OnLevelsLevel1()
{
	std::wstring filename = L"levels\\level1.xml";
	mGame.Load(filename);
	mLevelStart = true;
	mLevel = 1;
	mDisplayed = false;
	Invalidate();
}


void CChildView::OnLevelsLevel2()
{
	std::wstring filename = L"levels\\level2.xml";
	mGame.Load(filename);
	mLevelStart = true;
	mLevel = 2;
	mDisplayed = false;
	Invalidate();
}


void CChildView::OnFileSaveas()
{
	CFileDialog dlg(false,  // false = Save dialog box
		L".tower",           // Default file extension
		nullptr,            // Default file name (none)
		OFN_OVERWRITEPROMPT,    // Flags
		L"Tower Files (*.tower)|*.tower|All Files (*.*)|*.*||");    // Filter
	if (dlg.DoModal() != IDOK)
		return;

	std::wstring filename = dlg.GetPathName();

	mGame.Save(filename);
}
