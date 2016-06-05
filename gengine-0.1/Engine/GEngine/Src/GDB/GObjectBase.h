#pragma once
class CG3DDB;

/**
	@brief
		- object의 기본 클래스
		- Object 개발시 주의 사항 ----------------------------
			- GDEFINE_REGISTE_OBJECT 를 헤더에 정의해서 object를 등록한다.
			- GIMPLEMENT_POOL, GIMPLEMENT_OPERATOR_COPY_BEGIN, GIMPLEMENT_OPERATOR_COPY_END 를 소스에 정의한다.(GDEFINE_REGISTE_OBJECT와 항상 커플로 필요하다)
*/
class G_EXT_CLASS CGObjectBase
{
	friend class CGDBAPI;

public:
	void InitID();

	void SetID(const GID &ID);
	const GID &GetID() const;
	
	void SetParentID(const GID &ID);
	const GID &GetParentID() const;
	
	void SetPropertyID(const GID &ID);
	const GID &GetPropertyID() const;

	void SetVertexOffset(const UINT32 &uOffset);
	const UINT32 &GetVertexOffset() const;

	void SetVertexCount(const UINT32 &uCount);
	const UINT32 &GetVertexCount() const;


	void SetIndexOffset(const UINT32 &uOffset);
	const UINT32 &GetIndexOffset() const;

	void SetIndexCount(const UINT32 &uCount);
	const UINT32 &GetIndexCount() const;

	void SetBoundary(const CGCube &cubeBoundary);
	const CGCube &GetBoundary() const;

	void SetDB(CG3DDB *pDB);
	CG3DDB *GetDB();
	const CG3DDB *GetDB() const;

	bool GetRGB(GOUT gfloat3 &f3RGB) const;
	CAtlString GetMaterialName() const;

protected:
	GID m_ID;
	GID m_propertyID;
	GID m_parentID;	// 부모 object의 ID
	GID m_bufferItemID;	// buffer item id
	UINT32 m_uVertexOffset;	// vertex offset
	UINT32 m_uVertexCount;		// vertex count
	UINT32 m_uIndexOffset;
	UINT32 m_uIndexCount;
	
	CGCube m_cubeBoundary;	// object의 boundary
	CG3DDB *m_pDB;

protected:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();

public:
	/**
		@brief
			- vertex buffer layer의 Item ID를 리턴한다.
	*/
	const GID GetBufferItemID() const;
	void SetBufferItemID(const GID &bufferItemID);

	/**
		@brief
			- vertex buffer에 추가할 vertex를 모두 가져온다.
	*/
	const void GetAllVertex(GOUT CAtlArray<GVERTEX> &arrVertex) const;

	/**
		@brief
			- vertex buffer에 추가할 vertex를 가져온다.
			- object를 그리기 위해서는 반드시 재정의가 필요하다.
	*/
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;

	/**
		@brief
			- vertex buffer에 추가할 strip vertex와 list index를 가져온다.
			- object를 그리기 위해서는 반드시 재정의가 필요하다.
	*/
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;

	/**
		@brief
			- object의 타입을 리턴한다.
			- 유일한 string이어야 한다.
			- 반드시 재정의 되어야 한다.
	*/
	virtual CAtlString GetStrType() const{ return GNOTRANS("BASE");  };

	/**
		@brief
			- object의 vertex의 primitive topology를 리턴한다.
			- object는 한가지 primitive topology만 가질 수 있다.(다양한 primitive topology가 필요하다면 object를 여러개 가지도록 하면 된다)
	*/
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyPoint; };
	
	
public:
	GDEFINE_POOL(CGObjectBase);
	virtual CGObjectBase *NewObject() = 0;
	virtual CGObjectBase *CloneObject();
	GDEFINE_OPERATOR_COPY(CGObjectBase);
	
	CGObjectBase();
	virtual ~CGObjectBase();
};
