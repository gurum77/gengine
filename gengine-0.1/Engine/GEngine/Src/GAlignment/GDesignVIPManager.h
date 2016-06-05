#pragma once

/**
	@brief
		- 계획고 VIP 를 관리한다.
*/
class G_EXT_CLASS CGDesignVIPManager
{
public:
	void DeleteDesignVIP(const INT32 &iIdx);
	void AddDesignVIP(const CGDesignVIP &vip);
	INT32 GetDesignVIPCount() const;
	CGDesignVIP *GetDesignVIP(const INT32 &iIdx);
	CGDesignVIP *GetLastDesignVIP();
	const CGDesignVIP *GetDesignVIP(const INT32 &iIdx) const;
	void InitDesignVIP();

	double CalcDesignELByStation(const double &dStation) const;
	

private:
	INT32 GetRightVipBySta(const double &dStation) const;
	double GetAngVipToVip(const double &dStation) const;
	CAtlArray<CGDesignVIP> m_arrVIP;

public:
	GDEFINE_OPERATOR_EQUAL(CGDesignVIPManager);
	GDEFINE_OPERATOR_COPY(CGDesignVIPManager);
	CGDesignVIPManager();
	~CGDesignVIPManager();
};

