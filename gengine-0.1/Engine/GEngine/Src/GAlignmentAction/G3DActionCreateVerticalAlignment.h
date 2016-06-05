#pragma once

#define ACTION_CREATE_VERTICAL_ALIGNMENT GNOTRANS("CREATE_VERTICAL_ALIGNMENT")

/**
	@brief
		- 종단 선형 객체를 생성하는 액션
*/
class G_EXT_CLASS CG3DActionCreateVerticalAlignment :
	public CG3DActionBase
{
protected:
	enum Step
	{
		eStepSelectRefHorizontalAlignment,	// 참조 평면선형 선택
		eStepSpecifyBasePoint,	// 종단선형 기준점
	};
	Step m_eStep;

	CGObjectVerticalAlignment *GetPreviewObjectVerticalAlignment();
	void AddObjectVerticalAlignmentByPreviewObject();
	void CreatePreviewObject();
	void GoStep(const Step &eStep);
	

public:
	/**
		@brief
			- action이 시작되면서 action manager에 으해서 가장 먼저 호출되는 가상함수이다.
	*/
	virtual void StartAction();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	
public:
	GDEFINE_REGISTE_ACTION(CG3DActionCreateVerticalAlignment, ACTION_CREATE_VERTICAL_ALIGNMENT);
	CG3DActionCreateVerticalAlignment(void);
	~CG3DActionCreateVerticalAlignment(void);
};

