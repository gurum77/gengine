#pragma once
// direct define warning ²¨µÒ
// todo : ²ôÁö ¾Ê¾Æµµ warningÀÌ ¶ßÁö ¾Êµµ·Ï ¼öÁ¤ÇØ¾ßÇÔ.
#pragma warning(disable:4005)

#include <d3dx11.h>
#include "../../../../Lib/DirectX11/Effects11/Inc/d3dx11effect.h"
#include "../../../../lib/DirectX11/Common/LightHelper.h"
#include <dxerr.h>
#include "xnamath.h"
#include "atltypes.h"

class Effects;
class InputLayouts;
/**
	@brief
		- GDCÀÇ directx 11 ¹öÀü
*/
class G_EXT_CLASS CGDCDirectX11 :
	public CGDC
{
private:
	enum VertexType
	{
		eVertexType_LightTex32,
		eVertexType_Color24
	};
public:
	virtual void InitDCTargetViewByInitData(CGDCTargetView *pDCTargetView, const CGDCTargetViewInitData &initData);
	virtual void CopyGVERTEXToVertex(const CGDCBufferLayerItemIdentifier &identifier, const GVERTEX *pFrom, void *pToStart, const UINT &uToIdx);
	virtual UINT GetVertexID(const CGDCBufferLayerItemIdentifier &identifier, const void *pVertex, const UINT uIdx);
	virtual gfloat3 GetVertexPos(const CGDCBufferLayerItemIdentifier &identifier, const void *pVertex, const UINT uIdx);
	virtual void ChangeVertexColor(const CGDCBufferLayerItemIdentifier &identifier, GINOUT void *pVertex, const UINT uIdx, const gfloat3 &fRGB);
	virtual void GetAllBufferLayerItemIdentifierByBufferLayerName(const CAtlString &strViewLayer, GOUT CAtlArray<CGDCBufferLayerItemIdentifier> &arrIdentifier);
	virtual bool InitDC(const CGDCInitData &initData);
	virtual bool SetCamera(CGDCTargetView *pDCTargetView, GINOUT CGCamera &camera);
	virtual bool SetWorldTransform(CGDCTargetView *pDCTargetView, const CGMatrix &matTransform);
	virtual bool OnResize(CGDCTargetView *pDCTargetView, const CGDCTargetViewInitData &initData);
	virtual void DrawPointList(const UINT &uVertexOffset, const UINT &uVertexCount);
	virtual void DrawPointListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount);
	virtual void DrawLine(const UINT &uVertexOffset, const UINT &uVertexCount);
	virtual void DrawLineList(const UINT &uVertexOffset, const UINT &uVertexCount);
	virtual void DrawLineListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount);
	virtual void DrawTriangleList(const UINT &uVertexOffset, const UINT &uVertexCount);
	virtual void DrawTriangleListIndexed(const UINT &uIndexOffset, const UINT &uIndexCount);
	virtual void InitVertexBuffer(const CAtlString &strLayerName, const GID &ID=GNONE_ID);
	virtual void InitIndexBuffer(const CAtlString &strLayerName, const GID &ID=GNONE_ID);
	virtual void CreateVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<GVERTEX> &arr, const PrimitiveTopology &ePrimitiveTopology);
	virtual void CreateIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<UINT32> &arr, const PrimitiveTopology &ePrimitiveTopology);
	virtual void AddVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<GVERTEX> &arr, const PrimitiveTopology &ePrimitiveTopology);
	virtual void AddIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const CAtlArray<UINT32> &arr, const PrimitiveTopology &ePrimitiveTopology);
	virtual void DeleteVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const UINT32 &uDeleteVertexOffset, const UINT32 &uDeleteVertexSize, const PrimitiveTopology &ePrimitiveTopology);
	virtual void DeleteVertexBufferMultiple(const CGDCBufferLayerItemIdentifier &identifier, const std::map<UINT32, UINT32> &mapVertexOffsetCount, const PrimitiveTopology &ePrimitiveTopology);
	virtual void DeleteIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const UINT32 &uDeleteIndexOffset, const UINT32 &uDeleteIndexSize, const PrimitiveTopology &ePrimitiveTopology);
	virtual void DeleteIndexBufferMultiple(const CGDCBufferLayerItemIdentifier &identifier, const std::map<UINT32, UINT32> &mapIndexOffsetCount, const PrimitiveTopology &ePrimitiveTopology);
	virtual void *OpenVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology);
	virtual UINT32 *OpenIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology);
	virtual void CloseVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology);
	virtual void CloseIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology);
	virtual void SetCurVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &eUseVertexBuffer);
	virtual void SetCurIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &eUseVertexBuffer);
	virtual void PrepareDrawScene(CGDCTargetView *pDCTargetView);
	virtual void ApplyEffect(const CGDCBufferLayerItemIdentifier &identifier);
	virtual void RegisterLight(const CGLightManager &lightMng);
	virtual void CompleteDrawScene(CGDCTargetView *pDCTargetView);
	virtual void SetPrimitiveVertexCount(const CGDCBufferLayerItemIdentifier &identifier, const UINT &uPrimitiveVertexCount, const PrimitiveTopology &ePrimitiveTopology);
	virtual UINT GetPrimitiveVertexCount(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology);
	virtual UINT GetPrimitiveIndexCount(const CGDCBufferLayerItemIdentifier &identifier, const PrimitiveTopology &ePrimitiveTopology);
	virtual CGPoint3D CalcWorldCoordinateByWindowCoordinate(CGDCTargetView *pDCTargetView, const CPoint &ptWindow);
	virtual CGPoint3D CalcWorldCoordinateByWindowCoordinateWithDepth(CGDCTargetView *pDCTargetView, const CPoint &ptwindow, const float &fDepth);
	virtual CPoint CalcWindowCoordinateByWorldCoordinate(CGDCTargetView *pDCTargetView, const CGPoint3D &ptWorld);
	virtual CGDCTargetView *CreateDCTargetView(const CGDCTargetViewInitData &initData);
	virtual bool AddBufferLayer(const CAtlString &strLayerName);
	virtual bool AddBufferLayerItem(const CGDCBufferLayerItemIdentifier &identifier);

