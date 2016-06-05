#pragma once
#include "../../../../lib/DirectX11/Common/xnacollision.h"
/**
	@brief
		- ī�޶�
*/
class G_EXT_CLASS CGCamera
{
public:
	void SetTarget(const CGPoint3D &f3Target);
	const CGPoint3D &GetTarget() const;

	void SetEye(const CGPoint3D &f3Eye);
	const CGPoint3D &GetEye() const;

	void SetUp(const CGPoint3D &fUp);
	const CGPoint3D &GetUp() const;

	void SetWidth(const double &dWidth);
	const double &GetWidth() const;

	void SetHeight(const double &dHeight);
	const double &GetHeight() const;

	void ZoomIn(const CGPoint3D &ptOrgPos);
	void ZoomOut(const CGPoint3D &ptOrgPos);
	void ZoomPan(const CGPoint3D &ptLastPos, const CGPoint3D &ptCurPos);
	void ZoomAll(const CGCube &cubeBoundary);
	void ZoomRotate(const float &fRotateAngleUp, const float &fRotateAngleByHor);
	
	void SetPlaneFrustrum(const CGPlane &plane, const FrustrumPlane &eFrustrum);
	const CGPlane &GetPlaneFrustrum(const FrustrumPlane &eFrustrum) const;
	CGPlane &GetPlaneFrustrum(const FrustrumPlane &eFrustrum);

	void SetViewProjInv(const CGMatrix &matInv);
	const CGMatrix &GetViewProjInv() const;

	bool IsInSphere(const CGPoint3D &ptCenter, const double &dRadius) const;

	void SetPerspective(const bool &bPerspective);
	const bool &GetPerspective() const;

	void SetFovAngleY(const float &fFovAngleY);
	const float &GetFovAngleY() const;

private:
	void ZoomInOut(const CGPoint3D &ptOrgPos, const bool &bZoomIn);
	CGPoint3D m_ptTarget;
	CGPoint3D m_ptEye;
	CGPoint3D m_ptUp;
	double m_dWidth;
	double m_dHeight;

	// ����ü ����
	CGPlane m_planeFrustrum[eFrustrumPlaneCount];
	CGMatrix m_matViewProjInv;	// view * project�� �����

	bool m_bPerspective;	// perspective view ����?
	float m_fFovAngleY;	// ���� �þ߰�
	


public:
	CGCamera();
	~CGCamera();
};

