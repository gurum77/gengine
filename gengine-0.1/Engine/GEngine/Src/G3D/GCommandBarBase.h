#pragma once

/**
	@brief
		- Command Bar�� �����ϱ� ���� �⺻ Ŭ����
*/
class G_EXT_CLASS CGCommandBarBase
{
public:
	void MoveCommandTextToLog();
	void MoveCommandTextToLogAndSetCommandText(const CAtlString &strText);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void SetCurrentAction(CG3DActionBase *pAction);
	CAtlString GetUserInputCommandText();
	void SetLastCommandText(const CAtlString &strText);
	const CAtlString &GetLastCommandText() const;

	virtual void AddLog(const CAtlString &strLog) = 0;
	virtual void SetCommandText(const CAtlString &strText);
	virtual void ClearLog() = 0;
	virtual void ClearCommandText();
	virtual CAtlString GetCommandText() = 0;

protected:
	CG3DActionBase *m_pCurrentAction;
	CString m_strLastCommandText;	// ���������� command�� �ѷ��� text(����ڰ� �Է��ϱ� �� ����)

public:
	CGCommandBarBase(void);
	virtual ~CGCommandBarBase(void);
};

