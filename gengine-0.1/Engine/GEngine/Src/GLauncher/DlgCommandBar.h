#pragma once
#include "afxwin.h"


// CDlgCommandBar 대화 상자입니다.

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

	CDlgCommandBar(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgCommandBar();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_COMMANDBAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCommand;
	CRichEditCtrl m_reCommandBarLog;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CEdit m_edit;
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};
