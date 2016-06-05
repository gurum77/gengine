#pragma once

#include "../../../../lib/freetype-2.6.2/include/ft2build.h"
#include FT_FREETYPE_H

/**
	@brief
		- font manager
*/
class G_EXT_CLASS CGFontManager
{
public:
	BOOL LoadText(const CGText &text, const CGFontProperty &fontProperty);

	const CAtlArray<CGPoint3D> &GetOutlinePoint();
	const CAtlArray<INT32> &GetOutlineIndex();

	const CAtlArray<CGPoint3D> &GetFacePoint();
	const CAtlArray<INT32> &GetFaceIndex();

	

	CAtlString FindFontFileName(const CAtlString &strFontName);

private:
	void Rotate(CAtlArray<CGPoint3D> &arrPoint, const CGPoint3D &ptBase, const CGVector2D &vAng);
	void Scale(CAtlArray<CGPoint3D> &arrPoint, const CGPoint3D &ptBase, const float &fScale);
	void Move(CAtlArray<CGPoint3D> &arrPoint, const CGVector3D &vMove);

	void InitFace();
	void InitAllOutlineAndFace();

	CGRect CalcBoundary(CAtlArray<CGPoint3D> &arrPos);

	bool LoadFontByFreeType(const CAtlString &sFontName);

	CAtlArray<CGPoint3D> m_arrOutlinePoint;
	CAtlArray<INT32> m_arrOutlineIndex;

	CAtlArray<CGPoint3D> m_arrFacePoint;
	CAtlArray<INT32> m_arrFaceIndex;

	FT_Library m_ftLibrary;
	CAtlMap<CAtlString, FT_Face> m_mapFace;

public:
	CGFontManager(void);
	virtual ~CGFontManager(void);
};

