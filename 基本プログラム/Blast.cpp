#include "stdafx.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "Blast.h"

Blast::Blast(){
	LoadTexture();
	DataInit();
}
void Blast::DataInit(){
	for (int i = 0; i < BLASTREA; i++)   mapNo[i] = -1;
}
int Blast::LoadTexture(){
	HRESULT    hr;
	char       path[100];
	for (int i = 0; i < BLASTMAPSU; i++){
		wsprintfA(path, "gazo\\b%02d.png", i + 1);
		hr = D3DXCreateTextureFromFileExA(
			pD3DDevice,
			path,
			0, 0, 0, 0,
			D3DFMT_A1R5G5B5,
			D3DPOOL_MANAGED,
			D3DX_FILTER_LINEAR,
			D3DX_FILTER_LINEAR,
			D3DCOLOR_ARGB(255, 0, 0, 0),
			NULL, NULL,
			&blastGazo[i]);
		if (hr != D3D_OK){
			MessageBoxA(NULL, "‰æ‘œ‚ª“Ç‚Ýž‚ß‚Ü‚¹‚ñ", "ƒGƒ‰[", MB_OK);
			return FALSE;
		}
	}
	return TRUE;
}
void Blast::setBlast(int _x, int _y){
	for (int i = 0; i < BLASTREA; i++){
		if (mapNo[i] == -1){
			mapNo[i] = 0;
			x[i] = _x-16;
			y[i] = _y-16;
			break;
		}
	}
}
void Blast::BlastPaint(){
	int n;
	pSprite->Begin(0);
	for (int i = 0; i < BLASTREA; i++){
		if (mapNo[i] != -1){
			D3DXVECTOR3 pos = D3DXVECTOR3((float)x[i], (float)y[i], 0.0f);
			n = mapNo[i];
			pSprite->Draw(blastGazo[n], NULL, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

			mapNo[i]++;
			if (mapNo[i] >= BLASTMAPSU)mapNo[i] = -1;
		}
	}
	pSprite->End();
}