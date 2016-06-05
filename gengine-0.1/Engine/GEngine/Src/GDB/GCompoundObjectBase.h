#pragma once

/**
	@brief
		- 복합객체 base
		- 다양한 속성을 가질 수 있는 객체이다.
*/
class G_EXT_CLASS CGCompoundObjectBase :
	public CGObjectBase
{
	friend class CGDBAPI;

public:
	
	void InitAllSubObjectID();
	void InitAllSubObject();
	INT32 GetAllSubObjectIDCount() const;
	void GetAllSubObject(GOUT CAtlArray<CGObjectBase*> &arrAllSubObject);
	void AddSubObject(CGObjectBase *pObject);
	CAtlMap<GID, bool> &GetSubObjectIDList();
	

protected:
	virtual void GenerateSubObject() = 0;
	void GenerateSubObjectOfSubObject();
	CAtlMap<GID, bool> m_mapSubObjectID;

public:

	// CGCompoundObjectBase는 new를 정의 하지 않을 것이기 때문에 GDEFINE_REGISTE_OBJECT 를 직접 호출하지 않고 
	// GDEFINE_POOL, GDEFINE_OPERATOR_COPY을 각각 호출한다.
	GDEFINE_POOL(CGCompoundObjectBase)
	GDEFINE_OPERATOR_COPY(CGCompoundObjectBase);

	// CGCompoundObjectBase는 New를 정의하지 않는다.
	//GDEFINE_REGISTE_OBJECT(CGCompoundObjectBase)
	CGCompoundObjectBase(void);
	virtual ~CGCompoundObjectBase(void);
};

