#pragma once

// direct define warning 꺼둠
// todo : 끄지 않아도 warning이 뜨지 않도록 수정해야함.
#pragma warning(disable:4005)

#include "../../../../lib/DirectX11/Common/LightHelper.h"

struct ID3D11ShaderResourceView;
/**
	@brief
		- directx11 dc의 texture item
*/
class G_EXT_CLASS CGDCDirectX11TextureItem
{
public:
	ID3D11ShaderResourceView *GetTextureSRV();
	void SetTextureSRV(ID3D11ShaderResourceView *pTextureSRV);
	XMFLOAT4X4 &GetTextureTransform();
private:
	XMFLOAT4X4 m_textureTransform;
	ID3D11ShaderResourceView *m_pTextureSRV;

public:
	CGDCDirectX11TextureItem(void);
	~CGDCDirectX11TextureItem(void);
};

