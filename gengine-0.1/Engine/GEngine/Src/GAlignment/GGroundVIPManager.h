#pragma once
class CGGroundVIPManager
{
public:
	void AddGroundVIP(CGGroundVIP &vip);
	INT32 GetGroundVIPCount() const;
	CGGroundVIP *GetGroundVIP(const INT32 &iIdx);
	void InitGroundVIP();

private:
	CAtlArray<CGGroundVIP> m_arrVIP;

public:
	GDEFINE_OPERATOR_EQUAL(CGGroundVIPManager);
	GDEFINE_OPERATOR_COPY(CGGroundVIPManager);
	CGGroundVIPManager();
	~CGGroundVIPManager();
};

