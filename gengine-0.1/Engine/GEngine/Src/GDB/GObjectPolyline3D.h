#pragma once

#define OBJECT_POLYLINE3D	GNOTRANS("POLYLINE3D")

/**
	@brief
		- 3d polyline °´Ã¼
*/
class G_EXT_CLASS CGObjectPolyline3D :
	public CGObjectBase
{
public:
	void SetPolyline3D(const CGPolyline3D &polyline3D);
	const CGPolyline3D &GetPolyline3D() const;

private:
	CGPolyline3D m_polyline3D;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return OBJECT_POLYLINE3D; };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyLine; };

	GDEFINE_REGISTE_OBJECT(CGObjectPolyline3D)
	CGObjectPolyline3D(void);
	virtual ~CGObjectPolyline3D(void);
};

