#pragma once
#include "afxlistctrl.h"


// CNetworkTestPage �Ի���

class CNetworkTestPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CNetworkTestPage)

public:
	CNetworkTestPage();
	virtual ~CNetworkTestPage();

// �Ի�������
	enum { IDD = IDD_NETWORKTESTPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bEnableNETTest;
};
