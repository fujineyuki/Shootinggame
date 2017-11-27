#include "stdafx.h"
#include "JIki.h"
JIki::JIki(){
	LoadTexture();
	Jiki_X = 120;
	Jiki_Y = 300;
	DataInit();
	WaitCount = 5;
}
int JIki::LoadTexture(){
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
			D3DCOLOR_ARGB(255, 255,255,255),
			NULL, NULL,
			&jikiGazo);
		if (hr != D3D_OK){
			MessageBoxA(NULL, "画像が読み込めません", "エラー", MB_OK);
			return FALSE;
		}
	return TRUE;
}
void JIki::JikiPaint(){
	RECT         r;
	SetRect(&r, 0, 0, JIKI_W, JIKI_H);
	pSprite->Begin(0);
	D3DXVECTOR3 pos = D3DXVECTOR3((float)Jiki_X, (float)Jiki_Y, 0.0f);
	pSprite->Draw(jikiGazo, &r, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
	pSprite->End();
}

float JIki::MoveRight(){//右の移動
	Jiki_X += BASE_SPEED;
	if (Jiki_X >= SCREEN_W - JIKI_W) Jiki_X = SCREEN_W - JIKI_W;
	return Jiki_X;
}
float JIki::MoveLeft(){//左の移動
	Jiki_X -= BASE_SPEED;
	if (Jiki_X <= 0) Jiki_X = 0;//0以下に行かないため
	return Jiki_X;
}
float  JIki::MoveDown(){//下の移動量
	Jiki_Y += BASE_SPEED;
	if (Jiki_Y >= SCREEN_H - JIKI_H) Jiki_Y = SCREEN_H - JIKI_H;
	return Jiki_Y;
}
float JIki::MoveUp(){//上の移動量
	Jiki_Y -= BASE_SPEED;
	if (Jiki_Y <= 0) Jiki_Y = 0;//0以下に行かないため
	return Jiki_Y;
}
int JIki::retX(){ return Jiki_X; }
int  JIki::retY(){ return Jiki_Y; }
void JIki::DataInit(){
	for (int i = 0; i < JMISSILE_SU; i++) JMsw[i] = false;
}
void JIki::SetJMissile(){
	WaitCount++;
	if (WaitCount < 5)return;
	WaitCount = 0;
	for (int i = 0; i < JMISSILE_SU; i++)
		if (JMsw[i] == false){
			JMsw[i] = true;
			JMx[i] = Jiki_X + 20;
			jMy[i] = Jiki_Y;
			return;
		}
}
void JIki::JMissileMove(){
	for (int i = 0; i < JMISSILE_SU; i++){
		if (JMsw[i] == true)
			if (jMy[i] < 0)JMsw[i] = false;
			else           jMy[i] -= 8;
	}
}
void JIki::JMissilePaint(){
	D3DXVECTOR3    pos;
	RECT    r;
	SetRect(&r, 53, 0, 53 + JIKIMISSILE_W, JIKIMISSILE_H);
	JMissileMove();
	pSprite->Begin(0);
	for (int i = 0; i < JMISSILE_SU; i++){
		if (JMsw[i] == true){
			pos = D3DXVECTOR3((float)JMx[i], (float)jMy[i], 0.0f);
			pSprite->Draw(jikiGazo, &r, NULL,&pos, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
		}
	}

	pSprite->End();
}
void JIki::SetLife(int _life){
	JikiLife = _life;
}
void JIki::DownLife(){
	JikiLife--;
}
int JIki::retLife(){
	return JikiLife;
}
