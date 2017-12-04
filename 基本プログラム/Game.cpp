#include "stdafx.h"
#include "基本プログラム.h"
#include "game.h"
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
Game::Game(){//オブジェクトの作成
	backmap = new BackMap();
	jiki    = new JIki();
	SJiki = new JIkismall();
	Ssjiki = new ssjiki();
	SpAitems = new SpAitem();
	enemy = new Enemy(jiki);
	blast = new Blast();
	Options = new Option(jiki, enemy, blast);
	hitcheak = new HitCheak(jiki, enemy,blast,SpAitems,SJiki,Ssjiki);
	msg = new Msg();
	GameFlg = GAME_NOTREADY;
	GameScore = 0;
}
void Game::InputKey(){//キーごとの呼び出し
	unsigned char m[256];
	GetKeyboardState(m);
	if (m[VK_RIGHT] & 0x80){ Op_X = jiki->MoveRight(); SJiki->MoveX(Op_X); Ssjiki->MoveX(Op_X); Options->cX1(Op_X); }
	if (m[VK_LEFT] & 0x80){ Op_X = jiki->MoveLeft(); SJiki->MoveX(Op_X); Ssjiki->MoveX(Op_X); Options->cX1(Op_X); }
	if (m[VK_DOWN] & 0x80){ Op_Y = jiki->MoveDown(); SJiki->MoveY(Op_Y); Ssjiki->MoveY(Op_Y); Options->cY1(Op_Y); }
	if (m[VK_UP] & 0x80){ Op_Y = jiki->MoveUp(); SJiki->MoveY(Op_Y); Ssjiki->MoveY(Op_Y); Options->cY1(Op_Y); }
	if (m['X'] & 0x80)jiki->SetJMissile();
	if (m['Z'] & 0x80){
		GameFlg = GAME_READY;	PlaySoundA("sound\\Narration-Hanyou_GameStart_02.wav", NULL, (SND_ASYNC | SND_FILENAME));
	}
}
void Game::GameControl(){//画像描画
	pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0, 0);//背景を黒に設定
	pD3DDevice->BeginScene();//シーン作成開始
	pSprite->Begin(0);
	InputKey();//キー出力
	backmap->backMapping();
	jiki->JikiPaint();
	jiki->JMissilePaint();
	SJiki->SetJMissile();
	SJiki->JikiPaint();
	SJiki->JMissilePaint();
	Ssjiki->SetJMissile();
	Ssjiki->JikiPaint();
	Ssjiki->JMissilePaint();
	enemy->EnemyPaint();
	enemy->EMisslePaint();
	Options->OptionPaint();
	y = SpAitems->SpPaint();
	msg->ScorePaint(GameScore);
	msg->LifePaint(jiki->retLife());

	

	switch (GameFlg)
	{
	case GAME_NOTREADY:
		break;
	case GAME_READY:
	{
		static    int WaitCount = 0;
		GameScore = 0;
		WaitCount++;
		msg->MessagePaint("Game start!!", 0xffffffff);
	
		if (WaitCount < 40){
			break;
		}
		WaitCount = 0;
		GameFlg = GAME_PLAY;
		jiki->SetLife(JIKI_LIFE);
		SJiki->startLift();
		Ssjiki->startLift();
		jiki->DataInit();
		enemy->DataInit();
		Options->reset();
	}
	break;
	case GAME_PLAY:
	{
		int w;
		x = SpAitems->SetAitem();
		w = enemy->SetEnemy();
		if (w == GAME_CLAER){
			GameFlg = GAME_CLAER;
			PlaySoundA("sound\\Narration-Hanyou_WIN_02.wav", NULL, (SND_ASYNC | SND_FILENAME));
		}
			jiki->JMissilePaint();
		w = hitcheak->JMissileVsEnemy(x,y);
		if (w == 50)Options->reset();
		GameScore += w;
		hitcheak->JikiVsEMissile();

		blast->BlastPaint();
		if (jiki->retLife() <= 0){
			PlaySoundA("sound\\exp.wav", NULL, (SND_ASYNC | SND_FILENAME));
			GameFlg = GAME_OVER;
		}
	}
	break;
	case BOSE_STAGE:
		jiki->JMissilePaint();
		//GameScore += w;
		hitcheak->JikiVsEMissile();
		blast->BlastPaint();
		if (jiki->retLife() <= 0){
			PlaySoundA("sound\\exp.wav", NULL, (SND_ASYNC | SND_FILENAME));
			GameFlg = GAME_OVER;
		}
		break;
	case GAME_OVER:
		msg->MessagePaint("GameOver!!", 0xffff0000);
		break;
	case GAME_CLAER:
		msg->MessagePaint("GameClear!!", 0xff0000ff);
		break;
	}
	pSprite->End();
	pD3DDevice->EndScene();//シーン作成終了
	pD3DDevice->Present(NULL, NULL, NULL, NULL);
}