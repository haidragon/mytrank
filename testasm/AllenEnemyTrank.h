
typedef struct ENEMYTRANK
{
	int x, y;//我的坦克中心坐标
	int m, n;//我的坦克子弹的坐标
	int state; //我的坦克方向(1上，2下，3左，4右)
	int dir;//我的坦克子弹射向
	int life;//生命
	int skin;//皮肤
	int weapons;//武器
	int lv;//等级
	int speed;//速度
			  //颜色
	char color;
	//是否要清理
	int clear;
}EnemyTrank, *PenemyTrank;

void init_enemy_tank(PenemyTrank myenemytrank,int x, int y);
//打印坦克
void print_enemy_tank(EnemyTrank myenemytrank);
//清除坦克
void clear_enemy_tank(EnemyTrank myenemytrank);
void EnemyTankMove(PenemyTrank myenemytrank);
int EnemyChangeDir(PenemyTrank myenemytrank,char cDir);
//是否在home附近
int canenemymove(PenemyTrank myenemytrank);

extern EnemyTrank myEnemyTrank;
extern EnemyTrank myEnemyTrank1;
extern EnemyTrank myEnemyTrank2;
extern EnemyTrank myEnemyTrank3;
extern EnemyTrank myEnemyTrank4;
extern EnemyTrank myEnemyTrank5;
extern EnemyTrank myEnemyTrank6;
extern EnemyTrank myEnemyTrank7;
extern EnemyTrank myEnemyTrank8;
extern EnemyTrank myEnemyTrank9;
extern EnemyTrank myEnemyTrank10;
//检测是否碰到用户坦克或子弹
void enemytranklife(PenemyTrank  myUserTrank);