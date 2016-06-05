#pragma once
#include "afxwin.h"


// CDlgCommandBar ��ȭ �����Դϴ�.

class CDlgCommandBar : public CDialogEx, public CGCommandBarBase
{
	DECLARE_DYNAMIC(CDlgCommandBar)

public:
	virtual void AddLog(const CAtlString &strLog);
	virtual void SetCommandText(const CAtlString &strText);
	virtual void ClearLog();
	virtual void ClearCommandText();
	virtual CAtlString GetCommandText();
	void SetFocusAndAddChar(const WCHAR ch);

	CDlgCommandBar(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgCommandBar();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_COMMANDBAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCommand;
	CRichEditCtrl m_reCommandBarLog;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CEdit m_edit;
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};
