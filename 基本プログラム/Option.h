#pragma once
#include "stdafx.h"
#include "InitDX.h"
#include "Enemy.h"
#include "Blast.h"
#include "jiki.h"
class Option : public InitDX{
private:
	struct OData{
		float theta;
		float x, y;
	}OptionData;
	struct OData1{
		float theta1;
		int x1, y1;
	}OptionData1;
	struct OData2{
		int theta2;
		int x2, y2;
	}OptionData2;
	struct OData3{
		int theta3;
		int x3, y3;
	}OptionData3;
	int r;
	int r1;
	float cX, cY;
	LPDIRECT3DTEXTURE9 optionIm;
	Enemy   *enemy;
	Blast   *blast;
	JIki    *jiki;
	int hit[4];
	bool baria[4];
public:
	Option(JIki *_jiki, Enemy  *_enemy, Blast  *_blast);
	int LoadTexture();
	void CenterPaint();
	void OptionPaint();
	void reset();
	int  HitCheakOption(float  x, float y,int);
	void cX1(float Op_X);
	void cY1(float Op_Y);
};