#pragma once

// memory pool ����ؼ� new, delete�� �ϴ� ��� ����Ѵ�.
//#define USE_BOOST_POOL

#include "intsafe.h"
#include "assert.h"
#include "atlstr.h"
#ifdef USE_BOOST_POOL
#include "boost/pool/pool.hpp"
#endif

#define G_EXT_CLASS __declspec(dllexport)

const float GPi = 3.1415926535f;

// parameter�� Out / InOut�� ��� ����Ѵ�. ������ In���� ����
#define GOUT
#define GINOUT

#define GNONE_ID	0	// 0�� ID�� ������ �ǹ��Ѵ�.
#define GFIRST_ID	1	// ù��° ID�� 1
#define GDEFAULT_BUFFER_ITEM_ID	GFIRST_ID	// �⺻ buffer item id

#define GDEFAULT_TEXTURE GNOTRANS("")	// �⺻ Texture �̸�
#define GDEFAULT_MATERIAL GNOTRANS("")	// �⺻ material �̸�

#define GID UINT32

#define GSAFE_DELETE(a)\
	if(a)\
																							{\
		delete a;\
		a = 0;\
																							}\

#define GNOTRANS(a) _T(a)
#define GASSERT(a) assert(a);
#define GIMPLEMENT_OPERATOR_COPY_SUPER __super::operator =(d);
#define GIMPLEMENT_OPERATOR_COPY(value) value = d.value;
#define GIMPLEMENT_OPERATOR_COPY_ARRAY(value, class) GArrayCopy(&value, (void*)&d.value, (class*)0);
#define GIMPLEMENT_OPERATOR_COPY_BEGIN(class) class& class::operator=(const class &d) {
#define GIMPLEMENT_OPERATOR_COPY_END return *this; }
#define GDEFINE_OPERATOR_COPY(class)  virtual class& operator=(const class &d);
#define GDEFINE_OPERATOR_COPY_NOVIRTUAL(class)  class& operator=(const class &d);

#define GIMPLEMENT_OPERATOR_EQUAL_SUPER if((__super::operator ==(d)) == false) return false;
#define GIMPLEMENT_OPERATOR_EQUAL(value) if((value == d.value) == false) return false;
#define GIMPLEMENT_OPERATOR_EQUAL_BEGIN(class) bool class::operator==(const class &d) {
#define GIMPLEMENT_OPERATOR_EQUAL_END return true; }
#define GDEFINE_OPERATOR_EQUAL(class)  bool operator==(const class &d);




#ifdef USE_BOOST_POOL

	// GDEFINE_POOL�� ����ϴ� ��� new, delete �����ڸ� ȣ���ϸ� �����ϴ�. GPOOL_NEW, GPOOL_DELETE�� ����ϼ���.
	#define GDEFINE_POOL(class)\
		static class* newdelete(bool bNew, class *p);\
		void* operator new(size_t s);\
		void operator delete(void *p);\
		static void releasememory();

	#define GIMPLEMENT_POOL(class)\
		static boost::pool<> class##_bpool(sizeof(class));\
		class* class::newdelete(bool bNew, class *p)\
		{\
			\
			if (bNew)\
			{\
				p = (class*)class##_bpool.malloc();\
				p->class::class();\
				return p;\
			}\
			p->class::~class();\
			class##_bpool.free(p);\
			\
			return 0;\
			\
		}\
			\
		void* class::operator new(size_t s)\
		{\
			return (void*)class::newdelete(true, 0);\
		}\
			\
		void class::operator delete(void *p)\
		{\
			((class*)p)->newdelete(false, (class*)p);\
		}\
		void class::releasememory()\
		{\
			class##_bpool.release_memory(); \
		}

	#define GPOOL_NEW(class) class::newdelete(true, 0);
	#define GPOOL_DELETE(p) delete p;
	// GPOOL_RELEASE�� �ϱ� ������ ������ �޸𸮸� ���������� �ʴ´�. �� �Ҵ�� ��� �Ҵ��ϱ� ���� chunk�� �����Ѵ�.
	// GPOOL_RELEASE�� �ϸ� ������ �޸𸮸� �����Ѵ�.
	#define GPOOL_RELEASE(class) class::releasememory();
