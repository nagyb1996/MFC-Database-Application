#pragma once


// PayMe_Class dialog

class PayMe_Class : public CDialogEx
{
	DECLARE_DYNAMIC(PayMe_Class)

public:
	PayMe_Class(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PayMe_Class();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = PayMe_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString pay_name_variable;
	CString pay_rate_variable;
	CString pay_hours_variable;
	CString pay_gross_variable;
	CString pay_name_in;
	CString pay_rate_in;
	CString pay_hours_in;
	CString pay_gross_in;
	afx_msg void OnBnClickedButton2();
};
