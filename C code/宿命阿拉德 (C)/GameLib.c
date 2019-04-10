#include "Head.h"

void SetTitle(char *title) {
	SetConsoleTitle(title);            //设置程序标题
}

//0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
//8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
void SetColor(int foreColor, int backColor) {
	HANDLE winHandle;                  //句柄
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);        //设置控制台文本的属性
}


void SetPosition(int x, int y) {
	HANDLE winHandle;                  //设置光标位置
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);
}


void Clear(int x, int y, int rowCount) {
	int i, j;
	for (i = 0; i < rowCount; ++i) {
		SetPosition(x, y + i);
		for (j = 0; j < 70; ++j)
			printf(" ");
	}
}
