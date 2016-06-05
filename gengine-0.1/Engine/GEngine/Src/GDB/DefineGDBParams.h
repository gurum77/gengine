#pragma once

class G_EXT_CLASS GetAllVertexParam
{
public:
	CAtlString m_strMaterialName;
	GetAllVertexParam()
	{
		m_strMaterialName = GDEFAULT_MATERIAL;
	}
};

class G_EXT_CLASS GetAllVertexByObjectParam
{
public:
	CAtlArray<CGObjectBase*> *m_pArrObject;
	CAtlString m_strMaterialName;

	GetAllVertexByObjectParam()
	{
		m_pArrObject = NULL;
		m_strMaterialName = GDEFAULT_MATERIAL;
	}

};

class G_EXT_CLASS GetAllVertexByPrimitiveTopologyParam
{
public:
	PrimitiveTopology m_ePrimitiveTopology;
	UINT32 m_iStartVertexOffset;
	CAtlArray<CGObjectBase*> *m_pArrObject;
	CAtlString m_strMaterialName;

	GetAllVertexByPrimitiveTopologyParam()
	{
		m_ePrimitiveTopology = ePrimitiveTopologyNone;
		m_iStartVertexOffset = 0;
		m_pArrObject = NULL;
		m_strMaterialName = GDEFAULT_MATERIAL;
	}
};

class G_EXT_CLASS GetAllStripVertexListIndexByPrimitiveTopologyParam
{
public:
	PrimitiveTopology m_ePrimitiveTopology;
	UINT32 m_iStartVertexOffset;
	UINT32 m_iStartIndexOffset;
	CAtlArray<CGObjectBase*> *m_pArrObject;
	CAtlString m_strMaterialName;

	GetAllStripVertexListIndexByPrimitiveTopologyParam()
	{
		m_ePrimitiveTopology = ePrimitiveTopologyNone;
		m_iStartIndexOffset = 0;
		m_iStartIndexOffset = 0;
		m_pArrObject = NULL;
		m_strMaterialName = GDEFAULT_MATERIAL;
	}
};

class G_EXT_CLASS MoveVertexBufferByDeletingObjectParam
{
public:
	UINT32 m_uVertexOffset;
	UINT32 m_uVertexCount;
	PrimitiveTopology m_ePrimitiveTopology;
	CAtlString m_strMaterialName;

	MoveVertexBufferByDeletingObjectParam()
	{
		m_uVertexOffset = 0;
		m_uVertexCount = 0;
		m_ePrimitiveTopology = ePrimitiveTopologyNone;
		m_strMaterialName = GDEFAULT_MATERIAL;
	}
};

class G_EXT_CLASS MoveIndexBufferByDeletingObjectParam
{
public:
	UINT32 m_uIndexOffset;
	UINT32 m_uIndexCount;
	PrimitiveTopology m_ePrimitiveTopology;
	CAtlString m_strMaterialName;

	MoveIndexBufferByDeletingObjectParam()
	{
		m_uIndexOffset = 0;
		m_uIndexCount = 0;
		m_ePrimitiveTopology = ePrimitiveTopologyNone;
		m_strMaterialName = GDEFAULT_MATERIAL;
	}

};

