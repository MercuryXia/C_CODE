#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();//创建菜单界面
void Initborad(char arr[3][3]);//初始化棋盘
void Printborad(char arr[3][3]);//打印棋盘
void Playerdo(char arr[3][3]);//玩家下棋
void Comdo(char arr[3][3]);//电脑下棋
char Judggame(char arr[3][3]);//判断状态