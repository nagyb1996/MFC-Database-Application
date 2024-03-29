
#include "stdafx.h"
#include "Final_BENDlg.h"
#include "Final_BEN.h"
#include "View_Entry_Dialog_Class.h"
#include "afxdialogex.h"
#include "start_dialog.h"
#include "PayMe_Class.h"
#include "Person.h"
#include "WIT_Student.h"
#include "WIT_Staff.h"
#include "WIT_Faculty.h"

#include <stdlib.h>
#include <vector>
#include <iterator>
#include <string>

using namespace std;


// View_Entry_Dialog_Class dialog

IMPLEMENT_DYNAMIC(View_Entry_Dialog_Class, CDialogEx)

View_Entry_Dialog_Class::View_Entry_Dialog_Class(CWnd* pParent /*=nullptr*/)
	: CDialogEx(View_Entry_Dialog, pParent)
	, name_variable()
	, address_variable()
	, wnum_variable()
	, role_variable()
{

}

View_Entry_Dialog_Class::~View_Entry_Dialog_Class()
{
}

void View_Entry_Dialog_Class::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, Name_TextBox, name_variable);
	DDX_Text(pDX, Address_TextBox, address_variable);
	DDX_Text(pDX, Wnum_TextBox, wnum_variable);
	DDX_Text(pDX, Role_TextBox, role_variable);
}



BEGIN_MESSAGE_MAP(View_Entry_Dialog_Class, CDialogEx)
ON_BN_CLICKED(PayMe_Button, &View_Entry_Dialog_Class::OnBnClickedButton)
ON_BN_CLICKED(Next_Entry_Button, &View_Entry_Dialog_Class::OnBnClickedEntryButton)
ON_BN_CLICKED(Done_View_Entry_Button, &View_Entry_Dialog_Class::OnBnClickedViewEntryButton)
END_MESSAGE_MAP()




void View_Entry_Dialog_Class::OnBnClickedEntryButton()
{
	string name;
	string address;
	string wnum;
	string role;
	string gross_pay;
	string wage;
	string hours;
	static bool firstRun = true;
	static int num = 0;
	static int count = 0;
	if(firstRun)
	
	iter = display_vector.begin();

	if (firstRun)
	{
		iter = display_vector.begin()+1;
		num = display_vector.size();
		count = 1;
		firstRun = false;
	}
	else
	{
		if (count < num-1)
		{
			iter++;
			count++;
		}
		else if (count >= num-1)
		{
			//iter = display_vector.begin();
			firstRun = true;
			EndDialog(IDCANCEL);

			//return;
		}
	}
	
		name = (**iter).getName();
		address = (**iter).getAddress();
		wnum = (**iter).getW_num();
		role = (**iter).get_Role();

		gross_pay = (**iter).payMe();
		wage = (**iter).wageOut();
		hours = (**iter).hoursOut();
		
		
		CString nameout(name.c_str(), name.length());
		CString addressout(address.c_str(), address.length());
		CString wnumout(wnum.c_str(), wnum.length());
		CString roleout(role.c_str(), role.length());

		CString gross_pay_out1(gross_pay.c_str(), gross_pay.length());
		CString wage_out1(wage.c_str(), wage.length());
		CString hours_out1(hours.c_str(), hours.length());
		CString name_pay1(name.c_str(), name.length());

		name_pay = name_pay1;
		hours_out = hours_out1;
		wage_out = wage_out1;
		gross_pay_out = gross_pay_out1;

		name_variable = nameout;
		address_variable = addressout;
		wnum_variable = wnumout;
		role_variable = roleout;

		UpdateData(0);
}



void View_Entry_Dialog_Class::OnBnClickedViewEntryButton()
{
		EndDialog(IDCANCEL);
		//CFinalBENDlg *go = new CFinalBENDlg;
		//go->DoModal();
}

void View_Entry_Dialog_Class::OnBnClickedButton()
{
	//EndDialog(IDCANCEL);
	PayMe_Class *pm = new PayMe_Class();
	pm->pay_name_variable = name_variable;
	pm->pay_hours_variable = hours_out;
	pm->pay_rate_variable = wage_out;
	pm->pay_gross_variable = gross_pay_out;
	pm->DoModal();
}
