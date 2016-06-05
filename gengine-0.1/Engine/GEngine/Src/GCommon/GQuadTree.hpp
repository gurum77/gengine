#pragma once

/************************************************************************/
/* ���� : template�� dll�� ���� header�� ������ �ؾ� �Ѵ�.            */
/*        ���� �� ��������� cpp�� ���� �� ����.                      */
/************************************************************************/
#include <iostream>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Point2i
{
public:
	int x,  y;

	Point2i(const int &X, const int &Y)
		: x(X), y(Y)
	{
	};

	Point2i() {};


	bool operator==(Point2i &other) const
	{
		if(x == other.x && y == other.y)
			return true;

		return false;
	};
};

class Vec2f 
{
public:
	float x, y;

	/*void Serialize(CArchive &ar)
	{
		INT32 iFlag	= 0;

		if(ar.IsStoring())
		{
			ar << iFlag;
			ar << x;
			ar << y;
		}
		else
		{
			ar >> iFlag;
			ar >> x;
			ar >> y;
		}

	};*/

	Vec2f()
	{

	};

	Vec2f(const float &X, const float &Y)
	{
		x = X;
		y = Y;
	};

	Vec2f operator*(const float &scale) const
	{
		return Vec2f(x * scale, y * scale);
	};

	Vec2f operator/(const float &scale) const
	{
		return Vec2f(x / scale, y / scale);
	};

	Vec2f operator+(const Vec2f &other) const
	{
		return Vec2f(x + other.x, y + other.y);
	};

	Vec2f operator-(const Vec2f &other) const
	{
		return Vec2f(x - other.x, y - other.y);
	};

	Vec2f operator-() const
	{
		return Vec2f(-x, -y);
	};

	const Vec2f &operator*=(const float &scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	};

	const Vec2f &operator/=(const float &scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	};

	const Vec2f &operator+=(const Vec2f &other)
	{
		x += other.x;
		y += other.y;
		return *this;
	};

	const Vec2f &operator-=(const Vec2f &other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	};

	float magnitude() const
	{
		return sqrt(x * x + y * y);
	};

	float magnitudeSquared() const
	{
		return x * x + y * y;
	};

