#pragma once
/**
	@brief
		- The element of horizontal alignment
			- line, arc, clothoid, ovalness
		- Element �� ���� ����� �� �κ��� ����Ѵ�.
		- ������ �и��Ǿ� Ȱ���� �����ϴ�
			- ���� ��ü���� Ư�� Element�� ���� ������ �����ϵ��� �ϱ� ����.
			- Element�� ������ ��ü�� ���� Ȱ�� �� �� �ֵ��� �ϱ� ����.
*/
class G_EXT_CLASS CGHorizontalAlignmentElement
{
public:
	enum Type
	{
		eTypeUnknown,
		eTypeLine,
		eTypeArc,
		eTypeClothoidA1,
		eTypeClothoidA2,
		eTypeOvalness
	};

	void SetStartPos(const CGPoint2D &dptPos);
	const CGPoint2D &GetStartPos() const;

	void SetDir(const CGVector2D &vDir);
	const CGVector2D &GetDir() const;

	void SetStartStation(const double &dStation);
	const double &GetStartStation() const;
	
	void SetA1(const double &dA1);
	const double &GetA1() const;

	void SetA2(const double &dA2);
	const double &GetA2() const;

	void SetR1(const double &dR1);
	const double &GetR1() const;

	void SetR2(const double &dR2);
	const double &GetR2() const;

	void SetCCW(const bool &bCCW);
	const bool &GetCCW() const;

	void SetLength(const double &dLength);
	const double &GetLength() const;
	Type GetType() const;

	bool CalcLengthByParameter();
	bool IsIncludeStation(const double &dStation) const;
	CGPoint2D CalcPosByStation(const double &dStation, GOUT CGVector2D *pvEndDir = NULL) const;


private:
	CGPoint2D m_ptStartPos;
	CGVector2D m_vDir;
	double m_dStartStation;
	double m_dA1;
	double m_dA2;
	double m_dR1;
	double m_dR2;
	double m_dLength;
	bool m_bCCW;

public:
	GDEFINE_OPERATOR_COPY(CGHorizontalAlignmentElement);
	GDEFINE_OPERATOR_EQUAL(CGHorizontalAlignmentElement);
	CGHorizontalAlignmentElement(void);
	CGHorizontalAlignmentElement(const CGHorizontalAlignmentElement &d);
	~CGHorizontalAlignmentElement(void);
};

