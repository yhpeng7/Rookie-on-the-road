1. c语言头文件只有函数的声明，编译的时候会去找函数的实现，然后进行链接

2. 变量名，对内存空间上的一段数据的抽象

3. 正是因为有了指针的间接赋值，才有了Java的引用以及OOP。

4. 指针有类型，地址没有类型。地址只是开始的位置，类型规定了读取几个字节结束。

5. arr,&arr,&arr[0]都是数组首地址，由编译器默认指定

6. ```c
   int add(int a, int b) {
   	return a + b;
   }
   
   int minus(int a, int b) {
   	return a - b;
   }
   
   /**
    * 类似于Java中的回调函数
    */
   void calculate(int(*func_p)(int a,int b),int m,int n) {
   	printf("%d", func_p(m, n));
   }
   
   void main() {
       //同上，add与&add都表示函数首地址
   	calculate(add, 5, 2);
   	calculate(minus, 5, 2);
   }
   ```

7. C语言内存分配：

   1. 栈区（stack）

      Windows下，栈内存分配2M（确定的常数），超出限制会抛出stack overflow异常，例： int arr[1024 * 1024 * 10];

      栈内存自动分配释放

   2. 堆区（heap）

      可分配内存：操作系统80%的内存都可以分配

      程序员手动分配释放

   3. 全局区或静态区

   4. 字符常量区

   5. 程序代码区

   6. 动态分配的内存的基本规则：

      - 避免分配大量的小内存块。分配堆上的内存有一些系统开销，所以分配许多小的内存块比分配几个大内存块的系统开销大。
      - 仅在需要时分配内存。只要使用完堆上的内存块，就释放它。
      - 总是确保释放已分配的内存。在编写分配内存的代码时，就要确定在代码的什么地方释放内存。
      - 在释放内存之前，确保不会无意中覆盖堆上分配的内存的地址，否则程序就会出现内存泄漏。在循环中分配内存时，要特别小心。

8. void *realloc(void *p,unsigned int size)  --- 对动态分配的内存空间的大小进行修改。有两种情况：

   1. 缩小，缩小的部分数据丢失
   2. 扩大
      - 如果当前内存段后面有足够的内存空间，直接分配这段内存，relloc返回原指针。
      - 如果当前内存块后面的空闲字节不够，那么往后找出堆中第一个能够满足需求的内存块，将当前的数据复制到新的位置，并将当前的内存块释放掉，并返回新的指针。
      - 如果申请失败，返回NULL，原来的指针仍然有效。

9. ```c
   void main() {
   	int *ptr = (int *)malloc(1024 * 1024 * sizeof(int));
       printf("%#x\n", ptr);
       //此处不free的话会造成内存泄露（ptr重新赋值后再free并没有释放掉之前申请的内存块）
   	free(ptr);
       
   	ptr = (int *)malloc(1024 * 1024 * sizeof(int) * 2);
       printf("%#x\n", ptr);
   	free(ptr);
   	//标志释放完成
   	ptr = NULL;
   }
   ```

10. ```c
    /*
     * 匿名结构体，类似于单例
     */
    struct{
    	int id;
    	char name[50];
    	const char *job;
    	void(*study)(const char *Cname);
    }student;
    
    void main() {
        //字符数组只能在声明时进行赋值，可以修改字符
    	strcpy(student.name,"王泽鹏");
        //字符指针可以多次赋值，不可以修改字符
    	student.job = "Student";
    }
    ```

11. 结构体指针访问结构体成员时"ptr->"是"(*ptr)."的简写形式

12. [struct内存对齐](https://www.zhihu.com/question/27862634)

13. 