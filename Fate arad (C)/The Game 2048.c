#include "Head.h"

/*********************  来源：CSDN王小多  *********************/

typedef struct x_y {    //用来存放一个坐标
	int x;
	int y;
}x_y;
static x_y get_xy();
int a[4][4];
int empty;      //数组中空格的数目

void init();    //初始化数组
void Show();    //打印4X4方格及数组数据
void to_up();   //接收键盘输入，来控制数据移动方向
void to_down();
void to_left();
void to_right();
void add_num();     //随机添加一个数字到数组
void play();

int Game2048(void)
{
	printf("++++++++++++++++++++++++++++\n");
	printf("            2048            \n\n");
	printf("Control by:\n"
		" w/s/a/d or W/S/A/D\n");
	printf("press q or Q quit game!\n");
	printf("++++++++++++++++++++++++++++\n");
	printf("Any key to continue . . .\n");
	_getch();
	system("cls");
	init();
	Show();
	while (1)
		play();
	return 0;
}
void init()
{
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			a[i][j] = 0;
	srand(time(NULL));
	i = rand() % 4;
	j = rand() % 4;
	a[i][j] = 2;
	empty = 15;
}
void Show()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("|     ");
		printf("|\n");
		for (j = 0; j < 4; j++)
			if (a[i][j] == 0)
				printf("|     ");
			else
				printf("|%5d", a[i][j]);
		printf("|\n");
		for (j = 0; j < 4; j++)
			printf("|_____");
		printf("|\n");
	}
}
void play()
{
	switch (getch()) {
	case 'W':
	case 'w':
		system("cls");      //cls命令清空屏幕
		to_up();
		add_num();
		Show();
		break;
	case 'A':
	case 'a':
		system("cls");
		to_left();
		add_num();
		Show();
		break;
	case 'S':
	case 's':
		system("cls");
		to_down();
		add_num();
		Show();
		break;
	case 'D':
	case 'd':
		system("cls");
		to_right();
		add_num();
		Show();
		break;
	case 'q':
	case 'Q':
		puts("quiting");
		exit(EXIT_FAILURE);

	default:
		printf("\nwrong type!!!\n\n");
		printf("please type :\n");
		printf("w/s/a/d or W/S/A/D\n");
		break;
	}
}


//to_up()，将4x4方格阵向上移，并将相邻的大小相等的数据相加合并
void to_up()
{
	int i, j, tmp; //i为行数，j为列数，tmp为中间变量
	int lasti, lastj;
	//思路：
	//向上移动，则每一列为一个单元，每次操作，只考虑一列
	//对于一列，考虑第一个元素为当前元素，
	//如果当前元素为0，直接赋值为第一个相邻元素值，并置0该相邻元素
	//如果下一个元素（此时为第二个）为0，则，考虑下一个
	//如果下一个元素，与它相等，则相加合并（下一个元素要置0），
	//如果下一个元素，与它不等，则将它移到当前元素的相邻位置
	for (j = 0; j < 4; j++)
	{
		lasti = 0;
		lastj = j;          //当前元素坐标
		for (i = 1; i < 4; i++)
			if (a[i][j] == 0)                               //考虑下一个
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //当前元素为0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //当前元素与下一个相等
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //当前元素与第一个非0相邻元素不等
					tmp = a[i][j];
					a[i][j] = 0;
					a[++lasti][lastj] = tmp;                //置当前元素的相邻位（此时已被赋值）为当前元素
				}
			}
	}
}
//void to_up(void) {                //网上的另一种方法，多重循环造成的时间代价很大
//  int x, y, i;
//
//  for (y = 0; y < 4; ++y) {     // 从上向下合并相同的方块
//      for (x = 0; x < 4; ++x) {
//          if (a[x][y] == 0)
//              ;
//          else {
//              for (i = x + 1; i < 4; ++i) {
//                  if (a[i][y] == 0)
//                      ;
//                  else if (a[x][y] == a[i][y]) {
//                      a[x][y] += a[i][y];
//                      a[i][y] = 0;
//                      ++empty;
//                      x = i;
//                      break;
//                  }
//                  else {
//                      //x = i - 1;
//                      break;
//                  }
//              }
//          }
//      }
//  }
//
//  for (y = 0; y < 4; ++y)    // 向上移动箱子
//      for (x = 0; x < 4; ++x) {
//          if (a[x][y] == 0)
//              ;
//          else {
//              for (i = x; (i > 0) && (a[i - 1][y] == 0); --i) {
//                  a[i - 1][y] = a[i][y];
//                  a[i][y] = 0;
//              }
//          }
//      }
//}
void to_down()
{
	int i, j, tmp; //i为行数，j为列数，tmp为中间变量
	int lasti, lastj;
	for (j = 0; j < 4; j++)
	{
		lasti = 3;
		lastj = j;          //当前元素坐标
		for (i = 2; i >-1; i--)
			if (a[i][j] == 0)                               //考虑下一个
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //当前元素为0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //当前元素与下一个相等
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //当前元素与第一个非0相邻元素不等
					tmp = a[i][j];
					a[i][j] = 0;
					a[--lasti][lastj] = tmp;                //置当前元素的相邻位（此时已被赋值）为当前元素
				}
			}
	}
}
void to_left()
{
	int i, j, tmp; //i为行数，j为列数，tmp为中间变量
	int lasti, lastj;
	for (i = 0; i < 4; i++)
	{
		lasti = i;
		lastj = 0;          //当前元素坐标
		for (j = 1; j < 4; j++)
			if (a[i][j] == 0)                               //考虑下一个
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //当前元素为0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //当前元素与下一个相等
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //当前元素与第一个非0相邻元素不等
					tmp = a[i][j];
					a[i][j] = 0;
					a[lasti][++lastj] = tmp;                //置当前元素的相邻位（此时已被赋值）为当前元素
				}
			}
	}
}
void to_right()
{
	int i, j, tmp; //i为行数，j为列数，tmp为中间变量
	int lasti, lastj;
	for (i = 0; i < 4; i++)
	{
		lasti = i;
		lastj = 3;          //当前元素坐标
		for (j = 2; j>-1; j--)
			if (a[i][j] == 0)                               //考虑下一个
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //当前元素为0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //当前元素与下一个相等
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //当前元素与第一个非0相邻元素不等
					tmp = a[i][j];
					a[i][j] = 0;
					a[lasti][--lastj] = tmp;                //置当前元素的相邻位（此时已被赋值）为当前元素
				}
			}
	}
}

void add_num()
{
	x_y i_j;
	i_j = get_xy();
	if (i_j.x == -1)
	{
		return 0;
	}
	srand(time(NULL));

	a[i_j.x][i_j.y] = (rand() % 2) ? 2 : 4;
	empty--;
}
static x_y get_xy()
{
	int count, newxy, i, j;
	x_y i_j;
	if (empty == 0)
	{
		i_j.x = -1;
		i_j.y = -1;
		return i_j;
	}

	srand(time(NULL));
	count = -1;
	newxy = rand() % empty;     //表示应在第几个空添加新元素,newxy从0开始
	for (i = 0; i < 4; (i)++) {
		for (j = 0; j < 4; (j)++) {
			if (a[i][j] == 0) {
				count++;
				if (count == newxy)
				{
					i_j.x = i;
					i_j.y = j;
					return i_j;
				}
			}
		}
	}
}
