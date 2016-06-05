#pragma once

/**
	@brief
		- Light의 base class
		- Light의 공통속성은 재료를 가진다.
*/
class G_EXT_CLASS CGLightBase
{
public:
	void SetAmbient(const gfloat4 &f4Ambient);
	const gfloat4 &GetAmbient() const;

	void SetDiffuse(const gfloat4 &f4Diffuse);
	const gfloat4 &GetDiffuse() const;

	void SetSpecular(const gfloat4 &f4Specular);
	const gfloat4 &GetSpecular() const;

	void SetPad(const float &fPad);
	const float &GetPad() const;

	void SetEnable(const bool &bEnable);
	const bool &GetEnable() const;

private:
	gfloat4 m_f4Ambient;
	gfloat4 m_f4Diffuse;
	gfloat4 m_f4Specular;
	float m_fPad;
	bool m_bEnable;

public:
	GDEFINE_OPERATOR_COPY(CGLightBase);
	CGLightBase();
	~CGLightBase();
};

/**
	@brief
		- Point Light
*/
class G_EXT_CLASS CGPointLight : public CGLightBase
{
public:
	void SetPos(const gfloat3 &f3Pos);
	const gfloat3 &GetPos() const;

	void SetAtt(const gfloat3 &f3Att);
	const gfloat3 &GetAtt() const;

	void SetRange(const float &fRange);
	const float &GetRange() const;

private:
	gfloat3 m_f3Pos;
	gfloat3 m_f3Att; 
	float m_fRange;


public:
	GDEFINE_OPERATOR_COPY(CGPointLight);
	CGPointLight();
	~CGPointLight();
};


/**
	@brief
		- Spot Light
*/
class G_EXT_CLASS CGSpotLight : public CGLightBase
{
public:
	void SetPos(const gfloat3 &f3Pos);
	const gfloat3 &GetPos() const;


	void SetRange(const float &fRange);
	const float &GetRange() const;

	void SetDir(const gfloat3 &f3Dir);
	const gfloat3 &GetDir() const;

	void SetSpot(const float &fSpot);
	const float &GetSpot() const;

	void SetAtt(const gfloat3 &f3Att);
	const gfloat3 &GetAtt() const;

private:
	gfloat3 m_f3Pos;
	
	float m_fRange;
	gfloat3 m_f3Dir;
	float m_fSpot;

	gfloat3 m_f3Att;

public:
	GDEFINE_OPERATOR_COPY(CGSpotLight);
	CGSpotLight();
	~CGSpotLight();
};


/**
	@brief
		- Directional Light
*/
class G_EXT_CLASS CGDirectionalLight : public CGLightBase
{
public:
	void SetDir(const gfloat3 &f3Dir);
	const gfloat3 &GetDir() const;

private:
	gfloat3 m_f3Dir;

public:
	GDEFINE_OPERATOR_COPY(CGDirectionalLight);
	CGDirectionalLight();
	~CGDirectionalLight();
};