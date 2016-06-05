#pragma once

/**
	@brief
		- compound object를 테스트하기 위한 샘플용 object
		- 자동차..
*/
class G_EXT_CLASS CGObjectCar :
	public CGCompoundObjectBase
{
public:
	void SetCenter(const CGPoint3D &ptCenter);

	void SetSize(const double &dSize);
	
private:
	CGPoint3D m_ptCenter;
	double m_dSize;

protected:
	virtual void GenerateSubObject();

public:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);

	virtual void CalcBoundary();
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;
	virtual CAtlString GetStrType()const { return GNOTRANS("CAR");  };
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyNone; };

	GDEFINE_REGISTE_OBJECT(CGObjectCar)
	CGObjectCar(void);
	virtual ~CGObjectCar(void);
};