	Vec2f normalize() const
	{
		float m = sqrt(x * x + y * y);
		return Vec2f(x / m, y / m);
	};

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AABB
{
	/*void Serialize(CArchive &ar)
	{
		INT32 iFlag	= 0;

		if(ar.IsStoring())
		{
			ar << iFlag;
			lowerBound.Serialize(ar);
			upperBound.Serialize(ar);
		}
		else
		{
			ar >> iFlag;
			lowerBound.Serialize(ar);
			upperBound.Serialize(ar);
		}
	};*/

	// Members
	Vec2f lowerBound;
	Vec2f upperBound;

	// Constructor
	AABB()
		: lowerBound(0.0f, 0.0f),
		upperBound(1.0f, 1.0f)
	{
		
	};
	AABB(const Vec2f &bottomLeft, const Vec2f &topRight)
		: lowerBound(bottomLeft),
		upperBound(topRight)
	{

	}

	// Accessors
	Vec2f GetCenter() const
	{
		return (lowerBound + upperBound) / 2.0f;
	};

	Vec2f GetDims() const
	{
		return upperBound - lowerBound;
	};
	
	// Utility
	bool Intersects(const AABB &other)
	{
		if(upperBound.x < other.lowerBound.x)
			return false;

		if(upperBound.y < other.lowerBound.y)
			return false;

		if(lowerBound.x > other.upperBound.x)
			return false;

		if(lowerBound.y > other.upperBound.y)
			return false;

		return true;
	};

	bool Contains(const AABB &other)
	{
		if(other.lowerBound.x >= lowerBound.x &&
			other.upperBound.x <= upperBound.x &&
			other.lowerBound.y >= lowerBound.y &&
			other.upperBound.y <= upperBound.y)
			return true;

		return false;
	};
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class QuadTreeOccupant
{
public:
	void* pQuadTreeNode;
	void* pQuadTree;

	AABB aabb;

	// Call this whenever the AABB is modified or else stuff will break!
	

	// ���� : serialize�� �ϰ� �Ǹ� �ݵ�� pQuadTree�� pQuadTreeNode�� ��������� �Ѵ�.
	/*virtual void Serialize(CArchive &ar)
	{
		INT32 iFlag	= 0;

		if(ar.IsStoring())
		{
			ar << iFlag;
			ar << aabb.lowerBound.x;
			ar << aabb.lowerBound.y;
			ar << aabb.upperBound.x;
			ar << aabb.upperBound.y;
		}
		else
		{
			ar >> iFlag;
			INT32 nPtr	= 0;
			ar >> aabb.lowerBound.x;
			ar >> aabb.lowerBound.y;
			ar >> aabb.upperBound.x;
			ar >> aabb.upperBound.y;
		}
	};*/
	
	virtual QuadTreeOccupant& operator=(const QuadTreeOccupant& d)
	{
		pQuadTree	= d.pQuadTree;
		pQuadTreeNode	= d.pQuadTreeNode;
		aabb.lowerBound.x	= d.aabb.lowerBound.x;
		aabb.lowerBound.y	= d.aabb.lowerBound.y;
		aabb.upperBound.x	= d.aabb.upperBound.x;
		aabb.upperBound.y	= d.aabb.upperBound.y;

		return *this;
	}

	QuadTreeOccupant()
	{

	};

	QuadTreeOccupant(const QuadTreeOccupant& d)
		: pQuadTreeNode(NULL), pQuadTree(NULL)
	{
		*this	= d;
	};

	virtual ~QuadTreeOccupant()
	{

	};
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class ELEMENT>
class QuadTree;

template <class ELEMENT>
class QuadTreeNode
{
	friend class QuadTreeNode<ELEMENT>;
	friend class QuadTree<ELEMENT>;

public:
	enum Attr
	{
		eAttrInMemory	= 0x00000001,	// QuadTreeOccupant�� �޸𸮿� �ִ� ����(eAttrInFile�� ���ÿ� �����Ǹ� �ȵ�)
		eAttrInFile		= 0x00000002,	// QuadTreeOccupant�� ���Ͽ� �ִ� ����(eAttrInMemory�� ���ÿ� �����Ǹ� �ȵ�)
		eAttrWillSaveFile	= 0x0000004,	// save�� ������ ��
		eAttrCount
	};

	// QuadTreeNode�� serialize�Ѵ�.
	//void Serialize(CArchive &ar)
	//{
	//	INT32 iFlag	= 0;
	//	INT32 iCount	= 0;

	//	if(ar.IsStoring())
	//	{
	//		ar << iFlag;
	//		ar << m_dwAttr;
	//		ar << m_strGuid;

	//		region.Serialize(ar);
	//		center.Serialize(ar);

	//		// occupants file�� �����Ѵ�.(memory�� �ִ°��� ��� ���Ϸ� �����Ѵ�)
	//		SaveMemoryToFile();

	//		iCount	= occupants.GetCount();
	//		ar << iCount;
	//		for(INT32 ix = 0; ix < (INT32)occupants.GetCount(); ++ix)
	//		{
	//			occupants.GetAt(ix).Serialize(ar);
	//		}

	//		ar << hasChildren;
	//		if(hasChildren)
	//		{
	//			for(INT32 ix = 0; ix < 2; ++ix)
	//			{
	//				for(INT32 jx = 0; jx < 2; ++jx)
	//				{
	//					children[ix][jx]->Serialize(ar);
	//				}
	//			}
	//		}
	//		ar << numOccupants;
	//		ar << level;
	//	}
	//	else
	//	{
	//		ar >> iFlag;
	//		ar >> m_dwAttr;
	//		ar >> m_strGuid;

	//		region.Serialize(ar);
	//		center.Serialize(ar);

	//		ar >> iCount;
	//		occupants.SetCount(iCount);
	//		ELEMENT ele;
	//		for(INT32 ix = 0; ix < (INT32)occupants.GetCount(); ++ix)
	//		{
	//			ele.Serialize(ar);
	//			ele.pQuadTree	= pQuadTree;
	//			ele.pQuadTreeNode	= this;
	//			occupants.SetAt(ix, ele);
	//		}
	//		
	//		ar >> hasChildren;
	//		if(hasChildren)
	//		{
	//			Partition();

	//			for(INT32 ix = 0; ix < 2; ++ix)
	//			{
	//				for(INT32 jx = 0; jx < 2; ++jx)
	//				{
	//					children[ix][jx]->Serialize(ar);
	//				}
	//			}
	//		}
	//		ar >> numOccupants;
	//		ar >> level;
	//	}
	//};

	// attr (20140626, ����ȣ)
	void SetAttr(const Attr &eAttr, const bool &bSet)
	{
		if(!bSet)
			m_dwAttr	= m_dwAttr &~ eAttr;
		else
			m_dwAttr	= m_dwAttr | eAttr;
	};

	bool GetAttr(const Attr &eAttr) const
	{
		return m_dwAttr & eAttr ? TRUE : FALSE;
	};

	bool GetAttr(const DWORD32 &dwAttr) const
	{
		return m_dwAttr & dwAttr ? TRUE : FALSE;
	};

	/**
		@brief
			- ��� ��带 ������.(���� ����)
	*/
	void GetAllNode(CAtlList<QuadTreeNode<ELEMENT>*> &listRet)
	{
		listRet.AddTail(this);

		if(hasChildren)
		{
			for(INT32 ix = 0; ix < 2; ++ix)
			{
				for(INT32 jx = 0; jx < 2; ++jx)
				{
					children[ix][jx]->GetAllNode(listRet);
				}
			}
		}
	};

	/**
		@brief
			- QuadTreeOccupant�� ���Ϸ� �����ϰ� QuadTreeOccupant�� �ʱ�ȭ �Ѵ�.
	*/
	void SaveMemoryToFile()
	{
		//// �̹� ����Ǿ� �ִٸ� �޸𸮸� �����ϰ� ����
		//if(GetAttr(eAttrInFile))
		//{
		//	// save�� �ϰ� ���� �޸𸮸� �����Ѵ�.
		//	if(occupants.GetCount() > 1)
		//	{
		//		occupants.RemoveAt(1, occupants.GetCount()-1);
		//	}
		//	occupants.FreeExtra();	// �̰� ����� �޸𸮰� ������ �����ȴ�.
		//}
		//else
		//// ���Ϸ� ����
		//{
		//	// ���� open
		//	CString sFileName	= GetFileName();
		//	CFile file;
		//	if(!file.Open(sFileName, CFile::modeWrite | CFile::modeCreate))
		//		return;

		//	CArchive ar(&file, CArchive::store);
		//	SerializeOccupants(ar);
		//	ar.Close();
		//	file.Close();


		//	// save�� �ϰ� ���� �޸𸮸� �����Ѵ�.
		//	if(occupants.GetCount() > 1)
		//	{
		//		occupants.RemoveAt(1, occupants.GetCount()-1);
		//	}
		//	occupants.FreeExtra();	// �̰� ����� �޸𸮰� ������ �����ȴ�.
		//}

		//SetAttr(eAttrInFile, TRUE);
		//SetAttr(eAttrInMemory, FALSE);	// ���Ͽ� �����ϸ� �޸𸮸� �����Ѵ�.
		//SetAttr(eAttrWillSaveFile, FALSE);
	};

	/**
		@brief
			- QuadTreeOccupant�� ���Ͽ��� �о�ͼ� �޸𸮿� �ִ´�.
	*/
	void LoadMemoryFromFile()
	{
		//// �̹� �޸𸮿� �ִٸ� �׳� ����
		//if(GetAttr(eAttrInMemory))
		//	return;

		//// ���Ͽ��� �о�´�.
		//{
		//	// ���� open
		//	CString sFileName	= GetFileName();
		//	CFile file;
		//	if(!file.Open(sFileName, CFile::modeRead))
		//		return;

		//	CArchive ar(&file, CArchive::load);
		//	SerializeOccupants(ar);
		//	ar.Close();
		//	file.Close();

		//	//SetAttr(eAttrInFile, FALSE);	load�� �Ѵٰ� �ؼ� ������ �������� ���� �ƴϴ�. ������ �ѹ� ����� �׳� ����
		//	SetAttr(eAttrInMemory, TRUE);
		//	SetAttr(eAttrWillSaveFile, FALSE);
		//}
	};

	AABB GetRegion() const
	{
		return AABB(region.lowerBound, region.upperBound);
	};

	void GetAllOccupant(CAtlList<QuadTreeOccupant*> &listRet)
	{
		for(HGSIZE_T ix = 0; ix < occupants.GetCount(); ++ix)
		{
			listRet.AddTail(&occupants.GetAt(ix));
		}
	};

	void GetAllOccupant(CAtlArray<ELEMENT*> &arrRet)
	{
		arrRet.SetCount(occupants.GetCount());
		for(HGSIZE_T ix = 0; ix < occupants.GetCount(); ++ix)
			arrRet.SetAt(ix, &occupants.GetAt(ix));
	};

	CAtlString GetGuid()
	{
		return m_strGuid;
	};

private:

	/**
		@brief
			- occupants�� �����Ѵ�.
			- reference�� 1 �̻��� ���� �������� �ʴ´�.
	*/
	void InitOccupants()
	{
		occupants.RemoveAll();
		occupants.FreeExtra();
	};

	/**
		@brief
			- single reference�� �͸� �����´�.
	*/
	INT32 GetCountOccupant(const bool &bExcludeFirst=TRUE)
	{
		return bExcludeFirst ? occupants.GetCount() - 1 : occupants.GetCount();
	};

	CAtlString m_strGuid;	// guid
	DWORD m_dwAttr;


	AABB region;
	Vec2f center;

	QuadTreeNode<ELEMENT>* pParentNode;
	void* pQuadTree;

	CAtlArray<ELEMENT> occupants;	// 

	QuadTreeNode<ELEMENT>* children[2][2];
	bool hasChildren;

	UINT32 numOccupants;

	UINT32 level;

	// ���� ���丮 �ڿ� quadtree�� guid �� �ڿ� qnt_temp�� node ������ ����ȴ�.
	CAtlString GetFileName() const
	{
		CAtlString strQuadTreeGuid	= NOTRANS("");
		CAtlString strPath	= NOTRANS(".\\");
		if(pQuadTree)
		{
			strQuadTreeGuid	= ((QuadTree<ELEMENT>*)pQuadTree)->GetGuid();
			strPath	= ((QuadTree<ELEMENT>*)pQuadTree)->GetPath();
		}

		return strPath + strQuadTreeGuid + NOTRANS("\\qtn_temp\\") + m_strGuid + NOTRANS(".qtn");
	};

	void Partition()
	{
		// Create the children nodes with the appropriate bounds set
		Vec2f halfWidth = region.GetDims() / 2.0f;

		const unsigned int nextLevel = level + 1;

		for(unsigned int x = 0; x < 2; x++)
			for(unsigned int y = 0; y < 2; y++)
			{
				children[x][y] = new QuadTreeNode<ELEMENT>(AABB(Vec2f(region.lowerBound.x + x * halfWidth.x, region.lowerBound.y + y * halfWidth.y),
				Vec2f(center.x + x * halfWidth.x, center.y + y * halfWidth.y)), nextLevel, this, pQuadTree);
			}

		hasChildren = true;
	};

	void DestroyChildren()
	{
		for(unsigned int x = 0; x < 2; x++)
			for(unsigned int y = 0; y < 2; y++)
			{
				delete children[x][y];
			}
	};

	Point2i GetPossibleOccupantPos(QuadTreeOccupant* pOc)
	{
		Point2i pos;

		// NOTE: The center position of the pOc->aabb is not tested, instead a corner is.
		// The center point is not required because if a corner is not in the
		// same partition as the center then it won't fit in any partition anyways.

		if(pOc->aabb.lowerBound.x > center.x)
			pos.x = 1;
		else
			pos.x = 0;

		if(pOc->aabb.lowerBound.y > center.y)
			pos.y = 1;
		else
			pos.y = 0;

		return pos;
	};

public:

	INT32 GetNumOccupants()
	{
		
		return numOccupants;
	};

	// QuadTreeNode�� occupant ������ �����Ѵ�.
	//virtual void SerializeOccupants(CArchive &ar)
	//{
	//	INT32 iFlag	= 0;

	//	INT32 nCount	= 0;
	//	if(ar.IsStoring())
	//	{
	//		ar << iFlag;

	//		nCount	= occupants.GetCount() - 1;//GetCountOccupant();
	//		ar << nCount;

	//		ELEMENT *p	= NULL;
	//		// ù��°�� �ǳʶڴ�.
	//		for(HGSIZE_T ix = 1; ix < occupants.GetCount(); ++ix)
	//		{
	//			p	= &occupants.GetAt(ix);
	//			p->Serialize(ar);
	//		}


	//	}
	//	else
	//	{
	//		ar >> iFlag;

	//		ar >> nCount;

	//		{
	//			occupants.SetCount(nCount + 1);
	//			ELEMENT ele;
	//			for(INT32 ix = 0; ix < nCount; ++ix)
	//			{
	//				ele.Serialize(ar);
	//				ele.pQuadTreeNode = this;
	//				ele.pQuadTree = pQuadTree;
	//				occupants.SetAt(ix+1, ele);
	//			}
	//		}
	//	}
	//};

	QuadTreeNode(const AABB &newRegion, unsigned int numLevels, QuadTreeNode<ELEMENT>* pParent = NULL, void * pContainer = NULL)
		: region(newRegion), hasChildren(false), numOccupants(0),
		pParentNode(pParent), pQuadTree(pContainer), level(numLevels)
	{

		center = region.GetCenter();

		m_dwAttr	= eAttrInMemory;
		m_strGuid	= CGShell::NewGuid();
	};

	~QuadTreeNode()
	{
		if(hasChildren)
			DestroyChildren();

		InitOccupants();

		// ���ϵ� �����Ѵ�.(��ȣ���� �������� �����Ѵ�)
		bool bDeleteFile	= TRUE;
		
		if(pQuadTree)
		{
			bDeleteFile	= ((QuadTree<ELEMENT>*)pQuadTree)->GetProtectSavedNodeFile() == TRUE ? FALSE : TRUE;
		}

		if(bDeleteFile)
		{
			/*CFileFind ff;
			if(ff.FindFile(GetFileName()))
				DeleteFile(GetFileName());*/
		}
	};

	ELEMENT *AddOccupant(ELEMENT &oc)
	{
		numOccupants++;

		// ������ level�̸� ���⿡ �߰��Ѵ�.
		if(level < ((QuadTree<ELEMENT>*)pQuadTree)->GetMaxLevel())
		{
			// �ڽĳ�尡 ���ٸ� ���� ����� �ش�.
			if(!hasChildren)
				Partition();

			Point2i pos = GetPossibleOccupantPos(&oc);

			// �ڽ� ��忡 �߰��� �����ϸ� �׳� ���⿡ �߰��Ѵ�.(�ڽĳ���� ��輱�� �ɸ��� ����̴�)
			if(children[pos.x][pos.y]->region.Contains(oc.aabb))
			{
				// Fits into this child node, to continue
				// the adding process from there
				return children[pos.x][pos.y]->AddOccupant(oc);
			}
		}


		// �ڽ� ��忡 �߰����� ���ϰų�, ������ level�̸� �׳� ���⿡ �߰��Ѵ�.
		oc.pQuadTreeNode = this;
		oc.pQuadTree = pQuadTree;
		return ((QuadTree<ELEMENT>*)pQuadTree)->AddOccupantFast(occupants, oc);
	};

	void Query(const AABB &queryRegion, CAtlList<QuadTreeOccupant*> &queryResult)
	{
		// See if this region is visible
		if(region.Intersects(queryRegion))
		{
			// query�� �Ҷ��� ���Ͽ� �ִ� ��� �޸𸮷� �ø��� ���� query�� �ؾ��Ѵ�.(����ȣ)
			{
				LoadMemoryFromFile();
			}


			// Add the occupants of this node to the array and then parse the children
			QuadTreeOccupant *p	= NULL;
			for(size_t ix = 0; ix < occupants.GetCount(); ++ix)
			{
				p	= &occupants.GetAt(ix);
				if(p->aabb.Intersects(queryRegion))
					queryResult.AddTail(p);
			}

			if(hasChildren)
			{
				for(unsigned int x = 0; x < 2; x++)
					for(unsigned int y = 0; y < 2; y++)
						children[x][y]->Query(queryRegion, queryResult);
			}
		}
	};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class ELEMENT>
class QuadTree
{
public:
	// QuadTree �� serialize �Ѵ�.
	//void Serialize(CArchive &ar)
	//{
	//	INT32 iFlag	= 0;
	//	INT32 iCount	= 0;
	//	bool bExistRootNode	= TRUE;
	//	if(ar.IsStoring())
	//	{
	//		ar << iFlag;
	//		ar << m_strGuid;

	//		iCount	= outsideRoot.GetCount();
	//		ar << iCount;
	//		for(INT32 ix = 0; ix < iCount; ++ix)
	//		{
	//			outsideRoot.GetAt(ix).Serialize(ar);
	//		}
	//		
	//		if(rootNode)
	//		{
	//			bExistRootNode	= TRUE;
	//			ar << bExistRootNode;
	//			rootNode->Serialize(ar);
	//		}
	//		else
	//		{
	//			bExistRootNode	= FALSE;
	//			ar << bExistRootNode;
	//		}
	//		
	//		ar << m_nMaxLevel;
	//		ar << m_nGrowSizeOccupants;	// occ�� �߰��Ҷ� �����Ǵ� ����
	//	}
	//	else
	//	{
	//		ar >> iFlag;
	//		ar >> m_strGuid;

	//		InitOutsideRoot();

	//		ar >> iCount;
	//		outsideRoot.SetCount(iCount);
	//		
	//		ELEMENT ele;
	//		for(INT32 ix = 0; ix < iCount; ++ix)
	//		{
	//			ele.Serialize(ar);
	//			outsideRoot.SetAt(ix, ele);
	//		}

	//		ar >> bExistRootNode;
	//		if(bExistRootNode)
	//		{
	//			if(!rootNode)
	//			{
	//				AABB region;
	//				rootNode = new QuadTreeNode<ELEMENT>(region, 0, NULL, this);
	//			}
	//			rootNode->Serialize(ar);
	//		}
	//		else
	//		{
	//			HG_SAFE_DELETE(rootNode);
	//		}
	//		
	//		ar >> m_nMaxLevel;
	//		ar >> m_nGrowSizeOccupants;	// occ�� �߰��Ҷ� �����Ǵ� ����
	//	}
	//};

protected:
	void InitOutsideRoot()
	{
		outsideRoot.RemoveAll();
		outsideRoot.FreeExtra();
	};

	CAtlArray<ELEMENT> outsideRoot;

	
	QuadTreeNode<ELEMENT>* rootNode;
	UINT32 m_nMaxLevel;
	UINT32 m_nGrowSizeOccupants;	// occ�� �߰��Ҷ� �����Ǵ� ����
	bool m_bProtectSavedNodeFile;	// save�� node ���ϵ��� ��ȣ�ؾ� �ϴ���?
	CAtlString m_strGuid;	// quadtree�� guid(multi quadtree������ sub quad tree�� ��� ���� guid�� ������)
	CAtlString m_strPath;	// ���Ϸ� �����Ҷ��� ���


public:

	void SetProtectSavedNodeFile(const bool &bProtectSavedNodeFile)
	{
		m_bProtectSavedNodeFile	= bProtectSavedNodeFile;
	};

	bool GetProtectSavedNodeFile() const
	{
		return m_bProtectSavedNodeFile;
	};

	/**
		@brief
			- array�� element�� ������ �߰��Ѵ�.
			- grow size�� �����Ѵ�.
		@return
			- �߰��� ELEMENT�� pointer�� �����Ѵ�.
	*/
	ELEMENT* AddOccupantFast(CAtlArray<ELEMENT> &arr, ELEMENT &ele)
	{
		// grow�� �ؾ� �ϴ� ��Ȳ�̸� grow�� �Ѵ�.
		INT32 nCountOld	= arr.GetCount();
		INT32 nCount	= arr.GetCount() / m_nGrowSizeOccupants;
		if(arr.GetCount() % m_nGrowSizeOccupants == 0)
		{
			arr.SetCount(m_nGrowSizeOccupants * (nCount + 1));
			arr.RemoveAt(nCountOld, arr.GetCount()-nCountOld);
		}

		arr.Add(ele);

		return &arr.GetAt(arr.GetCount()-1);
	};

	UINT32 GetMaxLevel()
	{
		return m_nMaxLevel;
	};

	UINT32 GetGrowSizeOccupants()
	{
		return m_nGrowSizeOccupants;
	};

	CAtlString GetGuid()
	{
		return m_strGuid;
	};

	CAtlString GetPath()
	{
		return m_strPath;
	};

	QuadTree(const AABB &startRegion)
	{
		m_nMaxLevel	= 10;
		m_nGrowSizeOccupants	= 6;
		m_strGuid	= CGShell::NewGuid();
		m_strPath	= GNOTRANS(".\\");

		rootNode = new QuadTreeNode<ELEMENT>(startRegion, 1, NULL, this);
	};

	~QuadTree()
	{
		InitOutsideRoot();

		delete rootNode;
	};

	QuadTreeNode<ELEMENT> *GetRootNode()
	{
		return rootNode;
	};

	ELEMENT* AddOccupant(ELEMENT &oc)
	{
		if(rootNode->region.Contains(oc.aabb)) // If it fits inside the root node
			return rootNode->AddOccupant(oc);
		else // Otherwise, add it to the outside root set
		{
			// Set the pointers properly
			oc.pQuadTreeNode = NULL; // Not required unless removing a node and then adding it again
			oc.pQuadTree = this;
			return AddOccupantFast(outsideRoot, oc);
		}

		return NULL;
	}

	void ClearTree(const AABB &newStartRegion)
	{
		delete rootNode;
		rootNode = new QuadTreeNode(newStartRegion, 1, NULL, this);

		// Clear ouside root
		InitOutsideRoot();
	};

	void SetMaxLevel(const UINT32 &nMaxLevel)
	{
		m_nMaxLevel	= nMaxLevel;
	};

	/**
		@brief
			- max occupants�� �����ϸ� rootnode�� �ٽ� ������.
	*/
	void SetGrowSizeOccupants(const UINT32 &nMaxOccupants)
	{
		m_nGrowSizeOccupants	= nMaxOccupants;
	};

	/**
		@brief
			- quadtree�� guid
			- multi quadtree������ sub �� ��� main�� ������ guid�� ������.
			- node�� ���Ϸ� �����Ҷ� directory���� �ȴ�.
	*/
	void SetGuid(const CAtlString &strGuid)
	{
		m_strGuid	= strGuid;
	};

	/**
		@brief
			- ��������� ���
			- �⺻��(.\\)
	*/
	void SetPath(const CAtlString &strPath)
	{
		m_strPath	= strPath;
	};

	void Query(const AABB &queryRegion, CAtlList<QuadTreeOccupant*> &queryResult)
	{
		// First parse the occupants outside of the root and
		// add them to the array if the fit in the query region
		QuadTreeOccupant *p	= NULL;
		for(size_t ix = 0; ix < outsideRoot.GetCount(); ++ix)
		{
			p	= &outsideRoot.GetAt(ix);
			if(p->aabb.Intersects(queryRegion))
				queryResult.AddTail(p);
		}

		// Then query the tree itself
		rootNode->Query(queryRegion, queryResult);
	};

	unsigned int GetNumOccupants()
	{
		return rootNode->numOccupants;
	};
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CGQuadTreeElement : public QuadTreeOccupant
{
public:
	void SetBoundary(const AABB &rc)

	{
		aabb	= rc;

	};

	CGQuadTreeElement()
	{

	};

	CGQuadTreeElement(const CGQuadTreeElement& d)
		:QuadTreeOccupant(d)
	{

	};

	virtual ~CGQuadTreeElement(void){};
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	@brief
		- quadtree Ŭ����
*/
template<class ELEMENT>
class CGQuadTree : public QuadTree<ELEMENT>
{
public:
	enum Attr
	{
		eAttrManageNodeByFile	= 0x00000001,	// node�� ���Ϸ� ����
		eAttrCount
	};

	/**
		@brief
			- quadtree�� serialize�Ѵ�.
	*/
	//void Serialize(CArchive &ar)
	//{
	//	// 1 : m_dMaxSegmentLength
	//	INT32 iFlag	= 1;

	//	if(ar.IsStoring())
	//	{
	//		ar << iFlag;
	//		__super::Serialize(ar);

	//		ar << m_dwAttr;
	//		ar << m_rcRegion;
	//		ar << m_dMaxSegmentLength;
	//	}
	//	else
	//	{
	//		ar >> iFlag;
	//		__super::Serialize(ar);

	//		ar >> m_dwAttr;
	//		ar >> m_rcRegion;
	//		if(iFlag > 0)
	//		{
	//			ar >> m_dMaxSegmentLength;
	//		}
	//	}
	//};

protected:
	void SetWillFileSaveToAllNode()
	{
		CAtlList<QuadTreeNode<ELEMENT>*> list;
		GetAllNode(list);

		POSITION pos	= list.GetHeadPosition();
		while(pos != NULL)
		{
			list.GetNext(pos)->SetAttr(QuadTreeNode<ELEMENT>::eAttrWillSaveFile, TRUE);
		}
	};

	/**
		@brief
			- save �� ���� ������ �����Ѵ�.
	*/
	void SetNotWillFileSave(CAtlList<QuadTreeOccupant*> &listRet)
	{
		QuadTreeOccupant *p	= NULL;
		POSITION pos	= listRet.GetHeadPosition();
		while(pos != NULL)
		{
			p	= listRet.GetNext(pos);
			if(!p->pQuadTreeNode)
				continue;

			((QuadTreeNode<ELEMENT>*)p->pQuadTreeNode)->SetAttr(QuadTreeNode<ELEMENT>::eAttrWillSaveFile, FALSE);
		}
	};

	/**
		@brief
			- save �� ������ node�� ��� save�Ѵ�.
	*/
	void SaveFileWillFileSavdAllNode()
	{
		if(!GetAttr(eAttrManageNodeByFile))
			return;

		CAtlList<QuadTreeNode<ELEMENT>*> list;
		GetAllNode(list);

		QuadTreeNode<ELEMENT> *p	= NULL;
		POSITION pos	= list.GetHeadPosition();
		while(pos != NULL)
		{
			p	= list.GetNext(pos);
			if(p->GetAttr(QuadTreeNode<ELEMENT>::eAttrWillSaveFile))
			{
				p->SaveMemoryToFile();
			}
		}
	};

	DWORD32 m_dwAttr;
	AABB m_rcRegion;
	float m_fMaxSegmentLength;	// segment�� �˻��Ҷ� segment�� �ִ� ����(0�̸� �ѹ��� ã��)
	
public:
	// attr
	AABB GetRegion() const
	{
		return m_rcRegion;
	};

	float GetMaxSegmentLength() const
	{
		return m_fMaxSegmentLength;
	};

	void SetMaxSegmentLength(const double &dMaxSegmentLength)
	{
		m_fMaxSegmentLength	= dMaxSegmentLength;
	};

	void SetAttr(const DWORD32 &dwAttr)
	{
		m_dwAttr	= dwAttr;
	};

	void SetAttr(const Attr &eAttr, const bool &bSet)
	{
		if(!bSet)
			m_dwAttr	= m_dwAttr &~ eAttr;
		else
			m_dwAttr	= m_dwAttr | eAttr;
	};

	DWORD32 GetAttr() const
	{
		return m_dwAttr;
	}

	bool GetAttr(const Attr &eAttr) const
	{
		return m_dwAttr & eAttr ? TRUE : FALSE;
	};
	void GetAllElement(CAtlArray<ELEMENT*> &arrEleRet)
	{
		// outside element�� �����´�.
		arrEleRet.SetCount(outsideRoot.GetCount());
		for(HGSIZE_T ix = 0; ix < outsideRoot.GetCount(); ++ix)
			arrEleRet.SetAt(ix, &outsideRoot.GetAt(ix));

		// ��带 ��� �����´�.
		{
			CAtlList<QuadTreeNode<ELEMENT>*> list;
			GetAllNode(list);
			POSITION pos	= list.GetHeadPosition();
			while(pos != NULL)
			{
				QuadTreeNode<ELEMENT> *pNode	= list.GetNext(pos);
				if(!pNode)
					continue;

				CAtlArray<ELEMENT*> arr;
				pNode->GetAllOccupant(arr);

				arrEleRet.Append(arr);
			}
		}
	}

	void GetAllNode(CAtlList<QuadTreeNode<ELEMENT>*> &listRet)
	{
		if(!GetRootNode())
			return;

		GetRootNode()->GetAllNode(listRet);
	};

	/**
		@brief
			- file�� ����� node�� ��� �����´�.
			- test�� ���� �ڵ��̴�.
	*/
	void GetAllInFileNode(CAtlList<QuadTreeNode<ELEMENT>*> &listRet)
	{
		CAtlList<QuadTreeNode<ELEMENT>*> listAll;
		GetAllNode(listAll);


		QuadTreeNode<ELEMENT> *p	= NULL;
		POSITION pos	= listAll.GetHeadPosition();
		while(pos != NULL)
		{
			p	= listAll.GetNext(pos);
			if(p->GetAttr(QuadTreeNode<ELEMENT>::eAttrInFile) && !p->GetAttr(QuadTreeNode<ELEMENT>::eAttrInMemory))
				listRet.AddTail(p);
		}
	};

	/**
		@brief
			- memory�� ����� node�� ��� �����´�.
			- test�� ���� �ڵ��̴�.
	*/
	void GetAllInMemoryNode(CAtlList<QuadTreeNode<ELEMENT>*> &listRet)
	{
		CAtlList<QuadTreeNode<ELEMENT>*> listAll;
		GetAllNode(listAll);


		QuadTreeNode<ELEMENT> *p	= NULL;
		POSITION pos	= listAll.GetHeadPosition();
		while(pos != NULL)
		{
			p	= listAll.GetNext(pos);
			if(!p->GetAttr(QuadTreeNode<ELEMENT>::eAttrInFile) && p->GetAttr(QuadTreeNode<ELEMENT>::eAttrInMemory))
				listRet.AddTail(p);
		}
	};

	
	/**
		@brief
			- ��� ��带 ���Ϸ� �����Ѵ�.
	*/
	void SaveFileAllNode()
	{
		if(!GetAttr(eAttrManageNodeByFile))
			return;

		// ��� ��带 �����´�.
		CAtlList<QuadTreeNode<ELEMENT>*> list;
		{
			GetAllNode(list);
		}


		// ��� ��带 �����Ѵ�.
		{
			// ���丮�� �����Ѵ�.
			if(m_strPath != NOTRANS(".\\"))
			{
				CreateDirectory(m_strPath, NULL);
			}

			CreateDirectory(m_strPath + GetGuid(), NULL);
			CreateDirectory(m_strPath + GetGuid() + NOTRANS("\\qtn_temp"), NULL);
			//_mkdir(".\\qtn_temp");
			POSITION pos	= list.GetHeadPosition();
			while(pos != NULL)
			{
				QuadTreeNode<ELEMENT> *pNode	= list.GetNext(pos);
				pNode->SaveMemoryToFile();
			}
		}
	};

	void FindElementByRegion(const AABB &rc, CAtlList<CGQuadTreeElement*> &listRet)
	{
		// query �������� ����save �������� �����Ѵ�.
		{
			SetWillFileSaveToAllNode();
		}


		// query ����
		CAtlList<QuadTreeOccupant*> queryResult;
		AABB region(rc);

		Query(region, queryResult);

		// query�� ���ؼ� ���� ���� WilFileSave ���� ����(������ �� ����� ���ɼ��� �����Ƿ�)
		{
			SetNotWillFileSave(queryResult);
		}

		POSITION pos	= queryResult.GetHeadPosition();
		while(pos != NULL)
		{
			listRet.AddTail(reinterpret_cast<CGQuadTreeElement*>(queryResult.GetNext(pos)));
		}


		// qeury �����Ŀ� memory�� load�� �� �߿��� save ������ �͵��� ��� save�Ѵ�.
		{
			SaveFileWillFileSavdAllNode();
		}
	};

	void FindElementBySeg(const Vec2f &xy1, const Vec2f &xy2, CAtlList<CGQuadTreeElement*> &listRet)
	{
		// �� ���� �������� pos�� ã�´�.
		if(xy1 == xy2)
		{
			FindElementByPos(xy1, listRet);
			return;
		}

		// max segment length�� 0�̸� region���� �ѹ濡 ���Ѵ�.
		if(m_fMaxSegmentLength == 0)
		{
			AABB rc(0, 0, 0, 0);
			rc.left	= min(xy1.x, xy2.x);
			rc.bottom	= min(xy1.y, xy2.y);
			rc.right	= max(xy1.x, xy2.x);
			rc.top	= max(xy1.y, xy2.y);

			FindElementByRegion(rc, listRet);

			return;
		}

		// query �������� ����save �������� �����Ѵ�.
		{
			SetWillFileSaveToAllNode();
		}

		// seg�� �������� �ɰ��� query�� ������.
		double dLenTot	= (xy1 - xy2).magnitude();
		double dLenUnit	= m_fMaxSegmentLength;	// seg �Ѱ��� ����
		INT32 nCount	= dLenTot / dLenUnit;
		double dLenRemain	= dLenTot - (nCount * dLenUnit);
		
		AABB region;
		CAtlList<QuadTreeOccupant*> queryResult;
		CAtlMap<QuadTreeOccupant*, bool> mapEle;
		Vec2f dptStt	= xy1;
		Vec2f vDir	= (xy2 - xy1).normalize();
		Vec2f dptEnd	= xy1;
		
		for(INT32 ix = 0; ix < nCount+1; ++ix)
		{
			if(ix < nCount)
			{
				dptEnd	= dptStt + vDir * dLenUnit;
			}
			else
			{
				if(dLenRemain == 0)
					break;
					
				dptEnd	= dptStt + vDir * dLenRemain;
			}

			// query ����
			{
				queryResult.RemoveAll();

				region.lowerBound.x	= min(dptStt.x, dptEnd.x);
				region.lowerBound.y	= min(dptStt.y, dptEnd.y);
				region.upperBound.x	= max(dptStt.x, dptEnd.x);
				region.upperBound.y	= max(dptStt.y, dptEnd.y);

				Query(region, queryResult);

				// query�� ���ؼ� ���� ���� WilFileSave ���� ����(������ �� ����� ���ɼ��� �����Ƿ�)
				{
					SetNotWillFileSave(queryResult);
				}

				// �ߺ��Ǵ� eleement�� �ɷ����� �Ѵ�.
				POSITION pos	= queryResult.GetHeadPosition();
				while(pos != NULL)
				{
					mapEle.SetAt(queryResult.GetNext(pos), TRUE);
				}
			}

			dptStt	= dptEnd;
		}
		
		// 
		{
			POSITION pos	= mapEle.GetStartPosition();
			while(pos != NULL)
			{
				listRet.AddTail(reinterpret_cast<CGQuadTreeElement*>(mapEle.GetNextKey(pos)));
			}
		}

		// qeury �����Ŀ� memory�� load�� �� �߿��� save ������ �͵��� ��� save�Ѵ�.
		{
			SaveFileWillFileSavdAllNode();
		}
	};

	void FindElementByPos(const Vec2f &xy, CAtlList<CGQuadTreeElement*> &listRet)
	{
		AABB rc(xy, xy);

		FindElementByRegion(rc, listRet);
	};

	/**
		@brief
			- �Ӽ��� ���ؼ� element�� �����´�.
			- �ַ� �����Ҷ� ȣ���.
	*/
	void FindElementByAttr(const DWORD32 &dwAttr, CAtlList<CGQuadTreeElement*> &listRet)
	{
		// query �������� ����save �������� �����Ѵ�.
		{
			SetWillFileSaveToAllNode();
		}	

		CAtlList<QuadTreeNode<ELEMENT>*> listNode;
		GetAllNode(listNode);
		POSITION pos	= listNode.GetHeadPosition();

		QuadTreeNode<ELEMENT> *pNode	= NULL;
		CAtlList<QuadTreeOccupant*> listOcc;
		while(pos != NULL)
		{
			pNode	= listNode.GetNext(pos);
			if((dwAttr & QuadTreeNode<ELEMENT>::eAttrInMemory && pNode->GetAttr(QuadTreeNode<ELEMENT>::eAttrInMemory)) ||
				(dwAttr & QuadTreeNode<ELEMENT>::eAttrInFile && pNode->GetAttr(QuadTreeNode<ELEMENT>::eAttrInFile)) ||
				(dwAttr & QuadTreeNode<ELEMENT>::eAttrWillSaveFile && pNode->GetAttr(QuadTreeNode<ELEMENT>::eAttrWillSaveFile))
				)
			{
				pNode->LoadMemoryFromFile();

				pNode->GetAllOccupant(listOcc);
			}
			else
			{
				int i =0;
				i = 0;
			}
		}

		// query�� ���ؼ� ���� ���� WilFileSave ���� ����(������ �� ����� ���ɼ��� �����Ƿ�)
		{
			SetNotWillFileSave(listOcc);
		}

		POSITION posOcc	= listOcc.GetHeadPosition();
		while(posOcc != NULL)
		{
			listRet.AddTail(dynamic_cast<CGQuadTreeElement*>(listOcc.GetNext(posOcc)));
		}


		// qeury �����Ŀ� memory�� load�� �� �߿��� save ������ �͵��� ��� save�Ѵ�.
		{
			SaveFileWillFileSavdAllNode();
		}
	};

	bool IsExistElement()
	{
		return GetNumOccupants() > 0;
	};

	INT32 GetCountElement()
	{
		return rootNode->GetNumOccupants() + outsideRoot.GetCount();
	};

	static void InitElement(CAtlList<CGQuadTreeElement*> &listRet)
	{
		POSITION pos	= listRet.GetHeadPosition();
		while(pos != NULL)
		{
			delete listRet.GetNext(pos);
		}

		listRet.RemoveAll();
	};


	virtual ELEMENT *AddElement(ELEMENT &element)
	{
		return AddOccupant(element);
	};
	

	CGQuadTree(const AABB &startRegion)
		: QuadTree(startRegion)
	{
		m_dwAttr	= 0x00000000;
		m_rcRegion	= AABB(startRegion.lowerBound, startRegion.upperBound);
		m_fMaxSegmentLength	= 0;
	};

	~CGQuadTree()
	{
		
	};
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	@brief
		- multi quadtree
		- �������� quadtree�� ���� �� �ִ�.
		- quadtree merge�� �����ϴ�.
*/
template<class ELEMENT>
class CGMultiQuadTree :
	public CGQuadTree<ELEMENT>
{
public:
	/**
		@brief
			- quadtree�� serialize�Ѵ�.
	*/
	//void Serialize(CArchive &ar)
	//{
	//	INT32 iFlag	= 0;

	//	INT32 iCount	= 0;
	//	if(ar.IsStoring())
	//	{
	//		ar << iFlag;
	//		__super::Serialize(ar);

	//		ar << m_nMaxElement;	// quadtree�� �ִ� element����
	//		ar << m_nCountElement;	// ��ü element ����

	//		iCount	= m_listSubQuadTree.GetCount();
	//		ar << iCount;
	//		
	//		CGQuadTree *p	= NULL;
	//		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
	//		while(pos != NULL)
	//		{
	//			p	= m_listSubQuadTree.GetNext(pos);
	//			p->Serialize(ar);
	//		}
	//	}
	//	else
	//	{
	//		ar >> iFlag;
	//		__super::Serialize(ar);

	//		ar >> m_nMaxElement;	// quadtree�� �ִ� element����
	//		ar >> m_nCountElement;	// ��ü element ����

	//		iCount	= m_listSubQuadTree.GetCount();
	//		ar >> iCount;

	//		InitSubQuadTree();
	//		for(INT32 ix = 0; ix < iCount; ++ix)
	//		{
	//			CGQuadTree *pQuadTree	= new CGQuadTree(AABB(0, 0, 0, 0));
	//			pQuadTree->Serialize(ar);
	//			AddSubQuadTree(pQuadTree);
	//		}
	//	}
	//};

	/**
		@brief
			- sub quadtree�� �߰��Ѵ�.
	*/
	void AddSubQuadTree( CGQuadTree *pSubQuadTree )
	{
		if(!pSubQuadTree)
			return;

		pSubQuadTree->SetAttr(GetAttr());
		pSubQuadTree->SetMaxLevel(m_nMaxLevel);
		pSubQuadTree->SetGrowSizeOccupants(m_nGrowSizeOccupants);
		pSubQuadTree->SetGuid(GetGuid());
		pSubQuadTree->SetMaxSegmentLength(m_fMaxSegmentLength);
		pSubQuadTree->SetPath(GetPath());

		// sub quadtree�� �߰��Ѵ�.
		m_listSubQuadTree.AddTail(pSubQuadTree);
	};

	void GetAllNode(CAtlList<QuadTreeNode<ELEMENT>*> &listRet)
	{
		__super::GetAllNode(listRet);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->GetAllNode(listRet);
		}
	};

	void GetAllInFileNode(CAtlList<QuadTreeNode<ELEMENT>*> &listRet)
	{
		__super::GetAllInFileNode(listRet);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->GetAllInFileNode(listRet);
		}
	};
		
	// �޸𸮿� loading�� node�� ��� ������.
	void GetAllInMemoryNode(CAtlList<QuadTreeNode<ELEMENT>*> &listRet)
	{
		__super::GetAllInMemoryNode(listRet);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->GetAllInMemoryNode(listRet);
		}
	};
		
	// ��� node�� ���Ϸ� �����Ѵ�.
	void SaveFileAllNode()
	{
		__super::SaveFileAllNode();

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->SaveFileAllNode();
		}
	};

	void FindElementByRegion(const AABB &rc, CAtlList<CGQuadTreeElement*> &listRet)
	{
		__super::FindElementByRegion(rc, listRet);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->FindElementByRegion(rc, listRet);
		}
	};

	void FindElementBySeg(const Vec2f &xy1, const Vec2f &xy2, CAtlList<CGQuadTreeElement*> &listRet)
	{
		__super::FindElementBySeg(xy1, xy2, listRet);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->FindElementBySeg(xy1, xy2, listRet);
		}
	};

	void FindElementByPos(const Vec2f &xy, CAtlList<CGQuadTreeElement*> &listRet)
	{
		__super::FindElementByPos(xy, listRet);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->FindElementByPos(xy, listRet);
		}
	}
	bool IsExistElement()
	{
		if(__super::IsExistElement())
			return TRUE;

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			if(m_listSubQuadTree.GetNext(pos)->IsExistElement())
				return TRUE;
		}

