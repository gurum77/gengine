#pragma once
class CG3DDB;

/**
	@brief
		- object�� �⺻ Ŭ����
		- Object ���߽� ���� ���� ----------------------------
			- GDEFINE_REGISTE_OBJECT �� ����� �����ؼ� object�� ����Ѵ�.
			- GIMPLEMENT_POOL, GIMPLEMENT_OPERATOR_COPY_BEGIN, GIMPLEMENT_OPERATOR_COPY_END �� �ҽ��� �����Ѵ�.(GDEFINE_REGISTE_OBJECT�� �׻� Ŀ�÷� �ʿ��ϴ�)
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
	GID m_parentID;	// �θ� object�� ID
	GID m_bufferItemID;	// buffer item id
	UINT32 m_uVertexOffset;	// vertex offset
	UINT32 m_uVertexCount;		// vertex count
	UINT32 m_uIndexOffset;
	UINT32 m_uIndexCount;
	
	CGCube m_cubeBoundary;	// object�� boundary
	CG3DDB *m_pDB;

protected:
	virtual void Move(const CGVector3D &vMove);
	virtual void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	virtual void Scale(const CGPoint3D &ptBase, const double &dScale);
	virtual void CalcBoundary();

public:
	/**
		@brief
			- vertex buffer layer�� Item ID�� �����Ѵ�.
	*/
	const GID GetBufferItemID() const;
	void SetBufferItemID(const GID &bufferItemID);

	/**
		@brief
			- vertex buffer�� �߰��� vertex�� ��� �����´�.
	*/
	const void GetAllVertex(GOUT CAtlArray<GVERTEX> &arrVertex) const;

	/**
		@brief
			- vertex buffer�� �߰��� vertex�� �����´�.
			- object�� �׸��� ���ؼ��� �ݵ�� �����ǰ� �ʿ��ϴ�.
	*/
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;

	/**
		@brief
			- vertex buffer�� �߰��� strip vertex�� list index�� �����´�.
			- object�� �׸��� ���ؼ��� �ݵ�� �����ǰ� �ʿ��ϴ�.
	*/
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;

	/**
		@brief
			- object�� Ÿ���� �����Ѵ�.
			- ������ string�̾�� �Ѵ�.
			- �ݵ�� ������ �Ǿ�� �Ѵ�.
	*/
	virtual CAtlString GetStrType() const{ return GNOTRANS("BASE");  };

	/**
		@brief
			- object�� vertex�� primitive topology�� �����Ѵ�.
			- object�� �Ѱ��� primitive topology�� ���� �� �ִ�.(�پ��� primitive topology�� �ʿ��ϴٸ� object�� ������ �������� �ϸ� �ȴ�)
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
