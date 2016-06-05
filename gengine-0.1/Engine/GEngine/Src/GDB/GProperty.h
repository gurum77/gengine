#pragma once
/**
	@brief
		- 객체의 속성을 가진다.
*/
class G_EXT_CLASS CGProperty
{
private:
	GID m_ID;
	CAtlString m_strName;
	CGColor m_color;
	float m_fAlpha;
	CAtlString m_strMaterialName;

public:
	void SetID(const GID &ID);
	const GID &GetID() const;

	void SetName(const CAtlString &strName);
	const CAtlString &GetName() const;

	void SetColor(const CGColor &color);
	const CGColor &GetColor() const;

	void SetAlpha(const float &fAlpha);
	const float &GetAlpha() const;

	void SetMaterialName(const CAtlString &strTextureName);
	const CAtlString &GetMaterialName() const;

	CAtlString GetStrProperty() const;
	
public:
	GDEFINE_OPERATOR_COPY(CGProperty);

	CGProperty(const CGProperty &d);
	CGProperty();
	~CGProperty();
};

