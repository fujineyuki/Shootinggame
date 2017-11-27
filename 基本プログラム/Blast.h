#pragma once 
#include <d3d9.h>
#include <d3dx9.h>
#include "InitDX.h"
#define BLASTREA    5
#define BLASTMAPSU  12

class Blast : public InitDX{
private :
	LPDIRECT3DTEXTURE9      blastGazo[BLASTMAPSU];
	int    x[BLASTREA], y[BLASTREA];
	int    mapNo[BLASTREA];
public :
	Blast();
	void DataInit();
	int LoadTexture();
	void setBlast(int, int);
	void BlastPaint();
};