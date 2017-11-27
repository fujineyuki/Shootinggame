#include "stdafx.h"
#include "Msg.h"
#include "Const.h"

Msg::Msg(){
	pFont1 = NULL;
	D3DXCreateFontA(pD3DDevice, 20, 10,
		0, 0, 0, 0, 0, 0, 0, "HG‘n‰pŠpÎß¯Ìß‘Ì",&pFont1);
	pFont2 = NULL;
	D3DXCreateFontA(pD3DDevice, 20, 20,
		0, 0, 0, 0, 0, 0, 0, "HG‘n‰pŠpÎß¯Ìß‘Ì", &pFont2);
	HRESULT hr;
	char path[100];
	wsprintfA(path, "gazo\\Jiki1.png");
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
}
void Msg::ScorePaint(int score){
	char m[100];
	RECT rc;
	SetRect(&rc, 200, 20, 300, 60);
	wsprintfA(m, "Score:%3d", score);
	pFont1->DrawTextA(NULL, m, -1, &rc, NULL, 0xFFFFFFFF);
}
void Msg::MessagePaint(char *m, D3DCOLOR Color){
		RECT rc;
		SetRect(&rc, 50, 100, 300, 200);
		pFont2->DrawTextA(NULL, m, -1, &rc, NULL, Color);
}
void Msg::LifePaint(int life){
	RECT  r;
	SetRect(&r, 0, 0, 25, 25);
	pSprite->Begin(0);
	for (int i = 0, y = 45; i < life; i++, y += 27){
		D3DXVECTOR3 pos = D3DXVECTOR3((float)265, (float)y, 0.0f);
		pSprite->Draw(jikiGazo, &r, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));//ƒXƒvƒ‰ƒCƒg‚Ì•`‰æ
	}
	pSprite->End();
}
