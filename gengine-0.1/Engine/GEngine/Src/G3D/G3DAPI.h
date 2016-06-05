#pragma once
/**
	@brief
		- G3D의 DLL의 주요 API
*/
class G_EXT_CLASS CG3DAPI
{
public:
	/**
		@brief
			- 추가되는 object와 object의 sub object를 rendering 한다.
	*/
	static void RenderAddedObjectAndSubObject(CG3DView &view, const CAtlString &strViewLayerName, CGObjectBase &object);
	
	/**
		@brief
			- 삭제되는 object와 object의 sub object를 rendering 한다.
	*/
	static void RenderDeletingObjectAndSubObject(CG3DView &view, const CAtlString &strViewLayerName, CGObjectBase &object);


	/**
		@brief
			- Regen과 render를 일괄적으로 한다.
	*/
	static void RegenAndRenderObjectAndSubObject(CG3DView &view, const CAtlString &strViewLayerName, CGObjectBase &object);

public:
	CG3DAPI(void);
	~CG3DAPI(void);
};

