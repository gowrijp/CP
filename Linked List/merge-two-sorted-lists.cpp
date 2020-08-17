/*
https://www.interviewbit.com/problems/merge-two-sorted-lists/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode* head = NULL;
    if(l1->val<l2->val){
        head=l1;
        l1=l1->next;
    }
    else{
        head=l2;
        l2=l2->next;
    }
    ListNode* p=head;
    while(l1 and l2){
        if(l1->val<l2->val){
            p->next=l1;
            l1=l1->next;
        }
        else{
            p->next=l2;
            l2=l2->next;
        }
        p=p->next;
    }
    if(l1){
        p->next=l1;
    }
    else{
        p->next=l2;
    }
    return head;
}
