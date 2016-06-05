#pragma once

/**
	@brief
		- ���հ�ü base
		- �پ��� �Ӽ��� ���� �� �ִ� ��ü�̴�.
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

	// CGCompoundObjectBase�� new�� ���� ���� ���� ���̱� ������ GDEFINE_REGISTE_OBJECT �� ���� ȣ������ �ʰ� 
	// GDEFINE_POOL, GDEFINE_OPERATOR_COPY�� ���� ȣ���Ѵ�.
	GDEFINE_POOL(CGCompoundObjectBase)
	GDEFINE_OPERATOR_COPY(CGCompoundObjectBase);

	// CGCompoundObjectBase�� New�� �������� �ʴ´�.
	//GDEFINE_REGISTE_OBJECT(CGCompoundObjectBase)
	CGCompoundObjectBase(void);
	virtual ~CGCompoundObjectBase(void);
};

