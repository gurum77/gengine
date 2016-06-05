#pragma once
/**
	@brief
		- G3D DLL에 대한 각종 테스트 함수
*/
class G_EXT_CLASS CG3DTest
{
public:
	enum Test
	{
		eTest_EqualObjectVertexInfoAndVertexBuffer	= 0x00000001,
		eTest_EqualSpaceAndBufferItem	= 0x00000002,
		eTest_EquanObjectNumOfSpaceManagerAndObjectNumOfSpace	= 0x00000004,
		eTest_EqualMapObjectByBufferItemIDAndObjectArray	= 0x00000008,
		eTest_All	= 0xFFFFFFFF
	};

public:
	static void Test_All(CG3DView *pView);
	static void Test_EqualObjectVertexInfoAndVertexBuffer(CG3DView *pView);
	static void Test_EqualSpaceAndBufferItem(CG3DView *pView);
	static void Test_EquanObjectNumOfSpaceManagerAndObjectNumOfSpace(CGSpaceManager *pSpaceMng);
	static void Test_EqualMapObjectByBufferItemIDAndObjectArray(const CAtlMap<GID, CAtlArray<CGObjectBase*>*> &mapObjectByBufferItemID, const CAtlArray<CGObjectBase*> &arrObject);

private:
	static bool IsEnableTest(Test eTest);
	static DWORD32 m_dwTest;
	
public:
	CG3DTest(void);
	~CG3DTest(void);
};

