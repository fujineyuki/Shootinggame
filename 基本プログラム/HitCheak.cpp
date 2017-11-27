#include "stdafx.h"
#include "HitCheak.h"
#include "Msg.h"
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

HitCheak::HitCheak(JIki *_jiki, Enemy  *_enemy,Blast  *_blast,SpAitem   *_SpAitems){
	jiki = _jiki;
	enemy = _enemy;
	blast = _blast;
	spAitems = _SpAitems;
}
int HitCheak::JMissileVsEnemy(int x,int y){
	int  sx, sy, ex, ey, p;
	for (int i = 0; i < JMISSILE_SU; i++){
		if (jiki->JMsw[i] == true){
			sx = jiki->JMx[i] + JIKIMISSILE_W / 2;
			sy = jiki->jMy[i] + JIKIMISSILE_H / 2;
			for (int j = 0; j < MAPENEMY_SU; j++){
				p = enemy->EMapNo[j];
				if (p != -1){
					ex = enemy->Ex[p];
					ey = enemy->Ey[p];
					if (ex < sx && sx < ex + ENEMY_W)
						if (ey < sy && sy < ey + ENEMY_H){
							enemy->EMapNo[j] = -1;
							jiki->JMsw[i] = false;
							blast->setBlast(sx, sy);
							PlaySoundA("sound\\01bom.wav", NULL, (SND_ASYNC | SND_FILENAME));
							return   10;
						}
				}
				else if (x < sx && sx < x + 32){
					if (y < sy && sy < y + 32){
						blast->setBlast(sx, sy);
						if (hit >= 3){
							spAitems->SpM = false;
							jiki->JMsw[i] = false;
							hit = 0;
							PlaySoundA("sound\\soubi-02.wav", NULL, (SND_ASYNC | SND_FILENAME));
							return   50;
							
						}
						else hit++;

					}
				}
			}
		}
	}

	return   0;
}
void HitCheak::JikiVsEMissile(){
	int jx, jy, ex, ey, r;
	double wx, wy;

	jx = jiki->retX() + JIKI_W / 2;
	jy = jiki->retY() + JIKI_H / 2;
	for (int i = 0; i < EMISSILE_SU; i++){
		if (enemy->EMsw[i] == true){
			ex = enemy->EMx[i] + EMISSILE_W / 2;
			ey = enemy->EMy[i] + EMISSILE_H / 2;
			wx = abs(jx - ex);
			wy = abs(jy - ey);
			r = (int)sqrt(wx * wx + wy * wy);
			if (r < (15 + 5)){
				enemy->EMsw[i] = false;
				blast->setBlast(ex, ey);
				jiki->DownLife();
				return;
			}
			
		}
	}
}