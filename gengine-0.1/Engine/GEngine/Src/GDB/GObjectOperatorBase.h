#pragma once

/**
	@brief
		- The base class of Operator for object
*/
class G_EXT_CLASS CGObjectOperatorBase
{
public:
	virtual void Move(CGObjectBase &object, const CGVector3D &vMove);
	virtual void Rotate(CGObjectBase &object, const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(CGObjectBase &object, const CGPoint3D &ptBase, const double &dScale);
	virtual void GenerateSubObject(CGObjectBase &object);
	virtual void CalcBoundary(CGObjectBase &object);
	const virtual void GetAllVertexByPrimitiveTopology(CGObjectBase &object, GOUT CAtlArray<GVERTEX> &arrVertex);
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(CGObjectBase &object, GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex);

	CGObjectOperatorBase(void);
	~CGObjectOperatorBase(void);
};

