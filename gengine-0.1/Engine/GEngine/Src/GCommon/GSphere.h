#pragma once
class G_EXT_CLASS CGSphere
{
public:
	void SetCenterPos(const CGPoint3D &pt);
	const CGPoint3D &GetCenterPos() const;

	void SetRadius(const float &fRadius);
	const float &GetRadius() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CGPoint3D m_ptCenterPos;
	float m_fRadius;
	
public:
	GDEFINE_OPERATOR_COPY(CGSphere);
	CGSphere();
	~CGSphere();
};

