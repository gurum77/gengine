#pragma once
/**
	@brief
		- ���� 1���� ���� ���� ���� ������ ������.
*/
class G_EXT_CLASS CGSuperelevationSlope
{
public:
	void AddItem(CGSuperelevationSlopeItem &item);
	INT32 GetItemCount() const;
	CGSuperelevationSlopeItem *GetItem(const INT32 &iIdx);
	void DeleteItem(const INT32 &iIdx);

private:
	CAtlArray<CGSuperelevationSlopeItem> m_arrItem;

public:
	GDEFINE_OPERATOR_COPY(CGSuperelevationSlope);
	GDEFINE_OPERATOR_EQUAL(CGSuperelevationSlope);
	CGSuperelevationSlope(void);
	CGSuperelevationSlope(const CGSuperelevationSlope &d);
	~CGSuperelevationSlope(void);
};

