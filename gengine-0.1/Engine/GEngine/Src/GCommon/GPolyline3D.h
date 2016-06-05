#pragma once
/**
	@brief
		- polyline 3D 
*/
class G_EXT_CLASS CGPolyline3D
{
public:
	void SetPoint(const CAtlArray<CGPoint3D> &arrPoint);
	const CAtlArray<CGPoint3D> &GetPoint() const;
	INT32 GetCountPoint() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CAtlArray<CGPoint3D> m_arrPoint;

public:
	GDEFINE_OPERATOR_COPY(CGPolyline3D);

public:
	CGPolyline3D(const CGPolyline3D &d);
	CGPolyline3D(void);
	~CGPolyline3D(void);
};

// CGPolygon3D와 CGPolygon 완전히 동일하지만 코드상에서 사용 목적을 명시할 수 있도록 하기 위해 아래처럼 형을 정의한다.
typedef CGPolyline3D CGPolygon;
typedef CGPolyline3D CGFace;
