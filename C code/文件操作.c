#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
	double nums[4] = {1.2,3.4,5.6,7.8};

	/**
	  * r	 打开一个已有的文本文件，允许读取文件。
	  * w	 打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。程序会从文件的开头写入内容。如果文件存在，则会被截断为零长度，重新写入。
	  * a	 打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。程序会在已有的文件内容中追加内容。
	  * r+	 打开一个文本文件，允许读写文件。
	  * w+	 打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。
	  * a+	 打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。
	 */
    fp = fopen("file.txt","wt");
    while((ch = getchar()) != EOF)
        fputc(ch,fp);
        fclose(fp);
		
    fp = fopen("file.txt","rt");
    while((ch = getc(fp)) != EOF)
        putchar(ch);
        fclose(fp);
		
	fp = fopen("file.txt","rt");
	char buff[50];
	while(fgets(buff,50,fp))
		printf("%s",buff);
		fclose(fp);
		
	fp = fopen("file.txt","wb");
		//fprintf等标准I/O函数都是面向文本的，用于处理字符和字符串，用fprintf函数和%f转换说明只是把数值保存为字符串
		//fwrite和fread把二进制数据写入文件，在文件中保存数值数据
        fwrite(nums,sizeof(double),4,fp);		
        fclose(fp);								
}