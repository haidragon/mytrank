
typedef struct ENEMYTRANK
{
	int x, y;//�ҵ�̹����������
	int m, n;//�ҵ�̹���ӵ�������
	int state; //�ҵ�̹�˷���(1�ϣ�2�£�3��4��)
	int dir;//�ҵ�̹���ӵ�����
	int life;//����
	int skin;//Ƥ��
	int weapons;//����
	int lv;//�ȼ�
	int speed;//�ٶ�
			  //��ɫ
	char color;
	//�Ƿ�Ҫ����
	int clear;
}EnemyTrank, *PenemyTrank;

void init_enemy_tank(PenemyTrank myenemytrank,int x, int y);
//��ӡ̹��
void print_enemy_tank(EnemyTrank myenemytrank);
//���̹��
void clear_enemy_tank(EnemyTrank myenemytrank);
void EnemyTankMove(PenemyTrank myenemytrank);
int EnemyChangeDir(PenemyTrank myenemytrank,char cDir);
//�Ƿ���home����
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
//����Ƿ������û�̹�˻��ӵ�
void enemytranklife(PenemyTrank  myUserTrank);