		return FALSE;
	};

	virtual ELEMENT *AddElement(ELEMENT &element)
	{
		// sub quadtree�� ������ ��ü ����
		m_nCountElement++;


		// �ִ� element������ ������ �������� ���Ϸ� �����ϰ� sub quadtree�� �߰��Ѵ�.
		CGQuadTree *pCurQuadtree	= this;
		if(m_listSubQuadTree.GetCount() > 0)
			pCurQuadtree	 = m_listSubQuadTree.GetTail();
		if(!pCurQuadtree)
			pCurQuadtree	= this;

		if(pCurQuadtree->GetCountElement() == m_nMaxElement)
		{
			// ���ο� sub quadtree�� ���涧�� ���������� ����� quadtree�� ���Ϸ� �����Ѵ�.
			if(m_listSubQuadTree.GetCount() > 0)
			{
				m_listSubQuadTree.GetTail()->SaveFileAllNode();
			}
			else
			{
				__super::SaveFileAllNode();
			}

			CGQuadTree *pNewQuadTree	= new CGQuadTree(m_rcRegion);
			AddSubQuadTree(pNewQuadTree);
		}


		// sub quadtree�� �ִٸ� ������ sub quadtree�� �߰��Ѵ�.
		if(m_listSubQuadTree.GetCount() > 0)
		{
			return m_listSubQuadTree.GetTail()->AddElement(element);
		}
		else
		{
			return __super::AddElement(element);
		}

		return NULL;
	};
	
	void SetMaxElement(const INT32 &nMaxElement)
	{
		m_nMaxElement	= nMaxElement;
	};

	INT32 GetCountAllElement() const
	{
		return m_nCountElement;
	};
	
