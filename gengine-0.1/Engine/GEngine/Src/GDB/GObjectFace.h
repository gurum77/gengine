#pragma once

/**
	@brief
		- face 1개를 표현하는 objects
*/
class G_EXT_CLASS CGObjectFace :
	public CGObjectBase
{
public:
	void SetFace(const CGFace &polygon);
	const CGFace &GetFace() const;

	void AddHole(const CGFace &polygonHole);
	INT32 GetHoleCount() const;
	CGFace *GetHole(const INT32 &iIdx);
	void InitHole();

private:
	CGFace m_face;
	CAtlArray<CGFace> m_arrHole;

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("FACE"); };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyTriangle; };

	GDEFINE_REGISTE_OBJECT(CGObjectFace)
	CGObjectFace();
	virtual ~CGObjectFace();
};

