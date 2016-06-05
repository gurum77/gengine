#pragma once
/**
	@brief
		- �������� object
		- space�� �������� �����ǰų� �������. ���� unload�Ѵٰ� ���Ϸ� ������� �ʴ´�.
		- ���Ϸ� ������ ��� ���� Ȯ���ڴ� g3s�̴�.
*/
class G_EXT_CLASS CGSpace : public CGObjectBase
{
public:
	enum Attr
	{
		eAttrLoaded			= 0x00000001,	// file to memory�� load �Ǿ� ������ ǥ��
		eAttrUnloaded		= 0x00000002,	// memory to file�� unload �Ǿ� ������ ǥ��
		eAttrDrawBoundary	= 0x00000004,	// boundary�� ǥ�õǾ� ����.(�Ǵ� �Ǿ�� �ϴ� ��Ȳ)
		eAttrDrawObject		= 0x00000008,	// object�� ���� ���·� ǥ�õǾ� ����(�Ǵ� �Ǿ�� �ϴ� ��Ȳ)
		eAttrChanged		= 0x00000010	// space�� ������ �Ǿ�����?
	};

	size_t GetObjectCount() const;
	size_t GetSpaceCount() const;

	void Load();
	void Unload();

	bool AddObject(const CGObjectBase &object);
	bool RemoveObject(const CGObjectBase &object);

	bool IsAttr(const CGSpace::Attr &eAttr) const;
	void SetAttr(const CGSpace::Attr &eAttr, const bool &bSet);

	void UpdateSimpleShape(const CGObjectBase &object);	// space�� ���������� �����Ѵ�.

	const CAtlMap<GID, bool> &GetObjectMap() const;
	const CAtlMap<GID, bool> &GetSpaceMap() const;

private:
	CAtlString GetPathFileName() const;

	// space attribute
	DWORD32 m_dwAttr;

	// included object
	CAtlMap<GID, bool> m_mapObject;
	
	// included spaces
	CAtlMap<GID, bool> m_mapSpace;

	// simple shape�� ����
	gfloat3 m_rgbaSimpleShape;

public:
	virtual void CalcBoundary();
	virtual PrimitiveTopology GetPrimitiveTopology() const { return ePrimitiveTopologyLine; };
	const void GetAllVertex(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex) const;
	const virtual void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex) const;

	GDEFINE_REGISTE_OBJECT(CGSpace);
	CGSpace();
	~CGSpace();
};

