#include "JIki.h"
#include "Enemy.h"
#include "Const.h"
#include "Blast.h"
#include "SpAitem.h"

class HitCheak{
private:
	JIki    *jiki;
	Enemy   *enemy;
	Blast   *blast;
	SpAitem *spAitems;
	Option  *optiion;
	int hit;
public :
	HitCheak(JIki   *, Enemy   *,Blast    *,SpAitem    *);
	int JMissileVsEnemy(int x,int y);
	void  JikiVsEMissile();
};