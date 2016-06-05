#pragma once

/**
	@brief
		- texture coord
		- object 1���� texture coord 1���� �����ȴ�.
*/
class G_EXT_CLASS CGTextureCoord
{
public:
	void Init();
	void AddCoord(const float &fX, const float &fY);
	INT32 GetCoordCount() const;
	const gfloat2 *GetCoord(const INT32 &iIdx) const;

	CGTextureCoord *CloneTextureCoord();

private:
	CAtlArray<gfloat2> m_arrCoord;

public:
	GDEFINE_OPERATOR_COPY(CGTextureCoord);
	CGTextureCoord();
	~CGTextureCoord();
};

