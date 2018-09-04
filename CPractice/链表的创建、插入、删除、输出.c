#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    int count;
    struct _node *next;
}Node;

/*用的时候记得初始化*/
typedef struct _list{
    struct _node * head;
    struct _node * tail;
}List;

void Add(List *list,int value)
{
    Node *pNew = (Node *)malloc(sizeof(Node));
    pNew -> value = value;
    pNew -> next = NULL;
    if(list -> head)    //链表不为空
    {
        list -> tail -> next = pNew;
        list -> tail = pNew;
    }
    else
        list -> head = list -> tail = pNew;
}

Node *Create()
{
    Node *pPre,*pNew,*pHead = NULL;
    do
    {
        if(pHead == NULL)
        {
            pHead = pPre = pNew = (Node*)malloc(sizeof(Node));
            pNew -> next = NULL;
        }
        else
        {
            pNew = (Node*)malloc(sizeof(Node));
            pNew -> next = NULL;
        }
        scanf("%d",&pNew -> value);
        if(pNew -> value == 0)
        {
            if(pHead == pNew)
                pHead = NULL;
            pPre -> next = NULL;
        }
        else
        {
            pPre -> next = pNew;
            pPre = pNew;
        }

    }while(pNew -> value != 0);
    free(pNew);
    return pHead;
}

void Print(Node *pHead)
{
    printf("\n");
    Node *pTemp;
    pTemp = pHead;
    while(pTemp != NULL)
    {
        printf("%d\t",pTemp -> value);
        pTemp = pTemp -> next;
    }
}

Node *Insert(Node *pHead)
{
    int i,site;
    Node *pNew,*pTemp = pHead;
    printf("\n\n请输入要插入的位置：");
    scanf("%d",&site);
    pNew = (Node*)malloc(sizeof(Node));
    printf("\n请输入要插入的数字：");
    scanf("%d",& pNew ->value);
    for(i = 1;i < site;i++)
        pTemp = pTemp -> next;
    pNew -> next = pTemp -> next;
    pTemp -> next = pNew;
}

void DeleteSite(Node *pHead)
{
    int i,site;
    Node *pPre,*pTemp = pHead;
    printf("\n\n 请输入要删除的位置：");
    scanf("%d",&site);
    for(i = 1;i < site;i++)
    {
        pPre = pTemp;
        pTemp = pTemp -> next;
    }
    pPre -> next = pTemp -> next;
    free(pTemp);
}

void DeleteNode(Node *pHead)
{
    int i,value;
    Node *pPre,*pTemp = pHead;
    printf("\n\n 请输入要删除的节点：");
    scanf("%d",&value);
    while(pTemp != NULL && pTemp -> value != value)
    {
        pPre = pTemp;
        pTemp = pTemp -> next;
    }
    pPre -> next = pTemp -> next;
    free(pTemp);
}

/*得到链表长度*/
int GetNodeCount(Node *pHead)
{
    int count = 0;
    Node *ptemp = pHead;
    while(ptemp)
    {
        count++;
        ptemp = ptemp -> next;
    }
    return count;
}

/*链表的逆置*/
Node *ReverseLink(List list)
{
    Node *p,*q;
    p = list.head -> next;
    list.head -> next = NULL;
    while(p)
    {
        q = p;
        p = p -> next;

        q -> next = list.head -> next;
        list.head -> next = q;
    }
}

/*检测链表是否有环*/
bool DetectLoopLink(Node *pHead)
{
    if(pHead == NULL)
        return false;
    Node *quicknode = pHead -> next;
    Node *slownode = pHead;
    while(quicknode)
    {
        if(quicknode == slownode)
            return true;
        slownode = slownode -> next;
        quicknode = (quicknode -> next) -> next;
    }
    return false;
}

/*约瑟夫环*/
int JosephusProblem(Node *pHead,int n)
{
    Node *pPre,*pTemp = pHead;
    int i;
    while(pTemp -> next != pTemp)
    {
        for(i = 0;i < n - 1;i++)
        {
            pPre = pTemp;
            pTemp = pTemp -> next;
        }
        pPre -> next = pTemp -> next;
        free(pTemp);
        pTemp = pPre -> next;
    }
    return pTemp -> value;
}
