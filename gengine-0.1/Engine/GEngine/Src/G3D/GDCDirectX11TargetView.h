#pragma once
// direct define warning ����
// todo : ���� �ʾƵ� warning�� ���� �ʵ��� �����ؾ���.
#pragma warning(disable:4005)

#include <d3dx11.h>
#include "../../../../Lib/DirectX11/Effects11/Inc/d3dx11effect.h"
#include <dxerr.h>
#include "xnamath.h"
#include "atltypes.h"

/**
	@brief
		- DirectX11 DC�� �׷����� view
		- �ɹ� ������ ���� �ִ´�. ���� ������ DC���� ó���Ѵ�.
*/
class G_EXT_CLASS CGDCDirectX11TargetView :
	public CGDCTargetView
{
	friend class CGDCDirectX11;

private:

	IDXGISwapChain* mSwapChain;
	ID3D11RenderTargetView* mRenderTargetView;
	ID3D11RasterizerState* mRasterizerState;
	ID3D11DepthStencilView* mDepthStencilView;
	ID3D11Texture2D* mDepthStencilBuffer;
	D3D11_VIEWPORT mScreenViewport;

	ID3DX11EffectMatrixVariable *mfxWorldViewProj; // camera

	XMFLOAT4X4 mWorld;
	XMFLOAT4X4 mView;
	XMFLOAT4X4 mProj;

	float mTheta;
	float mPhi;
	float mRadius;
public:
	CGDCDirectX11TargetView();
	virtual ~CGDCDirectX11TargetView();
};

