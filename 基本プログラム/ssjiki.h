#pragma once
#include "stdafx.h"
#include "äÓñ{ÉvÉçÉOÉâÉÄ.h"
#include "InitDX.h"
#include "JIki.h"
class ssjiki : public InitDX{
private:LPDIRECT3DTEXTURE9 jikiGazo;
		LPDIRECT3DTEXTURE9 jikiGazo1;
		int WaitCount;
		int JikiLife;
		int Op_X, Op, Y;
		JIki *jiki;
		bool SP2;

public:
	int SJiki_X, SJiki_Y;
	bool JMsw[JMISSILE_SU];
	int JMx[JMISSILE_SU], jMy[JMISSILE_SU];
	ssjiki();
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