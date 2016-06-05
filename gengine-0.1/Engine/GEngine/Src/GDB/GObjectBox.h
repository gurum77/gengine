#pragma once

/**
	@brief
		- box object
*/
class G_EXT_CLASS CGObjectBox :
	public CGObjectBase
{
public:
	void SetBox(const CGBox &box);
	const CGBox &GetBox() const;

private:
	CGBox m_box;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("BOX"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyTriangle; };

	GDEFINE_REGISTE_OBJECT(CGObjectBox)
	CGObjectBox();
	virtual ~CGObjectBox();
};

