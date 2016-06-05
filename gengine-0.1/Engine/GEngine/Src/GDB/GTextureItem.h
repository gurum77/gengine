#pragma once

/**
	@brief
		- texture 1개를 의미
*/
class G_EXT_CLASS CGTextureItem
{
public:
	void SetImagePathFileName(const CAtlString &strImagePathFileName);
	const CAtlString &GetImagePathFileName() const;

private:
	CAtlString m_strImagePathFileName;

public:
	GDEFINE_OPERATOR_COPY(CGTextureItem);
	CGTextureItem();
	~CGTextureItem();
};

