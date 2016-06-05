#pragma once

/**
	@brief
		- API for GDB module for developer
*/
class G_EXT_CLASS CGDBAPI
{
public:
	static void GenerateSubObject(GINOUT CGObjectBase &object);
	static void Move(GINOUT CGObjectBase &object, const CGVector3D &vMove);
	static void Rotate(GINOUT CGObjectBase &object, const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	static void Scale(GINOUT CGObjectBase &object, const CGPoint3D &ptBase, const double &dScale);
	static void CalcBoundary(GINOUT CGObjectBase &object);

	static CGPropertyManager *GetPropertyManagerForObject(CGObjectBase &object);
public:
	CGDBAPI(void);
	~CGDBAPI(void);
};

