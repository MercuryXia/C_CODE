#include "game.h" 

void game() {

	//初始化棋盘
	char ch[3][3];
	Initborad(ch);

	//打印棋盘
	Printborad(ch);
	
	do {
		Playerdo(ch);	//人下棋
		if (Judggame(ch) == '*') {
			printf("恭喜你！你赢了！！！\n");
			break;
		}
		else if (Judggame(ch) == 'h') {
			printf("和棋了。。。\n");
			break;
		}
		srand((unsigned int)time(NULL));
		Comdo(ch);	//电脑下棋
		if (Judggame(ch) == '#') {
			printf("电脑赢了。。。\n");
			break;
		}
		else if (Judggame(ch) == 'h') {
			printf("和棋了。。。\n");
			break;
		}
	} while (Judggame(ch) == 'c');//下棋中c 我赢* 电脑赢# 和棋h
}

int main() {
	int input = 0;
	do {
		menu();
		printf("请选择:");
		scanf("%d", &input);
		rewind(stdin);//清除键盘缓冲区
		if (input == 1) {
			printf("\n开始游戏！！！\n");
			game();
		}
		else if (input == 0) {
			printf("\n退出游戏:(\n");
		}else
			printf("\n输入错误，请重试：\n");
	} while (input);
	return 0;
}