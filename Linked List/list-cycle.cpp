/*
https://www.interviewbit.com/problems/list-cycle/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

FLOYD'S ALGO FOR LOOP DETECTION
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* one, *two;
    bool loop = false;
    one = A; two = A;
    while(one && two && two->next){
        one = one->next;
        two = two->next->next;
        if(one==two){
            loop = true;
            break;
        }
    }
    if(loop){
        one = A;
        while(one!=two){
            one = one->next;
            two = two->next;
        }
        return one;
    }
    return NULL;
}

