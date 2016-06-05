#pragma once

/**
	@brief
		- 3D circle object
*/
class G_EXT_CLASS CGObjectCircle3D :
	public CGObjectBase
{
public:
	void SetCircle3D(const CGCircle3D &circle3D);
	const CGCircle3D &GetCircle3D() const;
	CGCircle3D &GetCircle3D();

private:
	CGCircle3D m_circle3D;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("CIRCLE3D"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyLine; };

	GDEFINE_REGISTE_OBJECT(CGObjectCircle3D)
	CGObjectCircle3D();
	virtual ~CGObjectCircle3D();
};

