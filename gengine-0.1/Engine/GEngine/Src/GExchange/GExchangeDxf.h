#pragma once

/**
	@brief
		- dxf ���� import / export
*/
class G_EXT_CLASS CGExchangeDxf 
	: public CGExchangeBase
{
public:
	void Import(const CAtlString &strPathFileName, GOUT CG3DDB &db);
	void Export(const CAtlString &strPathFileName, const CG3DDB &db);

public:
	CGExchangeDxf(void);
	virtual ~CGExchangeDxf(void);
};

