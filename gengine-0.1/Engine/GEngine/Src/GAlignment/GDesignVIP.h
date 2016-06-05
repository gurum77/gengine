#pragma once

/**
	@brief
		- ��ȹ�� VIP
		- ���ݰ� VIP�� ��� ���� �߰��� ������.
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

