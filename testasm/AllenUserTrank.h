
typedef struct USERTRANK2
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
}UserTrank, *PUserTrank;

void init_my_tank(PUserTrank myuse,int x, int y);
//打印坦克
void print_my_tank(UserTrank myuse);
//清除坦克
void clear_my_tank(UserTrank myuse);
void TankMove(PUserTrank myUserTrank);
int ChangeDir(PUserTrank  myUserTrank,char cDir);
int ChangeDir2(PUserTrank  myUserTrank, char cDir);
int canusermove(PUserTrank myUserTrank);
extern UserTrank myuser;
extern UserTrank myuser2;
void usetranklife(PUserTrank  myUserTrank);
