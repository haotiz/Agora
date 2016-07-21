// DlgJoinChannel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "DlgJoinChannel.h"


// CDlgJoinChannel �Ի���

IMPLEMENT_DYNAMIC(CDlgJoinChannel, CDialog)

CDlgJoinChannel::CDlgJoinChannel(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgJoinChannel::IDD, pParent)
	, m_strVendorKey(_T("6D7A26A1D3554A54A9F43BE6797FE3E2"))
	, m_nUID(0)
	, m_strChannelName(_T(""))
	, m_nWorkMode(0)
	, m_nDecodeMode(0)
	, m_bRecvMode(FALSE)
	, m_nMaxResolution(0)
{

}

CDlgJoinChannel::~CDlgJoinChannel()
{
}

void CDlgJoinChannel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDVKEY_JOIN, m_strVendorKey);
	DDX_Text(pDX, IDC_EDCHANNEL_JOIN, m_strChannelName);
	DDX_Text(pDX, IDC_EDID_JOIN, m_nUID);
	DDX_CBIndex(pDX, IDC_CMBWORKMODE_JOIN, m_nWorkMode);
	DDX_CBIndex(pDX, IDC_CMBDECDMODE_JOIN, m_nDecodeMode);
	DDX_Check(pDX, IDC_CKRECVMODE_JOIN, m_bRecvMode);
	DDX_CBIndex(pDX, IDC_CMBMAXRESOLUTION_JOIN, m_nMaxResolution);
}


BEGIN_MESSAGE_MAP(CDlgJoinChannel, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgJoinChannel::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgJoinChannel ��Ϣ�������

BOOL CDlgJoinChannel::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgJoinChannel::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	OnOK();
}