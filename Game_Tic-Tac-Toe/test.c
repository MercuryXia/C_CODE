#include "game.h" 

void game() {

	//��ʼ������
	char ch[3][3];
	Initborad(ch);

	//��ӡ����
	Printborad(ch);
	
	do {
		Playerdo(ch);	//������
		if (Judggame(ch) == '*') {
			printf("��ϲ�㣡��Ӯ�ˣ�����\n");
			break;
		}
		else if (Judggame(ch) == 'h') {
			printf("�����ˡ�����\n");
			break;
		}
		srand((unsigned int)time(NULL));
		Comdo(ch);	//��������
		if (Judggame(ch) == '#') {
			printf("����Ӯ�ˡ�����\n");
			break;
		}
		else if (Judggame(ch) == 'h') {
			printf("�����ˡ�����\n");
			break;
		}
	} while (Judggame(ch) == 'c');//������c ��Ӯ* ����Ӯ# ����h
}

int main() {
	int input = 0;
	do {
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		rewind(stdin);//������̻�����
		if (input == 1) {
			printf("\n��ʼ��Ϸ������\n");
			game();
		}
		else if (input == 0) {
			printf("\n�˳���Ϸ:(\n");
		}else
			printf("\n������������ԣ�\n");
	} while (input);
	return 0;
}