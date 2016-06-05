#pragma once

#define ACTION_CREATE_VERTICAL_ALIGNMENT GNOTRANS("CREATE_VERTICAL_ALIGNMENT")

/**
	@brief
		- ���� ���� ��ü�� �����ϴ� �׼�
*/
class G_EXT_CLASS CG3DActionCreateVerticalAlignment :
	public CG3DActionBase
{
protected:
	enum Step
	{
		eStepSelectRefHorizontalAlignment,	// ���� ��鼱�� ����
		eStepSpecifyBasePoint,	// ���ܼ��� ������
	};
	Step m_eStep;

	CGObjectVerticalAlignment *GetPreviewObjectVerticalAlignment();
	void AddObjectVerticalAlignmentByPreviewObject();
	void CreatePreviewObject();
	void GoStep(const Step &eStep);
	

public:
	/**
		@brief
			- action�� ���۵Ǹ鼭 action manager�� ���ؼ� ���� ���� ȣ��Ǵ� �����Լ��̴�.
	*/
	virtual void StartAction();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	
public:
	GDEFINE_REGISTE_ACTION(CG3DActionCreateVerticalAlignment, ACTION_CREATE_VERTICAL_ALIGNMENT);
	CG3DActionCreateVerticalAlignment(void);
	~CG3DActionCreateVerticalAlignment(void);
};

