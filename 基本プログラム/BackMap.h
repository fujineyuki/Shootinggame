#include "stdafx.h"
#include "Šî–{ƒvƒƒOƒ‰ƒ€.h"
#include "InitDX.h"
class BackMap : public InitDX{
private:
	LPDIRECT3DTEXTURE9    tbackmap;
	int a;
public:
	BackMap();
	int LoadTexture();
	void backMapping();
};