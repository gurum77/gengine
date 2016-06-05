#pragma once

class G_EXT_CLASS CGObjectOperatorManager
{
public:
	static void InitOperator();
	static CGObjectOperatorBase *FindOperatorByObjectType(const CAtlString &strType);
	static void AddOperator(const CAtlString &strType, CGObjectOperatorBase *pOp);

private:
	static CAtlMap<CAtlString, CGObjectOperatorBase*> m_mapOpeator;

public:
	CGObjectOperatorManager();
	~CGObjectOperatorManager();
};

