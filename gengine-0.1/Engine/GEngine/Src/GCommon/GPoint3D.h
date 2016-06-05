#pragma once



/**
	@brief
		- 3차원 좌표
*/
class G_EXT_CLASS CGPoint3D :
	public CGPoint2D
{
public:
	const double &GetZ() const;
	const float GetZf() const;
	void SetZ(const double &dZ);

	void SetPointByXYZ(const double &dX, const double &dY, const double &dZ);

	virtual gfloat3 GetFloat3() const;
	void SetPointByFloat3(const gfloat3 &f3);

	CGPoint3D operator-() const;
	CGPoint3D operator +(const CGPoint3D& s) const;
	CGPoint3D& operator +=(const CGPoint3D& s);
	CGPoint3D operator -(const CGPoint3D& s) const;
	CGPoint3D& operator -=(const CGPoint3D& s);
	CGPoint3D operator *(double d) const;
	CGPoint3D& operator *=(double d);
	CGPoint3D operator /(double d) const;
	CGPoint3D& operator /=(double d);
	CGPoint3D operator *(const CGPoint3D &s) const;
	double operator ^(const CGPoint3D &s) const;
	double operator ~() const;
	BOOL operator ==(const CGPoint3D& s) const;	
	BOOL operator !=(const CGPoint3D& s) const;
	CGPoint3D Unit() const;
	bool Rotate(const CGPoint3D &ptBase, const CGPoint3D &vAxis, const CGPoint2D &ptAngle);
	void Scale(const CGPoint3D &ptBase, const double &dScale);
private:
	double m_dZ;

public:
	GDEFINE_OPERATOR_COPY(CGPoint3D);

	CGPoint3D(const CGPoint3D& s);
	CGPoint3D(const CGPoint2D& s);
	CGPoint3D(const double &dX, const double &dY, const double &dZ);
	CGPoint3D();
	~CGPoint3D();
};

// CGVector3D와  CGPoint3D 는 완전히 동일하지만 코드상에서 사용 목적을 명시할 수 있도록 하기 위해 아래처럼 형을 정의한다.
typedef CGPoint3D CGVector3D;


/**
	@brief
		- 평면을 정의한다.
		- 평면의 좌표와 법선벡터를 가진다.
*/
class G_EXT_CLASS CGPlane
{
public:
	void SetDist(const double &dDist);
	const double &GetDist() const;
	
	void SetNormal(const CGVector3D &vNormal);
	const CGVector3D &GetNormal() const;

private:
	CGVector3D m_vNormal;
	double m_dDist;

public:

	GDEFINE_OPERATOR_COPY(CGPlane);
	CGPlane();
	~CGPlane();
};