#include "AllenBullet.h"
#include "Allendraw.h"

 Bullet UserBullet[100];
//敌人
 Bullet EnemyBullet[100];


//打印
void print_User_Bullet(Bullet userBullet) {
	if (!(userBullet.life)) return;

	if (g_map[userBullet.x][userBullet.y] == CAOMAP) {
		PrintChar(userBullet.x, userBullet.y, CAO, 0x2);
		return;
	}
	//如果障碍
	 if (g_map[userBullet.x][userBullet.y] == ZHANGAIMAP) {
		userBullet.life = 0;
		return;
	}
	if (g_map[userBullet.x][userBullet.y] == KONG) 
		{
		PrintChar(userBullet.x, userBullet.y, "◎", 0x3);
		g_map[userBullet.x][userBullet.y] = USERBULLETMAP;
		return;
	}
	
}

//清除用户子弹
void clear_User_Bullet(Bullet userBullet) {
	//判断是否为障碍物
	if (g_map[userBullet.x][userBullet.y] == ZHANGAIMAP)
	{
		userBullet.life = 0;
		return;
	}
	if (g_map[userBullet.x][userBullet.y] == USERBULLETMAP) {
		PrintChar(userBullet.x, userBullet.y, "  ", 0x00);
		g_map[userBullet.x][userBullet.y] = KONG;
		return;
	}
	
}

//移动所有的生命值为ture子弹
void User_Bullet_Move(Pbullet userBullet) {

	 User_Bullet_home(userBullet);
	for (int i = 0; i < 100; i++) {
		//移动之前先擦掉
		clear_User_Bullet(userBullet[i]);
		
		//如果在障碍物上子弹生命失效
		if (g_map[userBullet[i].x][userBullet[i].y] == ZHANGAIMAP) {
			userBullet[i].life = 0;
		}
		//判断是否在范围内
		if (userBullet[i].x > 2 && userBullet[i].x <= 37 && userBullet[i].y>2 && userBullet[i].y <=37&& (userBullet[i].life==1))
		{
			switch (userBullet[i].dir) {
			case TANK_DIR_UP:
				userBullet[i].y--;
				break;
			case TANK_DIR_DW:
				userBullet[i].y++;
				break;
			case TANK_DIR_LF:
				userBullet[i].x--;
				break;
			case TANK_DIR_RH:
				userBullet[i].x++;
				break;
			}
			//再打印出来
			//userBullet[i].life = 1;
			print_User_Bullet(userBullet[i]);
		}
		//如果超出范围这个子弹就没用了
		else
		{
			userBullet[i].life = 0;
		}
	}
}
//生成子弹
void create_User_Bullet(UserTrank userTrank, Pbullet userBullet) {


	if (((g_map[2 + userTrank.x][userTrank.y] == ZHANGAIMAP || g_map[1 + userTrank.x][-1 + userTrank.y] == ZHANGAIMAP || g_map[1 + userTrank.x][1 + userTrank.y] == ZHANGAIMAP) && userTrank.dir == TANK_DIR_RH) ||
		((g_map[-2 + userTrank.x][userTrank.y] == ZHANGAIMAP || g_map[-1 + userTrank.x][-1 + userTrank.y] == ZHANGAIMAP || g_map[-1 + userTrank.x][1 + userTrank.y] == ZHANGAIMAP) && userTrank.dir == TANK_DIR_LF) ||
		((g_map[userTrank.x][2 + userTrank.y] == ZHANGAIMAP || g_map[1 + userTrank.x][1 + userTrank.y] == ZHANGAIMAP || g_map[-1 + userTrank.x][1 + userTrank.y] == ZHANGAIMAP) && userTrank.dir == TANK_DIR_DW) ||
		((g_map[userTrank.x][-2 + userTrank.y] == ZHANGAIMAP || g_map[-1 + userTrank.x][-1 + userTrank.y] == ZHANGAIMAP || g_map[1 + userTrank.x][-1 + userTrank.y] == ZHANGAIMAP) && userTrank.dir == TANK_DIR_UP)
		) 
	{
		return;
	}
	if (userTrank.life <= 0) return;
	if (!(userTrank.x > 3 && userTrank.x < 36 && userTrank.y >3 && userTrank.y <=36))
	{
		return;
	}
	//在家附近不生成子弹
	if ((userTrank.x >= 15 && userTrank.x <=25 && userTrank.y >=32)&& userTrank.dir!= TANK_DIR_UP)
	{
		return;
	}
	if (userTrank.y == 36 && userTrank.dir == TANK_DIR_DW) return;
	switch (userTrank.dir) {
	case TANK_DIR_UP:
		for (int i = 0; i < 100; i++) {

			if (userBullet[i].life == 0) {
				userBullet[i].life = 1;
				userBullet[i].dir = userTrank.dir;
				userBullet[i].x = userTrank.x;
				userBullet[i].y = userTrank.y - 3;
				print_User_Bullet(userBullet[i]);
				break;
			}
			else {
				continue;
			}
		}

		break;
	case TANK_DIR_DW:
		for (int i = 0; i < 100; i++) {
			if (userBullet[i].life == 0) {
				userBullet[i].life = 1;
				userBullet[i].dir = userTrank.dir;
				userBullet[i].x = userTrank.x;
				userBullet[i].y = userTrank.y + 3;
				print_User_Bullet(userBullet[i]);
				break;
			}
			else {
				continue;
			}
		}
		break;
	case TANK_DIR_LF:
		for (int i = 0; i < 100; i++) {
			if (userBullet[i].life == 0) {
				userBullet[i].life = 1;
				userBullet[i].dir = userTrank.dir;
				userBullet[i].x = userTrank.x - 3;
				userBullet[i].y = userTrank.y;
				print_User_Bullet(userBullet[i]);
				break;
			}
			else {
				continue;
			}
		}

		break;
	case TANK_DIR_RH:
		for (int i = 0; i < 100; i++) {
			if (userBullet[i].life == 0) {
				userBullet[i].life = 1;
				userBullet[i].dir = userTrank.dir;
				userBullet[i].x = userTrank.x + 3;
				userBullet[i].y = userTrank.y;
				print_User_Bullet(userBullet[i]);
				break;
			}
			else {
				continue;
			}
		}
		break;
	}
}
//所有子弹初始化为flase
void init_User_Bullet(UserTrank userTrank, Pbullet userBullet) {
	for (int i = 0; i < 100; i++) {

		userBullet[i].x = userTrank.x;
		userBullet[i].y = userTrank.y;
		userBullet[i].life = 0;
	}
}

