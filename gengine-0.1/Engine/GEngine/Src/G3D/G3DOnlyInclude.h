#define GIF_NO_DC_TARGET_VIEW	if(!m_pDCTargetView) { return; }
#define GIF_NO_DC_TARGET_VIEW_RETURN(a)	if(!m_pDCTargetView) { return(a); }

#define GIF_NO_DB	if(!m_pDB) { return; }
#define GIF_NO_DC	if(!m_pDC) { return; }
#define GIF_NO_DB_RETURN(a)	if(!m_pDB) { return a; }
#define GIF_NO_DC_RETURN(a)	if(!m_pDC) { return a; }

// CGPoint3D를 XMVECTOR로 변환
#define GPOINT3D_TO_XMVECTOR(a) XMVectorSet(a.GetXf(), a.GetYf(), a.GetZf(), 1.0f)

// CGVector3D를 XMVECTOR로 변환
#define GVECTOR3D_TO_XMVECTOR(a) XMVectorSet(a.GetXf(), a.GetYf(), a.GetZf(), 0.0f)

#include "windows.h"

#include "GCamera.h"
#include "GFog.h"
#include "GDCInitData.h"
#include "GDCTargetViewInitData.h"
#include "G3DViewLayer.h"
#include "G3DViewInitData.h"


#include "GDCTargetView.h"
#include "GDCBufferLayerItemIdentifier.h"
#include "GDC.h"


#include "GDirectX11Util.h"
#include "GDCDirectX11TextureItem.h"
#include "GDCDirectX11TextureManager.h"
#include "GDCDirectX11MaterialItem.h"
#include "GDCDirectX11MaterialManager.h"
#include "GDCDirectX11LightManager.h"
#include "GDCDirectX11TargetView.h"
#include "GDCDirectX11BufferLayerItem.h"
#include "GDCDirectX11BufferLayer.h"
#include "GDCDirectX11.h"

// drawing callback
#include "G3DDefine.h"
#include "G3DCallBackDrawingObject.h"
#include "G3DCallBackManager.h"

// view
#include "G3DView.h"

// space view
#include "GSpace.h"
#include "GSpaceManager.h"
#include "G3DSpaceView.h"

// seelction manager
#include "GSelectionManager.h"

// edit manager
#include "GEditManager.h"

// action
#define GDEFINE_REGISTE_ACTION(class_name, action_name)\
	virtual CAtlString GetStrType() { return action_name; };\
	static CG3DActionBase* Create##class_name() { return (CG3DActionBase*)(new class_name); }\

#define GIMPLEMENT_REGISTE_ACTION(class_name, action_name)\
	CG3DCallBackManager::AddCreatingActionCallBack(action_name, class_name::Create##class_name)\


// command bar text의 헤더
#define COMANDTEXT_HEADER GNOTRANS("Command : ")

// command bar
#include "GCommandBarBase.h"

// action
#include "G3DActionBase.h"
#include "G3DActionSelect.h"
#include "G3DActionCreateLine.h"
#include "G3DActionCreateCircle.h"
#include "G3DActionMove.h"
#include "G3DActionCopy.h"
#include "G3DActionRotate2D.h"
#include "G3DActionScale.h"

#include "G3DActionManager.h"

// API
#include "G3DAPI.h"

// Test
#include "G3DTest.h"
