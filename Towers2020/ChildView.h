
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"


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
public:

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
};

