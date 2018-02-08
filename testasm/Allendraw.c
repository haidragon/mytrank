#include "Allendraw.h"
//#include <windows.h>
#include<stdio.h>
#include <time.h>


int g_map[40][40] = { 0 };
BOOL SetWindowInfo(char* pTitle, int nWid, int nHeight) {
	//���ô��ڱ���
	SetConsoleTitleA(pTitle);
	// ���ô��ڴ�С
	// ��Ϊ��Ļ��С���ܱȻ������������Ȱѻ�������С����Ϊ�㹻��
	// �Ȼ�ȡ��ǰ��Ļ�����ֵ
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cd = GetLargestConsoleWindowSize(hOut);
	// ���û��������ֵ
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("���ô��ڻ�������Сʧ��1��\n");
		return FALSE;
	}
	// ��Ҫ�����ô��ڴ�С
	SMALL_RECT sr = { 0,0,nWid - 1,nHeight - 1 };
	if (!SetConsoleWindowInfo(hOut, 1, &sr)) {
		printf("���ô��ڴ�Сʧ�ܣ�\n");
		return FALSE;
	}
	// �������û�������С
	cd.X = nWid;
	cd.Y = nHeight;
	if (!SetConsoleScreenBufferSize(hOut, cd)) {
		printf("���ô��ڻ�������Сʧ��2��\n");
		return FALSE;
	}
	return TRUE;
}

//�������ع��ĺ���
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//��ӡ�߽�
void my_print()
{

	for (int i = 0; i <= 40; i++) {
		for (int j = 0; j <= 40; j++) {
			if (i == 0 || i == 40 || j == 0 || j == 40) {

				g_map[40][40] = 1;
			}
		}
	}
	for (int i = 0; i <= 40; i++) {
		for (int j = 0; j <= 40; j++) {
			if (g_map[i][j] == 1) {
				PrintChar(i, j, "��", 0x44);
			}

		}
	}
}
void PrintChar(int nPosX, int nPosY, char*pszChar, WORD wAttr) {

	
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

		printf("%s", pszChar);
}

//��ʼ����ͼ
void initmap() {
	for (int i = 0; i <WIDE; i++) {
		for (int j = 0; j < LONG; j++) {
			if (i >= 18&& i <= 22&& j ==35) {
				g_map[i][j] = HOME;
				continue;
			}
			if ((i == 18 || i == 22) && j>35&&j<LONG -1) {
				g_map[i][j] = HOME;
				continue;
			}
			if ((i > 18 && i <22) && j>35 && j<LONG - 1) {
				g_map[i][j] = LIFE;
				continue;
			}
			if (i == 0 || i == LONG - 1 ||
				j == 0 || j == WIDE - 1) {
				g_map[i][j] = QINGMAP;
				continue;
			}
			else
			{
				g_map[i][j] = KONG;

			}
		}
	}
	//���ɲ�
	for (int i = 0; i < 100; i++) {
		int a = rand() % 39;
		int b = rand() % 39;
		if (g_map[a][b] == KONG) {
			g_map[a][b] = CAOMAP;
		}
		else {
			--i;
		}
		
	}
	//�����ϰ���
	for (int i = 0; i < 20; i++) {
		int a = rand() % 39;
		int b = rand() % 39;
		if (g_map[a][b] == KONG) {
			g_map[a][b] = ZHANGAIMAP;
		}
		else {
			--i;
		}

	}
	//�ַ���ӡ
}

//��
void darw()
{
	PrintChar(0, 0, " ", 0x44);
	printf("�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l�l|\n");
	for (int i = 0; i < LONG; i++) {
		for (int j = 0; j < WIDE; j++) {
			if (g_map[i][j] == QINGMAP)
				PrintChar(i, j, "��", 0x44);
			if (g_map[i][j] == USERTANKMAP)
				PrintChar(i, j, USERTANK, 0x55);
			if (g_map[i][j] == KONG)
				PrintChar(i, j, " ", 0x00);
			if (g_map[i][j] == HOME)
				PrintChar(i, j, "��", 0x2);
			if (g_map[i][j] == CAOMAP)
				PrintChar(i, j, CAO, 0x2);
			if (g_map[i][j] == ZHANGAIMAP)
				PrintChar(i, j, ZHANGAI, 0xff);
			if (g_map[i][j] == LIFE) {
				if ( ((i == 19 && (j == 36 || j == 38)) || (i == 21 && (j == 36 || j == 38)) )) {
					PrintChar(i, j, "��", 0x6);
				}
				else {
					PrintChar(i, j, "��", 0x3);
				}
			}

		}

	}
	printf("�l�l�l�l�l�l�l�l�l�l|\n");
}