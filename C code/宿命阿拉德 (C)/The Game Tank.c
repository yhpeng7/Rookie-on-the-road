#include "Head.h"

/*********************  来源：CSDN 王子原 *********************/

#define tank_taotal_N 10
#define tank_N 3
int p1_x = 12, p1_y = 29, p2_x = 19, p2_y = 29, p1_ball_x, p1_ball_y, p2_ball_x, p2_ball_y;
char map[32][32];
char p1_done = 'w', p2_done = 72, p1_ball_steer = '%', p2_ball_steer = '%';
int tank_number = 0, tank_total_number = 0, p1_live = 5, p2_live = 5;
int tank_x[tank_taotal_N], tank_y[tank_taotal_N], tank_live[tank_taotal_N];
int tank_step_number[tank_taotal_N], tank_steer[tank_taotal_N];
int tank_ball_steer[tank_taotal_N], tank_ball_x[tank_taotal_N], tank_ball_y[tank_taotal_N];
int home_live = 1;
void load_map_1() {
	int i;
	for (i = 4; i <= 13; i++, i++, i++) {
		map[i][4] = '#';
		map[i][5] = '#';
		map[i][6] = '#';
		map[i][10] = '#';
		map[i][11] = '#';
		map[i][12] = '#';
		map[i][19] = '#';
		map[i][20] = '#';
		map[i][21] = '#';
		map[i][25] = '#';
		map[i][26] = '#';
		map[i][27] = '#';
	}
	map[21][1] = '='; map[21][2] = '='; map[21][3] = '=';
	map[21][28] = '='; map[21][29] = '='; map[21][30] = '=';
	for (i = 10; i <= 21; i++) {
		map[24][i] = '#';
	}
	for (i = 10; i <= 21; i++) {
		map[17][i] = '#';
	}
}
void p1_fire() {
	p1_ball_steer = p1_done;
	switch (p1_ball_steer) {
		case 'w': {p1_ball_x = p1_x; p1_ball_y = p1_y - 2; break; }
		case 's': {p1_ball_x = p1_x; p1_ball_y = p1_y + 2; break; }
		case 'a': {p1_ball_x = p1_x - 2; p1_ball_y = p1_y; break; }
		case 'd': {p1_ball_x = p1_x + 2; p1_ball_y = p1_y; break; }
	}
	if (map[p1_ball_y][p1_ball_x] == ' ')map[p1_ball_y][p1_ball_x] = '*';
	else if (map[p1_ball_y][p1_ball_x] == '@') { map[p1_ball_y][p1_ball_x] = '*'; p1_ball_steer = '%'; } else if (map[p1_ball_y][p1_ball_x] == '#' || map[p1_ball_y][p1_ball_x] == '.') {
		map[p1_ball_y][p1_ball_x] = ' '; p1_ball_steer = '%';
	} else if (map[p1_ball_y][p1_ball_x] == '$')home_live = 0;
	else p1_ball_steer = '%';
}
void p2_fire() {
	p2_ball_steer = p2_done;
	switch (p2_ball_steer) {
		case 72: {p2_ball_x = p2_x; p2_ball_y = p2_y - 2; break; }
		case 80: {p2_ball_x = p2_x; p2_ball_y = p2_y + 2; break; }
		case 75: {p2_ball_x = p2_x - 2; p2_ball_y = p2_y; break; }
		case 77: {p2_ball_x = p2_x + 2; p2_ball_y = p2_y; break; }
	}
	if (map[p2_ball_y][p2_ball_x] == ' ')map[p2_ball_y][p2_ball_x] = '*';
	else if (map[p2_ball_y][p2_ball_x] == '@') { map[p2_ball_y][p2_ball_x] = '*'; p2_ball_steer = '%'; } else if (map[p2_ball_y][p2_ball_x] == '#' || map[p2_ball_y][p2_ball_x] == '.') {
		map[p2_ball_y][p2_ball_x] = ' '; p2_ball_steer = '%';
	} else if (map[p2_ball_y][p2_ball_x] == '$')home_live = 0;
	else p2_ball_steer = '%';
}
int if_tank_can_move(int x, int y) {
	if (map[y - 1][x - 1] != ' '&&map[y - 1][x - 1] != '.')return 0; if (map[y - 1][x] != ' '&&map[y - 1][x] != '.')return 0; if (map[y - 1][x + 1] != ' '&&map[y - 1][x + 1] != '.')return 0;
	if (map[y][x - 1] != ' '&&map[y][x - 1] != '.')return 0;    if (map[y][x] != ' '&&map[y][x] != '.')return 0;    if (map[y][x + 1] != ' '&&map[y][x + 1] != '.')return 0;
	if (map[y + 1][x - 1] != ' '&&map[y + 1][x - 1] != '.')return 0; if (map[y + 1][x] != ' '&&map[y + 1][x] != '.')return 0; if (map[y + 1][x + 1] != ' '&&map[y + 1][x + 1] != '.')return 0;
	return 1;
}
int if_tank_be_shot(int x, int y, int steer, char ball) {
	switch (steer) {
		case 0:
			{
				if (map[y - 1][x - 1] == ball)return 1;                                 if (map[y - 1][x + 1] == ball)return 1;
				if (map[y][x - 1] == ball)return 1;   if (map[y][x] == ball)return 1;     if (map[y][x + 1] == ball)return 1;
				if (map[y + 1][x] == ball)return 1;
				return 0;
			}
		case 1:
			{
				if (map[y - 1][x] == ball)return 1;   if (map[y - 1][x + 1] == ball)return 1;
				if (map[y][x - 1] == ball)return 1;   if (map[y][x] == ball)return 1;
				if (map[y + 1][x] == ball)return 1;   if (map[y + 1][x + 1] == ball)return 1;
				return 0;
			}
		case 2:
			{
				if (map[y - 1][x - 1] == ball)return 1; if (map[y - 1][x] == ball)return 1;
				if (map[y][x] == ball)return 1;     if (map[y][x + 1] == ball)return 1;
				if (map[y + 1][x - 1] == ball)return 1; if (map[y + 1][x] == ball)return 1;
				return 0;
			}
		case 3:
			{
				if (map[y - 1][x] == ball)return 1;
				if (map[y][x - 1] == ball)return 1;   if (map[y][x] == ball)return 1;     if (map[y][x + 1] == ball)return 1;
				if (map[y + 1][x - 1] == ball)return 1;                                 if (map[y + 1][x + 1] == ball)return 1;
				return 0;
			}
	}
	return 0;
}
void update(int x, int y) {
	map[y][x] = ' ';
	map[y - 1][x - 1] = ' ';
	map[y - 1][x] = ' ';
	map[y - 1][x + 1] = ' ';
	map[y][x + 1] = ' ';
	map[y + 1][x + 1] = ' ';
	map[y + 1][x] = ' ';
	map[y + 1][x - 1] = ' ';
	map[y][x - 1] = ' ';
}
void up(int x, int y, char w) {
	map[y - 1][x - 1] = ' '; map[y - 1][x] = w; map[y - 1][x + 1] = ' ';
	map[y][x - 1] = w;  map[y][x] = w;  map[y][x + 1] = w;
	map[y + 1][x - 1] = w; map[y + 1][x] = ' '; map[y + 1][x + 1] = w;
}
void down(int x, int y, char w) {
	map[y - 1][x - 1] = w; map[y - 1][x] = ' '; map[y - 1][x + 1] = w;
	map[y][x - 1] = w;  map[y][x] = w;  map[y][x + 1] = w;
	map[y + 1][x - 1] = ' '; map[y + 1][x] = w; map[y + 1][x + 1] = ' ';
}
void left(int x, int y, char w) {
	map[y - 1][x - 1] = ' '; map[y - 1][x] = w; map[y - 1][x + 1] = w;
	map[y][x - 1] = w;  map[y][x] = w;  map[y][x + 1] = ' ';
	map[y + 1][x - 1] = ' '; map[y + 1][x] = w; map[y + 1][x + 1] = w;
}
void right(int x, int y, char w) {
	map[y - 1][x - 1] = w; map[y - 1][x] = w; map[y - 1][x + 1] = ' ';
	map[y][x - 1] = ' ';  map[y][x] = w;  map[y][x + 1] = w;
	map[y + 1][x - 1] = w; map[y + 1][x] = w; map[y + 1][x + 1] = ' ';
}
void p1_move(char a) {
	int flag;
	update(p1_x, p1_y);
	p1_done = a;
	switch (a) {
		case 'w':
			{
				p1_y--;
				flag = if_tank_can_move(p1_x, p1_y);
				if (flag == 0)p1_y++;
				up(p1_x, p1_y, 'O');
				break;
			}
		case 's':
			{
				p1_y++;
				flag = if_tank_can_move(p1_x, p1_y);
				if (flag == 0)p1_y--;
				down(p1_x, p1_y, 'O');
				break;
			}
		case 'a':
			{
				p1_x--;
				flag = if_tank_can_move(p1_x, p1_y);
				if (flag == 0)p1_x++;
				left(p1_x, p1_y, 'O');
				break;
			}
		case 'd':
			{
				p1_x++;
				flag = if_tank_can_move(p1_x, p1_y);
				if (flag == 0)p1_x--;
				right(p1_x, p1_y, 'O');
				break;
			}
	}
}
void p2_move(char a) {
	int flag;
	update(p2_x, p2_y);
	p2_done = a;
	switch (a) {
		case 72:
			{
				p2_y--;
				flag = if_tank_can_move(p2_x, p2_y);
				if (flag == 0)p2_y++;
				up(p2_x, p2_y, 'o');
				break;
			}
		case 80:
			{
				p2_y++;
				flag = if_tank_can_move(p2_x, p2_y);
				if (flag == 0)p2_y--;
				down(p2_x, p2_y, 'o');
				break;
			}
		case 75:
			{
				p2_x--;
				flag = if_tank_can_move(p2_x, p2_y);
				if (flag == 0)p2_x++;
				left(p2_x, p2_y, 'o');
				break;
			}
		case 77:
			{
				p2_x++;
				flag = if_tank_can_move(p2_x, p2_y);
				if (flag == 0)p2_x--;
				right(p2_x, p2_y, 'o');
				break;
			}
	}
}
void choose_player(char a) {
	if (a == 'w' || a == 's' || a == 'a' || a == 'd' || a == 'g') {
		if (a != 'g')p1_move(a);
		else if (a == 'g'&&p1_ball_steer == '%')p1_fire();
	} else if (a == 72 || a == 80 || a == 75 || a == 77 || a == '0') {
		if (a != '0')p2_move(a);
		else if (a == '0'&&p2_ball_steer == '%')p2_fire();
	}
}
void load_map() {
	int i;
	for (i = 0; i <= 31; i++) {
		map[0][i] = '_';
		map[31][i] = '_';
		map[i][0] = '|';
		map[i][31] = '|';
	}
	map[0][0] = '+';
	map[0][31] = '+';
	map[31][31] = '+';
	map[31][0] = '+';
	map[28][14] = '#'; map[28][15] = '#'; map[28][16] = '#'; map[28][17] = '#';
	map[29][14] = '#'; map[29][15] = '$'; map[29][16] = '$'; map[29][17] = '#';
	map[30][14] = '#'; map[30][15] = '$'; map[30][16] = '$'; map[30][17] = '#';
	load_map_1();
}
void create_map() {
	int i, j;
	for (i = 0; i <= 31; i++) {
		for (j = 0; j <= 31; j++) {
			printf("%c", map[i][j]);
			printf(" ");
			if (j == 31) {
				printf("\n");
			}
		}
	}
}
void create_tank() {
	int x, y;
	while (1) {
		tank_x[tank_total_number] = rand() % 28 + 2;
		tank_y[tank_total_number] = 2;
		if (if_tank_can_move(tank_x[tank_total_number], tank_y[tank_total_number])) {
			break;
		}
	}
	x = tank_x[tank_total_number];
	y = tank_y[tank_total_number];
	map[y - 1][x - 1] = '@'; map[y - 1][x] = ' '; map[y - 1][x + 1] = '@';
	map[y][x - 1] = '@';  map[y][x] = '@';  map[y][x + 1] = '@';
	map[y + 1][x - 1] = ' '; map[y + 1][x] = '@'; map[y + 1][x + 1] = ' ';
	tank_live[tank_total_number] = 1;
	tank_step_number[tank_total_number] = 0;
}
void all_tank_move() {
	int i;
	for (i = 1; i <= tank_taotal_N - 1; i++) {
		if (tank_live[i] == 1) {
			if (tank_step_number[i] == 0) {
				tank_steer[i] = rand() % 4;
				tank_step_number[i] = rand() % 9 + 1;
			} else {
				update(tank_x[i], tank_y[i]);
				switch (tank_steer[i]) {
					case 0:
						{
							tank_y[i]++;
							if (if_tank_can_move(tank_x[i], tank_y[i]) == 0)tank_y[i]--;
							down(tank_x[i], tank_y[i], '@');
							break;
						}
					case 1:
						{
							tank_x[i]--;
							if (if_tank_can_move(tank_x[i], tank_y[i]) == 0)tank_x[i]++;
							left(tank_x[i], tank_y[i], '@');
							break;
						}
					case 2:
						{
							tank_x[i]++;
							if (if_tank_can_move(tank_x[i], tank_y[i]) == 0)tank_x[i]--;
							right(tank_x[i], tank_y[i], '@');
							break;
						}
					case 3:
						{
							tank_y[i]--;
							if (if_tank_can_move(tank_x[i], tank_y[i]) == 0)tank_y[i]++;
							up(tank_x[i], tank_y[i], '@');
							if (tank_step_number[i] > 3) {
								tank_step_number[i] = 3;
							}
						}
				}
				tank_step_number[i]--;
			}
		}
	}
}
void all_tank_check() {
	int i;
	for (i = 1; i <= tank_taotal_N - 1; i++) {
		if (tank_live[i] == 1) {
			if (if_tank_be_shot(tank_x[i], tank_y[i], tank_steer[i], '*')) {
				tank_live[i]--;
				tank_number--;
				update(tank_x[i], tank_y[i]);
			}
		}
	}
}
void all_tank_fire() {
	int i;
	for (i = 1; i <= tank_taotal_N - 1; i++) {
		if (tank_live[i] == 1 && tank_ball_steer[i] == '%'&&rand() % 20 == 1) {
			tank_ball_steer[i] = tank_steer[i];
			switch (tank_ball_steer[i]) {
				case 3: {tank_ball_x[i] = tank_x[i]; tank_ball_y[i] = tank_y[i] - 2; break; }
				case 0: {tank_ball_x[i] = tank_x[i]; tank_ball_y[i] = tank_y[i] + 2; break; }
				case 1: {tank_ball_x[i] = tank_x[i] - 2; tank_ball_y[i] = tank_y[i]; break; }
				case 2: {tank_ball_x[i] = tank_x[i] + 2; tank_ball_y[i] = tank_y[i]; break; }
			}
			if (map[tank_ball_y[i]][tank_ball_x[i]] == ' ')map[tank_ball_y[i]][tank_ball_x[i]] = '.';
			else if (map[tank_ball_y[i]][tank_ball_x[i]] == 'o' || map[tank_ball_y[i]][tank_ball_x[i]] == 'O') {
				map[tank_ball_y[i]][tank_ball_x[i]] = '.'; tank_ball_steer[i] = '%';
			} else if (map[tank_ball_y[i]][tank_ball_x[i]] == '#' || map[tank_ball_y[i]][tank_ball_x[i]] == '*') {
				map[tank_ball_y[i]][tank_ball_x[i]] = ' '; tank_ball_steer[i] = '%';
			} else if (map[tank_ball_y[i]][tank_ball_x[i]] == '$')home_live = 0;
			else tank_ball_steer[i] = '%';
		}
	}
}
void all_tank_ball_move() {
	int i;
	for (i = 1; i <= tank_taotal_N - 1; i++) {
		if (tank_ball_steer[i] != '%') {
			map[tank_ball_y[i]][tank_ball_x[i]] = ' ';
			switch (tank_ball_steer[i]) {
				case 3: {tank_ball_y[i]--; break; }
				case 0: {tank_ball_y[i]++; break; }
				case 1: {tank_ball_x[i]--; break; }
				case 2: {tank_ball_x[i]++; break; }
			}
			if (map[tank_ball_y[i]][tank_ball_x[i]] == ' ')map[tank_ball_y[i]][tank_ball_x[i]] = '.';
			else if (map[tank_ball_y[i]][tank_ball_x[i]] == 'o' || map[tank_ball_y[i]][tank_ball_x[i]] == 'O') {
				map[tank_ball_y[i]][tank_ball_x[i]] = '.'; tank_ball_steer[i] = '%';
			} else if (map[tank_ball_y[i]][tank_ball_x[i]] == '#' || map[tank_ball_y[i]][tank_ball_x[i]] == '*') {
				map[tank_ball_y[i]][tank_ball_x[i]] = ' '; tank_ball_steer[i] = '%';
			} else if (map[tank_ball_y[i]][tank_ball_x[i]] == '$')home_live = 0;
			else tank_ball_steer[i] = '%';
		}
	}
}
void p1_check() {
	int steer;
	switch (p1_done) {
		case 'w': {steer = 3; break; }
		case 's': {steer = 0; break; }
		case 'a': {steer = 1; break; }
		case 'd': {steer = 2; break; }
	}
	if (if_tank_be_shot(p1_x, p1_y, steer, '.')) {
		p1_live--;
		update(p1_x, p1_y);
		p1_x = 12; p1_y = 29;
	}
}
void p2_check() {
	int steer;
	switch (p2_done) {
		case 72: {steer = 3; break; }
		case 80: {steer = 0; break; }
		case 75: {steer = 1; break; }
		case 77: {steer = 2; break; }
	}
	if (if_tank_be_shot(p2_x, p2_y, steer, '.')) {
		p2_live--;
		update(p2_x, p2_y);
		p2_x = 19; p2_y = 29;
	}
}
int GameTank(void) {
	system("pause");
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned)time(NULL));
	char a;
	memset(map, ' ', sizeof(map));
	load_map();
	getch();
	while (1) {
		if (tank_number < tank_N&&tank_total_number < tank_taotal_N - 1) {
			tank_number++;
			tank_total_number++;
			create_tank();
		}
		all_tank_move();
		if (p1_ball_steer != '%') {
			map[p1_ball_y][p1_ball_x] = ' ';
			switch (p1_ball_steer) {
				case 'w': {p1_ball_y--; break; }
				case 's': {p1_ball_y++; break; }
				case 'a': {p1_ball_x--; break; }
				case 'd': {p1_ball_x++; break; }
			}
			if (map[p1_ball_y][p1_ball_x] == ' ')map[p1_ball_y][p1_ball_x] = '*';
			else if (map[p1_ball_y][p1_ball_x] == '@') { map[p1_ball_y][p1_ball_x] = '*'; p1_ball_steer = '%'; } else if (map[p1_ball_y][p1_ball_x] == '#' || map[p1_ball_y][p1_ball_x] == '.') {
				map[p1_ball_y][p1_ball_x] = ' '; p1_ball_steer = '%';
			} else if (map[p1_ball_y][p1_ball_x] == '$')home_live = 0;
			else p1_ball_steer = '%';
		}
		if (p2_ball_steer != '%') {
			map[p2_ball_y][p2_ball_x] = ' ';
			switch (p2_ball_steer) {
				case 72: {p2_ball_y--; break; }
				case 80: {p2_ball_y++; break; }
				case 75: {p2_ball_x--; break; }
				case 77: {p2_ball_x++; break; }
			}
			if (map[p2_ball_y][p2_ball_x] == ' ')map[p2_ball_y][p2_ball_x] = '*';
			else if (map[p2_ball_y][p2_ball_x] == '@') { map[p2_ball_y][p2_ball_x] = '*'; p2_ball_steer = '%'; } else if (map[p2_ball_y][p2_ball_x] == '#' || map[p2_ball_y][p2_ball_x] == '.') {
				map[p2_ball_y][p2_ball_x] = ' '; p2_ball_steer = '%';
			} else if (map[p2_ball_y][p2_ball_x] == '$')home_live = 0;
			else p2_ball_steer = '%';
		}
		if (kbhit()) {
			a = getch();
			choose_player(a);
		} else {
			Sleep(0);
		}
		all_tank_check();
		all_tank_fire();
		all_tank_ball_move();
		p1_check();
		p2_check();
		create_map();
		SetConsoleCursorPosition(hOutput, coord);
		if (tank_number == 0 && tank_total_number == 9) {
			break;
		}
		if (p1_live == 0 && p2_live == 0) {
			break;
		}
		if (home_live == 0) {
			break;
		}
	}
	SetConsoleCursorPosition(hOutput, coord);

	return 0;
}
