#pragma once
#include "InitDX.h"

class Msg :public InitDX{
private:
	LPD3DXFONT    pFont1;
	LPD3DXFONT    pFont2;
	LPDIRECT3DTEXTURE9 jikiGazo;
public :
	Msg();
	void ScorePaint(int);
	void MessagePaint(char  *, D3DCOLOR);
	void LifePaint(int);
};