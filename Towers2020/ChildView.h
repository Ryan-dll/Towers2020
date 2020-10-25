
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"
#include "Message.h"

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
* CChildView window
*/
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

private:
	/// An object that describes our Game
	CGame mGame;
	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

// Attributes
private:
	/// Maximum amount of time to allow for elapsed
	const double MaxElapsed = 0.050;
	/// True until the first time we draw
	bool mFirstDraw = true;
	/// Last time we read the timer
	long long mLastTime = 0;
	/// Rate the timer updates
	double mTimeFreq = 0;

	/// The in-game message
	CMessage mMessage;
	/// The level number
	int mLevel = 1;
	/// Indicator of whether draw start message
	bool mLevelStart = false;
	/// Indicator of whether displayed or not
	bool mDisplayed = false;
	/// The message timer
	long long mDisplayTime = 0;

// Operations
public:

// Overrides
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnFileLoad();
	afx_msg void OnUpdateFileLoad32776(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLevelsLevel0();
	afx_msg void OnLevelsLevel1();
	afx_msg void OnLevelsLevel2();
	afx_msg void OnFileSaveas();
};

