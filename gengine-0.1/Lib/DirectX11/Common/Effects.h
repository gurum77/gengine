//***************************************************************************************
// Effects.h by Frank Luna (C) 2011 All Rights Reserved.
//
// Defines lightweight effect wrappers to group an effect and its variables.
// Also defines a static Effects class from which we can access all of our effects.
//***************************************************************************************

#ifndef EFFECTS_H
#define EFFECTS_H

#include "d3dUtil.h"
#include "atlstr.h"
#pragma region Effect
class Effect
{
public:
	Effect(ID3D11Device* device, const std::wstring& filename);
	virtual ~Effect();

private:
	Effect(const Effect& rhs);
	Effect& operator=(const Effect& rhs);

protected:
	ID3DX11Effect* mFX;
};
#pragma endregion

#pragma region BasicEffect
class LightTexEffect : public Effect
{
public:
	LightTexEffect(ID3D11Device* device, const std::wstring& filename);
	~LightTexEffect();

	void SetWorldViewProj(CXMMATRIX M)                  { if (!WorldViewProj) return; WorldViewProj->SetMatrix(reinterpret_cast<const float*>(&M)); }
	void SetWorld(CXMMATRIX M)                          { if (!World) return; World->SetMatrix(reinterpret_cast<const float*>(&M)); }
	void SetWorldInvTranspose(CXMMATRIX M)              { if (!WorldInvTranspose) return; WorldInvTranspose->SetMatrix(reinterpret_cast<const float*>(&M)); }
	void SetTexTransform(CXMMATRIX M)                   { if (!TexTransform) return; TexTransform->SetMatrix(reinterpret_cast<const float*>(&M)); }
	void SetEyePosW(const XMFLOAT3& v)                  { if (!EyePosW) return; EyePosW->SetRawValue(&v, 0, sizeof(XMFLOAT3)); }
	
	void SetEnableFog(bool b)                           { if (!EnableFog) return; EnableFog->SetBool(b); }
	void SetFogStart(float f)                           { if (!FogStart) return; FogStart->SetFloat(f); }
	void SetFogRange(float f)                           { if (!FogRange) return; FogRange->SetFloat(f); }
	void SetFogColor(const FXMVECTOR v)                 { if (!FogColor) return; FogColor->SetFloatVector(reinterpret_cast<const float*>(&v)); }

	void SetEnableDirLights(const XMFLOAT3& v)			{ if (!EnableDirLights) return; EnableDirLights->SetRawValue(&v, 0, sizeof(XMFLOAT3)); }
	void SetDirLights(const DirectionalLight* lights)   { if (!DirLights) return; DirLights->SetRawValue(lights, 0, 3 * sizeof(DirectionalLight)); }
	
	void SetEnablePointLights(const XMFLOAT3& v)		{ if (!EnablePointLights) return; EnablePointLights->SetRawValue(&v, 0, sizeof(XMFLOAT3)); }
	void SetPointLights(const PointLight* lights)		{ if (!PointLights) return; PointLights->SetRawValue(lights, 0, 3 * sizeof(PointLight)); }
	
	void SetEnableSpotLights(const XMFLOAT3& v)			{ if (!EnableSpotLights) return; EnableSpotLights->SetRawValue(&v, 0, sizeof(XMFLOAT3)); }
	void SetSpotLights(const SpotLight* lights)			{ if (!SpotLights) return; SpotLights->SetRawValue(lights, 0, 3 * sizeof(SpotLight)); }
	
	void SetMaterial(const Material& mat)               { if (!Mat) return; Mat->SetRawValue(&mat, 0, sizeof(Material)); }
	void SetDiffuseMap(ID3D11ShaderResourceView* tex)   { if (!DiffuseMap) return; DiffuseMap->SetResource(tex); }

	ID3DX11EffectTechnique* LightTexTech;
	
	ID3DX11EffectMatrixVariable* WorldViewProj;
	ID3DX11EffectMatrixVariable* World;
	ID3DX11EffectMatrixVariable* WorldInvTranspose;
	ID3DX11EffectMatrixVariable* TexTransform;
	ID3DX11EffectVectorVariable* EyePosW;

	ID3DX11EffectScalarVariable* EnableFog;
	ID3DX11EffectScalarVariable* FogStart;
	ID3DX11EffectScalarVariable* FogRange;
	ID3DX11EffectVectorVariable* FogColor;

	ID3DX11EffectVectorVariable* EnableDirLights;
	ID3DX11EffectVariable* DirLights;
	ID3DX11EffectVectorVariable* EnablePointLights;
	ID3DX11EffectVariable* PointLights;
	ID3DX11EffectVectorVariable* EnableSpotLights;
	ID3DX11EffectVariable* SpotLights;
	ID3DX11EffectVariable* Mat;

	ID3DX11EffectShaderResourceVariable* DiffuseMap;
};
#pragma endregion

#pragma region ColorEffect
class ColorEffect : public Effect
{
public:
	ColorEffect(ID3D11Device* device, const std::wstring& filename);
	~ColorEffect();

	void SetWorldViewProj(CXMMATRIX M)                  { if (!WorldViewProj) return; WorldViewProj->SetMatrix(reinterpret_cast<const float*>(&M)); }

	ID3DX11EffectTechnique* ColorTech;

	ID3DX11EffectMatrixVariable* WorldViewProj;
};
#pragma endregion

#pragma region Effects
class Effects
{
public:
	void InitAll(ID3D11Device* device);
	void DestroyAll();
	CAtlString GetExtPath();

	LightTexEffect* LightTexFX;
	ColorEffect* ColorFX;

};
#pragma endregion

#endif // EFFECTS_H