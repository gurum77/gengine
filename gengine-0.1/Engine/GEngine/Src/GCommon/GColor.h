#pragma once

/**
	@brief
		- color를 가지는 클래스
*/
class G_EXT_CLASS CGColor
{
public:
	void SetRGB(const gfloat3 &f3RGB);
	const gfloat3 &GetRGB() const;

	void SetACADColorIndex(const INT32 &iIdx);

	COLORREF FindRGBFromACADColorIndex(const INT32 &iIdx);
private:
	gfloat3 m_f3RGB;

public:
	GDEFINE_OPERATOR_COPY(CGColor);
	GDEFINE_OPERATOR_EQUAL(CGColor);
	CGColor(const float &fR, const float &fG, const float &fB);
	CGColor(const gfloat3 &f3RGB);
	CGColor(const COLORREF &rgb);
	CGColor();
	~CGColor();
};

