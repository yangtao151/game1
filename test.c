#include "game.h"
void game()
{
	char board[ROW][COL] = { 0 };
	//��ʼ������
	initboard(board, ROW, COL);
	//��ӡ����
	displayboard(board, ROW, COL);
	//����
	char ret = 0;
	while (1)
	{
		//�������
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
			break;
			commove(board, ROW, COL);
			displayboard(board, ROW, COL);
			 ret = iswin(board, ROW, COL);
			if (ret != 'c')
			     break;	
	}
	if (ret == '*')
		printf("���Ӯ��\n");
	else if (ret == '#')
		printf("����Ӯ��\n");
	else
		printf("ƽ��\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		printf("1.��ʼ��Ϸ\n");
		printf("0.�˳���Ϸ\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("����������");
			break;
		}
	} while (input);
		return 0;
}