#pragma once
class G_EXT_CLASS CGProxyVariable
{
public:
	bool SetDoubleVariable(const CAtlString &strName, const double &dValue);
	bool SetFloatVariable(const CAtlString &strName, const float &fValue);
	bool SetInt32Variable(const CAtlString &strName, const INT32 &iValue);
	bool SetStrVariable(const CAtlString &strName, const CAtlString &strValue);
	bool SetBoolVariable(const CAtlString &strName, const bool &bValue);

	bool IsExistVariableByName(const CAtlString &strName) const;

	double GetDoubleValueByName(const CAtlString &strName) const;
	float GetFloatValueByName(const CAtlString &strName) const;
	INT32 GetInt32ValueByName(const CAtlString &strName) const;
	CAtlString GetStrValueByName(const CAtlString &strName) const;
	bool GetBoolValueByName(const CAtlString &strName) const;

	void InitVariable();

private:
	CGVariantVariable *FindVariableByName(const CAtlString &strName);
	const CGVariantVariable *FindVariableByName(const CAtlString &strName) const;
	bool AddVariableByName(const CAtlString &strName, CGVariantVariable *p);
	CAtlMap<CAtlString, CGVariantVariable*> m_mapVar;

public:
	GDEFINE_OPERATOR_COPY(CGProxyVariable);
	GDEFINE_OPERATOR_EQUAL(CGProxyVariable);
	CGProxyVariable(void);
	~CGProxyVariable(void);
};

