#pragma once

/**
	@brief
		- object ���� ������.
		- object�� ���û�Ȳ�� �����Ѵ�.
*/
class G_EXT_CLASS CGSelectionManager
{
public:
	enum Attr
	{
		eAttrDynamicHighlight	= 0x00000001,	// dynamic highlight
		eAttrSelectAllSubObject	= 0x00000002	// sub object�� ��� �Բ� �����ϴ���?
	};
	void Select(CGObjectBase &object);
	void Select(CAtlArray<CGObjectBase*> &arrObject);
	void UnSelect(CGObjectBase &object);
	void UnselectAll(CAtlArray<CGObjectBase*> *pArrExcludeObject=NULL);
	bool IsSelected(CGObjectBase &object);
	void Redraw();
	void SetView(CG3DView *pView);

	void SetViewLayerName(const CAtlString &strViewLayerName);
	const CAtlString &GetViewLayerName() const;
	
	void SetPickBoxSize(const size_t &pickBoxSize);
	const size_t &GetPickBoxSize() const;

	void SetAttr(const Attr &eAttr, const bool &bSet);
	bool IsAttr(const Attr &eAttr) const;

	void GetAllObject(GOUT CAtlArray<CGObjectBase*> &arrObject);
	CGObjectBase *GetFirstRootObject();

private:
	CAtlString m_strViewLayerName;
	CAtlMap<GID, bool> m_mapSelectedObject;
	CG3DView *m_pView;
	CGColor m_color;
	size_t m_pickBoxSize;	// ���콺 ���ý� pickbox size
	DWORD32 m_dwAttr;

public:
	CGSelectionManager();
	~CGSelectionManager();
};

