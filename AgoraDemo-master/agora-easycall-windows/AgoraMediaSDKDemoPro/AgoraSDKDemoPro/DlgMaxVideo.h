#pragma once


// CDlgMaxVideo �Ի���

class CDlgMaxVideo : public CDialog
{
	DECLARE_DYNAMIC(CDlgMaxVideo)

public:
	CDlgMaxVideo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMaxVideo();

	void SetUID(UINT nUID);
	UINT GetUID() {return m_nUID;};

// �Ի�������
	enum { IDD = IDD_DLGMAXVIDEO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	virtual void OnCancel();

	DECLARE_MESSAGE_MAP()

private:
	UINT	m_nUID;

};
