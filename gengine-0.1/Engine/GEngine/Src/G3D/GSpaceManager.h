#pragma once


class CGSpaceQuadtreeElement : public CGQuadTreeElement
{
public:
	GID m_spaceID;	// point�� ���� �Ѱ� �ִ� ���� �� ...����..(���߿� ���Ϸ� ������ ���� ����)

	virtual CGSpaceQuadtreeElement& operator=(const CGSpaceQuadtreeElement& d)
	{
		__super::operator =(d);
		m_spaceID	= d.m_spaceID;

		return *this;
	}
};


/**
	@brief
		- space manager
		- space�� ȭ�鿡 ������ �ϴ����Ǵ��Ѵ�.
		- space�� ��Ȳ�� �°� ȭ�鿡 ǥ���Ѵ�.
			- ������������ ������ �ϴ���, ���� ������� ������ �ϴ��� �Ǵ��Ѵ�.
*/
class G_EXT_CLASS CGSpaceManager : public CG3DDB
{
	friend class CG3DTest;
public:
	// space ���� �˰���
	enum SpaceAlgorithm
	{
		eSpaceAlgorithm_SizeByRateOfObjectSize,	// object size�� ����� ũ��
		eSpaceAlgorithm_SizeByFix				// ����ũ��
	};

	enum Attr
	{
		eAttrCreateAroundSpace			= 0x00000001,	// �ֺ� space�� ������?
		eAttrSpaceCanHaveOneObject		= 0x00000002,	// space�� 1���� object�� ���� �� �ֵ��� �Ѵ�.(������)
		eAttrAll	= 0xFFFFFFFF
	};

private:
	CG3DView *m_pView;
	SpaceAlgorithm m_eSpaceAlgorithm;
	DWORD32 m_dwAttr;
	float m_fDefaultSpaceSize;	// space ���� �⺻ ũ��
	UINT m_uSizeForObjectToSpace;	// object�� space�� ��ȯ �Ǵ� ũ��
	
	//CAtlMap<GID, CGSpace*> m_mapSpace;	// ���� space�� �����Ǿ� �ִ� map
	CAtlMap<GID, GID> m_mapObject;	// object ID, object ���ԵǾ� �ִ� space ID
	CGQuadTree<CGSpaceQuadtreeElement> *m_pQuadTree;
	
	bool IsInCamera(const CGCamera &camera, const CGSpace &space) const;
	INT32 CalcRadiusByWindow(const double &dRadius) const;
		 
	bool IsNeedRegenQuadtree(const CGSpace &space);
	void AddSpaceToQuadTree(const CGSpace &space);
	void AddSpace(CGSpace &space);
	bool RegenQuadTree();
	bool CreateQuadTree(const CGRect &rcBoundary);
	CGSpace *FindSpaceByID(const GID &ID);
	void FindUnloadedSpaceInView(GOUT CAtlArray<CGSpace*> &arrSpace);
	void FindLoadedSpaceOutOfView(GOUT CAtlArray<CGSpace*> &arrSpace);
	bool CheckDrawSpaceByObject(const CGSpace &space) const;
	
	
	CGSpace *CreateOptimizedSpaceForOBjectByRateOfObjectSize(const CGObjectBase &object);
	CGSpace *CreateOptimizedSpaceForOBjectByFixSize(const CGObjectBase &object);
	void CreateAroundSpace(const CGSpace &space);
	void GetAllObjectInSpace(const CGSpace &space, GINOUT CAtlArray<CGObjectBase*> &arrObject);

	bool IsDisplaySpaceAlways() const;

public:
	const UINT32 &GetSizeForObjectToSpace() const;
	void SetSizeForObjectToSpace(const UINT32 &uSize);

	void SetDefaultSpaceSize(const float &fDefaultSpaceSize);
	const float &GetDefaultSpaceSize() const;

	CGSpace *CreateOptimizedSpaceForOBject(const CGObjectBase &object);
	const CGSpaceManager::SpaceAlgorithm &GetSpaceAlgorithm() const;
	void SetSpaceAlgorithm(const CGSpaceManager::SpaceAlgorithm &eSpaceAlgorithm);
	CGCube CalcBoundary() const;
	CGSpace *UpdateSimpleSpaceByObject(const CGObjectBase &object);

	
	void UnloadSpace(GINOUT CGSpace &space);
	void LoadSpace(GINOUT CGSpace &space);

	void UnloadAllOutOfView();
	void LoadAllInView();

	void SetView(CG3DView *pView);
	void InitSpace();
	CGSpace *AddObject(const CGObjectBase &object);
	CGSpace *RemoveObject(const CGObjectBase &object);
	CGSpace *FindSpaceByObjectID(const GID &ID);
	CGSpace *FindOptimizedSpaceForObject(const CGObjectBase &object);
	
	bool DeleteSpace(CGSpace &space);
	bool MoveObjectToSpace(const CGObjectBase &object, CGSpace &toSpace);
	void FindSpaceInView(GOUT CAtlArray<CGSpace*> &arrSpace);
	void FindSpaceOutOfView(GOUT CAtlArray<CGSpace*> &arrSpace);

	void RegenOnlySpace(GINOUT CGSpace &space);

	void SetAttr(const DWORD32 &dwAttr);
	const DWORD32 &GetAttr() const;
	const bool IsAttr(const CGSpaceManager::Attr &eAttr) const;
	
public:
	CGSpaceManager();
	~CGSpaceManager();
};

