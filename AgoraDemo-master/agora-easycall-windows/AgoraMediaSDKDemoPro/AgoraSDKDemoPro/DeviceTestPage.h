#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDeviceTestPage �Ի���

class CDeviceTestPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CDeviceTestPage)

public:
	CDeviceTestPage();
	virtual ~CDeviceTestPage();

// �Ի�������
	enum { IDD = IDD_DEVICETESTPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedBtnrcdctrlDevicetest();
	afx_msg void OnBnClickedBtnploctrlDevicetest();

	DECLARE_MESSAGE_MAP()

private:
	CComboBox m_ctrRocordDeviceSel;
	CSliderCtrl m_ctrRecordVolSet;
	CComboBox m_ctrPlayoutDeviceSel;
	CSliderCtrl m_ctrVolVolSet;

};
