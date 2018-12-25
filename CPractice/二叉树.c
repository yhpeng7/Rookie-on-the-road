#include <stdio.h>
#include <stdlib.h>

typedef struct _treenode{
    int value;
    struct _treenode *left;
    struct _treenode *right;
}TreeNode;

TreeNode *TreeInsert(TreeNode *T,int value)
{
    if(T == NULL)
    {
        T = (TreeNode *)malloc(sizeof(TreeNode));
        T -> value = value;
        T -> left = NULL;
        T -> right = NULL;
    }
    else if(value < T -> value)
        T -> left = TreeInsert(T -> left,value);
    else if(value > T -> value)
        T -> right = TreeInsert(T -> right,value);
    return T;
}

void Print(TreeNode *T)
{
    if(T != NULL)
    {
        Print(T -> left);
        printf("%d  ",T -> value);
        Print(T -> right);
    }
}


void HierarchyBiTree(TreeNode *T)
{
    TreeNode *temp = T;
    SeqQueue node;
    InitQueue(&node);
    EnQueue(&node,temp);
    while(!QueueEmpty(node))
    {
        DeQueue(&node,&temp);
        printf("%d ",temp -> value);

        if(temp -> left != NULL)
            EnQueue(&node,temp -> left);
        if(temp -> right != NULL)
            EnQueue(&node,temp -> right);
    }
}

TreeNode *MakeEmpty(TreeNode *T)
{
    if(T != NULL)
    {
        MakeEmpty(T -> left);
        MakeEmpty(T -> right);
        free(T);
    }
    return NULL;
}

TreeNode *FindMin(TreeNode *T)
{
    if(T == NULL)
        return NULL;
    else if(T -> left ==NULL)
        return T;
    else
        return FindMin(T -> left);
}