private:
	void FindElementByAttr(const DWORD32 &dwAttr, CAtlList<CGQuadTreeElement*> &listRet)
	{
		__super::FindElementByAttr(dwAttr, listRet);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			m_listSubQuadTree.GetNext(pos)->FindElementByAttr(dwAttr, listRet);
		}
	};

	/**
		@brief
			- ��� quadtree�� �����´�.
	*/
	void GetAllQuadTree(CAtlArray<CGQuadTree*> &arrQuadTree)
	{
		arrQuadTree.RemoveAll();
		arrQuadTree.FreeExtra();
		arrQuadTree.SetCount(m_listSubQuadTree.GetCount() + 1);
		

		INT32 iIdx	= 0;
		arrQuadTree.SetAt(iIdx++, this);

		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			arrQuadTree.SetAt(iIdx++, m_listSubQuadTree.GetNext(pos));
		}
	};

	void InitSubQuadTree()
	{
		POSITION pos	= m_listSubQuadTree.GetHeadPosition();
		while(pos != NULL)
		{
			delete m_listSubQuadTree.GetNext(pos);
		}

		m_listSubQuadTree.RemoveAll();
		m_nCountElement	= 0;
	};

	CAtlList<CGQuadTree*> m_listSubQuadTree;
	INT32 m_nMaxElement;	// quadtree�� �ִ� element����
	INT32 m_nCountElement;	// ��ü element ����
	


public:
	CGMultiQuadTree(const AABB &startRegion) :
		CGQuadTree(startRegion)
	{
		m_nMaxElement	= 1000000;
		m_nCountElement	= 0;
	};

	virtual ~CGMultiQuadTree(void)
	{
		InitSubQuadTree();
	};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////