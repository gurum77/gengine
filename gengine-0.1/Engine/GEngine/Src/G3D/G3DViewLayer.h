#pragma once

class CG3DDB;
/**
	@brief
		- view layer
*/
class G_EXT_CLASS CG3DViewLayer
{
public:
	void SetDB(CG3DDB *pDB);
	CG3DDB *GetDB();

	void SetName(const CAtlString &strName);
	CAtlString GetName() const;


private:
	CAtlString m_strName;	// view layer name
	CG3DDB *m_pDB;
	
	

public:
	
	GDEFINE_OPERATOR_COPY(CG3DViewLayer)
	CG3DViewLayer();
	~CG3DViewLayer();
};
