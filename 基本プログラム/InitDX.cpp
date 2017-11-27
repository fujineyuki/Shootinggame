#include "stdafx.h"
#include "��{�v���O����.h"
#include "InitDx.h"

#include<d3d9.h>
#include<d3dx9.h>

#define RELEASE(x) if(x){x->Release();x = NULL;}

#pragma once //�ǂݍ��݂���x�����ɂ���A�s�����������͖̂�������悤�Ȑݒ�
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")
/*
class InitDX{
static LPDIRECT3D9				pD3D;		//DirectX9�̃I�u�W�F�N�g
static LPDIRECT3DDEVICE9		pD3DDevice;	//3D�f�o�C�X
static D3DPRESENT_PARAMETERS	d3dppApp;	//�f�o�C�X�쐬���̃p�����[�^
static LPDIRECT3DSURFACE9		pBackBuffer;//DirectX9Surface
static LPD3DXSPRITE				pSprite;
static HWND hwndApp;						//���v���O�����ɂ����hwndApp�͕ύX���邱��
~InitDX();
static int InitDev(HWND);
};
*/

LPDIRECT3D9				InitDX::pD3D = NULL;		//DirectX9�̃I�u�W�F�N�g
LPDIRECT3DDEVICE9		InitDX::pD3DDevice = NULL;	//3D�f�o�C�X
D3DPRESENT_PARAMETERS	InitDX::d3dppApp;	//�f�o�C�X�쐬���̃p�����[�^
LPDIRECT3DSURFACE9		InitDX::pBackBuffer = NULL;//DirectX9Surface
LPD3DXSPRITE			InitDX::pSprite = NULL;
HWND					InitDX::hwndApp;

InitDX::~InitDX(){
	RELEASE(pD3DDevice);
	RELEASE(pD3D);
}

int InitDX::InitDev(HWND _hWndApp){
	hwndApp = _hWndApp;

	pD3D = Direct3DCreate9(D3D_SDK_VERSION);//Direct3D�I�u�W�F�N�g�̎擾
	if (pD3D == NULL)	return FALSE;

	D3DDISPLAYMODE dmode;	//���݂̃f�B�X�v���C���[�h�𓾂�
	if (FAILED(pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &dmode)))
		return FALSE;

	//�o�b�N�T�[�t�F�[�X�̃t�H�[�}�b�g���R�s�[���Ďg�p����
	ZeroMemory(&d3dppApp, sizeof(d3dppApp));
	d3dppApp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dppApp.BackBufferFormat = dmode.Format;
	d3dppApp.Windowed = 1;
	d3dppApp.BackBufferWidth = SCREEN_W;
	d3dppApp.BackBufferHeight = SCREEN_H;
	d3dppApp.BackBufferCount = 1;

	//�f�o�C�X�̍쐬
	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwndApp, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dppApp, &pD3DDevice))){
		if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwndApp, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dppApp, &pD3DDevice)))
			return FALSE;
	}
	//�A���t�@�E�u�����f�B���O���s���@���ߏ������s��
	pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//�o�b�N�o�b�t�@�𓾂�
	pD3DDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
	HRESULT hr;
	hr = D3DXCreateSprite(pD3DDevice, &pSprite);
	if (hr != D3D_OK)		return FALSE;
	return TRUE;
}