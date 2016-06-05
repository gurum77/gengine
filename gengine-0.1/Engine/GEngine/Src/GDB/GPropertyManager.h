#pragma once

/**
	@brief
		- property 관리하는 클래스
*/
class G_EXT_CLASS CGPropertyManager
{
public:
	void InitProperty(const bool &bCreateDefaultProperty = TRUE);
	
	bool SetObjectMaterial(GINOUT CGObjectBase *pObj, const CAtlString &strMaterialName);
	bool SetObjectColor(GINOUT CGObjectBase *pObj, const INT32 &iObjectCount, const CGColor &color);
	bool SetObjectColor(GINOUT CGObjectBase *pObj, const CGColor &color);
	void Optimize(CG3DDB *pDB);

	CGProperty *FindPropertyByID(const GID &ID);
	void AddProperty(CGProperty *pProperty);

private:
	void CreateDefaultProperty();
	CGProperty *FindPropertyByString(const CAtlString &strProperty);
	CGProperty *GetValidObjectProperty(CGObjectBase *pObj);
	void ChangeObjectPropertyID(CG3DDB *pDB, const GID &oldPropertyID, const GID &newPropertyID);
	CGProperty *ClonePropertyByID(const GID &ID);
	

	CGIDManager m_IDManager;
	CAtlMap<GID, CGProperty*> m_mapPropertyWithID;
	CAtlMap<CAtlString, CGProperty*> m_mapPropertyWithString;
	
public:
	CGPropertyManager();
	~CGPropertyManager();
};

