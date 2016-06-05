#pragma once

/**
	@brief
		- 2d point °´Ã¼
*/
class G_EXT_CLASS CGObjectPoint2D :
	public CGObjectBase
{
public:
	void SetPoint2D(const CGPoint2D &point2D);
	void SetPoint2DByXY(const double &dX, const double &dY);

private:
	CGPoint2D m_point2D;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("POINT2D"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyPoint; };

	GDEFINE_REGISTE_OBJECT(CGObjectPoint2D)
	CGObjectPoint2D();
	virtual ~CGObjectPoint2D();
};

