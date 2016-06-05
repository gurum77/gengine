#pragma once

/**
	@brief
		- material manager
*/
class G_EXT_CLASS CGMaterialManager
{
public:
	bool AddMaterial(const CAtlString &strMaterialName);
	bool AddColorMaterial(const CAtlString &strMaterialName, const CGColor &color);
	CGMaterialItem *FindMaterialByName(const CAtlString &strMaterialName);
	const CGMaterialItem *FindMaterialByName(const CAtlString &strMaterialName) const;
	void InitAllMaterial();
	void DeleteMaterialByName(const CAtlString &strMaterialName);
	const CAtlMap<CAtlString, CGMaterialItem*> &GetMap() const;

	CGTextureManager &GetTextureManager();
	const CGTextureManager &GetTextureManager() const;

	CGTextureCoordManager &GetTextureCoordManager();

private:
	CAtlMap<CAtlString, CGMaterialItem*> m_mapMaterialWithName;

	CGTextureManager m_textureManager;
	CGTextureCoordManager m_textureCoordManager;

public:
	CGMaterialManager(void);
	~CGMaterialManager(void);
};

