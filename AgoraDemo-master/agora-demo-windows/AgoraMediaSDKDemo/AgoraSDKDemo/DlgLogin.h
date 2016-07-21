#pragma once
#include "DemoData.h"

// CDlgLogin �Ի���

class CDlgLogin : public CDialog
{
	DECLARE_DYNAMIC(CDlgLogin)

public:
	CDlgLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgLogin();

	CString GetVendorKey() {return m_strVendorKey;};
	CString GetChannelName() {return m_strChannelName;};
	UINT GetUID() {return m_nUID;};
	int	GetEngineMode() {return m_nEngineMode;};
// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedOk();

	DECLARE_MESSAGE_MAP()

private:

	CString			m_strVendorKey;
	CString			m_strChannelName;
	UINT			m_nUID;
	int				m_nEngineMode;
};
