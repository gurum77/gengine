#pragma once

#define ACTION_INPUT_DESIGN_VIP GNOTRANS("INPUT_DESIGN_VIP")

/**
	@brief
		- ���ܼ����� ��ȹ�� �Է��ϴ� �׼�
*/
class G_EXT_CLASS CG3DActionInputDesignVIP :
	public CG3DActionBase
{
protected:
	enum Step
	{
		eStepSelectVerticalAlignment,	// ���ܼ����� �����Ѵ�.
		eStepSpecifyFirstVIPPoint,	// ù��° VIP �Է�
		eStepSpecifyNextVIPPoint,	// �ι�° ���� VIP�� ��ǥ �Է�
		eStepInputVIPParameter	// �ι�° ���� VIP�� parameter �Է�
	};
	Step m_eStep;

	void CopyDesignVIPFromPreviewObjectToMainObject();
	void CreatePreviewObject();
	CGObjectVerticalAlignment *GetPreviewObjectVerticalAlignment();
	CGObjectVerticalAlignment *GetSelectedObjectVerticalAlignment();
	void GoStep(const Step &eStep);

	void OnLButtonDown_SpecifyFirstVIPPoint(const CGPoint2D &ptPos);
	void OnLButtonDown_SpecifyNextVIPPoint(const CGPoint2D &ptPos);
	void OnKeyDown_InputVIPParameter(const CAtlString &strText);

public:
	/**
		@brief
			- action�� ���۵Ǹ鼭 action manager�� ���ؼ� ���� ���� ȣ��Ǵ� �����Լ��̴�.
	*/
	virtual void StartAction();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);

	virtual void OnMouseMove(UINT nFlags, CPoint point);
	
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	GDEFINE_REGISTE_ACTION(CG3DActionInputDesignVIP, ACTION_INPUT_DESIGN_VIP);
	CG3DActionInputDesignVIP(void);
	~CG3DActionInputDesignVIP(void);
};

