#pragma once
/**
	@brief
		- Database
*/
class G_EXT_CLASS CG3DDB
{
public:
	void AddObject(CGObjectBase *pObject);
	CGObjectManager &GetObjectManager();
	const CGObjectManager &GetObjectManager() const;
	
	CGPropertyManager &GetPropertyManager();

	CGFontManager &GetFontManager();

	CGMaterialManager &GetMaterialManager();
	const CGMaterialManager &GetMaterialManager() const;

	CGLightManager &GetLightManager();
	const CGLightManager &GetLightManager() const;

private:
	CGObjectManager m_objectManager;
	CGPropertyManager m_propertyManager;
	CGFontManager m_fontManager;
	CGMaterialManager m_materialManager;
	CGLightManager m_lightManager;

public:
	CG3DDB();
	~CG3DDB();
};

