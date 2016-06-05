#pragma once

#define GDEFAULT_COLOR_TEXTURE GNOTRANS("WHITE")

class G_EXT_CLASS CGTextureManager
{
public:
	bool AddTexture(const CAtlString &strTextureName, const CAtlString &strImagePathFileName);
	CGTextureItem *FindTextureByName(const CAtlString &strTextureName);
	const CGTextureItem *FindTextureByName(const CAtlString &strTextureName) const;
	void InitAllTexture();
	void DeleteTextureByName(const CAtlString &strTextureName);
	const CAtlMap<CAtlString, CGTextureItem*> &GetMap() const;

private:
	CAtlMap<CAtlString, CGTextureItem*> m_mapItem;

public:
	CGTextureManager();
	~CGTextureManager();
};

