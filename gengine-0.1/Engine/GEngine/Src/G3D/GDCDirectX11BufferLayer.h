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
		- Directx11�� buffer layer(vertex buffer, index buffer(todo))
		- vertex buffer�� ���� ����� ����� ũ�� ������ ���� ����Ǵ� buffer�� ������ ������ �� �ֵ��� �ϱ� ���� �����̴�.
*/
class G_EXT_CLASS CGDCDirectX11BufferLayer
{
public:
	void SetName(const CAtlString &strName);
	const CAtlString &GetName() const;

	void InitItem();
	void AddItem(CGDCDirectX11BufferLayerItem *pItem);
	CGDCDirectX11BufferLayerItem *FindItemByID(const GID &ID);
	CGDCDirectX11BufferLayerItem *FindItemByIdentifier(const CGDCBufferLayerItemIdentifier &identifier, const bool &bCreateIfNone=false);
	const CAtlMap<GID, CGDCDirectX11BufferLayerItem*> &GetMap() const;
	void GetAllItemIdentifier(GOUT CAtlArray<CGDCBufferLayerItemIdentifier> &arrIdentifier) const;

	void InitIndexBuffer(const PrimitiveTopology &ePrimitiveTopology, const GID &ID = GNONE_ID);
	void InitVertexBuffer(const PrimitiveTopology &ePrimitiveTopology, const GID &ID = GNONE_ID);
	
private:
	INT32 GetBufferLayerItemIdentifierCount() const;
	CAtlString m_strName;
	CAtlMap<GID, CGDCDirectX11BufferLayerItem*> m_mapItem;

public:
	CGDCDirectX11BufferLayer();
	~CGDCDirectX11BufferLayer();
};

