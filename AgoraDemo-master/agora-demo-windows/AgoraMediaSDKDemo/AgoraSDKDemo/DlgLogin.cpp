// DlgLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemo.h"
#include "DlgLogin.h"


// CDlgLogin �Ի���

IMPLEMENT_DYNAMIC(CDlgLogin, CDialog)

CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
	, m_nUID(0)
	, m_strVendorKey(_T("6D7A26A1D3554A54A9F43BE6797FE3E2"))
	, m_strChannelName(_T(""))
	, m_nEngineMode(1)
{

}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDUID_LOGIN, m_nUID);
	DDX_Text(pDX, IDC_EDVDKEY_LOGIN, m_strVendorKey);
	DDX_Text(pDX, IDC_EDCHNAME_LOGIN, m_strChannelName);
	DDX_Radio(pDX, IDC_RDAUDIO_LOGIN, m_nEngineMode);
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgLogin ��Ϣ�������

BOOL CDlgLogin::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgLogin::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	
	if(m_strVendorKey.IsEmpty()) {
		MessageBox(_T("VendorKey����Ϊ��"), _T("����"), MB_OK|MB_ICONERROR);
		return;
	}

	if(m_strChannelName.IsEmpty()) {
		MessageBox(_T("ChannelName����Ϊ��"), _T("����"), MB_OK|MB_ICONERROR);
		return;
	}

	OnOK();
}
