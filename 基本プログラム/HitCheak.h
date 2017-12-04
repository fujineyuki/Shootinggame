#include "JIki.h"
#include "Enemy.h"
#include "Const.h"
#include "Blast.h"
#include "SpAitem.h"
#include "smallJiki.h"
#include "ssjiki.h"

class HitCheak{
private:
	JIki    *jiki;
	Enemy   *enemy;
	Blast   *blast;
	SpAitem *spAitems;
	Option  *optiion;
	JIkismall   *sjiki;
	ssjiki      *Ssjiki;
	bool shit,sshit,sp;
	int hit;
public :
	HitCheak(JIki   *, Enemy   *,Blast    *,SpAitem    *,JIkismall  *,ssjiki    *);
	int JMissileVsEnemy(int x,int y);
	void  JikiVsEMissile();
};