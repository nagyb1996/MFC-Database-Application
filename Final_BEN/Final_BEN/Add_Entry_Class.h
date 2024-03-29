#pragma once

#include <vector>
#include <iterator>
#include <stdlib.h>
#include "Person.h"

using namespace std;


// Add_Entry_Class dialog

class Add_Entry_Class : public CDialogEx
{
	DECLARE_DYNAMIC(Add_Entry_Class)

public:
	Add_Entry_Class(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Add_Entry_Class();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Add_Entry_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedEntryButton();
	CString Name_EntryBox_Variable;
	CString Address_Entry_Variable;
	int selected_role_variable;
	vector <Person*> entry_vector;
	CString WNum_Entry_Variable;
	afx_msg void OnEnChangeEntrybox();
	CString PayRate_Entry_Variable;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedEntryButton();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedAddEntryButton();
	CString Hours_variable;
};
