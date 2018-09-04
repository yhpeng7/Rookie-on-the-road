/*非递归实现*/
Node *MergeTwoLists(Node *pHead1,Node *pHead2)
{
    Node *newHead = NULL;
    Node *pTail = NULL;
	//判断两个链表是否为空
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;
    else
    {
        if(pHead1 -> value < pHead2 -> value)
        {
            newHead = pHead1;
            pHead1 = pHead1 -> next;
        }
        else
        {
            newHead = pHead2;
            pHead2 = pHead2 -> next;
        }
    }
	//将pTail作为头指针指向值较小的节点
    pTail = newHead;
    while(pHead1 && pHead2)
    {
        if(pHead1 -> value < pHead2 -> value)
        {
            pTail -> next = pHead1;
            pHead1 = pHead1 -> next;
        }
        else
        {
            pTail -> next = pHead2;
            pHead2 = pHead2 -> next;
        }
		//pTail不断向后移动
        pTail = pTail -> next;
    }
	//将另一个链表剩下的元素都连接到第一个节点的后面
    if(!pHead1)
        pTail -> next = pHead2;
    else if(!pHead2)
        pTail -> next = pHead1;
    return newHead;
}

/*递归实现*/
Node *MergeTwoLists2(Node *pHead1,Node *pHead2)
{
    Node *newHead = NULL;
	/*判断*/
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;
    else
    {
		//newHead不断向后移动
        if(pHead1 -> value < pHead2 -> value)
        {
            newHead = pHead1;
            newHead -> next = MergeTwoLists(pHead1 -> next,pHead2);
        }
        else
        {
            newHead = pHead2;
            newHead -> next = MergeTwoLists(pHead1,pHead2 -> next);
        }
    }
	//每级return各自的newHead变量，将其赋给上一级的next
    return newHead;
}