#pragma once
/**
	@brief
		- ��ü ������ �����ش�.
*/
class G_EXT_CLASS CGEditManager
{
public:
	void SetView(CG3DView *pView);
	void SetViewLayerName(const CAtlString &strViewLayerName);

	void MoveObject(GINOUT CAtlArray<CGObjectBase*> &arrObject, const CGPoint3D &ptSrc, const CGPoint3D &ptTar, const bool &bRedraw);
	void CopyObject(GINOUT CAtlArray<CGObjectBase*> &arrObject, const CGPoint3D &ptSrc, const CGPoint3D &ptTar, const bool &bRedraw);
	void Rotate2DObject(GINOUT CAtlArray<CGObjectBase*> &arrObject, const CGPoint2D &ptBase, const CGPoint2D &vAng, const bool &bRedraw);
	void ScaleObject(GINOUT CAtlArray<CGObjectBase*> &arrObject, const CGPoint2D &ptBase, const double &dScale, const bool &bRedraw);

private:
	CG3DView *m_pView;
	CAtlString m_strViewLayerName;

public:
	CGEditManager(void);
	~CGEditManager(void);
};

