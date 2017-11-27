#include <d3d9.h>
#include <d3dx9.h>
#include "Const.h"

#pragma once 

class InitDX{
public :
	static LPDIRECT3D9              pD3D;
	static  LPDIRECT3DDEVICE9       pD3DDevice;
	static LPDIRECT3DSURFACE9      pBackBuffer;
	static 	D3DPRESENT_PARAMETERS   d3dppApp;
	static LPD3DXSPRITE             pSprite;
	static HWND hwndApp;
	~InitDX();
	static int InitDev(HWND);
};
