#pragma once
/**
	@brief
		- Áö¹Ý°í VIP
*/
class G_EXT_CLASS CGGroundVIP
{
public:
	void SetStation(const double &dStation);
	const double &GetStation() const;

	void SetEL(const double &dEL);
	const double &GetEL() const;

private:
	double m_dStation;
	double m_dEL;

public:
	GDEFINE_OPERATOR_COPY(CGGroundVIP);
	GDEFINE_OPERATOR_EQUAL(CGGroundVIP);
	CGGroundVIP();
	CGGroundVIP(const CGGroundVIP &d);
	~CGGroundVIP();
};

