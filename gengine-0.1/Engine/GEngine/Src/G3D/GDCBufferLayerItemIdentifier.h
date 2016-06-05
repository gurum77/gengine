#pragma once

/**
	@brief
		- bufferlayer item ½Äº°ÀÚ
*/
class CGDCBufferLayerItemIdentifier
{
public:
	void SetBufferLayerName(const CAtlString &strBufferLayerName);
	const CAtlString &GetBufferLayerName() const;

	void SetBufferLayerItemID(const GID &ID);
	const GID GetBufferLayerItemID() const;

	void SetMaterialName(const CAtlString &strMaterialName);
	const CAtlString &GetMaterialName() const;

	void SetMaterial(const CGMaterialItem &material);
	const CGMaterialItem &GetMaterial() const;

	void SetTexture(const CGTextureItem &texture);
	const CGTextureItem &GetTexture() const;

	void SetByObject(const CAtlString &strBufferLayerName, const CGObjectBase &object);
	bool IsMatchWithObject(const CGObjectBase &object) const;

	bool IsExistMaterial() const;

private:
	CAtlString m_strBufferLayerName;
	GID m_bufferLayerItemID;

	// material
	CAtlString m_strMaterialName;
	CGMaterialItem m_material;
	CGTextureItem m_texture;
		
public:
	GDEFINE_OPERATOR_COPY(CGDCBufferLayerItemIdentifier);
	CGDCBufferLayerItemIdentifier(const CGDCBufferLayerItemIdentifier &d);
	CGDCBufferLayerItemIdentifier(void);
	~CGDCBufferLayerItemIdentifier(void);
};

