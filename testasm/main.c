#include "Allendraw.h"
#include "AllenBullet.h"
#include<stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h> 
//����ȫ���û�̹��
UserTrank myuser;
UserTrank myuser2;
EnemyTrank myEnemyTrank;
EnemyTrank myEnemyErank1;
EnemyTrank myEnemyTrank2;
EnemyTrank myEnemyTrank3;
EnemyTrank myEnemyTrank4;
EnemyTrank myEnemyTrank5;
EnemyTrank myEnemyTrank6;
EnemyTrank myEnemyTrank7;
EnemyTrank myEnemyTrank8;
EnemyTrank myEnemyTrank9;
EnemyTrank myEnemyTrank10;
void start();
void MouseEventProc(MOUSE_EVENT_RECORD mer);
void OutputPos(int nX, int nY);
void WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr);
int MessageLoop();
void gotoxy(int x, int y);
int booldraw = 1;
int  main() {
	int a=0;
	printf(" %s\n", "��������ң����1�������Ϊ wasd ���2.�����Ϊijkl,�з�̹�˿�ʼ����ֵΪ20��");
	printf(" %s\n", "�����û�̹�˻��ӵ���10���û������Ҳһ�����û�����ֵΪ100������ֵΪ0ʱ��");
	printf(" %s\n", "�������򡣵���̹��ȫ���ꡣĿǰ����������Ŀǰhome���޵�״̬��");

	printf(" %s\n", "��ѡ��ģʽ");
	printf("1 %s\n", "����ģʽ");
	printf("2 %s\n", "��ԭ����ͼ�������Զ���ģʽ(�Ҽ��������ϰ������ͬʱ�϶����ݣ�");

	SetWindowInfo("Tank", 100, 45);
	HideCursor();//���ع��
	scanf_s("%d", &a);
switch (a)
	{
	case 1:
		start();
		break;
	case 2:
		booldraw = 0;
		//�Ȼ�ԭ����
		initmap();
		//��
		darw();
		gotoxy(82, 10);
		printf("��ʼ��Ϸ");
		MessageLoop();
		break;
	default:
		break;
	}

	return 0;
}


void start() {
	//////////////////ģ�ⰴ��shit��////////////////
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	/////////////////////////////////////////////////
	SetWindowInfo("Tank", 100, 45);
	HideCursor();//���ع��
				 //��ʼ����ͼ
	if (booldraw) {
		initmap();
		//��
		darw();
	}
	srand(time(NULL));//�������������	
					  /////////////////////////////////////////////
	init_my_tank(&myuser, 16, 37);
	init_my_tank(&myuser2, 24, 37);
	/////////////////
	init_enemy_tank(&myEnemyTrank, 2, 4);
	init_enemy_tank(&myEnemyErank1, 6, 10);
	init_enemy_tank(&myEnemyTrank2, 10, 16);
	init_enemy_tank(&myEnemyTrank3, 14, 24);
	init_enemy_tank(&myEnemyTrank4, 18, 26);
	init_enemy_tank(&myEnemyTrank5, 20, 30);
	init_enemy_tank(&myEnemyTrank6, 22, 26);
	init_enemy_tank(&myEnemyTrank7, 26, 24);
	init_enemy_tank(&myEnemyTrank8, 30, 16);
	init_enemy_tank(&myEnemyTrank9, 34, 10);
	init_enemy_tank(&myEnemyTrank10, 37, 4);
	///////////////////////
	init_User_Bullet(myuser, UserBullet);
	//init_User_Bullet(myuser2, UserBullet);
	init_Enemy_Bullet(myEnemyTrank, EnemyBullet);


	char enemych = 'w';
	char enemych1 = 's';
	char enemych2 = 'a';
	char enemych3 = 'd';
	char enemych4 = 'w';
	char enemych5 = 'd';
	char enemych6 = 's';
	char enemych7 = 'a';
	char enemych8 = 'w';
	char enemych9 = 'd';
	char enemych10 = 'a';
	char ch = _getch();

	clock_t tBegin = clock(), tEnd = 0;
	clock_t t1, t2;
	t1 = clock();
	t2 = 0;
	int inttime = 100;
	while (1) {

		int temp = rand() % 4;
		if (temp == 0) enemych = 'a', enemych1 = 's', enemych2 = 'w', enemych4 = 'd', enemych5 = 'w', enemych6 = 'a', enemych7 = 'd', enemych8 = 'd', enemych9 = 'w', enemych10 = 'd';
		if (temp == 1) enemych = 'w', enemych1 = 'd', enemych2 = 'a', enemych4 = 'w', enemych5 = 'd', enemych6 = 'd', enemych7 = 'w', enemych8 = 's', enemych9 = 'a', enemych10 = 'a';
		if (temp == 2) enemych = 's', enemych1 = 'w', enemych2 = 'd', enemych4 = 's', enemych5 = 's', enemych6 = 's', enemych7 = 'a', enemych8 = 'w', enemych9 = 's', enemych10 = 's';
		if (temp == 3) enemych = 'd', enemych1 = 'a', enemych2 = 's', enemych4 = 'a', enemych5 = 'a', enemych6 = 'w', enemych7 = 's', enemych8 = 'a', enemych9 = 'd', enemych10 = 'w';
		EnemyChangeDir(&myEnemyTrank, enemych);
		EnemyChangeDir(&myEnemyErank1, enemych1);
		EnemyChangeDir(&myEnemyTrank2, enemych2);
		EnemyChangeDir(&myEnemyTrank3, enemych3);
		EnemyChangeDir(&myEnemyTrank4, enemych4);
		EnemyChangeDir(&myEnemyTrank5, enemych5);
		EnemyChangeDir(&myEnemyTrank6, enemych6);
		EnemyChangeDir(&myEnemyTrank7, enemych7);
		EnemyChangeDir(&myEnemyTrank8, enemych8);
		EnemyChangeDir(&myEnemyTrank9, enemych9);
		EnemyChangeDir(&myEnemyTrank10, enemych10);
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w' || ch == 'W' || ch == 'a' || ch == 'A' || ch == 's' || ch == 'S' || ch == 'd' || ch == 'D')
				ChangeDir(&myuser, ch);

			if (ch == 'i' || ch == 'I' || ch == 'J' || ch == 'j' || ch == 'K' || ch == 'k' || ch == 'l' || ch == 'L')
				ChangeDir2(&myuser2, ch);

		}

		tEnd = clock();
		t2 = clock();
		create_User_Bullet(myuser, UserBullet);
		create_User_Bullet(myuser2, UserBullet);
		create_Enemy_Bullet(myEnemyTrank, EnemyBullet);
		create_Enemy_Bullet(myEnemyErank1, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank2, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank3, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank4, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank5, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank6, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank7, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank8, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank9, EnemyBullet);
		create_Enemy_Bullet(myEnemyTrank10, EnemyBullet);
		if (t2 - t1  > 5) {

			User_Bullet_Move(UserBullet);

			Enemy_Bullet_Move(EnemyBullet);

			t1 = t2;
		}

		if (tEnd - tBegin > 200)
		{
			inttime -= 1;
			if ((myuser.life <= 0 || myuser2.life <= 0) && inttime < 1) {
				MessageBoxA(0, "GG��", "����", MB_OK);
				Sleep(5);
				exit(0);
			}
			TankMove(&myuser);
			TankMove(&myuser2);
			if(myEnemyTrank.life>=0)     EnemyTankMove(&myEnemyTrank);
			if (myEnemyErank1.life >= 0) EnemyTankMove(&myEnemyErank1);
			if (myEnemyTrank2.life >= 0) EnemyTankMove(&myEnemyTrank2);
			if (myEnemyTrank3.life >= 0) EnemyTankMove(&myEnemyTrank3);
			if (myEnemyTrank4.life >= 0) EnemyTankMove(&myEnemyTrank4);
			if (myEnemyTrank5.life >= 0) EnemyTankMove(&myEnemyTrank5);
			if (myEnemyTrank6.life >= 0) EnemyTankMove(&myEnemyTrank6);
			if (myEnemyTrank7.life >= 0) EnemyTankMove(&myEnemyTrank7);
			if (myEnemyTrank8.life >= 0) EnemyTankMove(&myEnemyTrank8);
			if (myEnemyTrank9.life >= 0) EnemyTankMove(&myEnemyTrank9);
			if (myEnemyTrank10.life >= 0 ) EnemyTankMove(&myEnemyTrank10);

			tBegin = tEnd;

		}



	}
}



