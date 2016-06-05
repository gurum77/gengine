#pragma once

#define ACTION_INPUT_DESIGN_VIP GNOTRANS("INPUT_DESIGN_VIP")

/**
	@brief
		- 종단선형의 계획고를 입력하는 액션
*/
class G_EXT_CLASS CG3DActionInputDesignVIP :
	public CG3DActionBase
{
protected:
	enum Step
	{
		eStepSelectVerticalAlignment,	// 종단선형을 선택한다.
		eStepSpecifyFirstVIPPoint,	// 첫번째 VIP 입력
		eStepSpecifyNextVIPPoint,	// 두번째 이후 VIP의 좌표 입력
		eStepInputVIPParameter	// 두번째 이후 VIP의 parameter 입력
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
			- action이 시작되면서 action manager에 으해서 가장 먼저 호출되는 가상함수이다.
	*/
	virtual void StartAction();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);

	virtual void OnMouseMove(UINT nFlags, CPoint point);
	
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	GDEFINE_REGISTE_ACTION(CG3DActionInputDesignVIP, ACTION_INPUT_DESIGN_VIP);
	CG3DActionInputDesignVIP(void);
	~CG3DActionInputDesignVIP(void);
};

