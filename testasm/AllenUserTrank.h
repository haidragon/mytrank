
typedef struct USERTRANK2
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
}UserTrank, *PUserTrank;

void init_my_tank(PUserTrank myuse,int x, int y);
//��ӡ̹��
void print_my_tank(UserTrank myuse);
//���̹��
void clear_my_tank(UserTrank myuse);
void TankMove(PUserTrank myUserTrank);
int ChangeDir(PUserTrank  myUserTrank,char cDir);
int ChangeDir2(PUserTrank  myUserTrank, char cDir);
int canusermove(PUserTrank myUserTrank);
extern UserTrank myuser;
extern UserTrank myuser2;
void usetranklife(PUserTrank  myUserTrank);
