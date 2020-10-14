/**
 * \file Towers2020.h
 *
 * \author Craig Smith
 *
 * Main header file for the Towers2020 application
 */

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTowers2020App:
// See Towers2020.cpp for the implementation of this class
//

/**
*CTowers2020App:
*/
class CTowers2020App : public CWinApp
{
public:
	CTowers2020App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CTowers2020App theApp;
