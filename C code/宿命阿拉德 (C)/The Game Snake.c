#include "Head.h"

/*********************  来源：CSDN Sriven *********************/

#define R 24
#define H 24
#define W 48
#define UP 'w'  //上
#define DOWN 's'  //下
#define LEFT 'a'  //左
#define RIGHT 'd'  //右
void getfood();//产生食物
void start();//初始界面
void gameover();//游戏结束
void Play();//游戏过程F
void gotoxy(int, int);//定位坐标
void wall();//墙；
void gamerule();
void menu();//游戏菜单
void chushihua();//初始化蛇
void move();
void print();//打印蛇
void HideCursor();//隐藏光标
void turn(char);//改变方向
void getfood();//随机获取食物
void eatfood();//吃食物
int die();//判断是否死亡
struct Snake
{
	int x[100];//x[0]表示蛇尾的横坐标
	int y[100];//y[0]表示蛇尾的纵坐标
	int length;//蛇的长度
	int speed;//蛇的速度
	int count;//蛇吃的食物数量
}snake;
struct Food
{
	int x;
	int y;
}food;
int i, j;
int a[2];//a[1]储存蛇尾的纵坐标，a[0]储存蛇尾的横坐标
void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void toxy(int x, int y)//将光标移动到X,Y坐标处
{
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void start()//特效
{
	int x, y, i, j;
	system("color 72");
	for (i = 0; i<10; i++)
	{
		x = i;
		for (y = x; y<24 - x; y++)
		{
			toxy(2 * x, y);
			printf("0 ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * x, y);
			printf("0 ");
		}
		x = i;
		for (y = x; y<24 - x; y++)
		{
			toxy(2 * y, x);
			printf("0 ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * y, x);
			printf("0 ");
		}
		Sleep(100);
	}
	for (i = 0; i<10; i++)
	{
		x = i;
		for (y = x; y<R - x; y++)
		{
			toxy(2 * x, y);
			printf("  ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * x, y);
			printf("  ");
		}
		x = i;
		for (y = x; y<R - x; y++)
		{
			toxy(2 * y, x);
			printf("  ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * y, x);
			printf("  ");
		}
		Sleep(100);
	}

}
void wall()//边界
{
	system("color 74");
	system("cls");
	int i, j, map[H][W];
	for (i = 0; i<H; i++)
	{
		for (j = 0; j<W; j++)
		{
			if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
			{
				map[i][j] = '0';
			}
			else
			{
				map[i][j] = ' ';
			}
		}
	}
	for (i = 0; i<H; i++)
	{
		for (j = 0; j<W; j++)
		{
			//toxy(j,i);
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
void menu()//菜单
{
	toxy(20, 5);
	printf("贪吃蛇");
	toxy(19, 7);
	printf("1.开始游戏");
	toxy(19, 9);
	printf("2.游戏规则");
	toxy(19, 11);
	printf("3.退出游戏");
	toxy(19, 13);
	printf("By---Sriven");
}
void gamerule()
{
	system("cls");
	toxy(20, 11);
	printf("游戏规则");
	start();
	system("cls");
	wall();
	toxy(1, 1);
	printf("1.用w，s，a，d控制贪吃蛇的方向");
	toxy(1, 3);
	printf("2.当贪吃蛇吃到食物后，\n贪吃蛇身子变长");
	toxy(1, 5);
	printf("3.如果贪吃蛇的头部碰到墙壁或者碰到自己的身体，\n则游戏结束");
	getch();
	toxy(20, 11);
	printf("贪吃蛇");
	start();
}
void gameover()
{
	system("cls");
	system("color 71");
	wall();
	toxy(20, 11);
	printf("BY-BY");
	start();
	exit(0);
	getch();
}
void chushihua()//初始化蛇
{
	snake.length = 3;
	snake.speed = 500;
	snake.count = 0;
	snake.x[0] = 8;
	snake.y[0] = 10;
	for (i = 1; i<snake.length; i++)
	{
		snake.x[i] = snake.x[i - 1] + 1;
		snake.y[i] = snake.y[i - 1];
	}
}
void move()
{
	toxy(snake.x[0], snake.y[0]);
	printf(" ");
	for (i = 1; i<snake.length; i++)//将蛇的前一节坐标赋给后一节
	{
		snake.x[i - 1] = snake.x[i];
		snake.y[i - 1] = snake.y[i];
	}
	//snake.x[snake.length-1]=snake.x[snake.length-2]+2;
	//snake.y[snake.length-1]=snake.y[snake.length-2];
}
void print()//打印蛇
{
	for (i = 0; i<snake.length; i++)
	{
		toxy(snake.x[i], snake.y[i]);
		if (i == 0)
		{
			printf("+");
		}
		else if (i == snake.length - 1)
		{
			printf("+");
		}
		else
		{
			printf("+");
		}
	}
	system("color 71");
	toxy(50, 11);
	/*printf("按0结束游戏");
	toxy(50, 0);
	printf("分数：%d", 10 * snake.count);
	toxy(50, 2);
	printf("当前速度为：%d", snake.speed);
	toxy(50, 5);
	printf("1.用w，s，a，d控制贪吃蛇的方向");
	toxy(50, 7);
	printf("2.当贪吃蛇吃到食物后，贪吃蛇身子变长,每吃5个食物，速度增加");
	toxy(50, 9);
	printf("3.如果贪吃蛇的头部碰到墙壁或者碰到自己的身体，则游戏结束");
	toxy(60, 15);
	printf("By---Sriven");*/
}
void turn(char direction)//获取方向
{
	if (direction == 'w')
	{
		snake.y[snake.length - 1]--;
	}
	else if (direction == 's')
	{
		snake.y[snake.length - 1]++;
	}
	else if (direction == 'a')
	{
		snake.x[snake.length - 1] -= 1;
	}
	else if (direction == 'd')
	{
		snake.x[snake.length - 1] += 1;
	}
}
void getfood()
{
	//wall();
	srand(time(NULL));
	while (1)
	{
		food.x = rand() % 44 + 2;
		food.y = rand() % 21 + 2;
		for (i = 0; i<snake.length; i++)
		{
			if (food.x == snake.x[i] && food.y == snake.y[i])
			{
				break;
			}
		}
		if (i == snake.length)
		{
			toxy(food.x, food.y);
			printf("*"); break;
		}
	}
}
void eatfood()
{
	if (food.x == snake.x[snake.length - 1] && food.y == snake.y[snake.length - 1])
	{
		snake.length++;
		snake.count++;
		for (i = snake.length - 1; i >= 1; i--)
		{
			snake.x[i] = snake.x[i - 1];
			snake.y[i] = snake.y[i - 1];
		}
		snake.x[0] = a[0];
		snake.y[0] = a[1];
		if (snake.count % 5 == 0)
		{
			if (snake.count >= 40)
			{
				snake.speed = 100;
			}
			else
				snake.speed -= 50;
		}
		getfood();
	}
}
int die()
{
	int flag = 0;
	for (i = 0; i<snake.length - 1; i++)
	{
		if (snake.x[snake.length - 1] == snake.x[i] && snake.y[snake.length - 1] == snake.y[i])
		{
			flag = 1;
		}
	}
	if (snake.x[snake.length - 1] == 0 || snake.x[snake.length - 1] == W - 1 || snake.y[snake.length - 1] == 0 || snake.y[snake.length - 1] == H - 1)
	{
		flag = 1;
	}
	return(flag);
}
void Play()
{
	toxy(20, 11);
	printf("开始游戏");
	start();
	system("cls");
	char t = 'd';
	wall();
	chushihua();
	getfood();
	while (1)
	{
		a[0] = snake.x[0];
		a[1] = snake.y[0];
		if (kbhit())//判断是否有按键
		{
			t = getch();
		}
		if (t == '0')break;
		move();
		turn(t);
		eatfood();
		print();
		if (die())
		{
			toxy(20, 12);
			printf("Game over!");
			Sleep(2000);
			break;
		}
		Sleep(snake.speed);
	}
}
void GameSnake()
{
	system("color 72");
	HideCursor();//隐藏光标
	toxy(20, 11);
	printf("贪吃蛇");
	start();
	system("color 70");

	do
	{
		system("cls");
		HideCursor();
		char n;
		wall();
		menu();
		n = getch();
		switch (n)
		{
		case '1':Play(); break;
		case '2':gamerule(); break;
		case '3':gameover(); break;
		default:printf("Please input 1~3:"); break;
		}
	} while (1);//永远为真
}
