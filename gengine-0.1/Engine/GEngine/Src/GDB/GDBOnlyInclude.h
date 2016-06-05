// tool
#include "GGeometryGenerator.h"


// Object를 정의할때 object를 정상적으로 사용할 수 있도록 하는 역할을 한다.
#define GDEFINE_REGISTE_OBJECT(class_name)\
	virtual CGObjectBase *NewObject() { return GPOOL_NEW(class_name); };\
	virtual CGObjectBase& operator=(const CGObjectBase &d) { *((class_name*)this) = ((class_name&)d); return *this; };\
	GDEFINE_POOL(class_name)\
	GDEFINE_OPERATOR_COPY(class_name)\

#define GIMPLEMENT_REGISTE_OPERATOR(operator_class_name, object_type_name)\
	CGObjectOperatorManager::AddOperator(object_type_name, new operator_class_name)\


// texture
#include "GTextureItem.h"
#include "GTextureManager.h"
#include "GTextureCoord.h"
#include "GTextureCoordManager.h"

// material
#include "GMaterialItem.h"
#include "GMaterialManager.h"

// light
#include "GLightBase.h"

// object base
#include "GObjectBase.h"
#include "GCompoundObjectBase.h"
#include "GLightManager.h"


// object
#include "GObjectPoint2D.h"
#include "GObjectLine2D.h"
#include "GObjectPolyline2D.h"
#include "GObjectPolyline3D.h"
#include "GObjectTriangleStrip.h"
#include "GObjectCylinder.h"
#include "GObjectSphere.h"
#include "GObjectBox.h"
#include "GObjectCircle3D.h"
#include "GObjectCar.h"
#include "GObjectText.h"
#include "GObjectFace.h"
#include "GObjectProxy.h"

// define
#include "DefineGDBParams.h"

// object manager
#include "GObjectManager.h"

// property
#include "GProperty.h"
#include "GPropertyManager.h"


// font manager
#include "GFontManager.h"

// object operator
#include "GObjectOperatorBase.h"
#include "GObjectOperatorManager.h"

// db
#include "G3DDB.h"

// API
#include "GDBAPI.h"


