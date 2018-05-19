#include "Head.h"

void Write()
{
    Player *temp1 = ShanXi.head;
    Player *temp2 = BeiJing.head;
    Player *temp3 = GuangDong.head;
    Player *temp4 = JiangSu.head;
    Player *temp5 = HeiLongJiang.head;

    FILE *fp_1,*fp_2,*fp_3,*fp_4,*fp_5;

    /*陕西*/
    fp_1 = fopen("ShanXi.bin","wb+");

    while(temp1)
    {
        fwrite(temp1,sizeof(Player),1,fp_1);
        temp1 = temp1 -> next;
    }

    fclose(fp_1);

    /*北京*/
    fp_2 = fopen("BeiJing.bin","wb+");

    while(temp2)
    {
        fwrite(temp2,sizeof(Player),1,fp_2);
        temp2 = temp2 -> next;
    }

    fclose(fp_2);

    /*广东*/
    fp_3 = fopen("GuangDong.bin","wb+");

    while(temp3)
    {
        fwrite(temp3,sizeof(Player),1,fp_3);
        temp3 = temp3 -> next;
    }

    fclose(fp_3);

    /*江苏*/
    fp_4 = fopen("JiangSu.bin","wb+");

    while(temp4)
    {
        fwrite(temp4,sizeof(Player),1,fp_4);
        temp4 = temp4 -> next;
    }

    fclose(fp_4);

    /*黑龙江*/
    fp_5 = fopen("HeiLongJiang.bin","wb+");

    while(temp5)
    {
        fwrite(temp5,sizeof(Player),1,fp_5);
        temp5 = temp5 -> next;
    }

    fclose(fp_5);
}


void Read(List *currlist)
{
    Player *temp = NULL;

    ShanXi.head = NULL;
    BeiJing.head = NULL;
    GuangDong.head = NULL;
    JiangSu.head = NULL;
    HeiLongJiang.head = NULL;

    FILE *fp_1,*fp_2,*fp_3,*fp_4,*fp_5;

    int i,x,count;
    /*陕西*/
    fp_1 = fopen("ShanXi.bin","ab+");

    fseek(fp_1,0L,SEEK_END);
    x = ftell(fp_1);
    count = x / sizeof(Player);
    fseek(fp_1,0L,SEEK_SET);

    for(i = 0;i < count;i++)
    {
        temp = Add(&ShanXi);
        fread(temp,sizeof(Player),1,fp_1);
    }

    fclose(fp_1);

    /*北京*/
    fp_2 = fopen("BeiJing.bin","ab+");

    fseek(fp_1,0L,SEEK_END);
    x = ftell(fp_1);
    count = x / sizeof(Player);
    fseek(fp_1,0L,SEEK_SET);

    for(i = 0;i < count;i++)
    {
        temp = Add(&BeiJing);
        fread(temp,sizeof(Player),1,fp_1);
    }

    fclose(fp_2);

    /*广东*/
    fp_3 = fopen("GuangDong.bin","ab+");

    fseek(fp_1,0L,SEEK_END);
    x = ftell(fp_1);
    count = x / sizeof(Player);
    fseek(fp_1,0L,SEEK_SET);

    for(i = 0;i < count;i++)
    {
        temp = Add(&GuangDong);
        fread(temp,sizeof(Player),1,fp_1);
    }

    fclose(fp_3);

    /*江苏*/
    fp_4 = fopen("JiangSu.bin","ab+");

    fseek(fp_1,0L,SEEK_END);
    x = ftell(fp_1);
    count = x / sizeof(Player);
    fseek(fp_1,0L,SEEK_SET);

    for(i = 0;i < count;i++)
    {
        temp = Add(&JiangSu);
        fread(temp,sizeof(Player),1,fp_1);
    }

    fclose(fp_4);

    /*黑龙江*/
    fp_5 = fopen("HeiLongJiang.bin","ab+");

    fseek(fp_1,0L,SEEK_END);
    x = ftell(fp_1);
    count = x / sizeof(Player);
    fseek(fp_1,0L,SEEK_SET);

    for(i = 0;i < count;i++)
    {
        temp = Add(&HeiLongJiang);
        fread(temp,sizeof(Player),1,fp_1);
    }

    fclose(fp_5);
}
