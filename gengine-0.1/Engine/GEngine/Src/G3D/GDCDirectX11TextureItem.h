#pragma once

// direct define warning ����
// todo : ���� �ʾƵ� warning�� ���� �ʵ��� �����ؾ���.
#pragma warning(disable:4005)

#include "../../../../lib/DirectX11/Common/LightHelper.h"

struct ID3D11ShaderResourceView;
/**
	@brief
		- directx11 dc�� texture item
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

