#pragma once

#define ACTION_CREATE_OLYMPIC_FLAG	GNOTRANS("CREATE OLYMPIC FLAG")

/**
	@brief
		- A action to create olympic flag for proxyobject example.
*/
class G_EXT_CLASS CG3DActionCreateOlympicFlag :
	public CG3DActionCreateLine
{
protected:
	virtual void CreatePreviewObject();
	void CreateNewObject();
public:
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);

public:
	GDEFINE_REGISTE_ACTION(CG3DActionCreateOlympicFlag, ACTION_CREATE_OLYMPIC_FLAG);

public:
	CG3DActionCreateOlympicFlag(void);
	~CG3DActionCreateOlympicFlag(void);
};

