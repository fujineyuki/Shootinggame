#include "stdafx.h"
#include "Const.h"
#include "EnemyData.h"
EnemyData::EnemyData(){
	DataInit();
}
void EnemyData::DataInit(){
	int w = 0;
	EnemyDataPoint = 0;

	Emovetype[w] = 0;  Ex[w] = 20;  Ey[w] = -20;   EspeedX[w] = -1;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] = -1;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 130;  Ey[w] = -20;   EspeedX[w] = -1;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] = -1;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 130;  Ey[w] = -20;   EspeedX[w] = -1;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;

	//�P�T�@
	Emovetype[w] = 1;  Ex[w] = 225;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 2; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 1;  Ex[w] = 175;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 3; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 1;  Ex[w] = 125;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 1;  Ex[w] = 50;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 3; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 1;  Ex[w] = 0;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 2; EmissileFlg[w] = 0;   w++;

	//�O�@�@
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;

	//�T�@  
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;

	//�P�O�@ 
	Emovetype[w] = 0;  Ex[w] = 20;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 130;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 130;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;

	//�P�T�@
	Emovetype[w] = 1;  Ex[w] = 250;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 1;  Ex[w] = 200;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 1;  Ex[w] = 150;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 1;  Ex[w] = 250;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 1;  Ex[w] = 200;  Ey[w] = -20;   EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;

	//�Q�O�@  
	Emovetype[w] = 0;  Ex[w] = -20;  Ey[w] = 10;    EspeedX[w] = 4;  EspeedY[w] = 0; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = -20;  Ey[w] = 40;    EspeedX[w] = 4;  EspeedY[w] = 0; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 10;    EspeedX[w] = -4;  EspeedY[w] = 0; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 40;    EspeedX[w] = -4;  EspeedY[w] = 0; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 130;  Ey[w] = -20;    EspeedX[w] = 0;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;

	//�Q�T�@
	Emovetype[w] = 0;  Ex[w] = 100;  Ey[w] = -20;   EspeedX[w] = 4;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 100;  Ey[w] = -20;   EspeedX[w] = 4;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 100;  Ey[w] = -20;   EspeedX[w] = 4;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 100;  Ey[w] = -20;   EspeedX[w] = 4;  EspeedY[w] = 4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 100;  Ey[w] = -20;   EspeedX[w] = 4;  EspeedY[w] = 4; EmissileFlg[w] = 0;   w++;            //30�@

	//�R�O�@ 
	Emovetype[w] = 2;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 2;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 2;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 2;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 2;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;

	//�R�T�@
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	
	//�S�O�@
	Emovetype[w]= 0;  Ex[w] = 20;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =130;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =130;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	//�S�T�@
	Emovetype[w]= 1;  Ex[w] =250;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 1;  Ex[w] =200;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 1;  Ex[w] =150;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 1;  Ex[w] =250;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 1;  Ex[w] =200;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	//�T�O�@
	Emovetype[w]= 0;  Ex[w] =-20;  Ey[w] = 10;    EspeedX[w] =  4;  EspeedY[w] =  0;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =-20;  Ey[w] = 40;    EspeedX[w] =  4;  EspeedY[w] =  0;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 10;    EspeedX[w] = -4;  EspeedY[w] =  0;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 40;    EspeedX[w] = -4;  EspeedY[w] =  0;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =150;  Ey[w] =-20;    EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	//�T�T�@
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;            //60�@
	//�U�O�@
	Emovetype[w]= 0;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	//�U�T�@
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	//�V�O�@
	Emovetype[w]= 0;  Ex[w] = 20;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =130;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =130;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	//�V�T�@
	Emovetype[w]= 0;  Ex[w] =250;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =200;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =150;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =250;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =200;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	//�W�O�@
	Emovetype[w]= 0;  Ex[w] =-20;  Ey[w] = 10;    EspeedX[w] =  4;  EspeedY[w] =  0;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =-20;  Ey[w] = 40;    EspeedX[w] =  4;  EspeedY[w] =  0;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 10;    EspeedX[w] = -4;  EspeedY[w] =  0;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 40;    EspeedX[w] = -4;  EspeedY[w] =  0;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =150;  Ey[w] =-20;    EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	//�W�T�@
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	//�X�O�@
	Emovetype[w]= 2;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 2;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 2;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 2;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 2;  Ex[w] =-10;  Ey[w] = 200;   EspeedX[w] =  4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	//�P�O�O�@
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 200;   EspeedX[w] = -4;  EspeedY[w] = -4;EmissileFlg[w] =  0;   w++;
	//�P�O�T�@
	Emovetype[w]= 0;  Ex[w] = 20;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =130;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] = 70;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =130;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	//�P�P�O�@
	Emovetype[w]= 0;  Ex[w] =250;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =200;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =150;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =250;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =200;  Ey[w] = -20;   EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	//�P�P�T�@
	Emovetype[w]= 0;  Ex[w] =-20;  Ey[w] = 10;    EspeedX[w] =  4;  EspeedY[w] =  0;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =-20;  Ey[w] = 40;    EspeedX[w] =  4;  EspeedY[w] =  0;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 10;    EspeedX[w] = -4;  EspeedY[w] =  0;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =300;  Ey[w] = 40;    EspeedX[w] = -4;  EspeedY[w] =  0;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =150;  Ey[w] =-20;    EspeedX[w] =  0;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	//�P�Q�O�@
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  1;   w++;
	Emovetype[w]= 0;  Ex[w] =100;  Ey[w] = -20;   EspeedX[w] =  4;  EspeedY[w] =  4;EmissileFlg[w] =  0;   w++;            //120�@

	//125�@�@
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 10;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 10;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 10;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 10;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = -10;  Ey[w] = 200;   EspeedX[w] = 10;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;

	//130�@  
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -10;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -10;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -10;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -10;  EspeedY[w] = -4; EmissileFlg[w] = 1;   w++;
	Emovetype[w] = 0;  Ex[w] = 300;  Ey[w] = 200;   EspeedX[w] = -10;  EspeedY[w] = -4; EmissileFlg[w] = 0;   w++;
}