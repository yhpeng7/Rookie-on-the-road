/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /**
  * 1. 进位后当前位减十
  * 2. 如果进位后l1链表后面没有可以保存进位的节点...
  * 3. 如果l1位数少就把l2后面的接上去---在循环的过程中找到l1的尾节点
  * 4. 刚开始没有考虑这种骚情况---(99 + 9)...循环判断条件就是(l1 && l2)，最后改为只在循环判断条件里判断l1，在循环体内判断l2
  */ 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* newhead = l1;
    struct ListNode* tail = NULL;
    
    while(l1){
        if(l2){
            l1 -> val += l2 -> val;
        }
    /*进位/判断l1当前位是否大于十*/
    if(l1 -> val > 9){
        l1 -> val -= 10;
        if(l1 -> next){
            l1 -> next -> val++;
        }else{
            l1 -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l1 -> next -> next = NULL;
            l1 -> next -> val = 1;
        }
    }
        if(l1 != NULL && l1 -> next == NULL){
            tail = l1;
        }
            l1 = l1 -> next;
        if(l2){
            l2 = l2 -> next;
        }
    }
    /*判断l1位数是否比l2小*/
    if(l1 == NULL && tail != NULL){
        tail -> next = l2;
    }
    
    return newhead;
}

/*官方答案*/
/*
class Solution {
public:
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
};
*/