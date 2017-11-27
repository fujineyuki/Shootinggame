#include "stdafx.h"
#include "基本プログラム.h"
#include "BackMap.h"
BackMap::BackMap(){//オブジェクトの作成
	LoadTexture();
	a = 0;
}
int BackMap::LoadTexture(){//画像取り込み
	HRESULT hr;
	hr = D3DXCreateTextureFromFileA(pD3DDevice, "gazo\\BackMapX.png",&tbackmap);
	if (hr != D3D_OK){
		MessageBoxA(NULL, "画像を読み込めません", "エラー", MB_OK);
		return FALSE;
	}
	return TRUE;
}
void BackMap::backMapping(){
	RECT r1, r2;
	SetRect(&r1, 0, 0, SCREEN_W, SCREEN_H - a);
	D3DXVECTOR3 pos1 = D3DXVECTOR3((float)0, (float)a, 0.0f);
	SetRect(&r2, 0, SCREEN_H - a, SCREEN_W, SCREEN_H);
	D3DXVECTOR3 pos2 = D3DXVECTOR3((float)0, (float)0, 0.0f);
	pSprite->Begin(0);
	pSprite->Draw(tbackmap,&r1, NULL, &pos1, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
	pSprite->Draw(tbackmap,&r2, NULL, &pos2, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画

	pSprite->End();
	a += 8;
	if (a >= SCREEN_H) a = 0;

}