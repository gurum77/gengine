#pragma once


class CGSpaceQuadtreeElement : public CGQuadTreeElement
{
public:
	GID m_spaceID;	// point를 직접 넘겨 주는 것은 좀 ...위험..(나중에 파일로 관리할 수도 없음)

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
		- space가 화면에 보여야 하는지판단한다.
		- space를 상황에 맞게 화면에 표시한다.
			- 개략형상으로 보여야 하는지, 실제 모양으로 보여야 하는지 판단한다.
*/
class G_EXT_CLASS CGSpaceManager : public CG3DDB
{
	friend class CG3DTest;
public:
	// space 생성 알고리즘
	enum SpaceAlgorithm
	{
		eSpaceAlgorithm_SizeByRateOfObjectSize,	// object size에 비례한 크기
		eSpaceAlgorithm_SizeByFix				// 고정크기
	};

	enum Attr
	{
		eAttrCreateAroundSpace			= 0x00000001,	// 주변 space를 만들지?
		eAttrSpaceCanHaveOneObject		= 0x00000002,	// space가 1개의 object만 가질 수 있도록 한다.(디버깅용)
		eAttrAll	= 0xFFFFFFFF
	};

private:
	CG3DView *m_pView;
	SpaceAlgorithm m_eSpaceAlgorithm;
	DWORD32 m_dwAttr;
	float m_fDefaultSpaceSize;	// space 생성 기본 크기
	UINT m_uSizeForObjectToSpace;	// object가 space로 변환 되는 크기
	
	//CAtlMap<GID, CGSpace*> m_mapSpace;	// 실제 space가 보관되어 있는 map
	CAtlMap<GID, GID> m_mapObject;	// object ID, object 포함되어 있는 space ID
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

