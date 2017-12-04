#include "stdafx.h"
#include "ssjiki.h"
#include<d3d9.h>
#include <d3dx9.h>
#include <math.h>
#include <mmsystem.h>
#include <windows.h>
#include <random>
#pragma comment(lib, "winmm.lib")
ssjiki::ssjiki(){
	LoadTexture();
	LoadTexture1();
	JikiLife = 0;
	SJiki_X = 80;
	SJiki_Y = 270;
	DataInit();
	WaitCount = 5;
	SP2 = false;
	startLift();
	
}
int ssjiki::LoadTexture(){
	HRESULT hr;
	char path[100];
	wsprintfA(path, "gazo\\Jiki.png");
	hr = D3DXCreateTextureFromFileExA(
		pD3DDevice,
		path,
		0, 0, 0, 0,
		D3DFMT_A1R5G5B5,
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 255, 255, 255),
		NULL, NULL,
		&jikiGazo);
	if (hr != D3D_OK){
		MessageBoxA(NULL, "画像が読み込めません", "エラー", MB_OK);
		return FALSE;
	}
	return TRUE;
}
int ssjiki::LoadTexture1(){
	HRESULT hr1;
	char path1[100];
	wsprintfA(path1, "gazo\\small.png");
	hr1 = D3DXCreateTextureFromFileExA(
		pD3DDevice,
		path1,
		0, 0, 0, 0,
		D3DFMT_A1R5G5B5,
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 255, 255, 255),
		NULL, NULL,
		&jikiGazo1);
	if (hr1 != D3D_OK){
		MessageBoxA(NULL, "画像が読み込めません", "エラー", MB_OK);
		return FALSE;
	}
	return TRUE;
}
float ssjiki::MoveX(int Op_X)//右の移動
{
	SJiki_X = Op_X - 40;
	return 1;
}
float ssjiki::MoveY(int Op_Y){//左の移動
	SJiki_Y = Op_Y - 30;
	return 1;
}
int ssjiki::retX(){ return SJiki_X; }
int ssjiki::retY(){ return SJiki_Y; }

void ssjiki::JikiPaint(){
	if (JikiLife >0){
		RECT         r;
		SetRect(&r, 0, 0, 25, 32);
		pSprite->Begin(0);
		D3DXVECTOR3 pos = D3DXVECTOR3((float)SJiki_X + 14
			, (float)SJiki_Y, 0.0f);
		pSprite->Draw(jikiGazo1, &r, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
		pSprite->End();
	}
	else SP2 = false;
}

void ssjiki::DataInit(){
	for (int i = 0; i < JMISSILE_SU; i++) JMsw[i] = false;
}
void ssjiki::SetJMissile(){
	if (JikiLife > 0){
		WaitCount++;
		if (WaitCount < 5)return;
		WaitCount = 0;
		for (int i = 0; i < JMISSILE_SU; i++)
			if (JMsw[i] == false){
				JMsw[i] = true;
				JMx[i] = SJiki_X + 20;
				jMy[i] = SJiki_Y;
				return;
			}
	}
}
void ssjiki::JMissileMove(){
	for (int i = 0; i < JMISSILE_SU; i++){
		if (JMsw[i] == true)
			if (jMy[i] < 0)JMsw[i] = false;
			else           jMy[i] -= 8;
	}
}
void ssjiki::JMissilePaint(){
	if (JikiLife > 0){
		D3DXVECTOR3    pos;
		RECT    r;
		SetRect(&r, 53, 0, 53 + JIKIMISSILE_W, JIKIMISSILE_H);
		JMissileMove();
		pSprite->Begin(0);
		for (int i = 0; i < JMISSILE_SU; i++){
			if (JMsw[i] == true){
				pos = D3DXVECTOR3((float)JMx[i], (float)jMy[i], 0.0f);
				pSprite->Draw(jikiGazo, &r, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
			}
		}

		pSprite->End();
	}
	else SP2 = false;
}
void ssjiki::resetLife(){
	JikiLife = 5;
	SP2 = true;
}
void ssjiki::startLift(){
	SP2 = false;
	JikiLife = 0;
}
void ssjiki::DownLife(){
	JikiLife--;
}
bool ssjiki::retLife(){
	return SP2;
}