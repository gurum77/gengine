#pragma once

/**
	@brief
		- Command Bar를 구성하기 위한 기본 클래스
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
	CString m_strLastCommandText;	// 마지막으로 command에 뿌려진 text(사용자가 입력하기 전 내용)

public:
	CGCommandBarBase(void);
	virtual ~CGCommandBarBase(void);
};

