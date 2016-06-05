#pragma once

#define OBJECT_HORIZONTAL_ALIGNMENT GNOTRANS("HORIZONTAL_ALIGNMENT")
/**
	@brief
		- horizontal alignment object
*/
class G_EXT_CLASS CGObjectHorizontalAlignment :
	public CGCompoundObjectBase
{
public:
	void SetHorizontalAlignment(const CGHorizontalAlignment &hor);
	const CGHorizontalAlignment &GetHorizontalAlignment() const;
	CGHorizontalAlignment &GetHorizontalAlignment();

private:
	CGHorizontalAlignment m_hor;

protected:
	void GenerateSubObject_Element(const CAtlArray<CGHorizontalAlignmentPoint> &arrChainPoint);
	void GenerateSubObject_2CircleByPos(const CGHorizontalAlignmentPoint &pt);
	void GenerateSubObject_BPEP(const CAtlArray<CGHorizontalAlignmentPoint> &arrChainPos);
	void GenerateSubObject_Chain(const CAtlArray<CGHorizontalAlignmentPoint> &arrChainPos);
	void GenerateSubObject_Chain(const CGHorizontalAlignmentPoint &point);
	void GenerateSubObject_StationText(const CGHorizontalAlignmentPoint &point);
	virtual void GenerateSubObject();

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return OBJECT_HORIZONTAL_ALIGNMENT; };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyNone; };

	GDEFINE_REGISTE_OBJECT(CGObjectHorizontalAlignment)

	CGObjectHorizontalAlignment(void);
	~CGObjectHorizontalAlignment(void);
};

