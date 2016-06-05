#pragma once
/**
	@brief
		- light manager
*/
class G_EXT_CLASS CGLightManager
{
public:
	enum LightNum
	{
		eLightNum1,
		eLightNum2,
		eLightNum3,
		eLightNumCount
	};

	void SetPointLight(const CGPointLight &pointLight, const LightNum &eLightNum);
	const CGPointLight &GetPointLight(const LightNum &eLightNum) const;

	void SetSpotLight(const CGSpotLight &spotLight, const LightNum &eLightNum);
	const CGSpotLight &GetSpotLight(const LightNum &eLightNum) const;

	void SetDirectionalLight(const CGDirectionalLight &dirLight, const LightNum &eLightNum);
	const CGDirectionalLight &GetDirectionalLight(const LightNum &eLightNum) const;


private:
	CGPointLight m_pointLight[3];
	CGSpotLight m_spotLight[3];
	CGDirectionalLight m_dirLight[3];

public:
	CGLightManager();
	~CGLightManager();
};

