#pragma once
/**
	@brief
		- 3점을 통과하는 이루어진 arc
	@todo
		- 구현해야함.
*/
class G_EXT_CLASS CGArc3D
{
public:
	enum Pos
	{
		ePosStart,
		ePosMid,
		ePosEnd,
		ePosCount
	};
	void SetPos(const CGPoint3D &pt, const Pos &ePos);
	const CGPoint3D &GetPos(const Pos &ePos) const;

	CGPoint3D GetCenterPos() const;

private:
	CGPoint3D m_ptPos[ePosCount];

public:
	GDEFINE_OPERATOR_COPY(CGArc3D);
	CGArc3D();
	~CGArc3D();
};

