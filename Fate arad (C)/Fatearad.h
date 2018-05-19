#ifndef SWORDSMAN_H_INCLUDED
#define SWORDSMAN_H_INCLUDED

#define SEP "------------------------------------------------------------------------------------"
#define LSEP "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

#define MARGIN_X 17             //左边距
#define MAP_START_Y 3           //地图开始的Y坐标
#define MAP_END_Y   11          //地图结束的Y坐标
#define INFO_START_Y 12         //信息界面开始的Y坐标
#define INFO_END_Y 21           //信息界面的结束Y坐标
#define MAINMENU_START_Y 22     //主菜单开始的Y坐标

/***************************************************
 *
 * 描  述：一个C语言小项目
 * 创建人：鹏
 * 日  期：2018-02-20
 * 版  本：1.1
 * 博  客：
 *
 **************************************************/

typedef enum _proptype
{
    Weapon,Armor,Consumables,Card,Fragment
}PropType;
/*武器，防具，消耗品，卡片，碎片*/
typedef struct _prop
{
    int id;              //道具编号
    char name[50];       //道具名称
    int level;           //道具级别
    int stock;           //道具的库存量或玩家背包中的叠加数量
    int price;        //道具价格
    PropType type;       //道具类型
    union
    {
        int mindefence;
        int minattack;
    }Min;
    union
    {
        int maxdefence;
        int maxattack;
    }Max;
    char desc[200];
}Prop;


/*背包*/
typedef struct _bag{
    int count;                  //当前背包中道具的数量
    int max;                    //当前背包的插槽总数
    Prop props[9];              //当前背包中的道具数组
}Bag;


/*地图*/
typedef struct _map
{
    int id;
    char name[50];
    int minLevel;       //玩家进入的最低等级
    COORD coord;        //地图坐标
    char desc[500];
}Map;


typedef struct _player
{
    int id;
    char name[51];
    char password[50];
    char role[50];
    int level;
    int exp;
    int gamecredit;//游戏积分
    int hp;
    int mp;
    int gold;
    int attack;
    int defence;
    Prop weapon;
    Prop armor;
    Bag bag;
    struct _player *next;
}Player;

typedef struct _list{
    struct _player * head;
    struct _player * tail;
}List;

List *Target,ShanXi,BeiJing,GuangDong,JiangSu,HeiLongJiang,HeiLongJiang;

/*怪物*/
typedef struct _monster
{
    int id;
    char name[50];
    int hp;
    int attack;
    int defence;
    int minMoney;
    int maxMoney;
    int exp;
    int state;
    COORD coord;
}Monster;

void GameStart();
void Register();
void Login();
void ShowHeart1();
void ShowGameInfo();
void ShowWelcome();
void ShowMap();
void ShowMapInfo();
void ShowInfomation();
void ShowMainMenu();
void ProcessMainMenu(char key);
void ShowPlayerInfo();
void ShowMonster();
void FightMonster(int,int*);
void AreaMovement();
void ShowStore();
void Transaction();
void ShowBag();
void UseProps();
void FunnyGames();

#endif // SWORDSMAN_H_INCLUDED
