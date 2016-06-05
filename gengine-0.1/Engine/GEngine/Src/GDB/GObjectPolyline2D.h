#pragma once

#define OBJECT_POLYLINE2D	GNOTRANS("POLYLINE2D")

/**
	@brief
		- 2d polyline °´Ã¼
*/
class G_EXT_CLASS CGObjectPolyline2D :
	public CGObjectBase
{
public:
	void SetPolyline2D(const CGPolyline2D &polyline2D);
	void SetPolyline2DByPosArr(const CAtlArray<CGPoint2D> &arrPos);
	const CGPolyline2D &GetPolyline2D() const;


private:
	CGPolyline2D m_polyline2D;
	

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return OBJECT_POLYLINE2D; };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyLine; };

	GDEFINE_REGISTE_OBJECT(CGObjectPolyline2D)
	CGObjectPolyline2D();
	virtual ~CGObjectPolyline2D();
};



