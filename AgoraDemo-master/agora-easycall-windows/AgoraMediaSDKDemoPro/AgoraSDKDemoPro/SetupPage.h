#pragma once


// CSetupPage �Ի���

class CSetupPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSetupPage)

public:
	CSetupPage();
	virtual ~CSetupPage();

// �Ի�������
	enum { IDD = IDD_SETUPPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnApply();
	virtual void OnOK();

	DECLARE_MESSAGE_MAP()

private:
	int m_nResolution;

};
