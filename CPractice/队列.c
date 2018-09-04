#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 50

typedef int QElemtype;

typedef struct _sqqueue{
    QElemtype data[MAXSIZE];
    int front;  //头指针
    int rear;   //尾指针
}SeqQueue;

bool InitQueue(SeqQueue *Q)
{
    Q -> front = 0;
    Q -> rear = 0;
    return true;
}

bool EnQueue(SeqQueue *Q,QElemtype e)
{
    if((Q -> rear + 1) % MAXSIZE == Q -> front)
        return false;
    Q -> data[Q -> rear] = e;
    Q -> rear = (Q -> rear + 1) % MAXSIZE;
        return true;
}

bool DeQueue(SeqQueue *Q,QElemtype *e)
{
    if(Q -> rear == Q -> front)
        return false;
    *e = Q -> data[Q -> front];
    Q -> front = (Q -> front + 1) % MAXSIZE;
        return true;
}

bool ClearQueue(SeqQueue *Q)
{
    Q -> rear == Q -> front;
    return true;
}

bool QueueEmpty(SeqQueue Q)
{
    if(Q.front == Q.rear)
        return true;
        return false;
}

int QueueLength(SeqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
