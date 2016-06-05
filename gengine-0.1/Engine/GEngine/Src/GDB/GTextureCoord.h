#pragma once

/**
	@brief
		- texture coord
		- object 1개가 texture coord 1개와 대응된다.
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

