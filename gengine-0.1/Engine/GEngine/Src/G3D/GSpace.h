#pragma once
/**
	@brief
		- 공간정보 object
		- space는 동적으로 생성되거나 사라진다. 따라서 unload한다고 파일로 저장되지 않는다.
		- 파일로 저장할 경우 파일 확장자는 g3s이다.
*/
class G_EXT_CLASS CGSpace : public CGObjectBase
{
public:
	enum Attr
	{
		eAttrLoaded			= 0x00000001,	// file to memory로 load 되어 있음을 표시
		eAttrUnloaded		= 0x00000002,	// memory to file로 unload 되어 있음을 표시
		eAttrDrawBoundary	= 0x00000004,	// boundary로 표시되어 있음.(또는 되어야 하는 상황)
		eAttrDrawObject		= 0x00000008,	// object의 실제 형태로 표시되어 있음(또는 되어야 하는 상황)
		eAttrChanged		= 0x00000010	// space가 변경이 되었는지?
	};

	size_t GetObjectCount() const;
	size_t GetSpaceCount() const;

	void Load();
	void Unload();

	bool AddObject(const CGObjectBase &object);
	bool RemoveObject(const CGObjectBase &object);

	bool IsAttr(const CGSpace::Attr &eAttr) const;
	void SetAttr(const CGSpace::Attr &eAttr, const bool &bSet);

	void UpdateSimpleShape(const CGObjectBase &object);	// space의 개략형상을 갱신한다.

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

	// simple shape의 색상
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

