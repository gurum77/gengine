#pragma once
/**
	@brief
		- font �Ӽ�
*/
class G_EXT_CLASS CGFontProperty
{
public:
	enum Align
	{
		eAlignLeft,	// ����
		eAlignMiddle,	// �߽�
		eAlignRight,	// ������
		eAlignCenter,	// �߰�
		eAlignRightTop	// ���� ������
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

