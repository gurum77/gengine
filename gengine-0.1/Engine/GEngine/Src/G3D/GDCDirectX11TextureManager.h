#pragma once

// direct define warning 꺼둠
// todo : 끄지 않아도 warning이 뜨지 않도록 수정해야함.
#pragma warning(disable:4005)

#include <d3dx11.h>
#include "../../../../Lib/DirectX11/Effects11/Inc/d3dx11effect.h"
#include "../../../../lib/DirectX11/Common/LightHelper.h"
#include <dxerr.h>
#include "xnamath.h"
#include "atltypes.h"

/**
	@brief
		- DirectX11용 Texture를 관리자.
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

