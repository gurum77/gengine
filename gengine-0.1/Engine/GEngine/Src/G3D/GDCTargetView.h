#pragma once
/**
	@brief
		- DC�� �׷����� View�� ���� ����
*/
class G_EXT_CLASS CGDCTargetView
{
public:
	const INT32 &GetClienWidth() const;
	void SetClienWidth(const INT32 &ClientWidth);

	const INT32 &GetClienHeight() const;
	void SetClientHeight(const INT32 &ClienHeight);

protected:
	INT32 mClientWidth;
	INT32 mClientHeight;

public:
	CGDCTargetView();
	virtual ~CGDCTargetView();
};

