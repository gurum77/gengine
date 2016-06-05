#pragma once
#define ACTION_CREATE_LINE	GNOTRANS("CREATE LINE")
/**
	@brief
		- line을 생성하는 action
*/
class G_EXT_CLASS CG3DActionCreateLine :
	public CG3DActionBase
{
protected:
	enum Step
	{
		eStepFirstPoint,
		eStepSecondPoint
	};
	Step m_eStep;


	virtual void CreatePreviewObject();
	void OnLButtonDown_StepFirstPoint(const CGPoint3D &ptPos);
	void OnLButtonDown_StepSecondPoint(const CGPoint3D &ptPos);
	CGObjectLine2D *GetPreviewObjectLine2D();
public:
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
			- 키 입력
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	/**
		@brief
			- 마우스 이벤트 핸들러이다.
	*/
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);


	/**
		@brief
			- action에 미리보기 객체가 있는 경우 이 함수를 재정의 하여 미리보기 객체를 그리도록 구현해야 한다.
	*/
	virtual void RenderPreview();
	

	GDEFINE_REGISTE_ACTION(CG3DActionCreateLine, ACTION_CREATE_LINE);

	CG3DActionCreateLine();
	~CG3DActionCreateLine();
};