//判断子弹是否在home附近
int User_Bullet_home(Pbullet userBullet) {
	for (int i = 0; i < 100; i++) {
		if (userBullet[i].x >= 17 && userBullet[i].x <= 23 && userBullet[i].y >= 33) {
			userBullet[i].life = 0;
			clear_User_Bullet(userBullet[i]);
		}
		
	}
}

///////////////////////////////////_Enemy_//////////////////////////////////////////////////////////


//打印敌方子弹
void print_Enemy_Bullet(Bullet userBullet) {
	if (userBullet.x == 0 || userBullet.x == 39 || userBullet.y == 39 || userBullet.y == 0) return;

	if (!(userBullet.life)) return;
	//如果在草上打印草
	if (g_map[userBullet.x][userBullet.y] == CAOMAP) {
		PrintChar(userBullet.x, userBullet.y, CAO, 0x2);
		return;
	}
	//如果障碍
	 if (g_map[userBullet.x][userBullet.y] == ZHANGAIMAP) {
		userBullet.life = 0;
		return;
	}
	if(g_map[userBullet.x][userBullet.y]==KONG){
		PrintChar(userBullet.x, userBullet.y, "●", 0x6);
		g_map[userBullet.x][userBullet.y] = ENETBULLETMAP;
		return;
	}
	
	
}

//清除敌方子弹
void clear_Enemy_Bullet(Bullet userBullet) {
	//判断是否为障碍物
	if (g_map[userBullet.x][userBullet.y] == ZHANGAIMAP)
	{
		userBullet.life = 0;
		return;
	}
	if (g_map[userBullet.x][userBullet.y] == ENETBULLETMAP) {
		PrintChar(userBullet.x, userBullet.y, "  ", 0x00);
		g_map[userBullet.x][userBullet.y] = KONG;
		return;
	}
	
}

