#include "Head.h"

/**
 *******来源: 知乎Milo Yip *******
 *
 * 1.心形
 * 2.心形（有花纹）
 * 3.心形（3D）
 * 4.心形（动画）
 *
 */

void ShowHeart1() {
	float y;
	float x;
	for (y = 1.5f; y > -1.5f; y -= 0.1f) {
		for (x = -1.5f; x < 1.5f; x += 0.05f) {
			float a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
		}
		putchar('\n');
	}
	ShowGameInfo();     //显示游戏信息
	getch();
	system("cls");
}


void ShowHeart2() {
	float y;
	float x;
	for (y = 1.5f; y > -1.5f; y -= 0.1f) {
		for (x = -1.5f; x < 1.5f; x += 0.05f) {
			float z = x * x + y * y - 1;
			float f = z * z * z - x * x * y * y * y;
			putchar(f <= 0.0f ? ".:-=+*#%@"[(int)(f * -8.0f)] : ' ');
		}
		putchar('\n');
	}
	system("pause");
	system("cls");
}

void ShowHeart3() {
	float f(float x, float y, float z) {
		float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
		return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
	}

	float h(float x, float z) {
		float y;
		for (y = 1.0f; y >= 0.0f; y -= 0.001f)
			if (f(x, y, z) <= 0.0f)
				return y;
		return 0.0f;
	}

	int ShowHeart_3D() {
		float z;
		float x;
		for (z = 1.5f; z > -1.5f; z -= 0.05f) {
			for (x = -1.5f; x < 1.5f; x += 0.025f) {
				float v = f(x, 0.0f, z);
				if (v <= 0.0f) {
					float y0 = h(x, z);
					float ny = 0.01f;
					float nx = h(x + ny, z) - y0;
					float nz = h(x, z + ny) - y0;
					float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
					float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
					putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
				} else
					putchar(' ');
			}
			putchar('\n');
		}
		system("pause");
		system("cls");
	}
}

float f(float x, float y, float z) {
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z) {
	float y;
	for (y = 1.0f; y >= 0.0f; y -= 0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

void ShowHeart4() {
	int ShowHeart() {
		HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
		_TCHAR buffer[25][80] = { _T(' ') };
		_TCHAR ramp[] = _T(".:-=+*#%@");

		float t;
		float z;
		float x;
		for (t = 0.0f;; t += 0.1f) {
			int sy = 0;
			float s = sinf(t);
			float a = s * s * s * s * 0.2f;
			for (z = 1.3f; z > -1.2f; z -= 0.1f) {
				_TCHAR* p = &buffer[sy++][0];
				float tz = z * (1.2f - a);
				for (x = -1.5f; x < 1.5f; x += 0.05f) {
					float tx = x * (1.2f + a);
					float v = f(tx, 0.0f, tz);
					if (v <= 0.0f) {
						float y0 = h(tx, tz);
						float ny = 0.01f;
						float nx = h(tx + ny, tz) - y0;
						float nz = h(tx, tz + ny) - y0;
						float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
						float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
						*p++ = ramp[(int)(d * 5.0f)];
					} else
						*p++ = ' ';
				}
			}

			for (sy = 0; sy < 25; sy++) {
				COORD coord = { 0, sy };
				SetConsoleCursorPosition(o, coord);
				WriteConsole(o, buffer[sy], 79, NULL, 0);
			}
			Sleep(33);
		}
	}
}
