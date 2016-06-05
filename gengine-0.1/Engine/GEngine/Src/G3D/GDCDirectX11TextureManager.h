#pragma once

// direct define warning ����
// todo : ���� �ʾƵ� warning�� ���� �ʵ��� �����ؾ���.
#pragma warning(disable:4005)

#include <d3dx11.h>
#include "../../../../Lib/DirectX11/Effects11/Inc/d3dx11effect.h"
#include "../../../../lib/DirectX11/Common/LightHelper.h"
#include <dxerr.h>
#include "xnamath.h"
#include "atltypes.h"

/**
	@brief
		- DirectX11�� Texture�� ������.
*/
class G_EXT_CLASS CGDCDirectX11TextureManager
{
public:
	void Init(ID3D11Device *d3dDevice);
	
	void AddTexture(const CAtlString &strTextureName, const CAtlString &strImagePathFileName);
	CGDCDirectX11TextureItem *FindTextureByName(const CAtlString &strTextureName);
	void InitAlltexture();

private:
	ID3D11Device* md3dDevice;
	CAtlMap<CAtlString, CGDCDirectX11TextureItem*> m_mapTextureWithName;
	

public:
	CGDCDirectX11TextureManager(void);
	~CGDCDirectX11TextureManager(void);
};

