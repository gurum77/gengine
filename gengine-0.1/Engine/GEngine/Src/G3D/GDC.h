#pragma once

#include "atltypes.h"
#include <map>


/**
	@brief
		- DC
		- 정보를 화면에 표시한다.
		- 데이타 관리는 하지 않는다.
		- graphics library와 직접 통신한다.
*/
class G_EXT_CLASS CGDC
{
public:

	/**
		@brief
			- DC Target View를 초기화 한다.
				- fill mode
				- cull mode
				- 안티알리아싱
	*/
	virtual void InitDCTargetViewByInitData(CGDCTargetView *pDCTargetView, const CGDCTargetViewInitData &initData) = 0;

	/**
		@brief
			- GVERTEX를 Vertex로 복사한다.
	*/
	virtual void CopyGVERTEXToVertex(const CGDCBufferLayerItemIdentifier &identifier, const GVERTEX *pFrom, void *pToStart, const UINT &uToIdx) = 0;
	/**
		@brief
			- vertex의 ID 정보를 리턴한다.
	*/
	virtual UINT GetVertexID(const CGDCBufferLayerItemIdentifier &identifier, const void *pVertex, const UINT uIdx) = 0;

	/**
		@brief
			- vertex의 pos 정보를 리턴한다.
	*/
	virtual gfloat3 GetVertexPos(const CGDCBufferLayerItemIdentifier &identifier, const void *pVertex, const UINT uIdx) = 0;

	/**
		@brief
			- vertex의 color를 변경한다.
	*/
	virtual void ChangeVertexColor(const CGDCBufferLayerItemIdentifier &identifier, GINOUT void *pVertex, const UINT uIdx, const gfloat3 &fRGB) = 0;


	/**
		@brief
			- view layer에 포함되어 있는 모든 layer item의 identifier를 가져온다.
	*/
	virtual void GetAllBufferLayerItemIdentifierByBufferLayerName(const CAtlString &strViewLayer, GOUT CAtlArray<CGDCBufferLayerItemIdentifier> &arrIdentifier) = 0;

	/**
		@brief
			- 그래픽 라이브러리를 초기화 한다.
	*/
	virtual bool InitDC(const CGDCInitData &initData) = 0;

	/**
		@brief
			- 현재 뷰의 카메라를 설정한다.
			- 카메라 설정후 frustum을 계산하여 camera에 set 한다.
	*/
	virtual bool SetCamera(CGDCTargetView *pDCTargetView, GINOUT CGCamera &camera) = 0;

	/**
		@brief
			- 현재 뷰의 안개를 설정한다.
	*/
	virtual void SetFog(const CGFog &fog);

	
	/**
		@brief
			- world 좌표 변환 matrix를 설정한다.
	*/
	virtual bool SetWorldTransform(CGDCTargetView *pDCTargetView, const CGMatrix &matTransform) = 0;

	/**
		@brief
			- view의 크기 조정시 호출
	*/
	virtual bool OnResize(CGDCTargetView *pDCTargetView, const CGDCTargetViewInitData &initData) = 0;

	/**
		@brief
			- 장면을 그릴 준비를 한다.
				- 배경을 지운다.
				- object외의 모든 것을 준비한다.
	*/
	virtual void PrepareDrawScene(CGDCTargetView *pDCTargetView) = 0;

	/**
		@brief
			- 효과를 적용한다.
			- texture를 적용
			- light 적용
	*/
	virtual void ApplyEffect(const CGDCBufferLayerItemIdentifier &identifier) = 0;

	/**
		@brief
			- Light를 등록한다.
	*/
	virtual void RegisterLight(const CGLightManager &lightMng) = 0;

	/**
		@brief
			- 장면 그리기를 완료한다.
			- buffer에 그려진 장면을 view로 swap한다.
	*/
	virtual void CompleteDrawScene(CGDCTargetView *pDCTargetView) = 0;

	/**
		@brief
			- point list를 그린다.
	*/
	virtual void DrawPointList(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	/**
		@brief
			- point list를 index로 그린다.
	*/
	virtual void DrawPointListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount) = 0;
	

	/**
		@brief
			- point를 그린다.
	*/
	virtual void DrawLine(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	

	/**
		@brief
			- line list를 그린다.
			- 짝수번째 line만 그린다.
	*/
	virtual void DrawLineList(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	/**
		@brief
			- line list를 그린다.
			- 짝수번째 line만 그린다.
			- index로 그린다.
	*/
	virtual void DrawLineListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount) = 0;

	/**
		@brief
			- triangle list를 그린다.
			- 3개의 vertex를 각각의 triangle로 그린다.
	*/
	virtual void DrawTriangleList(const UINT &uVertexOffset, const UINT &uVertexCount) = 0;

	/**
		@brief
			- triangle list를 그린다.
			- 3개의 vertex를 각각의 triangle로 그린다.
			- index로 그린다.
	*/
	virtual void DrawTriangleListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount) = 0;


	/**
		@brief
			- vertex buffer를 초기화 한다.
		@param
			- const GID &ID : GNONE_ID - 모든 item을 초기화 한다. !GNONE_ID - 해당 ID의 item만 초기화 한다.
	*/
	virtual void InitVertexBuffer(const CAtlString &strLayerName, const GID &ID=GNONE_ID) = 0;
	
	/**
		@brief
			- index buffer를 초기화 한다.
		@param
			- const GID &ID : GNONE_ID - 모든 item을 초기화 한다. !GNONE_ID - 해당 ID의 item만 초기화 한다.
	*/
	virtual void InitIndexBuffer(const CAtlString &strLayerName, const GID &ID=GNONE_ID) = 0;

