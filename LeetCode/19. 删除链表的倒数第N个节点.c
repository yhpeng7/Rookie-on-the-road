/**
 * 我的思路：先让front向前走n个节点，如果front为空--return head -> next，然后while(front -> next)时让rear指针和front指针同时向前移动，则当循环结束时rear指针刚好指向待删除节点的上一个节点。 
 * 注意点：1.考虑删除第一个节点的情况
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *front = head;
    struct ListNode *rear = head;
    
    if(head == NULL || n < 0){
        return NULL;
    }
    for(int i = 0;i < n;i++){
        front = front -> next;
    }
    if(!front){
        head = head -> next;
        return head;
    }
    while(front -> next){
        front = front -> next;
        rear = rear ->  next;
    }
    if(rear -> next){
        rear -> next = rear -> next -> next;
    }
    return head;
}