/*
https://www.interviewbit.com/problems/add-two-numbers-as-lists/

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* ptr = new ListNode(0);
    ListNode* start = ptr;
    int c=0;
    
    while(A || B)
    {
        int a=0,b=0;
        if(A)
            a=A->val;
        if(B)
            b=B->val;
        int x = a+b+c;
        c = x/10;
        x = x%10;
        ListNode* temp = new ListNode(x);
        ptr->next = temp;
        ptr = temp;
        
        if(A)
            A = A->next;
        if(B)
            B = B->next;
    }
    
    if(c)
    {
        ListNode* temp = new ListNode(c);
        ptr->next = temp;
        ptr = temp;
    }
    
    return start->next;
}
