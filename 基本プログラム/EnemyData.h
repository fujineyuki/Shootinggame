#include "Const.h"
#include "InitDX.h"
class EnemyData{
private:
public :
	int Emovetype[ENEMY_SU];
	int Ex[ENEMY_SU], Ey[ENEMY_SU];
	int EspeedX[ENEMY_SU], EspeedY[ENEMY_SU];
	int EmissileFlg[ENEMY_SU];
	int EnemyDataPoint;
	int EMx[EMISSILE_SU], EMy[EMISSILE_SU];
	int EMspeedX[EMISSILE_SU], EMspeedY[EMISSILE_SU];
	bool EMsw[EMISSILE_SU];
	EnemyData();
	void DataInit();
};