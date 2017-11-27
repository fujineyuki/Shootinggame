#pragma once
#include "stdafx.h"
#include "äÓñ{ÉvÉçÉOÉâÉÄ.h"
#include "InitDX.h"
class JIki : public InitDX{
private:LPDIRECT3DTEXTURE9 jikiGazo;
		int WaitCount;
		int JikiLife;
		int Op_X, Op, Y;
public:
    int Jiki_X, Jiki_Y;
	bool JMsw[JMISSILE_SU];
	int JMx[JMISSILE_SU], jMy[JMISSILE_SU];
	JIki();
	int LoadTexture();
	void JikiPaint();
	float MoveLeft();
	float MoveRight();
	float MoveUp();
	float MoveDown();
	int retX();
	int retY();
	void DataInit();
	void SetJMissile();
	void JMissileMove();
	void JMissilePaint();
	void SetLife(int);
	void DownLife();
	int retLife();
};