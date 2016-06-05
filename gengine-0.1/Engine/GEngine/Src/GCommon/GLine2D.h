#pragma once
/**
	@brief
		- 2d line °´Ã¼
*/
class G_EXT_CLASS CGLine2D
{
public:
	void SetPoint(const CGPoint2D &pt1, const CGPoint2D &pt2);
	void SetPoint(const CGPoint2D &pt, const bool &bStt);
	const CGPoint2D &GetPoint(const bool &bStt) const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CGPoint2D m_pt[2];

public:
	GDEFINE_OPERATOR_COPY(CGLine2D);
	CGLine2D();
	~CGLine2D();
};