protected:
	
	void CreateRasterizerState(CGDCDirectX11TargetView &dcTargetView, const CGDCTargetViewInitData &initData);
	void ApplyEffect_Fog();
	void *MakeSubresourceData(const CGDCBufferLayerItemIdentifier &identifier, const GVERTEX *pVertex, const UINT &uCount);
	UINT GetSizeOfVertex(const CGDCBufferLayerItemIdentifier &identifier);
	const CGDCDirectX11::VertexType GetVertexType(const CGDCBufferLayerItemIdentifier &identifier) const;
	ID3DX11EffectTechnique *GetActiveEffectTechnique(const CGDCBufferLayerItemIdentifier &identifier);
	ID3D11InputLayout *GetActiveInputLayout(const CGDCBufferLayerItemIdentifier &identifier);
	void ReportDebuggingInformation();
	void InitBufferLayer();
	
	void CreateVertexBufferByVoid(const CGDCBufferLayerItemIdentifier &identifier, void *pVertex, const UINT &uCount, const PrimitiveTopology &ePrimitiveTopology);
	void CreateVertexBuffer(const CGDCBufferLayerItemIdentifier &identifier, GVERTEX *pVertex, const UINT &uCount, const PrimitiveTopology &ePrimitiveTopology);
	void CreateIndexBuffer(const CGDCBufferLayerItemIdentifier &identifier, UINT32 *pIndex, const UINT &uCount, const PrimitiveTopology &ePrimitiveTopology);
	bool InitDirect3D(const CGDCInitData &initData);
	float AspectRatio(CGDCTargetView *pDCTargetView)const;

	CGDCDirectX11BufferLayer *GetBufferLayer(const CAtlString &strLayerName);
	CGDCDirectX11BufferLayerItem *GetBufferLayerItem(const CGDCBufferLayerItemIdentifier &identifier, const bool &bCreateIfNone=false);
	
private:
	
	bool mEnable4xMsaa;
	UINT32 m4xMsaaQuality;
	ID3D11Device* md3dDevice;
	ID3D11DeviceContext* md3dImmediateContext;
	CAtlMap<CAtlString, CGDCDirectX11BufferLayer*> mBufferLayer;
	bool m_bDynamicVertexBuffer;


	// material
	CGDCDirectX11MaterialManager m_materialManager;
	Effects *mEffects;
	InputLayouts *mInputLayouts;

	// light
	CGDCDirectX11LightManager m_lightManager;

	
public:
	CGDCDirectX11();
	virtual ~CGDCDirectX11();
};

