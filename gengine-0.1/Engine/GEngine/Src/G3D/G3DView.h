#pragma once
#include "atltypes.h"

class CG3DDB;

#define GVIEWLAYER_MAIN	GNOTRANS("MAIN")
#define GVIEWLAYER_PREVIEW	GNOTRANS("PREVIEW")
#define GVIEWLAYER_TEMP	GNOTRANS("TEMP")


/**
	@brief
		- 3D view
		- ����Ÿ ������ �Ѵ�.
*/
class G_EXT_CLASS CG3DView
{
	friend class CG3DTest;
public:
	enum Attr
	{
		eAttrZoomming	= 0x00000001	// zoom ����������?
	};

	bool ReinitView(CG3DViewInitData &initData);
	virtual bool InitView(CG3DViewInitData &initData);
	CG3DViewLayer *GetViewLayer(const CAtlString &strViewLayerName);
	CG3DDB *GetDB(const CAtlString &strViewLayerName);
	virtual void Render(const CAtlString &strViewLayerName);
	virtual void RenderOnlyAddedObject(const CAtlString &strViewLayerName, CGObjectBase &object);
	virtual void RenderOnlyAddedObjectWithSubObject(const CAtlString &strViewLayerName, CGCompoundObjectBase &objectCompound);
	virtual void RenderOnlyAddedObjectMultiple(const CAtlString &strViewLayerName, CAtlArray<CGObjectBase*> &arrObject);
	virtual void RenderOnlyDeletingObject(const CAtlString &strViewLayerName, const CGObjectBase &object);
	virtual void RenderOnlyDeletingObjectMultiple(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject);
	void RenderOnlyDeletingObjectByViewLayer(const CAtlString &strViewLayerName);
	virtual void RenderOnlyChangingColorObject(const CAtlString &strViewLayerName, const CGObjectBase &object, const CGColor &color);
	virtual void RenderOnlyChangingColorObjectMultiple(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject, const CGColor &color);
	virtual void RenderOnlyObject(const CAtlString &strViewLayerName, const CGObjectBase &object);
	virtual void RenderOnlyObjectMultiple(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject);
	virtual void Redraw();
	void OnResize();
	CGCamera &GetCamera();
	

	void PreTranslateMessage(MSG* pMsg);

	bool IsAbort() const;

	void SetAttr(const Attr &eAttr, const bool &bSet);
	bool IsAttr(const Attr &eAttr);

	INT32 GetClienHeight() const;
	
	/**
		@brief
			- window ��ǥ�� ���ؼ� world ��ǥ�� ��´�.
	*/
	CGPoint3D CalcWorldCoordinateByWindowCoordinate(const CPoint &ptScreen);

	/**
		@brief
			- window��ǥ�� ���̰��� ���ؼ� world ��ǥ�� ��´�.
	*/
	CGPoint3D CalcWorldCoordinateByWindowCoordinateWithDepth(const CPoint &ptwindow, const float &fDepth);

	/**
		@brief
			- world��ǥ�� window ��ǥ�� ��´�.
	*/
	CPoint CalcWindowCoordinateByWorldCoordinate(const CGPoint3D &ptWorld);

	/**
		@brief
			- ray�� ���ؼ� �����Ǵ� object�� ����Ѵ�.
		@return
			- ã���� TRUE
	*/
	bool CalcIntersectTriangularObjectByRay(const CAtlString &strViewLayer, const CGPoint3D &ptRayOrg, const CGVector3D &vRayDir, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount=0);

	/**
		@brief
			- window ��ǥ�� ��ü ������ ����Ѵ�.
		@return
			- ã���� TRUE
	*/
	bool CalcIntersectObjectByXY(const CAtlString &strViewLayer, const CPoint &pt, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);


