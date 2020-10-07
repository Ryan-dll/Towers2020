
// Towers2020View.h : interface of the CTowers2020View class
//

#pragma once


class CTowers2020View : public CView
{
protected: // create from serialization only
	CTowers2020View() noexcept;
	DECLARE_DYNCREATE(CTowers2020View)

// Attributes
public:
	CTowers2020Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTowers2020View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Towers2020View.cpp
inline CTowers2020Doc* CTowers2020View::GetDocument() const
   { return reinterpret_cast<CTowers2020Doc*>(m_pDocument); }
#endif

