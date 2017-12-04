#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(JIki *_jiki){
	jiki = _jiki;
	DataInit();
	LoadTexture();
	EnemyData::DataInit();
}
void Enemy::DataInit(){ 
	for (int i = 0; i < MAPENEMY_SU; i++)EMapNo[i] = -1;
	for (int i = 0; i < EMISSILE_SU; i++)EMsw[i] = false;
	EnemyData::DataInit();
}
int Enemy::LoadTexture(){
	HRESULT hr;
	char path[100];
	wsprintfA(path, "gazo\\enemy.png");
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
		&emenyGazo);
	if (hr != D3D_OK){
		MessageBoxA(NULL, "画像が読み込めません", "エラー", MB_OK);
		return FALSE;
	}
	return TRUE;
}
int Enemy::SetEnemy(){
	WaitCount++;
	if (WaitCount < 6) return -1;
	WaitCount = 0;
	if (EnemyDataPoint >= ENEMY_SU){
		return GAME_CLAER;
	}
	for (int i = 0; i < MAPENEMY_SU; i++){
		if (EMapNo[i] == -1){
			EMapNo[i] = EnemyDataPoint;
			EnemyDataPoint++;
			return 0;
		}
	}
	return -1;
}

void Enemy::EnemyMove(){
	int p, mtype;
	for (int i = 0; i < MAPENEMY_SU; i++){
		if (EMapNo[i] != -1){
			p = EMapNo[i];
			mtype = Emovetype[p];
			switch (mtype)
			{
			case 1: if (Ey[p] > 200)EspeedY[p] *= -1;
				break;
			case 2: if (Ey[p] > 100)EspeedX[p] *= -1;
				break;
			}
			Ex[p] += EspeedX[p];
			Ey[p] += EspeedY[p];

			if (Ex[p] < -20 || Ex[p] > SCREEN_W || Ey[p] < -20 || Ey[p] > SCREEN_H)  EMapNo[i] = -1;
			if (EmissileFlg[p] != 0){
				EmissileFlg[p]++;
				if (EmissileFlg[p] > 5){
					SetMissile(Ex[p], Ey[p]);
					EmissileFlg[p] = 1;

				}
			}
		}
	}
}
void Enemy::EnemyPaint(){
	int p;
	D3DXVECTOR3 pos;
	RECT        r;
	SetRect(&r, 0, 0, ENEMY_W, ENEMY_H);
	EnemyMove();

	pSprite->Begin(0);
	for (int i = 0; i < MAPENEMY_SU; i++){
		if (EMapNo[i] >= 0){
			p = EMapNo[i];
			pos = D3DXVECTOR3((float)Ex[p], (float)Ey[p], 0.0f);
			pSprite->Draw(emenyGazo, &r, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
		}
	}
	pSprite->End();
}


int Enemy::SetMissile(int px, int py){
	for (int i = 0; i < EMISSILE_SU; i++){
		if (EMsw[i] == false){
			EMsw[i] = true;
			EMx[i] = px + 10;
			EMy[i] = py;
			EMspeedX[i] = 0;  EMspeedY[i] = 7;
				int saX, saY;
				double w;
				saX = (EMx[i] + 5) - (jiki->retX() + 25);
				saY = (EMy[i] + 5) - (jiki->retY() + 25);
				w = atan2((double)saY, (double)saX);
				EMspeedX[i] = (int)(cos(w) * -8);
				EMspeedY[i] = (int)(sin(w) * -8);
				return  i;
		}
	}
	return   99;
}
void Enemy::EMissileMove(){
	for (int i = 0; i < EMISSILE_SU; i++){
		if (EMsw[i] == true){
			EMx[i] += EMspeedX[i];
			EMy[i] += EMspeedY[i];
		}
		if (EMx[i] < -20 || EMx[i] > 300 || EMy[i] < -20 || EMy[i] > 400)EMsw[i] = false;
	}
}
void Enemy::EMisslePaint(){
	D3DXVECTOR3   pos;
	RECT          r;
	SetRect(&r, 40, 0, 40 + EMISSILE_W, EMISSILE_H);
	EMissileMove();
	pSprite->Begin(0);
	for (int i = 0; i < EMISSILE_SU; i++){
		if (EMsw[i] == true){
			pos = D3DXVECTOR3((float)EMx[i], (float)EMy[i], 0.0f);
			pSprite->Draw(emenyGazo, &r, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));//スプライトの描画
		}
	}
	pSprite->End();
	
}