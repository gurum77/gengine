#pragma once
class G_EXT_CLASS CGObjectParser_OLYMPIC_FLAG
{
public:
	void ParseObject(const CGObjectProxy &object);
	void WriteObject(GOUT CGObjectProxy &object);

	void SetCenterPos(const CGPoint2D &ptCenter);
	const CGPoint2D &GetCenterPos() const;

	void SetRadius(const double &dRadius);
	const double &GetRadius() const;

private:
	CGPoint2D m_ptCenterPos;
	double m_dRadius;

public:
	CGObjectParser_OLYMPIC_FLAG(void);
	~CGObjectParser_OLYMPIC_FLAG(void);
};

