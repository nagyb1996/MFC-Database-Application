// PayMe_Class.cpp : implementation file
//

#include "stdafx.h"
#include "Final_BEN.h"
#include "PayMe_Class.h"
#include "afxdialogex.h"
#include "View_Entry_Dialog_Class.h"


// PayMe_Class dialog

IMPLEMENT_DYNAMIC(PayMe_Class, CDialogEx)

PayMe_Class::PayMe_Class(CWnd* pParent /*=nullptr*/)
	: CDialogEx(PayMe_Dialog, pParent)
	, pay_name_variable()
	, pay_rate_variable()
	, pay_hours_variable()
	, pay_gross_variable()
{

}

PayMe_Class::~PayMe_Class()
{
}

void PayMe_Class::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, pay_name_variable);
	DDX_Text(pDX, IDC_EDIT2, pay_rate_variable);
	DDX_Text(pDX, IDC_EDIT3, pay_hours_variable);
	DDX_Text(pDX, IDC_EDIT4, pay_gross_variable);
}


BEGIN_MESSAGE_MAP(PayMe_Class, CDialogEx)
	ON_BN_CLICKED(IDOK, &PayMe_Class::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &PayMe_Class::OnBnClickedButton2)
END_MESSAGE_MAP()


// PayMe_Class message handlers


void PayMe_Class::OnBnClickedOk()
{
	EndDialog(IDCANCEL);
}


void PayMe_Class::OnBnClickedButton2()
{
	//pay_name_variable = pay_name_in;
	//pay_rate_variable = pay_rate_in;
	//pay_hours_variable = pay_hours_in;
	//pay_gross_variable = pay_gross_in;

	//UpdateData(0);
}
