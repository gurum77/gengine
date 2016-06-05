#pragma once

/**
	@brief
		- texture coord를 관리한다.
*/
class G_EXT_CLASS CGTextureCoordManager
{
public:
	void CloneTextureCoord(const GID &fromObjectID, const GID &toObjectID);
	void AddTextureCoord(const GID &objectID, CGTextureCoord *pCoord);
	CGTextureCoord *FindTextureCoordByObjectID(const GID &objectID);
	void InitAllTextureCoord();
	void DeleteTextureCoordByObjectID(const GID &objectID);

	void SetTextureCoordToVERTEX(const GID &objectID, GOUT CAtlArray<GVERTEX> &arrVertex);
private:
	CAtlMap<GID, CGTextureCoord*> m_mapTextureCoord;

public:
	CGTextureCoordManager();
	~CGTextureCoordManager();
};

