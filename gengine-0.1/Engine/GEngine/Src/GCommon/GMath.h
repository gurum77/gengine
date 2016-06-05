#pragma once

/**
	@brief
		- frustrum plane 
*/
enum FrustrumPlane
{
	eFrustrumPlaneTop,
	eFrustrumPlaneBottom,
	eFrustrumPlaneNear,
	eFrustrumPlaneFar,
	eFrustrumPlaneLeft,
	eFrustrumPlaneRight,
	eFrustrumPlaneCount
};

/**
	@brief
		- 간단한 수학 계산관련 
		- 입력값에 대한 예외처리는 하지 않는다.
			- 속도위주의 함수들이기 때문
			- caller가 예외처리를 해야함(여기서 예외처리 함수를 제공할 수는 있다)
*/
class G_EXT_CLASS CGMath
{
public:
	static bool MatchLine2DAndLine2D(const CGPoint2D &ptLinePos1, const CGVector2D &vLineDir1, const CGPoint2D &ptLinePos2, const CGVector2D &vLineDir2, GOUT CGPoint2D &ptMatch);
	static bool MatchPlaneAndLine(const CGPoint3D &ptPlanePos, const CGVector3D &vPlaneNormal, const CGPoint3D &ptLinePos, const CGVector3D &ptLineDir, GOUT CGPoint3D &ptMatch);
	static CGVector2D RadianToVector(const double &dRadian);
	static CGVector2D DegreeToVector(const double &dDegree);
	static CGVector3D RadianToVector3D(const double &dRadian);
	static double DegreeToRadian(const double &dDegree);
	
	static double RadianToDegree(const double &dRadian);
	static double VectorToDegree(const CGPoint2D &vAng);
	static double VectorToRadian(const CGPoint2D &vAng);
	static void Transform(CGPoint3D *pPos, const size_t &uSizePos, const CGPoint3D &ptFrom, const CGPoint3D &ptTo, const CGVector3D &vAxisXFrom, const CGVector3D &vAxisYFrom, const CGVector3D &vAxisXTo, const CGVector3D &vAxisYTo);
	static void TransformByMatrix(GINOUT CGPoint3D &pos, const CGMatrix &mat);
	static CGVector3D PerpendicularOfVector(const CGVector3D &v);
	static CGVector3D NormalOf2Axis(const CGVector3D &vAxis1, const CGVector3D &vAxis2);
	static CGPoint3D PerpendicularFromPointToLine(const CGPoint3D &ptFrom, const CGPoint3D &ptLine, const CGVector3D &vDirLine);
	static CGPoint2D PerpendicularFromPointToLine(const CGPoint2D &ptFrom, const CGPoint2D &ptLine, const CGVector2D &vDirLine);
	static void PlaneFrom3Point(const CGPoint3D &pt1, const CGPoint3D &pt2, const CGPoint3D &pt3, GOUT CGPlane &plane);
	static double PlaneDotPoint(const CGPlane &plane, const CGPoint3D &pt);
	static double PlaneDotXYZ(const CGPlane &plane, const float &fX, const float &fY, const float &fZ);
	static bool PlaneFrustrumFromXYRateAndViewProjMatrixInverse(const float &fLeft, const float &fTop, const float &fRight, const float &fBottom, const CGMatrix &matViewProjInv, GOUT CGPlane *pPlaneFrustrum);
	static bool PolygonToTriangleStripByTriangulate(const CAtlArray<CGPolygon> &arrPolygon, GOUT CGTriangleStrip &triangleStrip);
	static bool PolygonToTriangleStripByPoly2Tri(const CAtlArray<CGPolygon> &arrPolygon, GOUT CGTriangleStrip &triangleStrip);
	static bool PolygonToTriangleStrip(const CAtlArray<CGPolygon> &arrPolygon, GOUT CGTriangleStrip &triangleStrip);
	
	// boundary
	static CGRect BoundaryFromPointArray(const CAtlArray<CGPoint3D> &arrPoint);
	
	// CCw
	static bool IsCCW2D(const CGPoint2D &pt1, const CGPoint2D &pt2, const CGPoint2D &pt3);

	// matrix
	static void MatrixTransform(GOUT CGMatrix &matTransform, const CGPoint3D &ptFrom, const CGPoint3D &ptTo, const CGVector3D &vAxisXFrom, const CGVector3D &vAxisYFrom, const CGVector3D &vAxisXTo, const CGVector3D &vAxisYTo);
	static void MatrixIdentity(GOUT CGMatrix &mat);
	static void MatrixAffineTransformation(GOUT CGMatrix &matTransform, const CGPoint3D &ptOrigin, const CGVector3D &vScale, const CGVector3D &vRotateAxis, const double &dRotateAngleRadian, const CGVector3D &vMove);
	static void MatrixFromXMMATRIX(GOUT CGMatrix &mat, const void *pMatrix);

	// include
	static bool IncludePointInSegment(const CGPoint3D &pt, const CGPoint3D &ptSeg1, const CGPoint3D &ptSeg2, const double &dTol=0.0001);
	static bool IncludePointInSegment(const CGPoint2D &pt, const CGPoint2D &ptSeg1, const CGPoint2D &ptSeg2, const double &dTol=0.0001);

	// intersect 관련 함수
	static bool IntersectXYZFrustrum(const float &fX, const float &fY, const float &fZ, const CGPlane *pPlaneFrustrum);
	static bool IntersectSegmentRectangle(const CGPoint2D &ptSeg1, const CGPoint2D &ptSeg2, const CGPoint2D &ptRectCenter, const double &dRectWidthHalf, const double &dRectHeightHalf, GOUT double *pdDist);
	static bool IntersectSphereFrustrum(const float &fX, const float &fY, const float &fZ, const float &fRadius, const CGPlane *pPlaneFrustrum);

	// equal
	static bool Equal(const double &d1, const double &d2, const double &dTol=0.00001);
	public:
	CGMath();
	~CGMath();
};

