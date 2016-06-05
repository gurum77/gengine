#pragma once

/**
	@brief
		- polyline2D µ•¿Ã≈∏
*/
class G_EXT_CLASS CGPolyline2D
{
public:
	void SetPointByRectangle(const CGRect &rc);
	void SetPoint(const CAtlArray<CGPoint2D> &arrPoint);
	const CAtlArray<CGPoint2D> &GetPoint() const;
	CAtlArray<CGPoint2D> &GetPoint();

	void SetEL(const float &fEL);
	const float &GetEL() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CAtlArray<CGPoint2D> m_arrPoint;
	float m_fEL;

public:
	GDEFINE_OPERATOR_COPY(CGPolyline2D);
	CGPolyline2D();
	~CGPolyline2D();
};

