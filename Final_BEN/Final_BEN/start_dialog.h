#pragma once


// start_dialog dialog

class start_dialog : public CDialogEx
{
	DECLARE_DYNAMIC(start_dialog)

public:
	start_dialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~start_dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINAL_BEN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
