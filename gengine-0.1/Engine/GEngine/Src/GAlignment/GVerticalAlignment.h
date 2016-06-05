#pragma once

/**
	@brief
		- 종단 선형 정보
			- 계획고
			- 지반고
*/
class G_EXT_CLASS CGVerticalAlignment
{
public:
	CGDesignVIPManager &GetDesignVIPManager();
	CGGroundVIPManager &GetGroundVIPManager();

	void SetBasePos(const CGPoint2D &ptBasePos);
	const CGPoint2D &GetBasePos() const;

	void GetDesignVIPParameterPosArray(const CGDesignVIP &vip, GOUT CAtlArray<CGPoint2D> &arrPos);
	void GetDesignVIPPosArray(GOUT CAtlArray<CGPoint2D> &arrPos);
	void GetGroundVIPPosArray(GOUT CAtlArray<CGPoint2D> &arrPos);

	CGPoint2D CalcPosByStationAndEL(const double &dStation, const double &dEL);
	double CalcStationByPos(const CGPoint2D &ptPos);
	double CalcELByPos(const CGPoint2D &ptPos);
	
	const double CalcMinMaxEL(const bool &bMax) const;
	const double GetFirstDesignEL() const;
	const double GetFirstDesignStation() const;
	
private:
	CGPoint2D m_ptBasePos;
	CGDesignVIPManager m_designVIPManager;
	CGGroundVIPManager m_groundVIPManager;

public:
	GDEFINE_OPERATOR_COPY(CGVerticalAlignment);
	GDEFINE_OPERATOR_EQUAL(CGVerticalAlignment);
	CGVerticalAlignment();
	~CGVerticalAlignment();
};

