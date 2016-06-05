#pragma once
class CG3DDB;
class CGDC;

/**
	@brief
		- G3Dview init data
		- view에 대한 환경 설정을 할 수 있다.
*/
class G_EXT_CLASS CG3DViewInitData :
	public CGDCTargetViewInitData
{
public:

	// object를 그리는 방법
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
			- view layer를 추가한다.
			- 반드시 이름이 있어야 한다.
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
	CGDC *m_pDC;	// CG3DViewInitData는 Point만 받는다. (view에서 메모리 해제를 하면 안된다.)
	
public:
	GDEFINE_OPERATOR_COPY(CG3DViewInitData);
	CG3DViewInitData();
	~CG3DViewInitData();
};

