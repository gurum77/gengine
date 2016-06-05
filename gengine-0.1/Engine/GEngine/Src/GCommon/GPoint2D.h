#pragma once

/**
	@brief
		- 2D ��ǥ Ŭ����
*/
class G_EXT_CLASS CGPoint2D
{
public:
	void SetPointByXY(const double &dX, const double &dY);
	
	const double &GetX() const;
	const float GetXf() const;
	void SetX(const double &dX);

	const double &GetY() const;
	const float GetYf() const;
	void SetY(const double &dY);

	void Move(const double &dVectorX, const double &dVectorY);
	bool Rotate(const CGPoint2D &ptBase, const CGPoint2D &vAngle);
	bool Rotate(const CGPoint2D &vAngle);
	void Scale(const CGPoint2D &ptBase, const double &dScale);
	void MirrorHorizontal();

	virtual gfloat3 GetFloat3() const;

	double operator*(const CGPoint2D& d) const;//	{ return (x*d.y-y*d.x); }  // ����
	CGPoint2D operator-() const;
	CGPoint2D operator +(const CGPoint2D& s) const;
	CGPoint2D& operator +=(const CGPoint2D& s);
	CGPoint2D operator -(const CGPoint2D& s) const;
	CGPoint2D& operator -=(const CGPoint2D& s);
	CGPoint2D operator *(double d) const;
	CGPoint2D& operator *=(double d);
	CGPoint2D operator /(double d) const;
	CGPoint2D& operator /=(double d);
	double operator ^(const CGPoint2D &s) const;
	double operator ~() const;
	BOOL operator ==(const CGPoint2D& s) const;	
	BOOL operator !=(const CGPoint2D& s) const;
	CGPoint2D Unit() const;
	
	
protected:
	double m_dX;
	double m_dY;

public:
	GDEFINE_OPERATOR_COPY(CGPoint2D);
	CGPoint2D(const double &dX, const double &dY);
	CGPoint2D();
	~CGPoint2D();
};

// CGVector2D��  CGPoint2D �� ������ ���������� �ڵ�󿡼� ��� ������ ����� �� �ֵ��� �ϱ� ���� �Ʒ�ó�� ���� �����Ѵ�.
typedef CGPoint2D CGVector2D;
