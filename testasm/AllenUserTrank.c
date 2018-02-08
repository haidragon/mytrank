#include "AllenUserTrank.h"
#include "Allendraw.h"
#include<stdio.h>
#include <windows.h>
#include <conio.h>
int oldDir = 0;
void init_my_tank(PUserTrank myuse,int x, int y) {
	myuse->x = x;
	myuse->y = y;
	myuse->dir = TANK_DIR_UP;
	myuse->life = 100;
	myuse->color = 0x4;
	for (int i = (*myuse).x - 1; i <= (*myuse).x + 1; i++) {
		for (int j = (*myuse).y - 1; j <= (*myuse).y + 1; j++) {
			//生成坦克时只要在草上不打印那个点
			if (g_map[i][j] != CAOMAP) {
				g_map[i][j] = USERTANKMAP;
			}
		}
	}
	print_my_tank(*myuse);
}
UserTrank myuser;

void print_my_tank(UserTrank myuse) {
	switch (myuse.dir)
	{
	case TANK_DIR_LF:
		if ((myuse.x + 1) == 18) break;

		if (g_map[myuse.x][myuse.y] == CAOMAP) {  }
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y] = USERTANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y-1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y - 1] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x-1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x ][myuse.y+1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y + 1] = USERTANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x+1][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x + 1][myuse.y - 1] = USERTANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y + 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x + 1][myuse.y + 1] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, TANKLF, rand() % 0xf + 0x0);
			g_map[myuse.x+1][myuse.y] = USERTANKMAP;
		}
		///////////////////////////////////////////////////////////
		break;
	case TANK_DIR_RH:
		if ((myuse.x + 1) == 22) break;
		if (g_map[myuse.x][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x+1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x + 1][myuse.y] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x ][myuse.y-1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y - 1] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y + 1] = USERTANKMAP;
		}

		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x-1][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y - 1] = USERTANKMAP;
		}

		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y + 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y + 1] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, TANKRH, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y] = USERTANKMAP;
		}
		
		break;
	case TANK_DIR_UP:
		if (g_map[myuse.x ][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y] = USERTANKMAP;
		}
		
		//////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y-1] == CAOMAP) {

		}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y - 1] = USERTANKMAP;
		}

		
		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x+1][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y + 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x + 1][myuse.y + 1] = USERTANKMAP;
		}
		
		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x + 1][myuse.y] = USERTANKMAP;
		}
		
		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y-1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y - 1] = USERTANKMAP;
		}

	
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y ] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y] = USERTANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y+1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y + 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y + 1] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, TANKUP, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y + 1] = USERTANKMAP;
		}

		
		break;
	case TANK_DIR_DW:
		if ((myuse.y + 1) == 35) break;
		if (g_map[myuse.x][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y] = USERTANKMAP;
		}

		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x-1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y-1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x - 1][myuse.y - 1] = USERTANKMAP;
		}
		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y +1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y + 1] = USERTANKMAP;
		}

		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x+1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x + 1][myuse.y] = USERTANKMAP;
		}

		
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y-1] == CAOMAP) {}
		else {

			PrintChar(myuse.x + 1, myuse.y - 1, USERTANK, rand() % 0xf + 0x0);
			g_map[myuse.x + 1][myuse.y - 1] = USERTANKMAP;
		}
		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x ][myuse.y - 1] == CAOMAP) {

		}
		else {

			PrintChar(myuse.x, myuse.y - 1, TANKDW, rand() % 0xf + 0x0);
			g_map[myuse.x][myuse.y - 1] = USERTANKMAP;
		}

		
		break;
	default:
		break;
	}

}

//清除坦克
void clear_my_tank(UserTrank myuse) {
	for (int i = myuse.x - 1; i <= myuse.x + 1; i++) {
		for (int j = myuse.y - 1; j <= myuse.y + 1; j++) {
			if (g_map[i][j] == USERTANKMAP) {
				PrintChar(i, j, "  ", 0x00);
				g_map[i][j] == KONG;
			}
		}
	}
}

