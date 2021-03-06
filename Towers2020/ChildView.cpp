
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
#include "BalloonCollector.h"

using namespace Gdiplus;

// CChildView

CChildView::CChildView()
{
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
	ON_COMMAND(ID_LEVELS_LEVEL3, &CChildView::OnLevelsLevel3)
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

		std::wstring filename = L"levels\\level1.xml";
		mGame.Load(filename);
		mLevelStart = true;
		mLevel = 1;
		mDisplayed = false;
	}

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

	// Consume any remaining time
	if (elapsed > 0)
	{
		mGame.Update(elapsed);
	}

	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting

	Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context]

	CRect rect;
	GetClientRect(&rect);


	mGame.OnDraw(&graphics, rect.Width(), rect.Height());


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

	CBalloonCollector bc;
	mGame.Accept(&bc);

	if (mGame.GetGameActive() && !mStarted)
	{
		mStartTime = time.QuadPart;
		mStarted = true;
	}

	if (mGame.GetGameActive()) {
		long long timer = time.QuadPart - mStartTime;
		double timePassed = double(timer) / mTimeFreq;
		
		if (timePassed > 3 && mDisplayed && !mLevelStart && mGame.GetGameActive() && bc.GetBalloons().size() == 0)
		{

			if (!mEndMessageShown)
			{
				mEndMessageTime = time.QuadPart;
				mEndMessageShown = true;
			}

			long long timer = time.QuadPart - mEndMessageTime;
			double timePassed = double(timer) / mTimeFreq;
			if (timePassed < 3) {
				mMessage.DrawEndMessage(&graphics);
			}
			else
			{
				// Reset game and load next level
				if (mLevel == 1)
				{
					mGame.SetGameActive(false);
					std::wstring filename = L"levels\\level2.xml";
					mGame.Load(filename);
					mLevelStart = true;
					mLevel = 2;
					mDisplayed = false;
					mStarted = false;
					mEndMessageShown = false;
					Invalidate();
				}
				else if (mLevel == 2)
				{
					mGame.SetGameActive(false);
					std::wstring filename = L"levels\\level3.xml";
					mGame.Load(filename);
					mLevelStart = true;
					mLevel = 3;
					mDisplayed = false;
					mStarted = false;
					mEndMessageShown = false;
					Invalidate();
				}
				else if(mLevel == 3)
				{
					mGame.SetGameActive(false);
					std::wstring filename = L"levels\\level3.xml";
					mGame.Load(filename);
					mLevelStart = true;
					mLevel = 3;
					mDisplayed = false;
					mStarted = false;
					mEndMessageShown = false;
					Invalidate();
				}
			}
		}
	}


/*
	CBalloonCollector bc;
	mGame.Accept(&bc);

	if (mLevelStart2)
	{
		if (bc.GetBalloons().size() == 0)
		{
			mMessage.DrawEndMessage(&graphics);
		}

		if (!mDisplayed2)
		{
			mDisplayTime2 = time.QuadPart;
			mDisplayed2 = true;
		}
	}
	long long continued2 = time.QuadPart - mDisplayTime2;
	double passTime2 = double(continued2) / mTimeFreq;
	if (passTime2 > 1)
	{
		mLevelStart2 = false;
	}
*/
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
* \param pCmdUI UIA
*/
void CChildView::OnUpdateFileLoad32776(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(true);
}


/**
* Override Default function
* \param pDC idk
* \return BOOL
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
	mGame.OnLButtonUp(point.x,point.y);
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


/**
 * Called when the user selects Level 0
 */
void CChildView::OnLevelsLevel0()
{
	std::wstring filename = L"levels\\level0.xml";
	mGame.Load(filename);
	mLevelStart = true;
	mLevel = 0;
	mDisplayed = false;
	Invalidate();
}


/**
 * Called when the user selects Level 1
 */
void CChildView::OnLevelsLevel1()
{
	std::wstring filename = L"levels\\level1.xml";
	mGame.Load(filename);
	mLevelStart = true;
	mLevel = 1;
	mDisplayed = false;
	Invalidate();
}


/**
 * Called when the user selects Level 2
 */
void CChildView::OnLevelsLevel2()
{
	std::wstring filename = L"levels\\level2.xml";
	mGame.Load(filename);
	mLevelStart = true;
	mLevel = 2;
	mDisplayed = false;
	Invalidate();
}


/**
 * Called when the user selects Level 3
 */
void CChildView::OnLevelsLevel3()
{
	std::wstring filename = L"levels\\level3.xml";
	mGame.Load(filename);
	mLevelStart = true;
	mLevel = 3;
	mDisplayed = false;
	Invalidate();
}

/**
 * Called when the user selects Save
 */
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


