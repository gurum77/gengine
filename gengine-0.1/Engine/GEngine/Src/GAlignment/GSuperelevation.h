#pragma once
/**
	@brief
		- ���翡 ���� ������ ��� �ִ� Ŭ�����̴�.
		- �¿� ���� ������ �����ϰ� �ִ�.
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

