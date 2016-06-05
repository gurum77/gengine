#pragma once
/**
	@brief
		- CDCTargetView를 초기화하기 위한 data class
*/
class G_EXT_CLASS CGDCTargetViewInitData
{
public:
	// fill mode
	enum FillMode
	{
		eFillModeSolid,
		eFillModeWireframe,
		eFillModeCount
	};


	// cull mode
	enum CullMode
	{
		eCullModeNone,
		eCullModeFront,
		eCullModeBack,
		eCullModeCount
	};

	void SetWnd(HWND hWnd);
	HWND GetWnd() const;

	void SetBackgroundColor(const CGColor &color);
	const CGColor &GetBackgroundColor() const;

	void SetFillMode(const CGDCTargetViewInitData::FillMode &eFillMode);
	const CGDCTargetViewInitData::FillMode &GetFillMode() const;

	void SetCullMode(const CGDCTargetViewInitData::CullMode &eCullMode);
	const CGDCTargetViewInitData::CullMode &GetCullMode() const;

	void SetAntialiasedLineEnable(const BOOL &bEnable);
	const BOOL &GetAntialiasedLineEnable() const;

	void SetFog(const CGFog &fog);
	const CGFog &GetFog() const;

private:
	HWND m_hWnd;
	CGColor m_backgroundColor;	// 배경색
	FillMode m_eFillMode;
	CullMode m_eCullMode;
	BOOL m_bAntialiasedLineEnable;	// 안티알리아싱
	CGFog m_fog;

public:
	GDEFINE_OPERATOR_COPY(CGDCTargetViewInitData);
	CGDCTargetViewInitData();
	~CGDCTargetViewInitData();
};

