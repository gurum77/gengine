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

// CGPolygon3D�� CGPolygon ������ ���������� �ڵ�󿡼� ��� ������ ����� �� �ֵ��� �ϱ� ���� �Ʒ�ó�� ���� �����Ѵ�.
typedef CGPolyline3D CGPolygon;
typedef CGPolyline3D CGFace;
