#include "AllenUserTrank.h"
#include "AllenEnemyTrank.h"
#include "Allendraw.h"
#include<stdio.h>
#include <windows.h>
#include <conio.h>

void init_enemy_tank(PenemyTrank myenemytrank,int x, int y) {
	myenemytrank->x = x;
	myenemytrank->y = y;
	myenemytrank->dir = TANK_DIR_DW;
	myenemytrank->life = 20;
	myenemytrank->color = 0x5;
	//在地理坐标中设置坦克中心
	g_map[x][y] = ENETANKMAP;
	print_enemy_tank(*myenemytrank);
}
//


void print_enemy_tank(EnemyTrank myuse) {
	switch (myuse.dir)
	{
	case TANK_DIR_LF:
		if ((myuse.x + 1) == 18) break;

		if (g_map[myuse.x][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, 0x5);
			g_map[myuse.x][myuse.y] = ENETANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x][myuse.y - 1] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, USERTANK, 0x5);
			g_map[myuse.x - 1][myuse.y] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, USERTANK, 0x5);
			g_map[myuse.x][myuse.y + 1] = ENETANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x + 1][myuse.y - 1] = ENETANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y + 1, USERTANK, 0x5);
			g_map[myuse.x + 1][myuse.y + 1] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, TANKLF, 0x5);
			g_map[myuse.x + 1][myuse.y] = ENETANKMAP;
		}
		///////////////////////////////////////////////////////////
		break;
	case TANK_DIR_RH:
		if ((myuse.x + 1) == 22) break;
		if (g_map[myuse.x][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, 0x5);
			g_map[myuse.x][myuse.y] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, USERTANK, 0x5);
			g_map[myuse.x + 1][myuse.y] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x][myuse.y - 1] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, USERTANK, 0x5);
			g_map[myuse.x][myuse.y + 1] = ENETANKMAP;
		}


		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x - 1][myuse.y - 1] = ENETANKMAP;
		}


		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y + 1, USERTANK, 0x5);
			g_map[myuse.x - 1][myuse.y + 1] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, TANKRH, 0x5);
			g_map[myuse.x - 1][myuse.y] = ENETANKMAP;
		}

		break;
	case TANK_DIR_UP:
		if (g_map[myuse.x][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, 0x5);
			g_map[myuse.x][myuse.y] = ENETANKMAP;
		}

		//////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y - 1] == CAOMAP) {

		}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x][myuse.y - 1] = ENETANKMAP;
		}


		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y + 1, USERTANK, 0x5);
			g_map[myuse.x + 1][myuse.y + 1] = ENETANKMAP;
		}

		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, USERTANK, 0x5);
			g_map[myuse.x + 1][myuse.y] = ENETANKMAP;
		}

		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x][myuse.y - 1] = ENETANKMAP;
		}


		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, USERTANK, 0x5);
			g_map[myuse.x - 1][myuse.y] = ENETANKMAP;
		}
		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y + 1, USERTANK, 0x5);
			g_map[myuse.x - 1][myuse.y + 1] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, TANKUP, 0x5);
			g_map[myuse.x][myuse.y + 1] = ENETANKMAP;
		}


		break;
	case TANK_DIR_DW:
		if ((myuse.y + 1) == 35) break;
		if (g_map[myuse.x][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y, USERTANK, 0x5);
			g_map[myuse.x][myuse.y] = ENETANKMAP;
		}


		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y, USERTANK, 0x5);
			g_map[myuse.x - 1][myuse.y] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x - 1][myuse.y - 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x - 1, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x - 1][myuse.y - 1] = ENETANKMAP;
		}

		///////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y + 1] == CAOMAP) {}
		else {
			PrintChar(myuse.x, myuse.y + 1, USERTANK, 0x5);
			g_map[myuse.x][myuse.y + 1] = ENETANKMAP;
		}


		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y] == CAOMAP) {}
		else {
			PrintChar(myuse.x + 1, myuse.y, USERTANK, 0x5);
			g_map[myuse.x + 1][myuse.y] = ENETANKMAP;
		}


		///////////////////////////////////////////////////////////
		if (g_map[myuse.x + 1][myuse.y - 1] == CAOMAP) {}
		else {

			PrintChar(myuse.x + 1, myuse.y - 1, USERTANK, 0x5);
			g_map[myuse.x + 1][myuse.y - 1] = ENETANKMAP;
		}
		/////////////////////////////////////////////////////////////
		if (g_map[myuse.x][myuse.y - 1] == CAOMAP) {

		}
		else {

			PrintChar(myuse.x, myuse.y - 1, TANKDW, 0x5);
			g_map[myuse.x][myuse.y - 1] = ENETANKMAP;
		}


		break;
	default:
		break;
	}

}

