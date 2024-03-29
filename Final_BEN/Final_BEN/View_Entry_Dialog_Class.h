#pragma once

#include <vector>
#include <iterator>
#include <stdlib.h>
#include "Person.h"

using namespace std;


// View_Entry_Dialog_Class dialog

class View_Entry_Dialog_Class : public CDialogEx
{
	DECLARE_DYNAMIC(View_Entry_Dialog_Class)

public:
	View_Entry_Dialog_Class(CWnd* pParent = nullptr);   // standard constructor
	virtual ~View_Entry_Dialog_Class();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = View_Entry_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString name_variable;
	CString address_variable;
	CString wnum_variable;
	CString role_variable;
	CString gross_pay_out;
	CString wage_out;
	CString hours_out;
	CString name_pay;
	vector <Person*> display_vector;
	vector<Person*>::iterator iter;
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedEntryButton();
	afx_msg void OnBnClickedViewEntryButton();
};
