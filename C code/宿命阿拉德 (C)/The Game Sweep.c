#include "Head.h"

/*********************  来源：CSDN zhaoxaun666 *********************/

#define ROW 10
#define LOW 10
#define ROWS ROW+2
#define LOWS LOW+2
#define  COUNT 10

void Menu();
void Game();
void set(char board[ROWS][LOWS], int row, int low, char M);
void show(char board[ROWS][LOWS], int row, int low);
void insert(char board[ROWS][LOWS], int count);
void Play1(char mine[ROWS][LOWS], char look[ROWS][LOWS], int x, int y);
int jishu(char mine[ROWS][LOWS], int x, int y);

int GameSweep(void) {
	int n = 0;
	srand((unsigned)time(NULL));
	do {
		Menu();
		scanf("%d", &n);
		switch (n) {
			case 1:
				Game();
				//system("cls");
				break;
			case 2:
				break;
			default:printf("输入错误！请重新输入：\n");
		}
		if (n == 2) {
			break;
		}
	} while (n);
}
void Menu() {
	printf("******************************\n");
	printf("******************************\n");
	printf("******************************\n");
	printf("*******    1.Play1     ********\n");
	printf("*******    2.Exit     ********\n");
	printf("******************************\n");
	printf("******************************\n");
	printf("******************************\n");
}
void Game() {
	int x, y;
	int m;
	int n = 0;
	int lei = 0;
	char mine[ROWS][LOWS] = { 0 };
	char look[ROWS][LOWS] = { 0 };
	set(mine, ROWS, LOWS, '0');//建立布雷棋盘
	set(look, ROWS, LOWS, '*');//建立可视界面棋盘
	insert(mine, COUNT);//布雷


	do {
		int select;
		system("cls");
		//show(mine,ROW,LOW);
		show(look, ROW, LOW);//显示排过的雷
		printf("-------1.扫雷-----2.标记雷--------\n");
		scanf("%d", &select);
		if (select == 1) {
			printf("请输入坐标：");
			scanf("%d%d", &x, &y);
			if (mine[x][y] == '1'&&n == 0)//保证第一次踩到的不是雷
			{
				set(mine, ROWS, LOWS, '0');
				insert(mine, COUNT);
			}
			if (mine[x][y] == '0'&&look[x][y] == '*') {
				Play1(mine, look, x, y);
				show(look, ROW, LOW);
			}
			if (mine[x][y] == '1'&&look[x][y] == '*') {
				m = 0;
				look[x][y] = '@';
				show(look, ROW, LOW);
				printf("游戏结束，你踩雷了！！！\n");
			}
			n++;
		}
		if (select == 2) {

			printf("请输入标记雷的坐标：");
			scanf("%d%d", &x, &y);

			if (mine[x][y] == '1'&&look[x][y] == '*') {
				look[x][y] = 'X';
				lei++;
				show(look, ROW, LOW);

			}
			if (mine[x][y] == '0'&&look[x][y] == '*') {
				m = 0;//<span style="white-space:pre">  </span>//为了跳出循环


				printf("游戏结束，你雷标记错误了！！！\n");
			}
			if (lei == COUNT) {
				m = 0;  //为了跳出循环
				printf("恭喜你排雷成功！！！\n");
			}
		}

	} while (m);
}
void set(char board[ROWS][LOWS], int row, int low, char M) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < low; j++) {
			board[i][j] = M;
		}
	}
}
void show(char board[ROWS][LOWS], int row, int low) {
	int i, j;

	printf("    ");//为了棋盘的美观
	for (i = 1; i <= row; i++) {
		printf(" %d ", i);
	}
	printf("\n    ------------------------------\n");
	for (i = 1; i <= row; i++) {
		printf("%2d |", i);
		for (j = 1; j <= low; j++) {
			printf(" %c ", board[i][j]);
			if (j == low) {
				printf("|");
			}
		}
		printf("\n");
	}
	printf("    ------------------------------\n");
}
void insert(char board[ROWS][LOWS], int count) {
	while (count) {
		int x, y;
		x = rand() % ROW + 1;
		y = rand() % LOW + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}
void Play1(char mine[ROWS][LOWS], char look[ROWS][LOWS], int x, int y)//应用递归排除周围没有雷的区域
{
	int ret;
	ret = jishu(mine, x, y);
	if (ret == 0) {
		look[x][y] = ' ';
		if ((x - 1) > 0 && (y - 1) > 0 && (look[x - 1][y - 1] == '*'))
			Play1(mine, look, x - 1, y - 1);
		if ((x - 1) > 0 && (y) > 0 && (look[x - 1][y] == '*'))
			Play1(mine, look, x - 1, y);
		if ((x - 1) > 0 && (y + 1) > 0 && (look[x - 1][y + 1] == '*'))
			Play1(mine, look, x - 1, y + 1);
		if ((x) > 0 && (y - 1) > 0 && (look[x][y - 1] == '*'))
			Play1(mine, look, x, y - 1);
		if ((x) > 0 && (y + 1) > 0 && (look[x][y + 1] == '*'))
			Play1(mine, look, x, y + 1);
		if ((x + 1) > 0 && (y - 1) > 0 && (look[x + 1][y - 1] == '*'))
			Play1(mine, look, x + 1, y - 1);
		if ((x + 1) > 0 && (y) > 0 && (look[x + 1][y] == '*'))
			Play1(mine, look, x + 1, y);
		if ((x + 1) > 0 && (y + 1) > 0 && (look[x + 1][y + 1] == '*'))
			Play1(mine, look, x + 1, y + 1);
	} else
		look[x][y] = ret + '0';
}
int jishu(char mine[ROWS][LOWS], int x, int y)//统计周围的雷数
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';

}
