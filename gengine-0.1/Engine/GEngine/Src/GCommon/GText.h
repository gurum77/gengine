#pragma once
/**
	@brief
		- text data
*/
class G_EXT_CLASS CGText
{
public:
	void SetText(const CAtlString &strText);
	const CAtlString &GetText() const;

	void SetPos(const CGPoint3D &ptBase);
	const CGPoint3D &GetPos() const;

	void SetAngle(const float &fAngle);
	const float &GetAngle() const;

	void Move(const CGVector3D &vMove);
	void Rotate(const CGPoint3D &ptBase, const CGPoint2D &vAng);
	void Scale(const CGPoint3D &ptBase, const double &dScale);

	INT32 GetCountString(const CAtlString &str) const;

private:
	CAtlString m_strText;
	CGPoint3D m_ptBase;
	float m_fAngle;

public:
	GDEFINE_OPERATOR_COPY(CGText);
	CGText(void);
	virtual ~CGText(void);
};