void TankMove(PUserTrank myUserTrank)
{
	usetranklife(myUserTrank);
	if (canusermove(myUserTrank)) return;
	if ((myUserTrank->x) > 2 && (myUserTrank->x)<=36 && (myUserTrank->y) >=3 &&( myUserTrank->y)<=36)
	{
		//清理所有
		clear_my_tank(*myUserTrank);

		switch (myUserTrank->dir) {
		case TANK_DIR_UP:
			myUserTrank->y--;
			break;
		case TANK_DIR_DW:
			myUserTrank->y++;
			break;
		case TANK_DIR_LF:
			myUserTrank->x--;
			break;
		case TANK_DIR_RH:
			myUserTrank->x++;
			break;
		}
		//给坦克新方向
		myUserTrank->dir = myUserTrank->dir;
		print_my_tank(*myUserTrank);
		return;
	}
	else if (myUserTrank->x <=2) {
		//清理所有
		clear_my_tank(*myUserTrank);
		//给坦克新方向
		myUserTrank->x++;
		ChangeDir(myUserTrank,'d');
		print_my_tank(*myUserTrank);
		return;
	}
	else if (myUserTrank->y <= 2) {
		//清理所有
		clear_my_tank(*myUserTrank);
		myUserTrank->y++;
		//给坦克新方向
		ChangeDir(myUserTrank,'s');
		print_my_tank(*myUserTrank);
		return;
	}
	else if (myUserTrank->x >= 37) {
		//清理所有
		clear_my_tank(*myUserTrank);
		//给坦克新方向
		myUserTrank->x--;
		ChangeDir(myUserTrank,'a');
		print_my_tank(*myUserTrank);
		return;
	}
	else if (myUserTrank->y >= 37) {

		//清理所有
		clear_my_tank(*myUserTrank);
		//给坦克新方向
		myUserTrank->y--;
		ChangeDir(myUserTrank,'w');
		print_my_tank(*myUserTrank);
		return;
	}

}

int ChangeDir(PUserTrank myUserTrank,char cDir) {
	int nNewDir = -1;
	switch (cDir) {
	case 'W':
	case 'w':
		nNewDir = TANK_DIR_UP;
		break;
	case 's':
	case 'S':
		nNewDir = TANK_DIR_DW;
		break;
	case 'a':
	case 'A':
		nNewDir = TANK_DIR_LF;
		break;
	case 'd':
	case 'D':
		nNewDir = TANK_DIR_RH;
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'e':
	case 'E':
		_getch();
		break;
	default:
		break;
	}
	//if (myUserTrank->dir == cDir) TankMove(myUserTrank);
	myUserTrank->dir = nNewDir;

	return 1;
}

