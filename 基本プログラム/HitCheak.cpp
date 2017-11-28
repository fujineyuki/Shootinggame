#include "stdafx.h"
#include "HitCheak.h"
#include "Msg.h"
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

HitCheak::HitCheak(JIki *_jiki, Enemy  *_enemy,Blast  *_blast,SpAitem   *_SpAitems, JIkismall   *_jikiSmall){
	jiki = _jiki;
	enemy = _enemy;
	blast = _blast;
	spAitems = _SpAitems;
	sjiki = _jikiSmall;
}
int HitCheak::JMissileVsEnemy(int x,int y){
	int  sx, sy, ex, ey, p,ssx,ssy,exs,eys,r;
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
	for (int m = 0; m < JMISSILE_SU; m++){
		if (sjiki->JMsw[m] == true){
			ssx = sjiki->JMx[m] + JIKIMISSILE_W / 2;
			ssy = sjiki->jMy[m] + JIKIMISSILE_H / 2;
			for (int l = 0; l < MAPENEMY_SU;l++){
				p = enemy->EMapNo[l];
				if (p != -1){
					exs = enemy->Ex[p];
					eys = enemy->Ey[p];
					if (exs < ssx && ssx < exs + ENEMY_W)
						if (eys < ssy && ssy < eys + ENEMY_H){
							enemy->EMapNo[l] = -1;
							sjiki->JMsw[l] = false;
							blast->setBlast(ssx, ssy);
							PlaySoundA("sound\\01bom.wav", NULL, (SND_ASYNC | SND_FILENAME));
							return   10;
						}
				}
				else if (x < ssx && ssx < x + 32){
					if (y < ssy && ssy < y + 32){
						blast->setBlast(ssx, ssy);
						if (hit >= 3){
							spAitems->SpM = false;
							sjiki->JMsw[l] = false;
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
	int jx, jy, ex, ey, r,mx,my,p;
	double wx, wy,sxw,syw;

	jx = jiki->retX() + JIKI_W / 2;
	jy = jiki->retY() + JIKI_H / 2;
	mx = sjiki->retX() + 25 / 2;
	my = sjiki->retY() + 32 / 2;
	for (int i = 0; i < EMISSILE_SU; i++){
		if (enemy->EMsw[i] == true){
			ex = enemy->EMx[i] + EMISSILE_W / 2;
			ey = enemy->EMy[i] + EMISSILE_H / 2;
			wx = abs(jx - ex);
			wy = abs(jy - ey);
			sxw = wx = abs(mx - ex);
			syw = abs(my - ey);
			r = (int)sqrt(wx * wx + wy * wy);
			p = (int)sqrt(sxw * sxw + syw * syw);
			if (r < (15 + 5)){
				enemy->EMsw[i] = false;
				blast->setBlast(ex, ey);
				jiki->DownLife();
				return;
			}
			else if (p < (15 + 5)){
				enemy->EMsw[i] = false;
				blast->setBlast(ex, ey);
				jiki->DownLife();
				return;
			}
			
		}
	}
}