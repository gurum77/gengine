#pragma once

/**
	@brief
		- sphere object
*/
class G_EXT_CLASS CGObjectSphere :
	public CGObjectBase
{
public:
	void SetSphere(const CGSphere &sphere);
	const CGSphere &GetSphere() const;

private:
	CGSphere m_sphere;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("SPHERE"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyTriangle; };

	GDEFINE_REGISTE_OBJECT(CGObjectSphere)
	CGObjectSphere();
	virtual ~CGObjectSphere();
};

