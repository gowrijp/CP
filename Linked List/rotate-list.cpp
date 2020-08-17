/*
https://www.interviewbit.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
        return A;
    ListNode* temp=A;
    int count=0;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    count++;
    temp->next=A;
    temp=A;
    B=B%count;
    int x=count-B;
    for(int i=0;i<x-1;i++)
        temp=temp->next;
    A=temp->next;
    temp->next=NULL;
    return A;
}
