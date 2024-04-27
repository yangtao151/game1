#include "game.h"
void game()
{
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	initboard(board, ROW, COL);
	//打印棋盘
	displayboard(board, ROW, COL);
	//下棋
	char ret = 0;
	while (1)
	{
		//玩家下棋
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
		printf("玩家赢了\n");
	else if (ret == '#')
		printf("电脑赢了\n");
	else
		printf("平局\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		printf("1.开始游戏\n");
		printf("0.退出游戏\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("请重新输入");
			break;
		}
	} while (input);
		return 0;
}