#pragma once

/**
	@brief
		- ������ ��簪 1��
*/
class G_EXT_CLASS CGSuperelevationSlopeItem
{
public:
	void SetStation(const double &dStation);
	const double &GetStation() const;

	void SetSlope(const double &dSlope);
	const double &GetSlope() const;
	
private:
	double m_dStation;
	double m_dSlope;

public:
	GDEFINE_OPERATOR_COPY(CGSuperelevationSlopeItem);
	GDEFINE_OPERATOR_EQUAL(CGSuperelevationSlopeItem);
	CGSuperelevationSlopeItem(void);
	CGSuperelevationSlopeItem(const CGSuperelevationSlopeItem &d);
	~CGSuperelevationSlopeItem(void);
};

