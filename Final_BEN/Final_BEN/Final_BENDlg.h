
// Final_BENDlg.h : header file
//

#pragma once
#include <stdlib.h>
#include <vector>
#include <string>

#include "Person.h"
#include "WIT_Student.h"
#include "WIT_Staff.h"
#include "WIT_Faculty.h"



// CFinalBENDlg dialog
class CFinalBENDlg : public CDialogEx
{
// Construction
public:
	CFinalBENDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINAL_BEN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedEntriesButton();
	afx_msg void OnBnClickedEntryButton();
	vector <Person*> CreateVector();
	vector <Person*> CopyVector();
	vector <Person*> start_vector;
	vector<Person*>::iterator iter;
	CString iname_variable;
	CString iaddress_variable;
	CString iwnum_variable;
	CString irole_variable;
	CString iwage;
	CString ihours;
	CString igross;
	string name;
	string address;
	string role;
	string wnum;
	string wage;
	string hours;
	string gross;
};
