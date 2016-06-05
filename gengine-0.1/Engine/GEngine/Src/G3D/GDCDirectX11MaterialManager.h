#pragma once
#include <d3dx11.h>

class Effects;
/**
	@brief
		- directx11의 material을 관리한다.
*/
class G_EXT_CLASS CGDCDirectX11MaterialManager
{
public:
	void Init(ID3D11Device* device);
	void ApplyMaterialToEffect(const CGDCBufferLayerItemIdentifier &identifier, Effects *mEffects);

	CGDCDirectX11MaterialItem *AddMaterial(const CAtlString &strMaterialName);
	CGDCDirectX11MaterialItem *FindMaterialByName(const CAtlString &strMaterialName);
	void InitAllMaterial();

	ID3D11ShaderResourceView *FindTextureSRVByName(const CAtlString &strMaterialName);
	CGDCDirectX11TextureItem *FindTextureItemByName(const CAtlString &strMaterialName);

	CGDCDirectX11TextureManager &GetTextureManager();

private:
	CGDCDirectX11TextureManager m_textureManager;
	CAtlMap<CAtlString, CGDCDirectX11MaterialItem*> m_mapMaterialWithName;

public:
	CGDCDirectX11MaterialManager(void);
	~CGDCDirectX11MaterialManager(void);
};

