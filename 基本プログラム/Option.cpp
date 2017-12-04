#include "stdafx.h"
#include"基本プログラム.h"
#include "Option.h"
#include<d3d9.h>
#include <d3dx9.h>
#include <math.h>
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

#define PAI 3.1415926f
Option::Option(JIki *_jiki, Enemy  *_enemy, Blast  *_blast){
	LoadTexture();
	jiki = _jiki;
	enemy = _enemy;
	blast = _blast;
	reset();
}
void Option::reset(){
	for (int i = 0; i < 4; i++){
		baria[i] = true; hit[i] = 0;
		r = 60;
		r1 = 45;
		cX = jiki->retX();
		cY = jiki->retY();
		OptionData.theta = 0;
		OptionData1.theta1 = 180;
		OptionData2.theta2 = 90;
		OptionData3.theta3 = 270;
	}
}
int Option::LoadTexture(){
	HRESULT hr;
	hr = D3DXCreateTextureFromFileExA(
		pD3DDevice,

		"gazo\\download.png",
		0, 0, 0, 0,
		D3DFMT_A1R5G5B5,
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 255, 255, 255),
		NULL, NULL,
		&optionIm);
	if (hr != D3D_OK){
		MessageBoxA(NULL, "画像が読み込めません", "エラー", MB_OK);
		return FALSE;
	}
	return TRUE;
}
void Option::OptionPaint(){
	D3DXVECTOR3 pos;
	RECT         e;
	float wRadian, px, py;

	pSprite->Begin(0);


	if (baria[0] == true){
		OptionData.theta -= 20;
		if (OptionData.theta > 360)OptionData.theta = 0;

		wRadian = (float)OptionData.theta * PAI / 180.0f;

		px = cos(wRadian) * r;
		py = sin(wRadian) * r;
		OptionData.x = px + cX;
		OptionData.y = py + cY;

		pos = D3DXVECTOR3((float)OptionData.x, (float)OptionData.y, 0.0f);
		//pos = D3DXVECTOR3((float)cX + 10, (float)cY+10, 0.0f);

		SetRect(&e, 352, 32, 384, 64);

		pSprite->Draw(optionIm, &e, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		HitCheakOption(OptionData.x, OptionData.y, 0);
	}

	if (baria[1] == true){
		OptionData1.theta1 -= 20;
		if (OptionData1.theta1 > 360)OptionData1.theta1 = 0;

		wRadian = (float)OptionData1.theta1 * PAI / 180.0f;

		px = cos(wRadian) * r;
		py = sin(wRadian) * r;
		OptionData.x = px + cX;
		OptionData.y = py + cY;

		pos = D3DXVECTOR3((float)OptionData.x, (float)OptionData.y, 0.0f);
		//pos = D3DXVECTOR3((float)cX + 10, (float)cY+10, 0.0f);

		pSprite->Draw(optionIm, &e, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
		HitCheakOption(OptionData.x, OptionData.y, 1);
	}
	if (baria[2] == true){


		OptionData2.theta2 -= 20;
		if (OptionData2.theta2 > 360)OptionData2.theta2 = 0;

		wRadian = (float)OptionData2.theta2 * PAI / 180.0f;


		px = cos(wRadian) * r1;
		py = sin(wRadian) * r1;
		OptionData.x = px + cX;
		OptionData.y = py + cY;

		pos = D3DXVECTOR3((float)OptionData.x, (float)OptionData.y, 0.0f);
		//pos = D3DXVECTOR3((float)cX + 10, (float)cY+10, 0.0f);


		pSprite->Draw(optionIm, &e, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
		HitCheakOption(OptionData.x, OptionData.y, 2);
	}

	if (baria[3] == true){
		OptionData3.theta3 -= 20;
		if (OptionData3.theta3 > 360)OptionData3.theta3 = 0;

		wRadian = (float)OptionData3.theta3 * PAI / 180.0f;


		px = cos(wRadian) * r1;
		py = sin(wRadian) * r1;
		OptionData.x = px + cX;
		OptionData.y = py + cY;

		pos = D3DXVECTOR3((float)OptionData.x, (float)OptionData.y, 0.0f);
		//pos = D3DXVECTOR3((float)cX + 10, (float)cY+10, 0.0f);
		
		pSprite->Draw(optionIm, &e, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
		HitCheakOption(OptionData.x, OptionData.y, 3);
	}


	pSprite->End();


}
int  Option::HitCheakOption(float  x, float   y, int q){
	int  ex, ey;
	for (int i = 0; i < EMISSILE_SU; i++){
		if (enemy->EMsw[i] == true){
			ex = enemy->EMx[i] + EMISSILE_W / 2;
			ey = enemy->EMy[i] + EMISSILE_H / 2;
			if (x < ex && ex < x + 32){
				if (y < ey && ey < y + 32){
					blast->setBlast(ex, ey);
					if (hit[q] >= 5){
						enemy->EMsw[i] = false;
						blast->setBlast(ex, ey);
						baria[q] = false;
						return 3;
						
						
					}
					else hit[q]++;
					return 3;
				}

			}

		}
	}
	return 3;
}

void Option::cX1(float Op_X){cX = Op_X + 13.0f;}
void Option::cY1(float Op_Y) {cY = Op_Y + 13.0f; }
