#pragma once

/**
	@brief
		- cylidner object
*/
class G_EXT_CLASS CGObjectCylinder :
	public CGObjectBase
{
public:
	void SetCylinder(const CGCylinder &cylinder);
	const CGCylinder &GetCylinder() const;

private:
	CGCylinder m_cylinder;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("CYLINDER"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyTriangle; };

	GDEFINE_REGISTE_OBJECT(CGObjectCylinder)
	CGObjectCylinder();
	virtual ~CGObjectCylinder();
};