	/**
		@brief
			- pickbox�� ���ؼ� �����Ǵ� object�� ã�´�.
			- �ֻ��� �θ� object�� ã�´�.
			- Ÿ���� �����ؼ� �ϳ��� ã�� �� �ִ�.
		@param
			- const CAtlString &strObjectType : ã�� object�� Ÿ���� �����ϴ� ��� object�� type�̴�.
	*/
	CGObjectBase *CalcIntersectOneRootObjectByPickboxAndObjectType(const CAtlString &strViewLayer, const CPoint &ptWindow, const size_t &iPickboxSize, const CAtlString &strObjectType);
	

	/**
		@brief
			- window�� ���ؼ� �����Ǵ� object�� ����Ѵ�.
			- windowũ���� ����ü�� ���� �˻��Ѵ�.
			- ����ü ����� �ٱ��� �ִ°��� �ɸ��� �ʴ� ������ �����Ѵ�.
			- window�� ������ �����ϴ� ��ü�� ã�� ���� CalcIntersectObjectByRay�� ȥ���Ѵ�.
		@param
			- ptWindow1, ptWindow2 : ������ 2 �𼭸� ��ǥ(���� ����� 0,0)
	*/
	virtual bool CalcIntersectObjectByWindow(const CAtlString &strViewLayer, const CPoint &ptWindow1, const CPoint &ptWindow2, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);

	/**
		@brief
			- pickbox�� ���ؼ� �����Ǵ� object�� ã�´�.
	*/
	virtual CGObjectBase *CalcIntersectObjectByPickbox(const CAtlString &strViewLayer, const CPoint &ptWindow, const size_t &iPickboxSize, GOUT CAtlArray<CGObjectBase*> *pArrIntersectedObject=NULL);


	/**
		@brief
			- view �ʱ�ȭ ����Ÿ ����
			- ������ �����ϴ�
			- ������ �Ϸ��� InitView �Լ��� ���ؼ� �����ؾ� �Ѵ�.
	*/
	const CG3DViewInitData &GetInitData() const;

	void CreateVertexIndexBufferByObjectArrayByBufferItemID(const CAtlString &strViewLayerName, CAtlArray<CGObjectBase*> &arrOBject, const GID &bufferItemID, const bool &bAdd = false, const GID &ID = GFIRST_ID);
	void InitVertexIndexBufferByBufferItemID(const CAtlString &strViewLayerName, CAtlArray<CGObjectBase*> &arrObject, const GID &bufferItemID);

	/**
		@brief
			- buffer layer item�� �߰��Ѵ�.
	*/
	void AddBufferLayerItem(const CGDCBufferLayerItemIdentifier &identifier);

	// texture�� ����Ѵ�.
	void RegisterMaterialToDCByViewLayerName(const CAtlString &strViewLayerName);
	void RegisterMaterialToDCByObject(const CAtlString &strViewLayerName, const CGObjectBase &object);

