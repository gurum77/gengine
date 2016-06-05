#pragma once

#include "atltypes.h"
#include <map>


/**
	@brief
		- DC
		- ������ ȭ�鿡 ǥ���Ѵ�.
		- ����Ÿ ������ ���� �ʴ´�.
		- graphics library�� ���� ����Ѵ�.
*/
class G_EXT_CLASS CGDC
{
public:

	/**
		@brief
			- DC Target View�� �ʱ�ȭ �Ѵ�.
				- fill mode
				- cull mode
				- ��Ƽ�˸��ƽ�
	*/
	virtual void InitDCTargetViewByInitData(CGDCTargetView *pDCTargetView, const CGDCTargetViewInitData &initData) = 0;

	/**
		@brief
			- GVERTEX�� Vertex�� �����Ѵ�.
	*/
	virtual void CopyGVERTEXToVertex(const CGDCBufferLayerItemIdentifier &identifier, const GVERTEX *pFrom, void *pToStart, const UINT &uToIdx) = 0;
	/**
		@brief
			- vertex�� ID ������ �����Ѵ�.
	*/
	virtual UINT GetVertexID(const CGDCBufferLayerItemIdentifier &identifier, const void *pVertex, const UINT uIdx) = 0;

	/**
		@brief
			- vertex�� pos ������ �����Ѵ�.
	*/
	virtual gfloat3 GetVertexPos(const CGDCBufferLayerItemIdentifier &identifier, const void *pVertex, const UINT uIdx) = 0;

	/**
		@brief
			- vertex�� color�� �����Ѵ�.
	*/
	virtual void ChangeVertexColor(const CGDCBufferLayerItemIdentifier &identifier, GINOUT void *pVertex, const UINT uIdx, const gfloat3 &fRGB) = 0;


	/**
		@brief
			- view layer�� ���ԵǾ� �ִ� ��� layer item�� identifier�� �����´�.
	*/
	virtual void GetAllBufferLayerItemIdentifierByBufferLayerName(const CAtlString &strViewLayer, GOUT CAtlArray<CGDCBufferLayerItemIdentifier> &arrIdentifier) = 0;

	/**
		@brief
			- �׷��� ���̺귯���� �ʱ�ȭ �Ѵ�.
	*/
	virtual bool InitDC(const CGDCInitData &initData) = 0;

	/**
		@brief
			- ���� ���� ī�޶� �����Ѵ�.
			- ī�޶� ������ frustum�� ����Ͽ� camera�� set �Ѵ�.
	*/
	virtual bool SetCamera(CGDCTargetView *pDCTargetView, GINOUT CGCamera &camera) = 0;

	/**
		@brief
			- ���� ���� �Ȱ��� �����Ѵ�.
	*/
	virtual void SetFog(const CGFog &fog);

	
	/**
		@brief
			- world ��ǥ ��ȯ matrix�� �����Ѵ�.
	*/
	virtual bool SetWorldTransform(CGDCTargetView *pDCTargetView, const CGMatrix &matTransform) = 0;

	/**
		@brief
			- view�� ũ�� ������ ȣ��
	*/
	virtual bool OnResize(CGDCTargetView *pDCTargetView, const CGDCTargetViewInitData &initData) = 0;

	/**
		@brief
			- ����� �׸� �غ� �Ѵ�.
				- ����� �����.
				- object���� ��� ���� �غ��Ѵ�.
	*/
	virtual void PrepareDrawScene(CGDCTargetView *pDCTargetView) = 0;

	/**
		@brief
			- ȿ���� �����Ѵ�.
			- texture�� ����
			- light ����
	*/
	virtual void ApplyEffect(const CGDCBufferLayerItemIdentifier &identifier) = 0;

	/**
		@brief
			- Light�� ����Ѵ�.
	*/
	virtual void RegisterLight(const CGLightManager &lightMng) = 0;

