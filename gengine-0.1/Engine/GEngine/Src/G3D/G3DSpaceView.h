#pragma once

#define GVIEWLAYER_SPACE	GNOTRANS("SPACE")
class CGSelectionManager;
/**
	@brief
		- space view
		- CG3DSpaceView�� CG3DView�� ���� ��뷮ó���� ���������� �ӵ��� ������, ��Ƽ�䰡 �������� �ʴ´ٴ� ������ �ִ�.
		- ����
			- CG3DView �� ������ ������ ��ħ
			- CGSelectManager ����
				- space ������ �����ϱ� ���ؼ��� select manager�� �����Ǿ�� �Ѵ�.
*/
class G_EXT_CLASS CG3DSpaceView :
	public CG3DView
{
public:
	// space view�� �Ӽ�
	enum Attr
	{
		eAttrDisplaySpace	= 0x00000001,
		eAttrLockEndZoom	= 0x00000002
	};

public:
	static UINT WINAPI Thread_EndZoom( LPVOID );  
	CGSpaceManager &GetSpaceManager();
	bool IsAttr(const Attr &eAttr) const;
	const DWORD32 &GetAttr() const;
	void SetAttr(const DWORD32 &dwAttr);

	void SetSelectManager(CGSelectionManager *pSelectManager);
	CGSelectionManager *GetSelectManager();

	virtual bool InitView(CG3DViewInitData &initData);
	virtual void Render(const CAtlString &strViewLayerName);
	virtual void RenderOnlyAddedObject(const CAtlString &strViewLayerName, CGObjectBase &object);
	virtual void RenderOnlyDeletingObject(const CAtlString &strViewLayerName, const CGObjectBase &object);
	virtual void RenderOnlyDeletingObjectMultiple(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject);
	virtual void RenderOnlyChangingColorObject(const CAtlString &strViewLayerName, const CGObjectBase &object, const CGColor &color);
	virtual void RenderOnlyChangingColorObjectMultiple(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject, const CGColor &color);
	virtual void RenderOnlyObject(const CAtlString &strViewLayerName, const CGObjectBase &object);
	virtual void RenderOnlyObjectMultiple(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject);
	virtual void Redraw();
	virtual bool CalcIntersectObjectByWindow(const CAtlString &strViewLayer, const CPoint &ptWindow1, const CPoint &ptWindow2, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);
	virtual CGObjectBase *CalcIntersectObjectByPickbox(const CAtlString &strViewLayer, const CPoint &ptWindow, const size_t &iPickboxSize, GOUT CAtlArray<CGObjectBase*> *pArrIntersectedObject=NULL);

protected:
	bool IsRenderableLayer(const CAtlString &strViewLayerName) const;
	void RenderOnlyDeletingSpaceByObject(const CGObjectBase &object);
	virtual void EndZoom();

	CGSpaceManager m_spaceManager;
	DWORD32 m_dwAttr;
	CGSelectionManager *m_pSelectManager;

public:
	CG3DSpaceView();
	virtual ~CG3DSpaceView();
};

