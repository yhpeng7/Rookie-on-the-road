#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;

	/**
	 *w	写
	 *r	读
	 *a	追加
	 *+	读和写
	 *w	文本类型
	 *b	二进制类型
	 */
    fp = fopen("file.txt","wt");
    while((ch = getchar()) != EOF)
        fputc(ch,fp);
        fclose(fp);

    fp = fopen("file.txt","rt");
    while((ch = getc(fp)) != EOF)
        putchar(ch);
        fclose(fp);
}

int main()
{
    FILE *fp;
    char ch;
    double str[100] = {1.2,2.001,3.1231,4.0013131};
    double str2[100];
    int strl = strlen(str);

	 //printf("%d",str);
    fp = fopen("file.txt","wb");
    //while((ch = getchar()) != EOF)
        //fputc(ch,fp);
        fwrite(str,sizeof(double),4,fp);		//fwrite和fread把二进制数据写入文件，在文件中保存数值数据
        fclose(fp);								//fprintf等标准I/O函数都是面向文本的，用于处理字符和字符串，用fprintf函数和%f转换说明只是把数值保存为字符串

    fp = fopen("file.txt","rb");
    //while((ch = getc(fp)) != EOF)
        //putchar(ch);
        fread(str2,sizeof(double),4,fp);
        fclose(fp);
        printf("%lf",str2[1]);
        //puts(str2);
}










(1-2)*(4+5)