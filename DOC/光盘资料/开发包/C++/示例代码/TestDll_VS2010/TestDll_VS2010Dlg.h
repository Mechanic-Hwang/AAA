
// TestDll_VS2010Dlg.h : ͷ�ļ�
//

#pragma once
#include "ParameterDlg.h"


// CTestDll_VS2010Dlg �Ի���
class CTestDll_VS2010Dlg : public CDialogEx
{
// ����
public:
	CTestDll_VS2010Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CString StrsysQuery_500(unsigned char ikind);

		void listData();
// �Ի�������
	enum { IDD = IDD_TESTDLL_VS2010_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CParameterDlg ParameterDlg;
	void TestItem(int ItemID);
	void  setEpc();

	// ���ɵ���Ϣӳ�亯��B
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBtnStartTest();
	afx_msg void OnClickedBtnConnOrDisconn();
	afx_msg void OnClickedBtnSeltestitem();
	afx_msg void OnClose();
	afx_msg void OnClickedBtnMutiReaderConnOrDisc();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnChangjing();
};
