// Add_Entry_Class.cpp : implementation file
//

#include "stdafx.h"
#include "Final_BENDlg.h"
#include "Final_BEN.h"
#include "Add_Entry_Class.h"
#include "afxdialogex.h"
#include "PayMe_Class.h"
#include "Person.h"
#include "WIT_Student.h"
#include "WIT_Staff.h"
#include "WIT_Faculty.h"
#include <string>

// Add_Entry_Class dialog

IMPLEMENT_DYNAMIC(Add_Entry_Class, CDialogEx)

Add_Entry_Class::Add_Entry_Class(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Add_Entry_Dialog, pParent)
	, Name_EntryBox_Variable(_T(""))
	, Address_Entry_Variable(_T(""))
	, selected_role_variable(0)
	, WNum_Entry_Variable(_T(""))
	, PayRate_Entry_Variable(_T(""))
	, Hours_variable(_T(""))
{

}

Add_Entry_Class::~Add_Entry_Class()
{
}

void Add_Entry_Class::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, Name_EntryBox, Name_EntryBox_Variable);
	DDX_Text(pDX, Address_EntryBox, Address_Entry_Variable);
	DDX_Radio(pDX, Student_Radio, selected_role_variable);
	DDX_Text(pDX, Wnum_EntryBox, WNum_Entry_Variable);
	DDX_Text(pDX, PayRate_EntryBox, PayRate_Entry_Variable);
	DDX_Text(pDX, Hours_EntryBox, Hours_variable);
}


BEGIN_MESSAGE_MAP(Add_Entry_Class, CDialogEx)
	ON_BN_CLICKED(Submit_Entry_Button, &Add_Entry_Class::OnBnClickedEntryButton)
	ON_BN_CLICKED(Cancel_Add_Entry_Button, &Add_Entry_Class::OnBnClickedAddEntryButton)
END_MESSAGE_MAP()


// Add_Entry_Class message handlers


void Add_Entry_Class::OnBnClickedEntryButton()
{
	{
		UpdateData();

		if (selected_role_variable == 0)
		{
			CString entered_name = Name_EntryBox_Variable;
			CString entered_address = Address_Entry_Variable;
			CString entered_wnum = WNum_Entry_Variable;
			CString entered_wage = PayRate_Entry_Variable;
			CString entered_hours = Hours_variable;

			CT2A con_name (entered_name);
			CT2A con_address (entered_address);
			CT2A con_wnum (entered_wnum);
			CT2A con_wage (entered_wage);
			CT2A con_hours (entered_hours);

			string name (con_name);
			string address (con_address);
			string wnum (con_wnum);
			string wage (con_wage);
			string hours(con_hours);

			Person *test_Student = new WIT_Student(name, address, wnum, wage, hours);

			entry_vector.push_back(test_Student);

		}


		if (selected_role_variable == 1)
		{
			CString entered_name = Name_EntryBox_Variable;
			CString entered_address = Address_Entry_Variable;
			CString entered_wnum = WNum_Entry_Variable;
			CString entered_wage = PayRate_Entry_Variable;
			CString entered_hours = Hours_variable;

			CT2A con_name(entered_name);
			CT2A con_address(entered_address);
			CT2A con_wnum(entered_wnum);
			CT2A con_wage(entered_wage);
			CT2A con_hours(entered_hours);

			string name(con_name);
			string address(con_address);
			string wnum(con_wnum);
			string wage(con_wage);
			string hours(con_hours);

			Person *test_Staff = new WIT_Staff(name, address, wnum, wage, hours);

			entry_vector.push_back(test_Staff);
		}

		else if (selected_role_variable == 2)
		{
			CString entered_name = Name_EntryBox_Variable;
			CString entered_address = Address_Entry_Variable;
			CString entered_wnum = WNum_Entry_Variable;
			CString entered_wage = PayRate_Entry_Variable;
			CString entered_hours = Hours_variable;

			CT2A con_name(entered_name);
			CT2A con_address(entered_address);
			CT2A con_wnum(entered_wnum);
			CT2A con_wage(entered_wage);
			CT2A con_hours(entered_hours);

			string name(con_name);
			string address(con_address);
			string wnum(con_wnum);
			string wage(con_wage);
			string hours(con_hours);

			Person *test_Faculty = new WIT_Faculty(name, address, wnum, wage, hours);

			entry_vector.push_back(test_Faculty);
		}
	}

		ofstream out("array.txt");
		for (vector<Person*>::iterator iter = entry_vector.begin(); iter != entry_vector.end(); ++iter) {
			out << **iter;
		}

		CString clear = (_T(""));
		
		Name_EntryBox_Variable = clear;
		Address_Entry_Variable = clear;
		WNum_Entry_Variable = clear;
		PayRate_Entry_Variable = clear;
		Hours_variable = clear;
		selected_role_variable = 0;

		UpdateData(0);

		EndDialog(IDCANCEL);

}



void Add_Entry_Class::OnBnClickedAddEntryButton()
{
	EndDialog(IDCANCEL);
	//CFinalBENDlg *start = new CFinalBENDlg;
	//start->DoModal();
}
