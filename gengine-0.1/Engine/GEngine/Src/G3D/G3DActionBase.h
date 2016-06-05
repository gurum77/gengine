#pragma once

class CG3DActionManager;

/**
	@brief
		- action base Ŭ����
		- user defined action�� ����� ���ؼ��� �ݵ�� ��ӹ޾ƾ� �Ѵ�.
		- action ��� ���
			- action ���߽� : action header���� GDEFINE_REGISTE_ACTION ����ؼ� ���
			- action ���� : ����� ������Ʈ���� GIMPLEMENT_REGISTE_ACTION ����ؼ� ���
*/
class G_EXT_CLASS CG3DActionBase
{
protected:
	CG3DActionManager *m_pActionManager;
	
	CG3DView *GetView();
	CG3DDB *GetPreviewDB();
	CG3DDB *GetTempDB();
	void RenderPreviewDB();
	void RenderTempDB();
	void CopySelectedObjectToTempDB();
	void InitPreviewDB();
	void InitTempDB();




public:
		/**
		@brief
			- ���� �������� �Ѿ�� ���� Ű���� �Ǵ��Ѵ�.
	*/
	virtual bool IsNextStepKey(UINT nChar) const;

	/**
		@brief
			- �׼��� �����ϱ� ���� Ű���� �Ǵ��Ѵ�.
	*/
	virtual bool IsAbortActionKey(UINT nChar) const;


	/**
		@brief
			- �׼��� ���� ���� �ϱ� ���� Ű���� �Ǵ��Ѵ�.
	*/
	virtual bool IsCompleteActionKey(UINT nChar) const;

	void SetActionManager(CG3DActionManager *pActionManager);

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
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);

	/**
		@brief
			- key �̺�Ʈ �ڵ巯�̴�.
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	/**
		@brief
			- action�� �̸����� ��ü�� �ִ� ��� �� �Լ��� ������ �Ͽ� �̸����� ��ü�� view���� ���쵵�� �����ؾ� �Ѵ�.
	*/
	virtual void FlushPreview();

	/**
		@brief
			- action�� �̸����� ��ü�� �ִ� ��� �� �Լ��� ������ �Ͽ� �̸����� ��ü�� �׸����� �����ؾ� �Ѵ�.
	*/
	virtual void RenderPreview();

	/**
		@brief
			- action�� ������ ������ �� �ִ� string
	*/
	virtual CAtlString GetStrType() = 0;

	CG3DActionBase();
	~CG3DActionBase();
};

