#pragma once

/**
	@brief
		- 평면선형의 한 점에 대한 정보
*/
class G_EXT_CLASS CGHorizontalAlignmentPoint : public CGPoint2D
{
public:
	void SetStation(const double &dStation);
	const double &GetStation() const;

	void SetDir(const CGVector2D &vDir);
	const CGVector2D &GetDir() const;

private:
	double m_dStation;
	CGVector2D m_vDir;

public:
	GDEFINE_OPERATOR_COPY(CGHorizontalAlignmentPoint)
	CGHorizontalAlignmentPoint(void);
	CGHorizontalAlignmentPoint(const CGHorizontalAlignmentPoint &d);
	~CGHorizontalAlignmentPoint(void);
};

