#pragma once
class CG3DDB;
class CGDC;

/**
	@brief
		- G3Dview init data
		- view�� ���� ȯ�� ������ �� �� �ִ�.
*/
class G_EXT_CLASS CG3DViewInitData :
	public CGDCTargetViewInitData
{
public:

	// object�� �׸��� ���
	enum DrawObjectMethod
	{
		eDrawObjectMethodByObject,
		eDrawObjectMethodByPrimitiveTopologyByListVertexNoIndex,
		eDrawObjectMethodByPrimitiveTopologyByStripVertexListIndex
	};

	

	void SetDrawObjectMethod(const DrawObjectMethod &eDrawObjectMethod);
	const CG3DViewInitData::DrawObjectMethod &GetDrawObjectMethod() const;

	/**
		@brief
			- view layer�� �߰��Ѵ�.
			- �ݵ�� �̸��� �־�� �Ѵ�.
	*/
	void AddViewLayer(CG3DViewLayer *pViewLayer);
	INT32 GetViewLayerCount() const;
	CG3DViewLayer *GetViewLayer(const CAtlString &strName);
	void InitViewLayer();


	void SetDC(CGDC *pDC);
	CGDC *GetDC();

	void GetAllViewLayer(GOUT CAtlArray<CG3DViewLayer*> &arrViewLayer);

	
private:
	DrawObjectMethod m_eDrawObjectMethod;
	CAtlMap<CAtlString, CG3DViewLayer*> m_mapViewLayer;	// view layer
	CGDC *m_pDC;	// CG3DViewInitData�� Point�� �޴´�. (view���� �޸� ������ �ϸ� �ȵȴ�.)
	
public:
	GDEFINE_OPERATOR_COPY(CG3DViewInitData);
	CG3DViewInitData();
	~CG3DViewInitData();
};

