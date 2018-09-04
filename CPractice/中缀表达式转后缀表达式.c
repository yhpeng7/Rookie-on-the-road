#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 50

typedef char Elemtype;

typedef struct _seqstack{
    Elemtype data[MAXSIZE];
    int top;    //栈顶指针
}SeqStack;

SeqStack *InitStack()
{
    //设置为-1比0更合理些
    SeqStack *S = (SeqStack *)malloc(sizeof(SeqStack));
    S -> top = -1;
    return S;
}

/*判断栈是否为空*/
bool IsEmpty( SeqStack *S)
{
    if(S -> top > -1)
        return false;
    else
        return true;
}

bool Push(SeqStack *S,char ch)
{
    if(S -> top < MAXSIZE)
    {
        S -> top ++;
        S -> data[S -> top] = ch;
        return true;
    }
        printf("error:stack full,cnt't push\n");
        return false;
}


bool Pop(SeqStack *S,Elemtype *e)
{
    if(!(IsEmpty(S)))
    {
        *e = S -> data[S -> top];
        S -> top--;
        return true;
    }
        printf("error:stack empty\n");
        return false;
}

Elemtype Top(SeqStack *S)
{
    if(!(IsEmpty(S)))
        return S -> data[S -> top];
        return 0;
}

int Priority(char ch)
{
    switch(ch)
    {
        case '(':   return 0;   break;
        case ')':   return 0;   break;
        case '+':   return 1;   break;
        case '-':   return 1;   break;
        case '*':   return 2;   break;
        case '/':   return 2;   break;
    }
}

void Transform(char str[],int strlen)
{
    char top;
    int i,k = 0;
    char *newstr = (char *)malloc(strlen * sizeof(char));
    SeqStack *signS = InitStack();

//    printf("%d",strlen);

    for(i = 0;i < strlen;i++)
    {
        /*是数字直接输出*/
        if(str[i] >= '0' && str[i] <= '9')
            newstr[k++] = str[i];
        else
        {
            /*若栈为空，遇到运算符，直接入栈*/
            if(IsEmpty(signS) || str[i] == '(')
                Push(signS,str[i]);
            /*如果遇到')',将栈顶元素出栈，直到弹出栈的是左括号,左括号不输出*/
            else if(str[i] == ')')
            {
                do
                {
                    Pop(signS,&top);
                    newstr[k++] = top;
                }while(top != '(' && !IsEmpty(signS));
                    k--;
            }
            /*若是遇到其他运算符，弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈*/
            else if(!IsEmpty(signS) && Priority(str[i]) <= Priority(Top(signS)))
            {
                while(!IsEmpty(signS) && Priority(str[i]) <= Priority(Top(signS)))
                {
                    Pop(signS,&top);
                    newstr[k++] = top;
                }
                    Push(signS,str[i]);
            }
            else
                Push(signS,str[i]);
        }
    }

    while(!IsEmpty(signS))
        {
            Pop(signS,&top);
            newstr[k++] = top;
        }
    newstr[k++] = '\0';

    while(*str++ = *newstr++);
    free(newstr);
}

int main()
{
    char str[50];
    gets(str);
    int Strlen = strlen(str);

    Transform(str,Strlen);

    FILE *fp;
    fp = fopen("file.txt","wt");
        fputs(str,fp);
    fclose(fp);

    puts(str);
}

