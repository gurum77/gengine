#pragma once

class CDC;
class CGObjectBase;



/**
	@brief
		- callback manager
			- drawing callback
*/
class G_EXT_CLASS CG3DCallBackManager
{
public:
	static bool AddDrawingCallBack(const CAtlString &strType, G3D_DRAWING_CALLBACK pf);
	static G3D_DRAWING_CALLBACK GetDrawingCallBack(const CGObjectBase &object);

	static bool AddCreatingActionCallBack(const CAtlString &strAction, G3D_CREATING_ACTION_CALLBACK pf);
	static G3D_CREATING_ACTION_CALLBACK GetCreateActionBallBack(const CAtlString &strAction);

	static void Init();

private:
	static CAtlMap<CAtlString, void*> m_mapDrawingCallBack;
	static CAtlMap<CAtlString, void*> m_mapCreatingActionCallBack;

public:
	CG3DCallBackManager();
	~CG3DCallBackManager();
};