void MouseEventProc(MOUSE_EVENT_RECORD mer) {

	//�����������ǽ
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		int x = mer.dwMousePosition.X;
		int y = mer.dwMousePosition.Y;


		OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);

		if ((x >80 && x<88) && y == 10) {

			//�Ȼ�
			darw();
			gotoxy(82, 10);
			printf("       ");
			start();
		}
		if (x <78 && y < 38&&x >2 && y >2) {
			WriteChar(ZHANGAI, (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0xff);
			g_map[(mer.dwMousePosition.X) / 2][mer.dwMousePosition.Y] = ZHANGAIMAP;
		}
		if (mer.dwEventFlags == MOUSE_MOVED) {
			OutputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
			if (mer.dwMousePosition.X < 78 && mer.dwMousePosition.Y < 38&&mer.dwMousePosition.X >2 && mer.dwMousePosition.Y >2) {
				WriteChar(CAO, (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x2);
				g_map[x / 2][y] = CAOMAP;
			}
		}
	}
	else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
		//WriteChar("�ҵ���", (mer.dwMousePosition.X) / 2, mer.dwMousePosition.Y, 0x6);
	}

}

//�����������
void OutputPos(int nX, int nY) {
	char szBuf[100] = { 10 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d   ", nX, nY);
	SetConsoleTitleA(szBuf);
	WriteChar(szBuf, 0, 0, 0x50);
}
int MessageLoop()
{
	//��ȡһ�����
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//����һ������ṹ��
	INPUT_RECORD stcRcord = { 0 };

	DWORD dwRead;
	//���ÿ���̨ģʽ�������
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1)
	{
		ReadConsoleInput(hStdin, &stcRcord, 1, &dwRead);
		if (stcRcord.EventType == KEY_EVENT) {

		}
		else if (stcRcord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRcord.Event.MouseEvent);
		}
	}


}
void WriteChar(char* psz, int nPosX, int nPosY, WORD wAttr) {
	// ���ù��λ��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { nPosX * 2,nPosY };
	SetConsoleCursorPosition(hOut, pos);
	// ���ع��
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = FALSE;
	ci.dwSize = 1;
	SetConsoleCursorInfo(hOut, &ci);
	// ���ô�ӡ���ŵ�ǰ��ɫ����ɫ
	SetConsoleTextAttribute(hOut, wAttr);
	// ������������
	printf("%s", psz);
}

//ָ��λ��
void gotoxy(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
	HANDLE    hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleTextAttribute(hConsoleOut, 0x4);
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}