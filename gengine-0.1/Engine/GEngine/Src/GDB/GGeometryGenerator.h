#pragma once
/**
	@brief
		- ������ ���� ����
		- Grid, box, cylinder, sphere���� triangle strip ���·� �����.
		- parameter 
			- dWidth : X ���� ũ��
			- dDepth : Y ���� ũ��
			- dHeight : Z ���� ũ��
*/
class G_EXT_CLASS CGGeometryGenerator
{
public:
	static bool GenerateGrid(const double &dWidth, const double &dDepth, const UINT32 &uM, const UINT32 &uN, GOUT CGTriangleStrip &triangleStrip);
	static bool GenerateBox(const double &dWidth, const double &dHeight, const double &dDepth, GOUT CGTriangleStrip &triangleStrip);
	static bool GenerateSphere(const double &dRadius, const UINT32 &uSliceCount, const UINT32 &uStackCount, GOUT CGTriangleStrip &triangleStrip);
	static bool GenerateCylinder(const double &dBottomRadius, const double &dTopRadius, const double &dHeight, const UINT32 &uSliceCount, const UINT32 &uStackCount, GOUT CGTriangleStrip &triangleStrip);
	static bool GenerateCircle(const double &dRadius, const UINT32 &uSliceCount, GOUT CAtlArray<CGPoint3D> &arrPolyline);
	static void ConvertTriangleStripToTriangleList(const CGTriangleStrip &triangleStrip, TriangleStripPoint &triangleList);
	
private:
	static void BuildCylinderTopCap(const double &dBottomRadius, const double &dTopRadius, const double &dHeight, const UINT32 &uSliceCount, const UINT32 &uStackCount, GOUT CGTriangleStrip &triangleStrip, const bool &bBottom=FALSE);
	static void BuildCylinderBottomCap(const double &dBottomRadius, const double &dTopRadius, const double &dHeight, const UINT32 &uSliceCount, const UINT32 &uStackCount, GOUT CGTriangleStrip &triangleStrip);

public:
	CGGeometryGenerator();
	~CGGeometryGenerator();
};

