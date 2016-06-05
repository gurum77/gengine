#pragma once

#define OBJECT_VERTICAL_ALIGNMENT GNOTRANS("VERTICAL_ALIGNMENT")

/**
	@brief
		- 종단 선형 객체
*/
class G_EXT_CLASS CGObjectVerticalAlignment :
	public CGCompoundObjectBase
{
public:
	void SetVerticalAlignment(const CGVerticalAlignment &vert);
	const CGVerticalAlignment &GetVerticalAlignment() const;
	CGVerticalAlignment &GetVerticalAlignment();

	void SetRefHorizontalAlignment(const GID &ID);
	const GID &GetRefHorizontalAlignment() const;

	CGObjectHorizontalAlignment *GetRefHorizontalAlignmentObject();
	void MatchStationWithHorizontalAlignment();

private:
	CGVerticalAlignment m_vert;
	GID m_refHorizontalAlignmentID;

protected:
	virtual void GenerateSubObject();
	void GenerateSubObject_Frame();
	void GenerateSubObject_DesignVIPLine();
	void GenerateSubObject_DesignVIPParameter();
	void GenerateSubObject_DesignVIP();
	void GenerateSubObject_DesignVIPText();
	void GenerateSubObject_GroundVIPLine();
	void GenerateSubObject_2CircleByPos(const CGPoint2D &pt);

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return OBJECT_VERTICAL_ALIGNMENT; };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyNone; };

	GDEFINE_REGISTE_OBJECT(CGObjectVerticalAlignment)
	CGObjectVerticalAlignment(void);
	~CGObjectVerticalAlignment(void);
};

