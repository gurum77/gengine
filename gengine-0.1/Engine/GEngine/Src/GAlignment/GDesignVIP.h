#pragma once

/**
	@brief
		- 계획고 VIP
		- 지반고 VIP에 종곡선 값을 추가로 가진다.
*/
class G_EXT_CLASS CGDesignVIP : public CGGroundVIP
{
public:
	void SetParameter(const double &dParameter);
	const double &GetParameter() const;

private:
	double m_dParameter;

public:
	GDEFINE_OPERATOR_COPY(CGDesignVIP);
	GDEFINE_OPERATOR_EQUAL(CGDesignVIP);

	CGDesignVIP();
	CGDesignVIP(const CGDesignVIP &d);
	~CGDesignVIP();
};

