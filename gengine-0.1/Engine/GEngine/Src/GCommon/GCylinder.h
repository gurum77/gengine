#pragma once
/**
	@brief
		- cylinder ����Ÿ
*/
class G_EXT_CLASS CGCylinder
{

public:
	void SetPos(const CGPoint3D &pt, const bool &bStt);
	const CGPoint3D &GetPos(const bool &bStt) const;

	void SetRadius(const float &fRadius, const bool &bStt);
	const float &GetRadius(const bool &bStt) const;

	double GetHeight() const;
	CGVector3D GetVector() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CGPoint3D m_ptPos[2];
	float m_fRadius[2];

public:
	GDEFINE_OPERATOR_COPY(CGCylinder);
	CGCylinder();
	~CGCylinder();
};

