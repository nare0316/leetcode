/* N2. Add Two Numbers 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/*  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *newHead = l1;
    int c = 0;
    struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    while(l1->next != NULL && l2->next != NULL) {
        l1->val = l1->val + l2->val + c;
        if(l1->val >= 10) {
            c = l1->val /10;
            l1->val = l1->val %10;
        } else {
            c = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    l1->val = l1->val + l2->val + c;
    if(l1->val >= 10) {
        c = l1->val/10;
        l1->val = l1->val%10;;
    } else {
        c = 0;
    }
    while(l1->next != NULL) {
        l1 = l1->next;
        l1->val = l1->val + c;
        if(l1->val >= 10) {
            c = l1->val/10;
            l1->val = l1->val %10; 
        } else {
            c = 0;
        }
        

    }
    while(l2->next != NULL){
        l2 = l2->next;
        l1->next = l2;
        l1 = l1->next;
        l2->val = l2->val + c;
        if(l2->val >= 10){
            c = l2->val /10;
            l2->val = l2->val %10;
        } else {
            c = 0;
        }

    }


    if(c > 0) {
        l1->next = tmp;
        tmp->val = c;
        tmp->next = NULL;
    }
    return newHead;
}
