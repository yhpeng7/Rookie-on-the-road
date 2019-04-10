#include "Head.h"

void encrypt(char *password, int len) {
	for (int i = 0; i < len; i++) {
		password[i] ^= 127;
	}
}

void Write() {
	Player *region[] = { ShanXi.head,BeiJing.head,GuangDong.head,JiangSu.head,HeiLongJiang.head };
	char *regionName[] = { "ShanXi.bin","BeiJing.bin","GuangDong.bin","JiangSu.bin","HeiLongJiang.bin" };
	FILE *fp;

	int i, regionCount = sizeof(region) / sizeof(region[0]);

	for (i = 0; i < regionCount; i++) {
		fp = fopen(regionName[i], "w+b");
		Player *temp = region[i];

		while (temp) {
			encrypt(temp->password, strlen(temp->password));
			fwrite(temp, sizeof(Player), 1, fp);
			temp = temp->next;
		}

		fclose(fp);
	}
}

void Read(List *currlist) {
	List *region[] = { &ShanXi,&BeiJing,&GuangDong,&JiangSu,&HeiLongJiang };
	Player *pre, *temp = NULL;
	char *regionName[] = { "ShanXi.bin","BeiJing.bin","GuangDong.bin","JiangSu.bin","HeiLongJiang.bin" };
	FILE *fp;
	int i, regionCount = sizeof(region) / sizeof(region[0]);

	for (i = 0; i < regionCount; i++) {
		region[i]->head = NULL;
		fp = fopen(regionName[i], "a+b");

		int j, nodeCount;
		fseek(fp, 0L, SEEK_END);
		nodeCount = ftell(fp) / sizeof(Player);
		fseek(fp, 0L, SEEK_SET);

		for (j = 0; j < nodeCount; j++) {
			temp = Add(region[i]);
			fread(temp, sizeof(Player), 1, fp);
			encrypt(temp->password, strlen(temp->password));
		}

		fclose(fp);
	}
}
