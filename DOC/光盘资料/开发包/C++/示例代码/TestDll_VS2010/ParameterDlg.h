#pragma once


// CParameterDlg �Ի���

class CParameterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CParameterDlg)

public:
	CParameterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CParameterDlg();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DlgParameter };
public:
	int  CheckedNum;
	int  CheckBoxID;
	CString strTestItemName;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
