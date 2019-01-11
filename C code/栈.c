typedef int Elemtype;

typedef struct _seqstack{
    Elemtype data[ARRMAX];
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
    if(S -> top < ARRMAX)
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
