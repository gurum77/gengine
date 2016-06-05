#pragma once
#define ACTION_CREATE_CIRCLE GNOTRANS("CREATE CIRCLE")
/**
	@brief
		- �� �׸��� �׼�
*/
class G_EXT_CLASS CG3DActionCreateCircle :
	public CG3DActionBase
{
protected:
	enum Step
	{
		eStepCenter,
		eStepRadius
	};
	Step m_eStep;
public:
	/**
		@brief
			- action�� ���۵Ǹ鼭 action manager�� ���ؼ� ���� ���� ȣ��Ǵ� �����Լ��̴�.
	*/
	virtual void StartAction();

	/**
		@brief
			- action�� ������ ȣ��Ǿ�� �ϴ� �����Լ��̴�.
			- �����ڰ� ���� ȣ���ؾ� �Ѵ�.
	*/
	virtual void EndAction();

	/**
		@brief
		- ���콺 �̺�Ʈ �ڵ鷯�̴�.
	*/
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);

	/**
		@brief
			- action�� �̸����� ��ü�� �ִ� ��� �� �Լ��� ������ �Ͽ� �̸����� ��ü�� �׸����� �����ؾ� �Ѵ�.
	*/
	virtual void CreatePreview();


	GDEFINE_REGISTE_ACTION(CG3DActionCreateCircle, ACTION_CREATE_CIRCLE);
	CG3DActionCreateCircle();
	virtual ~CG3DActionCreateCircle();
};

