#pragma once

#define OBJECT_SUPERELEVATION GNOTRANS("SUPERELEVATION")

/**
	@brief
		- 편경사 객체
		- 좌/우 모두를 담고 있다.
*/
class G_EXT_CLASS CGObjectSuperelevation :
	public CGCompoundObjectBase
{
public:
	void SetSuperelevation(const CGSuperelevation &superEL);
	const CGSuperelevation &GetSuperelevation() const;
	CGSuperelevation &GetSuperelevation();

	void SetRefHorizontalAlignment(const GID &ID);
	const GID &GetRefHorizontalAlignment() const;

private:
	CGSuperelevation m_superEL;
	GID m_refHorizontalAlignmentID;

protected:
	virtual void GenerateSubObject();

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return OBJECT_SUPERELEVATION; };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyNone; };

	GDEFINE_REGISTE_OBJECT(CGObjectSuperelevation)


	CGObjectSuperelevation(void);
	~CGObjectSuperelevation(void);
};

