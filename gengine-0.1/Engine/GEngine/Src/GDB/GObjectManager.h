#pragma once


/**
	@brief
		- 객체 관리
*/
class G_EXT_CLASS CGObjectManager
{
public:
	enum Attr
	{
		eAttrDisplayOnlyTextOutline	= 0x00000001	// text의 outline만 그린다.
	};

	CGObjectBase *GetFirstObjectByType(const CAtlString &strType);
	CGObjectBase *FindObjectByID(const GID &ID);

	void InitObject();
	void AddObject(CGObjectBase *pObj, const bool &bNewID=TRUE);
	bool DeleteObject(CGObjectBase *pObj);
	bool DeleteObject(CAtlArray<CGObjectBase *> &arrObj);

	CGObjectBase *GetRootObject(const CGObjectBase &object);
	CGObjectBase *GetParentObject(const CGObjectBase &object);
	void GetAllSubObject(const CGObjectBase &object, GOUT CAtlArray<CGObjectBase*> &arrObject);

	void GetAllVertex(GOUT CAtlList<GVERTEX> &listVertex, const GetAllVertexParam &param);
	void GetAllVertexByObject(GOUT CAtlArray<GVERTEX> &arrVertex, const GetAllVertexByObjectParam &param);
	void GetAllVertexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, const GetAllVertexByPrimitiveTopologyParam &param);
	void GetAllStripVertexListIndexByPrimitiveTopology(GOUT CAtlArray<GVERTEX> &arrVertex, GOUT CAtlArray<UINT32> &arrIndex, const GetAllStripVertexListIndexByPrimitiveTopologyParam &param);
	void MoveVertexBufferByDeletingObject(const MoveVertexBufferByDeletingObjectParam &param);
	void MoveIndexBufferByDeletingObject(const MoveIndexBufferByDeletingObjectParam &param);

	CGCube CalcBoundary() const;
	
	const CAtlMap<GID, CGObjectBase*> &GetObjectList() const;
	CAtlMap<GID, CGObjectBase*> &GetObjectList();
	void GetAllObject(GOUT CAtlArray<CGObjectBase*> &arrObject);

	void SetMatTransform(const CGMatrix &matTransform);
	const CGMatrix &GetMatTransform() const;
	CGMatrix &GetMatTransform();

	void SetAttr(const DWORD32 &dwAttr);
	const DWORD32 &GetAttr() const;
	
private:
	CAtlMap<GID, CGObjectBase*> m_mapObject;
	CGIDManager m_IDManager;
	CGMatrix m_matTransform;	// object 전체에 적용되는 변환 메트릭스(빠른 속도로 object 전체를 이동/회전/축적 할 수 있다)
	DWORD32 m_dwAttr;


public:
	CGObjectManager();
	~CGObjectManager();
};

