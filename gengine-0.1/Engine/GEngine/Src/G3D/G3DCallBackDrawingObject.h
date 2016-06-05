#pragma once
class CGDC;
class CGObjectBase;

/**
	@brief
		- drawing callback
			- line2d
*/
class CG3DCallBackDrawingObject
{
public:
	static void DrawObjectPoint2D(CGDC *pDC, const CGObjectBase *pObject);
	static void DrawObjectLine2D(CGDC *pDC, const CGObjectBase *pObject);
	static void DrawObjectPolyline2D(CGDC *pDC, const CGObjectBase *pObject);
	static void DrawObjectTriangleStrip(CGDC *pDC, const CGObjectBase *pObject);

public:
	CG3DCallBackDrawingObject();
	~CG3DCallBackDrawingObject();
};

