#include "AllenUserTrank.h"
#include "AllenEnemyTrank.h"
typedef struct PBULLET
{
	int x;
	int y;
	int dir;
	int life;
}Bullet, *Pbullet;

//初始化子弹
void init_User_Bullet(UserTrank userTrank,Pbullet userBullet);
//创建子弹
void create_User_Bullet(UserTrank userTrank, Pbullet userBullet);
//打印子弹
void print_User_Bullet(Bullet userBullet);
//清除子弹
void clear_User_Bullet(Bullet userBullet);
//移动所有
void User_Bullet_Move(Pbullet userBullet);
//判断子弹是否在home附近
int User_Bullet_home(Pbullet userBullet);


//////////////////////////////////////////////////////////////

//初始化子弹
void init_Enemy_Bullet(EnemyTrank enemyTrank, Pbullet userBullet);
//创建子弹
void create_Enemy_Bullet(EnemyTrank enemyTrank, Pbullet userBullet);
//打印子弹
void print_Enemy_Bullet(Bullet userBullet);
//清除子弹
void clear_Enemy_Bullet(Bullet userBullet);
//移动所有
void Enemy_Bullet_Move(Pbullet pbullet);
//判断子弹是否在home附近
int Enemy_Bullet_home(Pbullet pbullet);
//用户
extern Bullet UserBullet[100];
//敌人
extern Bullet EnemyBullet[100];
////敌人2
//extern Bullet EnemyBullet1[100];
////敌人3
//extern Bullet EnemyBullet2[100];
//extern list<Bullet> ListBullet;