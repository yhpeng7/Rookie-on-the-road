#include "Head.h"

/*********************************************************************************************************/

/*道具信息*/
Prop propArray[] =
{
{1,"御魂-七支刀",2,5,2000,Weapon,.Min.minattack=1,.Max.maxattack=4},
{2,"代号N-神谕",3,5,5000,Weapon,.Min.minattack=1,.Max.maxattack=4},
{3,"黑月狼牙",1,5,500,Weapon,.Min.minattack=1,.Max.maxattack=4},
{4,"幽魂魅影套装",1,5,500,Armor,.Min.mindefence=100,.Max.maxdefence=500},
{5,"魔战无双套装",1,5,500,Armor,.Min.mindefence=100,.Max.maxdefence=500},
{6,"天御雷罚套装",1,5,500,Armor,.Min.mindefence=100,.Max.maxdefence=500},
{7,"天堂的HP药剂(100%)",1,5,500,Consumables,"恢复100%HP。"},
{8,"闪亮的雷米援助(30%)",1,5,500,Consumables,"恢复30%HP和MP，解除所有等级的异常状态。"},
{9,"乾坤袋(+1)",1,5,500,Consumables,"背包插槽总数+1。"}
};

/*地图信息*/
Map mapArray[8][8] =
{
    {
        {1, "赫顿玛尔",   1, {0, 0}, "曾经是贝尔玛尔时期一个繁华的商业都市，后来与暗精灵王国的诺伊佩拉一样，因为一场瘟疫，而成为一座死城。据传瘟疫仅扩散了一个月左右，整个城市便无一人幸存。更令人不解的是，瘟疫过后，那里竟然找不到多少原居民的尸体。诺斯玛尔早年还曾被“疯狂盗贼团”占领，后来冒险家们剿灭盗贼团，查清瘟疫真相后便一直闲置。如今由于泰拉石资源丰富，又逐渐复苏。"},
        {2, "银色村庄",   1, {1, 0}, "毁灭纪使格兰之森一带变成了贫瘠之地。 不过耸立于亚诺法森林中央的圣树周围缭绕着强大的神圣气息，因而没有受到毁灭纪的伤害。幸存的人们，三三两两地聚集到圣树周围，在参天大树上形成了一个小村落“银色村庄”。 毁灭纪之后变得异常虚弱的精灵们也被圣树强大的气息所吸引，纷纷聚集到了这里。精灵们在圣树神圣的气息下恢复了部分能力，制作出无数精灵结晶体，覆盖于荒废的大地上，逐渐统治了银色村庄附近。不同属性的精灵结晶体会呈现出不同的颜色，以此划分不同的精灵领地。 "},
        {3, "悬空海港", 1, {2, 0}, "鲁夫特悬空海港位于根特西边、奥斯宾岛西南端的港口，是往返于奥斯宾诸岛的所有岛屿的文物，曾一度在卡勒特的进攻下沦为废墟。现在，皇都军收复了这里，并在一定程度上进行了重建，但是，一些与卡勒特签订契约的海洋生物的变种，却频繁袭击海上列车，很多海上列车不得不停止通行，停泊在港口。"},
        {4, "赫伊斯", 1, {3, 0}, "赫伊斯位于西部无法地带的阴森峡谷中，被卡勒特占领后成为其重要战略要塞。陡峻的地势和浓重的雾气，使它成为暗藏军队物资的绝佳地点。也因为这样，即使根特已经恢复安定，皇都军仍无法收复这里。有情报称皇女艾丽婕也被护送到了赫伊斯……为了确认这个消息，皇都军恳请勇士们前往赫伊斯地区进行搜索……"},
        {5, "阿登高地", 1, {4, 0}, "阿登高地是黎明之眼--安祖·赛弗驻守的最后堡垒。这个以阿登高地的两次会战而闻名的决战之都，现已沦陷为卡勒特的军事要塞。也许是因为安祖·赛弗的命令，虽然卡勒特部队已被逼入绝境，但仍毫无投降的意思，反而使战势越演越烈……"},
        {6, "绝望之塔", 1, {5, 0}, "这里聚集着各种各样的人，有不受欢迎的、不甘于死亡的，还有被诅咒、被遗弃、被背叛的.....他们忍受着寂寞的困扰，一直呆在这里，只为了一个共同的理由——寻找那个不可捉摸的虚幻传说，据说塔里的最上层有着一位传说中的强者，只要谁能够打败他，就可以站在技艺的顶峰。"},
        {7, "极限祭坛", 1, {6, 0}, "你了解自身的极限吗？你确定？或许，你的体内还隐藏着更强大的力量，只是害怕去挖掘……如果你勇于挑战，并且对自身的极限充满好奇的话，就到这里来吧。不过，如果你目前的实力就是你的极限，那么恐怕会因此付出生命的代价……"},
        {8, "斯顿雪域", 1, {7, 0}, "班图族的首都。为了躲避每30年苏醒一次的雪山冰龙斯卡萨，班图族不得不周期性的越过国境入侵他国，以求得生存空间。对于时常迁移的班图族而言，首都这个词可能不太恰当，但班图族们将首都定在了斯顿雪域后，并没有继续往南面撤退。 这里距离雪山并不远，从这儿可以很清晰的看到雪山。"}
    },
    {
        {9, "  ", 1, {0, 2}, " "},
        {10, " ", 1, {1, 2}, " "},
        {11, " ", 1, {2, 2}, " "},
        {12, " ", 1, {3, 2}, " "},
        {13, " ", 1, {4, 2}, " "},
        {14, " ", 1, {5, 2}, " "},
        {15, " ", 1, {6, 2}, " "},
        {16, " ", 1, {7, 2}, " "}
    },
    {
        {17, "迷妄之塔", 1, {0, 2}, " 穷尽一生追逐浮华的名利幻影，到人生的最后一刻才明白这一切不过是虚无，这是人生给予每个生命最珍贵的礼物！那些在尘世中感到彷徨无助的人啊，我已将你们心里的诸般迷妄在此地重现，你们再也不用忍受欲望的煎熬，直接来这里吧，来取走你们人生中最珍贵的礼物吧！ "},
        {18, "死亡之塔", 1, {1, 2}, " 没错！我就是死神！不过你不要害怕，死神是不会毫无理由的剥夺一个人的生命！渴望和强者对决的人啊，为了满足你们的欲望，我建造了此塔并把冥界的强者聚于一堂。呵呵，你们的斗志已经燃烧了吧？只有你们能登上塔顶，我保证全世界都会承认你们的强大！当然，我始终会等着你失败的那刻，呃哈哈~哈哈哈哈...... "},
        {19, "无尽祭坛", 1, {2, 2}, "你想试试手气吗？你想一夜暴富吗？那就快来参与吧！这里有专为勇者准备的祭坛。在这个祭坛里，只要你有不畏牺牲的勇气，就能拥有梦想的财富名利！在这里，死亡将变得毫无意义，等待你们的是永无止尽的战斗！恶魔的诱惑，欲望的召唤！被蒙蔽了双眼的冒险家们啊，浴血奋战吧！"},
        {20, "悲鸣洞穴", 1, {3, 2}, "悲鸣洞穴因其恐怖的悲鸣声闻名阿拉德大陆！12年前，第五使徒希洛克占据悲鸣洞穴并杀死了洞内的戮蛊，恐怖的悲鸣声也因此消失了。但悲鸣洞穴最近有传出了恐怖的悲鸣声，它预兆着什么？难道是虫王戮蛊复活？为了解开谜团，许多人开始前往悲鸣洞穴……"},
        {21, "诺伊佩拉", 1, {4, 2}, "突然爆发的传染病让暗精灵城镇洛伊佩拉一夕之间变成了一座空城，居住在那里的居民变成了恐怖的盗尸者，游荡在漂流洞穴附近，发出怨恨的悲鸣……它们对鲜血充满了渴望，带着无比的仇恨诅咒着诺伊佩拉城内还活着的人……得到这一消息之后，暗精灵王国立即派人前往调查。现在，最有价值的线索就是来自艾丽丝的占卜--“暗精灵城镇的传染病与人类的帝国有关。”一向与人类不睦的暗精灵，在听到这个预言之后，越加的不相信人类……"},
        {22, "炽晶森林", 1, {5, 2}, "精灵们的安身之所，但在毁灭纪中已经变得支离破碎。虽然借助银色村庄的力量，森林的资源和生态得到了恢复，但是曾经失去家园的精灵们，现在对外人的警惕心变得越来越强，也越来越具有攻击性，冒险家们，请一定要小心……。"},
        {23, "蜘蛛王国", 1, {6, 2}, "蜘蛛国王死后，蜘蛛王国被分成互相对立的两个势力。王子尼古拉斯和公主安吉丽娜为了争夺王位，愚蠢地使用禁忌的力量，最终让蜘蛛王国走上了被死灵诅咒的灭亡之路。现在，他们为了那所谓的王位，仍然在黑暗的洞穴中无休止地争斗着……"},
        {24, "邪龙封印", 1, {7, 2}, "很久之前，为了封印邪龙斯皮兹，矮人族和暗精灵付出了巨大的代价。数百年之后，邪龙的封印似乎有了松动征兆……在巨大的威胁面前，矮人和暗精灵族决定暂时化解仇恨，并肩战斗。希望他们不是貌合神离……"}
    },
    {
        {25, "  ", 1, {0, 3}," "},
        {26, "  ", 1, {1, 3}, " "},
        {27, "  ", 1, {2, 3}, " "},
        {28, "  ", 1, {3, 3}, " "},
        {29, "  ", 1, {4, 3}, " "},
        {30, "  ", 1, {5, 3}, " "},
        {31, "  ", 1, {6, 3}, " "},
        {32, "  ", 1, {7, 3}, " "}
    },
    {
        {33, "暗黑圣战", 1, {0, 4}, "一场激烈的交战后，圣职者们终于艰难的击退了混沌之奥兹玛和暗黑骑士们。因为是以神的名义战胜了黑暗势力，因此这场战役在历史上被成为暗黑圣战。但史书不会记载的是，有一个小女孩，正深深的思念着她在这场战斗中失踪的圣职者哥哥……"},
        {34, "暮色之城", 1, {1, 4}, "黑暗降临！蠢蠢欲动的瘟疫正在觊觎你的生命。千万不要停下脚步，只有向着光明前进，才有可能挽救你的性命！"},
        {35, "冰刺庭院", 1, {2, 4}, "为什么想进入这条荆棘之路？那里究竟有什么吸引着你，可以让你不惜遍体鳞伤也要一探究竟？你的勇气值得赞扬，但请记住，这里的一切是梦，又不完全是梦，锋利的荆棘随时会让你付出生命的代价！"},
        {36, "极光幻境", 1, {3, 4}, "阿拉德大陆上曾经有一座高耸入云的城，它的美轮美奂吸引着无数冒险家前往。可惜现在已经遭到了破坏，再也不复往日的荣光。但不要以为这样就能够任意进出了，城主的噩梦随时会让你身陷险境……"},
        {37, "黑色雪山", 1, {4, 4}, "即使是在万年冰雪覆盖的山上，黑暗也是犹如梦魇一般降临。冰冷与痛苦将会给你带来无尽的绝望，小心，不要被黑暗吞噬了……"},
        {38, "噩梦之源", 1, {5, 4}, "终于到达了噩梦的最深处，在这里你会遇到噩梦的根源，如果你能将它斩除，那么这一切可能就要结束了。但千万不能掉以轻心，一步走错，就会让你落入万丈深渊。"},
        {39, "根特防御", 1, {6, 4}, "皇都军突袭北门期间，截取到卡勒特正准备发动总攻的情报。一旦卡勒特发动总攻，冒险家们将要面对那些疯狂涌入的卡勒特兵团！冒险家们唯有坚定信念，尽最大努力阻挡卡勒特兵团，才能为皇都军争取多一点的时间。但，冒险家们能坚持到最后吗？"},
        {40, "哈尔特山", 1, {7, 4}, "卡勒特被冒险家和根特精锐部队打败后，剩下的残兵败将进入了根特北部的哈尔特山，在那里建造了最后的堡垒。他们的首领猎狗基辛格把吉赛尔丢弃的机器人改造为自己的武器，用剩余的物资建造了一个巨大的导弹塔，准备对根特进行反击。冒险家，潜入哈尔特山摧毁导弹塔，消灭猎狗基辛格和他的残余部队吧！"}
    },
    {
       {41, "  ", 1, {0, 3}, " "},
       {42, "  ", 1, {1, 3}, " "},
       {43, "  ", 1, {2, 3}, " "},
       {44, "  ", 1, {3, 3}, " "},
       {45, "  ", 1, {4, 3}, " "},
       {46, "  ", 1, {5, 3}, " "},
       {47, "  ", 1, {6, 3}, " "},
       {48, "  ", 1, {7, 3}, " "}
    },
    {
        {49, "  DNF", 1, {0, 7}, " "},
        {50, "  DNF", 1, {1, 7}, " "},
        {51, "  DNF", 1, {2, 7}, " "},
        {52, "  DNF", 1, {3, 7}, " "},
        {53, "  DNF", 1, {4, 7}, " "},
        {54, "  DNF", 1, {5, 7}, " "},
        {55, "  DNF", 1, {6, 7}, " "},
        {56, "  DNF", 1, {7, 7}, " "}
    },
    {
        {57, "  DNF", 1, {0, 3}, " "},
        {58, "  DNF", 1, {1, 3}, " "},
        {59, "  DNF", 1, {2, 3}, " "},
        {60, "  DNF", 1, {3, 3}, " "},
        {61, "  DNF", 1, {4, 3}, " "},
        {62, "  DNF", 1, {5, 3}, " "},
        {63, "  DNF", 1, {6, 3}, " "},
        {64, "  DNF", 1, {7, 3}, " "}
    }
};

