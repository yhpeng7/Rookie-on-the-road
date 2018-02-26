#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

/*设置控制台窗口的标题*/
void SetTitle(char *title);
/*设置文字的前景色和背景色*/
void SetColor(int foreColor,int backColor);
/*设置光标位置*/
void SetPosition(int x,int y);
/*从x,y坐标开始，清rowCount行*/
void Clear(int x,int y,int rowCount);

#endif // GAMELIB_H_INCLUDED
