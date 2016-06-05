#pragma once
#include "atltypes.h"

class CG3DDB;

#define GVIEWLAYER_MAIN	GNOTRANS("MAIN")
#define GVIEWLAYER_PREVIEW	GNOTRANS("PREVIEW")
#define GVIEWLAYER_TEMP	GNOTRANS("TEMP")


/**
	@brief
		- 3D view
		- 데이타 관리를 한다.
*/
class G_EXT_CLASS CG3DView
{
	friend class CG3DTest;
public:
	enum Attr
	{
		eAttrZoomming	= 0x00000001	// zoom 동작중인지?
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
			- window 좌표를 통해서 world 좌표를 얻는다.
	*/
	CGPoint3D CalcWorldCoordinateByWindowCoordinate(const CPoint &ptScreen);

	/**
		@brief
			- window좌표와 깊이값을 통해서 world 좌표를 얻는다.
	*/
	CGPoint3D CalcWorldCoordinateByWindowCoordinateWithDepth(const CPoint &ptwindow, const float &fDepth);

	/**
		@brief
			- world좌표로 window 좌표를 얻는다.
	*/
	CPoint CalcWindowCoordinateByWorldCoordinate(const CGPoint3D &ptWorld);

	/**
		@brief
			- ray에 의해서 교차되는 object를 계산한다.
		@return
			- 찾으면 TRUE
	*/
	bool CalcIntersectTriangularObjectByRay(const CAtlString &strViewLayer, const CGPoint3D &ptRayOrg, const CGVector3D &vRayDir, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount=0);

	/**
		@brief
			- window 좌표로 객체 교차를 계산한다.
		@return
			- 찾으면 TRUE
	*/
	bool CalcIntersectObjectByXY(const CAtlString &strViewLayer, const CPoint &pt, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);


	/**
		@brief
			- pickbox에 의해서 교차되는 object를 찾는다.
			- 최상위 부모 object를 찾는다.
			- 타입을 지정해서 하나만 찾을 수 있다.
		@param
			- const CAtlString &strObjectType : 찾을 object의 타입을 지정하는 경우 object의 type이다.
	*/
	CGObjectBase *CalcIntersectOneRootObjectByPickboxAndObjectType(const CAtlString &strViewLayer, const CPoint &ptWindow, const size_t &iPickboxSize, const CAtlString &strObjectType);
	

	/**
		@brief
			- window에 의해서 교차되는 object를 계산한다.
			- window크기의 절두체를 만들어서 검사한다.
			- 절두체 평면의 바깥에 있는것은 걸리지 않는 것으로 판정한다.
			- window를 완전히 포함하는 객체를 찾기 위해 CalcIntersectObjectByRay와 혼용한다.
		@param
			- ptWindow1, ptWindow2 : 윈도우 2 모서리 좌표(좌측 상단이 0,0)
	*/
	virtual bool CalcIntersectObjectByWindow(const CAtlString &strViewLayer, const CPoint &ptWindow1, const CPoint &ptWindow2, GOUT CAtlArray<CGObjectBase*> &arrIntersectedObject, const INT32 &iCount = 0);

	/**
		@brief
			- pickbox에 의해서 교차되는 object를 찾는다.
	*/
	virtual CGObjectBase *CalcIntersectObjectByPickbox(const CAtlString &strViewLayer, const CPoint &ptWindow, const size_t &iPickboxSize, GOUT CAtlArray<CGObjectBase*> *pArrIntersectedObject=NULL);


	/**
		@brief
			- view 초기화 데이타 리턴
			- 참조만 가능하다
			- 변경을 하려면 InitView 함수를 통해서 변경해야 한다.
	*/
	const CG3DViewInitData &GetInitData() const;

	void CreateVertexIndexBufferByObjectArrayByBufferItemID(const CAtlString &strViewLayerName, CAtlArray<CGObjectBase*> &arrOBject, const GID &bufferItemID, const bool &bAdd = false, const GID &ID = GFIRST_ID);
	void InitVertexIndexBufferByBufferItemID(const CAtlString &strViewLayerName, CAtlArray<CGObjectBase*> &arrObject, const GID &bufferItemID);

	/**
		@brief
			- buffer layer item을 추가한다.
	*/
	void AddBufferLayerItem(const CGDCBufferLayerItemIdentifier &identifier);

	// texture를 등록한다.
	void RegisterMaterialToDCByViewLayerName(const CAtlString &strViewLayerName);
	void RegisterMaterialToDCByObject(const CAtlString &strViewLayerName, const CGObjectBase &object);

	// light를 등록한다.
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
	void DrawObjectByObject(const CAtlString &strViewLayerName);	// object별로 그린다.
	void DrawObjectByPrimitiveTopology(const CAtlString &strViewLayerName);	// 기하학 종류별로 그린다.
	void DrawObjectByPrimitiveTopologyByStripVertexListIndex(const CAtlString &strViewLayerName);
	
	void InitVertexIndexBuffer(const CAtlString &strViewLayerName);
	
	void CreateVertexIndexBufferByObjectArrayByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, CAtlArray<CGObjectBase*> &arrObject, const bool &bAdd);
	void CreateVertexIndexBuffer(const CAtlString &strViewLayerName);
	void CreateVertexIndexBufferByObjectManager(const CAtlString &strViewLayerName, CGObjectManager &mng, const bool &bAdd=false);
	void AddVertexIndexBuffer(const CAtlString &strViewLayerName, CGObjectBase &objectBase);
	void AddVertexIndexBufferMultiple(const CAtlString &strViewLayerName, CAtlArray<CGObjectBase*> &arrObject);

	void UpdateObjectVertexOffset(const CGDCBufferLayerItemIdentifier &identifier, CG3DDB *pDB, void *pVertex, const UINT uVertexCount);
	const CAtlMap<GID, CGObjectBase*> *GetObjectList(const CAtlString &strViewLayerName);
	

	CPoint m_ptLastMousePos;	// 마지막 마우스 좌표
	CG3DViewInitData m_initData;
	CGDC *m_pDC;	// CG3DView는 Point만 받는다. (view에서 메모리 해제를 하면 안된다.)
	CGDCTargetView *m_pDCTargetView;	// CG3DView가 스스로 만든다(view에서 메모리 해제를 해야 한다)
	CGCamera m_camera;
	
	DWORD32 m_dwAttr;
	

public:
	CG3DView();
	virtual ~CG3DView();
};

