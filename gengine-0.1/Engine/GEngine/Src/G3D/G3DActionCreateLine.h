#pragma once
#define ACTION_CREATE_LINE	GNOTRANS("CREATE LINE")
/**
	@brief
		- line�� �����ϴ� action
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
			- Ű �Է�
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

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
	virtual void RenderPreview();
	

	GDEFINE_REGISTE_ACTION(CG3DActionCreateLine, ACTION_CREATE_LINE);

	CG3DActionCreateLine();
	~CG3DActionCreateLine();
};

