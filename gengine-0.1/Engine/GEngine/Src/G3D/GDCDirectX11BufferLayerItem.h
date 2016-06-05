#pragma once
// direct define warning ����
// todo : ���� �ʾƵ� warning�� ���� �ʵ��� �����ؾ���.
#pragma warning(disable:4005)

#include <d3dx11.h>
#include "../../../../Lib/DirectX11/Effects11/Inc/d3dx11effect.h"
#include <dxerr.h>
#include "xnamath.h"
#include "atltypes.h"
/**
	@brief
		- buffer layer�� item
*/
class G_EXT_CLASS CGDCDirectX11BufferLayerItem
{
public:
	void InitIndexBuffer(const PrimitiveTopology &ePrimitiveTopology);
	void InitVertexBuffer(const PrimitiveTopology &ePrimitiveTopology);
	CGDCDirectX11BufferLayerItem *FindItemByMaterialName(const CAtlString &strMaterialName, const bool &bCreateIfNone);
	CGDCDirectX11BufferLayerItem *AddItemWithMaterial(const CAtlString &strMaterialName);
	
	GID m_ID;
	ID3D11Buffer *mVertexBuffer[ePrimitiveTopologyCount];	// vertex buffer
	ID3D11Buffer *mIndexBuffer[ePrimitiveTopologyCount];	// index buffer
	UINT m_uCountPrimitiveVertex[ePrimitiveTopologyCount];
	UINT m_uCountPrimitiveIndex[ePrimitiveTopologyCount];
	CAtlMap<CAtlString, CGDCDirectX11BufferLayerItem*> m_mapItemWithMaterial;

	CGDCDirectX11BufferLayerItem(void);
	~CGDCDirectX11BufferLayerItem(void);
};

