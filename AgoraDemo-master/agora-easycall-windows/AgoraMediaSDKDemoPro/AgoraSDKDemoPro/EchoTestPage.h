#pragma once


// CEchoTestPage �Ի���

class CEchoTestPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CEchoTestPage)

public:
	CEchoTestPage();
	virtual ~CEchoTestPage();

// �Ի�������
	enum { IDD = IDD_ECHOTESTPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	afx_msg void OnBnClickedBtnctrEchotest();

	DECLARE_MESSAGE_MAP()

};
