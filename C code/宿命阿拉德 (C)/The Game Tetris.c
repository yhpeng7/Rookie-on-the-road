#include "Head.h"

/*********************  来源：CSDN 井蛙_t *********************/

#define FrameX 4   //窗口左上角的X轴坐标
#define FrameY 4   //窗口左上角的Y轴坐标
#define Frame_height  20 //窗口的高度
#define Frame_width   18 //窗口的宽度
struct Tetris {
	int x;  //中心方块的x轴坐标
	int y;  //中心方块的y轴坐标
	int flag;//标记方块类型号
	int next;//下一个俄罗斯方块类型的序号
	int speed;//俄罗斯方块移动的速度
	int count;//产生俄罗斯方块的个数
	int score;//游戏的分数
	int level;//游戏的等级
};
enum keyvalue {
	ESC = 0x1b, LeftArrow = 0x4be0, RightArrow = 0x4de0, Blank = 0x20, DownArrow = 0x50e0
};
int i, j, k, temp, temp1, temp2;//temp1,temp2,temp3用来记住和转换方块变量的值
int a[100][100] = { 0 };//1代表方块，2代表边界，0代表空格
int b[4];//记录四个方块
struct Tetris *tetris;
short int getkey()//定义共用体，接受键盘按键
{
	union key {
		unsigned short int value;
		unsigned char ch[2];
	} key1;
	key1.value = 0;
	if (kbhit()) {
		key1.ch[0] = getch();
		if (kbhit())
			key1.ch[1] = getch();
	}
	return key1.value;
}
void Gotoxy(int x, int y)   //将光标移到到指位置
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Make_tetris() //中心方块位置坐标，1-有，0-无
{
	a[tetris->x][tetris->y] = b[0];
	switch (tetris->flag) {
		case 1:
			a[tetris->x][tetris->y - 1] = b[1];    //■■
			a[tetris->x + 2][tetris->y - 1] = b[2];//■■
			a[tetris->x + 2][tetris->y] = b[3];    //
			break;
		case 2:
			a[tetris->x - 2][tetris->y] = b[1];//
			a[tetris->x + 2][tetris->y] = b[2];//■■■■
			a[tetris->x + 4][tetris->y] = b[3];//
			break;
		case 3:
			a[tetris->x][tetris->y - 1] = b[1];//■
			a[tetris->x][tetris->y - 2] = b[2];//■
			a[tetris->x][tetris->y + 1] = b[3];//■
			break;                             //■
		case 4:
			a[tetris->x - 2][tetris->y] = b[1];//
			a[tetris->x + 2][tetris->y] = b[2];//■■■
			a[tetris->x][tetris->y + 1] = b[3];//  ■
			break;
		case 5:
			a[tetris->x][tetris->y - 1] = b[1];//  ■
			a[tetris->x][tetris->y + 1] = b[2];//■■
			a[tetris->x - 2][tetris->y] = b[3];//  ■
			break;
		case 6:
			a[tetris->x][tetris->y - 1] = b[1];//  ■
			a[tetris->x - 2][tetris->y] = b[2];//■■■
			a[tetris->x + 2][tetris->y] = b[3];//
			break;
		case 7:
			a[tetris->x][tetris->y - 1] = b[1];//■
			a[tetris->x][tetris->y + 1] = b[2];//■■
			a[tetris->x + 2][tetris->y] = b[3];//■
			break;
		case 8:
			a[tetris->x][tetris->y + 1] = b[1];    //
			a[tetris->x - 2][tetris->y] = b[2];    //■■
			a[tetris->x + 2][tetris->y + 1] = b[3];//  ■■
			break;
		case 9:
			a[tetris->x][tetris->y - 1] = b[1];    //  ■
			a[tetris->x - 2][tetris->y] = b[2];    //■■
			a[tetris->x - 2][tetris->y + 1] = b[3];//■
			break;
		case 10:
			a[tetris->x][tetris->y - 1] = b[1];    //■■
			a[tetris->x - 2][tetris->y - 1] = b[2];//  ■■
			a[tetris->x + 2][tetris->y] = b[3];    //
			break;
		case 11:
			a[tetris->x][tetris->y + 1] = b[1];      //  ■
			a[tetris->x + 2][tetris->y - 1] = b[2];//■■
			a[tetris->x + 2][tetris->y] = b[3];    //■
			break;
		case 12:
			a[tetris->x][tetris->y - 1] = b[1];  //■■
			a[tetris->x][tetris->y + 1] = b[2];  //  ■
			a[tetris->x - 2][tetris->y - 1] = b[3];//  ■
			break;
		case 13:
			a[tetris->x - 2][tetris->y] = b[1];  //
			a[tetris->x - 2][tetris->y + 1] = b[2];//■■■
			a[tetris->x + 2][tetris->y] = b[3];  //■
			break;
		case 14:
			a[tetris->x][tetris->y - 1] = b[1];  // ■
			a[tetris->x][tetris->y + 1] = b[2];  // ■
			a[tetris->x + 2][tetris->y + 1] = b[3];// ■■
			break;
		case 15:
			a[tetris->x - 2][tetris->y] = b[1];    //
			a[tetris->x + 2][tetris->y - 1] = b[2];//■■■
			a[tetris->x + 2][tetris->y] = b[3];    //    ■
			break;
		case 16:
			a[tetris->x][tetris->y + 1] = b[1];    //■■
			a[tetris->x][tetris->y - 1] = b[2];    //■
			a[tetris->x + 2][tetris->y - 1] = b[3];//■
			break;
		case 17:
			a[tetris->x - 2][tetris->y] = b[1];    //■
			a[tetris->x - 2][tetris->y - 1] = b[2];//■■■
			a[tetris->x + 2][tetris->y] = b[3];    //
			break;
		case 18:
			a[tetris->x][tetris->y - 1] = b[1];    //  ■
			a[tetris->x][tetris->y + 1] = b[2];    //  ■
			a[tetris->x - 2][tetris->y + 1] = b[3];//■■
			break;
		case 19:
			a[tetris->x - 2][tetris->y] = b[1];    //
			a[tetris->x + 2][tetris->y + 1] = b[2];//■■■
			a[tetris->x + 2][tetris->y] = b[3];    //    ■
			break;
	}
}
//制作游戏窗口
void Make_Frame() {
	Gotoxy(FrameX + Frame_width - 5, FrameY - 2);
	printf("俄罗斯方块");
	Gotoxy(FrameX, FrameY);
	a[FrameX][FrameY] = 2;
	printf("╔");                          //窗口四周
	for (i = 2; i < 2 * Frame_width - 2; i += 2) {
		printf("═");                      //打印上横框
	}
	printf("╗");
	a[FrameX + 2 * Frame_width - 2][FrameY + Frame_height] = 2;
	for (i = 1; i < Frame_height; i++) {
		Gotoxy(FrameX, FrameY + i);
		printf("║");                      //打印左竖框
		a[FrameX][FrameY + i] = 2;         //记住左竖框有图案
	}
	Gotoxy(FrameX, FrameY + Frame_height);
	printf("╚");
	a[FrameX][FrameY + Frame_height] = 2;
	for (i = 1; i < Frame_height; i++) {
		Gotoxy(FrameX + 2 * Frame_width - 2, FrameY + i);
		printf("║");                        //打印右横框
		a[FrameX + 2 * Frame_width - 2][FrameY + i] = 2;//记住右竖框有图案
	}
	Gotoxy(FrameX + 2, FrameY + Frame_height);
	for (i = 2; i < 2 * Frame_width - 2; i += 2) {
		printf("═");                        //打印下横框
		a[FrameX + i][FrameY + Frame_height] = 2;//记住下横框有图案
	}
	printf("╝");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 7);   //打印菜单
	printf("**********下一个方块");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 13);
	printf("**********");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 15);
	printf("空格键：变体");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 17);
	printf("←键：左移");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 19);
	printf("→键：右移");
}
//判断方块是否可以移动
bool Movable() {
	if (a[tetris->x][tetris->y] != 0) //当中心方块位置上有图案时，返回false，即不可移动
		return false;
	else {
		if (//当方块的四个位置的值均为0，即无图案时，可移动
			(tetris->flag == 1 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)) ||
				(tetris->flag == 2 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 &&
					a[tetris->x + 4][tetris->y] == 0)) ||
					(tetris->flag == 3 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y - 2] == 0 &&
						a[tetris->x][tetris->y + 1] == 0)) ||
						(tetris->flag == 4 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 &&
							a[tetris->x][tetris->y + 1] == 0)) ||
							(tetris->flag == 5 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
								a[tetris->x - 2][tetris->y] == 0)) ||
								(tetris->flag == 6 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 &&
									a[tetris->x + 2][tetris->y] == 0)) ||
									(tetris->flag == 7 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
										a[tetris->x + 2][tetris->y] == 0)) ||
										(tetris->flag == 8 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y] == 0 &&
											a[tetris->x + 2][tetris->y + 1] == 0)) ||
											(tetris->flag == 9 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 &&
												a[tetris->x - 2][tetris->y + 1] == 0)) ||
												(tetris->flag == 10 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 &&
													a[tetris->x + 2][tetris->y] == 0)) ||
													(tetris->flag == 11 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 &&
														a[tetris->x + 2][tetris->y] == 0)) ||
														(tetris->flag == 12 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
															a[tetris->x - 2][tetris->y - 1] == 0)) ||
															(tetris->flag == 13 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y + 1] == 0 &&
																a[tetris->x + 2][tetris->y] == 0)) ||
																(tetris->flag == 14 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
																	a[tetris->x + 2][tetris->y + 1] == 0)) ||
																	(tetris->flag == 15 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 &&
																		a[tetris->x + 2][tetris->y] == 0)) ||
																		(tetris->flag == 16 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x][tetris->y - 1] == 0 &&
																			a[tetris->x + 2][tetris->y - 1] == 0)) ||
																			(tetris->flag == 17 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 &&
																				a[tetris->x + 2][tetris->y] == 0)) ||
																				(tetris->flag == 18 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
																					a[tetris->x - 2][tetris->y + 1] == 0)) ||
																					(tetris->flag == 19 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y + 1] == 0 &&
																						a[tetris->x + 2][tetris->y] == 0))) {
			return true;
		}
	}
	return false;
}
//随机产生俄罗斯方块类型的序号
void Get_flag() {
	tetris->count++; //记住产生方块的个数
	srand((unsigned)time(NULL));
	if (tetris->count == 1)
		tetris->flag = rand() % 19 + 1;//记住第一个方块的序号
	srand((unsigned)time(NULL));
	tetris->next = rand() % 19 + 1;//记住下一个方块的序号
}
//打印俄罗斯方块
void Print_tetris() {
	for (i = 0; i < 4; i++)
		b[i] = 1;
	Make_tetris();
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
		for (j = tetris->y - 2; j <= tetris->y + 1; j++) {
			if (a[i][j] == 1 && j > FrameY) {
				Gotoxy(i, j);
				printf("■");           ///有问题！！！
			}
		}
	}
	//打印菜单信息
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 1);
	printf("level：%d", tetris->level);
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 3);
	printf("score：%d", tetris->score);
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 5);
	printf("speed：%dms", tetris->speed);
}
//清除俄罗斯方块的痕迹
void Clear_tetris() {
	for (i = 0; i < 4; i++)
		b[i] = 0;
	Make_tetris();
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
		for (j = tetris->y - 2; j <= tetris->y + 1; j++) {
			if (a[i][j] == 0 && j > FrameY) {
				Gotoxy(i, j);
				printf("  ");
			}
		}
	}
}
//判断是否满行并删除满行的俄罗斯方块
void Del_full() {
	int del_count = 0;

	for (j = FrameY + Frame_height - 1; j >= FrameY + 1; j--) {
		k = 0;//用于记录某行方块的个数
		for (i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {
			if (a[i][j] == 1) {
				k++;
				if (k == Frame_width - 2)//该行已满
				{
					for (k = FrameX + 2; k < FrameX + 2 * Frame_width - 2; k += 2) {
						a[k][j] = 0;
						Gotoxy(k, j);
						printf("  ");
						Sleep(1);
					}
					for (k = j - 1; k > FrameY; k--) {
						for (i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {
							if (a[i][k] == 1) {
								a[i][k] = 0;
								Gotoxy(i, k);
								printf("  ");
								a[i][k + 1] = i;
								Gotoxy(i, k + 1);
								printf("■");
							}
						}
					}
					j++;//※※※方块下移后，重新判断删除行是否满行
					del_count++;//记录删除方块的行数
				}
			}
		}
	}
	tetris->score += 10 * del_count;    //没删除一行，得10分
	if (del_count > 0 && tetris->score % 100 == 0)                //有问题！！！
	{
		tetris->speed -= 20;//如果累计消除10行，速度加快20ms并升一级
		tetris->level++;
	}
}
//开始游戏
void Start_game() {
	tetris = (struct Tetris*)malloc(sizeof(struct Tetris));
	int key = 0;//键盘按键
	key = getkey();
	tetris->count = 0;//初始化俄罗斯方块数为0个
	tetris->speed = 300;//初始移动速度为300ms
	tetris->score = 0;//初始游戏分数为0分
	tetris->level = 1;//初始游戏关为第1关
	while (1)//循环产生方块，直至游戏结束
	{
		Get_flag();
		temp = tetris->flag;
		//打印下一个俄罗斯方块的图形（右窗口）
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		tetris->flag = tetris->next;
		Print_tetris();
		tetris->x = FrameX + Frame_width;//初始中心方块x坐标
		tetris->y = FrameY - 1;
		tetris->flag = temp; //取出当前的俄罗斯方块序号
		while (1)//控制方块方向，直至方块不再下移
		{
			Print_tetris();
			Sleep(tetris->speed);
			Clear_tetris();
			temp1 = tetris->x;//记住中心方块的横坐标
			temp2 = tetris->flag;//记住当前俄罗斯方块序号
			if (kbhit()) {
				key = getkey();
				switch (key) {
					case LeftArrow:
						tetris->x -= 2;//中心横坐标-2
						break;
					case RightArrow:
						tetris->x += 2;//中心横坐标+2
						break;
					case Blank://旋转
						if (tetris->flag == 2 || tetris->flag == 3) {
							tetris->flag++;
							tetris->flag %= 2;
							tetris->flag += 2;
						} else if (tetris->flag >= 4 && tetris->flag <= 7) {
							tetris->flag++;
							tetris->flag %= 4;
							tetris->flag += 4;
						} else if (tetris->flag >= 8 && tetris->flag <= 11) {
							tetris->flag++;
							tetris->flag %= 4;
							tetris->flag += 8;
						} else if (tetris->flag >= 12 && tetris->flag <= 15) {
							tetris->flag++;
							tetris->flag %= 4;
							tetris->flag += 12;
						} else if (tetris->flag >= 16 && tetris->flag <= 19) {
							tetris->flag++;
							tetris->flag %= 4;
							tetris->flag += 16;
						}
						break;
				}
				if (!Movable())//如果不可移动，上面操作无效
				{
					tetris->x = temp1;
					tetris->flag = temp2;
				}
			}
			tetris->y++;//如果没有操作指令，方块向下移动
			if (!Movable())//如果向下移动且不可移动，方块放在此处
			{
				tetris->y--;
				Print_tetris();
				Del_full();
				break;
			}
		}
		for (i = tetris->y - 2; i < tetris->y + 2; i++) {
			if (i == FrameY)
				j = 0;                             //游戏结束
		}
		if (j == 0) {
			for (j = 0; j < Frame_height + 1; j++) {
				Gotoxy(FrameX + 1, FrameY + j);
				for (i = 1; i < Frame_width; i++)
					printf("□");
			}
			Gotoxy(FrameX + Frame_width - 4, FrameY + Frame_height / 2);
			printf("GAME OVER!");
			Gotoxy(FrameX, FrameY + Frame_height + 1);
			getch();
			break;
		}
		//清除下一个俄罗斯方块的图形（右窗口）
		tetris->flag = tetris->next;
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		Clear_tetris();
	}
}
int GameTetris(void) {
	Make_Frame();
	Start_game();
	getch();
	printf("按任意键结束...");
	return 0;
}
