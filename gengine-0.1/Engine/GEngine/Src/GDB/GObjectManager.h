#pragma once


/**
	@brief
		- ��ü ����
*/
class G_EXT_CLASS CGObjectManager
{
public:
	enum Attr
	{
		eAttrDisplayOnlyTextOutline	= 0x00000001	// text�� outline�� �׸���.
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
	CGMatrix m_matTransform;	// object ��ü�� ����Ǵ� ��ȯ ��Ʈ����(���� �ӵ��� object ��ü�� �̵�/ȸ��/���� �� �� �ִ�)
	DWORD32 m_dwAttr;


public:
	CGObjectManager();
	~CGObjectManager();
};

