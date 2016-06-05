#pragma once

/**
	@brief
		- directx11ÀÇ light manager
*/
class G_EXT_CLASS CGDCDirectX11LightManager
{
public:
	void SetByCGLightManager(const CGLightManager &mng);
	void ApplyLightToEffect(Effects *mEffects);
private:
	void SetXMFLOAT4fromgfloat4(XMFLOAT4 &to, const gfloat4 &from);
	void SetXMFLOAT3fromgfloat3(XMFLOAT3 &to, const gfloat3 &from);

	// light
	XMFLOAT3 mEnableDirLights;
	DirectionalLight mDirLights[3];

	XMFLOAT3 mEnablePointLights;
	PointLight mPointLights[3];

	XMFLOAT3 mEnableSpotLights;
	SpotLight mSpotLights[3];

public:
	CGDCDirectX11LightManager();
	~CGDCDirectX11LightManager();
};

