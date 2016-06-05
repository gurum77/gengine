#pragma once

class CGCommandBarBase;

/**
	@brief
		- Action�� ����ϱ� ���� ������.
		- �����
			- �ɹ� ������ ����
			- G3DView ���� 
				- Set3DView
			- �޼��� ����
				- PreTranslateMessage
			- �׼� ����
				- RunAction
			- �̸����� DB ����
				- �̸����� ��ü�� ȭ�鿡 ǥ���ϱ� ���ؼ��� �̸����� DB�� �־�� �Ѵ�.

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

