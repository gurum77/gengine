#pragma once

/**
	@brief
		- directx11�� material item
*/
class G_EXT_CLASS CGDCDirectX11MaterialItem
{
public:
	void CopyGFLOAT4ToXMFLOAT4(const gfloat4 &from, OUT XMFLOAT4 &to);
	void SetByCGMaterialItem(const CGMaterialItem &item);
	void SetTextureName(const CAtlString &strTextureName);
	const CAtlString &GetTextureName() const;

	Material &GetMaterial();
	
private:
	CAtlString m_strTextureName;
	Material m_material;	// texture�� ������ �����̴�.

public:

	CGDCDirectX11MaterialItem(void);
	~CGDCDirectX11MaterialItem(void);
};

