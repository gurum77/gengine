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

	CGPoint3D m_ptMove[2];	// ����, ����
	CGVector3D m_vMoved;	// ������� �̵���

	void MoveSelectedObject();
	virtual void MoveTempObject();
	virtual void Run();
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
	virtual void OnRButtonUp(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);

	/**
		@brief
			- action�� �̸����� ��ü�� �ִ� ��� �� �Լ��� ������ �Ͽ� �̸����� ��ü�� �׸����� �����ؾ� �Ѵ�.
	*/
	virtual void CreatePreview();


	GDEFINE_REGISTE_ACTION(CG3DActionMove, ACTION_MOVE);
	CG3DActionMove(void);
	virtual ~CG3DActionMove(void);
};