//清除坦克
void clear_enemy_tank(EnemyTrank myenemytrank) {
	for (int i = myenemytrank.x - 1; i <= myenemytrank.x + 1; i++) {
		for (int j = myenemytrank.y - 1; j <= myenemytrank.y + 1; j++) {
			if (g_map[i][j] == ENETANKMAP) {
				PrintChar(i, j, "  ", 0x00);
				g_map[i][j] == KONG;
			}
		}
	}
}

void EnemyTankMove(PenemyTrank myenemytrank)
{
	enemytranklife(myenemytrank);
	if (canenemymove(myenemytrank)) return;
	if ((myenemytrank->x) > 2 && (myenemytrank->x)<=36 && (myenemytrank->y )>=3 && (myenemytrank->y)<=36&& myenemytrank->life >0)
	{
		//清理所有
		clear_enemy_tank(*myenemytrank);
		//再生成
	//	g_map[myenemytrank->x][myenemytrank->y] = ENETANKMAP;
		switch (myenemytrank->dir) {
		case TANK_DIR_UP:
			myenemytrank->y--;
			break;
		case TANK_DIR_DW:
			myenemytrank->y++;
			break;
		case TANK_DIR_LF:
			myenemytrank->x--;
			break;
		case TANK_DIR_RH:
			myenemytrank->x++;
			break;
		}
		//给坦克新方向
		myenemytrank->dir = myenemytrank->dir;
		print_enemy_tank(*myenemytrank);
		return;
	}
	else if ((myenemytrank->x) <= 2) {
		//清理所有
		clear_enemy_tank(*myenemytrank);
		//给坦克新方向
		myenemytrank->x++;
		EnemyChangeDir(myenemytrank,'d');
		print_enemy_tank(*myenemytrank);
		
		return;
	}
	else if ((myenemytrank->y) <= 2) {
		//清理所有
		clear_enemy_tank(*myenemytrank);
		//给坦克新方向
		myenemytrank->y++;
		EnemyChangeDir(myenemytrank,'s');
		print_enemy_tank(*myenemytrank);
		return;
	}
	else if ((myenemytrank->x )>= 37) {
		//清理所有
		clear_enemy_tank(*myenemytrank);
		//给坦克新方向
		myenemytrank->x--;
		EnemyChangeDir(myenemytrank,'a');
		print_enemy_tank(*myenemytrank);
		
		return;
	}
	else if ((myenemytrank->y) >= 37) {
		//清理所有
		clear_enemy_tank(*myenemytrank);
		//给坦克新方向
		myenemytrank->y--;
		EnemyChangeDir(myenemytrank,'w');
		print_enemy_tank(*myenemytrank);
		
		return;
	}

}
int EnemyChangeDir(PenemyTrank myenemytrank,char cDir) {
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

	myenemytrank->dir = nNewDir;

	return 1;
}
///
int canenemymove(PenemyTrank myUserTrank) {
	if (myUserTrank->life <= 0) {
		clear_enemy_tank(*myUserTrank); 
		return 1;
	}
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
			//clear_enemy_tank(*myUserTrank);
			//myUserTrank->y += 1;
			//print_enemy_tank(*myUserTrank);
			break;
		case TANK_DIR_DW:
			clear_enemy_tank(*myUserTrank);
			/*	clear_enemy_tank(*myUserTrank);
			myUserTrank->y += -1;
			print_enemy_tank(*myUserTrank);*/
			ChangeDir(myUserTrank, 'w');
			break;
		case TANK_DIR_LF:
			clear_enemy_tank(*myUserTrank);
			/*
			myUserTrank->x += 1;
			print_enemy_tank(*myUserTrank);*/
			ChangeDir(myUserTrank, 'd');
			break;
		case TANK_DIR_RH:
			clear_enemy_tank(*myUserTrank);
			/*myUserTrank->x += -1;
			print_enemy_tank(*myUserTrank);*/
			ChangeDir(myUserTrank, 'a');
			break;
		default:
			break;
		}
		return 1;
	}
	if ((myUserTrank->x) >= 16 && (myUserTrank->x) <= 24 && (myUserTrank->y) >= 33 && (myUserTrank->dir != TANK_DIR_UP))
	{
		if ((myUserTrank->x) <= 16) {
			clear_enemy_tank(*myUserTrank);
			myUserTrank->x -= 1;
			print_enemy_tank(*myUserTrank);
			return 1;
		}
		if ((myUserTrank->x) >= 24) {
			clear_enemy_tank(*myUserTrank);
			myUserTrank->x += 1;
			print_enemy_tank(*myUserTrank);
			return 1;
		}
		if ((myUserTrank->y) <= 34) {
			clear_enemy_tank(*myUserTrank);
			myUserTrank->y -= 1;
			print_enemy_tank(*myUserTrank);
			return 1;
		}
	}
	return 0;
}

