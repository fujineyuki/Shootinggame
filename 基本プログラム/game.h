#pragma once
#include "stdafx.h"
#include "äÓñ{ÉvÉçÉOÉâÉÄ.h"
#include "InitDX.h"
#include "BackMap.h"
#include "JIki.h"
#include "Enemy.h"
#include "HitCheak.h"
#include "Blast.h"
#include "Msg.h"
#include "SpAitem.h"
#include "Option.h"
#include "smallJiki.h"

class Game : public InitDX{
private:
	BackMap *backmap;
	JIki    *jiki;
	Enemy   *enemy;
	HitCheak *hitcheak;
	Blast   *blast;
	Msg     *msg;
	SpAitem *SpAitems;
	Option  *Options;
	JIkismall *SJiki;
	int GameFlg;
	int x, y;
	float Op_X, Op_Y;
public:
	Game();
	int GameInit();
	void GameControl();
	void InputKey();
	int GameScore;
};