	/**
		@brief
			- ��� �׸��⸦ �Ϸ��Ѵ�.
			- buffer�� �׷��� ����� view�� swap�Ѵ�.
	*/
	virtual void CompleteDrawScene(CGDCTargetView *pDCTargetView) = 0;

	/**
		@brief
			- point list�� �׸���.
	*/
	virtual void DrawPointList(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	/**
		@brief
			- point list�� index�� �׸���.
	*/
	virtual void DrawPointListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount) = 0;
	

	/**
		@brief
			- point�� �׸���.
	*/
	virtual void DrawLine(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	

	/**
		@brief
			- line list�� �׸���.
			- ¦����° line�� �׸���.
	*/
	virtual void DrawLineList(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	/**
		@brief
			- line list�� �׸���.
			- ¦����° line�� �׸���.
			- index�� �׸���.
	*/
	virtual void DrawLineListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount) = 0;

	/**
		@brief
			- triangle list�� �׸���.
			- 3���� vertex�� ������ triangle�� �׸���.
	*/
	virtual void DrawTriangleList(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	/**
		@brief
			- triangle list�� �׸���.
			- 3���� vertex�� ������ triangle�� �׸���.
			- index�� �׸���.
	*/
	virtual void DrawTriangleListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount) = 0;


	/**
		@brief
			- vertex buffer�� �ʱ�ȭ �Ѵ�.
		@param
			- const GID &ID : GNONE_ID - ��� item�� �ʱ�ȭ �Ѵ�. !GNONE_ID - �ش� ID�� item�� �ʱ�ȭ �Ѵ�.
	*/
	virtual void InitVertexBuffer(const CAtlString &strLayerName, const GID &ID=GNONE_ID) = 0;
	
	/**
		@brief
			- index buffer�� �ʱ�ȭ �Ѵ�.
		@param
			- const GID &ID : GNONE_ID - ��� item�� �ʱ�ȭ �Ѵ�. !GNONE_ID - �ش� ID�� item�� �ʱ�ȭ �Ѵ�.
	*/
	virtual void InitIndexBuffer(const CAtlString &strLayerName, const GID &ID=GNONE_ID) = 0;

	/**
		@brief
			- ����� vertex buffer�� �����Ѵ�.
	*/
	virtual void SetCurVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &eUseVertexBuffer) = 0;