/*玩家信息*/
/*Player players[50] = {
    {777,"花泽灸舞","tgtgtg","黑暗君主",90,1000,0,99999,99999,70000,66600,20000,{0,"荒古遗尘太刀"},{0,"光怪陆离套装"},{0,9}}
};*/

/*怪物信息*/
Monster monsterArray[] = {
    {1, "投掷十夫长", 1000, 1000, 100, 100, 5, 10, 5, 1, {0, 0}},
    {2, "库罗猫妖", 200, 200, 8, 2, 5, 10, 5, 1, {0, 0}},
    {3, "园丁鲁尔", 800, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {4, "浮游石巨人", 800, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {5, "光之城主赛格哈特", 7, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {6, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {7, "黎明之传道士", 500, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {8, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {9, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {10, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {11, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {12, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {13, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {14, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {15, "罪恶之眼", 600, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {16, "冰齿沙凡特", 900, 100, 5, 2, 5, 10, 5, 1, {0, 0}}
};

/*********************************************************************************************************/
int X = 0,Y = 0;
int propsCount = sizeof(propArray)/sizeof(Prop);

Player *currPlayer = NULL;
Prop *currProp = NULL;

int Fatearad()
{
    SetTitle("宿命阿拉德");

    Read();

    Select();
    SetColor(12,0);
    ShowHeart1();           //and ShowGameInfo()
    ShowWelcome();
    ShowMap();
    ShowInfomation();
    ShowMainMenu();

    while(1)
    {
        fflush(stdin);
        char key = getch();
        fflush(stdin);

        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '0' ||key == '6' || key == 32)
        {
            ProcessMainMenu(key);
            continue;
        }
        else if(key == 'H' || key == VK_UP)      //上
        {
            Y--;
            Y--;
        }
        else if(key == 'M' || key == VK_RIGHT)      //右
        {
            X++;
        }
        else if(key == 'P' || key == VK_DOWN)      //下
        {
            Y++;
            Y++;
        }
        else if(key == 'K' || key == VK_LEFT)      //左
        {
            X--;
        }
        if(X>7) X=0;
        if(X<0) X=7;
        if(Y>4) Y=0;
        if(Y<0) Y=4;
        ShowMap();
        SetPosition(MARGIN_X+11,MAINMENU_START_Y+4);
    }
    return 0;
}

void Select()
{
    while(1)
    {
    system("cls");
    SetColor(10,0);
    SetPosition(55,11);
    printf("欢迎来到阿拉德大陆！请确认您的身份：");
    SetPosition(55,12);
    printf("1.征战者");
    SetPosition(55,13);
    printf("2.独裁者");
    SetPosition(55,15);
    printf("按Esc键离开阿拉德大陆。");

    fflush(stdin);
    char key;
    while((key= getch())!='1' && key!='2' && key!=27);
    fflush(stdin);

    if(key == '1')
    {
        GameStart();
        return;
    }
    else if(key == '2')
    {
        Manage();
    }
    else if(key == 27)
    {
        Write();
        system("cls");
        exit(0);
    }
    }
}

void Manage()
{

    while(1)
    {
    system("cls");
    SetColor(10,0);
    SetPosition(55,11);
    printf("a.管理大区：");
    SetPosition(55,13);
    printf("1)陕西      2)北京");
    SetPosition(55,15);
    printf("3)广东      4)江苏      5)黑龙江");
    SetPosition(55,17);
    printf("b.福布斯排行榜（所有大区）");
    SetPosition(55,19);
    printf("0.返回上一层");

    char key;
    fflush(stdin);
    while((key= getch())!='1' && key!='2' && key!='3' && key!='4' && key!='5' && key!= '0');
    fflush(stdin);

    switch(key)
    {
        case '1':   Target = &ShanXi;    break;
        case '2':   Target = &BeiJing;    break;
        case '3':   Target = &GuangDong;    break;
        case '4':   Target = &JiangSu;    break;
        case '5':   Target = &HeiLongJiang;    break;
        case '0':   return;
    }
        Dispose();
    }
}

/*处理*/
void Dispose()
{
    while(1)
    {
    system("cls");
    SetColor(10,0);
    SetPosition(55,11);
    printf("请选择要执行的操作：");
    SetPosition(55,13);
    printf("1.玩家列表（ID）");
    SetPosition(55,15);
    printf("2.玩家列表（按字典顺序输出）");
    SetPosition(55,17);
    printf("3.福布斯排行榜");
    SetPosition(55,19);
    printf("4.查找玩家");
    SetPosition(55,21);
    printf("5.修改玩家信息");
    SetPosition(55,23);
    printf("6.增加玩家");
    SetPosition(55,25);
    printf("7.删除玩家");
    SetPosition(55,27);
    printf("0.返回上一层");

    char key;
    fflush(stdin);
    while(key= getch(),key !='1' && key!='2' && key!='3' && key!='4' && key!='5' && key!='6' && key!='7'&& key != '0');
    fflush(stdin);

    switch(key)
    {
        case '1':   SortID(Target);   break;
        case '2':   SortName(Target);   break;
        case '3':   SortGold(Target);   break;
        case '4':   FindPlayer(Target);     break;
        case '5':   Modification(Target);  break;
        case '6':   AddPlayer(Target);
        case '7':   DeletePlayer(Target);    break;
        case '0':   return;
    }
    }
}

void GameStart()
{
    system("cls");
    SetColor(10,0);
    SetPosition(55,11);
    printf("1.注册\n");
    SetPosition(55,12);
    printf("2.登录");
    SetPosition(55,14);
    printf("按Esc退出系统。");

    char key;
    fflush(stdin);
    while((key= getch())!='1' && key!='2' && key!=27);
    fflush(stdin);

    if(key == '1')  Register();
    if(key == '2')  Login();
    if(key == 27)
    {
        Write();
        system("cls");
        exit(0);
    }
}

void Register()
{

    system("cls");
    SetPosition(55,11);
    printf("请选择大区：");
    SetPosition(55,13);
    printf("1.陕西      2.北京");
    SetPosition(55,15);
    printf("3.广东      4.江苏      5.黑龙江");

    Choice();

    Add(Target);
    currPlayer = Target -> tail;

    int i,c,id;
    char name[50];

    system("cls");
    SetPosition(55,11);
    printf("Tips:按回车键结束输入");
    SetPosition(55,12);
    printf("请输入勇士名：");

    /*初始化玩家数据*/
        scanf("%s",&name);
        strcpy(currPlayer -> name,name);

    SetPosition(55,13);
    printf("请输入密码：");
    for(i=0;(c=getche())!=13;++i)
        currPlayer -> password[i] = c;

        currPlayer -> hp = 10000;
        currPlayer -> mp = 10000;
        currPlayer -> level = 1;
        currPlayer -> gold = 50000000;
        currPlayer -> attack = 1;
        currPlayer -> defence = 200;
        currPlayer -> bag.max = 3;

    SetPosition(55,15);
    printf("请选择角色：");
    SetPosition(65,17);
    printf("1. 鬼剑士(男)    2. 格斗家(女)");
    SetPosition(65,19);
    printf("3. 神枪手(男)    4. 圣职者");
    SetPosition(65,21);
    printf("5. 神枪手(女)    6. 暗夜使者");
    SetPosition(65,23);
    printf("7. 格斗家(男)    8. 守护者");
    SetPosition(65,25);
    printf("9. 魔法师(男)    a. 魔枪士");
    SetPosition(65,27);
    printf("b. 鬼剑士(女)    c. 黑暗武士");
    SetPosition(65,29);
    printf("d. 缔造者");

    while(c = getch(),c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != 'a' && c != 'b' && c != 'c' && c != 'd' && c != 'A' && c != 'B' && c != 'C' && c != 'D');

    switch(c)
    {
            case '1':   strcpy(currPlayer -> role,"鬼剑士(男)");
        break;
            case '2':   strcpy(currPlayer -> role,"格斗家(女)");
        break;
            case '3':   strcpy(currPlayer -> role,"神枪手(男))");
        break;
            case '4':   strcpy(currPlayer -> role,"圣职者");
        break;
            case '5':   strcpy(currPlayer -> role,"神枪手(女) ");
        break;
            case '6':   strcpy(currPlayer -> role,"暗夜使者");
        break;
            case '7':   strcpy(currPlayer -> role,"格斗家(男)");
        break;
            case '8':   strcpy(currPlayer -> role,"守护者");
        break;
            case '9':   strcpy(currPlayer -> role,"魔法师(男)");
        break;
            case 'A':
            case 'a':   strcpy(currPlayer -> role,"魔枪士");
        break;
            case 'B':
            case 'b':   strcpy(currPlayer -> role,"鬼剑士(女)");
        break;
            case 'C':
            case 'c':   strcpy(currPlayer -> role,"黑暗武士");
        break;
            case 'D':
            case 'd':   strcpy(currPlayer -> role,"缔造者");
        break;
    }
    system("cls");
}


void Login()
{
    system("cls");
    SetPosition(55,11);
    printf("请选择大区：");
    SetPosition(55,13);
    printf("1.陕西      2.北京");
    SetPosition(55,15);
    printf("3.广东      4.江苏      5.黑龙江");

    Choice();
    system("cls");
    int i,id;
    char c;
    char logpass[50];
    SetPosition(55,11);
    Player *temp = Target -> head;
    printf("请输入id：");

    /*控制不让用户胡乱输入*/
    while(scanf("%d",&id),!(Find(Target,id)) || id < 0 && !isdigit(id))
    {
        fflush(stdin);
        SetPosition(55,11);
        printf("                                            ");
        SetPosition(55,11);
        printf("请输入id：");
    }
    while(temp)
    {
        if(temp -> id == id)
        {
            currPlayer = temp;
            break;
        }
            temp = temp -> next;
    }

    do
    {
    SetPosition(55,12);
    printf("                                                          ");
    SetPosition(55,12);
    printf("请输入密码：");
    for(i = 0;c = getch(),c != '\r';i++)
    {
        logpass[i] = c;
        putchar('*');
    }
    logpass[i] = '\0';
    }while(strcmp(currPlayer -> password,logpass));
    system("cls");
}


void ShowGameInfo()
{
    SetColor(10,0);
    SetPosition(MARGIN_X+7,MAP_START_Y+4);
    printf("*            *");
    SetPosition(MARGIN_X+7,MAP_START_Y+5);
    printf("  宿命阿拉德  ");
    SetPosition(MARGIN_X+7,MAP_START_Y+6);
    printf("*            *");
    SetPosition(MARGIN_X+45,MAP_START_Y+14);
    SetColor(11,0);

    int i;
    char desc[500] = {"自阿拉德历977年，阿拉德大陆开始发生神秘的“异变”现象后，这片大陆就没有一刻安宁。 尽管在格兰之火中，精灵一族用自己的生命修复了魔法阵，换来了短暂的和平。 但是，随后发生的转移现象及各种瘟疫又让它再度陷入了危机…… 然而，这一切的噩梦也只是个开始。 那场史无前例的灾难才是真正地将整片大陆推入了无尽的地狱。 幸存者们对此只留下了深深的恐惧，他们将之称为：“毁灭纪”。 在那场灾难中，整个阿拉德大陆发生了大爆炸，很多地方因此成为了废墟，时空也因为爆炸的关系变得一片混乱……"};
    int descLen = strlen(desc);
    for(i=0;i<descLen;++i)
    {
        if(i != 0 && i % 41 == 0)
            SetPosition(MARGIN_X+45,MAP_START_Y+14+i/41);
        printf("%c",desc[i]);
    }
    SetColor(10,0);
}


void ShowWelcome()
{
    SetPosition(MARGIN_X,0);
    printf(SEP);
    SetPosition(MARGIN_X,1);
    printf("|");
    SetPosition(MARGIN_X+34,1);
    printf("欢迎来到阿拉德大陆");
    SetPosition(MARGIN_X+83,1);
    printf("|");
    SetPosition(MARGIN_X,2);
    printf(SEP);
}


void ShowMap()
{
    int i,j;
    for(i=0;i<8;++i)
    {
        SetPosition(MARGIN_X,MAP_START_Y+i);
        printf("*");
        for(j=0;j<8;++j)
        {
            if(i == Y && j == X)
                SetColor(13,0);                 //更改光标所在文字的颜色和背景色
            printf("  %-8s",mapArray[i][j].name);
                SetColor(10,0);                 //恢复默认前景色和背景色
        }
        SetPosition(MARGIN_X+83,i+3);
        printf("*\n");
    }
    SetPosition(MARGIN_X,MAP_END_Y);
    printf(SEP);
    ShowMapInfo();
}


void ShowMapInfo()
{
    /*1.清除信息窗的信息*/
    Clear(MARGIN_X + 7,INFO_START_Y,9);
    SetPosition(MARGIN_X+36,INFO_START_Y);
    printf("《%s》",mapArray[Y][X].name);
    SetPosition(MARGIN_X+12,INFO_START_Y+1);
    char *desc=mapArray[Y][X].desc;
    int descLen = strlen(desc);
    int i,j;
    for(i=0;i<descLen;++i)
    {
            if(i != 0 && i%60 == 0)
               SetPosition(MARGIN_X+12,INFO_START_Y+i/60+1);
            printf("%c",desc[i]);
    }
}


void ShowInfomation()
{
    SetPosition(MARGIN_X,INFO_START_Y);
    int i;
    for(i=0;i<9;++i)
    {
            SetPosition(MARGIN_X + 6,INFO_START_Y+i);
            printf("|");
            SetPosition(MARGIN_X + 77,INFO_START_Y+i);
            printf("|");
    }
    SetPosition(0,INFO_END_Y);
    printf(LSEP);
}


void ShowMainMenu()
{
/*    SetPosition(MARGIN_X,MAINMENU_START_Y);
    printf("游戏菜单：");*/
    SetPosition(MARGIN_X, MAINMENU_START_Y + 1);
    printf("1、个人信息");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 2);
    printf("2、进入地图");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("3、区域移动");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 4);
    printf("4、加百利的神秘商店");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 5);
    printf("5、背包");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 6);
    printf("6、返回初始界面");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 7);
    printf("0、退出游戏");
    SetPosition(MARGIN_X + 65, MAINMENU_START_Y + 8);
    printf("传送门(Space)");
}


void ProcessMainMenu(char key)
{
    switch(key)
    {
    case '1':   ShowPlayerInfo();
        break;
    case '2':   ShowMonster();
        break;
    case '3':   AreaMovement();
        break;
    case '4':   ShowStore();
        break;
    case '5':   ShowBag();
        break;
    case '6':   Select();       SetColor(12,0);     ShowHeart1();
                ShowWelcome();  ShowMap();          ShowInfomation();
                ShowMainMenu();
        break;
    case 32 :   FunnyGames();
        break;
    case '0':   system("cls");      Write();     exit(0);
        break;
    default:
        return;
    }
}


void ShowPlayerInfo()
{
    Clear(MARGIN_X + 7,INFO_START_Y,9);
    SetPosition(MARGIN_X + 30, INFO_START_Y);
    printf("*%s*的个人资料如下：",currPlayer -> name);
    SetColor(12,0);
    printf("\t   %s",currPlayer -> role);
    SetColor(10,0);

    SetPosition(MARGIN_X + 7, INFO_START_Y + 2);
    printf("ID：%-7d",currPlayer -> id);
    printf("等级：%-7d",currPlayer -> level);
    printf("生命值：%-9d",currPlayer -> hp);
    printf("魔法值：%-9d",currPlayer -> mp);
    printf("经验值：%d",currPlayer -> exp);

    SetPosition(MARGIN_X + 9, INFO_START_Y + 4);
    printf("\t攻击力：%-13d",currPlayer ->attack);
    printf("防御力：%-13d",currPlayer -> defence);
    printf("财富：%d金",currPlayer -> gold);

    SetPosition(MARGIN_X + 7, INFO_START_Y + 6);
    printf("当前武器：%s(攻击力%d-%d)    ",currPlayer -> weapon.name,currPlayer -> weapon.Min.minattack,currPlayer -> weapon.Max.maxattack);
    printf("当前防具：%s(防御力%d-%d)",currPlayer -> armor.name,currPlayer -> armor.Min.mindefence,currPlayer -> armor.Max.maxdefence);
}


void ShowMonster()
{
    if(currPlayer -> hp <= 0)
        return;

    Clear(MARGIN_X + 7,INFO_START_Y,9);
    SetPosition(MARGIN_X +29, INFO_START_Y);

    //当前地图怪物下标数组
    int monsterIndexs[15];
    //当前地图的怪物总数
    int currMapMonsterCount = 0;
    int monsterCount = sizeof(monsterArray) / sizeof(Monster);
    int i;
    for(i = 0;i < monsterCount; ++i)
    {
        if(monsterArray[i].coord.X == X && monsterArray[i].coord.Y == Y && monsterArray[i].state != 0)
        {
            monsterIndexs[currMapMonsterCount++] = i;
            if(currMapMonsterCount == 9)
                break;
        }
    }
    if(currMapMonsterCount == 0)
    {
        printf("当前地图无怪物。");
        return;
    }
    printf("当前地图出现了如下的怪物：");
    SetPosition(MARGIN_X + 7, INFO_START_Y+2);
    for(i=0;i<currMapMonsterCount;++i)
    {
        if(i!=0 && i%3 == 0)
        SetPosition(MARGIN_X + 7, INFO_START_Y+2+2*i/3);
        printf("%d.%-23s",i+1,monsterArray[monsterIndexs[i]].name);
    }
    FightMonster(currMapMonsterCount,monsterIndexs);             //传参
}


void FightMonster(int currMapMonsterCount, int *monsterIndexs)
{
    int i,attack;
    SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
    printf("请输入要攻击的对象：");
    char key;
    fflush(stdin);
    key = getch();
    fflush(stdin);
    if(key >= '1' && key <='currMapMonsterCount')
    {
        for(i=0;;++i)
        {
            SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
            if(currPlayer -> hp >= 0 && monsterArray[monsterIndexs[key - 49]].hp >= 0)
            {
                currPlayer -> hp -= (attack = monsterArray[monsterIndexs[key - 49]].attack - currPlayer -> defence) > 0 ? attack : 0;
                monsterArray[monsterIndexs[key - 49]].hp -= (attack = currPlayer -> attack - monsterArray[monsterIndexs[key - 49]].defence) > 0 ? attack : 0;
                printf("战斗第%d轮\t%sHP:%d\t%sHP:%d",i+1,currPlayer -> name,currPlayer -> hp,monsterArray[monsterIndexs[key - 49]].name,monsterArray[monsterIndexs[key - 49]].hp);
                Sleep(100);
                Clear(MARGIN_X + 7,INFO_END_Y - 1,1);
            }
            else
                break;
        }
        /*玩家死*/
        if((currPlayer -> hp) <= 0)
        {
            currPlayer -> hp = 0;
            if(currPlayer -> level > 0)
                currPlayer -> level --;
            SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
            printf("                                                                                    ");
            SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
            printf("您已被剽悍的怪物殴打致死，是否使用复活币（消耗1游戏积分）：（Y/N）");
            key = getch();
            if(key == 'y' || key == 'Y')
            {
                if(currPlayer -> gamecredit <= 0)
                {
                SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
                printf("您的游戏积分不足！");
                return;
                }
                currPlayer -> gamecredit --;
                currPlayer -> hp = 10000;
                currPlayer -> level++;
            }
        }
        /*怪物死*/
        else if(monsterArray[monsterIndexs[key - 49]].hp <= 0)
        {
            printf("%s已被您杀死！获得%d经验，%d金币。",monsterArray[monsterIndexs[key - 49]].name,monsterArray[monsterIndexs[key - 49]].exp,monsterArray[monsterIndexs[key - 49]].maxMoney);
            currPlayer -> exp += monsterArray[monsterIndexs[key - 49]].exp;
            currPlayer -> gold += monsterArray[monsterIndexs[key - 49]].maxMoney;
            monsterArray[monsterIndexs[key - 49]].state = 0;
        }
    }
    else
    {
        SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
        printf("要攻击的怪物不存在，按任意键继续：");
    }
}


void AreaMovement()
{
    int i,j;
    char mapname[50];
    SetPosition(MARGIN_X+2, MAINMENU_START_Y + 3);
    printf(" 请输入目的区域名称(我就是司机，快上车啊!): ");
    SetColor(13,0);
    scanf("%s",&mapname);
    SetColor(10,0);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(!(strcmp(mapArray[i][j].name,mapname)))
            {
                X = mapArray[i][j].coord.X;
                Y = mapArray[i][j].coord.Y;
                break;
            }
        }
    }

    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("                                                               ");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("3、区域移动");
    ShowMap();
}

void ShowStore()
{
    int i = -1;
    do
    {
        if(i == '1')
            {
                ShowBag();
                return;
            }

        Clear(0,INFO_START_Y,21);
        Clear(60,INFO_START_Y,21);

        SetPosition(MARGIN_X, INFO_START_Y);
        printf("                                                                                                       ");
        SetPosition(MARGIN_X,32);
        printf("                                                                                                                ");
    for(i=0;i<propsCount;i++)
    {
        SetPosition(32, 14+i*2);
        if(propArray[i].type == Weapon)
            printf("%d.%-15s(攻击力%d-%d)\t[库存:%d]\t单价：%d",i+1,propArray[i].name,propArray[i].Min.minattack,propArray[i].Max.maxattack,propArray[i].stock,propArray[i].price);
        else if(propArray[i].type == Armor)
            printf("%d.%-15s(防御力%d-%d)\t[库存:%d]\t单价：%d",i+1,propArray[i].name,propArray[i].Min.mindefence,propArray[i].Max.maxdefence,propArray[i].stock,propArray[i].price);
        else if(propArray[i].type == Consumables)
            printf("%d.%-23s\t[库存:%d]\t单价：%d",i+1,propArray[i].name,propArray[i].stock,propArray[i].price);
    }

    Transaction();
    SetPosition(MARGIN_X,32);
    printf("勇士-请按0退出购买,按1查看背包。");

    }while((i = getch())!='0');

    Clear(0,INFO_START_Y,21);
    Clear(60,INFO_START_Y,21);
    ShowInfomation();
    ShowMainMenu();
}


void Transaction()
{
        int i,id,propId,buyNum,find = 0;
        SetPosition(MARGIN_X, INFO_START_Y);
        printf("欢迎进入~来了就要买~商店，请输入要购买的商品ID及数量:");
        scanf("%d %d",&propId,&buyNum);
        for(i=0;i<propsCount;i++)
        {
            if(propId == propArray[i].id)
            {
                currProp=&propArray[i];    //tradeProp=props+i                         ??? &符号
                find = 1;
                    break;
            }
        }
        if(!find)
        {
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("                                                                                       ");
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("商店内无此商品！");
            return;
        }
        if(currProp -> stock < buyNum)
        {
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("                                                                                       ");
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("库存不足，请重新选择！");
            return;
        }
        if(currPlayer -> gold < currProp -> price)
        {
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("                                                                                       ");
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("你这样在阿拉德大陆是要挨打的！");
            return;
        }
        if(currPlayer -> bag.count >= currPlayer -> bag.max /*&&player->bag.count!=0*/)
        {
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("                                                                                       ");
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("您的背包已满，请赶快清理垃圾!");
            return;
        }

        //满足交易条件，执行交易的操作
        //1.商品库存-1
        currProp -> stock -= buyNum;
        //2.玩家金币-商品单价
        currPlayer -> gold -= (currProp -> price)*buyNum;
        //*3.玩家背包道具增加
        //判断玩家背包中是否已有该商品
        //如果没有该商品，该商品添加到背包即可
        //如果已有该商品，背包中的该商品总数加buyNum
        for(i=0;i<currPlayer->bag.count;i++)
        {
            //如果要购买的商品id跟背包中的某个商品id相同
            if(propId == currPlayer->bag.props[i].id)
            {
                currPlayer -> bag.props[i].stock += buyNum;
                break;
            }
        }
        if(i == currPlayer -> bag.count)                   //如果没有该商品，该商品添加到背包即
        {
            int newIndex = currPlayer-> bag.count;
            //向背包中创建一个商品，将复制一份要交易的商品信息到背包中
            currPlayer->bag.props[newIndex].id = currProp->id;
            strcpy(currPlayer->bag.props[newIndex].name,currProp->name);
            currPlayer->bag.props[newIndex].level = currProp->level;
            currPlayer->bag.props[newIndex].type = currProp->type;
            currPlayer->bag.props[newIndex].Min = currProp->Min;
            currPlayer->bag.props[newIndex].Max = currProp->Max;
            strcpy(currPlayer->bag.props[newIndex].desc,currProp->desc);


            currPlayer->bag.props[newIndex].stock=buyNum;
            currPlayer->bag.count++;
        }
}



void ShowBag()
{
    int i;
    do
    {
        if(i == '1')        ShowStore();
            else if(i == '2')   UseProps();

    Clear(0,INFO_START_Y,21);
    Clear(60,INFO_START_Y,21);

    SetPosition(MARGIN_X, INFO_START_Y);
    printf("                                                                           ");
    SetPosition(MARGIN_X, INFO_START_Y);
    printf("您当前的背包插槽总数：%d",currPlayer -> bag.max);
    SetPosition(MARGIN_X,32);
    printf("                                                                           ");
    SetPosition(MARGIN_X,32);
    printf("按0返回游戏，按1进入加百利的神秘商店，按2使用物品");

    for(i=0;i<currPlayer -> bag.count;i++)
    {
        SetPosition(32, 14+i*2);
        if(currPlayer -> bag.props[i].type == Weapon)
            printf("%d.%-15s(攻击力%d-%d)\t[数量:%d]",i+1,currPlayer -> bag.props[i].name,currPlayer -> bag.props[i].Min.minattack,currPlayer -> bag.props[i].Max.maxattack,currPlayer -> bag.props[i].stock);
        else if(currPlayer -> bag.props[i].type == Armor)
            printf("%d.%-15s(防御力%d-%d)\t[数量:%d]",i+1,currPlayer -> bag.props[i].name,currPlayer -> bag.props[i].Min.mindefence,currPlayer -> bag.props[i].Max.maxdefence,currPlayer -> bag.props[i].stock);
        else if(currPlayer -> bag.props[i].type == Consumables)
            printf("%d.%-23s[数量:%d]",i+1,currPlayer -> bag.props[i].name,currPlayer -> bag.props[i].stock);
    }
    }while((i = getch()) != '0');

    Clear(0,INFO_START_Y,21);
    Clear(60,INFO_START_Y,21);
    ShowInfomation();
    ShowMainMenu();
}


void UseProps()
{
    SetPosition(MARGIN_X,32);
    printf("                                                                           ");
    SetPosition(MARGIN_X,32);
    printf("请输入要使用的道具编号(未完待续...)：");
    fflush(stdin);
    int c = getche();
    fflush(stdin);


}


void FunnyGames()
{
    int num = -1;
    while(num != '0')
    {
    system("cls");
    SetPosition(40,4);
    SetColor(12,0);
    printf("Gamecredit: %d",currPlayer -> gamecredit);
    SetColor(10,0);
    SetPosition(40,7);
    printf("1.2048 (Unclock in source code!)");
    SetPosition(40,9);
    printf("2.Five in a row");
    SetPosition(40,11);
    printf("3.Gluttonous snake (Unclock in source code!)");
    SetPosition(40,13);
    printf("4.The tank war");
    SetPosition(40,15);
    printf("5.Mine clearance");
    SetPosition(40,17);
    printf("6.Labyrinth");
    SetPosition(40,19);
    printf("7.Flappy bird");
    SetPosition(40,21);
    printf("8.Tetris");
    SetPosition(40,23);
    printf("0.Exit");

    num = getch();
    system("cls");
        switch(num)
    {
//      case '1': Game2048();         break;
        case '2': GameGobang();       break;
//      case '3': GameSnake();        break;
        case '4': GameTank();         break;
        case '5': GameSweep();        break;
        case '6': GameLabyrinth();    break;
        case '7': GameFlappyBird();   break;
        case '8': GameTetris();       break;
        default:                      continue;
    }
        currPlayer -> gamecredit ++;        //游戏积分加1
    }
    system("cls");
    ShowWelcome();
    ShowMap();
    ShowInfomation();
    ShowMainMenu();
}