int ChangeDir2(PUserTrank myUserTrank, char cDir) {
	int nNewDir = -1;
	switch (cDir) {
	case 'i':
	case 'I':
		nNewDir = TANK_DIR_UP;
		break;
	case 'k':
	case 'K':
		nNewDir = TANK_DIR_DW;
		break;
	case 'j':
	case 'J':
		nNewDir = TANK_DIR_LF;
		break;
	case 'l':
	case 'L':
		nNewDir = TANK_DIR_RH;
		break;
	default:
		break;
	}
	if (myUserTrank->dir == cDir) TankMove(myUserTrank);
	myUserTrank->dir = nNewDir;

	return 1;
}
//
int canusermove(PUserTrank myUserTrank) {
	if (((g_map[2 + myUserTrank->x][myUserTrank->y] == ZHANGAIMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == ZHANGAIMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == ZHANGAIMAP) && myUserTrank->dir == TANK_DIR_RH) ||
		((g_map[-2 + myUserTrank->x][myUserTrank->y] == ZHANGAIMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == ZHANGAIMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == ZHANGAIMAP) && myUserTrank->dir == TANK_DIR_LF) ||
		((g_map[myUserTrank->x][2 + myUserTrank->y] == ZHANGAIMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == ZHANGAIMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == ZHANGAIMAP) && myUserTrank->dir == TANK_DIR_DW) ||
		((g_map[myUserTrank->x][-2 + myUserTrank->y] == ZHANGAIMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == ZHANGAIMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == ZHANGAIMAP) && myUserTrank->dir == TANK_DIR_UP)
		) {
		switch (myUserTrank->dir)
		{
		case TANK_DIR_UP:
			
			clear_enemy_tank(*myUserTrank);
			ChangeDir(myUserTrank, 's');
			break;
		case TANK_DIR_DW:
			clear_enemy_tank(*myUserTrank);
			ChangeDir(myUserTrank, 'w');
			break;
		case TANK_DIR_LF:
			clear_enemy_tank(*myUserTrank);
			ChangeDir(myUserTrank, 'd');
			break;
		case TANK_DIR_RH:
			clear_enemy_tank(*myUserTrank);
			ChangeDir(myUserTrank, 'a');
			break;
		default:
			break;
		}
		return 1;
	}
	if ((myUserTrank->x) >= 16 && (myUserTrank->x) <= 24 &&( myUserTrank->y) >= 33 && (myUserTrank->dir != TANK_DIR_UP))
	{
		if ((myUserTrank->x) <= 16) {
			clear_my_tank(*myUserTrank);
			myUserTrank->x -= 1;
			print_my_tank(*myUserTrank);
			return 1;
		}
		if ((myUserTrank->x) >= 24) {
			clear_my_tank(*myUserTrank);
			myUserTrank->x += 1;
			print_my_tank(*myUserTrank);
			return 1;
		}
		if ((myUserTrank->y) <= 34) {
			clear_my_tank(*myUserTrank);
			myUserTrank->y -= 1;
			print_my_tank(*myUserTrank);
			return 1;
		}
	}
	return 0;
}


void usetranklife(PUserTrank  myUserTrank) {
	//检测是否是敌方坦克
	if (((g_map[2 + myUserTrank->x][myUserTrank->y] == ENETANKMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == ENETANKMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == ENETANKMAP) && myUserTrank->dir == TANK_DIR_RH) ||
		((g_map[-2 + myUserTrank->x][myUserTrank->y] == ENETANKMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == ENETANKMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == ENETANKMAP) && myUserTrank->dir == TANK_DIR_LF) ||
		((g_map[myUserTrank->x][2 + myUserTrank->y] == ENETANKMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == ENETANKMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == ENETANKMAP) && myUserTrank->dir == TANK_DIR_DW) ||
		((g_map[myUserTrank->x][-2 + myUserTrank->y] == ENETANKMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == ENETANKMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == ENETANKMAP) && myUserTrank->dir == TANK_DIR_UP)
		||
		//检测是是否敌方子弹
		((g_map[2 + myUserTrank->x][myUserTrank->y] == ENETBULLETMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == ENETBULLETMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == ENETBULLETMAP) && myUserTrank->dir == TANK_DIR_RH) ||
		((g_map[-2 + myUserTrank->x][myUserTrank->y] == ENETBULLETMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == ENETBULLETMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == ENETBULLETMAP) && myUserTrank->dir == TANK_DIR_LF) ||
		((g_map[myUserTrank->x][2 + myUserTrank->y] == ENETBULLETMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == ENETBULLETMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == ENETBULLETMAP) && myUserTrank->dir == TANK_DIR_DW) ||
		((g_map[myUserTrank->x][-2 + myUserTrank->y] == ENETBULLETMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == ENETBULLETMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == ENETBULLETMAP) && myUserTrank->dir == TANK_DIR_UP)
		)
	{
		myUserTrank->life -= 10;
	}
}