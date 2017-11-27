#pragma once
#include "stdafx.h"
#include "InitDX.h"
#include "Option.h"
class SpAitem : public InitDX{
private:LPDIRECT3DTEXTURE9 SpAitems;
		int WaitCount;
		int X,Y,ball;
		Option *option;
		
public:
	bool SpM;
	SpAitem();
	int  SetAitem();
	void  SpMove();
	int SpPaint();
	int LoadTexture();
};
