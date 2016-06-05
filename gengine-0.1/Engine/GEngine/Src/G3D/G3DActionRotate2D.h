#pragma once
#define ACTION_ROTATE2D	GNOTRANS("ROTATE2D")
/**
	@brief
		- rotate action
*/
class G_EXT_CLASS CG3DActionRotate2D :
	public CG3DActionMove
{
protected:
	virtual void Run();
	virtual void MoveTempObject();
	void RotateSelectedObject();

public:
	GDEFINE_REGISTE_ACTION(CG3DActionRotate2D, ACTION_ROTATE2D);
	CG3DActionRotate2D(void);
	virtual ~CG3DActionRotate2D(void);
};

