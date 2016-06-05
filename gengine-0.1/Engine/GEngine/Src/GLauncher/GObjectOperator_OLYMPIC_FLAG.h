#pragma once

#define OBJECT_OLYMPIC_FLAG	GNOTRANS("OLYMPIC_FLAG")

/**
	@brief
		- example object for proxy object
		- object operator
*/
class G_EXT_CLASS CGObjectOperator_OLYMPIC_FLAG :
	public CGObjectOperatorBase
{
public:
	void SetCenterPos(CGObjectProxy &object, const CGPoint2D &ptCenter);
	CGPoint2D GetCenterPos(const CGObjectProxy &object) const;
	void SetRadius(CGObjectProxy &object, const double &dRadius);
	double GetRadius(const CGObjectProxy &object) const;
	
private:
	void GetAllCirclePos(const CGObjectParser_OLYMPIC_FLAG &parser, GOUT CAtlArray<CGPoint2D> &arrPos) const;
	CGColor GetCircleColor(const INT32 &iIdx) const;
	bool ParseObject(const CGObjectBase &object, GOUT CGObjectParser_OLYMPIC_FLAG &parser) const;

public:
	virtual void Move(CGObjectBase &object, const CGVector3D &vMove);
	virtual void Rotate(CGObjectBase &object, const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(CGObjectBase &object, const CGPoint3D &ptBase, const double &dScale);
	virtual void GenerateSubObject(CGObjectBase &object);
	virtual void CalcBoundary(CGObjectBase &object);
	const virtual void GetAllVertexByPrimitiveTopology(CGObjectBase &object, GOUT CAtlArray<GVERTEX> &arrVertex);
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(CGObjectBase &object, GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex);
	
public:
	CGObjectOperator_OLYMPIC_FLAG(void);
	~CGObjectOperator_OLYMPIC_FLAG(void);
};

