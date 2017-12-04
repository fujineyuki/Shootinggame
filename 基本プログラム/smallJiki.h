#pragma once
#include "stdafx.h"
#include "äÓñ{ÉvÉçÉOÉâÉÄ.h"
#include "InitDX.h"
#include "JIki.h"
class JIkismall : public InitDX{
private:LPDIRECT3DTEXTURE9 jikiGazo;
		LPDIRECT3DTEXTURE9 jikiGazo1;
		int WaitCount;
		int JikiLife;
		int Op_X, Op, Y;
		bool SP1;
		JIki *jiki;
		
public:
	int SJiki_X, SJiki_Y;
	bool JMsw[JMISSILE_SU];
	int JMx[JMISSILE_SU], jMy[JMISSILE_SU];
	JIkismall();
	int LoadTexture();
	int LoadTexture1();
	void JikiPaint();
	float MoveX(int);
	float MoveY(int);
	int retX();
	int retY();
	int JIKI_Xreturn();
	int JIKI_Yreturn();
	void DataInit();
	void SetJMissile();
	void JMissileMove();
	void JMissilePaint();
	void resetLife();
	void DownLife();
	void startLift();
	bool retLife();
};