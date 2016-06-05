#pragma once
/**
	@brief
		- G3D�� DLL�� �ֿ� API
*/
class G_EXT_CLASS CG3DAPI
{
public:
	/**
		@brief
			- �߰��Ǵ� object�� object�� sub object�� rendering �Ѵ�.
	*/
	static void RenderAddedObjectAndSubObject(CG3DView &view, const CAtlString &strViewLayerName, CGObjectBase &object);
	
	/**
		@brief
			- �����Ǵ� object�� object�� sub object�� rendering �Ѵ�.
	*/
	static void RenderDeletingObjectAndSubObject(CG3DView &view, const CAtlString &strViewLayerName, CGObjectBase &object);


	/**
		@brief
			- Regen�� render�� �ϰ������� �Ѵ�.
	*/
	static void RegenAndRenderObjectAndSubObject(CG3DView &view, const CAtlString &strViewLayerName, CGObjectBase &object);

public:
	CG3DAPI(void);
	~CG3DAPI(void);
};

