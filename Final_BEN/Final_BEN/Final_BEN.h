
// Final_BEN.h : main header file for the PROJECT_NAME application
//

#pragma once

#include <stdlib.h>
#include <vector>
#include <iterator>

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFinalBENApp:
// See Final_BEN.cpp for the implementation of this class
//

class CFinalBENApp : public CWinApp
{
public:
	CFinalBENApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFinalBENApp theApp;
