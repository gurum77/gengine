#pragma once
#define ACTION_SCALE	GNOTRANS("SCALE")
/**
	@brief
		- scale action
*/
class G_EXT_CLASS CG3DActionScale :
	public CG3DActionMove
{
protected:
	virtual void Run();
	virtual void MoveTempObject();
	void ScaleSelectedObject();
	double GetScale() const;

public:
	GDEFINE_REGISTE_ACTION(CG3DActionScale, ACTION_SCALE);
	CG3DActionScale();
	virtual ~CG3DActionScale();
};

