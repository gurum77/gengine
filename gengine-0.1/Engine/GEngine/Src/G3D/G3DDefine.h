#pragma once

class CG3DActionBase;
class CGObjectBase;
class CGDC;

/**
	@brief
		- drawing callback ����
*/
typedef void(*G3D_DRAWING_CALLBACK)(CGDC *, const CGObjectBase *);


/**
	@brief
		- action�� create�ϴ� callback ����
*/
typedef CG3DActionBase*(*G3D_CREATING_ACTION_CALLBACK)();