	/**
		@brief
			- ����� index buffer�� �����Ѵ�.
	*/
	virtual void SetCurIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &eUseVertexBuffer) = 0;

	/**
		@brief
			 - vertex buffer�� �����Ѵ�.
	*/
	virtual void CreateVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<GVERTEX> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer�� �����Ѵ�.
		@
	*/
	virtual void CreateIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<UINT32> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- vertex buffer�� vertex�� �߰��Ѵ�.
	*/
	virtual void AddVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<GVERTEX> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer�� vertex�� �߰��Ѵ�.
	*/
	virtual void AddIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<UINT32> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- vertex buffer�� �Ϻκ��� �����Ѵ�.
	*/
	virtual void DeleteVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const UINT32 &uDeleteVertexOffset, const UINT32 &uDeleteVertexSize, const PrimitiveTopology &ePrimitiveTopology) = 0;
	virtual void DeleteVertexBufferMultiple(const CGDCBufferLayerItemIdentifier &identifier, const std::map<UINT32, UINT32> &mapVertexOffsetCount, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer�� �Ϻκ��� �����Ѵ�.
	*/
	virtual void DeleteIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const UINT32 &uDeleteIndexOffset, const UINT32 &uDeleteIndexSize, const PrimitiveTopology &ePrimitiveTopology) = 0;
	virtual void DeleteIndexBufferMultiple(const CGDCBufferLayerItemIdentifier &identifier, const std::map<UINT32, UINT32> &mapIndexOffsetCount, const PrimitiveTopology &ePrimitiveTopology) = 0;

	
	/**
		@brief
			- vertex buffer�� open�Ѵ�.
	*/
	virtual void *OpenVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer�� open�Ѵ�.
	*/
	virtual UINT32 *OpenIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- vertex buffer�� close�Ѵ�.
	*/
	virtual void CloseVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer�� close�Ѵ�.
	*/
	virtual void CloseIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- window ��ǥ�� ���ؼ� world ��ǥ�� ��´�.
	*/
	virtual CGPoint3D CalcWorldCoordinateByWindowCoordinate(CGDCTargetView *pDCTargetView, const CPoint &ptWindow) = 0;

	/**
		@brief
			- window ��ǥ�� ���̰��� ���ؼ� world ��ǥ�� ��´�.
	*/
	virtual CGPoint3D CalcWorldCoordinateByWindowCoordinateWithDepth(CGDCTargetView *pDCTargetView, const CPoint &ptwindow, const float &fDepth) = 0;

	/**
		@brief
			- world ��ǥ�� ���ؼ� window ��ǥ�� ��´�.
	*/
	virtual CPoint CalcWindowCoordinateByWorldCoordinate(CGDCTargetView *pDCTargetView, const CGPoint3D &ptWorld) = 0;

	/**
		@brief
			- DC�� �ѷ����� view�� �����Ѵ�.
	*/
	virtual CGDCTargetView *CreateDCTargetView(const CGDCTargetViewInitData &initData) = 0;

	/**
		@brief
			- vertex buffer�� ����
	*/
	virtual void SetPrimitiveVertexCount(const CGDCBufferLayerItemIdentifier &identifier, const UINT &uPrimitiveVertexCount, const PrimitiveTopology &ePrimitiveTopology) = 0;
	virtual UINT GetPrimitiveVertexCount(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer�� ����
	*/
	virtual UINT GetPrimitiveIndexCount(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- current buffer layer�� �����Ѵ�.
			- Draw.., CreateVertexBuffer�� ����� buffer�� layer�� �̸� �����ϰ� ����ؾ� �Ѵ�.
	*/
	void SetCurBufferLayer(const CAtlString &strLayerName);

	/**
		@brief
			- buffer layer�� �߰��Ѵ�.
	*/
	virtual bool AddBufferLayer(const CAtlString &strLayerName) = 0;

	/**
		@brief
			- buffer layer item�� �߰��Ѵ�.
			- identifier�� Ư���� �ݿ��Ѵ�.
				- texture�� �ִ� ��� texture�� DC�� ����Ѵ�.
	*/
	virtual bool AddBufferLayerItem(const CGDCBufferLayerItemIdentifier &identifier) = 0;


	/**
		@brief
			- background color
	*/
	void SetBackgroundColor(const CGColor &color);

	/**
		@brief
			- ���������� �׸� target view
	*/
	CGDCTargetView *GetLastTargetView();

	/**
		@brief
			- � ������ �ߴ��ؾ� �ϴ� ��� true�� �����Ѵ�.
	*/
	void SetAbort(const bool &bAbort);
	const bool &GetAbort() const;

	void SetLock(const bool &bLock);
	const bool &GetLoock() const;

	/**
		@brief
			- view layer�� Ư�� buffer layer item�� ���ԵǾ� �ִ� ��� identifier�� �����´�.
	*/
	void GetAllBufferLayerItemIdentifierByBufferLayerNameByBufferLayerItem(const CAtlString &strViewLayer, const GID &bufferItemID, GOUT CAtlArray<CGDCBufferLayerItemIdentifier> &arrIdentifier);

	/**
		@brief
			- view layer�� ���ԵǾ� �ִ� ��� layer item�� ID�� �����´�.
	*/
	void GetAllBufferLayerItemIDByBufferLayerName(const CAtlString &strViewLayer, GOUT CAtlArray<GID> &arrID);


protected:
	CGColor m_backgroundColor;
	CGFog m_fog;
	CGDCTargetView *m_pLastTargetView;
	bool m_bAbort;	// � ������ ����� �ϴ� ��� true�� �ش�.
	
public:
	CGDC();
	virtual ~CGDC();
};

