/**
 * 我的思路：先找第m个节点前面的一个节点，再用mlast把第m个节点保存下来，然后进行m -- n的链表逆置，循环的过程中用nfrist把第n个节点的下一个节点保存下来，最后mlast -> next = nfirst
 * 注意点：1. 考虑到m == 1的情况，可声明newHead -> next = head，最后return newHead -> next
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *newHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    newHead -> next = head;
    head = newHead;
    for(int i = 1;(i < m) && head;i++){
        head = head -> next;
    }
    struct ListNode *nfirst,*mlast = head -> next;
    struct ListNode *q,*p = head -> next;
    head -> next = NULL;	//
    for(int i = 0;(i < n - m + 1) && p;i++){
        if(i == n - m){
            nfirst = p -> next;
        }
        q = p;
        p = p -> next;		//
        q -> next = head -> next;
        head -> next = q;
    }
    
    mlast -> next = nfirst;	//
    return newHead -> next;
}