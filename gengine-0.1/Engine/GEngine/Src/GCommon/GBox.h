#pragma once
/**
	@brief
		- Box
*/
class G_EXT_CLASS CGBox
{
public:
	void SetPos(const CGPoint3D &pt, const bool &bStt);
	const CGPoint3D &GetPos(const bool &bStt) const;

	void SetWidth(const float &fWidth);
	const float &GetWidth() const;

	void SetHeight(const float &fHeight);
	const float &GetHeight() const;

	double GetDepth() const;
	CGVector3D GetVector() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGVector3D &vAxis, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

private:
	CGPoint3D m_ptPos[2];
	float m_fWidth;
	float m_fHeight;

public:
	GDEFINE_OPERATOR_COPY(CGBox);
	CGBox();
	~CGBox();
};

