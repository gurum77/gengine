#pragma once
/**
	@brief
		- 다양한 타입의 값을 담을 수 있는 변수
*/
class G_EXT_CLASS CGVariantVariable
{
public:
	enum Type
	{
		eTypeInt32,
		eTypeDouble,
		eTypeFloat,
		eTypeString,
		eTypeBool
	};

	void SetDoubleValue(const double &dValue);
	void SetInt32Value(const INT32 &iValue);
	void SetFloatValue(const float &fValue);
	void SetStrValue(const CAtlString &strValue);
	void SetBoolValue(const bool &bValue);

	double GetDoubleValue() const;
	INT32 GetInt32Value() const;
	float GetFloatValue() const;
	CAtlString GetStrValue() const;
	bool GetBoolValue() const;
	
private:
	char m_chType;
	double m_dValue;
	CAtlString m_strValue;

public:
	GDEFINE_OPERATOR_EQUAL(CGVariantVariable);
	GDEFINE_OPERATOR_COPY(CGVariantVariable);
	CGVariantVariable(CGVariantVariable &d);
	CGVariantVariable(void);
	~CGVariantVariable(void);
};

