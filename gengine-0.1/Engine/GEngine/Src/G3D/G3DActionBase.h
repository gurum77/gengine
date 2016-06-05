#pragma once

class CG3DActionManager;

/**
	@brief
		- action base 클래스
		- user defined action을 만들기 위해서는 반드시 상속받아야 한다.
		- action 등록 방법
			- action 개발시 : action header에서 GDEFINE_REGISTE_ACTION 사용해서 등록
			- action 사용시 : 사용할 프로젝트에서 GIMPLEMENT_REGISTE_ACTION 사용해서 등록
*/
class G_EXT_CLASS CG3DActionBase
{
protected:
	CG3DActionManager *m_pActionManager;
	
	CG3DView *GetView();
	CG3DDB *GetPreviewDB();
	CG3DDB *GetTempDB();
	void RenderPreviewDB();
	void RenderTempDB();
	void CopySelectedObjectToTempDB();
	void InitPreviewDB();
	void InitTempDB();




public:
		/**
		@brief
			- 다음 스탭으로 넘어가기 위한 키인지 판단한다.
	*/
	virtual bool IsNextStepKey(UINT nChar) const;

	/**
		@brief
			- 액션을 중지하기 위한 키인지 판단한다.
	*/
	virtual bool IsAbortActionKey(UINT nChar) const;


	/**
		@brief
			- 액션을 정상 종료 하기 위한 키인지 판단한다.
	*/
	virtual bool IsCompleteActionKey(UINT nChar) const;

	void SetActionManager(CG3DActionManager *pActionManager);

	/**
		@brief
			- action이 시작되면서 action manager에 으해서 가장 먼저 호출되는 가상함수이다.
	*/
	virtual void StartAction();

	/**
		@brief
			- action이 끝날때 호출되어야 하는 가상함수이다.
			- 개발자가 직접 호출해야 한다.
	*/
	virtual void EndAction();

	/**
		@brief
			- 마우스 이벤트 핸들러이다.
	*/
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);

	/**
		@brief
			- key 이벤트 핸드러이다.
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	/**
		@brief
			- action에 미리보기 객체가 있는 경우 이 함수를 재정의 하여 미리보기 객체를 view에서 지우도록 구현해야 한다.
	*/
	virtual void FlushPreview();

	/**
		@brief
			- action에 미리보기 객체가 있는 경우 이 함수를 재정의 하여 미리보기 객체를 그리도록 구현해야 한다.
	*/
	virtual void RenderPreview();

	/**
		@brief
			- action의 종류를 구분할 수 있는 string
	*/
	virtual CAtlString GetStrType() = 0;

	CG3DActionBase();
	~CG3DActionBase();
};

