#include "stdafx.h"
#include <random>
#include "SpAitem.h"
SpAitem::SpAitem(){
	WaitCount = 0;
	X = 0;
	Y = 0;
	ball = 0;
	SpM = false;
	LoadTexture();
}
int SpAitem::LoadTexture(){
	HRESULT hr;
	char path[100];
	wsprintfA(path, "gazo\\download.png");
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
		&SpAitems);
	if (hr != D3D_OK){
		MessageBoxA(NULL, "画像が読み込めません", "エラー", MB_OK);
		return FALSE;
	}
	return TRUE;

}
int  SpAitem::SetAitem(){
	WaitCount++;
	if (WaitCount < 50)return X;
	WaitCount = 0;
	if (SpM == false){
		Y = 0; SpM = true;
		std::random_device rnd;
		X = rnd() % 250;
		ball = rnd() % 12 + 1;
		
	}
	return X;
}
void  SpAitem::SpMove(){
		if (SpM == true)
			if (Y > 400)SpM = false;
			else           Y += 4;
			
}
int SpAitem::SpPaint(){
	D3DXVECTOR3    pos;
	RECT    r;
	std::random_device rnd;
	SetRect(&r, 128 + ball_COLOR * ball, 0, 160  + ball_COLOR * ball, 32);
	SpMove();
	pSprite->Begin(0);
	if (SpM == true){
		pos = D3DXVECTOR3((float)X, (float)Y, 0.0f);
		pSprite->Draw(SpAitems, &r, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
	}
	pSprite->End();
	return Y;
}
