#pragma once

#define ACTION_SELECT	GNOTRANS("SELECT")
/**
	@brief
		- select action
*/
class G_EXT_CLASS CG3DActionSelect :
	public CG3DActionBase
{
public:
	enum Step
	{
		eStepFirstPoint,
		eStepSecondPoint
	};
	enum Rectangle
	{
		eRectangleLeftBottom,
		eRectangleRightBottom,
		eRectangleRightTop,
		eRectangleLeftTop,
		eRectangleCount
	};
	INT32 m_eStep;

	/**
		@brief
		- action이 시작되면서 action manager에 으해서 가장 먼저 호출되는 가상함수이다.
	*/
	virtual void StartAction();
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	/**
		@brief
			- action에 미리보기 객체가 있는 경우 이 함수를 재정의 하여 미리보기 객체를 그리도록 구현해야 한다.
	*/
	virtual void CreatePreview();

	virtual void FlushPreview();

	/**
		@brief
			- action이 끝날때 호출되어야 하는 가상함수이다.
			- 개발자가 직접 호출해야 한다.
	*/
	virtual void EndAction();
protected:
	CPoint GetRectanglePointFromWindowPoint(const Rectangle &eRectangle, const bool &bOrgLeftBottom) const;
	CPoint m_ptWindow[2];

public:
	GDEFINE_REGISTE_ACTION(CG3DActionSelect, ACTION_SELECT);
	
	CG3DActionSelect();
	~CG3DActionSelect();
};

