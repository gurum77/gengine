#pragma once
#define ACTION_CREATE_HORIZONTAL_ALIGNMENT GNOTRANS("CREATE HORIZONTAL ALIGNMENT")
/**
	@brief
		- A action To create a horizontal alignment.
*/
class G_EXT_CLASS CG3DActionCreateHorizontalAlignment :
	public CG3DActionBase
{
protected:
	enum Step
	{
		eStepStartPoint,
		eStepDirectionPoint,
		eStepCurveType,
		eStepRadius,
		eStepLength,
		eStepA1,
		eStepA2,
		eStepRadius2,
		eStepCCWPoint

	};
	
	enum CurveType
	{
		eCurveTypeNone	= 0,
		eCurveTypeLine,
		eCurveTypeArc,
		eCurveTypeClothoidA1,
		eCurveTypeClothoidA2,
		eCurveTypeOvalness
	};
	Step m_eStep;
	CurveType m_eCurveType;

	void AddObjectHorizontalAlignmentByPreviewObject();
	virtual void CreatePreviewObject();

	void GoStep(const Step &eStep);

	
	void OnKeyDown_CurveTypeStep(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyDown_LengthStep(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyDown_RadiusStep(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyDown_Radius2Step(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyDown_A1Step(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnKeyDown_A2Step(UINT nChar, UINT nRepCnt, UINT nFlags);
	
	CGObjectLine2D *GetPreviewObjectLine2D();

	CGObjectHorizontalAlignment *GetPreviewObjectHorizontalAlignment();
	CGHorizontalAlignmentElement *GetPreviewLastHorizontalAlignmentElement();


public:
	/**
		@brief
			- action�� ���۵Ǹ鼭 action manager�� ���ؼ� ���� ���� ȣ��Ǵ� �����Լ��̴�.
	*/
	virtual void StartAction();

	/**
		@brief
			- action�� �̸����� ��ü�� �ִ� ��� �� �Լ��� ������ �Ͽ� �̸����� ��ü�� �׸����� �����ؾ� �Ѵ�.
	*/
	virtual void RenderPreview();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

public:
	GDEFINE_REGISTE_ACTION(CG3DActionCreateHorizontalAlignment, ACTION_CREATE_HORIZONTAL_ALIGNMENT);
	CG3DActionCreateHorizontalAlignment(void);
	virtual ~CG3DActionCreateHorizontalAlignment(void);
};