//移动所有的生命值为ture子弹
void Enemy_Bullet_Move(Pbullet pbullet) {

	Enemy_Bullet_home(pbullet);
	for (int i = 0; i < 100; i++) {
		//移动之前先擦掉
		clear_Enemy_Bullet((pbullet[i]));
		//如果在障碍物上子弹生命失效
		if (g_map[pbullet[i].x][pbullet[i].y] == ZHANGAIMAP) {
			pbullet[i].life = 0;
		}
		//判断是否在范围内
		if ((pbullet[i].x )>=2 && (pbullet[i].x) <=37 &&( pbullet[i].y)>=2 && (pbullet[i].y) <= 37&&( pbullet[i].life) == 1)
		{
			switch (pbullet[i].dir) {
			case TANK_DIR_UP:
				pbullet[i].y--;
				break;
			case TANK_DIR_DW:
				pbullet[i].y++;
				break;
			case TANK_DIR_LF:
				pbullet[i].x--;
				break;
			case TANK_DIR_RH:
				pbullet[i].x++;
				break;
			}
			//再打印出来
			print_Enemy_Bullet((pbullet[i]));
		}
		//如果超出范围这个子弹就没用了
		else
		{
			pbullet[i].life = 0;
		}
	}
}
//生成子弹
void create_Enemy_Bullet(EnemyTrank enemyTrank, Pbullet EnemyBullet) {

	if (((g_map[2 + enemyTrank.x][enemyTrank.y] == ZHANGAIMAP || g_map[1 + enemyTrank.x][-1 + enemyTrank.y] == ZHANGAIMAP || g_map[1 + enemyTrank.x][1 + enemyTrank.y] == ZHANGAIMAP) && enemyTrank.dir == TANK_DIR_RH) ||
		((g_map[-2 + enemyTrank.x][enemyTrank.y] == ZHANGAIMAP || g_map[-1 + enemyTrank.x][-1 + enemyTrank.y] == ZHANGAIMAP || g_map[-1 + enemyTrank.x][1 + enemyTrank.y] == ZHANGAIMAP) && enemyTrank.dir == TANK_DIR_LF) ||
		((g_map[enemyTrank.x][2 + enemyTrank.y] == ZHANGAIMAP || g_map[1 + enemyTrank.x][1 + enemyTrank.y] == ZHANGAIMAP || g_map[-1 + enemyTrank.x][1 + enemyTrank.y] == ZHANGAIMAP) && enemyTrank.dir == TANK_DIR_DW) ||
		((g_map[enemyTrank.x][-2 + enemyTrank.y] == ZHANGAIMAP || g_map[-1 + enemyTrank.x][-1 + enemyTrank.y] == ZHANGAIMAP || g_map[1 + enemyTrank.x][-1 + enemyTrank.y] == ZHANGAIMAP) && enemyTrank.dir == TANK_DIR_UP)
		)
	{
		return;
	}
	if (enemyTrank.life <= 0) return;


	if (!(enemyTrank.x > 3 && enemyTrank.x < 36 && enemyTrank.y >3 && enemyTrank.y <= 36)&& enemyTrank.dir!= TANK_DIR_UP)
	{
		return;
	}
	//在家附近不生成子弹
	if ((enemyTrank.x >= 15 && enemyTrank.x <= 25 && enemyTrank.y >= 32))
	{
		return;
	}
	if (enemyTrank.y == 3 && enemyTrank.dir == TANK_DIR_UP) return;
	if (enemyTrank.y == 36 && enemyTrank.dir == TANK_DIR_DW) return;
	switch (enemyTrank.dir) {
	case TANK_DIR_UP:
		for (int i = 0; i < 100; i++) {

			if (EnemyBullet[i].life == 0) {
				EnemyBullet[i].life = 1;
				EnemyBullet[i].dir = enemyTrank.dir;
				EnemyBullet[i].x = enemyTrank.x;
				EnemyBullet[i].y = enemyTrank.y - 3;
				print_Enemy_Bullet(EnemyBullet[i]);
				break;
			}
			else {
				continue;
			}
		}

		break;
	case TANK_DIR_DW:
		for (int i = 0; i < 100; i++) {
			if (EnemyBullet[i].life == 0) {
				EnemyBullet[i].life = 1;
				EnemyBullet[i].dir = enemyTrank.dir;
				EnemyBullet[i].x = enemyTrank.x;
				EnemyBullet[i].y = enemyTrank.y + 3;
				print_Enemy_Bullet(EnemyBullet[i]);
				break;
			}
			else {
				continue;
			}
		}
		break;
	case TANK_DIR_LF:
		for (int i = 0; i < 100; i++) {
			if (EnemyBullet[i].life == 0) {
				EnemyBullet[i].life = 1;
				EnemyBullet[i].dir = enemyTrank.dir;
				EnemyBullet[i].x = enemyTrank.x - 3;
				EnemyBullet[i].y = enemyTrank.y;
				print_Enemy_Bullet(EnemyBullet[i]);
				break;
			}
			else {
				continue;
			}
		}

		break;
	case TANK_DIR_RH:
		for (int i = 0; i < 100; i++) {
			if (EnemyBullet[i].life == 0) {
				EnemyBullet[i].life = 1;
				EnemyBullet[i].dir = enemyTrank.dir;
				EnemyBullet[i].x = enemyTrank.x + 3;
				EnemyBullet[i].y = enemyTrank.y;
				print_Enemy_Bullet(EnemyBullet[i]);
				break;
			}
			else {
				continue;
			}
		}
		break;
	}
}
//所有子弹初始化为flase
void init_Enemy_Bullet(EnemyTrank enemyTrank, Pbullet EnemyBullet) {
	
	for (int i = 0; i < 100; i++) {
		EnemyBullet[i].x = enemyTrank.x;
		EnemyBullet[i].y = enemyTrank.y;
		EnemyBullet[i].life = 0;
	}
}
//判断子弹是否在home附近
int Enemy_Bullet_home(Pbullet userBullet) {
	for (int i = 0; i < 100; i++) {
		if (userBullet[i].x >= 17 && userBullet[i].x <= 23 && userBullet[i].y >= 34) {
			userBullet[i].life = 0;
			clear_Enemy_Bullet(userBullet[i]);
		}
	}
}