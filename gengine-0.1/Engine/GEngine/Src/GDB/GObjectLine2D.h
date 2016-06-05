#pragma once

#define OBJECT_LINE2D GNOTRANS("LINE2D")
/**
	@brief
		- 2d line °´Ã¼
*/
class G_EXT_CLASS CGObjectLine2D :
	public CGObjectBase
{
public:
	void SetLine2D(const CGLine2D &line2D);
	const CGLine2D &GetLine2D() const;
	void SetPoint2D(const CGPoint2D &point2D, const bool &bStt);
	const CGPoint2D &GetPoint2D(const bool &bStt) const;


private:
	CGLine2D m_line2D;


public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return OBJECT_LINE2D;  };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyLine; };

	GDEFINE_REGISTE_OBJECT(CGObjectLine2D)
	CGObjectLine2D();
	virtual ~CGObjectLine2D();
};


