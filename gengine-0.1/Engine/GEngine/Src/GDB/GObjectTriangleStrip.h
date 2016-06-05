#pragma once

class G_EXT_CLASS CGObjectTriangleStrip :
	public CGObjectBase
{
public:
	void SetTriangleStrip(const CGTriangleStrip &triangleStrip);
	const CGTriangleStrip &GetTriangleStrip() const;
	CGTriangleStrip &GetTriangleStrip();

private:
	CGTriangleStrip m_triangleStrip;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("TRIANGLE_STRIP"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyTriangle; };

	GDEFINE_REGISTE_OBJECT(CGObjectTriangleStrip)

public:
	CGObjectTriangleStrip();
	virtual ~CGObjectTriangleStrip();
};

