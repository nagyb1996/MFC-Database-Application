
// Final_BENDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Final_BEN.h"
#include "Final_BENDlg.h"
#include "afxdialogex.h"
#include "View_Entry_Dialog_Class.h"
#include "Add_Entry_Class.h"
#include "Person.h"
#include "WIT_Student.h"
#include "WIT_Staff.h"
#include "WIT_Faculty.h"

#include <fstream>
#include <stdlib.h>  
#include <iterator> // for iterators
#include <vector> // for vectors

using namespace std;

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

vector <Person*> CFinalBENDlg::CreateVector()
{
	int type = -1;
	vector <Person*> people;

	ifstream in("array.txt");
	string data;

	if (in.good())
	{
		while (getline(in, data))
		{
			if (data == "Student")
			{
				WIT_Student * p_test = new WIT_Student("", "", "", "","");
				in >> *p_test;
				people.push_back(p_test);
			}
			else if (data == "Faculty")
			{
				WIT_Faculty * p_test = new WIT_Faculty("", "", "", "","");
				in >> *p_test;
				people.push_back(p_test);
			}
			else if (data == "Staff")
			{
				WIT_Staff * p_test = new WIT_Staff("", "", "", "","");
				in >> *p_test;
				people.push_back(p_test);
			}
		}
	}

	return people;
	in.close();

}

vector <Person*> CFinalBENDlg::CopyVector()
{
	vector <Person*> current_vector;
	current_vector = CreateVector();
	
	vector <Person*> copied_vector;

	for (int i = 0; i < current_vector.size(); i++)
	{
		copied_vector.push_back(current_vector[i]);
	}

	return copied_vector;
}

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinalBENDlg dialog



CFinalBENDlg::CFinalBENDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINAL_BEN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalBENDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFinalBENDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(View_Entries_Button, &CFinalBENDlg::OnBnClickedEntriesButton)
	ON_BN_CLICKED(Add_Entry_Button, &CFinalBENDlg::OnBnClickedEntryButton)
END_MESSAGE_MAP()


// CFinalBENDlg message handlers

BOOL CFinalBENDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CreateVector();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFinalBENDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFinalBENDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalBENDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFinalBENDlg::OnBnClickedEntriesButton()
{
	CreateVector();
	start_vector = CreateVector();
	View_Entry_Dialog_Class *ve = new View_Entry_Dialog_Class();
	ve->display_vector = CopyVector();
	iter = start_vector.begin();
	name = (**iter).getName();
	role = (**iter).get_Role();
	wnum = (**iter).getW_num();
	address = (**iter).getAddress();
	wage = (**iter).wageOut();
	hours = (**iter).hoursOut();
	gross = (**iter).payMe();

	CString nameout(name.c_str(), name.length());
	CString addressout(address.c_str(), address.length());
	CString wnumout(wnum.c_str(), wnum.length());
	CString roleout(role.c_str(), role.length());
	CString wageout(wage.c_str(), wage.length());
	CString hoursout(hours.c_str(), hours.length());
	CString grossout(gross.c_str(), gross.length());

	iname_variable = nameout;
	iaddress_variable = addressout;
	irole_variable = roleout;
	iwnum_variable = wnumout;
	iwage = wageout;
	ihours = hoursout;
	igross = grossout;

	ve->name_variable = iname_variable;
	ve->address_variable = iaddress_variable;
	ve->wnum_variable = iwnum_variable;
	ve->role_variable = irole_variable;
	ve->wage_out = iwage;
	ve->hours_out = ihours;
	ve->gross_pay_out = igross;

	ve->DoModal();
}


void CFinalBENDlg::OnBnClickedEntryButton()
{
	CreateVector();
	Add_Entry_Class *ae = new Add_Entry_Class();
	ae->entry_vector = CopyVector();
	ae->DoModal();
}


