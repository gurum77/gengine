#pragma once

/**
	@brief
		- The function to calculate about any curve.
			- clothoid, arc, circle etc...
*/
class G_EXT_CLASS CGToolCurve
{
public:
	static bool CalcPosOnArc(const CGPoint2D &ptStart, const CGVector2D &vStartDir, const double &dR, const double &dLength, const bool &bCCW, GOUT CGPoint2D &ptEnd, GOUT CGVector2D &vEndDir);
	static bool CalcPosOnClothoid(const CGPoint2D &ptStart, const CGVector2D &vStartDir, const double &dR, const double &dA, const bool &bCCW, GOUT CGPoint2D &ptEnd, GOUT CGVector2D &vEndDir);
	static bool CalcPosOnClothoidA2(const CGPoint2D &ptStart, const CGVector2D &vStartDir, const double &dR, const double &dA, const bool &bCCW, GOUT CGPoint2D &ptEnd, GOUT CGVector2D &vEndDir);
	static bool CalcPosOnOvalnessClothoid(const CGPoint2D &ptStart, const CGVector2D &vStartDir, const double &dR1 , const double &dA, const double &dR2, const bool &bCCW, GOUT CGPoint2D &ptEnd, GOUT CGVector2D &vEndDir);
	static double CalcClothoidLength(const double &dA, const double &dR);
	static double CalcArcLength(const double &dA, const double &dR);
	static double CalcClothoidRadius(const double &dA, const double &dLength);
	static bool CalcPosOnClothoidBase(const double &dA, const double &dL, GOUT CGPoint2D &pt);
public:
	CGToolCurve(void);
	~CGToolCurve(void);
};

