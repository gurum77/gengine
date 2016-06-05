#pragma once
#define ACTION_MOVE	GNOTRANS("MOVE")
/**
	@brief
		- move action
*/
class G_EXT_CLASS CG3DActionMove :
	public CG3DActionSelect
{
protected:
	enum Step
	{
		eStepMoveSelectObject = CG3DActionSelect::eStepSecondPoint,
		eStepMoveFirstPoint,
		eStepMoveSecondPoint
	};

	CGPoint3D m_ptMove[2];	// 시점, 종점
	CGVector3D m_vMoved;	// 현재까지 이동량

	void MoveSelectedObject();
	virtual void MoveTempObject();
	virtual void Run();
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
			- 마우스 이벤트 핸들러이다.
	*/
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);

	/**
		@brief
			- action에 미리보기 객체가 있는 경우 이 함수를 재정의 하여 미리보기 객체를 그리도록 구현해야 한다.
	*/
	virtual void CreatePreview();


	GDEFINE_REGISTE_ACTION(CG3DActionMove, ACTION_MOVE);
	CG3DActionMove(void);
	virtual ~CG3DActionMove(void);
};

