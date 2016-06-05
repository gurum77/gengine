#pragma once
/**
	@brief
		- 3D Circle
*/
class G_EXT_CLASS CGCircle3D
{
public:
	void SetCenterPos(const CGPoint3D &pt);
	const CGPoint3D &GetCenterPos() const;

	void SetRadius(const float &fRadius);
	const float &GetRadius() const;

	void SetNormal(const CGVector3D &vNormal);
	const CGVector3D &GetNormal() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CGPoint3D m_ptCenterPos;
	float m_fRadius;
	CGVector3D m_vNormal;

public:
	GDEFINE_OPERATOR_COPY(CGCircle3D);
	CGCircle3D();
	~CGCircle3D();
};

