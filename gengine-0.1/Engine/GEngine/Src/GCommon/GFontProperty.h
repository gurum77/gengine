#pragma once
/**
	@brief
		- font 속성
*/
class G_EXT_CLASS CGFontProperty
{
public:
	enum Align
	{
		eAlignLeft,	// 왼쪽
		eAlignMiddle,	// 중심
		eAlignRight,	// 오른쪽
		eAlignCenter,	// 중간
		eAlignRightTop	// 맨위 오른쪽
	};
	void SetFontName(const CAtlString &strFontName);
	const CAtlString &GetFontName() const;

	void SetFontHeight(const float &fFontHeight);
	const float &GetFontHeight() const;

	void SetAlign(const CGFontProperty::Align &eAlign);
	const CGFontProperty::Align &GetAlign() const;

private:
	CAtlString m_strFontName;
	float m_fFontHeight;
	Align m_eAlign;

public:
	GDEFINE_OPERATOR_COPY(CGFontProperty);
	CGFontProperty(void);
	virtual ~CGFontProperty(void);
};

