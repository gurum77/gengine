#pragma once

class CGCommandBarBase;

/**
	@brief
		- Action을 사용하기 위한 관리자.
		- 사용방법
			- 맴버 변수로 선어
			- G3DView 설정 
				- Set3DView
			- 메세지 전달
				- PreTranslateMessage
			- 액션 실행
				- RunAction
			- 미리보기 DB 생성
				- 미리보기 객체를 화면에 표시하기 위해서는 미리보기 DB가 있어야 한다.

*/
class G_EXT_CLASS CG3DActionManager
{
public:
	bool RunAction(const CAtlString &strAction);

	CG3DActionBase *FindAction(const CAtlString &strAction);
	CG3DActionBase *GetRunningAction();

	void Set3DView(CG3DView *p3DView);
	CG3DView *GetView();

	void PreTranslateMessage(MSG* pMsg);

	CGSelectionManager &GetSelectionManager();
	void EndRunningAction();

	// CommandBar
	void SetCommandBar(CGCommandBarBase *pCommandBar);
	void MoveCommandTextToLog();
	void MoveCommandTextToLogAndSetCommandText(const CAtlString &strText);
	void AddLog(const CAtlString &strLog);
	void SetCommandText(const CAtlString &strText);
	void ClearLog();
	void ClearCommandText();
	CAtlString GetCommandText();
	CAtlString GetUserInputCommandText();
	bool ParseTextToPoint(const CAtlString &strText, GOUT CGPoint3D &ptPos) const;

		
private:
	CG3DActionBase *CreateAction(const CAtlString &strAction);
	
	void InitAction();

	CG3DView *m_p3DView;
	CG3DActionBase *m_pRunningAction;
	CAtlMap<CAtlString, CG3DActionBase*> m_mapAction;
	CGSelectionManager m_selectionManager;
	CGCommandBarBase *m_pCommandBar;

public:
	CG3DActionManager();
	~CG3DActionManager();
};