#else
	#define GDEFINE_POOL(class)
	#define GIMPLEMENT_POOL(class)
	#define GPOOL_NEW(class) new class;
	#define GPOOL_DELETE(p) delete p;
	#define GPOOL_RELEASE(class)
#endif




/**
	@brief
		- ���� ������ ����
*/
enum PrimitiveTopology
{
	ePrimitiveTopologyNone,	// ���¾���
	ePrimitiveTopologyPoint,
	ePrimitiveTopologyLine,
	ePrimitiveTopologyTriangle,
	ePrimitiveTopologyCount
};
/**
	@brief
		- 2���� float��
*/
typedef struct  G_EXT_CLASS _gfloat2
{
	float x;
	float y;

	_gfloat2() : x(0.0f), y(0.0f) {};
	_gfloat2(float _x, float _y) : x(_x), y(_y) {};
	_gfloat2(const float *pArray);
	_gfloat2& operator=(const _gfloat2 &f2);
	GDEFINE_OPERATOR_EQUAL(_gfloat2);
} gfloat2;

/**
	@brief
		- 3���� float��
*/
typedef struct  G_EXT_CLASS _gfloat3
{
	float x;
	float y;
	float z;

	_gfloat3() : x(0.0f), y(0.0f), z(0.0f) {};
	_gfloat3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
	_gfloat3(const float *pArray);
	_gfloat3& operator=(const _gfloat3 &f3);
	GDEFINE_OPERATOR_EQUAL(_gfloat3);
} gfloat3;

/**
	@brief
		- 4���� float��
*/
typedef struct G_EXT_CLASS _gfloat4
{
	float x;
	float y;
	float z;
	float a;
	
	_gfloat4() : x(0.0f), y(0.0f), z(0.0f), a(0.0f) {};
	_gfloat4(float _x, float _y, float _z, float _a) : x(_x), y(_y), z(_z), a(_a) {};
	_gfloat4(const float *pArray);
	_gfloat4& operator=(const _gfloat4 &f4);
	_gfloat4& operator=(const gfloat3 &f3);
} gfloat4;

/**
@brief
- 2���� double��
*/
typedef struct G_EXT_CLASS _gdouble2
{
	double x;
	double y;

	_gdouble2() : x(0.0), y(0.0) {};
	_gdouble2(double _x, double _y) : x(_x), y(_y) {};
	_gdouble2(const double *pArray);
	_gdouble2& operator=(const _gdouble2 &d2);
} gdouble2;

/**
	@brief
		- 3���� double��
*/
typedef struct G_EXT_CLASS _gdouble3
{
	double x;
	double y;
	double z;

	_gdouble3() : x(0.0), y(0.0), z(0.0) {};
	_gdouble3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {};
	_gdouble3(const double *pArray);
	_gdouble3& operator=(const _gdouble3 &d3);
} gdouble3;

/**
	@brief
		- 4���� double��
*/
typedef struct G_EXT_CLASS _gdouble4
{
	double x;
	double y;
	double z;
	double w;

	_gdouble4() : x(0.0), y(0.0), z(0.0), w(0.0) {};
	_gdouble4(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w) {};
	_gdouble4(const double *pArray);
	_gdouble4& operator=(const _gdouble4 &d4);
} gdouble4;


/**
	@brief
		- vertex buffer�� ���� vertex�� Ÿ��
		- ����
			- �պκ��� ����Ÿ ������ input layout�� ������ �����ؾ� �Ѵ�.
	@todo
		- vertex���� ������ ���� �� �ֵ��� �ؾ� �ϴ��� �����ؼ� �����Ѵ�.
	@brief
		- vertex type �� �����Ѵ�.
*/
struct G_EXT_CLASS GVERTEX
{
	gfloat3 pos;	// ��ǥ
	gfloat3 normal;	// normal
	gfloat2 tex;	// texture
	gfloat3 color;	// color(RGBA)
	UINT id;		// object �� id

	GVERTEX()
	{
		normal.z	= -1;
		id	= GNONE_ID;
	}

	// GVERTEX�� operator�� �����Լ��� ����� �ȵ�.... �ֱ׷��� �𸣰ڳ�..
	GDEFINE_OPERATOR_COPY_NOVIRTUAL(GVERTEX);
};

