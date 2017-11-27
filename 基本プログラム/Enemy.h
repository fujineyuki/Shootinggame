#pragma once
#include "InitDX.h"
#include "EnemyData.h"
#include "JIki.h"
class Enemy : public InitDX, public EnemyData{
private:LPDIRECT3DTEXTURE9 emenyGazo;
		JIki *jiki;
public :
	int WaitCount;
	int EMapNo[MAPENEMY_SU];
	Enemy(JIki   *);
	void DataInit();
	int LoadTexture();
	int SetEnemy();
	void EnemyMove();
	void EnemyPaint();
	int SetMissile(int,int);
	void EMissileMove();
	void EMisslePaint();
};