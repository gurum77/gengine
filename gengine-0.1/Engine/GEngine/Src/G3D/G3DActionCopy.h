#pragma once
#define ACTION_COPY	GNOTRANS("COPY")
/**
	@brief
		- copy action
*/
class G_EXT_CLASS CG3DActionCopy :
	public CG3DActionMove
{
protected:
	virtual void Run();
	void CopySelectedObject();

public:
	GDEFINE_REGISTE_ACTION(CG3DActionCopy, ACTION_COPY);
	CG3DActionCopy(void);
	virtual ~CG3DActionCopy(void);
};

