#pragma once
#include "afxwin.h"


// CDlgSpaceView ��ȭ �����Դϴ�.

class CDlgSpaceView : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSpaceView)
private:
	void DrawObjects(const bool &bRealTime);
	void UpdateControl();

	void InitG3DView();
	void InitActionManager();
	void InitControl();
	CG3DSpaceView m_g3DView;
	CG3DActionManager m_actionManager;
	CG3DDB m_g3DDB;
	CG3DDB m_g3DDBPreview;
	CGDCDirectX11 m_gDC;

public:
	CDlgSpaceView(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgSpaceView();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SPACE_VIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButtonGlauncherDraw();
	UINT m_iObjectNum;
	afx_msg void OnBnClickedButtonGlauncherDeleteall();
	afx_msg void OnBnClickedButtonGlauncherDrawRealtime();
	long m_nAllObjectNum;
	long m_nAllSpaceNum;
private:
	// ������ ��ü ����
	CComboBox m_cmbObjectType;
public:
	long m_nVisibleSpaceNum;
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonGlauncherSelect();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonGlauncherUnselect();
	afx_msg void OnBnClickedCheckViewSpace();
	CButton m_chkViewSpace;

	
	afx_msg void OnBnClickedCheckCreateAroundSpace();
	CButton m_chkCreateAroundSpace;
	afx_msg void OnBnClickedCheckCanHaveOneObject();
	CButton m_chkCanHaveOneObject;
	float m_fDefaultSpaceSize;
	UINT m_uSizeForObjectToSpace;
	afx_msg void OnEnKillfocusEditSpaceSize();
	afx_msg void OnEnKillfocusEditSpaceObjectToSpaceSize();
};
