#pragma once
/**
	@brief
		- 편경사에 대한 정보를 담고 있는 클래스이다.
		- 좌우 편경사 정보를 포함하고 있다.
*/
class G_EXT_CLASS CGSuperelevation
{
public:
	void SetSlope(const CGSuperelevationSlope &slope, const bool &bLeft);
	CGSuperelevationSlope &GetSlope(const bool &bLeft);

private:
	CGSuperelevationSlope m_slope[2];

public:
	GDEFINE_OPERATOR_COPY(CGSuperelevation);
	GDEFINE_OPERATOR_EQUAL(CGSuperelevation);
	CGSuperelevation(void);
	CGSuperelevation(const CGSuperelevation &d);
	~CGSuperelevation(void);
};

