#pragma once

class CG3DActionBase;
class CGObjectBase;
class CGDC;

/**
	@brief
		- drawing callback 정의
*/
typedef void(*G3D_DRAWING_CALLBACK)(CGDC *, const CGObjectBase *);


/**
	@brief
		- action을 create하는 callback 정의
*/
typedef CG3DActionBase*(*G3D_CREATING_ACTION_CALLBACK)();



