#include "Head.h"


void Choice() {
	char key;
	fflush(stdin);
	while ((key = getch()) != '1' && key != '2' && key != '3' && key != '4' && key != '5');
	fflush(stdin);

	switch (key) {
        case '1':   Target = &ShanXi;    break;
        case '2':   Target = &BeiJing;    break;
        case '3':   Target = &GuangDong;    break;
        case '4':   Target = &JiangSu;    break;
        case '5':   Target = &HeiLongJiang;    break;
	}
}

void encryption(char password[]) {

}

void Print(List *list) {
	system("cls");
	Player *temp = list->head;
	printf("ID      密码               姓名              职业              等级      物理攻击        金币\n");
	while (temp) {
		printf("%-8d%-19s%-18s%-18s%-10d%-16d%d\n", temp->id, temp->password, temp->name, temp->role, temp->level, temp->attack, temp->gold);
		temp = temp->next;
	}
	getch();
}

/*排序*/
void Sort(List *list, int choice) {
	int compare;

	Player *p, *pmin, *pminbefore;
	Player *newlist = NULL, *tail;
	while (list->head) {
		/*找到原链表中值最小的节点*/
		for (p = pmin = list->head; p->next != NULL; p = p->next) {
			switch (choice) {
			    case 1: compare = (p->next->id < pmin->id ? 1 : 0);     break;
			    case 2: compare = (strcmp(p->next->name, pmin->name) < 0 ? 1 : 0);  break;
			    case 3: compare = (p->next->gold > pmin->gold ? 1 : 0);     break;
			}
			if (compare) {
				pminbefore = p;
				pmin = p->next;
			}
		}
		/*把当前链表值最小的节点放到新链表的末尾*/
		if (newlist) {
			tail->next = pmin;
			tail = pmin;
		} else
			newlist = tail = pmin;

		/*对原链表的操作*/
		if (pmin == list->head)
			list->head = list->head->next;
		else        //最后一步不可以free
			pminbefore->next = pmin->next;
	}
	if (newlist != NULL)
		tail->next = NULL;

	list->head = newlist;
	list->tail = tail;
	Print(list);
}

/*增加玩家*/
Player *Add(List *list) {
	Player *pNew = (Player *)malloc(sizeof(Player));
	pNew->next = NULL;
	if (list->head) {
		pNew->id = list->tail->id + 1;
		list->tail->next = pNew;
		list->tail = pNew;
	} else {
		list->head = list->tail = pNew;
		pNew->id = 1;
	}
	return pNew;
}

/*ID查找*/
Player *Find(List *list, int id) {
	Player *temp = list->head;
	while (temp) {
		if (temp->id == id)
			return temp;
		temp = temp->next;
	}
	return 0;
}

/*查找玩家*/
bool FindPlayer(List *list) {
	while (1) {
		system("cls");
		int id;
		Player *find = NULL;
		printf("请输入要查找的玩家ID（按0退出查找）：\n");
		scanf("%d", &id);
		fflush(stdin);
		if (id == 0)
			return;
		if (!(find = Find(list, id))) {
			printf("输入有误，请重新输入！");
			continue;
		}

		printf("玩家信息如下：\n");
		printf("ID      密码               姓名              职业                 等级      物理攻击        金币\n");
		printf("%-8d%-19s%-18s%-21s%-10d%-16d%d\n", find->id, find->password, find->name, find->role, find->level, find->attack, find->gold);
		getch();
		return true;
		return false;
	}
}

/*修改玩家信息*/
void Modification(List *list) {
	do {
		system("cls");
		int id;
		char key;
		Player *find = NULL;
		printf("请输入要修改的玩家ID(按0退出修改):\n");
		scanf("%d", &id);
		fflush(stdin);
		if (id == 0)
			return;
		if (!(find = Find(list, id))) {
			printf("请确认您输入的ID是否正确！\n");
			getch();
			continue;
		}

		do {
			system("cls");
			printf("玩家信息如下:\n");
			printf("ID      姓名      密码      攻击力     防御力         金币\n");
			printf("%d      %s      %s      %d      %d      %d\n\n", find->id, find->name, find->password, find->attack, find->defence, find->gold);
			printf("请选择要修改的信息(按0返回)：\n");
			printf("1.姓名    2.密码    \n3.攻击力   4.防御力   5.金币\n");
			fflush(stdin);
			while (key = getche(), key != '1' && key != '2' && key != '3' && key != '4' && key != '5' && key != '0');
			fflush(stdin);

			switch (key) {
			    case '1': scanf("%s", find->name); break;
			    case '2': scanf("%s", find->password); break;
			    case '3': scanf("%d", &find->attack); break;
			    case '4': scanf("%d", &find->defence); break;
			    case '5': scanf("%d", &find->gold); break;
			}
		} while (key != '0');

	} while (1);
}

void AddPlayer(List *list) {
	char c;
	while (c = getch() != '0') {
		system("cls");
		Add(list);
		Player *add = list->tail;
		printf("请输入要添加的玩家姓名：\n");
		scanf("%s", add->name);
		printf("请输入要添加的玩家密码：\n");
		scanf("%s", add->password);
		printf("请输入要添加的玩家金币：\n");
		scanf("%d", &add->gold);
		printf("请输入要添加的卡槽数量：\n");
		scanf("%d", &add->bag.max);

		add->hp = 10000;
		add->mp = 10000;
		add->level = 1;
		add->attack = 200;
		add->defence = 200;
		strcpy(add->role, "鬼泣");
		totalQuantity++;
		printf("按0结束输入。\n");
	}
}

void DeletePlayer(List *list) {
	Player *pPre, *deleteid = list->head;
	int id;
	char c;
	while (c = getch() != '0') {
		system("cls");

		printf("请输入要删除的玩家ID(按0退出删除)：\n");
		while (scanf("%d", &id), !(Find(list, id))) {
			fflush(stdin);
			if (id == 0)
				return;
			printf("请检查输入的ID是否正确！");
			getch();
			system("cls");
			printf("请输入要删除的玩家ID(按0退出删除)：\n");
		}

		fflush(stdin);

		if (Find(list, id) == list->head) {
			list->head = list->head->next;
			deleteid = list->head;
			totalQuantity--;
			printf("按0结束删除。\n");
			continue;
		}
		while (deleteid && deleteid->id != id) {
			pPre = deleteid;
			deleteid = deleteid->next;
		}
		pPre->next = deleteid->next;
		free(deleteid);
		totalQuantity--;
		printf("按0结束删除。\n");
	}
}
