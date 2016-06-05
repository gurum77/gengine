#pragma once
// direct define warning 꺼둠
// todo : 끄지 않아도 warning이 뜨지 않도록 수정해야함.
#pragma warning(disable:4005)

#include <d3dx11.h>
#include "../../../../Lib/DirectX11/Effects11/Inc/d3dx11effect.h"
#include <dxerr.h>
#include "xnamath.h"
#include "atltypes.h"

/**
	@brief
		- DirectX11 DC가 그려지는 view
		- 맴버 변수만 갖고 있는다. 실제 동작은 DC에서 처리한다.
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

