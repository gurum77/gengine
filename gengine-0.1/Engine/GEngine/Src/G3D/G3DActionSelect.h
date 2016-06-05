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
		- action�� ���۵Ǹ鼭 action manager�� ���ؼ� ���� ���� ȣ��Ǵ� �����Լ��̴�.
	*/
	virtual void StartAction();
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	/**
		@brief
			- action�� �̸����� ��ü�� �ִ� ��� �� �Լ��� ������ �Ͽ� �̸����� ��ü�� �׸����� �����ؾ� �Ѵ�.
	*/
	virtual void CreatePreview();

	virtual void FlushPreview();

	/**
		@brief
			- action�� ������ ȣ��Ǿ�� �ϴ� �����Լ��̴�.
			- �����ڰ� ���� ȣ���ؾ� �Ѵ�.
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

