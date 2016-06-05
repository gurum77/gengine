#pragma once
/**
	@brief
		- material item
*/
class G_EXT_CLASS CGMaterialItem
{
public:
	void SetTextureName(const CAtlString &strTextureName);
	const CAtlString &GetTextureName() const;

	void SetAmbient(const gfloat4 &f4Ambient);
	const gfloat4 &GetAmbient() const;
	
	void SetDiffuse(const gfloat4 &f4Diffuse);
	const gfloat4 &GetDiffuse() const;

	void SetSpecular(const gfloat4 &f4Specular);
	const gfloat4 &GetSpecular() const;

	void SetReflect(const gfloat4 &f4Reflect);
	const gfloat4 &GetReflect() const;

private:
	CAtlString m_strTextureName;
	gfloat4 m_f4Ambient;
	gfloat4 m_f4Diffuse;
	gfloat4 m_f4Specular;
	gfloat4 m_f4Reflect;

public:
	GDEFINE_OPERATOR_COPY(CGMaterialItem);
	
	CGMaterialItem(void);
	~CGMaterialItem(void);
};

