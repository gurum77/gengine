#pragma once

/**
	@brief
		- 안개 설정값
*/
class G_EXT_CLASS CGFog
{
public:
	void SetEnable(const bool &bEnable);
	const bool &GetEnable() const;

	void SetStart(const float &fStart);
	const float &GetStart() const;
		
	void SetRange(const float &fRange);
	const float &GetRange() const;

	void SetColor(const CGColor &color);
	const CGColor &GetColor() const;

private:
	bool m_bEnable;
	float m_fStart;
	float m_fRange;
	CGColor m_color;

public:
	GDEFINE_OPERATOR_COPY(CGFog);
	CGFog(void);
	~CGFog(void);
};

