//***************************************************************************************
// Vertex.h by Frank Luna (C) 2011 All Rights Reserved.
//
// Defines vertex structures and input layouts.
//***************************************************************************************

#ifndef VERTEX_H
#define VERTEX_H

#include "d3dUtil.h"
#include "GTypes.h"
namespace Vertex
{
	// Basic 32-byte vertex structure. + a
	struct LightTex32 
	{
		gfloat3 Pos;
		gfloat3 Normal;
		gfloat2 Tex;

		UINT ID;
	};

	// Color 24-byte vertex structure. + a
	struct Color24
	{
		gfloat3 Pos;
		gfloat3 Col;

		UINT ID;
	};
}

class InputLayoutDesc
{
public:
	// Init like const int A::a[4] = {0, 1, 2, 3}; in .cpp file.
	static const D3D11_INPUT_ELEMENT_DESC Basic32[3];
	static const D3D11_INPUT_ELEMENT_DESC Color24[2];
};

class Effects;

class InputLayouts
{
public:
	void InitAll(ID3D11Device* device, Effects *effects);
	void DestroyAll();

	ID3D11InputLayout* LightTex32;
	ID3D11InputLayout* Color24;
};

#endif // VERTEX_H
