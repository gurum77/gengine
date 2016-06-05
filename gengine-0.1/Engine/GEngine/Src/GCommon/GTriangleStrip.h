#pragma once



/**
	@brief
		- Triangle Strip Point의 한 점을 정의한 클래스이다.
		- 좌표와 법선방향을 가진다.
		- 조명을 제대로 받게 하기 위해서는 법선이 제대로 계산되어 있어야 한다.
*/
class G_EXT_CLASS CGTrianglePoint
{
public:
	void CopyToGVERTEX(GOUT GVERTEX &vertex) const;
	void SetPos(const CGPoint3D &ptPos);
	const CGPoint3D &GetPos() const;
	CGPoint3D &GetPos();
	gfloat3 GetFloat3() const;

	void SetNormal(const gfloat3 &f3Normal);
	const gfloat3 &GetNormal() const;

	void SetTex(const gfloat2 &f2Tex);
	const gfloat2 &GetTex() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CGPoint3D m_ptPos;
	gfloat3 m_f3Normal;		// triangle point의 normal은 랜더링 용이다. 구지 double 형으로 정의할 필요 없음(메모리 절약)
	gfloat2 m_f2Tex;	// texture 위치

public:
	GDEFINE_OPERATOR_COPY(CGTrianglePoint);
	CGTrianglePoint(const CGTrianglePoint &d);
	CGTrianglePoint(const CGPoint3D &d);
	CGTrianglePoint(const double &dXPos, const double &dYPos, const double &dZPos, const float &fXNormal, const float &fYNormal, const float &fZNormal);
	CGTrianglePoint(const double &dXPos, const double &dYPos, const double &dZPos, const float &fXNormal, const float &fYNormal, const float &fZNormal, const float &fXTex, const float &fYTex);
	CGTrianglePoint();
	
};

typedef CAtlArray<CGTrianglePoint> TriangleStripPoint;
typedef CAtlArray<UINT32> TriangleStripIndex;

/**
	@brief
		- 삼각망
*/
class G_EXT_CLASS CGTriangleStrip
{
public:
	void SetPos(const CAtlArray<CGPoint3D> &arrPos);
	void SetPoint(TriangleStripPoint &point);
	const TriangleStripPoint &GetPoint() const;
	TriangleStripPoint &GetPoint();

	void SetIndex(TriangleStripIndex &index);
	const TriangleStripIndex &GetIndex() const;
	TriangleStripIndex &GetIndex();

	void Transform(const CGPoint3D &ptFrom, const CGPoint3D &ptTo, const CGVector3D &vAxisFrom, const CGVector3D &vAxisTo);
	void Transform(const CGPoint3D &ptFrom, const CGPoint3D &ptTo, const CGVector3D &vAxisXFrom, const CGVector3D &vAxisYFrom, const CGVector3D &vAxisXTo, const CGVector3D &vAxisYTo);
	void Move(const CGPoint3D &ptFrom, const CGPoint3D &ptTo);
	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	TriangleStripPoint m_point;
	TriangleStripIndex m_index;

public:
	GDEFINE_OPERATOR_COPY(CGTriangleStrip)
	CGTriangleStrip();
	~CGTriangleStrip();
};

