#pragma once
/**
	@brief
		- rect
*/
class G_EXT_CLASS CGRect
{
public:
	void SetLeft(const double &dLeft);
	const double &GetLeft() const;

	void SetTop(const double &dTop);
	const double GetTop() const;

	void SetRight(const double &dRight);
	const double GetRight() const;

	void SetBottom(const double &dBottom);
	const double GetBottom() const;

	CGPoint2D GetCenter() const;
	double GetWidth() const;
	double GetHeight() const;

	void SetByPoint2D(const CGPoint2D &point2D);
	void MergeByPoint2D(const CGPoint2D &point2D);
	void MergeByRect(const CGRect &rect);

	void Init();
	BOOL IsEmpty() const;
	BOOL IsIncludePos(const CGPoint2D &pt) const;
	
	GDEFINE_OPERATOR_COPY(CGRect)
	GDEFINE_OPERATOR_EQUAL(CGRect)
protected:
	double m_dLeft;
	double m_dTop;
	double m_dRight;
	double m_dBottom;

public:
	CGRect();
	~CGRect();
};