void enemytranklife(PenemyTrank  myUserTrank) {
	//检测地图是否是用户坦克
	if (((g_map[2 + myUserTrank->x][myUserTrank->y] == USERTANKMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == USERTANKMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == USERTANKMAP) && myUserTrank->dir == TANK_DIR_RH) ||
		((g_map[-2 + myUserTrank->x][myUserTrank->y] == USERTANKMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == USERTANKMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == USERTANKMAP) && myUserTrank->dir == TANK_DIR_LF) ||
		((g_map[myUserTrank->x][2 + myUserTrank->y] == USERTANKMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == USERTANKMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == USERTANKMAP) && myUserTrank->dir == TANK_DIR_DW) ||
		((g_map[myUserTrank->x][-2 + myUserTrank->y] == USERTANKMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == USERTANKMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == USERTANKMAP) && myUserTrank->dir == TANK_DIR_UP)
		||
		//检测是是否用户子弹
		((g_map[2 + myUserTrank->x][myUserTrank->y] == USERBULLETMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == USERBULLETMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == USERBULLETMAP) && myUserTrank->dir == TANK_DIR_RH) ||
		((g_map[-2 + myUserTrank->x][myUserTrank->y] == USERBULLETMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == USERBULLETMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == USERBULLETMAP) && myUserTrank->dir == TANK_DIR_LF) ||
		((g_map[myUserTrank->x][2 + myUserTrank->y] == USERBULLETMAP || g_map[1 + myUserTrank->x][1 + myUserTrank->y] == USERBULLETMAP || g_map[-1 + myUserTrank->x][1 + myUserTrank->y] == USERBULLETMAP) && myUserTrank->dir == TANK_DIR_DW) ||
		((g_map[myUserTrank->x][-2 + myUserTrank->y] == USERBULLETMAP || g_map[-1 + myUserTrank->x][-1 + myUserTrank->y] == USERBULLETMAP || g_map[1 + myUserTrank->x][-1 + myUserTrank->y] == USERBULLETMAP) && myUserTrank->dir == TANK_DIR_UP)
		)
	{
		myUserTrank->life -= 10;
	}
}