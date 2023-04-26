#include "game.h" 

//创建菜单
void menu() {
	printf("************************\n");
	printf("*********1.play*********\n");
	printf("*********0.quit*********\n");
	printf("************************\n");
}

//初始化棋盘
void Initborad(char arr[3][3]) {
	int i = 0, j = 0;
	for ( i = 0; i < 3; i++) {
		for ( j = 0; j < 3; j++) {
			arr[i][j] = ' ';
		}
	}
}

//打印棋盘
void Printborad(char arr[3][3]) {
	int i = 0, j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (i == 2 && j == 2) {
				printf(" %c \n", arr[i][j]);
			}else
			printf(" %c ", arr[i][j]);
			if (j < 2) {
				printf("|");
			}
		}
		if (i < 2) {
			printf("\n---|---|--- \n");
		}
	}
}

//玩家下棋
void Playerdo(char arr[3][3]) {
	int x = 0, y = 0;
	while (1) {//判断坐标合法性
		printf("请选择下棋的坐标:");
		scanf("%d%d", &x, &y);
		rewind(stdin);//清除键盘缓冲区
		if (1 <= x && x <= 3 && 1 <= y && y <= 3 && arr[x - 1][y - 1] == ' ') {
			arr[x - 1][y - 1] = '*';
			break;
		}
		else {
			printf("坐标非法!!!\n");
		}
	}
	//打印棋盘
	Printborad(arr);
}

//电脑下棋
void Comdo(char arr[3][3]) {
	printf("电脑的回合！\n");
	while (1) {
		int ret1 = rand() % 3;
		int ret2 = rand() % 3;
		if (arr[ret1][ret2] == ' ') {
			arr[ret1][ret2] = '#';
			break;
		}
	}
	//打印棋盘
	Printborad(arr);
	printf("到你了！\n");
}

//状态判断
char Judggame(char arr[3][3]) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == ' ') {
				count++;
			}
		}
	}
	if (count) {
		//先判断行一样
		for (int i = 0; i < 3; i++) {
			if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ') {
				return arr[i][0];
				break;
			}
		}
		//再判断列一样
		for (int j = 0; j < 3; j++) {
			if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ') {
				return arr[0][j];
				break;
			}
		}
		//再判断斜线
		if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ') || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) && arr[1][1] != ' ') {
			return arr[1][1];
		}
		return 'c';
	}
	else
		return 'h';
}
 