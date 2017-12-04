#include "stdafx.h"
#include "HitCheak.h"
#include "Msg.h"
#include <mmsystem.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

HitCheak::HitCheak(JIki *_jiki, Enemy  *_enemy,Blast  *_blast,SpAitem   *_SpAitems, JIkismall   *_jikiSmall,ssjiki    *_Ssjiki){
	jiki = _jiki;
	enemy = _enemy;
	blast = _blast;
	spAitems = _SpAitems;
	sjiki = _jikiSmall;
	Ssjiki = _Ssjiki;
	shit = false;
	sshit = false;
	sp = false;
}
int HitCheak::JMissileVsEnemy(int x,int y){
	int  sx, sy, ex, ey, p,ssx,ssy,exs,eys,zx,zy,fx,fy;
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
						if (hit == 4){
							PlaySoundA("sound\\soubi-02.wav", NULL, (SND_ASYNC | SND_FILENAME));
							spAitems->SpM = false;
							jiki->JMsw[i] = false;
							hit = 0;
							if (sp == false){
								shit = sjiki->retLife();
								sshit = Ssjiki->retLife();
								if (shit == false)sjiki->resetLife();
								else if (sshit == false)Ssjiki->resetLife();
								sp = true;
								return   50;
							}
							else return 0;
							
						}
						else { hit++; sp = false; }

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
						if (hit == 4){
							PlaySoundA("sound\\soubi-02.wav", NULL, (SND_ASYNC | SND_FILENAME));
							spAitems->SpM = false;
							sjiki->JMsw[l] = false;
							hit = 0;
							if (sp == false){
								sshit = Ssjiki->retLife();
								if (sshit == false) Ssjiki->resetLife();
								sp = true;
								return   50;
							}
							else return 0;

						}
						else { hit++; sp = false; }

					}
				}
			}
		}
	}	for (int m = 0; m < JMISSILE_SU; m++){
		if (Ssjiki->JMsw[m] == true){
			zx = Ssjiki->JMx[m] + JIKIMISSILE_W / 2;
			zy = Ssjiki->jMy[m] + JIKIMISSILE_H / 2;
			for (int l = 0; l < MAPENEMY_SU; l++){
				p = enemy->EMapNo[l];
				if (p != -1){
					fx = enemy->Ex[p];
				    fy = enemy->Ey[p];
					if (fx < zx && zx < fx + ENEMY_W)
						if (fy < zy && zy < fy + ENEMY_H){
							enemy->EMapNo[l] = -1;
							Ssjiki->JMsw[l] = false;
							blast->setBlast(ssx, ssy);
							PlaySoundA("sound\\01bom.wav", NULL, (SND_ASYNC | SND_FILENAME));
							return   10;
						}
				}
				else if (x < zx && zx < x + 32){
					if (y < zy && zy < y + 32){
						blast->setBlast(ssx, ssy);
						if (hit == 4){
							PlaySoundA("sound\\soubi-02.wav", NULL, (SND_ASYNC | SND_FILENAME));
							spAitems->SpM = false;
							Ssjiki->JMsw[l] = false;
							hit = 0;
							if (sp == false){
								shit = sjiki->retLife();
								if (shit == false) sjiki->resetLife();
								sp = true;
								return   50;
							}
							else return 0;
						}
						else {
							hit++; sp = false;
						}

					}
				}
			}
		}
	}

	return   0;
}
void HitCheak::JikiVsEMissile(){
	int jx, jy, ex, ey, r,mx,my,p,lx,ly,q;
	double wx, wy,sxw,syw,zx,zy;

	jx = jiki->retX() + JIKI_W / 2;
	jy = jiki->retY() + JIKI_H / 2;
	mx = sjiki->retX() + 25 / 2;
	my = sjiki->retY() + 32 / 2;
	lx = Ssjiki->retX() + 25 / 2;
	ly = Ssjiki->retY() + 32 / 2;
	for (int i = 0; i < EMISSILE_SU; i++){
		if (enemy->EMsw[i] == true){
			ex = enemy->EMx[i] + EMISSILE_W / 2;
			ey = enemy->EMy[i] + EMISSILE_H / 2;
			wx = abs(jx - ex);
			wy = abs(jy - ey);
			sxw = abs(mx - ex);
			syw = abs(my - ey);
			zx = abs(lx - ex);
			zy = abs(ly - ey);
			r = (int)sqrt(wx * wx + wy * wy);
			p = (int)sqrt(sxw * sxw + syw * syw);
			q = (int)sqrt(zx * zx + zy * zy);
			if (r < (15 + 5)){
				enemy->EMsw[i] = false;
				blast->setBlast(ex, ey);
				jiki->DownLife();
				return;
			}
			else if (p < (15 + 5)){
				enemy->EMsw[i] = false;
				blast->setBlast(ex, ey);
				sjiki->DownLife();
				return;
			}
			else if (q < (15 + 5)){
				enemy->EMsw[i] = false;
				blast->setBlast(ex, ey);
				Ssjiki->DownLife();
				return;
			}
			
		}
	}
}