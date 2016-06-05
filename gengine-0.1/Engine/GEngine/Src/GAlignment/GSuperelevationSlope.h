#pragma once
/**
	@brief
		- 선형 1개의 편도에 대한 편경사 정보를 가진다.
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

