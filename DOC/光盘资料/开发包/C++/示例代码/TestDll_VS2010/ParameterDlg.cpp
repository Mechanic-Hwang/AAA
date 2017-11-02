// ParameterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestDll_VS2010.h"
#include "ParameterDlg.h"
#include "afxdialogex.h"


// CParameterDlg �Ի���

IMPLEMENT_DYNAMIC(CParameterDlg, CDialogEx)

CParameterDlg::CParameterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CParameterDlg::IDD, pParent)
{
	CheckedNum = 0;
	CheckBoxID = -1;
	EnableAutomation();

}

CParameterDlg::~CParameterDlg()
{
}

void CParameterDlg::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CParameterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CParameterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CParameterDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CParameterDlg, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IParameterDlg ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {40E2AB2E-F975-488A-95FD-86C30DDC25F5}
static const IID IID_IParameterDlg =
{ 0x40E2AB2E, 0xF975, 0x488A, { 0x95, 0xFD, 0x86, 0xC3, 0xD, 0xDC, 0x25, 0xF5 } };

BEGIN_INTERFACE_MAP(CParameterDlg, CDialogEx)
	INTERFACE_PART(CParameterDlg, IID_IParameterDlg, Dispatch)
END_INTERFACE_MAP()


BOOL CParameterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//if (CheckBoxID >= IDC_PowerOn && CheckBoxID <= IDC_TestModeConfig_800)//mark by shuangIDC_POWEROFF_500
	//if (CheckBoxID >= IDC_PowerOn && CheckBoxID <= IDC_ServerClientConfig_500)
	//if (CheckBoxID >= IDC_PowerOn && CheckBoxID <= IDC_POWEROFF_500)
	if (CheckBoxID >= IDC_PowerOn && CheckBoxID <= IDC_READ_6B_TID)
	{
		((CButton*)GetDlgItem(CheckBoxID))->SetCheck(1);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


// CParameterDlg ��Ϣ�������


BOOL CParameterDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::OnCommand(wParam, lParam);
}


void CParameterDlg::OnBnClickedOk()
{
	CheckedNum = 0;
	//for (int i = IDC_PowerOn; i <= IDC_TestModeConfig_800; i++)//mark by shuangIDC_POWEROFF_500
	//for (int i = IDC_PowerOn; i <= IDC_ServerClientConfig_500; i++)
	//for (int i = IDC_PowerOn; i <= IDC_POWEROFF_500; i++)
	for (int i = IDC_PowerOn; i <= IDC_READ_6B_TID; i++)	
	{
		UINT nState =  IsDlgButtonChecked(i);
		if (1 == nState)
		{
			CheckedNum++;
			CheckBoxID = i;
		}
	}
	if (CheckedNum > 1)
	{
		MessageBox("ֻ��ѡ��һ��������","����",MB_OK);
		return;
	}

	GetDlgItemText(CheckBoxID,strTestItemName);

	CDialogEx::OnOK();
}
