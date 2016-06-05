#pragma once
#include "GRect.h"
class G_EXT_CLASS CGCube :
	public CGRect
{
public:
	void SetZMin(const double &dZMin);
	const double &GetZMin() const;

	void SetZMax(const double &dZMax);
	const double &GetZMax() const;

	void Offset(const double &dOffset);
	CGPoint3D GetCubeCenter() const;
	double GetRadius() const;

	void GetAllPoint3D(GOUT CAtlArray<CGPoint3D> &arrPoint3D) const;
	void SetByPoint2D(const CGPoint2D &point2D);
	void SetByPoint3D(const CGPoint3D &point3D);
	void SetByPoint2DArray(const CAtlArray<CGPoint2D> &arrPoint2D);
	void SetByPoint3DArray(const CAtlArray<CGPoint3D> &arrPoint3D);
	void MergeByPoint2D(const CGPoint2D &point2D);
	void MergeByPoint3D(const CGPoint3D &point3D);
	void MergeByCube(const CGCube &cube);
	void Init();

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);
	void Scale(const double &dScale);

	GDEFINE_OPERATOR_COPY(CGCube)
	GDEFINE_OPERATOR_EQUAL(CGCube)

private:
	double m_dZMin;
	double m_dZMax;

public:
	CGCube();
	~CGCube();
};

