
// WSCADDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CWSCADDlg
class CWSCADDlg : public CDialog
{
// ��������
public:
	CWSCADDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WSCAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//double m_Dverh;
	//double m_Dcentrotv;
	//double m_Dcentr;
	//double m_Dotv;
	//double m_Dosn;
	//double m_GlubinaPaza;
	//double m_ShirinaPaza;
	//double m_Lpaza;
	//double m_OtstupPaza;
	//double m_DVireza;
	//double m_GlubinaVireza;
	//int m_nZ;
	//double m_UgolNaklona;
	//double m_Lobsh;
	//double m_Losn;
	//double m_HZuba = 5.0f;
	//double m_SZuba = 4.0f;
	//double m_AZuba = 10.f;

	afx_msg void OnBnClickedButton1();
	bool CheckData();
	
	int m_NOtv;
	//afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	double m_D;
	double m_L;
	double m_l;
	double m_d1;
	double m_c;
	double m_d;
	double m_b;
	//afx_msg void OnEnChangeEditCSmall();
};