	/**
		@brief
			- 사용할 vertex buffer를 설정한다.
	*/
	virtual void SetCurVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &eUseVertexBuffer) = 0;

	/**
		@brief
			- 사용할 index buffer를 설정한다.
	*/
	virtual void SetCurIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &eUseVertexBuffer) = 0;

	/**
		@brief
			 - vertex buffer를 생성한다.
	*/
	virtual void CreateVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<GVERTEX> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer를 생성한다.
		@
	*/
	virtual void CreateIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<UINT32> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- vertex buffer에 vertex를 추가한다.
	*/
	virtual void AddVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<GVERTEX> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer에 vertex를 추가한다.
	*/
	virtual void AddIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<UINT32> &arr, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- vertex buffer의 일부분을 삭제한다.
	*/
	virtual void DeleteVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const UINT32 &uDeleteVertexOffset, const UINT32 &uDeleteVertexSize, const PrimitiveTopology &ePrimitiveTopology) = 0;
	virtual void DeleteVertexBufferMultiple(const CGDCBufferLayerItemIdentifier &identifier, const std::map<UINT32, UINT32> &mapVertexOffsetCount, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer의 일부분을 삭제한다.
	*/
	virtual void DeleteIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const UINT32 &uDeleteIndexOffset, const UINT32 &uDeleteIndexSize, const PrimitiveTopology &ePrimitiveTopology) = 0;
	virtual void DeleteIndexBufferMultiple(const CGDCBufferLayerItemIdentifier &identifier, const std::map<UINT32, UINT32> &mapIndexOffsetCount, const PrimitiveTopology &ePrimitiveTopology) = 0;

	
	/**
		@brief
			- vertex buffer를 open한다.
	*/
	virtual void *OpenVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer를 open한다.
	*/
	virtual UINT32 *OpenIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- vertex buffer를 close한다.
	*/
	virtual void CloseVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer를 close한다.
	*/
	virtual void CloseIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- window 좌표를 통해서 world 좌표를 얻는다.
	*/
	virtual CGPoint3D CalcWorldCoordinateByWindowCoordinate(CGDCTargetView *pDCTargetView, const CPoint &ptWindow) = 0;

	/**
		@brief
			- window 좌표와 깊이값을 통해서 world 좌표를 얻는다.
	*/
	virtual CGPoint3D CalcWorldCoordinateByWindowCoordinateWithDepth(CGDCTargetView *pDCTargetView, const CPoint &ptwindow, const float &fDepth) = 0;

	/**
		@brief
			- world 좌표를 통해서 window 좌표를 얻는다.
	*/
	virtual CPoint CalcWindowCoordinateByWorldCoordinate(CGDCTargetView *pDCTargetView, const CGPoint3D &ptWorld) = 0;

	/**
		@brief
			- DC가 뿌려지는 view를 생성한다.
	*/
	virtual CGDCTargetView *CreateDCTargetView(const CGDCTargetViewInitData &initData) = 0;

	/**
		@brief
			- vertex buffer의 개수
	*/
	virtual void SetPrimitiveVertexCount(const CGDCBufferLayerItemIdentifier &identifier, const UINT &uPrimitiveVertexCount, const PrimitiveTopology &ePrimitiveTopology) = 0;
	virtual UINT GetPrimitiveVertexCount(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- index buffer의 개수
	*/
	virtual UINT GetPrimitiveIndexCount(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology) = 0;

	/**
		@brief
			- current buffer layer를 설정한다.
			- Draw.., CreateVertexBuffer등 사용할 buffer의 layer를 미리 지정하고 사용해야 한다.
	*/
	void SetCurBufferLayer(const CAtlString &strLayerName);

	/**
		@brief
			- buffer layer를 추가한다.
	*/
	virtual bool AddBufferLayer(const CAtlString &strLayerName) = 0;

	/**
		@brief
			- buffer layer item을 추가한다.
			- identifier의 특성을 반영한다.
				- texture가 있는 경우 texture를 DC에 등록한다.
	*/
	virtual bool AddBufferLayerItem(const CGDCBufferLayerItemIdentifier &identifier) = 0;


	/**
		@brief
			- background color
	*/
	void SetBackgroundColor(const CGColor &color);

	/**
		@brief
			- 마지막으로 그린 target view
	*/
	CGDCTargetView *GetLastTargetView();

	/**
		@brief
			- 어떤 동작을 중단해야 하는 경우 true로 설정한다.
	*/
	void SetAbort(const bool &bAbort);
	const bool &GetAbort() const;

	void SetLock(const bool &bLock);
	const bool &GetLoock() const;

	/**
		@brief
			- view layer의 특정 buffer layer item에 포함되어 있는 모든 identifier를 가져온다.
	*/
	void GetAllBufferLayerItemIdentifierByBufferLayerNameByBufferLayerItem(const CAtlString &strViewLayer, const GID &bufferItemID, GOUT CAtlArray<CGDCBufferLayerItemIdentifier> &arrIdentifier);

	/**
		@brief
			- view layer에 포함되어 있는 모든 layer item의 ID를 가져온다.
	*/
	void GetAllBufferLayerItemIDByBufferLayerName(const CAtlString &strViewLayer, GOUT CAtlArray<GID> &arrID);


protected:
	CGColor m_backgroundColor;
	CGFog m_fog;
	CGDCTargetView *m_pLastTargetView;
	bool m_bAbort;	// 어떤 동작을 멈춰야 하는 경우 true를 준다.
	
public:
	CGDC();
	virtual ~CGDC();
};

