#include "game.h"
void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			 board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c ", board[i][j]);
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入坐标1<=x<%d,1<=y<=%d\n", row, col);
		scanf("%d %d", &x, &y);
		if (0 < x && x < row + 1 && 0 < y && y < col + 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标已被占用\n");
		}
		else
			printf("输入超过范围请重新输入\n");
	}
}
void commove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x, y;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			 break;
		}
	}
}
char iswin(char board[ROW][COL], int row, int col)
{
	//判断行
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j]!=' ')
				return board[i][j];
		}
	}
	//判断列
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 2; i++)
		{
			if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	//判断主斜边
	for (i = 0; i < row-2; i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i+1][j + 1] && board[i+1][j + 1] == board[i+2][j + 2] && board[i][j] == '*')
				return '*';
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] == '#')
				return '#';
		}
	}//判断副斜边
	for (i = 0; i < row-2 ; i++)
	{
		for (j = 2; j < col; j++)
		{
			if (board[i][j] == board[i+1][j - 1] && board[i+1][j - 1] == board[i+2][j - 2] && board[i][j] == '*')
				return '*';
			if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i][j] == '#')
				return '#';
		}
	}
	int ret = 1;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				ret = 0;
		}
	}
	if (ret == 1)
	{
		return 'Q';
	}
	else
		return 'c';
}