	// light�� ����Ѵ�.
	void RegisterLightToDCByViewLayerName(const CAtlString &strViewLayerName);

protected:
	bool OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnMButtonDblClk(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	
	void InitMapObjectByBufferItemID(CAtlMap<GID, CAtlArray<CGObjectBase*>*> &map);
	bool CreateFrustrumPlaneByWindow(const CPoint &ptWindow1, const CPoint &ptWindow2, GOUT CGPlane *pPlaneFrustrum);
	bool CalcIntersectObjectByWindowByBufferItemID(const CAtlString &strViewLayer, const CAtlArray<CGObjectBase*> &arrObject, const GID &bufferItemID, const CPoint &ptWindow1, const CPoint &ptWindow2, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);
	bool CalcIntersectObjectByWindowByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<CGObjectBase*> &arrObject, const CPoint &ptWindow1, const CPoint &ptWindow2, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);
	bool CalcIntersectTriangularObjectByRayByBufferItemID(const CAtlString &strViewLayer, const CAtlArray<CGObjectBase*> &arrObject, const GID &bufferItemID, const CGPoint3D &ptRayOrg, const CGVector3D &vRayDir, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);
	bool CalcIntersectTriangularObjectByRayByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<CGObjectBase*> &arrObject, const CGPoint3D &ptRayOrg, const CGVector3D &vRayDir, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);

	void RenderOnlyObjectMultipleByBufferItemID(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject, const GID &bufferItemID);
	void RenderOnlyObjectMultipleByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<CGObjectBase*> &arrObject);
	void RenderOnlyChangingColorObjectMultipleByBufferItemID(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject, const CGColor &color, const GID &bufferItemID);
	void RenderOnlyChangingColorObjectMultipleByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<CGObjectBase*> &arrObject, const CGColor &color);
	void RenderOnlyDeletingObjectMultipleByBufferItemID(const CAtlString &strViewLayerName, const CAtlArray<CGObjectBase*> &arrObject, const GID &bufferItemID);
	void RenderOnlyDeletingObjectMultipleByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<CGObjectBase*> &arrObject);
	virtual void FindAllTrianglaurObjectToIntersectByRay(const CAtlString &strViewLayer, const CGPoint3D &ptRayOrg, const CGVector3D &vRayDir, GOUT CAtlArray<CGObjectBase*> &arrObject);
	virtual void FindAllObjectToIntersectByRectangle(const CAtlString &strViewLayer, CGPlane *pPlaneFrustrum, GOUT CAtlArray<CGObjectBase*> &arrObject);
	virtual void StartZoom();
	virtual void EndZoom();
	void GetObjectByPrimitiveTopology(const CAtlArray<CGObjectBase*> &arrObjectSrc, const PrimitiveTopology &ePrimitiveTopology, const CGDCBufferLayerItemIdentifier &identifier, GOUT CAtlArray<CGObjectBase*> &arrObjectTar);
	void GetObjectByBufferLayerBufferItemID(const CAtlString &strViewLayer, const CAtlArray<CGObjectBase*> &arrObject, GOUT CAtlMap<GID, CAtlArray<CGObjectBase*>*> &mapObjectByBufferItemID);
	void OptimizeProperty(const CAtlString &strViewLayerName);
	void DrawObject();
	void DrawObjectByObject(const CAtlString &strViewLayerName);	// object���� �׸���.
	void DrawObjectByPrimitiveTopology(const CAtlString &strViewLayerName);	// ������ �������� �׸���.
	void DrawObjectByPrimitiveTopologyByStripVertexListIndex(const CAtlString &strViewLayerName);
	
	void InitVertexIndexBuffer(const CAtlString &strViewLayerName);
	
	void CreateVertexIndexBufferByObjectArrayByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, CAtlArray<CGObjectBase*> &arrObject, const bool &bAdd);
	void CreateVertexIndexBuffer(const CAtlString &strViewLayerName);
	void CreateVertexIndexBufferByObjectManager(const CAtlString &strViewLayerName, CGObjectManager &mng, const bool &bAdd=false);
	void AddVertexIndexBuffer(const CAtlString &strViewLayerName, CGObjectBase &objectBase);
	void AddVertexIndexBufferMultiple(const CAtlString &strViewLayerName, CAtlArray<CGObjectBase*> &arrObject);

	void UpdateObjectVertexOffset(const CGDCBufferLayerItemIdentifier &identifier, CG3DDB *pDB, void *pVertex, const UINT uVertexCount);
	const CAtlMap<GID, CGObjectBase*> *GetObjectList(const CAtlString &strViewLayerName);
	

	CPoint m_ptLastMousePos;	// ������ ���콺 ��ǥ
	CG3DViewInitData m_initData;
	CGDC *m_pDC;	// CG3DView�� Point�� �޴´�. (view���� �޸� ������ �ϸ� �ȵȴ�.)
	CGDCTargetView *m_pDCTargetView;	// CG3DView�� ������ �����(view���� �޸� ������ �ؾ� �Ѵ�)
	CGCamera m_camera;
	
	DWORD32 m_dwAttr;
	

public:
	CG3DView();
	virtual ~CG3DView();
};

