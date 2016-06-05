#pragma once

/**
	@brief
		- 임의의 값을 가질 수 있는 커스터마이징이 가능한 객체
*/
class G_EXT_CLASS CGObjectProxy :
	public CGCompoundObjectBase
{
private:
	CGProxyVariable m_var;
	CAtlString m_strType;
	PrimitiveTopology m_ePrimitiveTopology;
public:
	CGProxyVariable &GetVar();
	const CGProxyVariable &GetVar() const;
	void SetType(const CAtlString &strType);
	void SetPrimitiveTopology(const PrimitiveTopology &ePrimitiveTopology);

public:
	virtual void GenerateSubObject();
	
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();
	
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return m_strType; };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return m_ePrimitiveTopology; };

public:
	GDEFINE_REGISTE_OBJECT(CGObjectProxy)
	CGObjectProxy(void);
	virtual ~CGObjectProxy(void);
};

