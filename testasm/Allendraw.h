#include <windows.h>
#define KONG 0
#define USERTANKMAP 1
#define ENETANKMAP 2
#define BOMBMAP 3
#define QINGMAP 4
#define USERBULLETMAP 6
#define ENETBULLETMAP 7
#define HOME 8
#define LIFE 9
#define CAOMAP 10
#define ZHANGAIMAP  11
#define LONG 40
#define WIDE 40
#define USERTANK "■"
#define ZHANGAI  "■"
#define ENETANK "■"//◎●※∷
#define BULLET "◎"
#define CAO "※"
#define TANK_DIR_UP 0
#define TANK_DIR_DW 2
#define TANK_DIR_LF 1
#define TANK_DIR_RH 3
#define TANKUP "∧"
#define TANKDW "∨"
#define TANKLF "＜"
#define TANKRH "＞"
extern int g_map[40][40];
BOOL SetWindowInfo(char* pTitle, int nWid, int nHeight);
//用于隐藏光标的函数
void HideCursor();
//打印边界
void my_print();
void PrintChar(int Wide, int High, char*pszChar, WORD wAttr);
//初始化地图
void initmap();
//画
void darw();
