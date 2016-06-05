#pragma once
/**
	@brief
		- horizontal alignment
*/
class G_EXT_CLASS CGHorizontalAlignment
{
public:
	// Is
	bool IsMajorChain(const CGHorizontalAlignmentPoint &point);

	// get, set
	void AddElement(const CGHorizontalAlignmentElement &element);
	void InitElement();
	INT32 GetElementCount();
	CGHorizontalAlignmentElement *GetElement(const INT32 &iIdx);

	void SetStartStation(const double &dStartStation);
	const double &GetStartStation() const;

	void SetStartPos(const CGPoint2D &ptStartPos);
	const CGPoint2D &GetStartPos() const;
	CGPoint2D CalcEndPos() const;
	CGVector2D CalcEndDir() const;

	void SetDirectionPos(const CGPoint2D &ptDirectionPos);
	const CGPoint2D &GetDirectionPos() const;

	// calculate
	double CalcEndStation() const;
	double CalcLength() const;
	void CalcPosArr(GOUT CAtlArray<CGPoint2D> &arrPos, const double &dDist, const double &dGap);
	void CalcPointArray(GOUT CAtlArray<CGHorizontalAlignmentPoint> &arrPoint, const double &dDist, const double &dGap);

	// sync
	void SyncElement();

	// modify
	void Move(const CGVector2D &vMove);
	void Rotate(const CGPoint2D &ptBase, const CGPoint2D &vAng);
	void Scale(const CGPoint2D &ptBase, const double &dScale);

	
private:
	double m_dStartStation;
	CGPoint2D m_ptStartPos;
	CGPoint2D m_ptDirectionPos;
	CAtlArray<CGHorizontalAlignmentElement> m_arrElement;

public:
	GDEFINE_OPERATOR_COPY(CGHorizontalAlignment);
	GDEFINE_OPERATOR_EQUAL(CGHorizontalAlignment);

	CGHorizontalAlignment(void);
	~CGHorizontalAlignment(void);
};

