#include "AllenUserTrank.h"
#include "AllenEnemyTrank.h"
typedef struct PBULLET
{
	int x;
	int y;
	int dir;
	int life;
}Bullet, *Pbullet;

//��ʼ���ӵ�
void init_User_Bullet(UserTrank userTrank,Pbullet userBullet);
//�����ӵ�
void create_User_Bullet(UserTrank userTrank, Pbullet userBullet);
//��ӡ�ӵ�
void print_User_Bullet(Bullet userBullet);
//����ӵ�
void clear_User_Bullet(Bullet userBullet);
//�ƶ�����
void User_Bullet_Move(Pbullet userBullet);
//�ж��ӵ��Ƿ���home����
int User_Bullet_home(Pbullet userBullet);


//////////////////////////////////////////////////////////////

//��ʼ���ӵ�
void init_Enemy_Bullet(EnemyTrank enemyTrank, Pbullet userBullet);
//�����ӵ�
void create_Enemy_Bullet(EnemyTrank enemyTrank, Pbullet userBullet);
//��ӡ�ӵ�
void print_Enemy_Bullet(Bullet userBullet);
//����ӵ�
void clear_Enemy_Bullet(Bullet userBullet);
//�ƶ�����
void Enemy_Bullet_Move(Pbullet pbullet);
//�ж��ӵ��Ƿ���home����
int Enemy_Bullet_home(Pbullet pbullet);
//�û�
extern Bullet UserBullet[100];
//����
extern Bullet EnemyBullet[100];
////����2
//extern Bullet EnemyBullet1[100];
////����3
//extern Bullet EnemyBullet2[100];
//extern list<Bullet> ListBullet;