
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"

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

	afx_msg void OnFileLoad32776();
	afx_msg void OnUpdateFileLoad32776(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

